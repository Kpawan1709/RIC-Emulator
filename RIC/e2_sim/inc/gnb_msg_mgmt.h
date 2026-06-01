/******************************************************************************
*
*   FILE NAME:
*       gnb_msg_mgmt.h
*
*   DESCRIPTION:
*       This header file contains GNB messages management functions
*
*
*   Copyright (c) 2018, Aricent Inc. All Rights Reserved
*
******************************************************************************/

#ifndef _GNB_MSG_MGMT_H_
#define _GNB_MSG_MGMT_H_

#include "cspl.h" 

#define GNB_API_HEADER_SIZE             16

#define GNB_API_INTERFACE_HEADER_CELL_INDEX 10
#ifdef E2CU_MU_MIMO_CHANGES
#define GNB_INTERFACE_API_HEADER_SIZE   16
#endif
#define GNB_FULL_INTERFACE_HEADERS_SIZE \
    (GNB_API_HEADER_SIZE + GNB_INTERFACE_API_HEADER_SIZE)

#define GNB_API_INTERFACE_HEADER_SEGMENT_NUMBER 12
#define GNB_API_INTERFACE_HEADER_MORE_SEGMENT   13

#define GNB_API_INTERFACE_HEADER_CELL_INDEX 10

/* Typedef for callback function used while sending pup encoded message */
typedef UInt8 (*pup_send_callback) (void* p_msg, UInt16 destModId);

UInt8
gnb_get_version
(
    void *p_api
);

gnb_module_id_t
gnb_get_src_module_id
(
    void *p_api
);

gnb_module_id_t
gnb_get_dst_module_id
(
    void *p_api
);

UInt16
gnb_get_api_id
(
    UInt8 *p_api
);

UInt16
gnb_get_api_buf_size
(
    UInt8 *p_api
);

UInt16
gnb_get_cell_index
(
    void *p_api /* external API message */
);

void gnb_set_api_buf_size
(
    UInt8      *p_header,      /* RRC header */
    UInt16     api_buf_size    /* API message size */
);

void
gnb_construct_api_header
(
    UInt8                  *p_header,
    UInt8                  version_id,
    gnb_module_id_t     src_module_id,
    gnb_module_id_t     dst_module_id,
    UInt16                 api_id,
    UInt32                 api_buf_size
);


UInt16
gnb_get_transaction_id
(
    void *p_api
);

void
gnb_construct_interface_api_header
(
    UInt8                  *p_header,
    UInt16                 transaction_id,
    gnb_module_id_t     src_module_id,
    gnb_module_id_t     dst_module_id,
    UInt16                 api_id,
    UInt16                 api_buf_size,
    UInt16                  cell_index
);

void gnb_set_api_dest_id
(
    UInt8 *msg, 
    gnb_module_id_t dst_module_id
);

void* gnb_msg_mem_get
(
    gnb_size_t size /* Size of buffer which will be allocated */
);

void gnb_msg_mem_free
(
    void *p_buffer /* Pointer to buffer which will be freed */
);

#endif /* _GNB_MSG_MGMT_H_ */
