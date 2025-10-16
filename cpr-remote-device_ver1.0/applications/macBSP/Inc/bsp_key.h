/*
 * bsp_key.h
 *
 *  Created on: May 16, 2024
 *      Author: zphu
 */

#ifndef MACBSP_INC_BSP_KEY_H_

#define MACBSP_INC_BSP_KEY_H_

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


void MatrixKey_Scan(void);


#endif /* MACBSP_INC_BSP_KEY_H_ */
