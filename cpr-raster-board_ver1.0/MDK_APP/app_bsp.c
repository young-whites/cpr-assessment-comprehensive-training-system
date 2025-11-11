#include "app_bsp.h"




// 初始化GPIO
void APP_BSP_GPIO_Init(void)
{
    // 初始化为输入浮空模式
    GPIO_Init(GPIOC, GPIO_PIN_6, GPIO_MODE_IN_PU_IT);   // A相
    GPIO_Init(GPIOC, GPIO_PIN_7, GPIO_MODE_IN_PU_IT);   // B相
    GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_IN_PU_IT);   // A相
    GPIO_Init(GPIOD, GPIO_PIN_4, GPIO_MODE_IN_PU_IT);   // B相
}



void GPIO_EXTIConfig(void)
{
    // 配置外部中断
    EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOC, EXTI_SENSITIVITY_RISE_FALL);
    EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD, EXTI_SENSITIVITY_RISE_FALL);
}
