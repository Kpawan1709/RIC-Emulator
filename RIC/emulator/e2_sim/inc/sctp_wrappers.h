/****************************************************************************
*
*  ARICENT -
*
*  Copyright (c) 2009 Aricent.
*
****************************************************************************
* File Details
* ------------
*  $Id: sctp_wrappers.h,v 1.4 2010/10/13 07:02:19 gur57180 Exp $
****************************************************************************
*
*  File Description : 
*
****************************************************************************/
#ifndef _SCTP_WRAPPERS_H
#define _SCTP_WRAPPERS_H


/****************************************************************************
* Project Includes
****************************************************************************/

#include "stacklayer.h"
#include "e2du_global_ctx.h"
#include "e2_utils.h"

#define MAX_PEER_ENB_1    1
#define MAX_LEN_COMM_INFO               22

/****************************************************************************
* Exported Includes
****************************************************************************/
    #ifdef ARICENT_SCTP_IPR
        #include <s_cogbl.h>
        #include <s_cotyps.h>
        #include <s_osmem.h>
        #include <s_uisuif.h>
        #include "s_uisusk.h"
        #include "s_cspl.h"
        #include "s_cotyps.h"
        #include "sctp.h"
        #include "s_select.h"
        #include "sig_ipc_intr.h"
        #include "sig_typs.h"
        #include "sig_cspl_wrap.h"
    #endif

    #ifdef LKSCTP
        //#include <sys/types.h>
        #include <sys/socket.h>
        #include <netinet/sctp.h>

        #define SCTP_ADDRESS_UNREACHABLE           SCTP_ADDR_UNREACHABLE
        #define SCTP_ADDRESS_AVAILABLE             SCTP_ADDR_AVAILABLE
        #define SCTP_COMMUNICATION_UP              SCTP_COMM_UP
        #define SCTP_COMMUNICATION_LOST            SCTP_COMM_LOST
        #define SCTP_SHUTDOWN_COMPLETE             SCTP_SHUTDOWN_COMP
        #define SCTP_CANT_START_ASSOC              SCTP_CANT_STR_ASSOC

        #define SCTP_PARTIAL_DELIVERY              SCTP_PARTIAL_DELIVERY_EVENT
        #define SCTP_ADAPTION_EVENT                SCTP_ADAPTATION_INDICATION

#endif

extern S32 g_sctp_sd_list[MAX_PEER_ENB_1 +1];
extern U8 g_sctp_sd_count;
extern S32 g_m2ap_sctp_sd;
extern S32 g_m2ap_sctp_sd_count;


/****************************************************************************
* Exported Types
****************************************************************************/

/****************************************************************************
* Exported Constants
****************************************************************************/

/****************************************************************************
* Exported Variables
****************************************************************************/
/* All the Active SCTP Sock.desc are set in this GLOBAL variable */
#ifdef LKSCTP
extern S32 g_sctp_server_fd_ipv4;
extern S32 g_sctp_server_fd_ipv6;
extern fd_set sctp_fd;
#endif

/****************************************************************************
* Exported Functions
****************************************************************************/

#define SCTP_PAYLOAD_PROTOCOL_ID_E2CU 18
#define MAX_IP_ADDR            10
#define MAX_SCTP_INIT_ATTEMPT  3
#define MAX_BUFFER_SIZE             30000

#define E2CU_SCTP_ERROR            (-1)
#define SCTP_SOCKET_ERROR            (-1)
#define INVALID_SCTP_SOCKET        (-1)
#define SCTP_SD_OCTET_SIZE          4
#define SCTP_STREAM_ID_SIZE          2
#define SCTP_COMMON_PROC_STREAMS               0

#define SA_FAMILY_T sa_family_t

#define RIC_MESSAGE                        0
#define SCTP_CONN_FAILURE_IND              1
#define SCTP_CONN_RECOVERY_IND             2
#define SCTP_CONN_SHUTDOWN_EVENT           3
#define SCTP_ASSOC_UP_EVENT                4
#define SCTP_ASSOC_DOWN_EVENT              5
#define E2CU_SCTP_PAYLOAD_PROTOCOL_ID      60
#define E2CU_DEFAULT_RIC_SCTP_PORT         38412


e2_bool_et is_sctp_stack_init(void);
#ifdef ARICENT_SCTP_IPR

extern S32 g_sctp_server_fd;
U32 e2cu_sctp_init_stack(
            U8 cspl_already_intialised,
            e2cu_comm_info_t *p_e2cu_comm_info);

#endif

void* e2cu_sctp_receive(
                      QMODULE *sender,
                      QMODULE *receiver,
                      SInt8 *priority);


S32 e2cu_retry_connect(e2cu_gb_context_t *p_e2cu_gb_ctx ,
		     ric_context_t *p_ric_ctx);
S32 e2cu_open_sctp_association(e2cu_gb_context_t *p_e2cu_gb_ctx,
                             ric_context_t *p_ric_ctx,
                             e2cu_comm_info_t *p_e2cu_comm_info);

SInt32 e2cu_sctp_send
(
 SInt32                  socket_desc,
 const void              *p_message,
 socklen_t               msg_len,
 UInt32                  stream_no,
 UInt32                  payload_protocol_id,
 UInt8                   *ip_addr,
 UInt32                  port
 );

S32 e2cu_sctp_association_setup(
        e2cu_gb_context_t *p_e2cu_gb_ctx,
        ric_context_t *p_ric_ctx,
        e2cu_comm_info_t *p_e2cu_comm_info);

e2_return_et e2cu_sctp_close_association(sctp_sd_t  socket);

e2_return_et e2cu_sctp_close_socket(sctp_sd_t  socket);

typedef enum
{
   SCTP_FD_NOT_SET=0,
   E2CU_SCTP_FD_SET
} e2cu_sctp_fd;

#endif
