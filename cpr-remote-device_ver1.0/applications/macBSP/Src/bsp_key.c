/*
 * bsp_key.c
 *
 *  Created on: Jun 16, 2025
 *      Author: Administrator
 */


#include "bsp_key.h"



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
    Matrixkey_Task_Handle = rt_thread_create("Matrixkey_Thread_entry", Matrixkey_Thread_entry, RT_NULL, 4096, 9, 50);
    /* 检查是否创建成功,成功就启动线程 */
    if(Matrixkey_Task_Handle != RT_NULL)
    {
        rt_kprintf("PRINTF:%d. Matrixkey_Thread_entry is Succeed!! \r\n",Record.kprintf_cnt++);
        rt_thread_startup(Matrixkey_Task_Handle);
    }
    else {
        rt_kprintf("PRINTF:%d. Matrixkey_Thread_entry is Failed \r\n",Record.kprintf_cnt++);
    }

    return RT_EOK;
}
INIT_APP_EXPORT(Matrixkey_Thread_Init);
