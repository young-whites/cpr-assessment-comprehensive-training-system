/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-24     Administrator       the first version
 */
#ifndef APPLICATIONS_MACSRAM_INC_23LC1024_TLSF_H_
#define APPLICATIONS_MACSRAM_INC_MEM_TLSF_H_
#include "bsp_sys.h"

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* 初始化外部 SRAM TLSF 堆 */
void sram_tlsf_init(void);

/* 标准接口：与 LVGL 对接 */
void *sram_malloc(size_t size);
void  sram_free(void *ptr);
void *sram_realloc(void *ptr, size_t new_size);

/* 调试：打印堆信息 */
void sram_tlsf_dump(void);

#ifdef __cplusplus
}
#endif





#endif /* APPLICATIONS_MACSRAM_INC_23LC1024_TLSF_H_ */
