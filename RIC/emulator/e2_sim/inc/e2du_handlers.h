/******************************************************************************
*
*   FILE NAME:
*       e2cu_handlers.h
*
*   DESCRIPTION:
*       This header file contains all external handlers provided by E2CU layer
*
*   Copyright (c) 2018, Aricent Inc. All Rights Reserved
*
******************************************************************************/

#ifndef _E2CU_HANDLERS_H_
#define _E2CU_HANDLERS_H_

#include "oam_e2du_intf.h"

#include "gnb_types.h"
#include "cspl.h"

#define E2_MAX_COMM_INFO                                      4
#define E2_MAX_LEN_COMM_INFO                                  22
#define E2_OAM_MAX_EXT_SON_UPPER_LAYER_MODULES                10

#define E2_OAM_MAX_EXT_LOWER_LAYER_MODULES                    2

#ifdef E2DU_SEPARATE_THREAD
extern UInt8 *g_enable_rx_thread;
#endif

typedef struct _sector_comm_info_t
{
    cell_index_t                  cell_index;
    SInt8                  comm_info_lower_layer[E2_OAM_MAX_EXT_LOWER_LAYER_MODULES][E2_MAX_LEN_COMM_INFO];
}sector_comm_info_t;

typedef struct _sector_comm_info_list_t
{
    UInt8                    count;
    sector_comm_info_t    sector_comm_info[E2_MAX_COMM_INFO];
}sector_comm_info_list_t;

typedef struct _comm_info
{
    SInt8      comm_info_upper_layer[E2_OAM_MAX_EXT_SON_UPPER_LAYER_MODULES][E2_MAX_LEN_COMM_INFO];
    sector_comm_info_list_t    sector_comm_info_list;
}comm_info_t;

/* For license validation */
typedef struct comm_info_init_param
{
    UInt32     expiry_duration;
    comm_info_t    comm_info;
}comm_info_init_param_t;

typedef struct thread_arg
{
    QDRIVER driver_id;
    QWAIT * p_qwait;
    UInt8      logical_id;
    pthread_t tid;
}thread_arg_t;

/*****************************************************************************
 *  RIC handler
 *****************************************************************************/

void*
ric_init
(
    void *p_rrc_llim_init_data
);
#ifdef E2DU_MULTI_THREAD_SUPPORT
void* ric_init2
(
 void *p_validate_comm_info_int
);


#endif
#endif /* _E2CU_HANDLERS_H_ */

