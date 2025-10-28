/*
 * bsp_key.c
 *
 *  Created on: Jun 16, 2025
 *      Author: Administrator
 */


#include "bsp_key.h"


/* 上一次稳定状态 & 当前原始采样 */
static key_event_t key_last = {0};
static key_event_t key_cur  = {0};
static uint8_t     debounce_cnt = 0;   /* 连续相同次数 */
#define DEBOUNCE_TH   2               /* 20 ms 稳定即生效 */



char keys[3][3] = { {'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};


/**
 * @brief  第一行第一列的按键执行函数--1
 * @param  None
 * @retval None
 */
static void MatrixKey_Row1_Column1_Press(void)
{
//    LED_Blink(LED_Name_Green, 1, 0, 0);
    rt_kprintf("OK");
}


/**
 * @brief  第二行第一列的按键执行函数--4
 * @param  None
 * @retval None
 */
static void MatrixKey_Row2_Column1_Press(void)
{
//    LED_Blink(LED_Name_Green, 1, 0, 0);
    rt_kprintf("OK");
}


/**
 * @brief  第三行第一列的按键执行函数--7
 * @param  None
 * @retval None
 */
static void MatrixKey_Row3_Column1_Press(void)
{
//    LED_Blink(LED_Name_Green, 1, 0, 0);
    rt_kprintf("OK");
}




/**
 * @brief  第一行第二列的按键执行函数--2
 * @param  None
 * @retval None
 */
static void MatrixKey_Row1_Column2_Press(void)
{
//    LED_Blink(LED_Name_Green, 1, 0, 0);
    rt_kprintf("OK");
}


/**
 * @brief  第二行第二列的按键执行函数--5
 * @param  None
 * @retval None
 */
static void MatrixKey_Row2_Column2_Press(void)
{
//    LED_Blink(LED_Name_Green, 1, 0, 0);
    rt_kprintf("OK");
}


/**
 * @brief  第三行第二列的按键执行函数--8
 * @param  None
 * @retval None
 */
static void MatrixKey_Row3_Column2_Press(void)
{
//    LED_Blink(LED_Name_Green, 1, 0, 0);
    rt_kprintf("OK");
}




/**
 * @brief  第一行第三列的按键执行函数--3
 * @param  None
 * @retval None
 */
static void MatrixKey_Row1_Column3_Press(void)
{
//    LED_Blink(LED_Name_Green, 1, 0, 0);
    rt_kprintf("OK");
}


/**
 * @brief  第二行第三列的按键执行函数--6
 * @param  None
 * @retval None
 */
static void MatrixKey_Row2_Column3_Press(void)
{
//    LED_Blink(LED_Name_Green, 1, 0, 0);
    rt_kprintf("OK");
}


/**
 * @brief  第三行第三列的按键执行函数--9
 * @param  None
 * @retval None
 */
static void MatrixKey_Row3_Column3_Press(void)
{
    rt_kprintf("OK");
}



/* 按键事件回调（非阻塞） */
static void MatrixKey_Event(uint8_t row, uint8_t col, key_state_t st)
{
    if (st == KEY_PRESS) {
        /* 彩色日志 + 文件行号 */
        rt_kprintf("KEY: %c Press\n", keys[row - 1][col - 1]);
        /* 放短任务或发消息给工作线程 */
    }
}



/**
 * @brief  矩阵按键扫描函数
 * @param  无
 * @retval 轮询法：主动循环置低列所对应的引脚，然后循环反复轮询各个行上的按键状态
 */
void MatrixKey_Scan(void)
{
    static uint8_t scan_col = 0;   /* 0 1 2 轮询列 */

    /* ---- 1. 只扫一列，降低 CPU ---- */
    HAL_GPIO_WritePin(Matrixkey_Column1_GPIO_Port, Matrixkey_Column1_Pin,
                      scan_col == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(Matrixkey_Column2_GPIO_Port, Matrixkey_Column2_Pin,
                      scan_col == 1 ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(Matrixkey_Column3_GPIO_Port, Matrixkey_Column3_Pin,
                      scan_col == 2 ? GPIO_PIN_RESET : GPIO_PIN_SET);


    /* ---- 2. 读三行 ---- */
    key_event_t sample = {0};                  /* 本次采样临时变量 */
    for (uint8_t row = 0; row < 3; row++) {
        GPIO_PinState pin = HAL_GPIO_ReadPin(
            row == 0 ? Matrixkey_Row1_GPIO_Port :
            row == 1 ? Matrixkey_Row2_GPIO_Port :
                       Matrixkey_Row3_GPIO_Port,
            row == 0 ? Matrixkey_Row1_Pin :
            row == 1 ? Matrixkey_Row2_Pin :
                       Matrixkey_Row3_Pin);

        if (pin == GPIO_PIN_RESET) {           /* 低电平 = 按下 */
            sample.row  = row + 1;
            sample.col  = scan_col + 1;
            sample.state = KEY_PRESS;
            break;                              /* 一列里只取第一个按下的键 */
        }
    }

    /* 没有按键 -> 状态清零 */
        if (sample.state == KEY_RELEASE)
            sample.row = sample.col = 0;

        /* ---- 3. 消抖状态机 ---- */
        if (sample.row == key_cur.row &&
            sample.col == key_cur.col &&
            sample.state == key_cur.state) {
            /* 连续相同 -> 计数++ */
            if (debounce_cnt < DEBOUNCE_TH)
                debounce_cnt++;
        } else {
            /* 状态变化 -> 重新开始计数 */
            key_cur = sample;
            debounce_cnt = 0;
        }

        /* ---- 4. 达到稳定阈值 -> 生成一次事件 ---- */
        if (debounce_cnt == DEBOUNCE_TH) {
            if (key_cur.state == KEY_PRESS &&
                (key_cur.row != key_last.row ||
                 key_cur.col != key_last.col)) {
                /* 新按键按下 */
                MatrixKey_Event(key_cur.row, key_cur.col, KEY_PRESS);
            } else if (key_cur.state == KEY_RELEASE &&
                       key_last.state == KEY_PRESS) {
                /* 原按键松开（可选） */
                MatrixKey_Event(key_last.row, key_last.col, KEY_RELEASE);
            }
            key_last = key_cur;              /* 保存稳定状态 */
            debounce_cnt++;                    /* 避免重复触发 */
        }

        /* ---- 5. 列号++，下次进函数扫下一列 ---- */
        scan_col++;
        if (scan_col >= 3) scan_col = 0;
}




/*---------------------------------------------------------------------------------------------------------------*/
/* 以下是按键扫描线程的创建以及回调函数                                                                          */
/*---------------------------------------------------------------------------------------------------------------*/
#define USE_SOFT_TIMER  0   // 使用软件定时器
#define USE_HARD_TIMER  0   // 使用硬件定时器
#define USE_THREAD_TASK 1   // 使用RT-Thread线程


#if USE_SOFT_TIMER
/**
  * @brief  ledTimer Callback Function
  * @retval void
  */
static void keyTimer_callback(void* parameter)
{
    MatrixKey_Scan();
}



/**
  * @brief  keyTimer initialize
  * @retval int
  */
int keyTimer_Init(void)
{
    static rt_timer_t keyTimer;
    /* 创建led软件定时器线程 */
    keyTimer = rt_timer_create("keyTimer_callback", keyTimer_callback, RT_NULL, 10, RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_SOFT_TIMER);
    /* 如果句柄创建成功，就开启ledTimer软件定时器 */
    if(keyTimer != RT_NULL)
    {
        rt_kprintf("PRINTF:%d. keyTimer initialize succeed!\r\n",Record.kprintf_cnt++);
        rt_timer_start(keyTimer);
    }

    return RT_EOK;
}
INIT_APP_EXPORT(keyTimer_Init);

#elif USE_HARD_TIMER

#define HWTIMER6_DEV_NAME    "timer6"    /* 定时器名称 */
rt_device_t hw6_dev = RT_NULL;           /* 定时器设备句柄 */
rt_hwtimerval_t timeout_s;               /* 定时器超时值 */

/* 定时器超时回调函数 */
static rt_err_t timer6_timeout_cb(rt_device_t dev, rt_size_t size)
{

    MatrixKey_Scan();
//    LOG_I("Timer6 timeout @ %d\n", rt_tick_get());
//    rt_device_read(hw6_dev, 0, &timeout_s, sizeof(timeout_s));
//    LOG_I("LOG_I(%d): Read: Sec = %d, Usec = %d\n", Record.ulog_cnt++, timeout_s.sec, timeout_s.usec);
    return 0;
}


int hwtimer6_init(void)
{
    rt_err_t ret = RT_EOK;

    /* 定时器模式 */
    rt_hwtimer_mode_t mode;
    /* 计数频率 */
    rt_uint32_t freq = 1000000;

    /* 查找定时器设备 */
    hw6_dev = rt_device_find(HWTIMER6_DEV_NAME);
    if (hw6_dev == RT_NULL)
    {
        rt_kprintf("hwtimer sample run failed! can't find %s device!\n", HWTIMER6_DEV_NAME);
        return RT_ERROR;
    }

    /* 以读写方式打开设备 */
    ret = rt_device_open(hw6_dev, RT_DEVICE_OFLAG_RDWR);
    if (ret != RT_EOK)
     {
         rt_kprintf("open %s device failed!\n", HWTIMER6_DEV_NAME);
         return ret;
     }

    /* 设置超时回调函数 */
    rt_device_set_rx_indicate(hw6_dev, timer6_timeout_cb);

    /* 设置计数频率(默认1Mhz或支持的最小计数频率) */
    ret = rt_device_control(hw6_dev, HWTIMER_CTRL_FREQ_SET, &freq);
    if (ret != RT_EOK)
    {
        rt_kprintf("set frequency failed! ret is :%d\n", ret);
        return ret;
    }

    /* 设置模式为周期性定时器 */
    mode = HWTIMER_MODE_PERIOD;
    ret = rt_device_control(hw6_dev, HWTIMER_CTRL_MODE_SET, &mode);
    if (ret != RT_EOK)
    {
        rt_kprintf("set mode failed! ret is :%d\n", ret);
        return ret;
    }


    /* 设置定时器超时值为10ms并启动定时器 */
    timeout_s.sec = 0;      /* 秒 */
    timeout_s.usec = 10000;  /* 微秒 */

    if (rt_device_write(hw6_dev, 0, &timeout_s, sizeof(timeout_s)) != sizeof(timeout_s))
    {
        rt_kprintf("set timeout value failed\n");
        return RT_ERROR;
    }

    /* 读取定时器当前值 */
      rt_device_read(hw6_dev, 0, &timeout_s, sizeof(timeout_s));
      LOG_I("LOG_I(%d): Read: Sec = %d, Usec = %d\n",Record.ulog_cnt++, timeout_s.sec, timeout_s.usec);

      return ret;
}

#elif USE_THREAD_TASK

/**
  * @brief  This thread entry is used for key scan
  * @retval void
  */
void Matrixkey_Thread_entry(void* parameter)
{

    for(;;)
    {
        MatrixKey_Scan();
        rt_thread_mdelay(10);
    }
}



/**
  * @brief  This is a Initialization for matrix key
  * @retval int
  */
rt_thread_t Matrixkey_Task_Handle = RT_NULL;
int Matrixkey_Thread_Init(void)
{
    Matrixkey_Task_Handle = rt_thread_create("Matrixkey_Thread_entry", Matrixkey_Thread_entry, RT_NULL, 4096, 10, 50);
    /* 检查是否创建成功,成功就启动线程 */
    if(Matrixkey_Task_Handle != RT_NULL)
    {
        LOG_I("LOG:%d. Matrixkey_Thread_entry is Succeed.",Record.ulog_cnt++);
        rt_thread_startup(Matrixkey_Task_Handle);
    }
    else {
        LOG_I("LOG:%d. Matrixkey_Thread_entry is Failed.",Record.ulog_cnt++);
    }

    return RT_EOK;
}
INIT_APP_EXPORT(Matrixkey_Thread_Init);


#endif
