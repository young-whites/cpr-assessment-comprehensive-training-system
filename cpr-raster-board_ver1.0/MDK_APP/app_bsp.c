#include "app_bsp.h"




// 初始化GPIO
void APP_BSP_GPIO_Init(void)
{
    // 初始化为输入浮空模式
    GPIO_Init(GPIOC,GPIO_PIN_6,GPIO_MODE_IN_FL_NO_IT);
    GPIO_Init(GPIOC,GPIO_PIN_7,GPIO_MODE_IN_FL_NO_IT);
    GPIO_Init(GPIOD,GPIO_PIN_3,GPIO_MODE_IN_FL_NO_IT);
    GPIO_Init(GPIOD,GPIO_PIN_4,GPIO_MODE_IN_FL_NO_IT);
}








"