#if defined (E2CU_QOS_CHANGES) || defined (E2CU_MU_MIMO_CHANGES) || defined (E2CU_KPM_CHANGES)
#ifndef E2CU_ASN_ENC_DEC_WRAPPER_H
#define E2CU_ASN_ENC_DEC_WRAPPER_H

#include "e2_utils.h"
#include "e2ap_asn_enc_dec_3gpp.h"
#include "e2cu_asn_wrapper_utils.h"
#include "e2sm_rc_asn_enc_dec_3gpp.h"
#include "e2sm_ni_asn_enc_dec_3gpp.h"
#include "e2sm_kpm_asn_enc_dec_3gpp.h"
#include "e2cu_rrm_intf.h"

/* Macro Definition */
#define E2_ASN_OK  0
#define RIC_REQUESTOR_ID    1
#define RIC_INSTANCE_ID     1
#define RAN_FUNCTION_ID     101
#define RIC_ACTION_ID       1
#define RIC_INDICATION_SN   1
#define RIC_INDICATION_TYPE 0
#define E2AP_MAX_NO_OF_PDU_SESSION                    10
#define E2AP_MAX_NO_OF_ADMITTED_ITEM              3
#define E2AP_MAX_NO_OF_NOT_ADMITTED_ITEM              3
#define E2AP_MAX_NO_ACTION_TO_BE_SETUP                1
#define E2CU_NR_CELL_IDENTITY_NUMBITS       36
#define E2CU_AMF_REGION_ID_NUMBITS      8
#define E2CU_AMF_SET_ID_NUMBITS        10
#define E2CU_AMF_POINTER_NUMBITS        6
#define E2CU_MIN_NUM_MNC_DIGIT  2
#define E2CU_MAX_NUM_MNC_DIGIT  3
#define MAX_E2KPM_MEAS_NAME_LENGTH 200
#define E2SM_NI_FUNC_OID   "1.3.6.1.4.1.53148.1.1.2.1"
#define E2SM_RC_FUNC_OID   "1.3.6.1.4.1.53148.1.1.2.3"
#define E2SM_MIMO_FUNC_OID "0.1.2.3.4.5.6.7.8.9"
#define E2SM_KPM_FUNC_OID  "1.3.6.1.4.1.53148.1.1.2.2"

typedef enum
{
    E2AP_RIC_SUBSCRIPTION_REQUEST,
    E2AP_E2_SETUP_RESPONSE,
#ifdef E2CU_QOS_CHANGES
    E2AP_E2_CONTROL_REQUEST,
    E2AP_RIC_SUBSCRIPTION_DELETE_REQUEST,
#endif
#ifdef E2CU_KPM_CHANGES
    E2AP_E2_KPM_REQUEST,
#endif
    E2AP_E2_SETUP_FAILURE,
    E2AP_E2NODE_CONFIGURATION_UPDATE_RESPONSE,
    E2AP_E2NODE_CONFIGURATION_UPDATE_FAILURE,
    E2AP_ERROR_INDICATION,
    E2AP_RESET_REQUEST,
    E2AP_MAX_RIC_API
}e2ap_ric_api_et;

e2_return_et e2cu_encode_ric_indication
(
 UInt8           *p_ind_header_payload,
 UInt16           ind_header_len,
 UInt8           *p_ind_message_payload,
 UInt16           ind_message_len,
 UInt8           *p_asn_msg,    /* Output - ASN Encoded Buffer */
 UInt16          *p_asn_msg_len, /* Output - ASN Encoded Buffer Length */
 /* ric_action_id_changes */
 UInt16           ric_requestor_id,
 UInt16           ric_instance_id,
 UInt8            ric_action_id
 );

typedef struct
{
    UInt8			        order_num;
    UInt16                  ie_id;
    e2ap_Presence_Root   	presence;
    e2ap_Criticality_Root   criticality;
    UInt8                   occurances;
    UInt8                   invalid_value_present;
    UInt8                   wrong_order;
    UInt8                   data_missing;
} e2ap_message_map_t;

typedef struct
{
#define E2AP_MAX_IES_IN_MESSAGE     22 /* The maximum IEs in any one message is 19 */

    UInt8			    max_count;
    UInt8               successful_outcome_present;
    UInt8               unsuccessful_outcome_present;
    UInt16              bitmask;
    e2ap_message_map_t  msg_map[E2AP_MAX_IES_IN_MESSAGE];
} e2ap_message_data_t;

typedef enum
{
    OCCURANCE,
    INVALID_VALUE,
    WRONG_ORDER,
    DATA_MISSING
} e2ap_map_updation_const_et;

/* Dynamic String */
typedef struct
{
    /* Length of Dynamic String */
    UInt32  num_string_len;
    /* String Data */
    UInt8   *string_data;
} e2ap_dynamic_string_t;

typedef UInt8   e2ap_ric_action_id_t;
typedef UInt32  e2ap_ric_action_type_t;
typedef UInt32  e2ap_ric_subsequent_action_type_t;
typedef UInt32  e2ap_ric_time_to_wait_t;
typedef UInt16  e2ap_ran_function_id_t;

typedef struct{

    e2ap_ric_subsequent_action_type_t   ric_subsequent_action_type;
    e2ap_ric_time_to_wait_t             ric_time_to_wait;
}e2ap_ric_subsequent_action_t;

typedef struct{
    e2ap_ric_action_id_t            ric_action_id;
    e2ap_ric_action_type_t          ric_action_type;
    e2ap_dynamic_string_t           ric_action_trigger_def;
}ric_action_to_be_setup_element_t;

typedef struct{
    UInt8               count;
    ric_action_to_be_setup_element_t ric_action_to_be_setup_element[E2AP_MAX_NO_ACTION_TO_BE_SETUP];
}e2ap_ric_action_setup_list_t;

typedef struct{
    e2ap_dynamic_string_t                 ric_event_trigger_def;
    e2ap_ric_action_setup_list_t          ric_action_to_be_setup_list;
}e2ap_ric_subscription_details_t;

typedef struct{
    UInt16      ric_requestor_id;
    UInt16      ric_instance_id;
}e2ap_ric_request_id_t;

typedef struct{
    e2ap_ric_request_id_t               ric_request_id;
    UInt16                              ran_function_id;
    e2ap_ric_subscription_details_t     ric_subscription_details;
}e2ap_ric_subscription_request_t;

#ifdef E2CU_QOS_CHANGES

typedef struct{
    e2ap_ric_request_id_t               ric_request_id;
    UInt16                              ran_function_id;
}e2ap_ric_subscription_delete_request_t;

typedef struct{
    e2ap_ric_request_id_t               ric_request_id;
    UInt16                              ran_function_id;
}e2ap_ric_subscription_delete_response_t;

typedef enum _e2cu_failure_report_type
{
  REPORT_PROCEDURE_FAILURE,
  REPORT_ERROR_INDICATION
}e2cu_failure_report_type_t;

typedef struct e2cu_failure_details {
   e2cu_failure_report_type_t failure_report_type;
   e2ap_ric_api_et e2ap_ric_api;
   void *p_failure_details;
}e2cu_failure_details_t;

e2_return_et e2cu_decode_ric_subscription_delete_req
(
 UInt8			        *p_asn_msg,	    /* Input - ASN Encoded Buffer */
 UInt16                  asn_msg_len,	/* Input - ASN Encoded Buffer Length */
 e2ap_ric_subscription_delete_request_t	*p_ric_subscription_delete_req,	/* Output - Local Buffer */
 e2ap_error_causes_t     *p_error_cause
 );

e2_return_et e2ap_encode_ric_subscription_delete_response
(
 e2ap_ric_subscription_delete_response_t        *p_local_ric_subcription_delete_resp,
 UInt8                                          *p_asn_msg,           /* Output - ASN Encoded Buffer */
 UInt16                                         *p_asn_msg_len        /* Output-ASN Encoded Buffer Length */
 );



e2ap_map_updation_const_et validate_and_fill_ric_call_process_id
(
 e2ap_RICcallProcessID                  *p_value,
 e2ap_dynamic_string_t                  *p_local
 );

e2_return_et validate_e2sm_ni_event_trigger_definition
(
 e2sm_ni_event_trigger_definition_t *p_local_e2sm_ni_event_trigger_definition,
 UInt8   *p_e2sm_payloadd,
 UInt16   e2sm_buf_len
 );

typedef struct
{
    e2ap_ric_request_id_t                                                   ric_request_id;
    UInt16                                                                  ran_function_id;
    e2ap_dynamic_string_t                                                   e2ap_ric_call_process_id;
    e2ap_dynamic_string_t                                                   e2ap_ric_control_header;
    e2ap_dynamic_string_t                                                   e2ap_ric_control_message;
    UInt8 e2ap_ric_control_ack_request;
} e2ap_ric_control_request_t;


typedef struct ran_parameter
   {
       int id;
       char name[50];

   } ran_parameter_t;


e2ap_map_updation_const_et validate_and_fill_ric_control_header
(
 e2ap_RICcontrolHeader                  *p_value,
 e2ap_dynamic_string_t                  *p_local
);

e2ap_map_updation_const_et validate_and_fill_ric_control_message
(
 e2ap_RICcontrolMessage                  *p_value,
 e2ap_dynamic_string_t                   *p_local
);

typedef struct
{
    UInt32      call_process_id;
} e2sm_rc_call_process_id_t;

typedef struct
{
    UInt8      data[E2CU_NR_CELL_IDENTITY_OCTET_SIZE];
} nr_cell_identity_t;

typedef struct
{
 #define NR_CELL_ID_PRESENT     0x01
    UInt8                   bitmask;
    nr_cell_identity_t      nr_cell_identity;
} e2sm_rc_ric_control_header_t;

typedef struct
{
    UInt32                          qos_flow_id;
} qos_flow_admitted_list_item_t;

typedef struct
{
#define MAX_QOS_FLOW_COUNT          3
    UInt16                          count;

    qos_flow_admitted_list_item_t   qos_flow_admitted_list_item[MAX_QOS_FLOW_COUNT];
} qos_flow_admitted_list_t;

typedef struct
{
    UInt8                       pdu_session_id;

    qos_flow_admitted_list_t    qos_flow_admitted_list;

} pdu_session_resource_setup_list_item_t;

typedef struct
{
#define MAX_PDU_SESSION_COUNT         3

    UInt16                                     count;

    pdu_session_resource_setup_list_item_t     pdu_session_resource_setup_list_item[MAX_PDU_SESSION_COUNT];

} pdu_session_resource_admitted_list_t;

typedef struct
{
#define PDU_SESSION_RESOURCE_ADMITTED_LIST_PRESENT     0x01
#define UE_ID_TO_RELEASE_PRESENT                       0x02
    UInt8                                   bitmask;
    UInt32                                  ric_style_type;
    pdu_session_resource_admitted_list_t    pdu_session_resource_admitted_list;
    UInt32                                  ue_idx_to_release;
} e2sm_rc_ric_control_message_t;
#endif

typedef struct{
    UInt8                                                                  ric_action_id;
}e2ap_ric_action_admitted_list_t;



typedef enum {
    CTRL_DECISION_NOT_PROVIDED,
    CTRL_DECISION_ACCEPTED,
    CTRL_DECISION_REJECTED
}RIC_CONTROL_DECISION;




typedef struct {
    UInt16 paramter_id;
    e2ap_dynamic_string_t     dynamic_string;
}control_parameter_t;


typedef struct
{
#define TOTAL_SUPPORTED_CONTROL_RAN_PARAMTERTS 20
    UInt32 noofparamters;
    control_parameter_t parameter[TOTAL_SUPPORTED_CONTROL_RAN_PARAMTERTS];
} control_ran_parameter_t;

typedef struct
{
    control_ran_parameter_t ctrl_ran_parameters;
}e2sm_rc_control_message_format_1_t;


typedef struct
{
    UInt16 ric_style_type;
    UInt16 control_action_id;
    RIC_CONTROL_DECISION ric_control_decision;
    e2sm_ue_id_t ue_id;
}e2sm_rc_control_header_format_1_t;

typedef struct
{
    e2ap_ric_request_id_t ric_request_id;
    UInt16 ran_function_id;
    e2ap_dynamic_string_t e2ap_ric_call_process_id;
    e2sm_rc_control_header_format_1_t  e2ap_ric_control_header;
    e2sm_rc_control_message_format_1_t e2ap_ric_control_message;
    UInt8 e2ap_ric_control_ack_request;
} e2ap_e2sm_rc_control_request_t;

typedef struct{
#define e2ap_Cause_ricRequest         1
#define e2ap_Cause_ricService         2
#define e2ap_Cause_transport          3
#define e2ap_Cause_protocol           4
#define e2ap_Cause_misc               5
#define e2ap_Cause_extElem1           6
    UInt8                                                                   choice_type;
    UInt32                                                                  ric_request;
    UInt32                                                                  ric_service;
    UInt32                                                                  transport;
    UInt32                                                                  protocol;
    UInt32                                                                  misc;
}e2ap_cause_t;

typedef struct{
    UInt8                                                                  ric_action_id;
    e2ap_cause_t                                                           e2ap_cause;
}e2ap_ric_action_not_admitted_item_t;

typedef struct{
    UInt8                                                                  count;
    e2ap_ric_action_not_admitted_item_t                                    ric_action_not_admitted_item[E2AP_MAX_NO_OF_NOT_ADMITTED_ITEM];
}e2ap_ric_action_not_admitted_list_t;

typedef struct{
    e2ap_ric_request_id_t                                                   ric_request_id;
    UInt16                                                                  ran_function_id;
    e2ap_ric_action_admitted_list_t                                         ric_action_admitted;
}e2ap_ric_subscription_response_t;

typedef struct _e2ap_ric_subscription_failure{
    e2ap_ric_request_id_t                                                   ric_request_id;
    UInt16                                                                  ran_function_id;
    e2ap_error_causes_t                                                     cause;
    e2ap_criticality_diagnostics_t                                          criticality_diagnostics;
    UInt8                                                                   critical_diag_present;
}e2ap_ric_subscription_failure_t;

typedef struct _e2ap_ric_subscription_delete_failure{
    e2ap_ric_request_id_t                                                   ric_request_id;
    UInt16                                                                  ran_function_id;
    e2ap_error_causes_t                                                     cause;
}e2ap_ric_subscription_delete_failure_t;

e2_return_et e2ap_update_message_map
(
 e2ap_message_data_t            *p_ie_order_map,
 e2ap_map_updation_const_et  update_type,
 UInt32                      order_index,
 UInt16                      id
);

e2ap_map_updation_const_et validate_and_fill_ric_action_to_be_setup_item
(
 e2ap_RICaction_ToBeSetup_Item        *p_value,  /* ASN Buffer */
 ric_action_to_be_setup_element_t     *p_local            /* Local Buffer */
 );

e2_return_et e2cu_validate_and_fill_ie_value
(
 e2ap_message_data_t *p_ie_order_map,
 UInt32              order_index,
 UInt16              id,
 void                *p_value,
 void                *p_local
 );

typedef struct _e2ap_reset_response
{
 UInt16 transaction_id;
}e2_reset_response_t;

/* E2_NODE_CHANGE */
typedef struct
{
    UInt32              nodetype;
    UInt8               plmn_id[MAX_PLMN_ID_BYTES]; /*^ M,0,OCTET_STRING,FIXED ^*/
    UInt32              gnb_id_num_bits; /*^ M,0,H,22,32 ^*/
    UInt8               gnb_id[GNB_ID_OCTET_SIZE];
}e2_setup_request_t;

e2_return_et e2ap_encode_e2_setup_request
(
 UInt8                                          *p_asn_msg,           /* Output - ASN Encoded Buffer */
 UInt16                                         *p_asn_msg_len,        /* Output-ASN Encoded Buffer Length */
 e2_setup_request_t                             *p_local_e2_setup_req,
 UInt8                                          *p_ran_func_def_pdu,
 gnb_length_t                                    ran_func_def_len
);

e2_return_et e2cu_decode_ric_subscription_req
(
 UInt8			        *p_asn_msg,	    /* Input - ASN Encoded Buffer */
 UInt16                  asn_msg_len,	/* Input - ASN Encoded Buffer Length */
 e2ap_ric_subscription_request_t	*p_ric_subscription_req,	/* Output - Local Buffer */
 e2ap_ric_subscription_failure_t    *p_ric_subscription_failure 

 );

e2_return_et e2ap_get_asn_msg_type
(
    void                *p_asn_msg,
    UInt32              asn_msg_len,
    e2ap_ric_api_et   	*ep_type,
    UInt8               *is_rcv_msg_correct
);

e2_return_et e2ap_encode_ric_subscription_response
(
 e2ap_ric_subscription_response_t    *p_local_ric_subcription_resp,
 UInt8                                          *p_asn_msg,           /* Output - ASN Encoded Buffer */
 UInt16                                         *p_asn_msg_len        /* Output-ASN Encoded Buffer Length */
 );

e2_return_et ric_subscription_req_internal_dec
(
 OSCTXT                 *p_asn1_ctx,            /* Input: ASN1 Context to be used */
 e2ap_RICsubscriptionRequest     *p_asn_ric_subscription_req,    /* Input: Received ASN Buffer */
 e2ap_ric_subscription_request_t    *p_local_ric_subscription_req,   /* Output: Local Message Structure */
 e2ap_ric_subscription_failure_t      *p_local_ric_subcription_failure  
 );

e2ap_map_updation_const_et fill_ric_action_setup_list 
(
 e2ap_RICactions_ToBeSetup_List *p_value,
 e2ap_ric_action_setup_list_t *p_local
 );




/* E2_SETUP_RESPONSE STRUCTURE ELEMENTS */

/* RIC Id */
typedef struct
{
#define RIC_ID_NUMBITS                        32   /* To Support bits 22-32 */

    UInt8   ric_id[RIC_ID_NUMBITS];

} e2ap_ric_id_t;


/* PLMN-Id */
typedef struct
{
#define RIC_PLMN_IDENTITY_MAX_BYTES     3

    /* PLMN Identity Bytes */
    UInt8   plmn_id_bytes [RIC_PLMN_IDENTITY_MAX_BYTES];
    /*^ M, 0, OCTET_STRING, FIXED ^*/

} global_ric_plmn_identity_t;

typedef struct
{
    /* PLMN Identity */
    global_ric_plmn_identity_t    plmn_identity;

    /* Global RIC Identity */
    e2ap_ric_id_t                 near_ric_id;

} e2ap_GlobalRIC_ID_t;

typedef struct
{
    UInt16  ran_function_id;
    UInt16  ran_function_revision;
}e2ap_ran_function_list_node_item_t;


typedef struct
{
#define E2AP_MAX_NO_OF_RAN_FUNCTION_ID_LIST_COUNT   4

    UInt8       count;

    /* RAN function list item */
    e2ap_ran_function_list_node_item_t    ran_function_id_item[E2AP_MAX_NO_OF_RAN_FUNCTION_ID_LIST_COUNT];

}e2ap_RanFunctionId_List_t;


typedef struct
{
    e2ap_GlobalRIC_ID_t         GlobalRIC_ID;
    e2ap_RanFunctionId_List_t   RANfunctionsID_List;
}e2ap_e2_setup_resp_t;

typedef struct _component_ack_list_t
{
    UInt16 interface_id;
    UInt8 ack_status;
}component_ack_list_t;

typedef struct _e2ap_e2node_configuration_update
{
  component_ack_list_t component_add_status;
  component_ack_list_t component_update_status;
  component_ack_list_t component_removal_status;
}e2ap_e2node_configuration_update_t; 

e2ap_map_updation_const_et validate_and_fill_global_ric_id
(
 e2ap_GlobalRIC_ID *p_value,
 e2ap_GlobalRIC_ID_t *p_local
 );

e2ap_map_updation_const_et validate_and_fill_ran_function_id_list
(
 e2ap_RANfunctionsID_List *p_value,
 e2ap_RanFunctionId_List_t *p_local
 );

e2_return_et e2ap_e2_setup_resp_internal_dec
(
 OSCTXT                          *p_asn1_ctx,            /* Input: ASN1 Context to be used */
 e2ap_E2setupResponse            *p_asn_e2_setup_resp,    /* Input: Received ASN Buffer */
 e2ap_e2_setup_resp_t            *p_local_e2_setup_resp   /* Output: Local Message Structure */
);

e2_return_et e2ap_decode_e2_setup_resp
(
 UInt8                   *p_asn_msg,     /* Input - ASN Encoded Buffer */
 UInt16                  asn_msg_len,    /* Input - ASN Encoded Buffer Length */
 e2ap_e2_setup_resp_t    *p_local_e2_setup_resp  /* Output - Local Buffer */
);

#ifdef E2CU_QOS_CHANGES
e2_return_et e2ap_ric_control_req_internal_dec
(
 OSCTXT                  *p_asn1_ctx,            /* Input: ASN1 Context to be used */
 e2ap_RICcontrolRequest     *p_asn_e2ap_ric_control_req,    /* Input: Received ASN Buffer */
 e2ap_ric_control_request_t    *p_local_e2ap_ric_control_req,   /* Output: Local Message Structure */
 e2ap_error_causes_t         *p_error_cause
);


typedef struct _e2ap_error_indication
{
 UInt16 transaction_id;
 UInt16 cause;
 UInt16 time_to_wait;
}e2ap_error_indication_t;


typedef struct _e2ap_e2_setup_failure_t
{
 UInt16 transaction_id;
 UInt16 cause;
 UInt16 time_to_wait;
}e2ap_e2_setup_failure_t;

typedef struct _e2ap_e2node_configuration_update_failure_t
{
 UInt16 transaction_id;
 UInt16 cause;
 UInt16 time_to_wait;
}e2ap_e2node_configuration_update_failure_t;

typedef struct _e2ap_ric_control_req_ack
{
    UInt16                      ric_requestor_id;
    UInt16                      ric_instance_id;
    UInt16                      ran_function_id;
    UInt32                      call_process_id;
    e2ap_dynamic_string_t       call_process_id_payload;
    e2ap_dynamic_string_t       control_outcome;
    e2ap_error_causes_t         cause;
} e2ap_ric_control_req_ack_t;


typedef struct _e2ap_ric_control_failure
{
    UInt16                      ric_requestor_id;
    UInt16                      ric_instance_id;
    UInt16                      ran_function_id;
    UInt32                      call_process_id;
    e2ap_dynamic_string_t       call_process_id_payload;
    e2ap_dynamic_string_t       control_outcome;
    e2ap_error_causes_t         cause;
} e2ap_ric_control_failure_t;

typedef struct _e2ap_reset_request
{
 UInt16 transaction_id;
#if 0
 UInt16 cause;
#endif 
}e2ap_reset_request_t;


e2_return_et e2ap_encode_ric_control_acknowledge
(
 UInt8                                          *p_asn_msg,           /* Output - ASN Encoded Buffer */
 UInt16                                         *p_asn_msg_len,        /* Output-ASN Encoded Buffer Length */
 e2ap_ric_control_req_ack_t                     *p_local_e2ap_ric_control_req_ack
 );

e2_return_et e2ap_decode_ric_control_req
(
 UInt8                       *p_asn_msg, 
 UInt16                      asn_msg_len,
 e2ap_ric_control_request_t  *p_ric_control_req,
 e2ap_error_causes_t         *p_error_cause
 );

e2_return_et validate_e2sm_rc_event_trigger_definition
(
 rc_event_trigger_def_t *p_local_e2sm_rc_event_trigger_definition,
 UInt8   *p_e2sm_payloadd,
 UInt16   e2sm_buf_len
 );

e2_return_et validate_and_fill_e2sm_rc_call_process_id
(
 e2sm_rc_call_process_id_t *p_local_e2sm_rc_call_process_id,
 UInt8   *p_e2sm_payloadd,
 UInt16   e2sm_buf_len
 );

e2_return_et validate_and_fill_e2sm_rc_ric_control_header
(
 e2sm_rc_ric_control_header_t *p_local_e2sm_rc_ric_control_header,
 UInt8   *p_e2sm_payloadd,
 UInt16   e2sm_buf_len
 );

e2_return_et validate_and_fill_e2sm_rc_ric_control_message
(
 e2sm_rc_ric_control_message_t *p_local_e2sm_rc_ric_control_message,
 UInt8   *p_e2sm_payloadd,
 UInt16   e2sm_buf_len
 );

e2_return_et encode_e2sm_rc_call_process_id_payload
(
 UInt8           *p_asn_msg,    /* Output - ASN Encoded Buffer */
 UInt16          *p_asn_msg_len, /* Output - ASN Encoded Buffer Length */
 UInt32           call_process_id
 );

e2_return_et encode_e2sm_rc_indication_message_payload
(
 UInt8           *p_asn_msg,    /* Output - ASN Encoded Buffer */
 UInt16          *p_asn_msg_len, /* Output - ASN Encoded Buffer Length */
 void            *p_ni_msg,
 UInt16          rc_msg_length,
 UInt16          parameter_id
 );

e2_return_et encode_e2sm_rc_ran_function_description_payload
(
 UInt8           *p_asn_msg,    /* Output - ASN Encoded Buffer */
 UInt16          *p_asn_msg_len /* Output - ASN Encoded Buffer Length */
 );

e2_return_et encode_e2sm_ni_ran_function_description_payload
(
 UInt8           *p_asn_msg,    /* Output - ASN Encoded Buffer */
 UInt16          *p_asn_msg_len /* Output - ASN Encoded Buffer Length */
 );
#endif

#ifdef E2CU_KPM_CHANGES
typedef struct _e2cu_kpm_action_mes_data_t
{
    UInt8    mes_name[MAX_E2KPM_MEAS_NAME_LENGTH];
    UInt32   mes_name_len;
    UInt32   mes_id;
} e2cu_kpm_action_mes_data_t;

typedef struct
{
    UInt32  		       reportingPeriod;
    UInt16                 ric_style_type;
    UInt8                  count;
//    UInt8   	           *cellObjID;
    UInt16                 granularity_period;
    e2sm_nr_cgi_t          nr_cgi;
    e2cu_kpm_action_mes_data_t      Action_List[13];
} e2sm_ni_event_kpm_trigger_definition_t;

e2ap_map_updation_const_et validate_and_fill_ric_call_process_id
(
 e2ap_RICcallProcessID                  *p_value,
 e2ap_dynamic_string_t                  *p_local
 );

e2_return_et validate_e2sm_ni_event_kpm_trigger_definition
(
 e2sm_ni_event_kpm_trigger_definition_t *p_local_e2sm_ni_event_kpm_trigger_definition,
 UInt8   *p_e2sm_payloadd,
 UInt16   e2sm_buf_len
);

e2_return_et validate_e2sm_kpm_action_definition
(
 e2sm_ni_event_kpm_trigger_definition_t *p_local_e2sm_ni_event_kpm_trigger_definition,
 UInt8   *p_e2sm_payloadd,
 UInt16   e2sm_buf_len
);

e2_return_et encode_e2sm_kpm_indication_message_payload
(
 UInt8           *p_asn_msg,    /* Output - ASN Encoded Buffer */
 UInt16          *p_asn_msg_len, /* Output - ASN Encoded Buffer Length */
 void            *p_ni_msg,
 UInt16           ni_msg_length
 );
e2_return_et encode_e2sm_kpm_ran_function_description_payload
(
 UInt8           *p_asn_msg,    /* Output - ASN Encoded Buffer */
 UInt16          *p_asn_msg_len /* Output - ASN Encoded Buffer Length */
 );
#endif

e2_return_et e2ap_encode_globalE2_node_id
(
 OSCTXT                                              *p_asn1_ctx,
 e2ap_GlobalE2node_ID                                *p_asn_gb_e2_node_id,
 e2_setup_request_t                                  *p_local_e2_setup_req
 );


e2_return_et validate_e2sm_rc_action_definition
(
        rc_action_def_t *p_local_action_def,
 UInt8   *p_e2sm_payloadd,
 UInt16   e2sm_buf_len,
 e2ap_error_causes_t *p_error_cause
 );

e2_return_et decode_e2sm_rc_contol_header 
(
        e2ap_e2sm_rc_control_request_t *p_local_e2ap_e2sm_rc_control_request,
        e2ap_ric_control_request_t *p_e2ap_ric_control_request
);

e2_return_et decode_e2sm_rc_contol_message 
(
        e2ap_e2sm_rc_control_request_t *p_local_e2ap_e2sm_rc_control_request,
        e2ap_ric_control_request_t *p_e2ap_ric_control_request
);

e2_return_et e2sm_decode_nr_cgi 
(
        UInt8 *p_asn_msg, UInt16 asn_msg_len,
        nr_global_cell_id_t *p_local_nr_cgi
);

e2_return_et encode_e2sm_rc_indication_header_format1_payload 
(
        UInt8 *p_asn_msg, /* Output - ASN Encoded Buffer */
        UInt16 *p_asn_msg_len, /* Output - ASN Encoded Buffer Length */
        rc_indication_header_format_1_t *p_local_rc_indication_header_format_1
);

e2_return_et encode_e2sm_rc_indication_message_format5_payload_pdu_session_resource_setup 
(
        UInt8 *p_asn_msg, UInt16 *p_asn_msg_len,
        rrm_e2cu_pdu_session_res_setup_t *p_rrm_e2cu_handover_req
);

e2_return_et encode_e2sm_rc_indication_message_format5_payload_ho_control_adm 
(
        UInt8 *p_asn_msg, UInt16 *p_asn_msg_len,
        rrm_e2cu_handover_req *p_handover_req_info
);

e2_return_et encode_e2sm_rc_indication_header_format2_payload 
(
        UInt8 *p_asn_msg, /* Output - ASN Encoded Buffer */
        UInt16 *p_asn_msg_len, /* Output - ASN Encoded Buffer Length */
        rc_indication_header_format_2_t *p_local_rc_indication_header_format_2
);


e2_return_et encode_e2sm_rc_indication_message_format1_payload 
(
        UInt8 *p_asn_msg, /* Output - ASN Encoded Buffer */
        UInt16 *p_asn_msg_len, /* Output - ASN Encoded Buffer Length */
        rc_indication_message_format_1_t *p_rc_indication_message
);


e2_return_et compose_e2sm_rc_report_style_message_copy 
(
        OSCTXT *p_asn1_ctx,
        E2SM_RC_RANFunctionDefinition_Report_ric_ReportStyle_List *p_asn_report_style_list
);


e2_return_et append_report_style_ran_parameter_list 
(
        OSCTXT *p_asn1_ctx, void *p_asn_ran_param_list, 
        ran_parameter_t *parameter,
        UInt16 size
);


e2_return_et compose_e2sm_rc_event_trigger_style_message_event
(
        OSCTXT     *p_asn1_ctx,
        E2SM_RC_RANFunctionDefinition_EventTrigger_ric_EventTriggerStyle_List *p_asn_ric_event_trigger_style_list
);

e2_return_et compose_e2sm_rc_event_trigger_style_call_process_break_point
(
        OSCTXT     *p_asn1_ctx,
        E2SM_RC_RANFunctionDefinition_EventTrigger_ric_EventTriggerStyle_List *p_asn_ric_event_trigger_style_list
);

e2_return_et e2sm_rc_decode_ran_paramter_specific_type 
(
        E2SM_RC_RANParameter_ValueType *parameter_value_type,
        control_parameter_t *p_control_param
);

e2_return_et e2sm_rc_encode_ue_id 
(
OSUINT8 *p_asn_msg_ue_id_buff,
UInt16 *p_asn_ue_len, 
e2sm_ue_id_t *p_ue_id
);


e2_return_et e2sm_rc_encode_nr_cgi
(
      OSUINT8 *p_asn_nr_cgi,
      UInt16 *p_asn_nr_cgi_len, ng_ran_id_t *p_ran_id
);

e2_return_et e2ap_encode_ric_control_failure
(
 UInt8                                          *p_asn_msg,
 UInt16                                         *p_asn_msg_len,
 e2ap_ric_control_failure_t                     *p_local_e2ap_ric_control_failure
);



e2_return_et encode_e2sm_kpm_indication_message_payload
(
 UInt8           *p_asn_msg,    /* Output - ASN Encoded Buffer */
 UInt16          *p_asn_msg_len, /* Output - ASN Encoded Buffer Length */
 void            *p_ni_msg,
 UInt16           ni_msg_length
);

e2_return_et e2ap_encode_ric_subscription_failure
(
 UInt8 *p_asn_msg,
 UInt16 *p_asn_msg_len,
 e2ap_ric_subscription_failure_t      *p_local_ric_subcription_failure
);

e2_return_et e2ap_encode_ric_subscription_delete_failure
(
 UInt8 *p_asn_msg,
 UInt16 *p_asn_msg_len,
 e2ap_ric_subscription_delete_failure_t      *p_local_ric_subcription_delete_failure
);

e2_return_et e2ap_decode_error_indication
(
 UInt8                      *p_asn_msg, 
 UInt16                     asn_msg_len,
 e2ap_error_indication_t    *p_local_e2ap_error_indication
);

e2_return_et e2ap_decode_e2_setup_failure
(
 UInt8                      *p_asn_msg,
 UInt16                     asn_msg_len,
 e2ap_e2_setup_failure_t    *p_local_e2_setup_failure
);

e2_return_et e2ap_decode_e2node_config_update_failure
(
 UInt8                      *p_asn_msg,
 UInt16                     asn_msg_len,
 e2ap_e2node_configuration_update_failure_t *p_e2ap_e2node_cfg_update_failure
);

e2_return_et encode_e2sm_rc_control_outcome_payload
(
 UInt8                       *p_asn_msg, 
 UInt16                      *p_asn_msg_len,
 UInt64           received_timeStamp
);

e2_return_et encode_error_indication_message
(
 UInt8                         *p_asn_msg,    
 UInt16                        *p_asn_msg_len,
 e2_error_indication_msg_t     *p_local_e2_error_ind_msg
);

e2_return_et e2ap_decode_e2node_configuration_update_resp
(
 UInt8                   *p_asn_msg,     
 UInt16                  asn_msg_len,    
 e2ap_e2node_configuration_update_t   *p_decoded_e2ap_e2node_configuration_update
);


e2_return_et e2ap_encode_reset_response
(
 e2_reset_response_t                            *p_local_e2_reset_response,
 UInt8                                          *p_asn_msg, 
 UInt16                                         *p_asn_msg_len
 );


e2_return_et e2ap_encode_reset_resquest
(

 );


e2_return_et e2_decode_reset(
        UInt8                  *p_asn_msg,           /* Input - ASN Encoded Buffer */
        UInt16                  asn_msg_len,         /* Input - ASN Encoded Buffer Length */
        e2ap_reset_request_t    *p_decode_e2_reset);   /* Output - Local Buffer */

#endif /* E2CU_ASN_ENC_DEC_WRAPPER_H */
#endif 
