/*! \file e2_utils.h
 *  \brief This file contains the enums, struct, constants definitions for E2-CU APPS.
  */
/*!

*  \copyright {Copyright (c) 2009, Aricent Inc. All Rights Reserved}

*/


#ifndef _E2_UTILS_H_
#define _E2_UTILS_H_
/*
* Header File Includes
*/

/*! \headerfile cspl.h <>
 */
//#include <cspl.h>

/*! \headerfile stacklayer.h <>
 */
//#include <stacklayer.h>

/*! \headerfile string.h <>
 */
#include <string.h>

/*! \headerfile mqueue.h <>
 */
#include    <mqueue.h>
 
/*! \headerfile math.h <>
 */
#include    <math.h>
/*! \headerfile tgmath.h <>
 */
#include    <tgmath.h>
/*! \headerfile sys/timeb.h <>
 */
#include <sys/timeb.h>

/*! \headerfile lteLogger.h <>
 */
// #include "lteLogger.h"

/*! \headerfile sched.h <>
 */

#include <sched.h>


//#include <gnb_common_utils.h>

#include "gnb_defines.h" 
#include "e2du_fsm.h" 

#include "gnb_common_utils.h"
#ifdef E2DU_MULTI_THREAD_SUPPORT
#include "ylib-squeue.h"
#include "list_wrapper.h"
#endif
#define E2CU_ASN1_BUFFER_LENGTH     8192
#define E2CU_PROTOCOL_EVENT         GNB_DETAILED
#ifdef E2DU_MULTI_THREAD_SUPPORT
#define GET_MEM_FROM_POOL(dataType,data_p,size,pSize) \
{\
    data_p=(dataType *)getMemFromPool(size,pSize);\
    if(PNULL == data_p)\
    {\
    }\
}

//typedef UInt16   cell_index_t;
//cell_index_t     cell_index = 0;
typedef struct _asn_msg_buf_t
{
    UInt64 *p_asn_msg_buff;
    UInt32 asn_msg_len;
}asn_msg_buf_t;

#if 0
typedef struct _e2du_retx_node1_t
{
    NR_SNODE       anchor_node;
    UInt16         int_dst_id;
    UInt16         src_id;
    UInt16         api_id;
    asn_msg_buf_t  asn_msg_buf;
}e2du_retx_node1_t;

typedef struct _queue_msg_buf_t 
{
    UInt8 *p_asn_msg_buff; 
    UInt16 asn_msg_len;    
}queue_msg_buf_t;

typedef struct _e2du_retx_queue_node_t
{
    NR_LIST_NODE anchor_node;
    UInt16 int_dst_id;
    UInt16 src_id;
    UInt16 api_id;
    queue_msg_buf_t queue_msg_buf;
}e2du_retx_queue_node_t;
#endif 

typedef struct _e2du_queue_node_t
{
   NR_SNODE anchor_node;
   void *msg_ptr;
   UInt32 msg_len;
   UInt32 api_id;
   UInt16 cell_index;  
} e2du_queue_node_t;

#endif
typedef signed int          S32;
typedef unsigned int          U32;
typedef UInt8          U8;
typedef UInt16          U16;
typedef Int8          S8;
typedef UInt32          U32;

typedef QTIMER                    e2cu_timer_t;

typedef UInt16                    e2cu_timer_duration_t;

void e2cu_stop_timer(e2cu_timer_t timer);

#define E2_MEMCPY           memcpy_wrapper
#define E2CU_INDEX          3

QTIMER
e2cu_start_timer (
 /* Duration (in milliseconds) of the timer to be started */
 UInt32         timer_duration,
 /* Timer data that will be attached to timer */
 void        *p_timer_data,
 UInt16         timer_data_size,    /* Size of timer data */
 UInt8  is_repeated         /* Indicates whether timer is repeated */
);


UInt16
e2_get_src_module_id (
 void *p_header
 );


UInt16
e2_get_word_from_header (
    UInt8 *p_header
);

typedef enum {
    E2_FALSE,
    E2_TRUE
} e2_bool_et;

void
e2_mem_Free
(
 void *p_buffer,
 const char *func,
 const unsigned int line
 );

typedef struct
{
    UInt16        transaction_id;
    UInt16        source;
    UInt16        destination;
    UInt16        api_id;
    UInt16        msg_size;
}interface_api_header;

typedef struct _e2_rrc_msg_t
{

    void                    *p_msg_data;     
    
}e2_rrc_msg_t;


typedef enum
{
    E2_INDEX_ERR = -1,
    E2_FAILURE,
    E2_SUCCESS,
    E2_PARTIAL_SUCCESS,
    E2_CELL_INVALID_STATE_FOR_PWS
}e2_return_et;

e2_return_et e2cu_check_cspl_header ( UInt8 *p_api);


void
e2_free
(
 void *p_var
 );


#ifndef PNULL
/*! \def PNULL
 *  */
#define PNULL                                                                   NULL
#endif

/*! \def E2_NULL
 *  */
#define E2_NULL                                                        0


#define E2_ZERO 0


#ifndef _PNULL_
#define _PNULL_
/*! \def RRM_PNULL
 *  */
#define E2_PNULL                                               ((void *)0)
#endif

void*
e2_mem_Get
(
 UInt32 size, /* Size of buffer which will be allocated */
 const char *func, 
 const unsigned int line
 );

#define E2_API_HEADER_SIZE                  16
#define E2_VERSION_ID       0x01
#define EXT_MSG_API_OFFSET                              6

#define EXT_MSG_BUF_LEN_OFFSET                          8

#define e2_mem_get(size)       e2_mem_Get(size,__func__,__LINE__)
#define e2_mem_free(p_buffer)  e2_mem_Free(p_buffer,__func__,__LINE__)

#define E2_MEMSET			memset

#define E2_BUFFER_SHOULD_BE_RELEASED               1
#ifdef E2DU_MULTI_THREAD_SUPPORT
#define E2DU_STACK_MODULE_ID 207    
#endif


UInt32 e2cu_get_sctp_sd(UInt32 *p_header);
UInt16 e2cu_get_stream_id(UInt16 *p_header);

#endif // _E2CU_UTILS_H_
