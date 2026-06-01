/*******************************************************************************
 *
 *  FILE NAME   : ric_md.h
 *
 *  DESCRIPTION : This file contains the structure and function declaration 
 *                required for e2cu message distributor.
 *
 *  Copyright 2018, Aricent Inc.
 *
 *******************************************************************************/
#if defined (E2CU_MU_MIMO_CHANGES) || defined (E2CU_QOS_CHANGES) || defined (E2CU_KPM_CHANGES)

#ifndef _RIC_MD_H_
#define _RIC_MD_H_

#include "e2cu_handlers.h"
#include <cspl.h>
#include "e2cu_defines.h"
#include "e2cu_global_ctx.h"
#include "search_tree_wrap.h"
#include "e2_utils.h"
#include "e2cu_asn_wrapper_utils.h"
#define E2CU_COMM_RECD         0x01   /* 0 0 0 0 0 0 0 1 */
#define E2CU_PROV_RECD         0x02   /* 0 0 0 0 0 0 1 0 */
#define E2CU_OAM_PROV_REQ_RECD 0x80   /* 1 0 0 0 0 0 0 0 */
#define MAX_NUM_SCTP_STREAM    10


SInt32 ric_process_msg 
( 
    void    *p_api,    /* Pointer for incoming message for E2CU */
    void    *p_gl_ctx  /* Not used at E2 instead global context is used */
);

void ric_process_timer_msg
(
    QTIMER       timer_id,      /* Timer ID of the Expired Timer */
    void        *p_timer_buf,  /* Pointer to the timer buffer allocated when a timer is stated */
    void        *p_gl_ctx      /* Not used at E2-CU instead global context is used */
);

typedef struct _ric_info_t {
    UInt32             bitmask;
    ip_address_t       ip_addr[MAX_NUM_IP_ADDR];
    UInt16             port;
    ipv6_address_t     ipv6_addr[MAX_NUM_IP_ADDR];
    SInt32             sctp_sd;
}ric_info_t;

typedef struct _stream_info_t
{
    /*The array holds the stream ids of an SCTP association.
    */
    UInt16 stream_ids[MAX_NUM_SCTP_STREAM];

    /*This field is used to distribute streams among UEs in a 
     *Round Robin fashion.
     */
    UInt8 stream_idx_returned;

    /*The field represents total number of streams present between 
     * E2-CU and RIC.
     */
    UInt8  number_of_streams;

}stream_info_t;

typedef struct _ric_context_t
{
    /*It is the socket descriptor of an SCTP end point.
    */
    SInt32 sctp_sd;

    /*This contains description of streams present between a 
     * particular MME and eNB.
     */
    stream_info_t stream_info;
    /*Timer ID of timer started for connection recovery. 
    */
    QTIMER ric_timer_id;
    UInt8 current_ric_state;
    /* It represents present state of the eNB Configuration
     * update State Machine 
     */
    UInt8 current_enb_config_update_state;
    UInt8 ric_id;
    UInt32 is_conn_ongoing ;
    /*Count to retry select in case of EINPROGRESS error*/
    UInt8 sctp_einprogress_retry_count;
    /*State maintained in case of EINPROGRESS error*/
    UInt8 sctp_einprogress_initiated_from;
    UInt8 sctp_connected_after_recovery;
}ric_context_t;

/* E2_NODE_CHANGE */
typedef struct
{
    UInt32              e2_node_type;
    UInt8               plmn_id[MAX_PLMN_ID_BYTES]; /*^ M,0,OCTET_STRING,FIXED ^*/
    UInt32              e2_gnb_id_num_bits; /*^ M,0,H,22,32 ^*/
    UInt8               global_gnb_id[GNB_ID_OCTET_SIZE];
}global_e2node_info_t;

#ifdef E2CU_QOS_CHANGES

/****************************************************************************
 *  * Enumeration Definitions
 *   ****************************************************************************/
typedef enum
{
    E2CU_EVENT_OAM_COMM_INFO_REQ,           /* Communication info message event */
    E2CU_EVENT_OAM_PROV_REQ,                /* Provision request message event */
    E2CU_EVENT_OAM_CELL_INFO_REQ,           /* Cell info request message event */
#ifdef E2CU_MU_MIMO_CHANGES
    E2CU_EVENT_CONN_SETUP_REPORT_RESP,      /* RRC_E2 connection setup report resp event */
    E2CU_EVENT_CONN_SETUP_REPORT_RESPONSE,  /* RRC_E2 connection setup report resp event */
    E2CU_EVENT_CONN_RELEASE_REPORT_RESP,    /* RRC_E2 connection setup report resp event */
    E2CU_EVENT_CONN_RELEASE_REPORT_RESPONSE,/* RRC_E2 connection setup report resp event */
    E2CU_EVENT_CONNECTED_UE_REPORT_RESP,    /* RRC_E2 connection setup report resp event */
    E2CU_EVENT_CONNECTED_UE_REPORT_RESPONSE,/* RRC_E2 connection setup report resp event */
#endif
#ifdef E2CU_QOS_CHANGES
    E2CU_NGAP_EVENT_RIC_CONTROL_RESP,               /* E2CU NGAP RIC Control resp event */
    E2CU_NGAP_EVENT_NI_SUBSCRIPTION_RESP,          /* E2CU NGAP ICS Subscription resp event */
    E2CU_NGAP_EVENT_RC_SUBSCRIPTION_RESP,  /* E2CU NGAP PDU Session Subscription resp event */
    E2CU_NGAP_EVENT_RC_MESSAGE_INDICATION,
    E2CU_NGAP_EVENT_NI_SUBSCRIPTION_DELETE_RESP,          /* E2CU NGAP ICS Subscription resp event */
    E2CU_NGAP_EVENT_RC_SUBSCRIPTION_DELETE_RESP,          /* E2CU NGAP ICS Subscription resp event */
#endif
#ifdef E2CU_KPM_CHANGES
    E2CU_EVENT_OAM_KPM_RESP,
    E2CU_OAM_EVENT_KPM_SUBSCRIPTION_RESP,
    E2CU_EVENT_OAM_KPM_REQ,
#endif
#ifdef E2CU_QOS_CHANGES
    E2CU_EVENT_RRM_PERIODIC_MR_SUBSCRIPTION_RESP,
    E2CU_EVENT_RRM_PERIODIC_MR_SUBSCRIPTION_DEL_RESP,
    E2CU_EVENT_RRC_E2_PERIODIC_MR_IND,
#endif

#ifdef E2CU_QOS_CHANGES
    E2CU_EVENT_NGAP_PDS_RESOURCE_NOTIFY_SUBSCRIPTION_RESP,
    E2CU_EVENT_NGAP_PDS_RESOURCE_NOTIFY_SUBSCRIPTION_DEL_RESP,
    E2CU_EVENT_NG_E2CU_PDU_SESSION_NOTIFY_IND,
    E2CU_EVENT_NG_SETUP_INDICATION,
    E2CU_EVENT_F1_SETUP_INDICATION,
    E2CU_EVENT_XN_SETUP_INDICATION,
    E2CU_EVENT_RRM_E2CU_HO_REQ_SUBSCRIPTION_RESP,
    E2CU_EVENT_RRM_E2CU_HO_REQ_SUBSCRIPTION_DEL_RESP,
    E2CU_EVENT_RRM_E2CU_HANDOVER_REQUEST,
    E2CU_EVENT_RRM_E2CU_HO_REQ_ADM_CTRL_CMD_ACK,
    E2CU_EVENT_RRM_E2CU_PDU_SESSION_RES_SETUP_SUBSCRIPTION_RESP,
    E2CU_EVENT_RRM_E2CU_PDU_SESSION_RES_SETUP_SUBSCRIPTION_DELETE_RESP,
    E2CU_EvENT_RRM_E2CU_PDU_SESSION_RES_SETUP,
    E2CU_EVENT_RRM_E2CU_PDU_SESSION_RES_SETUP_ADM_CTRL_CMD_STATUS,
    E2CU_EVENT_RRM_E2CU_RRM_HO_COMPLETE_IND,
    E2CU_EVENT_RRM_E2CU_RRM_HO_FAILURE_IND,
#endif
    E2CU_NUM_OF_EVENTS,
    E2CU_INVALID_EVENT
} e2cu_event_et;

#ifdef E2CU_QOS_CHANGES
#define MAX_ID_INFO_LIST    4
#define MAX_RC_SUBSCRIPTIONS_SUPPORTED 10
#define RC_MAX_ACTION_DEFINTION_SUPPORTED 1
#define RC_MAX_EVENT_TRIGGER_SUPPORTED 1
#endif

typedef struct _ric_subscription_info_t
{
    UInt8 subscription_exist;
    ni_subscription_info_t ni_subscription_info[MAX_NI_SUBSCRIPTIONS_SUPPORTED];
    rc_subscription_info_t rc_subscription_info_list[MAX_RC_SUBSCRIPTIONS_SUPPORTED];
    kpm_subscription_info_t kpm_subscription_info[MAX_KPM_SUBSCRIPTIONS_SUPPORTED];
} ric_subscription_info_t;



typedef struct e2_reset_subscription_info_t
{
        UInt32 no_of_ni_subscriptions;
        ni_subscription_info_t ni_subscription_info[MAX_NI_SUBSCRIPTIONS_SUPPORTED];

        UInt32 no_of_rc_subscriptions;
        rc_subscription_info_t rc_subscription_info_list[MAX_RC_SUBSCRIPTIONS_SUPPORTED];

        UInt32 no_of_kpm_subscriptions;
        kpm_subscription_info_t kpm_subscription_info[MAX_KPM_SUBSCRIPTIONS_SUPPORTED];

} e2_reset_subscription_info_t;

typedef struct _e2_reset_subs
{

        e2_reset_subscription_info_t e2_reset_subscription_info;
        UInt16 transaction_id;
#if 0 
        UInt16 cause;
#endif 
}e2_reset_subs_t;
#endif 


typedef enum _e2cu_comp_config_state
{
  E2CU_CONFIG_NOT_INDICATED,
  E2CU_CONFIG_INDICATED
} e2cu_comp_config_state_t;


/* Dynamic String */
typedef struct _e2ap_dyn_str_t
{
    /* Length of Dynamic String */
    UInt32 num_string_len;
    /* String Data */
    UInt8 *string_data;
} e2ap_dyn_str_t;


#define E2CU_MAX_CTRL_REQ 50
typedef struct _ric_control_req_ctxt_t
{
 ric_id_info_list_t      ric_id_info;
 e2sm_ue_id_t            ue_id;
 UInt32                  call_process_id;
}ric_control_req_ctxt_t;

typedef struct _e2node_component_config_t
{
    UInt32 e2_node_comp_interface_type;
    e2ap_dyn_str_t setup_req;
    e2ap_dyn_str_t setup_resp;
    e2cu_comp_config_state_t indication_status;
    
} e2node_component_config_t;

#define         E2AP_COMPONENT_CONFIG_LIST_COUNT    3
typedef struct _e2node_component_config_add_list_t
{
    UInt8 component_count;
    /*Index-0 NGAP , Index-1 F1AP , Index-2 XNAP*/
    e2node_component_config_t e2node_component_cfg_list[E2AP_COMPONENT_CONFIG_LIST_COUNT];
} e2node_component_config_add_list_t;

typedef struct _e2node_component_config_update_list_t
{
    UInt8 component_count;
    /*Index-0 NGAP , Index-1 F1AP , Index-2 XNAP*/
    e2node_component_config_t e2node_component_cfg_list[E2AP_COMPONENT_CONFIG_LIST_COUNT];
} e2node_component_config_update_list_t;

typedef struct _e2node_component_config_remove_list_t
{
    UInt8 component_count;
    /*Index-0 NGAP , Index-1 F1AP , Index-2 XNAP*/
    e2node_component_config_t e2node_component_cfg_list[E2AP_COMPONENT_CONFIG_LIST_COUNT];
} e2node_component_config_remove_list_t;


/****************************************************************************
 *  * Types Definitions
 *   ****************************************************************************/
typedef struct _e2cu_gb_context_t
{
    UInt8                   prov_status;
    UInt8                   comm_prov_info_flag; /* Bit-0 for Comm, Bit-1 for Prov */
    UInt16                  oam_init_ind_duration; /*oam_init_ind_timer duration*/
    QTIMER                  oam_init_ind_timer;    /*timer for sending E2_OAM_INIT_IND msg*/
    UInt16                  prov_req_trans_id;
    UInt16                  comm_req_trans_id;
    UInt8                   current_state;
    comm_info_t             *p_comm_info_int;
    UInt8                   log_level;
    UInt32                  csc_cell_index_status; /* Bitmask for presence of communication info of cell */
    ric_info_t              ric_info;
    cell_index_t            cell_index;
    UInt16                  bitmask;
    e2cu_sctp_conf_info_t   e2cu_sctp_conf_param;
    e2cu_timeval_t          sctp_start_time;
    UInt16                  e2cu_conn_recovery_duration;
    search_tree_t           sctp_socket_desc_search_tree;
    ric_context_t           ric_contexts; 
    e2cu_comm_info_t        e2cu_comm_info;
    UInt16                  msg_type;
    global_e2node_info_t    gl_e2_node_info; /* E2_NODE_CHANGE */
#ifdef E2CU_MU_MIMO_CHANGES
    UInt8                   is_mu_mimo_reporting_disabled;
#endif
#ifdef E2CU_QOS_CHANGES
    UInt8                   padding[64];
    e2node_component_config_add_list_t e2node_component_config_add_list;
    e2node_component_config_update_list_t e2node_component_config_update_list;
    e2node_component_config_remove_list_t e2node_component_config_remove_list;
    UInt8                   subscription_exist;  
    ric_subscription_info_t ric_subscription_info;
    ric_control_req_ctxt_t   ric_control_req_ctx[E2CU_MAX_CTRL_REQ];
    e2_reset_subs_t         e2_reset_subs;
    UInt8                   nr_cell_identity[5];
#endif
}e2cu_gb_context_t;


void e2cu_process_init_timer ();

#ifdef E2CU_KPM_CHANGES
void e2cu_process_kpi_timer();
#endif



void e2ap_process_e2_setup_response
(
    void                    *p_asn_msg, 
    UInt16                  asn_msg_len, 
    e2cu_gb_context_t       *p_e2cu_gb_ctx,
    ric_context_t           *p_ric_ctx
);

void e2ap_process_ric_subscription_request
(
    void                    *p_asn_msg, 
    UInt16                  asn_msg_len, 
    e2cu_gb_context_t       *p_e2cu_gb_ctx,
    SInt32                  length_left
);

#ifdef E2CU_QOS_CHANGES
void e2ap_process_ric_control_request
(
 void                    *p_asn_msg,
 UInt16                  asn_msg_len,
 e2cu_gb_context_t       *p_e2cu_gb_ctx,
 SInt32                  length_left
 );
#endif /* E2CU_QOS_CHANGES */

#endif /* _RIC_MD_H_ */
#endif /* (E2CU_MU_MIMO_CHANGES) || defined (E2CU_QOS_CHANGES) */
