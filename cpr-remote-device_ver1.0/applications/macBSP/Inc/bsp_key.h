/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-10-29     Administrator       the first version
 */
#ifndef APPLICATIONS_MACBSP_INC_BSP_KEY_H_
#define APPLICATIONS_MACBSP_INC_BSP_KEY_H_
#include "bsp_sys.h"






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


/* ---------------  非阻塞扫描专用  --------------- */
typedef enum {
    KEY_RELEASE = 0,
    KEY_PRESS   = 1
} key_state_t;


typedef struct {
    uint8_t row;        /* 1~3 */
    uint8_t col;        /* 1~3 */
    uint8_t state;      /* KEY_PRESS / KEY_RELEASE */
} key_event_t;


void MatrixKey_Scan(void);
int keyTimer_Init(void);
int hwtimer6_init(void);




#endif /* APPLICATIONS_MACBSP_INC_BSP_KEY_H_ */
