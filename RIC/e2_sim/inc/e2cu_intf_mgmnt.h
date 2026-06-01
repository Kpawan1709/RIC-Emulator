#if defined (E2CU_QOS_CHANGES) || defined (E2CU_MU_MIMO_CHANGES)
/*******************************************************************************
 *
 *  ARICENT -
 *
 *  Copyright (C) 2018 Aricent Inc. All Rights Reserved.
 *
 *******************************************************************************
 *
 *  $Id: ngap_intf_mgmnt.h
 *
 *******************************************************************************
 *
 *  File Description : 
 *
 ******************************************************************************/

#ifndef _E2CU_INTF_MGMNT_H_
#define _E2CU_INTF_MGMNT_H_

/*******************************************************************************
 * Project Includes
 ******************************************************************************/
#include "gnb_defines.h"
#include "e2cu_asn_enc_dec_wrapper.h"
#include "e2cu_asn_wrapper_utils.h"
#include "ric_md.h"
#ifdef E2CU_QOS_CHANGES

/* RAN Function Added List Changes Start */
#define MAX_RIC_STYLE_COUNT         2
#define MAX_E2SM_RC_EVENT_STYLE     4
#define MAX_E2SM_FUNC_OID_LENGTH    50

typedef struct
{
    UInt16                       ran_function_id;

    e2ap_dynamic_string_t             ran_function_definition_payload;
    
    UInt16                       ran_function_revision;

} ran_function_added_item_list_t;

typedef struct
{
#define         E2AP_RAN_FUNCTION_LIST_COUNT    4

    UInt8       count;

    ran_function_added_item_list_t      ran_function_added_item_list[E2AP_RAN_FUNCTION_LIST_COUNT];

} ran_functions_added_list_t;
/* RAN Function Added List Changes End */

e2_return_et encode_e2_setup_request
(
 UInt8                                          *p_asn_msg,           /* Output - ASN Encoded Buffer */
 UInt16                                         *p_asn_msg_len,        /* Output-ASN Encoded Buffer Length */
 e2_setup_request_t                             *p_local_e2_setup_req,
 ran_functions_added_list_t                     *p_local_ran_function_added_list,
 e2node_component_config_add_list_t             *p_local_e2node_component_conf_list
 );
#endif

typedef struct
{
    /* PLMN ID */
    UInt8               plmn_id[MAX_PLMN_ID_BYTES];

    /* ENB-ID Num bits */
    UInt32              enb_id_num_bits;

    /* ENB ID */
    UInt8               enb_id[GNB_ID_OCTET_SIZE];
} global_ng_ran_id_t;

typedef struct
{
    /* Network Interface Type */
    UInt32                  ni_type;

    UInt8                   nr_cell_identity[E2CU_NR_CELL_IDENTITY_OCTET_SIZE];

    /* Global NG RAN ID */
    global_ng_ran_id_t      ng_ran_id;

    /* Network Interface Direction */
    UInt32                  ni_direction;

    e2ap_dynamic_string_t   ric_indication_header;
} e2ap_ric_indication_header_t;

typedef struct
{
    e2ap_dynamic_string_t   ric_indication_message;
} e2ap_ric_indication_message_t;

typedef struct
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
    UInt32  ric_indication_sn;

    /* RIC Indication type */
    UInt32  ric_indication_type;

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

#ifdef E2CU_KPM_CHANGES
e2_return_et encode_e2sm_kpm_indication_header_payload
(
 UInt8           *p_asn_msg,    /* Output - ASN Encoded Buffer */
 UInt16          *p_asn_msg_len, /* Output - ASN Encoded Buffer Length */
 e2ap_ric_indication_header_t *p_local_e2ap_ric_indication_header
 );
#endif

#endif /* _E2CU_INTF_MGMNT_H_ */
#endif
