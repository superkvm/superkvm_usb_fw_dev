/**
  ******************************************************************************
  * @file    proto.h
  * @author  www.superkvm.com
  * @version V1.0.0
  * @date    2025-01-01
  * @brief   Protocol header file
  ********************************************************************************
  * @attention
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PROTO_H
#define __PROTO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
/* Protocol constants */
#define PROTO_SYNC_HEAD 0xAB57  // 小端对应0x57, 0xAB
#define CH_ID_LOG    0x05
#define LOG_MSG_ID_LOG 0x01
#pragma pack(1)
/*
|      |HEAD|channel |SN|total len|type|len|content|SUM|
|----  |--- |--------|--|----     |----|---|-------|---|
|length|2   |1       |4 | 2       |  2 | 2 |   N   |2  |
*/
typedef struct {
    uint16_t head;
    uint8_t  channel;
    uint32_t sn;
    uint32_t total_len;
    uint16_t type;
    uint32_t len;
} __attribute__((packed)) proto_header_t;
typedef struct {
    uint16_t product_id;
    uint8_t  app_id;
    uint8_t  module_id;
    char     module_name[16];
    uint16_t log_len;
} log_pkg_head_t;
#pragma pack()
int proto_conv_log(const char* log, uint8_t* data, uint32_t* data_len);

#ifdef __cplusplus
}
#endif

#endif /* __PROTO_H */
