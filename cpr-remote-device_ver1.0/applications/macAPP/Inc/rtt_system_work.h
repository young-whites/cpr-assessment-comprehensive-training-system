/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2024-11-19     teati       the first version
 */
#ifndef APPLICATIONS_MACAPP_INC_RTT_SYSTEM_WORK_H_

#define APPLICATIONS_MACAPP_INC_RTT_SYSTEM_WORK_H_
#include "bsp_sys.h"


#define USE_SOFT_STATE_MACHINE 0
#if USE_SOFT_STATE_MACHINE
int sysTimer_Init(void);
#endif


#endif /* APPLICATIONS_MACAPP_INC_RTT_SYSTEM_WORK_H_ */
