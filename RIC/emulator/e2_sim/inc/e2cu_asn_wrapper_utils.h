#if defined (E2CU_QOS_CHANGES) || defined (E2CU_MU_MIMO_CHANGES)
#ifndef _E2CU_UTILS_H_
#define _E2CU_UTILS_H_
#include "e2_utils.h"
#include "e2ap_asn_enc_dec_3gpp.h"
#include "e2sm_rc_asn_enc_dec_3gpp.h"

#define CHECK_NULL_AND_BREAK(ptr) if (E2_PNULL == ptr){\
            GNB_TRACE(GNB_ERROR, "Memory allocation failed");\
            break;\
        }\

#define	UE_CONTEXT_RELEASE_COMPLETE_IE_ID  41
#define PDU_SESSION_RESOURCE_RELEASE_IE_ID 28
#define PDU_SESSION_RESOURCE_NOTIFY_IE_ID  30
#define MAX_RC_SUBSCRIPTIONS_SUPPORTED 10
#define MAX_NI_SUBSCRIPTIONS_SUPPORTED 10
#define MAX_KPM_SUBSCRIPTIONS_SUPPORTED 10
#define E2_PLMN_IDENTITY_MAX_BYTES              3

typedef enum _E2SM_FORMATS
{
    FORMAT1 = 1,
    FORMAT2,
    FORMAT3,
    FORMAT4,
    FORMAT5
} E2SM_FORMATS;


typedef enum _RC_EVENT_TRIGGER_MESSAGE_TYPE
{
  NOT_PROVIDED, NI_MESSAGE, RRC_MESSAGE
} RC_EVENT_TRIGGER_MESSAGE_TYPE;


typedef enum _E2_RC_NI_MESSAGE_TYPE
{
  NOT_INCLUDED,
  INITIATING_MESSAGE,
  SUCCESSFUL_OUTCOME,
  UN_SUCCESSFUL_OUTCOME
}E2_RC_NI_MESSAGE_TYPE;


typedef enum _e2cu_rc_subscription_type_et
{

    E2CU_SUBSCRIPTION_NOT_ACTIVE,
    E2CU_PDU_SESSION_RESOURCE_SETUP,
    E2CU_PDU_SESSION_RESOURCE_RELEASE,
    E2CU_PDU_SESSION_RESOURCE_NOTIFY, 
    E2CU_UE_CONTEXT_RELEASE_COMPLETE, 
    E2CU_HANDOVER_RESOURCE_ALLOCATION,
    E2CU_RRC_PERIODIC_MEASUREMENT_REPORT 

}e2cu_rc_subscription_type_et;


typedef struct _e2sm_ni_event_trigger_definition
{
    UInt32  ni_type;
} e2sm_ni_event_trigger_definition_t;


typedef struct _e2sm_guami_t
{
#define E2_REGION_ID_OCTET_SIZE                 1
#define E2_SET_ID_OCTET_SIZE                    2
#define E2_POINTER_OCTET_SIZE                   1

    UInt8 plmn_id_bytes[E2_PLMN_IDENTITY_MAX_BYTES];
    UInt8 amf_region_id[E2_REGION_ID_OCTET_SIZE];
    UInt8 amf_set_id[E2_SET_ID_OCTET_SIZE];
    UInt8 amf_pointer[E2_POINTER_OCTET_SIZE];
} e2sm_guami_t;

#define E2CU_UE_ID_PRESENT 0x01
typedef struct _e2sm_ue_id_t
{
    UInt8 bitmask;
    UInt64 amf_ue_ngap_id;
    e2sm_guami_t guami;
    UInt16 gnb_cu_ue_f1ap_id_count;
    UInt16 gnb_cu_ue_f1ap_id;
} e2sm_ue_id_t;

typedef struct _ric_id_info_list_t
{
    UInt16    ric_requestor_id;
    UInt16    ric_instance_id;
    UInt8     ric_action_id;
    UInt16    ran_function_id;
} ric_id_info_list_t;



typedef struct _e2sm_rc_action_def_format_1
{
    UInt32 ric_style_type;
} rc_action_def_format_1_t;

typedef struct _e2sm_rc_action_def_format_3
{
    UInt32 ric_style_type;
    UInt32 indication_id;
    e2sm_ue_id_t ueid;

} rc_action_def_format_3_t;

typedef struct _e2sm_rc_action_def_t
{
    E2SM_FORMATS e2sm_rc_action_def_format;
    UInt8 ric_action_id;
    UInt32 ric_action_type;
    rc_action_def_format_1_t e2sm_rc_action_def_format_1;
    rc_action_def_format_3_t e2sm_rc_action_def_format_3;
} rc_action_def_t;


typedef struct _rc_rrc_message_t
{
    UInt32 message_class;
    UInt32 rrc_message_id;
} rc_rrc_message_t;

/*common structure used for NI messages*/
typedef struct _rc_ni_message_t
{
  /*Interface Type*/
    UInt32 ni_type;
    /*Network Interface Message ID - Message Type*/
    /*NOT_INCLUDED  - indicate procedure id not provided*/
    E2_RC_NI_MESSAGE_TYPE ni_interface_message_type;
    /*Network Interface Message ID - Message Type*/
    UInt32 ni_interface_procedure_id;
} rc_ni_message_t;

typedef struct _rc_event_trigger_def_format1_t
{
    RC_EVENT_TRIGGER_MESSAGE_TYPE e2sm_rc_message_type;
    UInt32 event_trigger_condition_id;
    rc_ni_message_t ni_message;
    rc_rrc_message_t rrc_message;
} rc_event_trigger_def_format1_t;

typedef struct _rc_event_trigger_def_format2_t
{
    UInt32 call_breaking_point_id;
    UInt32 callProcess_type;
} rc_event_trigger_def_format2_t;


typedef struct _rc_event_trigger_t
{
    E2SM_FORMATS event_trigger_format;
    rc_event_trigger_def_format1_t e2sm_rc_event_trigger_type_1;
    rc_event_trigger_def_format2_t e2sm_rc_event_trigger_type_2;
} rc_event_trigger_def_t;


typedef struct
{
    ric_id_info_list_t      ric_id_info_list;
    UInt32                  ran_ue_ngap_id;
}ni_subscription_info_t;

typedef struct _kpm_subscription_info_t
{
    ric_id_info_list_t      ric_id_info_list;
    UInt32                  ran_ue_ngap_id;
}kpm_subscription_info_t;


typedef struct _rc_subscription_info_t
{

    UInt32 ran_ue_ngap_id;
    UInt32 last_indicated_sn;
    e2cu_rc_subscription_type_et expected_indication;
    ric_id_info_list_t ric_id_info;
    rc_event_trigger_def_t rc_event_trigger;
    rc_action_def_t  rc_action_def;

} rc_subscription_info_t;


 typedef struct
{
    UInt32 event_trigger_condition_id;
} rc_indication_header_format_1_t;

 typedef struct
{
    e2sm_ue_id_t ue_id;
    UInt32 insert_ind_id;
    UInt32 insert_sytle_id;
} rc_indication_header_format_2_t;


typedef struct
{
    /* PLMN ID */
    UInt8               plmn_id[3];

    /* ENB-ID Num bits */
    UInt32              enb_id_num_bits;

    /* ENB ID */
    UInt8               enb_id[4];
} ng_ran_id_t;

typedef struct _e2sm_nr_cgi
{

    /* PLMN Identity */
    UInt8    plmn_id_bytes[E2_PLMN_IDENTITY_MAX_BYTES];

    /* NR Cell Identity */
    UInt8    nr_cell_identity[E2CU_NR_CELL_IDENTITY_OCTET_SIZE];

} e2sm_nr_cgi_t;

typedef struct _rc_indication_message_format_1
{
 /*Common to NI & RRC message*/
  e2sm_ue_id_t ue_id;
  ng_ran_id_t  ng_ran_id;
  UInt8 *p_asn_msg;
  UInt32 asn_message_len;
  RC_EVENT_TRIGGER_MESSAGE_TYPE indication_msg_type;
} rc_indication_message_format_1_t;


typedef struct ran_paramter_value
{
    UInt16 param_id;
    UInt16 param_value;
} ran_paramter_value_t;
/* Dynamic String */
typedef struct
{
    /* Length of Dynamic String */
    UInt32  num_string_len;
    /* String Data */
    UInt8   *string_data;
} dynamic_string_t;

e2_return_et e2sm_rc_add_list_param 
(
        OSCTXT *p_asn1_ctx,
        UInt32 param_id, OSRTDListNode **pplist_node,
        OSRTDList **pplist_ranparamslist
);


e2_return_et e2sm_rc_add_int_parameter_to_structure 
(
        OSCTXT *p_asn1_ctx,
        E2SM_RC_RANParameter_STRUCTURE_sequence_of_ranParameters *p_asn_seq_parameter_list,
        UInt32 param_id, UInt32 value
);


e2_return_et e2sm_rc_add_struct_ran_param_to_list 
(
        OSCTXT *p_asn1_ctx,
        UInt32 param_id, 
        OSRTDListNode **pp_strut_node,
        OSRTDList **pplist_node,
        OSRTDList **pplist_ranparamseq
);

void decode_e2_ue_id
(
        void *p_msg ,
        e2sm_ue_id_t *p_e2cu_ue_id,
        void *p_asn_msg,
        UInt32 *p_asn_msg_len
);

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

void indication_pdu_session_resource_setup();
void indication_pdu_session_resource_release();
void indication_pdu_session_resource_notify();
void indication_ue_context_release_complete();
void indication_ho_resource_allocation();
void indication_rrc_periodic_meas();

#endif
#endif
