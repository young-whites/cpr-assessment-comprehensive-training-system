/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-29     18452       the first version
 */
#ifndef APPLICATIONS_MACAPP_INC_RTT_HWTIMER_STATE_MACHINE_H_
#define APPLICATIONS_MACAPP_INC_RTT_HWTIMER_STATE_MACHINE_H_

#include "bsp_sys.h"

#define USE_HWTIMER_STATE_MACHINE 0
#if USE_HWTIMER_STATE_MACHINE

int hwtimer6_init(void);

#endif

#endif /* APPLICATIONS_MACAPP_INC_RTT_HWTIMER_STATE_MACHINE_H_ */
