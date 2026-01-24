/**
  ******************************************************************************
  * @file    proto.c
  * @author  www.superkvm.com
  * @version V1.0.0
  * @date    2025-01-01
  * @brief   Protocol implementation
  ********************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "proto.h"
#include <string.h>
uint32_t                  global_sn = 0; 
int proto_conv_log(const char* log, uint8_t* data, uint32_t* data_len)
{
    proto_header_t header;
    header.head = PROTO_SYNC_HEAD;
    header.channel = CH_ID_LOG;
    header.sn = global_sn++;
    header.total_len = 6 + sizeof(log_pkg_head_t) + strlen(log) + 1;
    header.type = LOG_MSG_ID_LOG;
    header.len = sizeof(log_pkg_head_t) + strlen(log) + 1;
    //printf("log content len:%d\n", header.len);

    memcpy(data, &header, sizeof(proto_header_t));

    log_pkg_head_t log_head = {0};
    log_head.product_id = 102;
    log_head.app_id = 3;
    log_head.module_id = 0;
    strcpy(log_head.module_name, "usb");
    log_head.log_len = strlen(log) + 1;

    memcpy(data + sizeof(proto_header_t), &log_head, sizeof(log_pkg_head_t));
    memcpy(data + sizeof(proto_header_t) + sizeof(log_pkg_head_t), log, strlen(log) + 1);

    //*(uint32_t*)(data + sizeof(proto_header_t) + sizeof(log_pkg_head_t) + strlen(log) + 1) = get_mc_add_crc(data, sizeof(proto_header_t) + sizeof(log_pkg_head_t) + strlen(log) + 1);

    *data_len = sizeof(proto_header_t) + sizeof(log_pkg_head_t) + strlen(log) + 1 + 4;
    return 0;
}
