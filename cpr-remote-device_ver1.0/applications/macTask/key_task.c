/*
 * bsp_key.c
 *
 *  Created on: Jun 16, 2025
 *      Author: Administrator
 */


#include "bsp_sys.h"


void MatrixKey_Scan(void);
int keyTimer_Init(void);
int hwtimer6_init(void);

typedef enum
{
    Matrix_Column_1 = (0x01),
    Matrix_Column_2,
    Matrix_Column_3,
}MatrixKey_ColumnName_TypeDef;



typedef enum
{
    Matrix_Row_1 = (0x01),
    Matrix_Row_2,
    Matrix_Row_3,
}MatrixKey_RowName_TypeDef;


typedef enum
{
    Matrix_RESET = 0,
    Matrix_SET
}MatrixKey_Status_TypeDef;



char keys[3][3] = { {'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};


/**
 * @brief  第一行第一列的按键执行函数
 * @param  None
 * @retval None
 */
static void MatrixKey_Row1_Column1_Press(void)
{
//    LED_Blink(LED_Name_Green, 1, 0, 0);
}


/**
 * @brief  第二行第一列的按键执行函数
 * @param  None
 * @retval None
 */
static void MatrixKey_Row2_Column1_Press(void)
{
//    LED_Blink(LED_Name_Green, 1, 0, 0);
}


/**
 * @brief  第三行第一列的按键执行函数
 * @param  None
 * @retval None
 */
static void MatrixKey_Row3_Column1_Press(void)
{
//    LED_Blink(LED_Name_Green, 1, 0, 0);
}




/**
 * @brief  第一行第二列的按键执行函数
 * @param  None
 * @retval None
 */
static void MatrixKey_Row1_Column2_Press(void)
{
//    LED_Blink(LED_Name_Green, 1, 0, 0);
}


/**
 * @brief  第二行第二列的按键执行函数
 * @param  None
 * @retval None
 */
static void MatrixKey_Row2_Column2_Press(void)
{
//    LED_Blink(LED_Name_Green, 1, 0, 0);
}


/**
 * @brief  第三行第二列的按键执行函数
 * @param  None
 * @retval None
 */
static void MatrixKey_Row3_Column2_Press(void)
{
//    LED_Blink(LED_Name_Green, 1, 0, 0);
}




/**
 * @brief  第一行第三列的按键执行函数
 * @param  None
 * @retval None
 */
static void MatrixKey_Row1_Column3_Press(void)
{
//    LED_Blink(LED_Name_Green, 1, 0, 0);
}


/**
 * @brief  第二行第三列的按键执行函数
 * @param  None
 * @retval None
 */
static void MatrixKey_Row2_Column3_Press(void)
{
//    LED_Blink(LED_Name_Green, 1, 0, 0);
}


/**
 * @brief  第三行第三列的按键执行函数
 * @param  None
 * @retval None
 */
static void MatrixKey_Row3_Column3_Press(void)
{
//    LED_Blink(LED_Name_Green, 1, 0, 0);
}















/**
 * @brief  矩阵按键扫描函数
 * @param  无
 * @retval 轮询法：主动循环置低列所对应的引脚，然后循环反复轮询各个行上的按键状态
 */
void MatrixKey_Scan(void)
{
    {
        HAL_GPIO_WritePin(Matrixkey_Column1_GPIO_Port, Matrixkey_Column1_Pin, (GPIO_PinState)Matrix_RESET);
        HAL_GPIO_WritePin(Matrixkey_Column2_GPIO_Port, Matrixkey_Column2_Pin, (GPIO_PinState)Matrix_SET);
        HAL_GPIO_WritePin(Matrixkey_Column3_GPIO_Port, Matrixkey_Column3_Pin, (GPIO_PinState)Matrix_SET);

        /* 读取当前行的状态 -- 进一步锁定矩阵按键的位置 */
        if (HAL_GPIO_ReadPin(Matrixkey_Row1_GPIO_Port, Matrixkey_Row1_Pin) == (GPIO_PinState)Matrix_RESET) {
            /* 等待释放 */
            while (HAL_GPIO_ReadPin(Matrixkey_Row1_GPIO_Port, Matrixkey_Row1_Pin) == (GPIO_PinState)Matrix_RESET);
            /* 按下后的执行函数 */
            MatrixKey_Row1_Column1_Press();
        }
        else if (HAL_GPIO_ReadPin(Matrixkey_Row2_GPIO_Port, Matrixkey_Row2_Pin) == (GPIO_PinState)Matrix_RESET) {
            /* 等待释放 */
            while (HAL_GPIO_ReadPin(Matrixkey_Row2_GPIO_Port, Matrixkey_Row2_Pin) == (GPIO_PinState)Matrix_RESET);
            /* 按下后的执行函数 */
            MatrixKey_Row2_Column1_Press();
        }
        else if (HAL_GPIO_ReadPin(Matrixkey_Row3_GPIO_Port, Matrixkey_Row3_Pin) == (GPIO_PinState)Matrix_RESET) {
            /* 等待释放 */
            while (HAL_GPIO_ReadPin(Matrixkey_Row3_GPIO_Port, Matrixkey_Row3_Pin) == (GPIO_PinState)Matrix_RESET);
            /* 按下后的执行函数 */
            MatrixKey_Row3_Column1_Press();

        }
    }




    {
        HAL_GPIO_WritePin(Matrixkey_Column1_GPIO_Port, Matrixkey_Column1_Pin, (GPIO_PinState)Matrix_SET);
        HAL_GPIO_WritePin(Matrixkey_Column2_GPIO_Port, Matrixkey_Column2_Pin, (GPIO_PinState)Matrix_RESET);
        HAL_GPIO_WritePin(Matrixkey_Column3_GPIO_Port, Matrixkey_Column3_Pin, (GPIO_PinState)Matrix_SET);
        /* 读取当前行的状态 -- 进一步锁定矩阵按键的位置 */
        if (HAL_GPIO_ReadPin(Matrixkey_Row1_GPIO_Port, Matrixkey_Row1_Pin) == (GPIO_PinState)Matrix_RESET) {
            /* 等待释放 */
            while (HAL_GPIO_ReadPin(Matrixkey_Row1_GPIO_Port, Matrixkey_Row1_Pin) == (GPIO_PinState)Matrix_RESET);
            /* 按下后的执行函数 */
            MatrixKey_Row1_Column2_Press();
        }
        else if (HAL_GPIO_ReadPin(Matrixkey_Row2_GPIO_Port, Matrixkey_Row2_Pin) == (GPIO_PinState)Matrix_RESET) {
            /* 等待释放 */
            while (HAL_GPIO_ReadPin(Matrixkey_Row2_GPIO_Port, Matrixkey_Row2_Pin) == (GPIO_PinState)Matrix_RESET);
            /* 按下后的执行函数 */
            MatrixKey_Row2_Column2_Press();
        }
        else if (HAL_GPIO_ReadPin(Matrixkey_Row3_GPIO_Port, Matrixkey_Row3_Pin) == (GPIO_PinState)Matrix_RESET) {
            /* 等待释放 */
            while (HAL_GPIO_ReadPin(Matrixkey_Row3_GPIO_Port, Matrixkey_Row3_Pin) == (GPIO_PinState)Matrix_RESET);
            /* 按下后的执行函数 */
            MatrixKey_Row3_Column2_Press();
        }
    }



    {
        HAL_GPIO_WritePin(Matrixkey_Column1_GPIO_Port, Matrixkey_Column1_Pin, (GPIO_PinState)Matrix_SET);
        HAL_GPIO_WritePin(Matrixkey_Column2_GPIO_Port, Matrixkey_Column2_Pin, (GPIO_PinState)Matrix_SET);
        HAL_GPIO_WritePin(Matrixkey_Column3_GPIO_Port, Matrixkey_Column3_Pin, (GPIO_PinState)Matrix_RESET);
        /* 读取当前行的状态 -- 进一步锁定矩阵按键的位置 */
        if (HAL_GPIO_ReadPin(Matrixkey_Row1_GPIO_Port, Matrixkey_Row1_Pin) == (GPIO_PinState)Matrix_RESET) {
            /* 等待释放 */
            while (HAL_GPIO_ReadPin(Matrixkey_Row1_GPIO_Port, Matrixkey_Row1_Pin) == (GPIO_PinState)Matrix_RESET);
            /* 按下后的执行函数 */
            MatrixKey_Row1_Column3_Press();
        }
        else if (HAL_GPIO_ReadPin(Matrixkey_Row2_GPIO_Port, Matrixkey_Row2_Pin) == (GPIO_PinState)Matrix_RESET) {
            /* 等待释放 */
            while (HAL_GPIO_ReadPin(Matrixkey_Row2_GPIO_Port, Matrixkey_Row2_Pin) == (GPIO_PinState)Matrix_RESET);
            /* 按下后的执行函数 */
            MatrixKey_Row2_Column3_Press();

        }
        else if (HAL_GPIO_ReadPin(Matrixkey_Row3_GPIO_Port, Matrixkey_Row3_Pin) == (GPIO_PinState)Matrix_RESET) {
            /* 等待释放 */
            while (HAL_GPIO_ReadPin(Matrixkey_Row3_GPIO_Port, Matrixkey_Row3_Pin) == (GPIO_PinState)Matrix_RESET);
            /* 按下后的执行函数 */
            MatrixKey_Row3_Column3_Press();

        }
    }
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
