#include "e2_utils.h"
#include "e2ap_asn_enc_dec_3gpp.h"
#include "e2du_defines.h"
#include "gnb_msg_mgmt.h"

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
#define E2SM_KPM_MAX_E2_NODE_MEAS  2
#define E2SM_KPM_MAX_CELL_WIDE_UE_LEVEL_E2_NODE_MEAS  3
#define MAX_KPM_REPORT_STYLE_COUNT 2

typedef enum {
    KPM_CELL_LEVEL_KPM_BASE = 100,
    KPM_CELL_LEVEL_RRU_PRBTOTDL_DIST, /*101*/
    KPM_CELL_LEVEL_RRU_PRBTOTUL_DIST, /*102*/ 
    KPM_CELL_LEVEL_DRB_UE_THP_DL, /*103*/
    KPM_CELL_LEVEL_DRB_UE_THP_UL, /*104*/
    KPM_CELL_LEVEL_MR_INTRA_CELL_SSB_SWITCH_REQ,/*105*/
    KPM_CELL_LEVEL_MR_INTRA_CELL_SUCC_SSB_SWITCH, /*106*/
    KPM_CELL_LEVEL_L1M_SS_RSRP_BINX, /*107*/
    KPM_CELL_LEVEL_L1M_PHR1_BinX /*108*/

}e2sm_kpm_cell_level_kpm_et;

typedef enum {
    CELL_UE_LEVEL_KPM_BASE = 300,
    KPM_CELL_UE_LEVEL_CARR_WBCQI_DIST,
    KPM_CELL_UE_LEVEL_TB_ERRTOTALNBRDL,
    KPM_CELL_UE_LEVEL_TB_ERRTOTALNBRUL
}e2sm_kpm_cell_ue_level_kpm_et;


typedef enum {
    UE_LEVEL_KPM_BASE = 500,
    UE_LEVEL_DRB_UETHPDL,
    UE_LEVEL_DRB_UETHPUL
}e2sm_kpm_ue_level_kpm_et;


typedef enum
{
    E2AP_RIC_SUBSCRIPTION_REQUEST,
    E2AP_E2_SETUP_RESPONSE,
    E2AP_E2_CONTROL_REQUEST,
    E2AP_E2_KPM_REQUEST,
    E2AP_RIC_SUBSCRIPTION_DELETE_REQUEST,
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
typedef struct _e2ap_dynamic_string_t
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
#define E2KPM_MAX_MEAS_ID_IN_ACTION 10
typedef struct _e2ap_ric_action_admitted_list_t{
    UInt16 noofactionid;
    UInt8  ric_action_id[E2KPM_MAX_MEAS_ID_IN_ACTION];
}e2ap_ric_action_admitted_list_t;


typedef struct _e2ap_cause_t{
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

typedef struct _e2ap_ric_action_not_admitted_item_t{
    UInt8                                                                  ric_action_id;
    e2ap_cause_t                                                           e2ap_cause;
}e2ap_ric_action_not_admitted_item_t;

typedef struct _e2ap_ric_action_not_admitted_list_t{
    UInt8                                                                  count;
    e2ap_ric_action_not_admitted_item_t                                    ric_action_not_admitted_item[E2AP_MAX_NO_OF_NOT_ADMITTED_ITEM];
}e2ap_ric_action_not_admitted_list_t;

typedef struct _e2ap_ric_subscription_response_t{
    e2ap_ric_request_id_t                                                   ric_request_id;
    UInt16                                                                  ran_function_id;
    e2ap_ric_action_admitted_list_t                                         ric_action_admitted;
}e2ap_ric_subscription_response_t;


typedef struct _e2ap_ric_reset_response_t{
    UInt16                                                                  transaction_id;
}e2ap_ric_reset_response_t;


typedef enum _e2ap_error_causes{
    E2AP_NO_ERROR,
    E2AP_ERR_RIC_SERVICES_RIC_REQUEST_RAN_FUNCTION_ID_INVALID,
    E2AP_ERR_RIC_SERVICES_RIC_REQUEST_ACTION_NOT_SUPPORTED,
    E2AP_ERR_RIC_SERVICES_RIC_REQUEST_EXCESSIVE_ACTIONS,
    E2AP_ERR_RIC_SERVICES_RIC_REQUEST_DUPLICATE_ACTION,
    E2AP_ERR_RIC_SERVICES_RIC_REQUEST_DUPLICATE_EVENT_TRIGGER,
    E2AP_ERR_RIC_SERVICES_RIC_REQUEST_FUNCTION_RESOURCE_LIMIT,
    E2AP_ERR_RIC_SERVICES_RIC_REQUEST_RIC_REQUEST_ID_UNKNOWN,
    E2AP_ERR_RIC_SERVICES_RIC_REQUEST_INCONSISTENT_ACTION_SEQUENCE,
    E2AP_ERR_RIC_SERVICES_RIC_REQUEST_INCONSISTENT_SUBSEQUENT_ACTION_SEQUENCE,
    E2AP_ERR_RIC_SERVICES_RIC_REQUEST_CONTROL_MESSAGE_INVALID,
    E2AP_ERR_RIC_SERVICES_RIC_REQUEST_RIC_CALL_PROCESS_ID_INVALID,
    E2AP_ERR_RIC_SERVICES_RIC_REQUEST_CONTROL_TIMER_EXPIRED,
    E2AP_ERR_RIC_SERVICES_RIC_REQUEST_CONTROL_FAILED_TO_EXECUTE,
    E2AP_ERR_RIC_SERVICES_RIC_REQUEST_SYSTEM_NOT_READY,
    E2AP_ERR_RIC_SERVICES_RIC_REQUEST_UNSPECIFIED, 
    E2AP_ERR_RIC_SERVICES_RIC_SERVICE_RAN_FUNCTION_NOT_SUPPORTED,
    E2AP_ERR_RIC_SERVICES_RIC_SERVICE_EXCESSIVE_FUNCTIONS,
    E2AP_ERR_RIC_SERVICES_RIC_SERVICE_RIC_RESOURCE_LIMIT, 
    E2AP_ERR_RIC_SERVICES_E2_NODE_COMPONENT_UNKNOWN,
    E2AP_ERR_TRANS_LAYER_CAUSE_UNSPECIFIED,
    E2AP_ERR_TRANS_LAYER_CAUSE_TRANSPORT_RESOURCE_UNAVAILABLE,
    E2AP_ERR_PROTOCOL_CAUSE_TRANSFER_SYNTAX_ERROR,
    E2AP_ERR_PROTOCOL_CAUSE_ABSTRACT_SYNTAX_ERROR_REJECT,
    E2AP_ERR_PROTOCOL_CAUSE_ABSTRACT_SYNTAX_ERROR_IGNORE_AND_NOTIFY,
    E2AP_ERR_PROTOCOL_CAUSE_MESSAGE_NOT_COMPATIBLE_WITH_RECEIVER_STATE,
    E2AP_ERR_PROTOCOL_CAUSE_SEMANTIC_ERROR,
    E2AP_ERR_PROTOCOL_CAUSE_ABSTRACT_SYNTAX_ERROR_FALSELY_CONSTRUCTED_MESSAGE,
    E2AP_ERR_PROTOCOL_CAUSE_UNSPECIFIED,
    E2AP_ERR_MISC_CAUSE_CONTROL_PROCESSING_OVERLOAD,
    E2AP_ERR_MISC_CAUSE_HARDWARE_FAILURE,
    E2AP_ERR_MISC_CAUSE_OAM_INTERVENTION,
    E2AP_ERR_MISC_CAUSE_UNSPECIFIED
}e2ap_error_causes_t;

/* Type Of Error */
typedef enum
{
    E2AP_NOT_UNDERSTOOD,
    E2AP_MISSING

} e2ap_type_of_error_t;


/* IE Criticality */
typedef enum
{

    E2AP_IE_CRITICALITY_REJECT,
    E2AP_IE_CRITICALITY_IGNORE,
    E2AP_IE_CRITICALITY_NOTIFY

} e2ap_ie_criticality_t;



/* Information Element Criticality Diagnostics Elements */
typedef struct _e2ap_criticality_diagnostics_ie
{
    /* IE Criticality */
    e2ap_ie_criticality_t  ie_criticality;

    /* IE ID */
    UInt16                  ie_id;

    /* Type Of Error */
    e2ap_type_of_error_t   type_of_error;

} e2ap_criticality_diagnostics_ie_t;

/* Information Element Criticality Diagnostics */
typedef struct  _e2ap_criticality_diagnostics_ie_list
{
#define MAX_CD_ERRORS       256

    /* Number of Errors in CD */
    UInt16                              no_of_errors;

    /* CD IEs */
    e2ap_criticality_diagnostics_ie_t   criticality_diagnostics_ie [MAX_CD_ERRORS];

} e2ap_criticality_diagnostics_ie_list_t;


/* Procedure Criticality */
typedef enum
{

    E2AP_PROC_CRITICALITY_REJECT,
    E2AP_PROC_CRITICALITY_IGNORE,
    E2AP_PROC_CRITICALITY_NOTIFY,
    E2AP_PRPOC_INVALID_CRITICALITY

} e2ap_procedure_criticality_t;

/* Triggering Message */
typedef enum
{

    E2AP_TRIG_INITIATING_MESSAGE,
    E2AP_TRIG_SUCCESSFUL_OUTCOME,
    E2AP_TRIG_UNSUCCESSFUL_OUTCOME,
    E2AP_TRIG_INVALID_TRIGGERING_MSG

} e2ap_triggering_message_t;


/* Criticality Diagnostics */
typedef struct _e2ap_criticality_diagnostics
{

#define E2AP_CRITICALITY_DIAGNOSTICS_PROCEDURE_CODE         0x01
#define E2AP_CRITICALITY_DIAGNOSTICS_TRIGGERING_MESSAGE     0x02
#define E2AP_CRITICALITY_DIAGNOSTICS_PROCEDURE_CRITICALITY  0x04
#define E2AP_CRITICALITY_DIAGNOSTICS_PROCEDURE_IE_LIST      0x08

    UInt16                                  bitmask;

    /* Procedure Code */
    UInt8                                   procedure_code;

    /* Triggering Message */
    e2ap_triggering_message_t              triggering_message_event_id;

    /* Procedure Criticality */
    e2ap_procedure_criticality_t           procedure_criticality_event_id;

    /* Information Element Criticality Diagnostics */
    e2ap_criticality_diagnostics_ie_list_t  cd_ie_list;

} e2ap_criticality_diagnostics_t;


typedef struct _e2_error_indication_msg {

    UInt8       ric_request_id_present;
    UInt8       ranc_function_id_present; 
    UInt8       critical_diag_present; 
    UInt16      ric_requestor_id;
    UInt16      ric_instance_id;
    UInt16      ran_function_id;
    e2ap_error_causes_t  cause;
    e2ap_criticality_diagnostics_t  criticality_diagnostics;
 }e2_error_indication_msg_t;


typedef struct{
    e2ap_ric_request_id_t               ric_request_id;
    UInt16                              ran_function_id;
}e2ap_ric_subscription_delete_response_t;

typedef struct{
    e2ap_ric_request_id_t               ric_request_id;
    UInt16                              ran_function_id;
}e2ap_ric_subscription_delete_request_t;

typedef struct
{
    e2ap_ric_request_id_t                                                   ric_request_id;
    UInt16                                                                  ran_function_id;
    e2ap_dynamic_string_t                                                   e2ap_ric_call_process_id;
    e2ap_dynamic_string_t                                                   e2ap_ric_control_header;
    e2ap_dynamic_string_t                                                   e2ap_ric_control_message;
    UInt32			                                            e2ap_ric_control_ack_req;

} e2ap_ric_control_request_t;

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

e2ap_map_updation_const_et validate_and_fill_ric_control_ack_req
(
 e2ap_RICcontrolAckRequest                  *p_value,
 e2ap_dynamic_string_t                   *p_local
);

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

/* E2_NODE_CHANGE */
typedef struct
{
    UInt32              nodetype;
    UInt8               plmn_id[MAX_PLMN_ID_BYTES]; /*^ M,0,OCTET_STRING,FIXED ^*/
    UInt32              gnb_id_num_bits; /*^ M,0,H,22,32 ^*/
    UInt8               gnb_id[GNB_ID_OCTET_SIZE];
    UInt64              gnb_du_id; /*^ M,0,H,0,68,71,94,76,735 ^*/
}e2_setup_request_t;

e2_return_et e2ap_encode_e2_setup_request
(
 UInt8                                          *p_asn_msg,           /* Output - ASN Encoded Buffer */
 UInt16                                         *p_asn_msg_len,        /* Output-ASN Encoded Buffer Length */
 e2_setup_request_t                             *p_local_e2_setup_req,
 UInt8                                          *p_ran_func_def_pdu,
 gnb_length_t                                    ran_func_def_len
);


e2_return_et encode_e2sm_kpm_ran_function_description_payload
(
UInt8           *p_asn_msg,    /* Output - ASN Encoded Buffer */
UInt16          *p_asn_msg_len /* Output - ASN Encoded Buffer Length */
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


e2ap_map_updation_const_et fill_ric_action_setup_list 
(
 e2ap_RICactions_ToBeSetup_List *p_value,
 e2ap_ric_action_setup_list_t *p_local
 );

e2_return_et e2ap_ric_control_req_internal_dec
(
 OSCTXT                  *p_asn1_ctx,            /* Input: ASN1 Context to be used */
 e2ap_RICcontrolRequest     *p_asn_e2ap_ric_control_req,    /* Input: Received ASN Buffer */
 e2ap_ric_control_request_t    *p_local_e2ap_ric_control_req   /* Output: Local Message Structure */
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
#define E2AP_MAX_NO_OF_RAN_FUNCTION_ID_LIST_COUNT   2

    UInt8       count;

    /* RAN function list item */
    e2ap_ran_function_list_node_item_t    ran_function_id_item[E2AP_MAX_NO_OF_RAN_FUNCTION_ID_LIST_COUNT];

}e2ap_RanFunctionId_List_t;


typedef struct
{
    e2ap_GlobalRIC_ID_t         GlobalRIC_ID;
    e2ap_RanFunctionId_List_t   RANfunctionsID_List;
}e2ap_e2_setup_resp_t;


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


/* RAN Function Added List Changes Start */
#define MAX_RIC_STYLE_COUNT         1

typedef struct _ran_function_added_item_list_t
{
    UInt16                       ran_function_id;

    e2ap_dynamic_string_t             ran_function_definition_payload;
    
    UInt16                       ran_function_revision;

} ran_function_added_item_list_t;

typedef struct _ran_functions_added_list_t
{
#define         E2AP_RAN_FUNCTION_LIST_COUNT    4

    UInt8       count;

    ran_function_added_item_list_t      ran_function_added_item_list[E2AP_RAN_FUNCTION_LIST_COUNT];

} ran_functions_added_list_t;
/* RAN Function Added List Changes End */

typedef struct _global_ng_ran_id_t
{
    /* PLMN ID */
    UInt8               plmn_id[MAX_PLMN_ID_BYTES];

    /* ENB-ID Num bits */
    UInt32              enb_id_num_bits;

    /* ENB ID */
    UInt8               enb_id[GNB_ID_OCTET_SIZE];
} global_ng_ran_id_t;

typedef struct _e2ap_ric_indication_header_t
{
    /* Network Interface Type */
    UInt32                  ni_type;

    UInt8                   nr_cell_identity[5];

    /* Global NG RAN ID */
    global_ng_ran_id_t      ng_ran_id;

    /* Network Interface Direction */
    UInt32                  ni_direction;

    e2ap_dynamic_string_t   ric_indication_header;
} e2ap_ric_indication_header_t;

typedef struct _e2ap_ric_indication_message_t
{
    e2ap_dynamic_string_t   ric_indication_message;
} e2ap_ric_indication_message_t;

typedef struct _e2ap_ric_indication_t
{
    /* RIC Requestor ID */
    UInt16  ric_requestor_id;
    
    /* RIC Instance ID */
    UInt16  ric_instance_id;
    
    /* RIC Function ID */
    UInt16  ran_function_id;
    
    /* RIC Action ID */
    UInt8   ric_action_id;

    /* RIC Indication type */
    UInt32  ric_indication_type;

    /*RIC RIC Indication SN */
    UInt16  ric_seq_number;

    /* RIC Indication header */
    e2ap_ric_indication_header_t    ric_indication_header;
    
    /* RIC Indication message */
    e2ap_ric_indication_message_t   ric_indication_message;

    /* Call Process ID */
    e2ap_dynamic_string_t           call_process_id;
} e2ap_ric_indication_t;

e2_return_et encode_e2sm_ni_indication_header_payload
(
 UInt8           *p_asn_msg,    /* Output - ASN Encoded Buffer */
 UInt16          *p_asn_msg_len, /* Output - ASN Encoded Buffer Length */
 e2ap_ric_indication_header_t *p_local_e2ap_ric_indication_header
 );
e2_return_et encode_e2sm_ni_indication_message_payload
(
 UInt8           *p_asn_msg,    /* Output - ASN Encoded Buffer */
 UInt16          *p_asn_msg_len, /* Output - ASN Encoded Buffer Length */
 void            *p_ni_msg,
 UInt16           ni_msg_length
 );

e2_return_et encode_e2sm_ni_call_process_id_payload
(
 UInt8           *p_asn_msg,    /* Output - ASN Encoded Buffer */
 UInt16          *p_asn_msg_len, /* Output - ASN Encoded Buffer Length */
 UInt32           call_process_id
 );

e2_return_et encode_e2ap_ric_indication
(
 UInt8                       *p_asn_msg,    /* Output - ASN Encoded Buffer */
 UInt16                      *p_asn_msg_len, /* Output - ASN Encoded Buffer Length */
 e2ap_ric_indication_t       *p_local_e2ap_ric_indication /* Input from which ASN Msg will be prepared */
 );

e2_return_et encode_e2sm_rc_indication_header_payload
(
 UInt8           *p_asn_msg,    /* Output - ASN Encoded Buffer */
 UInt16          *p_asn_msg_len, /* Output - ASN Encoded Buffer Length */
 e2ap_ric_indication_header_t *p_local_e2ap_ric_indication_header
 );


typedef struct _ric_id_info_t
{
    UInt16          ric_requestor_id;
    /*^ M, 0, N, 0, 0 ^*/
    
    UInt16          ric_instance_id;
    /*^ M, 0, N, 0, 0 ^*/
    
    UInt8           ric_action_id;
    /*^ M, 0, N, 0, 0 ^*/
    
    UInt16          ran_function_id;
    /*^ M, 0, N, 0, 0 ^*/
} ric_id_info_t;

typedef struct _e2cu_ngap_ni_subscription_req_t
{
    ric_id_info_t   ric_id;
    /*^ M, 0, N, 0, 0 ^*/
    
    UInt8           ni_subscription_enable;
    /*^ M, 0, N, 0, 0 ^*/
} e2cu_ngap_ni_subscription_req_t;

typedef struct _e2du_kpm_action_mes_data_t
{
    UInt8   *mes_name;
    UInt32   mes_name_len;
    UInt32   mes_id;
} e2du_kpm_action_mes_data_t;

typedef struct _e2sm_ni_event_kpm_trigger_definition_t
{
#define E2KPM_MAX_MEAS_ID_IN_ACTION 10
    UInt32  reportingPeriod;
    UInt32 report_style;
    UInt8                     *cellObjID;
    UInt32 cell_obj_len;
    UInt32 granularity_period;
    UInt32 subscription_id;
    UInt8 count;
    e2du_kpm_action_mes_data_t      Action_List[E2KPM_MAX_MEAS_ID_IN_ACTION];
} e2sm_ni_event_kpm_trigger_definition_t;

typedef struct _e2ap_error_indication
{
 UInt16 transaction_id;
 UInt16 cause;
 UInt16 time_to_wait;
}e2ap_error_indication_t;

typedef struct _e2ap_reset_request
{
 UInt16 transaction_id;
 UInt16 cause;
}e2ap_reset_request_t;

typedef struct _e2ap_e2_setup_failure_t
{
 UInt16 transaction_id;
 UInt16 cause;
 UInt16 time_to_wait;
}e2ap_e2_setup_failure_t;

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

e2_return_et e2cu_decode_ric_subscription_req
(
 UInt8                  *p_asn_msg,     /* Input - ASN Encoded Buffer */
 UInt16                  asn_msg_len,   /* Input - ASN Encoded Buffer Length */
 e2ap_ric_subscription_request_t    *p_ric_subscription_req,    /* Output - Local Buffer */
 e2ap_ric_subscription_failure_t    *p_ric_subscription_failure
);


e2_return_et ric_subscription_req_internal_dec
(
 OSCTXT                 *p_asn1_ctx,            /* Input: ASN1 Context to be used */
 e2ap_RICsubscriptionRequest     *p_asn_ric_subscription_req,    /* Input: Received ASN Buffer */
 e2ap_ric_subscription_request_t    *p_local_ric_subscription_req,   /* Output: Local Message Structure */
 e2ap_ric_subscription_failure_t      *p_local_ric_subcription_failure
);


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


void build_and_send_e2du_mac_timing_advance_report_req
(   ric_event_trigger_definition_t *p_ric_event_trigger_definition,
            e2ap_ric_subscription_request_t     *p_decoded_ric_subscription_req,
                         cell_index_t       cell_index,
                                          UInt16             transaction_id
                                                           );

void build_and_send_e2du_mac_slot_indication_report_req
(    ric_event_trigger_definition_t *p_ric_event_trigger_definition,
               e2ap_ric_subscription_request_t     *p_decoded_ric_subscription_req,
                              cell_index_t       cell_index,
                                                  UInt16             transaction_id
                                                                      );

void build_and_send_e2du_rlc_traffic_report_req
(    ric_event_trigger_definition_t *p_ric_event_trigger_definition,
               e2ap_ric_subscription_request_t     *p_decoded_ric_subscription_req,
                              cell_index_t       cell_index,
                                                  UInt16             transaction_id
                                                                      );

void build_and_send_e2du_mac_downlink_channel_quality_report_req
(    ric_event_trigger_definition_t *p_ric_event_trigger_definition,
               e2ap_ric_subscription_request_t     *p_decoded_ric_subscription_req,
                              cell_index_t       cell_index,
                                                  UInt16             transaction_id
                                                                      );

void build_and_send_e2du_mac_uplink_channel_estimate_report_req
(    ric_event_trigger_definition_t *p_ric_event_trigger_definition,
               e2ap_ric_subscription_request_t     *p_decoded_ric_subscription_req,
                              cell_index_t       cell_index,
                                                  UInt16             transaction_id
                                                                      );

void build_and_send_e2du_mac_ue_scheduling_req
(    ric_control_header_t *ric_control_header,
               ric_control_message_t  *ric_control_message,
                              e2ap_ric_control_request_t      *p_decoded_ric_control_req,
                                                  cell_index_t       cell_index,
                                                                           UInt16             transaction_id
                                                                                                    );

e2_return_et e2ap_encode_ric_control_acknowledge
(
 UInt8                                          *p_asn_msg,           /* Output - ASN Encoded Buffer */
 UInt16                                         *p_asn_msg_len,        /* Output-ASN Encoded Buffer Length */
 UInt8                                         	control_feedback,        /* Output-ASN Encoded Buffer Length */
 UInt16                                         ric_requestor_id,
 UInt16                                         ric_instance_id,
 UInt8                                          ric_action_id
 );


e2_return_et encode_e2sm_kpm_indication_header_payload
(
 UInt8           *p_asn_msg,    /* Output - ASN Encoded Buffer */
 UInt16          *p_asn_msg_len, /* Output - ASN Encoded Buffer Length */
 e2ap_ric_indication_header_t *p_local_e2ap_ric_indication_header
);


e2_return_et encode_e2sm_kpm_indication_message_payload 
(
        UInt8 *p_asn_msg, /* Output - ASN Encoded Buffer */
        UInt16 *p_asn_msg_len, /* Output - ASN Encoded Buffer Length */
        void *p_ni_msg, UInt16 ni_msg_length,
        oam_e2du_kpm_indication_t *p_kpi_resp,
        ric_subscription_info_t *p_ric_subscription_info
);


e2_return_et encode_e2_setup_response
(
 UInt8                                          **pp_asn_msg,
 UInt16                                         *p_asn_msg_len
);


e2_return_et e2ap_encode_ric_subscription_failure
(
 UInt8 *p_asn_msg,
 UInt16 *p_asn_msg_len,
 e2ap_ric_subscription_failure_t      *p_local_ric_subcription_failure
);

e2_return_et e2cu_decode_ric_subscription_delete_req
(
 UInt8			        *p_asn_msg,	    /* Input - ASN Encoded Buffer */
 UInt16                  asn_msg_len,	/* Input - ASN Encoded Buffer Length */
 e2ap_ric_subscription_delete_request_t	*p_ric_subscription_delete_req,	/* Output - Local Buffer */
 e2ap_error_causes_t     *p_error_cause
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


e2_return_et encode_error_indication_message
(
 UInt8                         *p_asn_msg,    
 UInt16                        *p_asn_msg_len,
 e2_error_indication_msg_t     *p_local_e2_error_ind_msg
);

e2_return_et e2ap_decode_reset_request
(
 UInt8                      *p_asn_msg,     
 UInt16                     asn_msg_len,
 e2ap_reset_request_t      *p_local_e2ap_reset_request
);

e2_return_et e2ap_encode_ric_reset_response
(
 e2ap_ric_reset_response_t                      *p_local_ric_reset_resp,
 UInt8                                          *p_asn_msg,
 UInt16                                         *p_asn_msg_len
);


#if 0
e2_return_et encode_e2sm_kpm_subscription_event_trigger_format1
(
 UInt8                       **pp_asn_msg,
 UInt16                      *p_asn_msg_len,
 UInt16                      ric_style,
 UInt32 reportingPeriod
 );


e2_return_et encode_e2sm_kpm_action_definition_format1
(
 UInt8                       **pp_asn_msg,
 UInt16                      *p_asn_msg_len,
 UInt16                      ric_style,
 UInt16                      meas_id,
 UInt16                      granularity_period
 );
 #endif

e2_return_et encode_e2sm_kpm_action_definition_format3
(
 UInt8                       **pp_asn_msg,
 UInt16                      *p_asn_msg_len,
 UInt16                      ric_style,
 UInt16                      meas_id,
 UInt16                      granularity_period
 );



e2_return_et encode_e2_subscription_req
(
 UInt8                                          **pp_asn_msg,
 UInt16                                         *p_asn_msg_len,
 UInt16 ricInstanceID ,
 UInt16 ricRequestorID ,
 UInt16 functionId,
 UInt16 ricActionID,
 UInt16 ricActionType,
 UInt8 *p_event_trigger_def,
 UInt16 event_trigger_len ,
 UInt8 *p_action_def ,
 UInt16 action_pdu_len
 );

