#include "app_message.h"




/**
  * @brief  发送按压深度数据（带校验和）
  * @param  depth_mm: 深度值，单位 mm
  * @retval None
  */
void USART1_SendDepth(float depth_mm)
{
    uint8_t buf[6];
    uint16_t depth_01mm = (uint16_t)(depth_mm * 10); // 0.1mm精度

    buf[0] = 0xAA;                 // 帧头
    buf[1] = 0x02;                 // 数据长度
    buf[2] = (depth_01mm >> 8) & 0xFF;
    buf[3] = depth_01mm & 0xFF;

    uint8_t checksum = 0;
    for (uint8_t i = 0; i < 4; i++) {
        checksum += buf[i];
    }
    buf[4] = checksum;             // 校验和
    buf[5] = 0x55;                 // 帧尾

    USART1_SendData(buf, 6);
}













