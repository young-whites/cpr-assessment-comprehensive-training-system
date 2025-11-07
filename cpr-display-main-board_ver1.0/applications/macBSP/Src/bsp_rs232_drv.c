#include <bsp_rs232_drv.h>
/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-11-04     Administrator       the first version
 */


#define DBG_TAG "rs232"
#define DBG_LVL DBG_INFO
#include <rtdbg.h>




/* 接收超时定时器回调函数，当字节间隔超时时释放信号量，通知接收完成 */
static void rs232_recv_timeout(void *parameter)
{
    rs232_inst_t *hinst = (rs232_inst_t *)(parameter);

    if (hinst !=RT_NULL){
        rt_sem_release(&hinst->rx_sem);
    }
}


/* 串口接收指示回调函数，当有数据到达时读取并启动超时定时器 */
// 调用时机：当串口硬件 FIFO 收到新数据并触发 RX 中断 → RT-Thread 底层驱动调用 dev->rx_indicate(dev, size) → 注册的回调函数 rs232_recv_ind_hook 被执行
static rt_err_t rs232_recv_ind_hook(rt_device_t dev, rt_size_t size)
{
    /*当前每次接收1byte*/
    rs232_inst_t *hinst = (rs232_inst_t *)(dev->user_data);

    if (size > 0)
    {
        /* 每次接收到新数据，就从这个地址中去拿这个数据： hinst->received_buf 是数据接收区的首地址 + 已经接收的数据长度 = 当前数据地址*/
        int len = rt_device_read(hinst->serial, 0, hinst->received_buf + hinst->received_len, size);

        if (len)
        {
            /* 如果累计接收的数据长度 < 数据接收缓冲区的最大值就可以继续接收 */
            if (hinst->received_len < hinst->received_max_len-1)
            {
                hinst->received_len++;
            }
        }
        rt_timer_start(hinst->received_over_timer);
    }
    return(RT_EOK);
}


/* rs232_cal_byte_tmo() 就是“波特率→毫秒”的换算表，把 3.5 字符时间换算出来并锁在 [1,20] ms 安全区，给接收状态机当“帧间隔”用 */
static int rs232_cal_byte_tmo(int baudrate)
{
    /* 发送 40 bit 需要的时间折成毫秒 */
    int tmo = (40 * 1000) / baudrate;

    /* 算得太小（高速波特率）时，给个下限，防止系统定时器精度不够导致超时 */
    if (tmo < RS232_BYTE_TMO_MIN){
        tmo = RS232_BYTE_TMO_MIN;
    }
    /* 算得太大（低速波特率）时，给上限，避免一帧要等几百毫秒，系统响应太慢 */
    else if (tmo > RS232_BYTE_TMO_MAX){
        tmo = RS232_BYTE_TMO_MAX;
    }
    return (tmo);
}



/*
 * @brief   create rs232 instance dynamically
 * @param   serial      - serial device name
 * @param   baudrate    - serial baud rate
 * @param   parity      - serial parity mode
 * @retval  instance handle
 */
rs232_inst_t * rs232_create(const char *name, int baudrate, int parity)
{
    rs232_inst_t *hinst;    // 实例指针（返回值）
    rt_device_t dev;        // 底层串口设备句柄

    // 查找串口设备
    dev = rt_device_find(name);
    if (dev == RT_NULL){
        LOG_E("rs232 instance initiliaze error, the serial device(%s) no found.", name);
        return(RT_NULL);
    }

    // 校验字符型设备
    if (dev->type != RT_Device_Class_Char){
        LOG_E("rs232 instance initiliaze error, the serial device(%s) type is not char.", name);
        return(RT_NULL);
    }

    // 给RS232实例创建一个可用的内存空间
    hinst = rt_malloc(sizeof(struct rs232_inst));
    if (hinst == RT_NULL){
        LOG_E("rs232 create fail. no memory for rs232 create instance.");
        return(RT_NULL);
    }

    // 创建一个互斥锁
    hinst->lock = rt_mutex_create(name, RT_IPC_FLAG_FIFO);
    if (hinst->lock == RT_NULL){
        rt_free(hinst);
        LOG_E("rs232 create fail. no memory for rs232 create mutex.");
        return(RT_NULL);
    }

    // 创建一个 信号量，用于 通知“一次完整数据包已接收完毕”
    // 初始值为 0：表示当前没有数据可读
    // 接收线程会阻塞在 rt_sem_take() 上，等定时器释放信号量才醒来
    rt_sem_init(&hinst->rx_sem, name, 0, RT_IPC_FLAG_FIFO);
    hinst->received_len = 0;    // 已接收字节数清零
    hinst->serial = dev;        // 保存底层串口句柄
    hinst->status = 0;          // 连接状态：0=未打开
    hinst->byte_tmo = rs232_cal_byte_tmo(baudrate);     // 根据波特率计算字节间隔超时

    // 创建“接收超时”定时器
    hinst->received_over_timer = rt_timer_create(name, rs232_recv_timeout,
                                 hinst,  hinst->byte_tmo,
                                 RT_TIMER_FLAG_ONE_SHOT);
    if (hinst->received_over_timer == RT_NULL)
    {
        rt_mutex_delete(hinst->lock);
        rt_free(hinst);
        LOG_E("rs232 create fail. no memory for rs232 create timer.");
        return(RT_NULL);
    }

    // 配置RS232的串口参数（只配置参数，不开启串口设备）
    rs232_config(hinst, baudrate, (parity?9:8), parity, 0);

    LOG_D("rs232 create success.");

    return(hinst);
}

/*
 * @brief   destory rs232 instance created dynamically
 * @param   hinst       - instance handle
 * @retval  0 - success, other - error
 */
int rs232_destory(rs232_inst_t * hinst)
{
    if (hinst == RT_NULL){
        LOG_E("rs232 destory fail. hinst is NULL.");
        return(-RT_ERROR);
    }

    rs232_disconn(hinst);

    if (hinst->lock){
        rt_mutex_delete(hinst->lock);
        hinst->lock = RT_NULL;
    }

    rt_free(hinst);

    LOG_D("rs232 destory success.");

    return(RT_EOK);
}

/*
 * @brief   config rs232 params
 * @param   hinst       - instance handle
 * @param   baudrate    - baudrate of communication
 * @param   databits    - data bits, 5~8
 * @param   parity      - parity bit, 0~2, 0 - none, 1 - odd, 2 - even
 * @param   stopbits    - stop bits, 0~1, 0 - 1 stop bit, 1 - 2 stop bits
 * @retval  0 - success, other - error
 */
int rs232_config(rs232_inst_t * hinst, int baudrate, int databits, int parity, int stopbits)
{
    struct serial_configure config = RT_SERIAL_CONFIG_DEFAULT;

    if (hinst == RT_NULL){
        LOG_E("rs232 config fail. hinst is NULL.");
        return(-RT_ERROR);
    }

    hinst->byte_tmo = rs232_cal_byte_tmo(baudrate);
    if (hinst->received_over_timer != RT_NULL)
    {
        /* 重置断帧时间 */
        rt_timer_control(hinst->received_over_timer,
                         RT_TIMER_CTRL_SET_TIME,
                         &hinst->byte_tmo);
    }

    config.baud_rate = baudrate;
    config.data_bits = databits;
    config.parity = parity;
    config.stop_bits = stopbits;
    rt_device_control(hinst->serial, RT_DEVICE_CTRL_CONFIG, &config);

    return(RT_EOK);
}

/*
 * @brief   set byte interval timeout for receiving
 * @param   hinst       - instance handle
 * @param   tmo_ms      - byte interval timeout, default is calculated from baudrate
 * @retval  0 - success, other - error
 */
int rs232_set_byte_tmo(rs232_inst_t * hinst, int tmo_ms)
{
    if (hinst == RT_NULL)
    {
        LOG_E("rs232 set byte timeout fail. hinst is NULL.");
        return(-RT_ERROR);
    }

    if (tmo_ms < RS232_BYTE_TMO_MIN)
    {
        tmo_ms = RS232_BYTE_TMO_MIN;
    }
    else if (tmo_ms > RS232_BYTE_TMO_MAX)
    {
        tmo_ms = RS232_BYTE_TMO_MAX;
    }

    hinst->byte_tmo = tmo_ms;
    if (hinst->received_over_timer != RT_NULL)
    {
        /* 重置断帧时间 */
        rt_timer_control(hinst->received_over_timer,
                         RT_TIMER_CTRL_SET_TIME,
                         &hinst->byte_tmo);
    }

    LOG_D("rs232 set byte timeout success. the value is %d.", tmo_ms);

    return(RT_EOK);
}

/*
 * @brief   open rs232 connect
 * @param   hinst       - instance handle
 * @retval  0 - success, other - error
 */
int rs232_connect(rs232_inst_t * hinst)
{
    if (hinst == RT_NULL)
    {
        LOG_E("rs232 connect fail. hinst is NULL.");
        return(-RT_ERROR);
    }

    if (hinst->status == 1)//is connected
    {
        LOG_D("rs232 is connected.");
        return(RT_EOK);
    }

    //必须单个中断接收，DMA发送
    if ( rt_device_open(hinst->serial, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX |RT_DEVICE_FLAG_DMA_TX) != RT_EOK)
    {
        LOG_E("rs232 instance connect error. serial open fail.");
        return(-RT_ERROR);
    }

    hinst->serial->user_data = hinst;
    hinst->serial->rx_indicate = rs232_recv_ind_hook;
    //hinst->serial->tx_complete = rs232_sendover_hook; //如果希望知道发送完成，使用本语句
    hinst->status = 1;

    LOG_D("rs232 connect success.");

    return(RT_EOK);
}

/*
 * @brief   close rs232 connect
 * @param   hinst       - instance handle
 * @retval  0 - success, other - error
 */
int rs232_disconn(rs232_inst_t * hinst)
{
    if (hinst == RT_NULL)
    {
        LOG_E("rs232 disconnect fail. hinst is NULL.");
        return(-RT_ERROR);
    }

    if (hinst->status == 0)//is not connected
    {
        LOG_D("rs232 is not connected.");
        return(RT_EOK);
    }

    rt_mutex_take(hinst->lock, RT_WAITING_FOREVER);

    if (hinst->received_over_timer)
    {
        rt_timer_delete(hinst->received_over_timer);
    }

    if (hinst->serial)
    {
        hinst->serial->rx_indicate = RT_NULL;
        rt_device_close(hinst->serial);
    }

    hinst->status = 0;

    rt_mutex_release(hinst->lock);

    LOG_D("rs232 disconnect success.");

    return(RT_EOK);
}

/*
 * @brief   receive datas from rs232
 * @param   hinst       - instance handle
 * @param   buf         - buffer addr
 * @param   size        - maximum length of received datas
 * @retval  >=0 - length of received datas, <0 - error
 */
int rs232_recv(rs232_inst_t * hinst, void *buf, int size)
{
    int recv_len = 0;

    if (hinst == RT_NULL || buf == RT_NULL || size == 0)
    {
        LOG_E("rs232 receive fail. param error.");
        return(-RT_ERROR);
    }

    if (hinst->status == 0)
    {
        LOG_E("rs232 receive fail. it is not connected.");
        return(-RT_ERROR);
    }

    while(size)
    {
        while (rt_sem_take(&(hinst->rx_sem), RT_WAITING_FOREVER) == RT_EOK)
        {
            // if (rt_mutex_take(hinst->lock, RT_WAITING_FOREVER) != RT_EOK)
            // {
            //     LOG_E("rs232 receive fail. it is destoried.");
            //     return(-RT_ERROR);
            // }
            memcpy(buf ,hinst->received_buf , hinst->received_len);
            recv_len = hinst->received_len;
            hinst->received_len = 0;
            size = 0;
            //rt_mutex_release(hinst->lock);
            break;
        }
    }

    return(recv_len);
}

/*
 * @brief   send datas to rs232
 * @param   hinst       - instance handle
 * @param   buf         - buffer addr
 * @param   size        - length of send datas
 * @retval  >=0 - length of sent datas, <0 - error
 */
int rs232_send(rs232_inst_t * hinst, void *buf, int size)
{
    int send_len = 0;

    if (hinst == RT_NULL || buf == RT_NULL || size == 0)
    {
        LOG_E("rs232 send fail. param is error.");
        return(-RT_ERROR);
    }

    if (hinst->status == 0)
    {
        LOG_E("rs232 send fail. it is not connected.");
        return(-RT_ERROR);
    }

    send_len = rt_device_write(hinst->serial, 0, buf, size);

    return(send_len);
}










