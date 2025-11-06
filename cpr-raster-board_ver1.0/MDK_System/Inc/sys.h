#ifndef __SYS_H
#define __SYS_H
#include "stm8s.h"


/*System header file******************/
#include "stdarg.h"
#include "stdio.h"
#include "string.h"





/*Custom header file*****************/
#include "General_TIM.h"
#include "usart.h"
/*GPIO Port marco definition********/
#include "stm8s.h"
#include "stm8s_uart1.h"
#include "stm8s_gpio.h"
#include "stm8s_flash.h"





void System_Clock_Config(void);
void System_ShutDown(void);
void System_BootUp(void);

#endif /*__SYS_H*/