/******************************************************************************
 *
 *   FILE NAME:
 *       rrc_defines.h
 *
 *   DESCRIPTION:
 *       This file contains basic RRC types definitions.
 *
 *   DATE            AUTHOR      REFERENCE       REASON
 *   31 Mar 2009     VasylN      ---------       Initial
 *   27 Oct 2017     ManishK     ---------       Dual Connectivity
 *
 *   Copyright (c) 2009, Aricent Inc. All Rights Reserved
 *
 ******************************************************************************/

#ifndef _RRC_DEFINES_H_
#define _RRC_DEFINES_H_
#include "gnb_defines.h"
#include "stacklayer.h"
#include "logging.h"
typedef QTIMER      rrc_timer_t;
typedef UInt8              rrc_bool_t;
typedef UInt16      ue_index_t;
typedef UInt16      cell_index_t;
typedef UInt16      nr_pci_t;
typedef UInt16      counter_t;
typedef UInt16      bitmask_t; /* Bitmask for message structure */
typedef UInt8       srb_id_t; /* SRB=0,1,2,3 */
typedef UInt8       drb_id_t; /* DRB 4-32 */
#define MIN_DRB_ID          4
fd_set         sctp_fd;
/*GSAL_5394 fix S*/
#define F1AP_ADDITIONAL_PORT_IP_NUM  4 
/*GSAL_5394 fix E*/

#define MAX_RB              (MAX_SRB + MAX_DRB) /* Max RB excluding SRB0 */

//#define MAX_NUM_PURGE_UE_IN_BATCH 12000
#define MAX_NUM_RESET_UE          3000 /*F1Reset Changes*/
#define MAX_NUM_X2_RESET_UE       256
#define MAX_NUM_X2_RESET_PEER     16

#define MAX_QOS_FLOWS             64

/*FJT_cp_tnl_info_src_change_S*/
#define NGAP_MAX_NUM_IP_ADDR                    3
/*CSR_00162478_FIX_S*/
#define MAX_NUM_AMF_SUPPORTED                   4
/*CSR_00162478_FIX_E*/
/*FJT_cp_tnl_info_src_change_E*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/*Basic types */
#include <sys/types.h>

#ifdef ALM_FRWK
#include "alarm.h"
#endif

#include <cspl.h>

/*CDMA2000_CSFB_HO start*/
#include <pthread.h>
/*CDMA2000_CSFB_HO stop*/
#define LEFT_NIBBLE_MASK                        0x0F
#define FOUR_BIT_SHIFT                          0x04

/* make global visibility for static functions used in unit tests */
#ifdef RRC_DEBUG
#define STATIC
#else
#define STATIC static
#endif

#ifdef ALM_FRWK
#define ALARM_MSG_L3(src_module_id,alarm_id,criticality,cause_id)    ALARM_MSG(src_module_id,alarm_id,criticality)
#define ALARM_FMT_MSG_L3    ALARM_FMT_MSG
#else
#define ALARM_MSG_L3(src_module_id, alarm_id, criticality,cause_id)
#define ALARM_FMT_MSG_L3(src_module_id, alarm_id, criticality , ...)
#endif

/* CSR_00040799 Fix Start */
/*SPR 21653 changes start*/
/*ifdef MULTISECTOR_ENABLE flag removed as that is always defined*/
#define MAX_NUM_CELLS                          32 
/*SPR 21653 changes end*/
#define MAX_NO_OF_SIB_TYPES                    4

#define MAX_ENB_NAME_STR_SIZE           150 
/* SPR 20908 Start */
#define RRC_MAX_IP_SIZE 4
#define RRC_MINUS_ONE   -1
#define RRC_ONE         1
#define RRC_TWO         2
#define RRC_THREE       3
#define RRC_FOUR        4
#define RRC_FIVE        5
#define RRC_EIGHT       8
/* EN_DC_CHANGES_START */
#define RRC_SIX         6
#define RRC_SEVEN       7
#define RRC_NINE        9
#define RRC_TEN         10
#define RRC_ELEVEN      11

#define RRC_TWELVE      12
#define RRC_THIRTEEN    13
#define RRC_FOURTEEN    14
#define RRC_FIFTEEN     15
#define RRC_SIXTEEN     16
#define RRC_SEVENTEEN   17
#define RRC_EIGHTEEN    18
#define RRC_NINETEEN    19
#define RRC_TWENTY      20
#define RRC_TWENTYONE   21
#define RRC_TWENTYTWO   22
#define RRC_TWENTYTHREE 23
#define RRC_TWENTYFOUR  24
#define RRC_TWENTYFIVE  25
#define RRC_TWENTYSIX   26
#define RRC_TWENTYSEVEN 27
#define RRC_TWENTYEIGHT 28 
#define RRC_TWENTYNINE  29
#define RRC_SIXTY       60
/*maxBitRate fix*/
#define RRC_SIXTY_FIVE    65
#define RRC_SIXTY_SEVEN   67
#define RRC_SEVENTY_FIVE  77
/*maxBitRate fix*/
#define RRC_MILLI_SECONDS 1000
/* SPR 20908 End */
/* SPR 21806 Start */
#define RRC_HUNDRED    100
/* SPR 21806 End */
#define MAX_CELL_INDEX (MAX_NUM_CELLS - 1)

/* SPR 20526 Fix Start */
/* SPR 20526 Fix End */
/* CSR_00040799 Fix End */
/*SPR 19708 FIX START*/
#define RRC_12BIT_MAX_VALUE   4095 
/*SPR 19708 FIX START*/
#define ERAB_ID_MAX 15
#define RRC_OAM_PDCP_COMM_INFO_INDEX            0
#define RRC_OAM_NGU_COMM_INFO_INDEX             1
#define RRC_OAM_MAX_EXT_LOWER_LAYER_MODULES     2
#if defined (E2CU_MU_MIMO_CHANGES) || defined (E2_FRAMEWORK)
#define RRC_OAM_MAX_EXT_UPPER_LAYER_MODULES     4
#else
#define RRC_OAM_MAX_EXT_UPPER_LAYER_MODULES     3 
#endif/*end of E2_FRAMEWORK*/
#define BROADCAST_IP_ADDR  0xFFFFFFFF
#define INVALID_IP_ADDR    0x00

#define NAS_SECURITY_PARAM_INTER_RAT_HO_LEN 0x01

#define RRC_INET_ATON inet_aton
/* SPR 21371 Start */
#define IPV6_ADDRESS_LENGTH 40
/* SPR 21371 Start */

/* CSR_00040799 Fix Start */
/* SPR 21251 Start */
/* SPR 21553 Start */
/* SPR 21773 Start */ 
#define MAX_NUM_SUPPORTED_UE_PER_UECC       MAX_UE_SUPPORTED
/* SPR 21773 End */ 
/* SPR 21553 End */
/* SPR 21251 End */
/* CSR_00040799 Fix End */

#define MAX_NUM_SUPPORTED_X2AP_UEID         4096
/* SPR 22706 Fix Start */
#define MAX_ENB_X2AP_UE_ID                  4096
#define EXT_BIT                             16
/* SPR 22706 Fix Stop */

#define RRC_MAX_CELL_IDENTITY_OCTETS        8
#define INVALID_X2AP_UE_ID                  4096
/*SA_L3_MEM_FIX_S*/
#define MAX_UECC_INSTANCES                  8
/*SA_L3_MEM_FIX_E*/
#define MAX_CELL_REPORT                     8
#define MAX_FREQ                            8
#ifdef EN_DC_CUSTOM_ENABLED
#define RRC_OAM_MAX_EXT_SON_UPPER_LAYER_MODULES     12
#else
#define RRC_OAM_MAX_EXT_SON_UPPER_LAYER_MODULES     4 
#endif 
/* Trace Change Start */
#define TRACE_REF_LENGTH   6
/* Trace Change End */
#define MAX_MME_NAME                        150
#define MAX_NUM_SERVED_PLMN                 32
#define MAX_NUM_SERVED_GROUP_ID             256
#define MAX_NUM_SERVED_MMEC                 256
#define MMEGI_OCTET_SIZE                    2
/*CR 970 changes start*/
#define MAX_ASN_BUFF_LENGTH                 100
/*CR 970 changes stop*/

#define OAMH_HEALTH_MONITOR_EXPIRY_EVENT                1
#define UECC1_HEALTH_MONITOR_EXPIRY_EVENT               2
#define UECC2_HEALTH_MONITOR_EXPIRY_EVENT               3
#define UECC3_HEALTH_MONITOR_EXPIRY_EVENT               4
#define UECC4_HEALTH_MONITOR_EXPIRY_EVENT               5
#define UECC5_HEALTH_MONITOR_EXPIRY_EVENT               6
#define UECC6_HEALTH_MONITOR_EXPIRY_EVENT               7
#define UECC7_HEALTH_MONITOR_EXPIRY_EVENT               8
#define UECC8_HEALTH_MONITOR_EXPIRY_EVENT               9
#define UECC9_HEALTH_MONITOR_EXPIRY_EVENT               10
#define UECC10_HEALTH_MONITOR_EXPIRY_EVENT              11
#define UECC11_HEALTH_MONITOR_EXPIRY_EVENT              12
#define UECC12_HEALTH_MONITOR_EXPIRY_EVENT              13
#define UECC13_HEALTH_MONITOR_EXPIRY_EVENT              14
#define UECC14_HEALTH_MONITOR_EXPIRY_EVENT              15
#define UECC15_HEALTH_MONITOR_EXPIRY_EVENT              16
#define UECC16_HEALTH_MONITOR_EXPIRY_EVENT              17
#define UECC17_HEALTH_MONITOR_EXPIRY_EVENT              18
#define UECC18_HEALTH_MONITOR_EXPIRY_EVENT              19
#define UECC19_HEALTH_MONITOR_EXPIRY_EVENT              20
#define UECC20_HEALTH_MONITOR_EXPIRY_EVENT              21
#define UECC21_HEALTH_MONITOR_EXPIRY_EVENT              22
#define UECC22_HEALTH_MONITOR_EXPIRY_EVENT              23
#define UECC23_HEALTH_MONITOR_EXPIRY_EVENT              24
#define UECC24_HEALTH_MONITOR_EXPIRY_EVENT              25
#define UECC25_HEALTH_MONITOR_EXPIRY_EVENT              26
#define UECC26_HEALTH_MONITOR_EXPIRY_EVENT              27
#define UECC27_HEALTH_MONITOR_EXPIRY_EVENT              28
#define UECC28_HEALTH_MONITOR_EXPIRY_EVENT              29
#define UECC29_HEALTH_MONITOR_EXPIRY_EVENT              30
#define UECC30_HEALTH_MONITOR_EXPIRY_EVENT              31
#define UECC31_HEALTH_MONITOR_EXPIRY_EVENT              32
#define UECC32_HEALTH_MONITOR_EXPIRY_EVENT              33
#define CSC_HEALTH_MONITOR_EXPIRY_EVENT                 34
#define LLIM_HEALTH_MONITOR_EXPIRY_EVENT                35
#define ADV_LOGGER_HEALTH_MONITOR_EXPIRY_EVENT          36
#define S1AP_HEALTH_MONITOR_EXPIRY_EVENT                37 
#define SCTP_HEALTH_MONITOR_IPC_MASTER_EXPIRY_EVENT     38 
#define SCTP_HEALTH_MONITOR_RECV_TIMER_EXPIRY_EVENT     39 
#define X2AP_HEALTH_MONITOR_EXPIRY_EVENT                40
/* As per SPEC 36.331 maxBandComb-r10 = 128 can be used.
 * Due to system memory limitation we have been changed to value 32
 * to decrease the size of rrm_ue_context.
 * If system memory supports, 
 * The value can be changed to supported value as per spec 
 * i.e #define  MAX_BAND_COMB_R10 128 */
/* SPR 20817 Fix Start */
/* Optimization done under 18008 and 19986 removed */
/* SPR 21194 fix start*/
#define MAX_BAND_COMB_R10                   128
/* SPR 21194 fix end*/
/* SPR 20817 Fix End */
#define MAX_BAND_COMB_R11                   256
#define MAX_BAND_COMB_R13                   46
/* SPR 13502 Fix Stop */
/* SPR:9111 stop */
#define MAX_N1PUCCH_AN_CS                   4
#define MAX_N1PUCCH_AN_CS_LIST              2
#define MAX_SCELL                   8
#define MAX_SCELL_INDEX             31
/* CA start */
#define RRC_MAX_SCELL       2*MAX_SCELL
/* CA end*/
#define MAX_SERVING_CELL            5
#define CBSR_MAX_VALUE_V1020 14
#define RRC_OCTET_WINDOW            7 
#define MAX_CELLS_PER_UE            8
/* eICIC changes start */
#define MAX_SUBFRAME_CONFIG_FDD_NUMBITS                 40                  // eICIC ue reconfig changes start 
/* eICIC changes stop */
#define MAX_SUBFRAME_CONFIG1_5_TDD_NUMBITS              20
#define MAX_SUBFRAME_CONFIG0_TDD_NUMBITS                70
#define MAX_SUBFRAME_CONFIG6_TDD_NUMBITS                60
#define L3_S1AP_VERSION "\"a60\">"
#define L3_X2AP_VERSION "\"a50\">"
#define L3_RRC_VERSION "\"a70\">"
/* eICIC changes start */
#define CSI_MEAS_MEASUREMENT_SUBSET_SIZE    9
/* eICIC changes stop */
//#ifdef MULTISECTOR_ENABLE
#define  MAX_NUM_CURRENT_SUPPORTED_CELLS        2
//#else
//#define  MAX_NUM_CURRENT_SUPPORTED_CELLS        1
//#endif
#define MAX_MBSFN_SUBFRAME_CONFIG           8
/*SPR 18170:start*/
#define MAX_MBMS_UPDATED_AREA_LIST          16
/*SPR 18170:end*/
#define MAX_MBSFN_AREA_PER_ENB              MAX_NO_OF_MBSFN_AREAS /* MAX_NUM_CELLS * MAX_MBSFN_AREAS * (RESERVED + UNRESERVED) */

/* SCell_FailedtoSetup_List Changes Start */
#define MAX_SCELL_FAILED_TO_SETUP   32
/* SCell_FailedtoSetup_List Changes End */
/*PWS changes start*/
#define MAX_NUMBER_OF_SEGMENTS          64
#define MAXIMUM_SIB_MSG_SIZE            2976
/*PWS changes stop*/

/*RRC REESTABLISHMENT*/
#define DRB_ID_VAL_TO_CAL_MAC_I         0xFF
#define RB_DIR_VAL_TO_CAL_MAC_I         0xFFFF
/*RRC REESTABLISHMENT*/
typedef UInt16 rim_bitmask_t;
typedef UInt8 rim_app_identity_t;
typedef UInt8      rim_pdu_ext_t;
typedef UInt8      rim_ack_t;
typedef UInt8  rim_enb_type_t;
typedef UInt8 rim_nacc_cause_t;
typedef UInt8 rim_utra_si_cause_t;
typedef UInt32  rim_pdu_seq_num_t;
typedef UInt8  rim_protocol_ver_t;
typedef UInt8      rim_cause_t;
typedef UInt8 rim_tag_t;
typedef UInt8 rim_length_t;


/* SPS Start */
#define UE_ADM_SUCCESS_AND_SPS_FAILURE    0x01
/* SPS Stop */
/*SPR 15570 Fix Start*/
#define SCTP_SELECT_RETRY_COUNT 20
#define SCTP_W_CONNECT_TIMER_DURATION 500
/*SPR 15570 Fix Stop*/
/*SPR_16533_START*/
#define SCTP_STREAM_ID_SIZE 2
/*SPR_16533_END*/

#define SECURITY_KEY_BITS   256
#define COPY_BYTES           32
#define SRB_ID_0             0
#define SRB_ID_1             1
#define SRB_ID_2             2
#define SRB_ID_3             3
#define SRB_BIT_OFFSET       SRB_ID_3

#define DRB_ID_1             1

typedef enum
{
    INIT_STATE,
    SEC_COMPLETE_STATE,
    SEC_FAILURE_STATE
}security_mode_update_state_et;

/* eICIC changes start */
typedef enum
{
    X2AP_ONE=0,
    X2AP_TWO,
    X2AP_FOUR
}cell_specific_antenna_port_et;
/* eICIC changes stop */

/* eICIC ue reconfig changes start */
typedef enum
{
    NON_VICTIM=0,
    VICTIM
}dl_interference_info_et;

typedef enum
{
    FDD=0,
    TDD_CONFIG_1_5,
    TDD_CONFIG_0,
    TDD_CONFIG_6
}rrc_mac_csi_meas_subframe_set_choice_et;
/* eICIC changes stop */

void rrc_stop_timer(rrc_timer_t timer);

/* sync changes start */
typedef enum
{
    RRC_MAC_OUT_OF_SYN_INITIAL=0, 
    RRC_MAC_IN_SYN_AFTER_OUT_OF_SYN, 
    RRC_MAC_OUT_OF_SYN_MAX_RETRIES,
    RRC_INVALID_UE_SYNC_NUM=4
}rrc_rrm_ue_sync_status_et;
/* sync changes stop*/

/* re-estab changes start */
typedef enum
{
    RRC_RESTAB_CAUSE_RECONF_FAIL = 0,
    RRC_RESTAB_HO_FAIL,
    RRC_RESTAB_OTHER_FAIL,
    RRC_RESTAB_SP1_2
}rrc_rrm_ue_reestab_config_et;
/* re-estab changes stop */

rrc_timer_t rrc_start_timer
(
 UInt32         timer_duration,
 void        *p_timer_data,
 UInt16         timer_data_size,   
 rrc_bool_t  is_repeated      
 );


#ifdef EN_DC_CUSTOM_ENABLED
typedef struct
{
    UInt16 node_kind;
    UInt16 node_number;
}adpt_x2ap_nk_nnum_t;
#endif

typedef enum
{
    GNB_FAILURE,
    GNB_SUCCESS,
    GNB_PARTIAL_SUCCESS 
} gnb_return_et;

/* Values for rrc_return_et, rrc_return_t */
typedef enum
{
    RRC_FAILURE,
    RRC_SUCCESS,
    RRC_PARTIAL_SUCCESS 
} rrc_return_et;

/* values for rrc_bool_et, rrc_bool_t */
typedef enum
{
    RRC_FALSE,
    RRC_TRUE
} rrc_bool_et;

/*mac_apply_ind_fix_start*/
typedef enum
{
    SUSPEND_REQUIRED,
    REESTABLISH_REQUIRED,
    SCG_CONFIG_QUERY_REQ,
    RRC_RECONFIG_COMP_IND_REQ
} rrc_du_config_req_et;
/*mac_apply_ind_fix_stop*/

/* Trace Change Start */
typedef enum
{
    TRACE_OAM_INITIATED,
    TRACE_S1AP_INITIATED,
    TRACE_X2AP_INITIATED
} rrc_trace_initiator_et;
typedef enum
{
    MACRO_ENB,
    HOME_ENB
}enb_type_et;
/* Trace Change End */

/* values for rrc_periodicity_bool_et  */
typedef enum
{
    RRC_OAM_STATS_PERIODICITY_DISABLED,
    RRC_OAM_STATS_PERIODICITY_ENABLED
} rrc_oam_stats_periodicity_et;


/*Reconfig mode values */
typedef enum
{
    NO_MODE,
    PHY_ONLY,
    MAC_ONLY,
    PHY_MAC_BOTH
}rrc_reconfig_mode_et;

typedef enum
{
    RRC_CELL_DELETION_ONGOING,
    RRC_DUPLICATE_REQ,
    RRC_WRONG_CELL_INDEX,

    RRC_INVALID_CAUSE  
} rrc_trace_start_error_cause_et;

typedef enum
{
    GNB_TRACE_ACTIVATION_MME_INITIATE = 1,
    GNB_TRACE_ACTIVATION_CELL_INITIATE = 2
} rrc_trace_activation_flag_et;

typedef enum
{
    /*SPR 15896 Fix Start*/    
    RRC_OAM_INITIATED_TRACE_ALREADY_ONGOING,
    /*SPR 15896 Fix Stop*/    
    RRC_HO_ONGOING
} rrc_ue_trace_start_error_cause_et;

typedef enum
{
    RRM_RRC_TRUE_1
}concurrent_warning_msg_indicator_et;

/*PWS changes start*/
typedef enum
{
    RRM_PWS_SIB_TYPE_6,
    RRM_PWS_SIB_TYPE_7,
    RRM_PWS_SIB_TYPE_6_7,
    RRM_PWS_SIB_TYPE_8,
    RRM_PWS_SIB_UNDEF
}rrm_pws_sib_type_et;

typedef struct
{
    UInt16                          sib_message_length;

    UInt8                           SIB_Message[MAXIMUM_SIB_MSG_SIZE];

} SIB_Item_Info_t;

typedef enum
{
    CANCEL_ALL_WARNING_MSG_IND

}cancel_all_warning_msg_indicator_et;



/*PWS changes stop*/

typedef enum
{
    RRM_RRC_NO_ERROR,
    RRM_RRC_INTERNAL_FAILURE,
    RRM_RRC_LL_CONFIG_FAILURE,
    RRM_RRC_LL_DEL_FAILURE,
    RRM_RRC_UNKNOWN_FAILURE,
    RRM_RRC_INTERACTION_WITH_OTHER_PROCEDURE_FAILURE,
    RRM_RRC_CELL_START_TIMER_EXPIRED,
    RRM_RRC_CELL_STOP_TIMER_EXPIRED,
    RRM_RRC_PHY_START_FAILURE,
    RRM_RRC_PHY_STOP_FAILURE,
    RRM_RRC_MAC_START_FAILURE,
    RRM_RRC_MAC_STOP_FAILURE,
    RRM_RRC_CELL_START_ALREADY_ONGOING,
    RRM_RRC_CELL_STOP_ALREADY_ONGOING,
    RRM_RRC_INVALID_CONFIGURATION_RECV,
    RRM_RRC_CELL_CONFIG_DOES_NOT_EXIST,
    RRM_RRC_TIMER_EXPIRED,
    RRM_RRC_DUPLICATE_WARNING_MESSAGE,
    /*EPS_Fallback_change_S*/
    RRM_RRC_RNL_IMS_VOICE_EPS_FALLBACK_OR_RAT_FALLBACK_TRIGGERED,
    RRM_RRC_RNL_CAUSE_UNSPECIFIED
    /*EPS_Fallback_change_E*/
#if  defined(NR_NSA_MODE_ENABLED)
    ,RRM_RRC_SA_NSA_NG_LINK_FAILURE
#endif
} rrm_fail_cause_et;

typedef enum
{
    RRM_RRC_UE_INFO_INTERNAL_FAILURE,
    RRM_RRC_UE_INFO_TIMER_EXPIRY,
    RRM_RRC_UE_INFO_INTERACTION_WITH_OTHER_PROCEDURE_FAILURE
}rrm_ue_info_fail_cause_et;

typedef enum
{
    RRC_ERAB_NOT_INITIALIZED = 0,
    /*SPR_17382_START*/
    RRC_ERAB_FAILURE_PATH_SWITCH_REQ_ACK,
    RRC_ERAB_FAILURE_S1U_RECONFIGURE_CNF,
    /*SPR_17382_END*/
    RRC_ERAB_SUCESS
} rrc_s1ap_path_switch_erab_released_status_et;


typedef enum
{
    RRM_RRC_CAUSE_UNKNOWN_FAILURE,
    RRM_RRC_CAUSE_NO_BROADCAST_ONGOING
} rrm_kill_fail_cause_et;

typedef enum
{
    RRC_RRM_LL_CONFIG_FAILURE,
    RRC_RRM_LL_DEL_FAILURE,
    RRC_RRM_UNKNOWN_FAILURE,
    RRC_RRM_NO_BROADCAST_ONGOING
} rrc_kill_fail_cause_et;

/* cr_316 And 247 enums */
typedef enum
{
    CQI_MASK_R9_SETUP
} cqi_mask_r9_et;

/*tm7-8 fix*/
typedef enum
{
    PMI_RI_REPORT_R9_MAC_RELEASE,
    PMI_RI_REPORT_R9_MAC_SETUP
}pmi_ri_report_r9_mac_et;
/*tm7-8 fix*/

typedef enum
{
    PMI_RI_REPORT_R9_SETUP
}pmi_ri_report_r9_et;

#ifndef OAM_IPR
/* CLPC Start */
typedef enum
{
    DCI_FORMAT_3,
    DCI_FORMAT_3A
}rrc_tpc_rnti_configuration_format_et;
#endif

/*sctp parameters start */
typedef enum
{
    S1AP_OAM_SCTP_CLOSED,
    S1AP_OAM_SCTP_BOUND,
    S1AP_OAM_SCTP_LISTEN,
    S1AP_OAM_SCTP_COOKIE_WAIT,
    S1AP_OAM_SCTP_COOKIE_ECHOED,
    S1AP_OAM_SCTP_ESTABLISHED,
    S1AP_OAM_SCTP_SHUTDOWN_PENDING,
    S1AP_OAM_SCTP_SHUTDOWN_SENT,
    S1AP_OAM_SCTP_SHUTDOWN_RECEIVED,
    S1AP_OAM_SCTP_SHUTDOWN_ACK_SENT
}s1ap_oam_sctp_status_et;

typedef enum
{
    XWAP_OAM_SCTP_CLOSED,
    XWAP_OAM_SCTP_BOUND,
    XWAP_OAM_SCTP_LISTEN,
    XWAP_OAM_SCTP_COOKIE_WAIT,
    XWAP_OAM_SCTP_COOKIE_ECHOED,
    XWAP_OAM_SCTP_ESTABLISHED,
    XWAP_OAM_SCTP_SHUTDOWN_PENDING,
    XWAP_OAM_SCTP_SHUTDOWN_SENT,
    XWAP_OAM_SCTP_SHUTDOWN_RECEIVED,
    XWAP_OAM_SCTP_SHUTDOWN_ACK_SENT
}xwap_oam_sctp_status_et;
/*sctp parameters stop*/


/* CLPC Stop */

typedef enum
{
    MME_ROUND_ROBIN_ALGO,
    MME_WEIGHT_FACTOR_ALGO
}s1ap_oam_mme_selection_algo_et;

/* SPS Start */
typedef enum
{
    RRM_RRC_SETUP_TIMER_EXPIRES = 0,
    RRM_RRC_MAX_ERROR_CODE
}rrc_rrm_error_code_et;
/* SPS Stop */

/* LIPA start */
typedef enum
{
    LGW_NOT_CONFIGURED = 1,
    DEL_LGW_REQ_RECVD_IN_INVALID_L3_STATE
}rrc_oam_delete_lgw_fail_cause_et;

typedef enum
{
    LGW_ALREADY_CONFIGURED = 1,
    INVALID_LGW_IP_ADDR_CONFIGURED,
    ADD_LGW_REQ_RECVD_IN_INVALID_L3_STATE
}rrc_oam_add_lgw_fail_cause_et;

typedef enum
{
    GTP_ERROR_IND = 1,
    GTP_PATH_FAIL,
    OAM_INITIATED_LGW_DEL
}rrc_rrm_error_ind_cause_et;
/* LIPA end */

typedef enum
{
    PERIOD_FACTOR_N2,
    PERIOD_FACTOR_N4
}cqi_periodic_format_ind_subband_cqi_periodicy_factor_et;

typedef enum
{
    RRC_RADIO_FRAME_2,
    RRC_RADIO_FRAME_4,
    RRC_RADIO_FRAME_8,
    RRC_RADIO_FRAME_16,
    RRC_RADIO_FRAME_32,
    RRC_RADIO_FRAME_64,
    RRC_RADIO_FRAME_128,
    RRC_RADIO_FRAME_INFINITY=255
} scell_deactivation_timer_et;

typedef enum
{
    EXTENDED_BSR_SIZES_SETUP
} extended_bsr_sizes_et;

typedef enum
{
    EXTENDED_PHR_SETUP
} extended_phr_et;
typedef enum
{
    RRM_RRC_CSI_AN1,
    RRM_RRC_CSI_AN2,
    RRM_RRC_CSI_AN4,
    RRM_RRC_CSI_AN8
} rrc_rrm_csi_rs_r10_antennaPortCount_et;

typedef enum
{
    RRM_RRC_TM1,
    RRM_RRC_TM2,
    RRM_RRC_TM3,
    RRM_RRC_TM4,
    RRM_RRC_TM5,
    RRM_RRC_TM6,
    RRM_RRC_TM7,
    RRM_RRC_TM8_V920,
    RRM_RRC_TM9_V1020
} rrc_rrm_transmission_mode_r10_et;

typedef enum
{
    RRM_RRC_N6_5,
    RRM_RRC_N15_2,
    RRM_RRC_N25_2,
    RRM_RRC_N50_3,
    RRM_RRC_N75_2,
    RRM_RRC_N100_3
} rrc_rrm_scell_non_ul_dl_bandwidth_et;

typedef enum
{
    RRM_RRC_AN1,
    RRM_RRC_AN2,
    RRM_RRC_AN4
} rrc_rrm_scell_non_ul_antenna_port_count_et;

typedef enum
{
    N2_TX_ANTENNA_TM3_V1020 = 0,
    N4_TX_ANTENNA_TM3_V1020 = 1,
    N2_TX_ANTENNA_TM4_V1020  = 2,
    N4_TX_ANTENNA_TM4_V1020 = 3,
    N2_TX_ANTENNA_TM5_V1020 = 4,
    N4_TX_ANTENNA_TM5_V1020 = 5,
    N2_TX_ANTENNA_TM6_V1020 = 6,
    N4_TX_ANTENNA_TM6_V1020 = 7,
    N2_TX_ANTENNA_TM8_R9_V1020 = 8,
    N4_TX_ANTENNA_TM8_R9_V1020 = 9
} codebook_subset_restriction_v1020_type_et;

#define TX_ANTENNA_INVALID_VAL 10

typedef enum
{
    N2_TX_ANTENNA_TM3_NUM_BITS_V1020 = 2,
    N4_TX_ANTENNA_TM3_NUM_BITS_V1020 = 4,
    N2_TX_ANTENNA_TM4_NUM_BITS_V1020  = 6,
    N4_TX_ANTENNA_TM4_NUM_BITS_V1020 = 64,
    N2_TX_ANTENNA_TM5_NUM_BITS_V1020 = 4,
    N4_TX_ANTENNA_TM5_NUM_BITS_V1020 = 16,
    N2_TX_ANTENNA_TM6_NUM_BITS_V1020 = 4,              /* trans_mode_fix */
    N4_TX_ANTENNA_TM6_NUM_BITS_V1020 = 16,             /* trans_mode_fix */
    N2_TX_ANTENNA_TM8_NUM_BITS_R9_V1020 = 6,
    N4_TX_ANTENNA_TM8_NUM_BITS_R9_V1020 = 32,          /* trans_mode_fix */
    N2_TX_ANTENNA_TM9_NUM_BITS_R10_V1020 = 6,
    N4_TX_ANTENNA_TM9_NUM_BITS_R10_V1020 = 64,
    N8_TX_ANTENNA_TM9_NUM_BITS_R10_V1020 = 109
} codebook_subset_restriction_v1020_numbits_et;
typedef enum
{
    ADD_SCELL = 0,
    MODIFY_SCELL = 1,
    DELETE_SCELL = 2
}operation_type_et;
typedef enum
{
    F1_TIME_TO_WAIT_1S,
    F1_TIME_TO_WAIT_2S,
    F1_TIME_TO_WAIT_5S,
    F1_TIME_TO_WAIT_10S,
    F1_TIME_TO_WAIT_20S,
    F1_TIME_TO_WAIT_60S
}rrc_f1ap_time_to_wait_et;

typedef enum
{
    NR_NSA_MODE,
    NR_SA_MODE
} rrc_nr_mode_type_et;
typedef enum
{
    NR_SA_OP_MODE,
    NR_NSA_OP_MODE,
    NR_SA_NSA_OP_MODE
} rrc_operational_mode_et;

/* RRC types */
typedef UInt16             rrc_bitmask_t;
typedef UInt32             rrc_bitmask_UInt32_t;
typedef UInt16             rrc_error_t;
typedef UInt16             rrc_ue_index_t;
typedef UInt8              rrc_lc_id_t;
typedef UInt16             rrc_response_t;
typedef UInt16             rrc_tag_t;
typedef UInt16             rrc_length_t;
typedef UInt16             rrc_counter_t;
typedef UInt16             rrc_sfn_t;
typedef UInt8              rrc_sf_t;
/*CDMA2000_CSFB_HO start*/
typedef UInt64             rrc_timestamp_U64_t;
typedef UInt32             rrc_timestamp_UInt32_t;
/*CDMA2000_CSFB_HO stop*/
typedef UInt16             rrc_rnti_t;
typedef UInt16             rrc_transaction_id_t;
/*CSR_00159840 Fix Start*/
typedef UInt16              rrc_cell_index_t;
/*CSR_00159840 Fix End*/
/* SPR 20908 Start */
typedef UInt8              rrc_l2_instance_t;
/* SPR 20908 End */
typedef UInt16             rrc_sn_field_l_t;
typedef UInt16             rrc_t_reordering_t;
typedef void            rrc_void_t;
typedef size_t          rrc_size_t;
typedef QTIMER          rrc_timer_t;
/*RRC_INACTIVE_TIMER*/
typedef UInt32             rrc_timer_duration_t;
/*RRC_INACTIVE_TIMER*/
typedef UInt8              rrc_return_t;
typedef UInt8              rrc_bool_t;
typedef UInt16             gnb_module_id_t;
typedef UInt16             rrc_rb_direction_t;
typedef UInt16             rrc_phys_cell_id_t;
typedef UInt32             rrc_gtp_teid_t;
typedef UInt8              rrc_retry_count_t;


#define RRC_ASN_CNTXT OSCTXT

#define ENDIAN_INIT 1
#define IS_LITTLE_ENDIAN(endian_check) (*((UInt8*)&endian_check)?1:0)

/* Means that encapsulating shell should release the buffer after processing of
 *  the message */

#define RRC_BUFFER_SHOULD_BE_RELEASED 1

/* Settings for ASN buffer */
#define ASN_RRC_BUF_TYPE FALSE
#define ASN_S1AP_BUF_TYPE TRUE
#define ASN_X2AP_BUF_TYPE TRUE
#define ASN_XNAP_BUF_TYPE TRUE

/* Special value for rrc_transaction_id_t */
#define RRC_TRANSACTION_ID_ABSENT       0xFFFF
/* SPR 16087 Start */
#define RRC_S1U_END_MARKER_RESERVED_TRANSACTION_ID       0xFFFE
/* SPR 16087 Stop */
#define MAX_TRANSACTION_ID        256
/* MULTI_PDCP CHANGES START */
#define MAX_NUM_PDCP_INSTANCES        8
/* MULTI_PDCP CHANGES END */
#define RRC_ZERO        0
#define RRC_SIX         6
#define RRC_ONE         1
#define RRC_TWO         2

#define RRC_VERSION_ID          0x01
#define RRC_INVALID_RNTI            0      
#define RRC_INVALID_CELL_INDEX      0xFF      
#define RRC_INVALID_CORE_NUM        0xFF      
#define RRC_INVALID_UE_INDEX        0xFFFF
#define MAX_UDP_LENGTH              0xFFFF
#define MAX_VALID_DC_UE_ID          0xFFF
/* SPR 22706 Fix Start */
#define RRC_INVALID_X2AP_INDEX      0xFFFFFFFF
/*InterDuHO changes S*/
#define RRC_INVALID_NGAP_INDEX      0xFFFFFFFF
/*RAN_PAGING_S*/
#define RRC_MAX_ACTIVE_UES  10
/*RAN_PAGING_E*/
/*InterDuHO changes E*/
#define RRC_INVALID_TRANSACTION_ID  256     
/* SPR 22706 Fix Stop */
/* CSR_00040799 Fix Start */
/* Maximum number of supported UEs for Release 1.0 */
/* CSR_00040799 Fix End */
#define MAX_RRC_CONNECTION              32
#define RRC_SRB0_LC_ID                  0
#define RRC_SRB1_LC_ID                  1
#define RRC_SRB2_LC_ID                  2

/*  GSAL-4212 Changes Start */
#define RRC_SRB1_SRB2_LC_ID             3
/*  GSAL-4212 Changes End */

#define RRC_MAX_NUM_SRB                 3
#define RRC_MAX_NUM_DRB                 11
#define RRC_MAX_NUM_RB                  14
#define RRC_MAX_INTEGRITY_ALGORITHMS    4 /*ZUC Changes*/
#define RRC_MAX_CIPHERING_ALGORITHMS    4
/* ipv6_change */
#define RRC_MAX_IP_ADDR_LEN             4
#define RRC_MAX_IP_ADDR_LEN_IPV6        16
#define RRC_MAX_IP_ADDR_LEN_IPV4V6      20
/* ipv6_change */
#define RRC_S1U_MAX_QOS_PROFILE_DATA    254
#define MAX_FWD_TUNNELS_PER_ERAB        2
#define RRC_VENDOR_NAME_LEN             8

#define RRC_S1U_MAX_NUM_LC      16
/* cd_762 macro */
#define MAX_LAC_NUMOCTS 2
#define MAX_PLMN_ID_NUMOCTS 3

/*REL 1.2:HANDOVER PROCEDURE START*/
#define MAX_NO_OF_MESSAGES   33    /* Including target cell short mac-i*/
#define UL_PDCP_SDU_NUM_OF_BITS  4096
/*REL 1.2:HANDOVER PROCEDURE START*/
#define MAX_NUM_COUNTER_CHECK_UE    75
#define RRC_MAX_FSM                 0x0A
#define RRC_MAX_STATE_PER_FSM       0x06
#define RRC_MAX_API_TRANSITION      0x02
#define RRC_MAX_PROC_TIMER          0x0f


/* ERAB SETUP START */

#define RRC_MIN_QCI_GBR_LIMIT       1
#define RRC_MAX_QCI_GBR_LIMIT       4
#define RRC_MIN_QCI_NON_GBR_LIMIT   5
#define RRC_MAX_QCI_NON_GBR_LIMIT   9
/* + GQA-5221 changes */
#define RRC_MIN_DC_QCI_LIMIT        82
#define RRC_MAX_DC_QCI_LIMIT        86
/* - GQA-5221 changes */

#define MAX_MME_ERAB_LIST_COUNT     256
#define MAX_SUPPORTED_E_RAB_ID      16
#define MAX_CELL_ID_BITS            28
#define MAX_MACRO_CELL_ID_BITS      20 
#define MAX_HOME_CELL_ID_BITS       28

/* ERAB SETUP STOP */
/* Trace Procedure start */
#define MAX_FILE_NAME_SIZE                      256
#define MAX_UECC_FILE_NAME_SIZE                 262 /* MAX_FILE_NAME_SIZE + sizeof(_UECC1) */
#define MAX_TRANSPORT_LAYER_ADDR_SIZE           20
#define GNB_TRACE_REFERENCE_LENGTH              6
#define MAX_STRING_SIZE                         25   
/* SPR 16113 Start */
#define RRC_DL_CCCH             "RRC_DL_CCCH"
#define RRC_DL_DCCH             "RRC_DL_DCCH"
#define RRC_UL_CCCH             "RRC_UL_CCCH"
#define RRC_UL_DCCH             "RRC_UL_DCCH"
/* SPR 16113 Stop */
/* Trace Procedure stop */

#define RRC_MAX_INACTIVE_UES  10
#define BEARER_TUNNEL_ID  0
#define FWD_TUNNEL_ID_1   1
#define FWD_TUNNEL_ID_2   2
#define NUM_TUNNELS_WITHOUT_FWD                 1
#define NUM_TUNNELS_WITH_FWD_EITHER_UL_OR_DL    2
#define NUM_TUNNELS_WITH_FWD_BOTH_UL_AND_DL      3
#define SAP_FLAGS_FOR_UL_FORWARDING                0X0F
#define SAP_FLAGS_FOR_DL_FORWARDING                0X25
/* lipa start */
#define NUM_TUNNELS_LIPA 2
#define SAP_FLAG_PRIMARY_TUNNEL 0x0F
#define SAP_FLAG_SECONDARY_TUNNEL 0x0E
/* lipa end */

/*Maximum Logical channels for Data are 8 (3 to 10) */
#define MAX_NUM_OF_BEARERS          256
#define MAX_ERAB_COUNT              16
#define MAX_SRB_COUNT               3 /* SRB1,2,3...not includes SRB0 */
#define MAX_LC_COUNT                8
#define RRC_OCTET_SIZE              8
#define INVALID_ERAB_ID             16

/* Used in S1AP (and RRM) */
#define RRC_CELL_IDENTITY_BITS      28
#define RRC_CSG_ID_BITS             27

/* SFN is 10 bits wide: 0, 1, 2, ... SFN_UPPER_LIMIT - 1 */
#define SFN_UPPER_LIMIT             1024
#define SF_MAX_LIMIT              10

/*CDMA2000_CSFB_HO start*/
/*should be upper than the time in sfn required for L2 to process 
  the mac_reconfig_req message*/
#define GUARD_PERIOD_IN_SFN       5
#define MIN_SI_PERIODICITY         8

/*If sib8 periodicity is minimum i.e. 8 SFN, then from 0 to 1023, sib8 can come 128 times at max */
#define MAX_SIB_INSTANCES          SFN_UPPER_LIMIT/MIN_SI_PERIODICITY

/*CDMA2000_CSFB_HO stop*/
/* UL DL ARFCN DIFFERENCE */
#define UL_DL_ARFCN_DIFFRENCE 18000

/* LIPA start */
#define MAX_LOCAL_ERROR_IMPACTED_ITEMS     255
/* LIPA end */

/*PWS changes start*/
#define MSG_ID_NUMBITS                      16
#define SERIAL_NUMBER_NUMBITS               16
/*PWS changes stop*/
#define MSG_ID_OCTET_SIZE                   2
#define SERIAL_NUMBER_OCTET_SIZE            2
#define SECURITY_INFORMATION_OCTET_SIZE     50
#define RRC_MAX_THREADS 36
#ifdef ARICENT_SCTP_IPR
#define S1AP_SCTP_MAX_THREADS 3
#else
#define S1AP_SCTP_MAX_THREADS 1
#endif

#ifdef EN_DC_CUSTOM_ENABLED
#define MAX_MENB_COUNT 128
#define MAX_NODE_NUM 127
#define ADPT_MIN_EXT_MODULE_ID  0x0800
#define ADPT_L3S_MODULE_ID  (ADPT_MIN_EXT_MODULE_ID + 0)
#define ADPT_TRM_MODULE_ID  (ADPT_MIN_EXT_MODULE_ID + 1)
#define ADPT_CEC_MODULE_ID  (ADPT_MIN_EXT_MODULE_ID + 2)
#define ADPT_FHSCTP_MODULE_ID  (ADPT_MIN_EXT_MODULE_ID + 3)
#define ADPT_BHSCTP_MODULE_ID  (ADPT_MIN_EXT_MODULE_ID + 4)
#define ADPT_UEMR_L3_MODULE_ID  (ADPT_MIN_EXT_MODULE_ID + 5)
#define ADPT_UEMR_RRC_MODULE_ID  (ADPT_MIN_EXT_MODULE_ID + 6)
#define ADPT_HRM_MODULE_ID  (ADPT_MIN_EXT_MODULE_ID + 7)
#define ADPT_MAX_EXT_MODULE_ID  0x0807
#endif

/* Value for External Module Ids */
#define RRC_MIN_EXT_MODULE_ID   1
#define RRC_OAM_MODULE_ID   (RRC_MIN_EXT_MODULE_ID + 0)
#define RRC_RRM_MODULE_ID   (RRC_MIN_EXT_MODULE_ID + 1)
#ifndef OAM_IPR
#define RRC_MODULE_ID       (RRC_MIN_EXT_MODULE_ID + 2)
#endif
#define RRC_SON_MODULE_ID   (RRC_MIN_EXT_MODULE_ID + 3)
#define RRC_S1U_MODULE_ID   100
#define RRC_PDCP_MODULE_ID  (RRC_MIN_EXT_MODULE_ID + 4)
#define RRC_RLC_MODULE_ID   (RRC_MIN_EXT_MODULE_ID + 5)
#define RRC_MAC_MODULE_ID   (RRC_MIN_EXT_MODULE_ID + 6)
#define RRC_PHY_MODULE_ID   (RRC_MIN_EXT_MODULE_ID + 7)
#define RRC_MME_MODULE_ID   (RRC_MIN_EXT_MODULE_ID + 8) /*now used only for FT*/
#define RRC_X2AP_PEER_eNODEB_MODULE_ID (RRC_MIN_EXT_MODULE_ID + 9)
#define RRC_DU_MODULE_ID        (RRC_MIN_EXT_MODULE_ID + 10)
#define RRC_NGU_MODULE_ID       (RRC_MIN_EXT_MODULE_ID + 11)
#define RRC_XNAP_PEER_gNODEB_MODULE_ID (RRC_MIN_EXT_MODULE_ID + 12)
#define RRC_AMF_MODULE_ID      RRC_MIN_EXT_MODULE_ID + 13
#if !defined(NR_NSA_MODE_ENABLED)
#define RRC_MAX_EXT_MODULE_ID   RRC_AMF_MODULE_ID
#endif
#ifdef NR_NSA_MODE_ENABLED
#endif


#if  defined(NR_NSA_MODE_ENABLED)
#define RRC_MAX_EXT_MODULE_ID   RRC_AMF_MODULE_ID
#endif
#if defined (E2CU_MU_MIMO_CHANGES) || defined (E2_FRAMEWORK)
#define RRC_E2_MODULE_ID       (RRC_MIN_EXT_MODULE_ID + 13)
#define E2_CU_MODULE_ID       (RRC_MIN_EXT_MODULE_ID + 3)
#endif/*end of E2_FRAMEWORK*/
/* F1AP Changes - START */
/* F1AP Changes - END */

#ifdef MODE_PROFILER_DEFINED
#define RRC_WRONG_MODULE_ID   0xfe
#endif

/* Value for Internal Module Ids */
/* GQA-5247_Changes_S */
#define RRC_MIN_INT_MODULE_ID   0x10
#define RRC_OAMH_MODULE_ID    (RRC_MIN_INT_MODULE_ID + 0)
#define RRC_UECC_MODULE_ID    (RRC_MIN_INT_MODULE_ID + 1) /* Depricated in Rel4.0 */
#define RRC_CSC_MODULE_ID     (RRC_MIN_INT_MODULE_ID + 2)
#define RRC_LLIM_MODULE_ID    (RRC_MIN_INT_MODULE_ID + 3)
#define RRC_S1AP_MODULE_ID    (RRC_MIN_INT_MODULE_ID + 4)
#define RRC_X2AP_MODULE_ID    (RRC_MIN_INT_MODULE_ID + 5)
#define RRC_NGAP_MODULE_ID    (RRC_MIN_INT_MODULE_ID + 6)
#define RRC_XNAP_MODULE_ID    (RRC_MIN_INT_MODULE_ID + 7)
#define RRC_UECCMD_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 8)
#define RRC_UECC_1_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 9)
#define RRC_UECC_2_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 10)
#define RRC_UECC_3_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 11)
#define RRC_UECC_4_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 12)
#define RRC_UECC_5_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 13)
#define RRC_UECC_6_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 14)
#define RRC_UECC_7_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 15)
#define RRC_UECC_8_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 16)
#define RRC_UECC_9_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 17)
#define RRC_UECC_10_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 18)
#define RRC_UECC_11_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 19)
#define RRC_UECC_12_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 20)
#define RRC_UECC_13_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 21)
#define RRC_UECC_14_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 22)
#define RRC_UECC_15_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 23)
#define RRC_UECC_16_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 24)
#define RRC_UECC_17_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 25)
#define RRC_UECC_18_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 26)
#define RRC_UECC_19_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 27)
#define RRC_UECC_20_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 28)
#define RRC_UECC_21_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 29)
#define RRC_UECC_22_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 30)
#define RRC_UECC_23_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 31)
#define RRC_UECC_24_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 32)
#define RRC_UECC_25_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 33)
#define RRC_UECC_26_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 34)
#define RRC_UECC_27_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 35)
#define RRC_UECC_28_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 36)
#define RRC_UECC_29_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 37)
#define RRC_UECC_30_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 38)
#define RRC_UECC_31_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 39)
#define RRC_UECC_32_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 40)
#define RRC_UECC_MAX_MODULE_ID  RRC_UECC_32_MODULE_ID
#define RRC_S1U_1_MODULE_ID   (RRC_MIN_INT_MODULE_ID + 41)
#define RRC_S1U_2_MODULE_ID   (RRC_MIN_INT_MODULE_ID + 42)
#define RRC_S1U_3_MODULE_ID   (RRC_MIN_INT_MODULE_ID + 43)
#define RRC_S1U_4_MODULE_ID   (RRC_MIN_INT_MODULE_ID + 44)
#define RRC_S1U_5_MODULE_ID   (RRC_MIN_INT_MODULE_ID + 45)
#define RRC_S1U_6_MODULE_ID   (RRC_MIN_INT_MODULE_ID + 46)
#define RRC_S1U_7_MODULE_ID   (RRC_MIN_INT_MODULE_ID + 47)
#define RRC_S1U_8_MODULE_ID   (RRC_MIN_INT_MODULE_ID + 48)
#define RRC_PDCP_1_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 49)
#define RRC_PDCP_2_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 50)
#define RRC_PDCP_3_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 51)
#define RRC_PDCP_4_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 52)
#define RRC_PDCP_5_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 53)
#define RRC_PDCP_6_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 54)
#define RRC_PDCP_7_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 55)
#define RRC_PDCP_8_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 56)
#define GNB_LOGGER_MODULE_ID  (RRC_MIN_INT_MODULE_ID + 57)
#define RRC_XWAP_MODULE_ID     (RRC_MIN_INT_MODULE_ID + 58)
/* MULTI_PDCP CHANGES START */
#define RRC_F1AP_MODULE_ID      (RRC_MIN_INT_MODULE_ID + 59)
#define RRC_F1U_1_MODULE_ID    (RRC_MIN_INT_MODULE_ID + 60)
#define RRC_F1U_2_MODULE_ID    (RRC_MIN_INT_MODULE_ID + 61)
#define RRC_F1U_3_MODULE_ID    (RRC_MIN_INT_MODULE_ID + 62)
#define RRC_F1U_4_MODULE_ID    (RRC_MIN_INT_MODULE_ID + 63)
#define RRC_F1U_5_MODULE_ID    (RRC_MIN_INT_MODULE_ID + 64)
#define RRC_F1U_6_MODULE_ID    (RRC_MIN_INT_MODULE_ID + 65)
#define RRC_F1U_7_MODULE_ID    (RRC_MIN_INT_MODULE_ID + 66)
#define RRC_F1U_8_MODULE_ID    (RRC_MIN_INT_MODULE_ID + 67)
#define DU_F1AP_ADPT_MODULE_ID    (RRC_MIN_INT_MODULE_ID + 68)
/* MULTI_PDCP CHANGES END */
#define RRC_MAX_INT_MODULE_ID   DU_F1AP_ADPT_MODULE_ID
/* GQA-5247_Changes_E */
#ifdef RRC_UT_FRAMEWORK
#define RRC_UT_FRWK_MODULE_ID 90
#endif

/*Error Codes for RRC_PDCP*/
#define    RRC_PDCP_ERROR_CODE_BASE           0x0100
#define    RRC_PDCP_ERR_CONTEXT_NOT_INITIALIZED        RRC_PDCP_ERROR_CODE_BASE + 0
#define    RRC_PDCP_ERR_CONTEXT_ALREADY_INITIALIZED    RRC_PDCP_ERROR_CODE_BASE + 1
#define    RRC_PDCP_ERR_UE_CONTEXT_ALREADY_CREATED     RRC_PDCP_ERROR_CODE_BASE + 2
#define    RRC_PDCP_ERR_UE_CONTEXT_NOT_INITIALIZED     RRC_PDCP_ERROR_CODE_BASE + 3
#define    RRC_PDCP_ERR_ENTITY_ALREADY_CREATED         RRC_PDCP_ERROR_CODE_BASE + 4
#define    RRC_PDCP_ERR_ENTITY_WRONG_DIRECTION         RRC_PDCP_ERROR_CODE_BASE + 5
#define    RRC_PDCP_ERR_ENTITY_WRONG_TYPE              RRC_PDCP_ERROR_CODE_BASE + 6
#define    RRC_PDCP_ERR_ENTITY_NOT_FOUND               RRC_PDCP_ERROR_CODE_BASE + 7
#define    RRC_PDCP_ERR_ENTITY_SET_SN_SIZE             RRC_PDCP_ERROR_CODE_BASE + 8

#define    RRC_PDCP_ERR_ENTITY_SET_STATUS_REPORT_REQUIRED  RRC_PDCP_ERROR_CODE_BASE + 9

#define    RRC_PDCP_ERR_TLV_PARSING_INVALID_LENGTH     RRC_PDCP_ERROR_CODE_BASE + 10
#define    RRC_PDCP_ERR_TLV_PARSING_INVALID_UE_ID      RRC_PDCP_ERROR_CODE_BASE + 11

#define    RRC_PDCP_ERR_TLV_PARSING_INVALID_OPTIONAL_PARAMETERS_LENGTH RRC_PDCP_ERROR_CODE_BASE + 12

#define    RRC_PDCP_ERR_TLV_PARSING_INVALID_TAG_LENGTH RRC_PDCP_ERROR_CODE_BASE + 13
#define    RRC_PDCP_ERR_TLV_PARSING_INVALID_LC_ID      RRC_PDCP_ERROR_CODE_BASE + 14

#define    RRC_PDCP_ERR_TLV_PARSING_INVALID_TAG_PARAMETER_VALUE RRC_PDCP_ERROR_CODE_BASE + 15

#define    RRC_PDCP_ERR_TLV_PARSING_INVALID_CRNTI      RRC_PDCP_ERROR_CODE_BASE + 16
#define    RRC_PDCP_ERR_TLV_PARSING_INVALID_TAG_ID     RRC_PDCP_ERROR_CODE_BASE + 17
#define    RRC_PDCP_ERR_TLV_PARSING_INVALID_RNTI_RANGE RRC_PDCP_ERROR_CODE_BASE + 18
#define    RRC_PDCP_ERR_TLV_PARSING_INVALID_API_ID     RRC_PDCP_ERROR_CODE_BASE + 19


/*Error Codes for RRC_RLC*/
#define    RRC_RLC_ERROR_CODE_BASE           0x0200
#define    RRC_RLC_INVALID_UE_INDEX          RRC_RLC_ERROR_CODE_BASE + 0          
#define    RRC_RLC_UE_ID_EXISTS              RRC_RLC_ERROR_CODE_BASE + 1          
#define    RRC_RLC_UE_NOT_EXISTS             RRC_RLC_ERROR_CODE_BASE + 2          
#define    RRC_RLC_INTERNAL_ERROR            RRC_RLC_ERROR_CODE_BASE + 3          
#define    RRC_RLC_SYNTAX_ERROR              RRC_RLC_ERROR_CODE_BASE + 4          
#define    RRC_RLC_INVALID_LC_ID             RRC_RLC_ERROR_CODE_BASE + 5          
#define    RRC_RLC_ENTITY_EXISTS             RRC_RLC_ERROR_CODE_BASE + 6          
#define    RRC_RLC_ENTITY_NOT_EXISTS         RRC_RLC_ERROR_CODE_BASE + 7          
#define    RRC_RLC_UE_ENTITY_IN_USE          RRC_RLC_ERROR_CODE_BASE + 8          


/*Error Codes for RRC_RLC*/
#define    RRC_S1U_ERROR_CODE_BASE           0x0300
#define    RRC_S1U_SUCCESS                   RRC_S1U_ERROR_CODE_BASE + 0
#define    RRC_S1U_RESOURCES_NOT_AVAILABLE   RRC_S1U_ERROR_CODE_BASE + 1
#define    RRC_S1U_CTXT_NOT_FOUND            RRC_S1U_ERROR_CODE_BASE + 2
#define    RRC_S1U_DUPLICATE_PEER_TEID       RRC_S1U_ERROR_CODE_BASE + 3
#define    RRC_S1U_INV_SAP_CFG               RRC_S1U_ERROR_CODE_BASE + 4
#define    RRC_S1U_IPV6_ADDR_RECEIVED        RRC_S1U_ERROR_CODE_BASE + 5

/*Error Codes for RRC_UECC_LLIM (Per LC)*/
#define    RRC_UECC_LLIM_ERROR_CODE_BASE     0x0400
#define    RRC_UECC_LLIM_TIMER_EXPIRY        RRC_UECC_LLIM_ERROR_CODE_BASE + 0
#define    RRC_UECC_LLIM_ROLLBACK_FAILURE    RRC_UECC_LLIM_ERROR_CODE_BASE + 1    


/* Number of bits for MIB and SIBs IEs */
#define TAC_NBITS           16
#define CELL_ID_NBITS       36
#define CSG_ID_NBITS        27
#define ONE_FRAME_NBITS     6
#define FOUR_FRAME_NBITS    24
#define N_CELL_CFG_NBITS    2
#define SYN_SYS_TIME_NBITS  39
#define ASYN_SYS_TIME_NBITS 49
#define CSFB_REG_PARAM_1_XRTT_SID_NBITS 15
#define CSFB_REG_PARAM_1_XRTT_NID_NBITS 16
#define CSFB_REG_REG_PERIOD_NBITS       7
#define CSFB_REG_REG_ZONE_NBITS         12
#define CSFB_REG_TOTAL_ZONE_NBITS       3
#define CSFB_REG_ZONE_TIMER_NBITS       3
/*SPR_6293 Start*/
#define LONG_CODE_STATE_1_XRTT_NBITS    42
/*SPR_6293 Stop*/
#define NCC_PERMITTED_NBITS             8

/* Reestablishment_FIX start */
#define DRB_ID_VAL_TO_CAL_MAC_I         0xFF
#define RB_DIR_VAL_TO_CAL_MAC_I         0xFFFF         
/* Reestablishment_FIX stop */
#define CELL_ID_NBITS       36
#define CRNTI_NBITS         16

#define EMERGENCY_AREA_SIZE                 3
#define MAX_SIB_MESSAGE                     32
#define MAX_SIB_MESSAGE_1                   MAX_SIB_MESSAGE - 1
#define MAX_PLMN_ID_BYTES                   3
#define MAX_SI_MESSAGE                      12
#define WARNING_MSG_SEGMENT_OCTET_SIZE      9600
#define WARNING_TYPE_OCTET_SIZE             2
#define MME_GROUP_ID_OCTET_SIZE             2
#define MME_CODE_OCTET_SIZE                 1
#define E_UTRAN_TRACEID_OCTET_SIZE          1
#define DATA_CODING_SCHEME_OCTET_SIZE       1
#define WARNING_MSG_OCTET_SIZE              9600    
#define MAX_WARNING_MESSAGE                 3

/* EN_DC_CHANGES_START */
#define NR_ENB_ID_OCTET_SIZE                5
#define X2AP_NR_CELL_ID_BIT_STR_LEN         36
#define EN_GNB_ID_OCTET_SIZE                4
#define MAX_CELL_IN_EN_GNB                  16384
#define MAX_CELL_IN_ENB                     MAX_SERVED_CELLS
#define ASN_ERROR_PRINT(p_asn1_ctx)    rtxErrPrint(p_asn1_ctx)  
/* EN_DC_CHANGES_END */
/*XNAP changes start*/
#define NR_GNB_ID_OCTET_SIZE                5
#define MAX_NUM_SUPPORTED_XNAP_UEID         512
/*XNAP changes stop*/
#define MAX_NUM_TAI               MAX_NUM_CELLS
/*Cov 331905 331902 331901 331900 331906 331905 331904 Changes Start*/
#define HOME_ENB_ID_OCTET_SIZE          4
/*Cov 331905 331902 331901 331900 331906 331905 331904 Changes Stop*/
#define MAX_TAC_BYTES                   3
#define MAX_EUTRA_TAC_BYTES                   2
#define    X2AP_EUTRA_MODE_FDD   0x01
#define    X2AP_EUTRA_MODE_FDD   0x01
#define    X2AP_EUTRA_MODE_TDD   0x02
#define MAX_SERVED_CELLS 32 
#define MAX_ENB_MEASUREMENTS 4
#define MAX_ENB_POOLS 16
#define MAX_GNB_POOLS 16
#define MAX_PEER_ENB  64
/*SA_L3_MEM_FIX_S*/
/*5G-Challanges fix start*/
#define MAX_NUM_DU  8
/*5G-Challanges fix end*/
#define MAX_PEER_GNB  4
#define MAX_PEER_GNB_SUPPORTED                  4

/*SA_L3_MEM_FIX_E*/
#define MAX_X2AP_IP_ADDRESS_LENGTH               16
#define MAX_XNAP_IP_ADDRESS_LENGTH               16
/* IPV6 Start */
#define MAX_X2AP_IPV6_ADDRESS_LENGTH             40
/* IPV6 Stop */
#define MAX_XNAP_IPV6_ADDRESS_LENGTH             40
#define MAX_NUM_ENB_X2AP_EXT_TLAS       16
#define MAX_NUM_ENB_X2AP_GTP_TLAS       16
#define MACRO_ENB_ID_OCTET_SIZE         4
#define MAX_NUM_IP_ADDR                     3
/*Menb_WhiteList_Start*/
#define MAX_X2AP_MENB_NUMIPADDR                   64
/*Menb_WhiteList_Stop*/
#define MAX_NUM_BPLMN 6
#define MAX_AMF_GRP_BYTES 2
#define MAX_MME_GRP_BYTES 2
#define MAX_NEIGHBOURS 256
#define SCTP_SD_OCTET_SIZE          4
#define NUM_ANTENNA_PORT_BITMASK  0x01
#define GTP_TE_ID_BYTES 4
#ifndef OAM_IPR
/* CSR_00040799 Fix Start */
#define MAX_NUM_UE              MAX_NUM_SUPPORTED_UE_PER_UECC
#endif
/* #define NEW_MAX_NUM_UE  256 */
/* CSR_00040799 Fix End */
#ifdef KPI_STATS_SA
#define MAX_NUMBER_OF_KPI_COUNTERS 64
#define MAX_VALUE_OF_KPI_TIMER 3600
#endif
#define X2AP_ENB_CFG_RETRY_TIMER_VAL_DEFAULT    5000
#define X2AP_ENB_CFG_TIME_TO_WAIT_RETRY_COUNT_DEFAULT 3
#define X2AP_ENB_CFG_TIME_TO_WAIT_OFFSET_TIMER_VAL_DEFAULT 1000
#define X2AP_RESET_RETRY_COUNT_DEFAULT    3
#define X2AP_RESET_RETRY_TIMER_VAL_DEFAULT 3000
#define X2AP_CELl_ACTIVATION_RETRY_COUNT_DEFAULT    3
#define X2AP_CELl_ACTIVATION_TIMER_VAL_DEFAULT 7000
#define X2AP_MOBILITY_CHANGE_RETRY_COUNT_DEFAULT 3
#define X2AP_MOBILITY_CHANGE_RETRY_TIMER_VAL_DEFAULT 7000
#define X2AP_SUBFRAME_ALLOC_ONE_FRAME_NUMBITS 6
#define X2AP_SUBFRAME_ALLOC_FOUR_FRAME_NUMBITS 24
#define X2AP_SUBFRAME_ALLOC_ONE_FRAME_OCTET_SIZE 1
#define X2AP_SUBFRAME_ALLOC_FOUR_FRAME_OCTET_SIZE 3
#define MAX_NUM_MBSFN 8
#define X2AP_NUM_ANTENNA_INFO_PORT_PRESENT 0x01
#define X2AP_PRACH_CONFIG_INFO_PRESENT 0x02
#define X2AP_MBSFN_SUBFRAME_INFO_PRESENT 0x04
#define X2AP_CSG_ID_INFO_PRESENT 0x08
#define MAX_IP_ADDRESS_LENGTH           16
/* IPV6 Start */
#define MAX_IPV6_ADDRESS_LENGTH         40
/* IPV6 Stop */
#define RRC_X2APCOMMON_MODULE_ID 10
#define RRC_S1APCOMMON_MODULE_ID 11

/* CDMA2000_CSFB_HO start*/
#define MOBILITY_PARAMS_MAX_OCTETS          64
#define CDMA2000_1XRTT_CELL_ID_BITS         47
#define MAX_SECTOR_ID_BITS                  128
#define SIZE_OF_PILOT_LIST_PARAMS            256
#define MEID_NBITS                          56

/* PILOT LIST Start */
#define CDMA2000_PILOT_LIST_LENGTH                         0
#define CDMA2000_PILOT_LIST_LENGTH_WIDTH                   8
#define CDMA2000_PILOT_LIST_A21_ELMENT_IDENTIFIER          3
#define CDMA2000_PILOT_LIST_A21_ELMENT_IDENTIFIER_WIDTH    8
#define CDMA2000_PILOT_LIST_NUM_OF_PILOTS_WIDTH            8
#define CDMA_2000_PILOT_LIST_SYSTEM_TYPE_WIDTH             8 /*Ref: C.S0024-B_v2.0 section:13.1*/
#define CDMA_2000_PILOT_LIST_BAND_CLASS_WIDTH              5 /*Ref: C.S0024-B_v2.0 section:13.1*/
#define CDMA_2000_PILOT_LIST_CHANNEL_NUMBER_INFO_WIDTH    11 /*Ref: C.S0024-B_v2.0 section:13.1*/

/*
   (CDMA_2000_PILOT_LIST_SYSTEM_TYPE_WIDTH + CDMA_2000_PILOT_LIST_BAND_CLASS_WIDTH + 
   CDMA_2000_PILOT_LIST_CHANNEL_NUMBER_INFO_WIDTH)/ sizeof(UInt8) 
Ref: C.S0024-B_v2.0 section:13.1 
*/
#define CDMA_2000_PILOT_LIST_CHANNEL_RECORD_LENGTH         3
#define CDMA_2000_PILOT_LIST_CELL_ID_INFO_WIDTH            3
#define CDMA_2000_PILOT_LIST_CHANNEL_RECORD_RESERVED_BIT   5
#define CDMA_2000_PILOT_LIST_CHANNEL_RECORD_LENGTH_WIDTH   8
#define CDMA_2000_PILOT_LIST_REFERENCE_PILOT_WIDTH         1
#define CDMA_2000_PILOT_LIST_PILOT_PN_INFO_WIDTH               15
#define CDMA_2000_PILOT_LIST_PILOT_STRNGTH_WIDTH                6
#define CDMA_2000_PILOT_LIST_PILOT_ONE_WAY_DELAY_INCLUDED_WIDTH 1
#define CDMA_2000_PILOT_LIST_PILOT_STRENGTH_RESERVED_BIT_WIDTH  1
#define CDMA_2000_PILOT_LIST_PILOT_ONE_WAY_DELAY_WIDTH         16 
/* PILOT LIST END*/
#define MAX_SIZE_OCTET_BUFF                                128
#define CSFB_BITMASK_PRESENT_WIDTH                         1
#define CSFB_PARAM_1XRTT_MULTI_SIDS_NBITS                  1
#define CSFB_PARAM_1XRTT_MULTI_NIDS_NBITS                  1
/* Bug 12190 Fix Start */
#define CSFB_PARAM_1XRT_RECORD_TYPE_NBITS                  8
#define CSFB_PARAM_1XRTT_PACKET_ZONE_ID_NBITS              8
/* Bug 12190 Fix Stop */
#define CSFB_PARAM_1_XRTT_NID_NBITS                        15 
#define CSFB_PARAM_1XRTT_PZ_HYST_ENABLED_NBITS             1
#define CSFB_PARAM_1XRTT_PZ_HYST_INFO_INCL_NBITS           1
#define CSFB_PARAM_1XRTT_PZ_HYST_LIST_LEN_NBITS            1
#define CSFB_PARAM_1XRTT_PZ_HYST_ACT_TIMER_NBITS           8
#define CSFB_PARAM_1XRTT_PZ_HYST_TIMER_MUL_NBITS           3
#define CSFB_PARAM_1XRTT_PZ_HYST_TIMER_EXP_NBITS           5
#define CSFB_PARAM_1XRTT_P_REV_NBITS                       8
#define CSFB_PARAM_1XRTT_MIN_P_REV_NBITS                   8
#define CSFB_PARAM_1XRTT_NEG_SLOT_CYCLE_INDEX_SUP_NBITS    1
#define CSFB_PARAM_1XRTT_ENCRYPT_MODE_NBITS                2
#define CSFB_PARAM_1XRTT_ENC_SUPPORTED_NBITS               1
#define CSFB_PARAM_1XRTT_SIG_ENCRYPT_SUP_NBITS             8
#define CSFB_PARAM_1XRTT_MSG_INTEGRITY_SUP_NBITS           1
#define CSFB_PARAM_1XRTT_SIG_INTEGRITY_SUP_INCL_NBITS      1
#define CSFB_PARAM_1XRTT_SIG_INTEGRITY_SUP_NBITS           8
#define CSFB_PARAM_1XRTT_AUTH_NBITS                        2
#define CSFB_PARAM_1XRTT_MAX_NUM_ALT_SO_NBITS              3
#define CSFB_PARAM_1XRTT_USE_SYNC_ID_NBITS                 1
#define CSFB_PARAM_1XRTT_MS_INIT_POS_LOC_SUP_IND_NBITS     1
#define CSFB_PARAM_1XRTT_MOB_QOS_NBITS                     1
#define CSFB_PARAM_1XRTT_BAND_CLASS_INFO_REQ_NBITS         1
#define CSFB_PARAM_1XRTT_BAND_CLASS_NBITS                  5
#define CSFB_PARAM_1XRTT_BYPASS_REG_IND_NBITS              5
#define CSFB_PARAM_1XRTT_ALT_BAND_CLASS_NBITS              5
#define CSFB_PARAM_1XRTT_MAX_ADD_SERV_INSTANCE_NBITS       3
#define CSFB_PARAM_1XRTT_HOME_REG_NBITS                    1
#define CSFB_PARAM_1XRTT_FOR_SID_REG_NBITS                 1
#define CSFB_PARAM_1XRTT_FOR_NID_REG_NBITS                 1
#define CSFB_PARAM_1XRTT_POWER_UP_REG_NBITS                1
#define CSFB_PARAM_1XRTT_POWER_DOWN_REG_NBITS              1
#define CSFB_PARAM_1XRTT_PARAMETER_REG_NBITS               1
#define CSFB_PARAM_1XRTT_REG_PRD_NBITS                     7
#define CSFB_PARAM_1XRTT_REG_DIST_NBITS                   11
#define CSFB_PARAM_1XRTT_PREF_MSID_TYPE_NBITS              2
#define CSFB_PARAM_1XRTT_EXT_PREF_MSID_TYPE_NBITS          2
#define CSFB_PARAM_1XRTT_MEID_REQD_NBITS                   1
#define CSFB_PARAM_1XRTT_MCC_NBITS                        10
#define CSFB_PARAM_1XRTT_IMSI_11_12_NBITS                  7
#define CSFB_PARAM_1XRTT_IMSI_T_SUPPORTED_NBITS            1
#define CSFB_PARAM_1XRTT_RECONNECT_MSG_IND_NBITS           1
#define CSFB_PARAM_1XRTT_RER_MODE_SUPPORTED_NBITS          1
#define CSFB_PARAM_1XRTT_TKZ_MODE_SUPPORTED_NBITS          1
#define CSFB_PARAM_1XRTT_TKZ_ID_NBITS                      1
#define CSFB_PARAM_1XRTT_PILOT_REPORT_NBITS                1
#define CSFB_PARAM_1XRTT_SDB_SUPPORTED_NBITS               1
#define CSFB_PARAM_1XRTT_AUTO_FCSO_ALLOWED_NBITS           1
#define CSFB_PARAM_1XRTT_SDB_IN_RCNM_IND_NBITS             1
#define CSFB_PARAM_1XRT_FPC_FCH_INIT_SETPT_RC3_NBITS       8
#define CSFB_PARAM_1XRT_FPC_FCH_INIT_SETPT_RC4_NBITS       8
#define CSFB_PARAM_1XRT_FPC_FCH_INIT_SETPT_RC5_NBITS       8
/* Bug 12674 Fix Start */
#define CSFB_PARAM_1XRT_FPC_FCH_INIT_SETPT_RC11_NBITS      8
#define CSFB_PARAM_1XRT_FPC_FCH_INIT_SETPT_RC12_NBITS      8
/* Bug 12674 Fix Stop */
#define CSFB_PARAM_1XRT_T_ADD_NBITS                        6
#define CSFB_PARAM_1XRT_PILOT_INC_NBITS                    4
#define CSFB_PARAM_1XRT_LP_SEC_NBITS                       8
/* Bug 12190 Fix Start */
#define CSFB_PARAM_1XRT_LTM_OFF_NBITS                      6
/* Bug 12190 Fix Stop */
/* Bug 12674 Fix Start */
#define CSFB_PARAM_1XRT_LTM_OFF_VALUE                      18
/* Bug 12674 Fix Stop */
#define CSFB_PARAM_1XRT_DAYLT_NBITS                        1
#define CSFB_PARAM_1XRT_GCSNAL2ACKTIMER_NBITS              8
#define CSFB_PARAM_1XRT_GCSNASEQUENCECONTEXTTIMER_NBITS    8
#define HO_EUTRA_PREP_REQ_NBITS 32
/* Bug 12190 Fix Start */
#define CSFB_PARAM_1XRT_RAND_NBITS                         32
/* Bug 12190 Fix Stop */
/* CDMA2000_CSFB_HO stop*/
/*SPR_19166_START*/
#define MAX_CELL_IDENTITY_NUMBYTES 4
/*SPR_19166_END*/
/*sctp parameters start*/
#define RRC_SCTP_DEFAULT_RTO_INITIAL 3000
#define RRC_SCTP_DEFAULT_RTO_MAX 6000
#define RRC_SCTP_DEFAULT_RTO_MIN 1000
#define RRC_SCTP_DEFAULT_ASSOC_MAX_RTX 10
#define RRC_SCTP_DEFAULT_VAL_COOKIE_LIFE 60000
#define RRC_SCTP_DEFAULT_PATH_MAX_RTX 5
#define RRC_SCTP_DEFAULT_MAX_INIT_RTX 8
#define RRC_SCTP_DEFAULT_INIT_TIMEOUT 0
/*sctp parameters stop*/
/*sampling period changes */
#define RRC_CONVERT_TO_MILLISEC 1000
#define RRC_CONVERT_KPI_TO_MILLISEC 100
#define BITS_RESERVED_FOR_UE_INDEX    0x0E
//#define BITS_RESERVED_FOR_UECC_INSTANCE    0x05
///* Multi UECC Changes Start */
//#define BITS_RESERVED_FOR_UE_INDEX        (gnb_module_id_t) ((sizeof(ue_index_t)*8) - BITS_RESERVED_FOR_UECC_INSTANCE)
///* Multi UECC Changes End */
/******************************************************************************
 *   Interface types
 ******************************************************************************/

#pragma pack(push, 1)

/******************************************************************************
 *   These types are shared CSC-LLIM with PHY and RRM
 ******************************************************************************/
typedef struct _rrc_phy_phich_configuration_t
{
    UInt8  phich_resource;     /*^ M, 0, H, 0, 3 ^*/ /* phich_resource_et */
    UInt8  phich_duration;     /*^ M, 0, H, 0, 1 ^*/ /* phich_duration_et */
} rrc_phy_phich_configuration_t;

typedef struct _rrc_phy_pucch_configuration_t
{
    UInt8  delta_pucch_shift;      /*^ M, 0, B, 1, 3 ^*/ /* pucch_delta_shift_et */
    UInt8  nrb_cqi;                /*^ M, 0, H, 0, 98 ^*/
    UInt8  ncs_an;                 /*^ M, 0, H, 0, 7 ^*/
    UInt16 n1pucch_an;             /*^ M, 0, H, 0, 2047 ^*/
} rrc_phy_pucch_configuration_t;

typedef struct{
    UInt8      group_hopping_enabled;  /*^ M, 0, H, 0, 1 ^*/     /* rrc_bool_et */
    UInt8      group_assign_pusch;     /*^ M, 0, H, 1, 29 ^*/
    UInt8      seq_hopping_enabled;    /*^ M, 0, H, 0, 1 ^*/     /* rrc_bool_et */
    UInt8      cyclic_shift;           /*^ M, 0, H, 1, 7 ^*/
}ul_ref_signals_pusch_t;

typedef struct _rrc_phy_pusch_configuration_t
{
    UInt8  pusch_hopping_offset; /*^ M, 0, H, 0, 98 ^*/
    UInt8  num_of_sub_bands;       /*^ M, 0, B, 1, 4 ^*/
    UInt8  pusch_hopping_mode;
    /*^ M, 0, H, 0, 1 ^*/ /* pusch_hopping_mode_et */
    ul_ref_signals_pusch_t  ul_ref_signal;
} rrc_phy_pusch_configuration_t;

typedef struct _rrc_phy_prach_configuration_t
{
    UInt8  prach_config_sequence;  /*^ M, 0, H, 0, 63 ^*/
    UInt16 root_seq_index;         /*^ M, 0, H, 0, 837 ^*/
    UInt8  prach_freq_offset;      /*^ M, 0, H, 0, 104 ^*/
    UInt8  zero_cor_zone_config;   /*^ M, 0, H, 0, 15 ^*/
    UInt8  high_speed_flag;        /*^ M, 0, H, 0, 1 ^*/ /* high_speed_flag_et */
} rrc_phy_prach_configuration_t;

typedef struct _rrc_phy_sync_signals_t
{
    SInt8  prim_syn_signal_power;  /*^ M, 0, B, -6, 4 ^*/
    SInt8  sec_syn_signal_power;   /*^ M, 0, B, -6, 4 ^*/
    UInt8  sec_syn_signal_m_seq1;  /*^ M, 0, H, 0, 30 ^*/
    UInt8  sec_syn_signal_m_seq2;  /*^ M, 0, H, 0, 30 ^*/
} rrc_phy_sync_signals_t;

typedef struct _rrc_phy_reference_signal_t
{
    SInt8  ref_signal_power;       /*^ M, 0, B, -60, 50 ^*/
    ul_ref_signals_pusch_t    ul_ref_signals_pusch;  /*^ M, 0, N, 0, 0 ^*/
} rrc_phy_reference_signal_t;


typedef struct
{
    SInt8        ref_signal_power;       /*^ M, 0, B, -60, 50 ^*/
    UInt8        pb;                     /*^ M, 0, H, 0, 3 ^*/   /* rrm_pb_et */
}pdsch_config_common_t;

#define RRC_INVALID_DC_BEARER_TYPE   2
typedef enum
{
    OPERATING_MODE_ENB_ONLY = 0,
    OPERATING_MODE_SENB_ONLY,
    OPERATING_MODE_BOTH_ENB_SENB
} rrc_enb_operating_mode_et;


typedef enum
{
    EN_DC_BEARER_TYPE_SCG,      /* SN Terminated SCG Bearer */ 
    EN_DC_BEARER_TYPE_MCG_SPLIT,/* MN Terminated SPLIT Bearer */
    EN_DC_BEARER_TYPE_SCG_SPLIT,/* SN Terminated SPLIT Bearer */
    EN_DC_BEARER_TYPE_MCG,      /* SN Terminated MCG Bearer */
    EN_DC_BEARER_TYPE_INVALID
}rrc_en_dc_bearer_type_et;

typedef enum
{
    RLC_AM_MODE ,
    RLC_UM_MODE_BIDIRECTIONAL,
    RLC_UM_MODE_UNIDIRECTIONAL_UL,
    RLC_UM_MODE_UNIDIRECTIONAL_DL
}rrm_rlc_mode_et;

typedef enum
{
    RRC_NO_DATA,
    RRC_SHARED,
    RRC_ONLY
}rrc_ul_config_et;

typedef enum
{
    RRC_PRESENT,
    RRC_NOT_PRESENT
}rrc_resource_presence_et;

/* PRS + */
typedef struct _rrc_phy_prs_config_t
{
    UInt8        prs_bandwidth;      /*^ M, 0, B, 6, 100 ^*/
    UInt8        prs_cyclic_prefix_type;    /*^ M, 0, H, 0, 1 ^*/
}rrc_phy_prs_config_t;
/* PRS - */

typedef struct _rrc_phy_pdsch_configuration_t
{
    pdsch_config_common_t pdsch_config; /*^ M, 0, N, 0, 0 ^*/
}rrc_phy_pdsch_configuration_t;

#define SOUNDING_RS_UL_CONFIG_COMMON_SETUP_SRS_MAX_UP_PTS_PRESENCE_FLAG     0x01

typedef struct
{
    UInt16       presence_bitmask;          /*^ BITMASK ^*/
    UInt8        srs_bw_config;
    /*^ M, 0, H, 1, 7 ^*/    /* rrm_srs_bw_config_et */

    UInt8        srs_subframe_config;
    /*^ M, 0, H, 1, 15 ^*/   /* rrm_srs_subframe_config_et */

    UInt8        ack_nack_srs_simul_trans;
    /*^ M, 0, H, 0, 1 ^*/    /* rrc_bool_et */

    UInt8        srs_max_up_pts;
    /*^ O, SOUNDING_RS_UL_CONFIG_COMMON_SETUP_SRS_MAX_UP_PTS_PRESENCE_FLAG,H,0,0 ^*/
    /* rrm_srs_max_up_pts_et */ /*OM. O since 331.860*/
}sounding_rs_ul_config_common_setup_t;


#define SOUNDING_RS_UL_CONFIG_COMMON_SETUP_PRESENCE_FLAG      0x01

typedef struct
{
    UInt16                                  presence_bitmask;       /*^ BITMASK ^*/
    sounding_rs_ul_config_common_setup_t setup;
    /*^ O, SOUNDING_RS_UL_CONFIG_COMMON_SETUP_PRESENCE_FLAG, H, 0, 0 ^*/
}sounding_rs_ul_config_common_t;


/** TDD Changes Start **/



typedef struct _rrc_phy_tdd_config_t
{
    UInt16      sub_frame_assignment;
    /*^ M, 0, H, 0, 6 ^*/  /* rrm_sub_frame_assignment_et */
    UInt16      special_sub_frame_pattern;
    /*^ M, 0, H, 0 , 8 ^*/  /* rrm_special_sub_frame_pattern_et */
} rrc_phy_tdd_config_t;

/** TDD Changes Stop **/
/* SPR-18445 start */
#define RRC_PHYS_CELL_PARAMS_DL_EARFCN_MAX_COUNT   25
typedef struct _rrc_phys_dl_earfcn_t
{
    UInt16                 count;  /*^ M, 0, H, 0, RRC_PHYS_CELL_PARAMS_DL_EARFCN_MAX_COUNT ^*/    
    /* SPR-18445 stop */
    UInt32                 earfcnDl[RRC_PHYS_CELL_PARAMS_DL_EARFCN_MAX_COUNT];/*^ M, 0, OCTET_STRING, VARIABLE ^*/
}rrc_phys_dl_earfcn_t;           


typedef struct _rrc_config_phy_cell_parameters_t
{

    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_TDD_CONFIG_PRESENT 0x01
    /* PRS + */
#define RRC_PHY_PRS_CONFIG_INFO_PRESENT 0x02
    /* PRS - */

#define RRC_PHY_DL_EARFCN_LIST_PRESENT 0x04

    UInt8  duplexing_mode;
    /* HD-FDD start */
    /*^ M, 0, H, 0, 2 ^*/                       /* duplexing_mode_et */
    /* HD-FDD stop */
    UInt8                            freq_band_indicator;      /*^ M, 0, B, 1, MAX_FREQ_BAND_INDICATOR ^*/
    UInt16 ul_earfcn;
    UInt32 dl_earfcn;
    UInt8  num_of_antennas;                    /*^ M, 0, H, 1, 4 ^*/
    UInt8  ul_tx_bandwidth;
    /*^ M,0, H, 0, 5 ^*/  /* ul_tx_bandwidth_et */

    UInt8  dl_tx_bandwidth;
    /*^ M, 0, H, 0, 5 ^*/  /* dl_tx_bandwidth_et */

    UInt8  subcarrier_spacing;
    /*^ M, 0, H, 0, 1 ^*/                       /* subcarrier_spacing_et */

    UInt8  ul_cyclic_prefix;
    /*^ M, 0, H, 0, 1 ^*/                       /* cyclic_prefix_et */

    UInt8  dl_cyclic_prefix;
    /*^ M, 0, H, 0, 1 ^*/                       /* cyclic_prefix_et */

    sounding_rs_ul_config_common_t    srs_bandwidth_configuration;
    /*^ M, 0, H, 0, 0 ^*/

    rrc_phys_cell_id_t  phys_cell_id;       /*^ M, 0, H, 0, 1007 ^*/


    /* CLPC Start */

    UInt16 pcfich_power_offset;               /*^ M, 0, H, 0, 10000 ^*/

    UInt16 phich_power_offset;                /*^ M, 0, H, 0, 10000 ^*/

    /* CLPC Stop */

    /* SPR 3802 Start */
    UInt8    max_rs_epre;
    /*^ M, 0, H, 0, 160 ^*/ 
    /* SPR 3802 Stop */

    /** TDD Changes Start **/

    rrc_phy_tdd_config_t tdd_config;
    /*^ O, RRC_PHY_TDD_CONFIG_PRESENT ^*/

    /* TDD Changes Stop **/
    /* PRS + */
    rrc_phy_prs_config_t            prs_config;
    /*^ O, RRC_PHY_PRS_CONFIG_INFO_PRESENT, N, 0, 0 ^*/
    /* PRS - */

    rrc_phys_dl_earfcn_t           dl_earfcn_list;
    /*^ O, RRC_PHY_DL_EARFCN_LIST_PRESENT, N, 0, 0 ^*/

} rrc_config_phy_cell_parameters_t;

/* SPR-18445 start */
#define RRC_PHY_CELL_PARAMS_DL_EARFCN_MAX_COUNT   25
typedef struct _rrc_dl_earfcn_t
{
    UInt16                 count;  /*^ M, 0, H, 0, RRC_PHY_CELL_PARAMS_DL_EARFCN_MAX_COUNT ^*/  
    /* SPR-18445 stop */
    UInt32                 earfcnDl[RRC_PHY_CELL_PARAMS_DL_EARFCN_MAX_COUNT];/*^ M, 0, OCTET_STRING, VARIABLE ^*/
}rrc_dl_earfcn_t;


typedef struct _rrc_phy_cell_parameters_t
{
    UInt32 dl_earfcn;
    UInt8  num_of_antennas;                    /*^ M, 0, B, 1, 4 ^*/
    UInt8  subcarrier_spacing;
    /*^ M, 0, H, 0, 1 ^*/                       /* subcarrier_spacing_et */
    UInt8  dl_cyclic_prefix;
    /*^ M, 0, H, 0, 1 ^*/                       /* cyclic_prefix_et */
    UInt8  rb_size;
    /*^ M, 0, H, 0, 1 ^*/                       /* rb_size_et */

    rrc_phys_cell_id_t  phys_cell_id;       /*^ M, 0, H, 0, 1007 ^*/

    /* SPR 3802 Start */
    UInt8    max_rs_epre;
    /*^ M, 0, H, 0, 160 ^*/ 
    /* SPR 3802 Stop */
    rrc_dl_earfcn_t dl_earfcn_list;
} rrc_phy_cell_parameters_t;

typedef struct _rrc_rcfg_phy_cell_parameters_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_RRM_RECONFIG_PHY_CELL_PARAMS_DL_EARFCN_PRESENT 0x01
#define RRC_RRM_RECONFIG_PHY_CELL_PARAMS_NUM_OF_ANTENNAS   0x02
#define RRC_RRM_RECONFIG_PHY_CELL_PARAMS_DL_CYCLIC_PREFIX  0x04
#define RRC_RRM_RECONFIG_PHY_CELL_PARAMS_RB_SIZE           0x08
#define RRC_RRM_RECONFIG_PHY_CELL_ID                       0x10
    /* CLPC Start */
#define RRC_RRM_PRIMARY_SYNC_SIGNAL_EPRE_EPRERS            0x20
#define RRC_RRM_SECONDARY_SYNC_SIGNAL_EPRE_EPRERS          0x40
    /* CLPC Stop */
    /* SPR 3802 Start */
#define RRC_RRM_RECONFIG_PHY_CELL_MAX_RS_EPRE_PRESENT      0x80
    /* SPR 3802 Stop */

    UInt32 dl_earfcn;                          
    /*^ O, RRC_RRM_RECONFIG_PHY_CELL_PARAMS_DL_EARFCN_PRESENT ^*/
    UInt8  num_of_antennas;                    
    /*^ O, RRC_RRM_RECONFIG_PHY_CELL_PARAMS_NUM_OF_ANTENNAS, B, 1, 4 ^*/
    UInt8  dl_cyclic_prefix;
    /*^ O, RRC_RRM_RECONFIG_PHY_CELL_PARAMS_DL_CYCLIC_PREFIX, H, 0, 1 ^*/   /* cyclic_prefix_et */
    UInt8  rb_size;
    /*^ O, RRC_RRM_RECONFIG_PHY_CELL_PARAMS_RB_SIZE, H, 0, 1 ^*/    /* rb_size_et */
    rrc_phys_cell_id_t  phys_cell_id; /*^ O, RRC_RRM_RECONFIG_PHY_CELL_ID ^*/

    /* CLCP Start */
    UInt16 pri_sync_sig_epre_eprers;
    /*^ O, RRC_RRM_PRIMARY_SYNC_SIGNAL_EPRE_EPRERS, H, 0, 10000 ^*/

    UInt16 sec_sync_sig_epre_eprers;
    /*^ O, RRC_RRM_SECONDARY_SYNC_SIGNAL_EPRE_EPRERS, H, 0, 10000 ^*/

    /* CLPC Stop */
    /* SPR 3802 Start */
    UInt8    max_rs_epre;
    /*^ O, RRC_RRM_RECONFIG_PHY_CELL_MAX_RS_EPRE_PRESENT, H, 0, 160 ^*/ 
    /* SPR 3802 Stop */
} rrc_recfg_phy_cell_parameters_t;

/******************************************************************************
 *   End of these types are shared CSC-LLIM with PHY and RRM
 ******************************************************************************/

/******************************************************************************
 *   These types are shared CSC-LLIM with MAC
 ******************************************************************************/
#define RRC_MAX_MIB_LENGTH      10
#define RRC_MAX_SIBTYPE1_LENGTH 1024
#define RRC_MAX_SI_LENGTH       277

#define RRC_MAX_SI_MSGS         12
#define RRC_MIB_MSGS            256
#define RRC_MAX_SI_MSG_PARAMS   16
#define MAX_SI_SEGMENTS         64
#define MAX_SIB8_INSTANCES      16
/* SPR 13574 Fix Start */
#define MAX_NUM_CMAS_WARNING    3
/* SPR 13574 Fix Stop */
#define MAX_SI_START_OFFSET     8
#define RRC_INVALID_SI_INDEX    9
typedef enum {
    RRC_SI_SYNC_SYS_TIME,
    RRC_SI_ASYNC_SYS_TIME,
    RRC_SI_LONG_CODE_STATE_1_XRTT
} rrc_mac_si_msg_param_type_et;

typedef struct _rrc_mac_si_msg_param_t
{
    UInt8  id;     /*^ M, 0, H, 0, 2 ^*/ /* rrc_mac_si_msg_param_type_et */
    UInt32 offset; /* in bits */
    UInt32 length; /* in bits */
} rrc_mac_si_msg_param_t;

#ifndef OAM_IPR
/*CDMA2000_CSFB_HO start*/
typedef enum
{
    NO_SIB8,
    SIB8_NEW_BUFFER,
    SIB8_FLUSH_OLD_BUFFER_APPLY_NEW_BUFFER,
    SIB8_NO_CHANGE
}sched_reqd_for_sib8_et;
#endif

typedef struct _rrc_mac_sched_reqd_for_sib8_info_t
{
    UInt8  sched_reqd_for_sib8;        /*^ M, 0, H, 0, 3 ^*/  /* sched_reqd_for_sib8_et */
} rrc_mac_sched_reqd_for_sib8_info_t;

typedef struct
{
    rrc_timestamp_U64_t   ts_sec;    /*^ M, 0, H, 0, 9223372036854775807 ^*/
    rrc_timestamp_UInt32_t   ts_nsec;   /*^ M, 0, H, 0, 4294967295 ^*/
}rrc_timestamp_t;

/*CDMA2000_CSFB_HO stop*/

typedef struct _rrc_mac_si_segment_data_t
{
    rrc_counter_t           si_msg_buf_length;
    UInt8                      si_msg_buf[RRC_MAX_SI_LENGTH];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/
}rrc_mac_si_segment_data_t;

typedef struct _rrc_num_si_repetitions
{
    UInt16         num_of_repetitions; /*^ M, 0, H, 1, 4095 ^*/
}rrc_num_si_repetitions;

typedef struct _rrc_num_si_transmissions_t
{
    UInt8          num_of_transmissions; /*^ M, 0, B, 1, 8 ^*/
}rrc_num_si_transmissions_t;

typedef struct _rrc_mac_si_start_offset_info_t
{
    UInt8          si_start_offset[MAX_SI_START_OFFSET];
    /*^ M, 0, OCTET_STRING, FIXED, H, 0, 39 ^*/
}rrc_mac_si_start_offset_info_t;


#define RRC_NUM_SI_REPETITIONS_PRESENT 0x01
#define RRC_NUM_SI_TRANSMISSIONS_PRESENT 0x02
#define RRC_NUM_SI_START_OFFSET_PRESENT 0x04
/*CDMA2000_CSFB_HO start*/
#define RRC_SCHED_REQD_FOR_SIB8_PRESENT 0x08
/*CDMA2000_CSFB_HO stop*/

typedef struct _rrc_mac_si_msg_info_t
{
    rrc_bitmask_t                   optional_elems_present;
    /*^ M, 0, BITMASK, NOT_PRESENT_IN_MESSAGE ^*/

    UInt8      si_index;   /*^ M, 0, H, 0, 11 ^*/  
    UInt8          periodicity;
    /*^ M, 0, B, 1, 7 ^*/       /* Bug in MAC API document - we must update RRC */

    rrc_sfn_t   starting_sfn;   /*^ M, 0, H, 0, 1023 ^*/
    rrc_sf_t    starting_sf;    /*^ M, 0, H, 0, 9 ^*/

    UInt8                  num_of_segment ;  /*^ M, 0, B, 1, 64 ^*/

    rrc_num_si_repetitions   num_si_repetitions;
    /*^ TLV, RRC_NUM_SI_REPETITIONS, RRC_NUM_SI_REPETITIONS_PRESENT ^*/

    rrc_num_si_transmissions_t num_si_transmissions;
    /*^ TLV, RRC_NUM_SI_TRANSMISSIONS, RRC_NUM_SI_TRANSMISSIONS_PRESENT ^*/

    rrc_mac_si_start_offset_info_t   si_start_offset_info;
    /*^ TLV, RRC_MAC_SI_START_OFFSET, RRC_NUM_SI_START_OFFSET_PRESENT ^*/
    rrc_counter_t       segment_counter ;  
    /*^ M, 0, TLV_SEQUENCE_COUNTER, NOT_PRESENT_IN_MESSAGE ^*/
    rrc_mac_si_segment_data_t         si_segment_data[MAX_SI_SEGMENTS];
    /*^ TLV, SEQUENCE, RRC_MAC_SI_MSG_SEGMENT_REQ ^*/

    rrc_counter_t           si_msg_param_counter;
    /*^ M, 0, TLV_SEQUENCE_COUNTER, NOT_PRESENT_IN_MESSAGE ^*/

    rrc_mac_si_msg_param_t  si_msg_param[RRC_MAX_SI_MSG_PARAMS];
    /*^ TLV, SEQUENCE, RRC_MAC_SI_MSG_INFO_PARAM ^*/

    /*CDMA2000_CSFB_HO start*/
    rrc_mac_sched_reqd_for_sib8_info_t rrc_mac_sched_reqd_for_sib8;
    /*^ TLV, RRC_SCHED_REQD_FOR_SIB8, RRC_SCHED_REQD_FOR_SIB8_PRESENT ^*/
    /*CDMA2000_CSFB_HO stop*/

} rrc_mac_si_msg_info_t;

typedef struct _rrc_mac_si_msg_req_t
{
    UInt8  si_window_size;         /*^ M, 0, B, 1, 40 ^*/
    UInt8  num_si_message;         /*^ M, 0, H, 0, 74 ^*/

    rrc_counter_t           si_msg_info_counter;
    /*^ M, 0, TLV_SEQUENCE_COUNTER, NOT_PRESENT_IN_MESSAGE ^*/

    rrc_mac_si_msg_info_t   si_msg_info[RRC_MAX_SI_MSGS];
    /*^ TLV, SEQUENCE, RRC_MAC_SI_MSG_REQ ^*/

} rrc_mac_si_msg_req_t;

typedef struct _rrc_mac_sibtype1_msg_req_t
{
    UInt8      si_mapping_changed; /*^ M, 0, H, 0, 1 ^*/   
    rrc_sfn_t   sfn;    /*^ M, 0, H, 0, 1023 ^*/

    rrc_counter_t   sibtype1_msg_buf_counter;
    /*^ M, 0, BUFFER_SIZE, NOT_PRESENT_IN_MESSAGE ^*/

    UInt8              sibtype1_msg_buf[RRC_MAX_SIBTYPE1_LENGTH];
    /*^ M, 0, OCTET_STRING, LIMITED_TILL_THE_END ^*/

} rrc_mac_sibtype1_msg_req_t;

typedef struct _rrc_mac_mib_msg_req_t
{
    rrc_sfn_t   sfn;    /*^ M, 0, H, 0, 1023 ^*/

    rrc_counter_t   mib_msg_buf_counter;
    /*^ M, 0, BUFFER_SIZE, NOT_PRESENT_IN_MESSAGE ^*/

    UInt8              mib_msg_buf[RRC_MAX_MIB_LENGTH];
    /*^ M, 0, OCTET_STRING, LIMITED_TILL_THE_END ^*/

} rrc_mac_mib_msg_req_t;


typedef struct _rrc_mac_mod_period_info_t
{
    UInt32         mod_period; /*^ M, 0, B, 64, 4096 ^*/
}rrc_mac_mod_period_info_t;

typedef struct _rrc_mac_sfn_gap_info_t
{
    UInt8         sfn_gap; /*^ M, 0, B, 1, 32 ^*/
}rrc_mac_sfn_gap_info_t;


typedef struct
{
    UInt8            count;
    /*^ M, 0, N, 0, 31 ^*/     /* MAX_SIB_MESSAGE_1  */

    UInt8            sib_type[MAX_SIB_MESSAGE_1];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/  /* rrm_sib_type_et */

}sib_mapping_info_t;


typedef struct
{
    sib_mapping_info_t   sib_mapping_info; /*^ M, 0, N, 0, 0 ^*/
    UInt8                   si_periodicity;
    /*^ M, 0, H, 0, 6 ^*/ /* rrm_si_periodicity_et */

}scheduling_info_t;


typedef struct
{
    /* SPR_17664_start*/
    UInt8                count;              /*^ M, 0, B, 1, MAX_SI_MESSAGE ^*/

    /* SPR_17664_end*/
    scheduling_info_t  scheduling_info[MAX_SI_MESSAGE];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/

}scheduling_info_list_t;


typedef struct
{
    UInt8  message_identifier[MSG_ID_OCTET_SIZE];  
    /*^ M, 0, OCTET_STRING, FIXED ^*/

    UInt8  serial_number[SERIAL_NUMBER_OCTET_SIZE]; 
    /*^ M, 0, OCTET_STRING, FIXED ^*/
}rrc_warning_info_t;


typedef struct
{
    /* SPR-18445 start */
    UInt8                  count;              /*^ M, 0, B, 1, MAX_WARNING_MESSAGE ^*/
    /* SPR-18445 stop */
    rrc_warning_info_t  warning_info[MAX_WARNING_MESSAGE];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/
}rrc_warning_info_list_t;


typedef struct
{
    UInt8  message_identifier[MSG_ID_OCTET_SIZE];  
    /*^ M, 0, OCTET_STRING, FIXED ^*/

    UInt8  serial_number[SERIAL_NUMBER_OCTET_SIZE]; 
    /*^ M, 0, OCTET_STRING, FIXED ^*/

    UInt8  num_of_segments;
    /*^ M, 0, B, 1, 64 ^*/

    UInt16 num_of_repetitions; 
    /*^ M, 0, B, 1, 4095 ^*/

} cmas_scheduling_info_t;

typedef struct
{   /* SPR 13574 Fix Start */              
    UInt8                     cmas_warning_count; /*^ M, 0, B, 1, MAX_NUM_CMAS_WARNING ^*/ 

    /* SPR 13574 Fix Stop */ 

    cmas_scheduling_info_t cmas_scheduling_info[MAX_NUM_CMAS_WARNING];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/

} cmas_scheduling_info_list_t;

typedef struct
{
    rrc_bitmask_t    bitmask;        /*^ BITMASK ^*/

#define RRC_RRM_ETWS_SCHEDULING_NUM_OF_SEGMENTS_PRESENT 0x01

    UInt8  message_identifier[MSG_ID_OCTET_SIZE];  
    /*^ M, 0, OCTET_STRING, FIXED ^*/

    UInt8  serial_number[SERIAL_NUMBER_OCTET_SIZE]; 
    /*^ M, 0, OCTET_STRING, FIXED ^*/

    UInt8  num_of_segments;
    /*^ O, RRC_RRM_ETWS_SCHEDULING_NUM_OF_SEGMENTS_PRESENT, B, 1, 64 ^*/

} etws_scheduling_info_t;


/******************************************************************************
 *   End of these types are shared CSC-LLIM with MAC
 ******************************************************************************/

/******************************************************************************
 *   These types are shared CSC-LLIM with MAC and RRM
 ******************************************************************************/
/* PRS +*/
typedef enum
{
    RRC_PRS_RB_N6,
    RRC_PRS_RB_N15,
    RRC_PRS_RB_N25,
    RRC_PRS_RB_N50,
    RRC_PRS_RB_N75,
    RRC_PRS_RB_N100
}rrc_prs_bandwidth_et;

typedef enum
{
    RRC_PRS_N_SF_1,
    RRC_PRS_N_SF_2,
    RRC_PRS_N_SF_4,
    RRC_PRS_N_SF_6
}rrc_prs_subframes_et;

typedef enum
{
    RRC_PRS_N2,
    RRC_PRS_N4,
    RRC_PRS_N8,
    RRC_PRS_N16
}rrc_prs_muting_bits_et;

/* PRS -*/
typedef enum
{
    MAC_RA_RESP_WIN_SIZE_SF2,
    MAC_RA_RESP_WIN_SIZE_SF3,
    MAC_RA_RESP_WIN_SIZE_SF4,
    MAC_RA_RESP_WIN_SIZE_SF5,
    MAC_RA_RESP_WIN_SIZE_SF6,
    MAC_RA_RESP_WIN_SIZE_SF7,
    MAC_RA_RESP_WIN_SIZE_SF8,
    MAC_RA_RESP_WIN_SIZE_SF10
} mac_ra_resp_win_size_et;

typedef enum
{
    MAC_CONT_RES_TIMER_SF8,
    MAC_CONT_RES_TIMER_SF16,
    MAC_CONT_RES_TIMER_SF24,
    MAC_CONT_RES_TIMER_SF32,
    MAC_CONT_RES_TIMER_SF40,
    MAC_CONT_RES_TIMER_SF48,
    MAC_CONT_RES_TIMER_SF56,
    MAC_CONT_RES_TIMER_SF64
} mac_cont_resol_timer_et;

typedef struct _rrc_mac_enable_frequency_selective_scheduling_t
{
    UInt8      ul_freq_selective_enable;    /*^ M, 0, H, 0, 1 ^*/
    UInt8      dl_freq_selective_enable;    /*^ M, 0, H, 0, 1 ^*/
}rrc_mac_enable_frequency_selective_scheduling_t;


/* CLPC Start */
typedef struct _rrc_mac_downlink_power_control_common_t
{
    UInt16 pcfichPowerOffset; /*^ M, 0, H, 0, 10000 ^*/ 

    UInt16 phichPowerOffset;  /*^ M, 0, H, 0, 10000 ^*/

    UInt16 pdcchPowerOffset; /*^ M, 0, H, 0, 10000 ^*/

    UInt16 pbchTransmissionPower; /*^ M, 0, H, 0, 10000 ^*/

    UInt16 pchTransmissionpower; /*^ M, 0, H, 0, 10000 ^*/

}rrc_mac_downlink_power_control_common_t;

typedef struct _rrc_mac_tpc_rnti_range_t
{
    UInt16 startTpcRntiPucch; /*^ M, 0, B, 61, 65523 ^*/

    UInt16 endTpcRntiPucch; /*^ M, 0, B, 61, 65523 ^*/

    UInt16 startTpcRntiPusch; /*^ M, 0, B, 61, 65523 ^*/

    UInt16 endTpcRntiPusch; /*^ M, 0, B, 61, 65523 ^*/

}rrc_mac_tpc_rnti_range_t;

typedef struct _rrc_mac_power_control_enable_t
{
    UInt8 harqBlerClpcPucchEnable; /*^ M, 0, H, 0, 1 ^*/

    UInt8 cqiSinrClpcPucchEnable; /*^ M, 0, H, 0, 1 ^*/

    UInt8 clpcPuschEnable;       /*^ M, 0, H, 0, 1 ^*/

    UInt8 pdcchPowOrAggregationEnable;  /*^ M, 0, H, 0, 1 ^*/

    UInt8 clpcPuschfreqSelectiveEnable; /*^ M, 0, H, 0, 1 ^*/

}rrc_mac_power_control_enable_t;

/* PRS + */
typedef struct _rrc_rrm_prs_bandwidth_info_t
{
    UInt8  prs_bandwidth;          /*^ M, 0, H, 0, 5 ^*/
    /* rrc_prs_bandwidth_et */
}rrc_rrm_prs_bandwidth_info_t;

typedef struct _rrc_rrm_prs_subframes_info_t
{
    UInt8  prs_subframes;          /*^ M, 0, H, 0, 3 ^*/
    /* rrc_prs_subframes_et */
}rrc_rrm_prs_subframes_info_t;

typedef struct  _rrc_rrm_prs_config_index_info_t
{
    UInt16 prs_config_index;       /*^ M, 0, H, 0, 4095 ^*/
}rrc_rrm_prs_config_index_info_t;

typedef struct _rrc_rrm_prs_transmission_power_info_t
{
    UInt16 prs_transmission_power; /*^ M, 0, H, 0, 10000 ^*/
}rrc_rrm_prs_transmission_power_info_t;

typedef struct _rrc_rrm_prs_muting_config_info_t
{
    UInt8  bits_to_be_read;        /*^ M, 0, H, 0, 3 ^*/
    /* rrc_prs_muting_bits_et */
    UInt16 prs_muting_config_index;/*^ M, 0, N, 0, 0 ^*/
}rrc_rrm_prs_muting_config_info_t;

typedef struct _rrc_rrm_prs_config_t
{
    rrc_bitmask_t     bitmask;  /*^ BITMASK ^*/
#define RRC_RRM_CONFIG_PRS_MUTING_CONFIG_INFO_PRESENT          0x01

    rrc_rrm_prs_bandwidth_info_t    prs_bandwidth_info; 
    /*^ M, 0, N, 0, 0 ^*/
    rrc_rrm_prs_subframes_info_t    prs_subframes_info; 
    /*^ M, 0, N, 0, 0 ^*/
    rrc_rrm_prs_config_index_info_t prs_config_index_info;
    /*^ M, 0, N, 0, 0 ^*/    
    rrc_rrm_prs_transmission_power_info_t    prs_transmission_power_info;
    /*^ M, 0, N, 0, 0 ^*/
    rrc_rrm_prs_muting_config_info_t    prs_muting_config_info;
    /*^ O, RRC_RRM_CONFIG_PRS_MUTING_CONFIG_INFO_PRESENT, N, 0, 0 ^*/

}rrc_rrm_prs_config_t;

typedef struct _rrc_rrm_prs_config_info_t
{
    rrc_bitmask_t     bitmask;  /*^ BITMASK ^*/
#define RRC_RRM_CONFIG_PRS_CONFIG_PRESENT     0x01

    UInt8  request_type;           /*^ M, 0, H, 0, 1 ^*/ 
    rrc_rrm_prs_config_t    prs_config;
    /*^ O, RRC_RRM_CONFIG_PRS_CONFIG_PRESENT, N, 0, 0 ^*/
}rrc_rrm_prs_config_info_t;

typedef struct _rrc_rrm_prs_reconfig_t
{
    rrc_bitmask_t     bitmask;  /*^ BITMASK ^*/
    /* PRS_UPDATED + */
#define RRC_RRM_RECONFIG_PRS_BANDWIDTH_INFO_PRESENT              0x01
#define RRC_RRM_RECONFIG_PRS_SUBFRAMES_INFO_PRESENT              0x02
#define RRC_RRM_RECONFIG_PRS_CONFIG_INDEX_INFO_PRESENT           0x04
#define RRC_RRM_RECONFIG_PRS_TRANSMISSION_POWER_INFO_PRESENT     0x08
#define RRC_RRM_RECONFIG_PRS_MUTING_CONFIG_INFO_PRESENT          0x10

    rrc_rrm_prs_bandwidth_info_t    prs_bandwidth_info;
    /*^ O, RRC_RRM_RECONFIG_PRS_BANDWIDTH_INFO_PRESENT, N, 0, 0 ^*/

    /* PRS_UPDATED - */
    rrc_rrm_prs_subframes_info_t    prs_subframes_info;
    /*^ O, RRC_RRM_RECONFIG_PRS_SUBFRAMES_INFO_PRESENT, N, 0, 0 ^*/

    rrc_rrm_prs_config_index_info_t prs_config_index_info;
    /*^ O, RRC_RRM_RECONFIG_PRS_CONFIG_INDEX_INFO_PRESENT, N, 0, 0 ^*/

    rrc_rrm_prs_transmission_power_info_t    prs_transmission_power_info;
    /*^ O, RRC_RRM_RECONFIG_PRS_TRANSMISSION_POWER_INFO_PRESENT, N, 0, 0 ^*/

    rrc_rrm_prs_muting_config_info_t    prs_muting_config_info;
    /*^ O, RRC_RRM_RECONFIG_PRS_MUTING_CONFIG_INFO_PRESENT, N, 0, 0 ^*/

}rrc_rrm_prs_reconfig_t;

typedef struct _rrc_rrm_prs_reconfig_info_t
{
    rrc_bitmask_t     bitmask;  /*^ BITMASK ^*/
#define RRC_RRM_RECONFIG_PRS_CONFIG_PRESENT    0x01 

    UInt8  request_type;           /*^ M, 0, H, 0, 1 ^*/
    rrc_rrm_prs_reconfig_t        prs_reconfig;
    /*^ O, RRC_RRM_RECONFIG_PRS_CONFIG_PRESENT, N, 0, 0 ^*/
}rrc_rrm_prs_reconfig_info_t;

/* PRS + */
/* CLPC Stop */

#define RBS_FOR_DCI_1A_SIZE 27
#define RBS_FOR_DCI_1C_SIZE 32

typedef enum
{
    RRC_RBS_PER_TBS_DCI_1A,
    RRC_RBS_PER_TBS_DCI_1C
}rrc_dci_format_for_si_msgs_et;

typedef enum
{
    RRC_UL_SYNC_LOSS_TIMER_INFINITY, 
    RRC_UL_SYNC_LOSS_TIMER_100, 
    RRC_UL_SYNC_LOSS_TIMER_150, 
    RRC_UL_SYNC_LOSS_TIMER_200, 
    RRC_UL_SYNC_LOSS_TIMER_300, 
    RRC_UL_SYNC_LOSS_TIMER_400, 
    RRC_UL_SYNC_LOSS_TIMER_500, 
    RRC_UL_SYNC_LOSS_TIMER_750, 
    RRC_UL_SYNC_LOSS_TIMER_1280, 
    RRC_UL_SYNC_LOSS_TIMER_1920, 
    RRC_UL_SYNC_LOSS_TIMER_2560, 
    RRC_UL_SYNC_LOSS_TIMER_5120, 
    RRC_UL_SYNC_LOSS_TIMER_10240 
}rrc_ul_sync_loss_timer_et;

typedef enum
{
    RRC_NGAP_1 = 0,
    RRC_NGAP_2 = 1
}rrc_n_gap_et;

typedef struct _rrc_si_start_offset_t
{
    UInt8    si_start_offset; /*^ M, 0, H, 0, 39 ^*/
}rrc_si_start_offset_t;

typedef struct _rrc_si_start_offset_info_t
{
    /* SPR-18445 start */
    UInt8    offset_count; /*^ M, 0, B, 1, MAX_SI_START_OFFSET ^*/
    /* SPR-18445 stop */

    rrc_si_start_offset_t    si_start_offset[MAX_SI_START_OFFSET];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/
}rrc_si_start_offset_info_t;


typedef struct _rrc_si_transmission_info_t
{
    rrc_bitmask_t     bitmask;  /*^ BITMASK ^*/
#define RRC_RRM_NUM_OF_TRANSMISSIONS_PRESENT 0x01
#define RRC_RRM_SI_START_OFFSET_INFO_PRESENT 0x02

    UInt8     si_index;  /*^ M, 0, H, 0, 9 ^*/

    UInt8     num_of_transmissions;      
    /*^ O, RRC_RRM_NUM_OF_TRANSMISSIONS_PRESENT, B, 1, 8 ^*/

    rrc_si_start_offset_info_t  si_start_offset_info;
    /*^ O, RRC_RRM_SI_START_OFFSET_INFO_PRESENT, N, 0, 0 ^*/

}rrc_si_transmission_info_t;

typedef struct _rrc_si_transmission_info_list_t
{
    /* SPR-18445 start */
    UInt8     count;     /*^ M, 0, B, 1, MAX_SI_MESSAGE ^*/
    /* SPR-18445 stop */
    rrc_si_transmission_info_t    si_transmission[MAX_SI_MESSAGE];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/
}rrc_si_transmission_info_list_t;

/* SPS Start */
typedef struct _rrc_rrm_sps_crnti_range_t_
{
    UInt16 start_sps_crnti; /*^ M, 0, B, 61, 65523 ^*/

    UInt16 end_sps_crnti;   /*^ M, 0, B, 61, 65523 ^*/
}rrc_rrm_sps_crnti_range_t;
/* SPS Stop */

typedef struct _rrc_mac_reconfig_t
{
    rrc_bitmask_t          bitmask;  /*^ BITMASK ^*/
#define RRC_RRM_RECONFIG_DCI_FORMAT_FOR_SI_MESSAGES_PRESENT 0x01
#define RRC_RRM_RECONFIG_RBS_PER_TBS_DCI_1A_PRESENT         0x02
#define RRC_RRM_RECONFIG_RBS_PER_TBS_DCI_1C_PRESENT         0x04
#define RRC_RRM_RECONFIG_SI_TRANSMISSION_INFO_PRESENT       0x08
#define RRC_RRM_RECONFIG_UL_SYNC_LOSS_TIMER_PRESENT         0x10
#define RRC_RRM_RECONFIG_PUCCH_CQI_SINR_THRESHOLD_PRESENT   0x20
#define RRC_RRM_RECONFIG_N_GAP_PRESENT                      0x40 
    /* SPS Start */
#define RRC_RRM_RECONFIG_SPS_CRNTI_RANGE_PRESENT            0x80
    /* SPS Stop */
    /* PRS + */
#define RRC_RRM_RECONFIG_PRS_INFO_PRESENT            0x100
    /* PRS - */

    UInt8 dci_format_for_si_msgs;
    /*^ O, RRC_RRM_RECONFIG_DCI_FORMAT_FOR_SI_MESSAGES_PRESENT, H, 0, 1 ^*/ 
    /* rrc_dci_format_for_si_msgs_et */

    UInt8 num_rbs_per_tbs_dci_1a[RBS_FOR_DCI_1A_SIZE];
    /*^ O, 2, OCTET_STRING, FIXED, H, 0, 100 ^*/

    UInt8 num_rbs_per_tbs_dci_1c[RBS_FOR_DCI_1C_SIZE];
    /*^ O, 4, OCTET_STRING, FIXED, H, 0, 100 ^*/

    rrc_si_transmission_info_list_t    si_transmission_info;
    /*^ O, RRC_RRM_RECONFIG_SI_TRANSMISSION_INFO_PRESENT, N, 0, 0 ^*/

    UInt8 ul_sync_loss_timer;
    /*^ O, RRC_RRM_RECONFIG_UL_SYNC_LOSS_TIMER_PRESENT, H, 0, 12 ^*/
    /*rrc_ul_sync_loss_timer_et*/

    UInt8 pucch_cqi_sinr_value;
    /*^ O, RRC_RRM_RECONFIG_PUCCH_CQI_SINR_THRESHOLD_PRESENT, N, 0, 0 ^*/
    UInt8   n_gap;
    /*^ O, RRC_RRM_RECONFIG_N_GAP_PRESENT, H, 0, 1 ^*/
    /*rrc_n_gap_et */
    /* SPS Start */
    rrc_rrm_sps_crnti_range_t    sps_crnti_range;
    /*^ O, RRC_RRM_RECONFIG_SPS_CRNTI_RANGE_PRESENT, N, 0, 0 ^*/
    /* SPS Stop */

    /* PRS +*/
    rrc_rrm_prs_reconfig_info_t    prs_reconfig_info;
    /*^ O, RRC_RRM_RECONFIG_PRS_INFO_PRESENT, N, 0, 0 ^*/
    /* PRS -*/

}rrc_mac_reconfig_t;
/*SPR 18672 Fix Start*/
#define MAX_NO_OF_MBSFN_AREAS                   MAX_NUM_CURRENT_SUPPORTED_CELLS *(MAX_MBSFN_AREA_PER_CELL + MAX_RESERVED_MBSFN_AREA_PER_CELL) 
/*SPR 18672 Fix end*/
/*Max no if mbsfn area is multiplied by 2 as 8 areas are reserved and 8
 * unreserved*/

typedef struct 
{
    UInt32   signalling_mcs; /*^ M, 0, H, 0, 3 ^*//* signalling_mcs_et */
    UInt32   mcch_repetition_period; /*^ M, 0, H, 0, 3 ^*//* mcch_repetition_period_et */
    UInt32   mcch_modification_period; /*^ M, 0, H, 0, 1 ^*//* mcch_modification_period_et */
    UInt32   pdcch_length; /*^ M, 0, H, 0, 1 ^*//* pdcch_length_et */
    UInt8    mcch_offset;  /*^ M, 0, H, 0, 10 ^*/
    UInt8    sf_alloc_info;  /*^ M, 0, N, 0, 0 ^*/ /* Bit string of size 6 */
    UInt8    area_id;  /*^ M, 0, N, 0, 0 ^*/
    UInt8    notification_indicator_r9;  /*^ M, 0, H, 0, 7 ^*/
    UInt8    area_index;  /*^ M, 0, H, 0, 15 ^*/
    /*SPR 18672 Fix Start*/
    UInt8    area_type;  /*^ M, 0, H, 0, 1 ^*//*m2ap_area_type_et*/
    /*SPR 18672 Fix end*/
}m2ap_mcch_related_bcch_info_t;

/* SPR 18672 Fix Start */
typedef m2ap_mcch_related_bcch_info_t m2ap_reserved_mcch_related_bcch_info_t;
/* SPR 18672 Fix End */
typedef struct 
{
    UInt32 notification_repetition_coeff; /*^ M, 0, H, 0, 1 ^*//* notification_repetition_coeff_et */
    UInt8  notification_offset; /*^ M,0,H,1,10 ^*/
    UInt8  notification_sf_Index; /*^ M,0,H,1,6 ^*/
}m2ap_notification_config_t;

typedef struct
{
    UInt8                                  num_valid_mbsfn_area_info; /*^ M, 0, H, 0, MAX_MBSFN_SUBFRAME_CONFIG ^*/
    m2ap_mcch_related_bcch_info_t       m2ap_mbsfn_area_info_list[MAX_MBSFN_SUBFRAME_CONFIG]; /*^ M,0,OCTET_STRING,VARIABLE ^*/
    m2ap_notification_config_t          m2ap_notification_config; /*^ M, 0, N, 0, 0 ^*/
}sib_type_13_info_t;

typedef struct
{
    UInt8    area_id; /*^ M, 0,N, 0, 0 ^*/
    UInt8    area_index; /*^ M, 0,H, 0, 15 ^*/
    UInt8    flag; /*^ M, 0, H, 0, 3 ^*/ /* mbms_area_flag_et */ 
}mbms_updated_area_info_t;

typedef struct
{
    /*SPR 18170:start*/
    UInt8                                  num_valid_mbsfn_area_info; /*^ M, 0, H, 0, MAX_MBMS_UPDATED_AREA_LIST ^*/
    mbms_updated_area_info_t
        mbms_updated_area_info[MAX_MBMS_UPDATED_AREA_LIST];
    /*SPR 18170:end*/
    /*^ M,0,OCTET_STRING,VARIABLE ^*/
}mbms_updated_area_info_list_t;




/*SPR 18672 Fix Start*/
#define MAX_MBSFN_AREA_PER_CELL                 8
/*SPR 18672 Fix Start*/
#define MAX_RESERVED_MBSFN_AREA_PER_CELL        0          /*For Reserved areas*/
/*SPR 18672 Fix end*/
#define MAX_RESERVED_CELL_LIST_SIZE  MAX_MBSFN_AREA_PER_CELL + MAX_RESERVED_MBSFN_AREA_PER_CELL
/*SPR 18672 Fix end*/
typedef struct
{
    UInt8 count;/*^ M, 0,N, 1, 8 ^*/
    m2ap_reserved_mcch_related_bcch_info_t m2ap_reserved_cell_mcch_info[MAX_RESERVED_CELL_LIST_SIZE];/*^ M,0,OCTET_STRING,VARIABLE ^*/
}m2ap_reserved_mcch_related_bcch_info_list_t;

typedef struct _sib13_scheduling_info_t
{
    UInt8     si_index;
}sib13_scheduling_info_t;

typedef struct _rrc_mac_config_t
{
    rrc_bitmask_UInt32_t          bitmask;  /*^ BITMASK ^*/
#define RRC_MAC_ENABLE_FREQUENCY_SELECTIVE_SCHEDULING_PRESENT 0x01
    /*SPR_19066_START*/
    /* RRC_RRM_UE_INACTIVE_TIME_PRESENT has been deprecated */
    /*SPR_19066_END*/
    /* CLPC Start */
#define RRC_MAC_TPC_RNTI_PRESENT                              0x04
#define RRC_MAC_POWER_CONTROL_PRESENT                         0x08
    /* CLPC Stop */
#define RRC_RRM_CONTENTION_FREE_RACH_TIMER_PRESENT            0x10
#define RRC_RRM_RBS_PER_TBS_DCI_1A_PRESENT                    0x20
#define RRC_RRM_RBS_PER_TBS_DCI_1C_PRESENT                    0x40
#define RRC_RRM_SI_TRANSMISSION_INFO_PRESENT                  0x80
#define RRC_RRM_UL_SYNC_LOSS_TIMER_PRESENT                    0x100
#define RRC_RRM_PUCCH_CQI_SINR_THRESHOLD_PRESENT              0x200  
#define RRC_RRM_N_GAP_PRESENT                                 0x400 
    /* SPS Start */
#define RRC_RRM_SPS_CRNTI_RANGE_PRESENT                       0x800
    /* SPS Stop */
    /* HD-FDD start */
#define RRC_RRM_DUPLEXING_MODE_PRESENT                        0x1000  
#define RRC_RRM_IS_DYNAMIC_PDCCH_DISABLED_PRESENT             0x2000  
    /* HD-FDD stop */
    /* PRS +*/
#define RRC_RRM_PRS_CONFIG_INFO_PRESENT                       0x4000
    /* PRS -*/
#define RRC_RRM_SIB_13_INFO_PRESENCE_FLAG                     0x8000
#define RRC_RRM_MCCH_CELL_RESERVATION_INFO_PRESENCE_FLAG      0x10000

    UInt8  dl_res_blocks;          /*^ M, 0, B, 1, 100 ^*/
    UInt8  ul_res_blocks;          /*^ M, 0, B, 1, 100 ^*/
    UInt8  max_harq_retrans;       /*^ M, 0, B, 1, 8 ^*/
    UInt8  start_ra_rnti_range;    /*^ M, 0, B, 1, 60 ^*/
    UInt8  end_ra_rnti_range;      /*^ M, 0, B, 1, 60 ^*/
    UInt8  dci_format_for_si_msgs; /*^ M, 0, H, 0, 1 ^*/  /* rrc_dci_format_for_si_msgs_et */

    rrc_mac_enable_frequency_selective_scheduling_t  enable_frequency_selective_scheduling;
    /*^ O, RRC_MAC_ENABLE_FREQUENCY_SELECTIVE_SCHEDULING_PRESENT ^*/

    /*SPR_19066_START*/
    /* Code Removed */
    /*SPR_19066_END*/

    /* CLPC Start */
    rrc_mac_downlink_power_control_common_t downlink_power_control_common;
    /*^ M, 0, N, 0, 0 ^*/

    rrc_mac_tpc_rnti_range_t                tpc_rnti_range;
    /*^ O, RRC_MAC_TPC_RNTI_PRESENT, N, 0, 0 ^*/

    rrc_mac_power_control_enable_t          power_control_enable;
    /*^ O, RRC_MAC_POWER_CONTROL_PRESENT, N, 0, 0 ^*/

    /* CLPC Stop */

    UInt16  contention_free_rach_timer;
    /*^ O, RRC_RRM_CONTENTION_FREE_RACH_TIMER_PRESENT, N, 0, 0 ^*/

    UInt8   num_rbs_per_tbs_dci_1a[RBS_FOR_DCI_1A_SIZE];
    /*^ O, 32, OCTET_STRING, FIXED, H, 0, 100 ^*/

    UInt8   num_rbs_per_tbs_dci_1c[RBS_FOR_DCI_1C_SIZE];
    /*^ O, 64, OCTET_STRING, FIXED, H, 0, 100 ^*/

    rrc_si_transmission_info_list_t    si_transmission_info;
    /*^ O, RRC_RRM_SI_TRANSMISSION_INFO_PRESENT, N, 0, 0 ^*/

    UInt8   ul_sync_loss_timer;
    /*^ O, RRC_RRM_UL_SYNC_LOSS_TIMER_PRESENT, H, 0, 12 ^*/ 
    /*rrc_ul_sync_loss_timer_et */

    UInt8   pucch_cqi_sinr_value;
    /*^ O, RRC_RRM_PUCCH_CQI_SINR_THRESHOLD_PRESENT, N, 0, 0 ^*/
    UInt8   n_gap;
    /*^ O, RRC_RRM_N_GAP_PRESENT, H, 0, 1 ^*/
    /*rrc_n_gap_et */
    /* SPS Start */
    rrc_rrm_sps_crnti_range_t    sps_crnti_range;
    /*^ O, RRC_RRM_SPS_CRNTI_RANGE_PRESENT, N, 0, 0 ^*/

    /* SPS Stop */
    /* HD-FDD start */
    UInt8   duplexing_mode;
    /*^ O, RRC_RRM_DUPLEXING_MODE_PRESENT, H, 0, 2 ^*/
    UInt8   dynamic_pdcch;
    /*^ O, RRC_RRM_IS_DYNAMIC_PDCCH_DISABLED_PRESENT, H, 1, 1 ^*/
    /* HD-FDD stop */

    /* PRS +*/
    rrc_rrm_prs_config_info_t    prs_config_info;
    /*^ O, RRC_RRM_PRS_CONFIG_INFO_PRESENT, N, 0, 0 ^*/
    /* PRS -*/
    sib_type_13_info_t            sib_type_13_info;/*^ O, RRC_RRM_SIB_13_INFO_PRESENCE_FLAG, N, 0, 0 ^*/
    m2ap_reserved_mcch_related_bcch_info_list_t    m2ap_reserved_mcch_related_bcch_info_list;/*^ O,RRC_RRM_MCCH_CELL_RESERVATION_INFO_PRESENCE_FLAG , N, 0, 0 ^*/
    sib13_scheduling_info_t       sib13_scheduling_info; /*^ O, RRC_RRM_SIB_13_INFO_PRESENCE_FLAG, N, 0, 0 ^*/
    /* SPR 19309 + */
    UInt8                   cfi_value;         /*^ M, 0, B, 1, 4 ^*/
    /* SPR 19309 - */
    /* SPR 19310 + */
    UInt16                   num_of_eul;        /*^ M, 0, N, 0, 0 ^*/
    UInt16                   size_of_eul;       /*^ M, 0, N, 0, 0 ^*/
    /* SPR 19310 - */

} rrc_mac_config_t;

/* SPR 21371 Start */
#define RRC_RRM_IPV4_ADDRESS_PRESENT                        0x01  
#define RRC_RRM_IPV6_ADDRESS_PRESENT                        0x02  
typedef struct _rrc_l2_comm_info_t
{
    UInt8                bitmask;                     /*^ BITMASK ^*/
    UInt16             port;                       /*^ M, 0, N, 0, 0 ^*/
    /* MULTI_PDCP CHANGES START */
    UInt16             instance_id;                       /*^ M, 0, N, 0, 0 ^*/
    /* MULTI_PDCP CHANGES END */
    UInt8              ip_addr[IPV4_ADDRESS_LENGTH];    /*^ O, RRC_RRM_IPV4_ADDRESS_PRESENT, OCTET_STRING, FIXED ^*/
    UInt8              ip_addr6[IPV6_ADDRESS_LENGTH];    /*^ O, RRC_RRM_IPV6_ADDRESS_PRESENT, OCTET_STRING, FIXED ^*/
}rrc_l2_comm_info_t;

/******************************************************************************
 *   End of these types are shared CSC-LLIM with RRM
 ******************************************************************************/

/******************************************************************************
 *   These types are shared UECC-LLIM with PHY
 *   Actually this is rrc_phy_physical_config_dedicated_t
 ******************************************************************************/
typedef struct _rrc_phy_scheduling_request_config_param_t
{
    UInt16 sr_pucch_resource_index;  /*^ M, 0, H, 0, 2047 ^*/
    UInt8  sr_configuration_index;   /*^ M, 0, H, 0, 157 ^*/
    UInt8  dsr_trans_max;            /*^ M, 0, H, 0, 4 ^*/ /* dsr_trans_max_et */
} rrc_phy_scheduling_request_config_param_t;

typedef struct _rrc_phy_scheduling_request_config_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_SCHEDULING_REQUEST_CONFIG_PARAM_PRESENT 0x01

    rrc_phy_scheduling_request_config_param_t   scheduling_request_config_param;
    /*^ O, RRC_PHY_SCHEDULING_REQUEST_CONFIG_PARAM_PRESENT ^*/

} rrc_phy_scheduling_request_config_t;

/* cr_316 And 247 structure */
typedef struct _rrc_phy_cqi_report_config_v920_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_CQI_MASK_R9_PRESENT           0x01
#define RRC_PHY_PMI_RI_REPORT_R9_PRESENT      0x02

    UInt8            cqi_mask_r9;
    /*^ O, RRC_PHY_CQI_MASK_R9_PRESENT, H, 0, 0 ^*/  /*cqi_mask_r9_et*/


    UInt8       pmi_ri_report_r9;
    /*^ O, RRC_PHY_PMI_RI_REPORT_R9_PRESENT, H, 0, 0 ^*/  /*pmi_ri_report_r9_et*/

}rrc_phy_cqi_report_config_v920_t;


typedef struct _rrc_phy_codebook_subset_restriction_v920_t
{
    UInt16 type;  /*^ M, 0, H, 0, 1 ^*/ /* codebook_subset_restriction_v920_type_et */
    UInt8  value[4];   /*^ M, O, OCTET_STRING, FIXED ^*/
}rrc_phy_codebook_subset_restriction_v920_t;


typedef struct _rrc_phy_antenna_info_v920_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_CODEBOOK_SUBSET_RESTRICTION_V920_PRESENT  0x01

    rrc_phy_codebook_subset_restriction_v920_t codebook_subset_restriction_v920;
    /*^ O, RRC_PHY_CODEBOOK_SUBSET_RESTRICTION_V920_PRESENT, N, 0, 0 ^*/

}rrc_phy_antenna_info_v920_t;

typedef struct _rrc_phy_cqi_report_aperiodic_r10_setup_csi_trigger_t
{
    UInt8  trigger1;
    /*^ M, 0, N, 0, 0 ^*/

    UInt8  trigger2;
    /*^ M, 0, N, 0, 0 ^*/

} rrc_phy_cqi_report_aperiodic_r10_setup_csi_trigger_t;

typedef struct _rrc_phy_cqi_report_aperiodic_r10_setup_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_CQI_REPORT_APERIODIC_R10_SETUP_APERIODIC_CSI_TRIGGER_PRESENT  0x01

    UInt8  cqi_reporting_mode_aperiodic;
    /*^ M, 0, H, 0, 4 ^*/ /* cqi_reporting_mode_aperiodic_et */

    rrc_phy_cqi_report_aperiodic_r10_setup_csi_trigger_t  aperiodic_csi_trigger;
    /*^ O, RRC_CQI_REPORT_APERIODIC_R10_SETUP_APERIODIC_CSI_TRIGGER_PRESENT, N, 0, 0 ^*/

}rrc_phy_cqi_report_aperiodic_r10_setup_t;

typedef struct _rrc_phy_cqi_report_aperiodic_r10_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_CQI_REPORT_APERIODIC_R10_SETUP_PRESENT  0x01

    UInt8 request_type;            /*^ M, 0, H, 0, 1 ^*/    

    rrc_phy_cqi_report_aperiodic_r10_setup_t setup;
    /*^ O, RRC_PHY_CQI_REPORT_APERIODIC_R10_SETUP_PRESENT, N, 0, 0 ^*/

}rrc_phy_cqi_report_aperiodic_r10_t;

typedef struct _rrc_phy_cqi_format_ind_wideband_r10_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_CQI_FORMAT_IND_PERIODIC_WIDEBAND_CQI_REPORT_MODE_PRESENT  0x01

    UInt8  csi_report_mode;
    /*^ O, RRC_PHY_CQI_FORMAT_IND_PERIODIC_WIDEBAND_CQI_REPORT_MODE_PRESENT, H, 0, 1 ^*/ /* cqi_periodic_format_ind_widebandCQI_csi_reportMode_r10_et */

}rrc_phy_cqi_format_ind_wideband_r10_t;

typedef struct _rrc_phy_cqi_format_ind_subband_r10_t
{
    UInt8  k;
    /*^ M, 0, B, 1, 4 ^*/ 

    UInt8 periodicy_factor;
    /*^ M, 0, H, 0, 1 ^*/  /* cqi_periodic_format_ind_subband_cqi_periodicy_factor_et*/

}rrc_phy_cqi_format_ind_subband_r10_t;

typedef struct _rrc_phy_cqi_format_ind_periodic_r10_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_CQI_FORMAT_IND_PERIODIC_WIDEBAND_CQI_PRESENT  0x01
#define RRC_PHY_CQI_FORMAT_IND_PERIODIC_SUBBAND_CQI_PRESENT   0x02

    rrc_phy_cqi_format_ind_wideband_r10_t  cqi_format_ind_wideband;
    /*^ O, RRC_PHY_CQI_FORMAT_IND_PERIODIC_WIDEBAND_CQI_PRESENT, N, 0, 0 ^*/

    rrc_phy_cqi_format_ind_subband_r10_t cqi_format_ind_subband;
    /*^ O, RRC_PHY_CQI_FORMAT_IND_PERIODIC_SUBBAND_CQI_PRESENT, N, 0, 0 ^*/

} rrc_phy_cqi_format_ind_periodic_r10_t;

typedef struct _rrc_phy_cqi_report_periodic_r10_setup_csi_config_index_setup_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_CQI_PERIODIC_R10_SETUP_CSI_RI_CONFIG_INDEX2_PRESENT  0x01

    UInt16  cqi_pmi_config_index2;
    /*^ M, 0, H, 0, 1023 ^*/

    UInt16  ri_config_index2;
    /*^ O, RRC_PHY_CQI_PERIODIC_R10_SETUP_CSI_RI_CONFIG_INDEX2_PRESENT, H, 0, 1023 ^*/

} rrc_phy_cqi_report_periodic_r10_setup_csi_config_index_setup_t;

typedef struct _rrc_phy_cqi_report_periodic_r10_setup_csi_config_index
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_CQI_REPORT_PERIODIC_R10_SETUP_CSI_CONFIG_INDEX_SETUP_PRESENT  0x01

    UInt8 request_type;        /*^ M, 0, H, 0, 1 ^*/

    rrc_phy_cqi_report_periodic_r10_setup_csi_config_index_setup_t setup;
    /*^ O, RRC_PHY_CQI_REPORT_PERIODIC_R10_SETUP_CSI_CONFIG_INDEX_SETUP_PRESENT, N, 0, 0 ^*/

} rrc_phy_cqi_report_periodic_r10_setup_csi_config_index;

typedef struct _rrc_phy_cqi_report_periodic_r10_setup_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_CQI_REPORT_PERIODIC_R10_SETUP_PUCCH_REPORT_INDEX_P1_PRESENT  0x01
#define RRC_CQI_REPORT_PERIODIC_R10_SETUP_RI_CONFIG_INDEX_PRESENT     0x02
#define RRC_CQI_REPORT_PERIODIC_R10_SETUP_CQI_MASK_PRESENT            0x04
#define RRC_CQI_REPORT_PERIODIC_R10_SETUP_CSI_CONFIG_INDEX_PRESENT    0x08

    UInt16  cqi_pucch_resource_index;
    /*^ M, 0, H, 0,1184 ^*/ 

    UInt16  cqi_pucch_resource_index_p1;
    /*^ O, RRC_CQI_REPORT_PERIODIC_R10_SETUP_PUCCH_REPORT_INDEX_P1_PRESENT, H, 0,1184 ^*/ 

    UInt16  cqi_pmi_config_index;
    /*^ M, 0, H, 0, 1023 ^*/ 

    rrc_phy_cqi_format_ind_periodic_r10_t  cqi_format_ind_periodic;
    /*^ M, 0, N, 0, 0 ^*/ 

    UInt16  ri_config_index;
    /*^ O, RRC_CQI_REPORT_PERIODIC_R10_SETUP_RI_CONFIG_INDEX_PRESENT, H, 0, 1023 ^*/ 

    UInt8  simultaneous_ack_nack_cqi;
    /*^ M, 0, H, 0, 1 ^*/  /* rrc_bool_et */

    UInt8            cqi_mask_r9;
    /*^ O, RRC_CQI_REPORT_PERIODIC_R10_SETUP_CQI_MASK_PRESENT, H, 0, 0 ^*/  /*cqi_mask_r9_et*/

    rrc_phy_cqi_report_periodic_r10_setup_csi_config_index         csi_config_index;
    /*^ O, RRC_CQI_REPORT_PERIODIC_R10_SETUP_CSI_CONFIG_INDEX_PRESENT, N, 0, 0 ^*/


}rrc_phy_cqi_report_periodic_r10_setup_t;

typedef struct _rrc_phy_cqi_report_periodic_r10_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_CQI_REPORT_PERIODIC_R10SETUP_PRESENT  0x01

    UInt8  request_type;           /*^ M, 0, H, 0, 1 ^*/

    rrc_phy_cqi_report_periodic_r10_setup_t setup;
    /*^ O, RRC_PHY_CQI_REPORT_PERIODIC_R10SETUP_PRESENT, N, 0, 0 ^*/

}rrc_phy_cqi_report_periodic_r10_t;

#define MAX_SUBFRAME_CONFIG1_5_TDD 3
#define MAX_SUBFRAME_CONFIG0_TDD   9
#define MAX_SUBFRAME_CONFIG6_TDD   8
#define MAX_SUBFRAME_PATTERN_FDD   5

typedef struct _meas_subframe_pattern_tdd_r10_t
{
#define RRC_PHY_SUBFRAME_PATTERNTDD_SUBFRAME_CONFIG1_5_R10 0x01
#define RRC_PHY_SUBFRAME_PATTERNTDD_SUBFRAME_CONFIG0_R10   0x02
#define RRC_PHY_SUBFRAME_PATTERNTDD_SUBFRAME_CONFIG6_R10   0x04
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/

    UInt8    subframe_config1_5_r10[MAX_SUBFRAME_CONFIG1_5_TDD];
    /*^ O, RRC_PHY_SUBFRAME_PATTERNTDD_SUBFRAME_CONFIG1_5_R10, OCTET_STRING, FIXED ^*/

    UInt8    subframe_config0_r10[MAX_SUBFRAME_CONFIG0_TDD];
    /*^ O, RRC_PHY_SUBFRAME_PATTERNTDD_SUBFRAME_CONFIG0_R10, OCTET_STRING, FIXED ^*/

    UInt8    subframe_config6_r10[MAX_SUBFRAME_CONFIG6_TDD];
    /*^ O, RRC_PHY_SUBFRAME_PATTERNTDD_SUBFRAME_CONFIG6_R10, OCTET_STRING, FIXED ^*/
}rrc_phy_meas_subframe_pattern_tdd_r10_t;

typedef struct _meas_subframe_pattern_fdd_r10_t
{
    UInt8    data[MAX_SUBFRAME_PATTERN_FDD];
    /*^ M, 0, OCTET_STRING, FIXED ^*/
}rrc_phy_meas_subframe_pattern_fdd_r10_t;

typedef struct _meas_subframe_pattern_r10_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_MEAS_SUBFRAME_PATTERN_FDD_R10       0x01
#define RRC_PHY_MEAS_SUBFRAME_PATTERN_TDD_R10       0x02
    rrc_phy_meas_subframe_pattern_fdd_r10_t subframe_pattern_fdd_r10;
    /*^ O, RRC_PHY_MEAS_SUBFRAME_PATTERN_FDD_R10, N, 0, 0 ^*/

    rrc_phy_meas_subframe_pattern_tdd_r10_t subframe_pattern_tdd_r10;
    /*^ O, RRC_PHY_MEAS_SUBFRAME_PATTERN_TDD_R10, N, 0, 0 ^*/
}rrc_phy_meas_subframe_pattern_r10_t;

typedef struct _cqi_report_csi_subframe_pattern_config_r10_setup_t
{
    rrc_phy_meas_subframe_pattern_r10_t    csi_meas_subframe_set1_r10;  /*^ M, 0, N, 0, 0 ^*/
    rrc_phy_meas_subframe_pattern_r10_t    csi_meas_subframe_set2_r10;  /*^ M, 0, N, 0, 0 ^*/
}rrc_phy_cqi_report_csi_subframe_pattern_config_r10_setup_t;

typedef struct _rrc_phy_cqi_report_csi_subframePattern_r10_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_CQI_REPORT_CONFIG_R10_CSI_SUBFRAMEPATTERN_CONFIG_SETUP     0x01
    UInt8  request_type;
    /*^ M, 0, H, 0, 1 ^*/

    rrc_phy_cqi_report_csi_subframe_pattern_config_r10_setup_t    csi_subframe_pattern_config_r10_setup;
    /*^ O, RRC_PHY_CQI_REPORT_CONFIG_R10_CSI_SUBFRAMEPATTERN_CONFIG_SETUP, N, 0, 0 ^*/
}rrc_phy_cqi_report_csi_subframePattern_r10_t;

typedef struct _rrc_cqi_report_config_r10_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_CQI_REPORT_CONFIG_R10_REPORT_APERIODIC_R10_PRESENT  0x01
#define RRC_PHY_CQI_REPORT_CONFIG_R10_REPORT_PERIODIC_R10_PRESENT   0x02
#define RRC_PHY_CQI_REPORT_CONFIG_R10_PMI_RI_REPORT_R9_PRESENT      0x04
#define RRC_PHY_CQI_REPORT_CONFIG_R10_CSI_SUBFRAME_PATTERN_CONFIG_R10_PRESENT        0x08

    rrc_phy_cqi_report_aperiodic_r10_t   cqi_report_aperiodic_r10;
    /*^ O, RRC_PHY_CQI_REPORT_CONFIG_R10_REPORT_APERIODIC_R10_PRESENT, N, 0, 0 ^*/

    SInt8  nomPDSCH_rs_epre_offset;
    /*^ M, 0, B, -1, 6 ^*/

    rrc_phy_cqi_report_periodic_r10_t    cqi_report_periodic_r10;
    /*^ O, RRC_PHY_CQI_REPORT_CONFIG_R10_REPORT_PERIODIC_R10_PRESENT, N, 0, 0 ^*/

    UInt8    cqi_report_pmi_ri_report_r10;
    /*^ O, RRC_PHY_CQI_REPORT_CONFIG_R10_PMI_RI_REPORT_R9_PRESENT, H, 0, 0 ^*/

    rrc_phy_cqi_report_csi_subframePattern_r10_t    csi_subframePattern_r10;
    /*^ O, RRC_PHY_CQI_REPORT_CONFIG_R10_CSI_SUBFRAME_PATTERN_CONFIG_R10_PRESENT, N, 0, 0 ^*/

}rrc_cqi_report_config_r10_t;

typedef struct _rrc_phy_ue_transmit_antenna_selection_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_UE_TRANSMIT_ANTENNA_SELECTION_TYPE_PRESENT  0x01
    UInt8 request_type;        /*^ M, 0, H, 0, 1 ^*/

    UInt8  ue_transmit_antenna_selection_type;
    /*^ O, RRC_PHY_UE_TRANSMIT_ANTENNA_SELECTION_TYPE_PRESENT, H, 0, 1 ^*/
    /* ue_transmit_antenna_selection_type_et */

} rrc_phy_ue_transmit_antenna_selection_t;

typedef struct _rrc_phy_codebook_subset_restriction_t
{
    UInt16 type;  /*^ M, 0, H, 0, 7 ^*/ /* codebook_subset_restriction_type_et */

    UInt8  value[8];   /*^ M, O, OCTET_STRING, FIXED ^*/
} rrc_phy_codebook_subset_restriction_t;

typedef struct _rrc_phy_antenna_information_dedicated_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_CODEBOOK_SUBSET_RESTRICTION_PRESENT 0x01

    UInt8  transmission_mode;     /*^ M, 0, H, 0, 7 ^*/ /* transmission_mode_et */

    rrc_phy_codebook_subset_restriction_t   codebook_subset_restriction;
    /*^ O, RRC_PHY_CODEBOOK_SUBSET_RESTRICTION_PRESENT ^*/

    rrc_phy_ue_transmit_antenna_selection_t ue_transmit_antenna_selection;
} rrc_phy_antenna_information_dedicated_t;

typedef struct _rrc_phy_antenna_information_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_ANTENNA_INFORMATION_EXPLICIT_VALUE_PRESENT  0x01

    rrc_phy_antenna_information_dedicated_t antenna_information_explicit_value;
    /*^ O, RRC_PHY_ANTENNA_INFORMATION_EXPLICIT_VALUE_PRESENT ^*/

} rrc_phy_antenna_information_t;

typedef struct _rrc_phy_sounding_rs_ul_config_dedicated_param_t
{
    UInt8  srs_bandwidth;         /*^ M, 0, H, 0, 3 ^*/ /* srs_bandwidth_et */
    UInt8  srs_hopping_bandwidth;
    /*^ M, 0, H, 0, 3 ^*/ /* srs_hopping_bandwidth_et */

    UInt8  frequency_domain_position;  /*^ M, 0, H, 0, 23 ^*/
    UInt8  duration;                   /*^ M, 0, H, 0, 1 ^*/  /* rrc_bool_et */
    UInt16 srs_configuration_index;    /*^ M, 0, H, 0, 1023 ^*/
    UInt8  transmission_comb;          /*^ M, 0, H, 0, 1 ^*/
    UInt8  cyclic_shift;               /*^ M, 0, H, 0, 7 ^*/  /* cyclic_shift_et */
} rrc_phy_sounding_rs_ul_config_dedicated_param_t;

typedef struct _rrc_phy_sounding_rs_ul_config_dedicated_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_SOUNDING_RS_UL_CONFIG_DEDICATED_PARAM_PRESENT   0x01

    rrc_phy_sounding_rs_ul_config_dedicated_param_t
        sounding_rs_ul_config_dedicated_param;
    /*^ O, RRC_PHY_SOUNDING_RS_UL_CONFIG_DEDICATED_PARAM_PRESENT ^*/

} rrc_phy_sounding_rs_ul_config_dedicated_t;

typedef struct _rrc_phy_subband_cqi_param_param_t
{
    UInt8  k; /*^ M, 0, B, 1, 4 ^*/
} rrc_phy_subband_cqi_param_param_t;

typedef struct _rrc_phy_cqi_format_indicator_periodic_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_SUBBAND_CQI_PARAM_PRESENT   0x01

    rrc_phy_subband_cqi_param_param_t   subband_cqi_param;
    /*^ O, RRC_PHY_SUBBAND_CQI_PARAM_PRESENT ^*/

} rrc_phy_cqi_format_indicator_periodic_t;

typedef struct _rrc_phy_cqi_reporting_periodic_param_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_CQI_RI_CONFIG_INDEX_PRESENT 0x01

    UInt16 cqi_pucch_resource_index; /*^ M, 0, H, 0, 1185 ^*/
    UInt16 cqi_pmi_config_index;     /*^ M, 0, H, 0, 1023 ^*/

    rrc_phy_cqi_format_indicator_periodic_t cqi_format_indicator_periodic;

    UInt16 ri_config_index;
    /*^ O, RRC_PHY_CQI_RI_CONFIG_INDEX_PRESENT, H, 0, 1023 ^*/

    UInt8  simultaneous_ack_nack_and_cqi;  /*^ M, 0, H, 0, 1 ^*/  /* rrc_bool_et */
} rrc_phy_cqi_reporting_periodic_param_t;

typedef struct _rrc_phy_cqi_reporting_periodic_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_CQI_REPORTING_PERIODIC_PARAM_PRESENT    0x01

    rrc_phy_cqi_reporting_periodic_param_t  cqi_reporting_periodic_param;
    /*^ O, RRC_PHY_CQI_REPORTING_PERIODIC_PARAM_PRESENT ^*/

} rrc_phy_cqi_reporting_periodic_t;

typedef struct _rrc_phy_cqi_reporting_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_CQI_REPORTING_PERIODIC_PRESENT          0x01
#define RRC_PHY_CQI_REPORTING_MODE_APERIODIC_PRESENT    0x02

    UInt8  cqi_reporting_mode_aperiodic;
    /*^ O, RRC_PHY_CQI_REPORTING_MODE_APERIODIC_PRESENT, H, 0, 4 ^*/
    /* cqi_reporting_mode_aperiodic_et */

    SInt8  nom_pdsch_rs_epre_offset; /*^ M, 0, B, -1, 6 ^*/

    rrc_phy_cqi_reporting_periodic_t    cqi_reporting_periodic;
    /*^ O, RRC_PHY_CQI_REPORTING_PERIODIC_PRESENT ^*/

} rrc_phy_cqi_reporting_t;

typedef struct _rrc_phy_tpc_index_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define TPC_INDEX_FORMAT_3_PRESENT  0x01
#define TPC_INDEX_FORMAT_3A_PRESENT 0x02

    UInt8  index_of_format3;     /*^ O, TPC_INDEX_FORMAT_3_PRESENT, B, 1, 15 ^*/
    UInt8  index_of_format3a;    /*^ O, TPC_INDEX_FORMAT_3A_PRESENT, B, 1, 31 ^*/
} rrc_phy_tpc_index_t;

typedef struct _rrc_phy_tpc_pdcch_config_param_t
{
    UInt8                  tpc_rnti[2];    /*^ M, O, OCTET_STRING, FIXED ^*/
    rrc_phy_tpc_index_t tpc_index;
} rrc_phy_tpc_pdcch_config_param_t;

typedef struct _rrc_phy_tpc_pdcch_configuration_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_TPC_PDCCH_CONFIG_PARAM_PRESENT  0x01

    rrc_phy_tpc_pdcch_config_param_t    tpc_pdcch_config_param;
    /*^ O, RRC_PHY_TPC_PDCCH_CONFIG_PARAM_PRESENT ^*/

} rrc_phy_tpc_pdcch_configuration_t;

typedef enum
{
    RRC_FC0,
    RRC_FC1,
    RRC_FC2,
    RRC_FC3,
    RRC_FC4,
    RRC_FC5,
    RRC_FC6,
    RRC_FC7,
    RRC_FC8,
    RRC_FC9,
    RRC_FC11,
    RRC_FC13,
    RRC_FC15,
    RRC_FC17,
    RRC_FC19
}rrc_filter_coefficient_et;

typedef struct _rrc_phy_uplink_power_control_dedicated_t
{
    SInt8  p0_ue_pusch;           /*^ M, 0, B, -8, 7 ^*/
    UInt8  delta_mcs_enabled;     /*^ M, 0, H, 0, 1 ^*/ /* delta_mcs_enabled_et */
    UInt8  accumulation_enabled;  /*^ M, 0, H, 0, 1 ^*/   /* rrc_bool_et */
    SInt8  p0_ue_pucch;           /*^ M, 0, B, -8, 7 ^*/
    UInt8  p_srs_offset;          /*^ M, 0, H, 0, 15 ^*/
    UInt8  filter_coefficient;    /*^ M, 0, H, 0, 14 ^*/ /* rrc_filter_coefficient_et */
} rrc_phy_uplink_power_control_dedicated_t;

typedef struct _rrc_phy_pusch_configuration_dedicated_t
{
    UInt8  beta_offset_ack_index; /*^ M, 0, H, 0, 15 ^*/
    UInt8  beta_offset_ri_index; /*^ M, 0, H, 0, 15 ^*/
    UInt8  beta_offset_cqi_index; /*^ M, 0, H, 0, 15 ^*/
} rrc_phy_pusch_configuration_dedicated_t;

typedef struct _rrc_phy_ack_nack_repetition_param_t
{
    UInt8  factor; /*^ M, 0, H, 0, 2 ^*/  /* ack_nack_repetition_factor_et */
    UInt16 an_rep; /*^ M, 0, H, 0, 2047 ^*/
} rrc_phy_ack_nack_repetition_param_t;

typedef struct _rrc_phy_pucch_configuration_dedicated_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_ACK_NACK_REPETITION_PARAM_PRESENT   0x01
#define RRC_PHY_TDD_ACK_NACK_FEEDBACK_MODE_PRESENT  0x02

    rrc_phy_ack_nack_repetition_param_t ack_nack_repetition_param;
    /*^ O, RRC_PHY_ACK_NACK_REPETITION_PARAM_PRESENT ^*/

    UInt8                                  tdd_ack_nack_feedback_mode;
    /*^ O, RRC_PHY_TDD_ACK_NACK_FEEDBACK_MODE_PRESENT, H, 0, 1 ^*/
    /* tdd_ack_nack_feedback_mode_et */

} rrc_phy_pucch_configuration_dedicated_t;

typedef struct _rrc_phy_pdsch_configuration_dedicated_t
{
    UInt8  p_a;    /*^ M, 0, H, 0, 7 ^*/ /* pdsch_configuration_dedicated_p_a_et */
} rrc_phy_pdsch_configuration_dedicated_t;

typedef enum
{

    TM_1 = 0,
    TM_2
} antenna_info_ul_r10_et;

typedef struct _rrc_antenna_info_ul_r10_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_ANTENNA_INFO_UL_R10_TRANSMISSION_MODE_PRESENT             0x01
#define RRC_ANTENNA_INFO_UL_R10_FOUR_ANTENNA_PORT_ACTIVATED_PRESENT   0x02

    UInt8  transmission_mode_ul;
    /*^ O, RRC_ANTENNA_INFO_UL_R10_TRANSMISSION_MODE_PRESENT,H, 0, 1 ^*/  /* antenna_info_ul_r10_et */

    UInt8   four_antenna_port_activated;
    /*^ O, RRC_ANTENNA_INFO_UL_R10_FOUR_ANTENNA_PORT_ACTIVATED_PRESENT, H, 0, 0  ^*/

} rrc_antenna_info_ul_r10_t;

typedef struct
{
    UInt8 num_bits;  /*^ M, 0, B, 2, 109 ^*/

    UInt8  value[CBSR_MAX_VALUE_V1020];   /*^ M, O, OCTET_STRING, FIXED ^*/
} rrc_codebook_subset_restriction_r10_t;

typedef struct
{
    rrc_bitmask_t              bitmask;     /*^ BITMASK ^*/
#define RRM_CODEBOOK_SUBSET_RESTRICTION_PRESENT               0x01

    UInt8  transmission_mode;             
    /*^ M, 0, H, 0, 8 ^*/ /* rrc_rrm_transmission_mode_r10_et */

    rrc_codebook_subset_restriction_r10_t codebook_subset_restriction_r10;
    /*^ O, RRM_CODEBOOK_SUBSET_RESTRICTION_PRESENT  ^*/ 

    rrc_phy_ue_transmit_antenna_selection_t ue_transmit_antenna_selection;
    /*^ M, 0, N, 0, 0 ^*/

} rrc_antenna_info_dedicated_r10_t;

typedef struct _rrc_antenna_info_r10_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_ANTENNA_INFO_R10_EXPLICIT_VALUE_PRESENT   0x01

    rrc_antenna_info_dedicated_r10_t explicit_value;
    /*^ O, RRC_ANTENNA_INFO_R10_EXPLICIT_VALUE_PRESENT ^*/

} rrc_antenna_info_r10_t;

typedef struct _rrc_additional_spectrum_emission_ca_r10_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_ADDITIONAL_SPECTRUM_EMISSION_CA_R10_PCELL_PRESENT   0x01

    UInt8 request_type;            /*^ M, 0, H, 0, 1 ^*/

    UInt8      additional_spectrum_emission_pcell;
    /*^ O, RRC_PHY_ADDITIONAL_SPECTRUM_EMISSION_CA_R10_PCELL_PRESENT, B, 1, 32 ^*/

} rrc_additional_spectrum_emission_ca_r10_t;

typedef struct
{
    /* SPR-18445 start */
    UInt8    count;          /*^ M, 0, B, 1, MAX_N1PUCCH_AN_CS ^*/
    /* SPR-18445 stop */
    UInt16   n1_pucch_an_cs[MAX_N1PUCCH_AN_CS]; /*^ M, 0, OCTET_STRING, VARIABLE, H, 0, 2047 ^*/
}n1pucch_an_cs_r10_t;

typedef struct
{
    /* SPR-18445 start */
    UInt8                    count;          /*^ M, 0, B, 1, MAX_N1PUCCH_AN_CS_LIST ^*/
    /* SPR-18445 stop */
    n1pucch_an_cs_r10_t   n1_pucch_an_cs[MAX_N1PUCCH_AN_CS_LIST]; /*^ M, 0, OCTET_STRING, VARIABLE, N, 0, 0^*/
}n1pucch_an_cs_list_r10_t;

typedef struct _rrc_channel_selection_n1_pucch_an_cs_r10_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_N1PUCCH_AN_CS_LIST_R10_PRESENT                     0x01

    UInt8 request_type;        /*^ M, 0, H, 0, 1 ^*/

    n1pucch_an_cs_list_r10_t                            n1pucch_an_cs_list_r10;
    /*^ O, RRC_N1PUCCH_AN_CS_LIST_R10_PRESENT ^*/
} rrc_channel_selection_n1_pucch_an_cs_r10_t;

typedef struct _rrc_pucch_channel_selection_config_v1020_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_N1PUCCH_AN_CS_R10_PRESENT   0x01

    rrc_channel_selection_n1_pucch_an_cs_r10_t  channel_selection_n1_pucch_an_cs_r10;
    /*^ O, RRC_N1PUCCH_AN_CS_R10_PRESENT ^*/

}rrc_pucch_channel_selection_config_v1020_t;

typedef struct _rrc_phy_physical_config_dedicated_extended_t
{
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_ADDITIONAL_SPECTRUM_EMISSION_CA_R10_PRESENT   0x01
#define RRC_PHY_PUCCH_CHANNEL_SELECTION_CONFIG_R10_PRESENT    0x02

    rrc_additional_spectrum_emission_ca_r10_t      additional_spectrum_emission_ca;
    /*^ O, RRC_PHY_ADDITIONAL_SPECTRUM_EMISSION_CA_R10_PRESENT ^*/

    rrc_pucch_channel_selection_config_v1020_t     pucch_channel_selection_config_v1020; 
    /*^ O, RRC_PHY_PUCCH_CHANNEL_SELECTION_CONFIG_R10_PRESENT ^*/

} rrc_phy_physical_config_dedicated_extended_t;

typedef struct _rrc_phy_physical_config_dedicated_t
{
    UInt16     bitmask;    /*^ BITMASK ^*/
#define RRC_PHY_PDSCH_CONFIGURATION_DEDICATED_PRESENT   0x001
#define RRC_PHY_PUCCH_CONFIGURATION_DEDICATED_PRESENT   0x002
#define RRC_PHY_PUSCH_CONFIGURATION_DEDICATED_PRESENT   0x004
#define RRC_PHY_UPLINK_POWER_CONTROL_DEDICATED_PRESENT  0x008
#define RRC_PHY_TPC_PDCCH_CONFIG_PUCCH_PRESENT          0x010
#define RRC_PHY_TPC_PDCCH_CONFIG_PUSCH_PRESENT          0x020
#define RRC_PHY_CQI_REPORTING_PRESENT                   0x040
#define RRC_PHY_SOUNDING_RS_UL_CONFIG_DEDICATED_PRESENT 0x080
#define RRC_PHY_ANTENNA_INFORMATION_PRESENT             0x100
#define RRC_PHY_SCHEDULING_REQUEST_CONFIG_PRESENT       0x200
#define RRC_PHY_CQI_REPORT_CONFIG_V920_PRESENT          0x400
#define RRC_PHY_ANTENNA_INFO_V920_PRESENT               0x800
#define RRC_PHY_ANTENNA_INFO_R10_PRESENT                0x1000
#define RRC_PHY_ANTENNA_INFO_UL_R10_PRESENT             0x2000
#define RRC_PHY_CQI_REPORT_CONFIG_R10_PRESENT           0x4000
#define RRC_PHY_CONFIG_DEDICATED_EXTENDED_PRESENT       0x8000


    rrc_phy_pdsch_configuration_dedicated_t     pdsch_configuration_dedicated;
    /*^ O, RRC_PHY_PDSCH_CONFIGURATION_DEDICATED_PRESENT ^*/

    rrc_phy_pucch_configuration_dedicated_t     pucch_configuration_dedicated;
    /*^ O, RRC_PHY_PUCCH_CONFIGURATION_DEDICATED_PRESENT ^*/

    rrc_phy_pusch_configuration_dedicated_t     pusch_configuration_dedicated;
    /*^ O, RRC_PHY_PUSCH_CONFIGURATION_DEDICATED_PRESENT ^*/

    rrc_phy_uplink_power_control_dedicated_t    uplink_power_control_dedicated;
    /*^ O, RRC_PHY_UPLINK_POWER_CONTROL_DEDICATED_PRESENT ^*/

    rrc_phy_tpc_pdcch_configuration_t           tpc_pdcch_config_pucch;
    /*^ O, RRC_PHY_TPC_PDCCH_CONFIG_PUCCH_PRESENT ^*/

    rrc_phy_tpc_pdcch_configuration_t           tpc_pdcch_config_pusch;
    /*^ O, RRC_PHY_TPC_PDCCH_CONFIG_PUSCH_PRESENT ^*/

    rrc_phy_cqi_reporting_t                     cqi_reporting;
    /*^ O, RRC_PHY_CQI_REPORTING_PRESENT ^*/

    rrc_phy_sounding_rs_ul_config_dedicated_t   sounding_rs_ul_config_dedicated;
    /*^ O, RRC_PHY_SOUNDING_RS_UL_CONFIG_DEDICATED_PRESENT ^*/

    rrc_phy_antenna_information_t               antenna_information;
    /*^ O, RRC_PHY_ANTENNA_INFORMATION_PRESENT ^*/

    rrc_phy_scheduling_request_config_t         scheduling_request_config;
    /*^ O, RRC_PHY_SCHEDULING_REQUEST_CONFIG_PRESENT ^*/

    /* cr_316 And 247 structres */
    rrc_phy_cqi_report_config_v920_t            cqi_report_config_v920;
    /*^ O, RRC_PHY_CQI_REPORT_CONFIG_V920_PRESENT ^*/

    rrc_phy_antenna_info_v920_t                 antenna_info_v920;
    /*^ O, RRC_PHY_ANTENNA_INFO_V920_PRESENT ^*/

    rrc_antenna_info_r10_t         antenna_info_r10;
    /*^ O, RRC_PHY_ANTENNA_INFO_R10_PRESENT ^*/

    rrc_antenna_info_ul_r10_t         antenna_info_ul_r10;
    /*^ O, RRC_PHY_ANTENNA_INFO_UL_R10_PRESENT ^*/

    rrc_cqi_report_config_r10_t              cqi_report_config_r10;
    /*^ O, RRC_PHY_CQI_REPORT_CONFIG_R10_PRESENT ^*/

    rrc_phy_physical_config_dedicated_extended_t        phy_physical_config_dedicated_extended;
    /*^ O, RRC_PHY_CONFIG_DEDICATED_EXTENDED_PRESENT ^*/


} rrc_phy_physical_config_dedicated_t;

/******************************************************************************
 *   End of these types are shared UECC-LLIM with PHY
 ******************************************************************************/

/******* TDD changes start *******/
typedef enum
{

    DUPLEXING_MODE_TDD = 0,
    DUPLEXING_MODE_FDD = 1,
    /* HD-FDD start */   
    DUPLEXING_MODE_HD_FDD = 2
        /* HD-FDD stop */   
} duplexing_mode_et;

typedef enum
{
    TDD_ACK_NACK_FEEDBACK_MODE_BUNDLING = 0,
    TDD_ACK_NACK_FEEDBACK_MODE_MULTIPLEXING = 1
} tdd_ack_nack_feedback_mode_et;

/******* TDD changes stop *******/

/******************************************************************************
 *   These types are shared UECC-LLIM with MAC
 ******************************************************************************/

/* Enum values for MAC RLC mode */
typedef enum
{
    MAC_RLC_MODE_TM = 0,
    MAC_RLC_MODE_UM,
    MAC_RLC_MODE_AM
} rrc_mac_rlc_mode_et;

/* Enum values for Bearer type*/
typedef enum
{
    BEARER_TYPE_GBR = 0,
    BEARER_TYPE_NON_GBR = 1
} rrc_bearer_type_et;



typedef struct _rrc_mac_configure_status_report_required_enb_t
{
    UInt8  enb_psr_req_flag; /*^ M, 0, H, 0, 1 ^*/  /* rrc_bool_et */ 
} rrc_mac_configure_status_report_required_enb_t; 

typedef struct _rrc_mac_ca_lc_bandwidth_dist_info_t
{
    UInt8 band_width_distribution[MAX_CELLS_PER_UE]; /*^ M, 0, OCTET_STRING, FIXED, H, 0, 100 ^*/
}rrc_mac_ca_lc_bandwidth_dist_info_t;

typedef struct _rrc_mac_dc_bearer_type_info_t
{
    UInt8 dc_bearer_type;    /*^ M, 0, H, 0, 1 ^*/
}rrc_mac_dc_bearer_type_info_t;

#define RRC_MAC_ENB_PSR_REQ_PRESENT 0x01
#define RRC_MAC_DL_CREATE_CA_LC_BANDWIDTH_DIST_INFO_PRESENT 0x02
#define RRC_MAC_DC_BEARER_DL_TYPE_INFO_PRESENT 0x04
typedef struct _rrc_mac_dl_lc_create_req_t
{
    rrc_bitmask_t            optional_elems_present;
    /*^ M, 0, BITMASK, NOT_PRESENT_IN_MESSAGE ^*/
    UInt8  lch_priority;                   /*^ M, 0, B, 1, 16 ^*/
    UInt8  rlc_sn_field_length;            /*^ M, 0, B, 5, 10 ^*/
    rrc_mac_configure_status_report_required_enb_t     configure_status_report_required_enb;
    /*^ TLV, RRC_MAC_ENB_PSR_REQ, RRC_MAC_ENB_PSR_REQ_PRESENT ^*/
    rrc_mac_ca_lc_bandwidth_dist_info_t   ca_lc_bandwidth_dist_info;
    /*^ TLV, RRC_MAC_CA_LC_BANDWIDTH_DIST_INFO, RRC_MAC_DL_CREATE_CA_LC_BANDWIDTH_DIST_INFO_PRESENT ^*/
    rrc_mac_dc_bearer_type_info_t         dc_bearer_type_info;
    /*^ TLV, RRC_MAC_DC_BEARER_TYPE_INFO, RRC_MAC_DC_BEARER_DL_TYPE_INFO_PRESENT  ^*/
} rrc_mac_dl_lc_create_req_t;

typedef struct _rrc_mac_configure_status_report_required_ue_t
{
    UInt8  ue_psr_req_flag; /*^ M, 0, H, 0, 1 ^*/  /* rrc_bool_et */ 
} rrc_mac_configure_status_report_required_ue_t; 

#define RRC_MAC_UE_PSR_REQ_PRESENT 0x01
#define RRC_MAC_DC_BEARER_UL_TYPE_INFO_PRESENT 0x02
typedef struct _rrc_mac_ul_lc_create_req_t
{
    rrc_bitmask_t            optional_elems_present;
    /*^ M, 0, BITMASK, NOT_PRESENT_IN_MESSAGE ^*/
    UInt8  lc_g_id;                        /*^ M, 0, H, 0, 3 ^*/
    rrc_mac_configure_status_report_required_ue_t     configure_status_report_required_ue;
    /*^ TLV, RRC_MAC_UE_PSR_REQ, RRC_MAC_UE_PSR_REQ_PRESENT ^*/
    rrc_mac_dc_bearer_type_info_t dc_bearer_type_info;
    /*^ TLV, RRC_MAC_DC_BEARER_TYPE_INFO, RRC_MAC_DC_BEARER_UL_TYPE_INFO_PRESENT ^*/
} rrc_mac_ul_lc_create_req_t;

typedef struct _rrc_mac_gbr_qos_info_t
{
    UInt32  e_rab_mbr_dl;  /*^ M, 0, N, 0, 0 ^*/
    UInt32  e_rab_mbr_ul;  /*^ M, 0, N, 0, 0 ^*/
    UInt32  e_rab_gbr_dl;  /*^ M, 0, N, 0, 0 ^*/
    UInt32  e_rab_gbr_ul;  /*^ M, 0, N, 0, 0 ^*/
}rrc_mac_gbr_qos_info_t;


#define RRC_MAC_GBR_QOS_INFO_PRESENT 0x04
typedef struct _rrc_mac_qos_info_t
{
    rrc_bitmask_t            optional_elems_present;
    /*^ M, 0, BITMASK, NOT_PRESENT_IN_MESSAGE ^*/

    UInt8                      bearer_type;    
    /*^ M, 0, H, 0, 1 ^*/ /* rrc_bearer_type_et */

    UInt8                       qci;      /*^ M, 0, B, 1, 9 ^*/
    rrc_mac_gbr_qos_info_t   gbr_qos_info;
    /*^ TLV, RRC_MAC_GBR_QOS_INFO, RRC_MAC_GBR_QOS_INFO_PRESENT ^*/

}rrc_mac_qos_info_t;

/* SPS Start */
typedef struct _rrc_mac_rohc_profile_t
{
    UInt16    rohc_profile;
    /*^ M, 0, H, 1, 6 ^*/
}rrc_mac_rohc_profile_t;
/* SPS Stop */

#define RRC_MAC_UL_LC_CREATE_REQ_PRESENT 0x01
#define RRC_MAC_DL_LC_CREATE_REQ_PRESENT 0x02
#define RRC_MAC_QOS_INFO_PRESENT         0x04
/* SPS Start */
#define RRC_MAC_ROHC_PROFILE_PRESENT     0x08
/* SPS Stop */

typedef struct _rrc_mac_create_lc_req_t
{
    rrc_bitmask_t               optional_elems_present;
    /*^ M, 0, BITMASK, NOT_PRESENT_IN_MESSAGE ^*/


    rrc_lc_id_t                 lch_id;                 /*^ M, 0, H, 0, 10 ^*/
    UInt8                          rlc_mode;
    /*^ M, 0, H, 0, 2 ^*/ /* rrc_mac_rlc_mode_et */

    rrc_mac_ul_lc_create_req_t  ul_lc_create_req;
    /*^ TLV, RRC_MAC_UL_LC_CREATE_REQ, RRC_MAC_UL_LC_CREATE_REQ_PRESENT ^*/

    rrc_mac_dl_lc_create_req_t  dl_lc_create_req;
    /*^ TLV, RRC_MAC_DL_LC_CREATE_REQ, RRC_MAC_DL_LC_CREATE_REQ_PRESENT ^*/

    rrc_mac_qos_info_t          qos_info;
    /*^ TLV, RRC_MAC_QOS_INFO, RRC_MAC_QOS_INFO_PRESENT ^*/

    /* SPS Start */
    rrc_mac_rohc_profile_t       rohc_profile;
    /*^ TLV, RRC_MAC_ROHC_PROFILE, RRC_MAC_ROHC_PROFILE_PRESENT ^*/

} rrc_mac_create_lc_req_t;

/******************************************************************************
 *   End of these types are shared UECC-LLIM with MAC
 ******************************************************************************/

/******************************************************************************
 *   These types are shared UECC-LLIM with PDCP and OAM
 ******************************************************************************/

#define RRC_S1U_MAX_TUNNELS_PER_LC 4
/* Enum for PDCP RB direction */
typedef enum
{
    RRC_PDCP_RB_DIR_TX = 0,
    RRC_PDCP_RB_DIR_RX,
    RRC_PDCP_RB_DIR_BOTH
} rrc_rb_direction_et;

typedef enum
{
    UECC_FORWARDING_DIRECTION_DL,
    UECC_FORWARDING_DIRECTION_UL,
    UECC_FORWARDING_DIRECTION_BOTH,
    UECC_FORWARDING_DIRECTION_INVALID,
    UECC_FORWARDING_DIRECTION_ABSENT
}rrm_forwarding_direction_et;

typedef enum
{
    HO_SUCCESS,
    HO_FAILURE
}rrm_ho_status_et;


typedef enum
{
    UE_INACTIVITY_TIME_S1, 
    UE_INACTIVITY_TIME_S2, 
    UE_INACTIVITY_TIME_S3, 
    UE_INACTIVITY_TIME_S5, 
    UE_INACTIVITY_TIME_S7, 
    UE_INACTIVITY_TIME_S10, 
    UE_INACTIVITY_TIME_S15, 
    UE_INACTIVITY_TIME_S20,
    UE_INACTIVITY_TIME_S25, 
    UE_INACTIVITY_TIME_S30, 
    UE_INACTIVITY_TIME_S40, 
    UE_INACTIVITY_TIME_S50, 
    UE_INACTIVITY_TIME_MIN1, 
    UE_INACTIVITY_TIME_MIN1S20c, 
    UE_INACTIVITY_TIME_MIN1S40,
    UE_INACTIVITY_TIME_MIN2, 
    UE_INACTIVITY_TIME_MIN2S30, 
    UE_INACTIVITY_TIME_MIN3, 
    UE_INACTIVITY_TIME_MIN3S30, 
    UE_INACTIVITY_TIME_MIN4, 
    UE_INACTIVITY_TIME_MIN5, 
    UE_INACTIVITY_TIME_MIN6,
    UE_INACTIVITY_TIME_MIN7, 
    UE_INACTIVITY_TIME_MIN8, 
    UE_INACTIVITY_TIME_MIN9, 
    UE_INACTIVITY_TIME_MIN10,
    UE_INACTIVITY_TIME_MIN12, 
    UE_INACTIVITY_TIME_MIN14, 
    UE_INACTIVITY_TIME_MIN17, 
    UE_INACTIVITY_TIME_MIN20,
    UE_INACTIVITY_TIME_MIN24, 
    UE_INACTIVITY_TIME_MIN28, 
    UE_INACTIVITY_TIME_MIN33, 
    UE_INACTIVITY_TIME_MIN38, 
    UE_INACTIVITY_TIME_MIN44, 
    UE_INACTIVITY_TIME_MIN50, 
    UE_INACTIVITY_TIME_HR1,
    UE_INACTIVITY_TIME_HR1MIN30, 
    UE_INACTIVITY_TIME_HR2, 
    UE_INACTIVITY_TIME_HR2MIN30, 
    UE_INACTIVITY_TIME_HR3, 
    UE_INACTIVITY_TIME_HR3MIN30, 
    UE_INACTIVITY_TIME_HR4, 
    UE_INACTIVITY_TIME_HR5, 
    UE_INACTIVITY_TIME_HR6,
    UE_INACTIVITY_TIME_HR8, 
    UE_INACTIVITY_TIME_HR10, 
    UE_INACTIVITY_TIME_HR13, 
    UE_INACTIVITY_TIME_HR16, 
    UE_INACTIVITY_TIME_HR20, 
    UE_INACTIVITY_TIME_DAY1, 
    UE_INACTIVITY_TIME_DAY1HR12, 
    UE_INACTIVITY_TIME_DAY2,
    UE_INACTIVITY_TIME_DAY2HR12, 
    UE_INACTIVITY_TIME_DAY3, 
    UE_INACTIVITY_TIME_DAY4, 
    UE_INACTIVITY_TIME_DAY5, 
    UE_INACTIVITY_TIME_DAY7, 
    UE_INACTIVITY_TIME_DAY10, 
    UE_INACTIVITY_TIME_DAY14, 
    UE_INACTIVITY_TIME_DAY19,
    UE_INACTIVITY_TIME_DAY24, 
    UE_INACTIVITY_TIME_DAY30, 
    UE_INACTIVITY_TIME_DAYMORETHAN30
}rrc_ue_inactivity_time_et;

/* Max size of ASN1 message */
#define UECC_MAX_ASN1_BUF_LEN                   8192
/*SPR 20553 FIX START */
#define UECC_MAX_ASN1_BUF_LEN_RRC_CONN_REL      8188 //On PDCP interface, we have used the max approv 8K size.So,using 8188 value here.
/*SPR 20553 FIX END */
#define UECC_LLIM_SN_STATUS_LEN                 65100 /* Approx 450 bytes in SN HFN STATUS INDICATION will be taken be message */
#define UECC_LLIM_MAX_BUF_LEN                   1024 

/* Enum for PDCP integrity protection algorithm id */
typedef enum
{
    RRC_PDCP_INT_ALG_NIA0 = 0,
    RRC_PDCP_INT_ALG_NIA1,
    RRC_PDCP_INT_ALG_NIA2,
    RRC_PDCP_INT_ALG_NIA3, /*ZUC Changes*/
    RRC_PDCP_INT_ALG_MAX
} rrc_int_algorithm_et;

/* Enum for PDCP ciphering algorithm id */
typedef enum
{
    RRC_PDCP_CIPH_ALG_NEA0 = 0,
    RRC_PDCP_CIPH_ALG_NEA1,
    RRC_PDCP_CIPH_ALG_NEA2,
    RRC_PDCP_CIPH_ALG_NEA3,
    RRC_PDCP_CIPH_ALG_MAX
} rrc_ciph_algorithm_et;

#define RRC_PDCP_SECURITY_KEY_SIZE      16

typedef struct _rrc_pdcp_config_int_t
{
    UInt16 algorithm_id;                       /* rrc_int_algorithm_et */
    UInt8  key[RRC_PDCP_SECURITY_KEY_SIZE];    /*^ M, 0, OCTET_STRING, FIXED ^*/
} rrc_pdcp_config_int_t;

typedef enum
{
    BREARER_TYPE_SRB,
    BREARER_TYPE_DRB,
    BREARER_TYPE_MAX
}bearer_type_et;
#define K_RRC_ENC_ALG_P1 0x03
#define K_RRC_INT_ALG_P1 0x04
#define K_UP_ENC_ALG_P1  0x05

#define K_UP_INT_ALG_P1  0x06

/******************************************************************************
 *   End of these types are shared UECC-LLIM with PDCP
 ******************************************************************************/

/******************************************************************************
 *   These types are shared UECC-LLIM with MAC
 ******************************************************************************/
typedef enum
{
    INVALID_HO,
    NGAP_BASED_HO,
    XNAP_BASED_HO,
    INTER_DU_HO,
    INTER_DU_INTER_CU_UP_HO,
    INTER_CELL_HO,
    /*Multi_cu_up_changes */
    INTER_CELL_INTER_CU_UP_HO,
    /*Multi_cu_up_changes */
    /* OUTGOING_IRAT_CHANGES s*/
    INTER_RAT_HO,
    INTER_RAT_HO_5GS_TO_EPS
        /* OUTGOING_IRAT_CHANGES e*/
}rrc_ho_type_et;

typedef enum
{
    HANDOVER_TYPE_INTRA_LTE_S1,
    HANDOVER_TYPE_LTE_TO_UTRAN,
    HANDOVER_TYPE_LTE_TO_GERAN,
    HANDOVER_TYPE_UTRAN_TO_LTE,
    HANDOVER_TYPE_GERAN_TO_LTE,
    HANDOVER_TYPE_INTRA_LTE_X2,
    HANDOVER_TYPE_INTRA_CELL,
    HANDOVER_TYPE_LTE_TO_CDMA2000_1XRTT,
    HANDOVER_TYPE_LTE_TO_CDMA2000_HRPD,
    HANDOVER_TYPE_LTE_TO_CDMA2000_CONC_1XRTT_HRPD,
    HANDOVER_TYPE_CCO,
    HANDOVER_TYPE_INTER_CELL,
    /*Multi_cu_up_changes */
    HANDOVER_TYPE_INTER_CELL_INTER_CU_UP,
    /*Multi_cu_up_changes */
    /*NGAP_BASED_HO_START_*/
    /*NSA-InterDU-HO Changes Start*/
    HANDOVER_TYPE_INTRA_FREQ_INTER_DU,
    HANDOVER_TYPE_INTRA_FREQ_INTER_DU_INTER_CU_UP,
    HANDOVER_TYPE_INTER_FREQ_INTER_DU,
    HANDOVER_TYPE_INTER_FREQ_INTER_DU_INTER_CU_UP,
    /*NSA-InterDU-HO Changes Stop*/
    HANDOVER_TYPE_INTRA_FREQ_INTER_CU_NG,
    HANDOVER_TYPE_INTER_FREQ_INTER_CU_NG,
    HANDOVER_TYPE_INTRA_FREQ_INTER_CU_XN,
    HANDOVER_TYPE_INTER_FREQ_INTER_CU_XN,
    /* OUTGOING_IRAT_CHANGES_START */
    HANDOVER_TYPE_5GS_TO_EPS,
    /* OUTGOING_IRAT_CHANGES_END */

    /*NGAP_BASED_HO_START_*/
    /* SPR 19078: CID 101192 Fix Start */
    HANDOVER_TYPE_INVALID
        /* SPR 19078: CID 101192 Fix End */
}rrc_handover_type_et;

typedef enum
{
    HANDOVER_INTRA_FREQ,
    HANDOVER_INTER_FREQ
} rrc_handover_freq_type_et;

typedef enum
{
    RELEASE = 0,
    SETUP
} rrc_request_type_et;

/* Inactivity Feature Changes Start*/
typedef enum {
    RRC_NOT_SUPPORTED = 0
} rrc_InactivityMonitoringResponse_Root_et;
/* Inactivity Feature Changes Stop*/

typedef enum
{
    MAC_RELEASE = 0,
    MAC_SETUP
} rrc_mac_request_type_et;

typedef struct _rrc_mac_ri_config_index_info_t
{
    UInt16  ri_config_index;               /*^ M, 0, H, 0, 1023 ^*/
} rrc_mac_ri_config_index_info_t;

/* eICIC changes start */
typedef struct _cqi_pmi_config_index2_r10_t
{
    UInt16         cqi_pmi_config_index2;      /*^ M, 0, H, 0, 1023 ^*/
}cqi_pmi_config_index2_r10_t;


typedef struct _rrc_mac_csi_config_index_v10_t
{

#define RRC_MAC_CQI_PMI_CONFIG_INDEX2_R10_PRESENT 0x01
#define RRC_MAC_RI_CONFIG_INDEX2_R10_PRESENT 0x02

    rrc_bitmask_t                       optional_elems_present;
    /*^ M, 0, BITMASK, NOT_PRESENT_IN_MESSAGE ^*/

    UInt8                                  request_type;     /*^ M, 0, H, 0, 1 ^*/

    cqi_pmi_config_index2_r10_t         cqi_pmi_config_index2_r10;
    /*^ TLV, RRC_MAC_CQI_PMI_CONFIG_INDEX2_R10, RRC_MAC_CQI_PMI_CONFIG_INDEX2_R10_PRESENT ^*/

    rrc_mac_ri_config_index_info_t      ri_config_index2_r_10;
    /*^ TLV, RRC_MAC_RI_CONFIG_INDEX_INFO, RRC_MAC_RI_CONFIG_INDEX2_R10_PRESENT ^*/

}rrc_mac_csi_config_index_v10_t;
/* eICIC changes stop */

typedef enum
{
    RRC_MAC_PERIODIC_WIDEBAND = 0,
    RRC_MAC_PERIODIC_SUBBAND
}rrc_cqi_fmt_indicator_periodic_t;

typedef struct _rrc_mac_cqi_format_indicator_perdiodic_subband_k_t
{
    UInt8   cqi_format_indicator_periodic_subband_k;
    /*^ M, 0, H, 1, 4 ^*/

}rrc_mac_cqi_fmt_ind_perdiodic_subband_k_t;

#define RRC_MAC_RI_CONFIG_INDEX_INFO_PRESENT 0x01
#define RRC_MAC_CQI_FMT_IND_PERIODIC_SUBBAND_K_PRESENT 0x02
/* eICIC changes start */
#define RRC_MAC_CSI_CONFIG_INDEX_V10_PRESENT                  0x04
/* eICIC changes stop */

typedef struct _rrc_mac_cqi_pmi_config_index_info_t
{
    rrc_bitmask_t           optional_elems_present;
    /*^ M, 0, BITMASK, NOT_PRESENT_IN_MESSAGE ^*/


    UInt16  cqi_pmi_config_index;
    /*^ M, 0, H, 0, 1023 ^*/

    UInt16  cqi_pucch_resource_index;
    /*^ M, 0, H, 0, 1185 ^*/

    UInt8  simultaneous_ack_nack_and_cqi;
    /*^ M, 0, H, 0, 1 ^*/

    /**** TDD changes start ****/
    UInt8   cqi_fmt_ind_periodic;
    /*^ M, 0, H, 0, 1 ^*/ /* rrc_cqi_fmt_indicator_periodic_t */

    rrc_mac_cqi_fmt_ind_perdiodic_subband_k_t   cqi_fmt_ind_periodic_subband_k;
    /*^ TLV, RRC_MAC_CQI_FMT_IND_PERIODIC_SUBBAND_K, RRC_MAC_CQI_FMT_IND_PERIODIC_SUBBAND_K_PRESENT ^*/

    /**** TDD changes stop ****/

    rrc_mac_ri_config_index_info_t  ri_config_index_info;
    /*^ TLV, RRC_MAC_RI_CONFIG_INDEX_INFO, RRC_MAC_RI_CONFIG_INDEX_INFO_PRESENT ^*/

} rrc_mac_cqi_pmi_config_index_info_t;


typedef struct _rrc_mac_cqi_pmi_config_index_info_v1020_t
{

    rrc_bitmask_t                                   optional_elems_present;
    /*^ M, 0, BITMASK, NOT_PRESENT_IN_MESSAGE ^*/

    /* eICIC changes start */
    UInt16  cqi_pmi_config_index;
    /*^ M, 0, H, 0, 1023 ^*/

    UInt16  cqi_pucch_resource_index;
    /*^ M, 0, H, 0, 1185 ^*/

    UInt8  simultaneous_ack_nack_and_cqi;
    /*^ M, 0, H, 0, 1 ^*/

    /**** TDD changes start ****/
    UInt8   cqi_fmt_ind_periodic;
    /*^ M, 0, H, 0, 1 ^*/ /* rrc_cqi_fmt_indicator_periodic_t */

    rrc_mac_cqi_fmt_ind_perdiodic_subband_k_t   cqi_fmt_ind_periodic_subband_k;
    /*^ TLV, RRC_MAC_CQI_FMT_IND_PERIODIC_SUBBAND_K, RRC_MAC_CQI_FMT_IND_PERIODIC_SUBBAND_K_PRESENT ^*/

    /**** TDD changes stop ****/

    rrc_mac_ri_config_index_info_t  ri_config_index_info;
    /*^ TLV, RRC_MAC_RI_CONFIG_INDEX_INFO, RRC_MAC_RI_CONFIG_INDEX_INFO_PRESENT ^*/


    rrc_mac_csi_config_index_v10_t                  csi_config_index_v10;
    /*^ TLV, RRC_MAC_CSI_CONFIG_INDEX_V10, RRC_MAC_CSI_CONFIG_INDEX_V10_PRESENT ^*/
    /* eICIC changes stop */

}rrc_mac_cqi_pmi_config_index_info_v1020_t;


#define RRC_MAC_CQI_PMI_CONFIG_INDEX_INFO_PRESENT 0x01
#define RRC_MAC_CQI_PMI_CONFIG_INDEX_INFO_V1020_PRESENT 0x02

typedef struct _rrc_mac_cqi_periodic_config_info_t
{
    rrc_bitmask_t           optional_elems_present;
    /*^ M, 0, BITMASK, NOT_PRESENT_IN_MESSAGE ^*/


    UInt8  request_type;                               /*^ M, 0, H, 0, 1 ^*/

    rrc_mac_cqi_pmi_config_index_info_t cqi_pmi_config_index_info;
    /*^ TLV, RRC_MAC_CQI_PMI_CONFIG_INDEX_INFO, RRC_MAC_CQI_PMI_CONFIG_INDEX_INFO_PRESENT ^*/

    /* eICIC changes start */
    rrc_mac_cqi_pmi_config_index_info_v1020_t cqi_pmi_config_index_info_v1020;
    /*^ TLV, RRC_MAC_CQI_PMI_CONFIG_INDEX_INFO_V1020, RRC_MAC_CQI_PMI_CONFIG_INDEX_INFO_V1020_PRESENT ^*/
    /* eICIC changes stop */

} rrc_mac_cqi_periodic_config_info_t;

typedef struct _aperiodic_csi_trigger_r10_t
{
    UInt8   trigger1r10; /*^ M, 0, H, 0, 64 ^*/
    UInt8   trigger2r10; /*^ M, 0, H, 0, 192 ^*/
}aperiodic_csi_trigger_r10_t;

#define RRC_MAC_APERIODIC_CSI_TRIGGER_R10_PRESENT 0x01
typedef struct _rrc_mac_cqi_aperiodic_config_info_t
{
    rrc_bitmask_t                       optional_elems_present;
    /*^ M, 0, BITMASK, NOT_PRESENT_IN_MESSAGE ^*/

    UInt8  cqi_aperiodic_mode;         /*^ M, 0, B, 12, 31 ^*/

    aperiodic_csi_trigger_r10_t     aperiodic_csi_trigger_r10;
    /*^ TLV, RRC_MAC_APERIODIC_CSI_TRIGGER_R10, RRC_MAC_APERIODIC_CSI_TRIGGER_R10_PRESENT ^*/
} rrc_mac_cqi_aperiodic_config_info_t;


/* cr_316And247 IEs Mac Changes */

typedef struct _rrc_mac_cqi_mask_r9_t
{
    UInt8  cqi_mask_r9; /*^ M, 0, H, 0, 1 ^*/ /*cqi_mask_r9_et*/
}rrc_mac_cqi_mask_r9_t;

typedef struct _rrc_mac_pmi_ri_report_r9_t
{
    UInt8 pmi_ri_report_r9; /*^ M, 0, H, 0, 1 ^*/ /*pmi_ri_report_r9_mac_et*/
}rrc_mac_pmi_ri_report_r9_t;

#define RRC_MAC_CQI_REPORT_CONFIG_CQI_MASK_R9_PRESENT      0x01
#define RRC_MAC_CQI_REPORT_CONFIG_PMI_RI_REPORT_R9_PRESENT 0x02
typedef struct _rrc_mac_cqi_report_config_v920_t
{
    rrc_bitmask_t                       optional_elems_present;
    /*^ M, 0, BITMASK, NOT_PRESENT_IN_MESSAGE ^*/


    rrc_mac_cqi_mask_r9_t           rrc_mac_cqi_mask_r9;
    /*^ TLV, RRC_MAC_CQI_REPORT_CONFIG_CQI_MASK_R9, RRC_MAC_CQI_REPORT_CONFIG_CQI_MASK_R9_PRESENT ^*/

    rrc_mac_pmi_ri_report_r9_t       rrc_mac_pmi_ri_report_r9;
    /*^ TLV, RRC_MAC_CQI_REPORT_CONFIG_PMI_RI_REPORT_R9, RRC_MAC_CQI_REPORT_CONFIG_PMI_RI_REPORT_R9_PRESENT ^*/

}rrc_mac_cqi_report_config_v920_t;


/* eICIC changes start */
/* SPR 14057 start */
typedef struct _rrc_mac_csi_meas_subframe_set1_r10_t
{
    UInt8                                choice;               /*^ M, 0, H, 0, 3 ^*/ /* rrc_mac_csi_meas_subframe_set_choice_et */
    UInt8                                count;                /*^ M, 0, BUFFER_SIZE, NOT_PRESENT_IN_MESSAGE ^*/  
    UInt8                                csi_measurement_subset[CSI_MEAS_MEASUREMENT_SUBSET_SIZE]; /*^ M, 0, OCTET_STRING, LIMITED_TILL_THE_END ^*/ 
}rrc_mac_csi_meas_subframe_set1_r10_t;

typedef struct _rrc_mac_csi_meas_subframe_set2_r10_t
{
    UInt8                                choice;               /*^ M, 0, H, 0, 3 ^*/ /* rrc_mac_csi_meas_subframe_set_choice_et */
    UInt8                                count;                /*^ M, 0, BUFFER_SIZE, NOT_PRESENT_IN_MESSAGE ^*/  
    UInt8                                csi_measurement_subset[CSI_MEAS_MEASUREMENT_SUBSET_SIZE]; /*^ M, 0, OCTET_STRING, LIMITED_TILL_THE_END ^*/ 
}rrc_mac_csi_meas_subframe_set2_r10_t;
/* SPR 14057 end */

typedef struct _rrc_mac_csi_subframe_pattern_config_v10_t
{
#define RRC_MAC_CSI_MEAS_SUBFRAME_SET1_R10_PRESENT  0x01
#define RRC_MAC_CSI_MEAS_SUBFRAME_SET2_R10_PRESENT  0x02

    rrc_bitmask_t                              optional_elems_present; 
    /*^ M, 0, BITMASK, NOT_PRESENT_IN_MESSAGE ^*/
    UInt8                                         request_type;     /*^ M, 0, H, 0, 1 ^*/   /* rrc_mac_request_type_et */
    /* SPR 14057 start */
    rrc_mac_csi_meas_subframe_set1_r10_t        rrc_mac_csi_meas_subframe_set1_r10;
    /*^ TLV, RRC_MAC_CSI_MEAS_SUBFRAME_SET1_R10, RRC_MAC_CSI_MEAS_SUBFRAME_SET1_R10_PRESENT ^*/
    rrc_mac_csi_meas_subframe_set2_r10_t        rrc_mac_csi_meas_subframe_set2_r10;
    /*^ TLV, RRC_MAC_CSI_MEAS_SUBFRAME_SET2_R10, RRC_MAC_CSI_MEAS_SUBFRAME_SET2_R10_PRESENT ^*/
    /* SPR 14057 end */
}rrc_mac_csi_subframe_pattern_config_v10_t;
/* eICIC changes stop */

#define RRC_MAC_CQI_APERIODIC_CONFIG_INFO_PRESENT 0x01
#define RRC_MAC_CQI_PERIODIC_CONFIG_INFO_PRESENT  0x02
#define RRC_MAC_CQI_REPORT_CONFIG_V920_PRESENT    0x04
/* eICIC changes start */
#define RRC_MAC_CQI_CSI_SUBFRAME_PATTERN_CONFIG_V10_PRESENT     0x08
/* eICIC changes stop */
typedef struct _rrc_mac_cqi_info_t
{
    rrc_bitmask_t                       optional_elems_present;
    /*^ M, 0, BITMASK, NOT_PRESENT_IN_MESSAGE ^*/


    rrc_mac_cqi_aperiodic_config_info_t cqi_aperiodic_config_info;
    /*^ TLV, RRC_MAC_CQI_APERIODIC_CONFIG_INFO, RRC_MAC_CQI_APERIODIC_CONFIG_INFO_PRESENT ^*/

    rrc_mac_cqi_periodic_config_info_t  cqi_periodic_config_info;
    /*^ TLV, RRC_MAC_CQI_PERIODIC_CONFIG_INFO, RRC_MAC_CQI_PERIODIC_CONFIG_INFO_PRESENT ^*/

    /* Rel9 Upgrade Changes Start */
    /* cr 316And247 IEs MAC Changes */
    rrc_mac_cqi_report_config_v920_t cqi_report_config_v920;
    /*^ TLV, RRC_MAC_CQI_REPORT_CONFIG_V920, RRC_MAC_CQI_REPORT_CONFIG_V920_PRESENT ^*/ 
    /* Rel9 Upgrade Changes Stop */
    /* eICIC ue reconfig changes start */
    rrc_mac_csi_subframe_pattern_config_v10_t   rrc_mac_csi_subframe_pattern_config_v10;
    /*^ TLV, RRC_MAC_CQI_CSI_SUBFRAME_PATTERN_CONFIG_V10, RRC_MAC_CQI_CSI_SUBFRAME_PATTERN_CONFIG_V10_PRESENT ^*/
    /* eICIC ue reconfig changes stop */
} rrc_mac_cqi_info_t;


typedef struct _rrc_mac_sr_setup_info_t
{
    UInt16 sr_pucch_resource_index;    /*^ M, 0, H, 0, 2047 ^*/
    UInt8  sr_configuration_index;     /*^ M, 0, H, 0, 157 ^*/
} rrc_mac_sr_setup_info_t;

#define RRC_MAC_SR_SETUP_INFO_PRESENT 0x01

typedef struct _rrc_mac_sr_config_info_t
{
    rrc_bitmask_t           optional_elems_present;
    /*^ M, 0, BITMASK, NOT_PRESENT_IN_MESSAGE ^*/


    UInt8  request_type;                               /*^ M, 0, H, 0, 1 ^*/

    rrc_mac_sr_setup_info_t sr_setup_info;
    /*^ TLV, RRC_MAC_SR_SETUP_INFO, RRC_MAC_SR_SETUP_INFO_PRESENT ^*/

} rrc_mac_sr_config_info_t;

typedef struct _rrc_mac_pusch_config_info_t
{
    UInt8     beta_offset_ack_index; /*^ M, 0, H, 0, 15 ^*/

    UInt8     beta_offset_ri_index;  /*^ M, 0, H, 0, 15 ^*/

    UInt8     beta_offset_cqi_index; /*^ M, 0, H, 0, 15 ^*/

}rrc_mac_pusch_config_info_t;

/******************************************************************************
 *   End of these types are shared UECC-LLIM with MAC
 ******************************************************************************/

/******************************************************************************
 *   These types are shared CSC-UECC with RRM
 ******************************************************************************/
#define MAX_MNC_OCTET_SIZE                  3
#define MCC_OCTET_SIZE                      3
#define MAX_PLMN_ID_INFO_SIZE               6
#define CSG_ID_OCTET_SIZE                   4
#define TAC_OCTET_SIZE                      2
#define EXTENDED_TAC_OCTET_SIZE             3
#define LAC_OCTET_SIZE                      2
#define CELL_ID_OCTET_SIZE                  4
#define MAX_NR_CELL_IDENTITY_OCTETS         5
#define GNB_ID_OCTET_SIZE                  4
/* SPR 15180 FIX START */
/* SPR 19596 Fix Start */
/* Code Deleted */
/* SPR 19596 Fix End */
/* SPR 15180 FIX STOP */

/* SPR 2330 Start */
typedef enum
{
    MACRO_ENB_ID = 1,        
    HOME_ENB_ID         
}rrc_enb_id_et;
/* SPR 2330 Stop */

typedef struct
{
    UInt8        count;                      /*^ M, 0, B, 2, MAX_MNC_OCTET_SIZE ^*/
    UInt8        mnc[MAX_MNC_OCTET_SIZE];    /*^ M, 0, OCTET_STRING, VARIABLE ^*/
}mnc_t;


#define PLMN_IDENTITY_MCC_PRESENCE_FLAG     0x01

typedef struct
{
    UInt16       presence_bitmask;       /*^ BITMASK ^*/
    /*SPR 23565 Fix Start*/
    UInt8        mcc[MCC_OCTET_SIZE];    /*^ O, 1, OCTET_STRING, FIXED ^*/
    /*SPR 23565 Fix Stop*/
    mnc_t     mnc;                    /*^ M, 0, N, 0, 0 ^*/
}plmn_identity_t;


typedef enum
{
    RRC_RRM_MS0_DOT_5,
    RRC_RRM_MS1,
    RRC_RRM_MS2,
    RRC_RRM_MS5,
    RRC_RRM_MS10
}dl_ul_trnsmisn_pdcty_et;

#define RRC_RRM_DL_UL_TRANSMISSION_PERIODICITY_PRESENT  0x01
#define RRC_RRM_NUM_UL_SLOTS_PRESENT                    0x02
#define RRC_RRM_NUM_UL_SYMBOLS_PRESENT                  0x04
#define RRC_RRM_NUM_DL_SLOTS_PRESENT                    0x08
#define RRC_RRM_NUM_DL_SYMBOLS_PRESENT                  0x10
typedef struct
{
    UInt16         presence_bitmask;/*^ BITMASK ^*/
    UInt32         dl_ul_transmission_periodicity;/*^ O, RRC_RRM_DL_UL_TRANSMISSION_PERIODICITY_PRESENT, H, 0, 4 ^*//*dl_ul_trnsmisn_pdcty_et*/
    UInt8          num_ul_slots;/*^ O, RRC_RRM_NUM_UL_SLOTS_PRESENT, H, 0, 160 ^*/
    UInt8          num_ul_symbols;/*^ O, RRC_RRM_NUM_UL_SYMBOLS_PRESENT, N, 0, 0 ^*/
    UInt8          num_dl_slots;/*^ O, RRC_RRM_NUM_DL_SLOTS_PRESENT, H, 0, 160 ^*/
    UInt8          num_dl_symbols;/*^ O, RRC_RRM_NUM_DL_SYMBOLS_PRESENT, N, 0, 0 ^*/
}rrc_tdd_config_info_t;

typedef struct
{
    plmn_identity_t    plmn_identity;/*^ M, 0, N, 0, 0 ^*/
    UInt8              cell_id[MAX_NR_CELL_IDENTITY_OCTETS];/*^ M,0,OCTET_STRING,FIXED ^*/

    /*ASKEY_GNBID Change 2 S*/
    UInt8              gNB_ID_len; /*^ M, 0, N, 0, 0 ^*/
    /*ASKEY_GNBID Change 2 E*/
}nr_global_cell_id_t;

/* DU+FPA_integration fix starts */
#define RRC_RRM_PDCP_COUNT_WRAPARND_THRESH_DL_PRESENT  0x01
#define RRC_RRM_PDCP_COUNT_WRAPARND_THRESH_UL_PRESENT  0x02
/* DU+FPA_integration fix ends */
typedef struct
{
    UInt8              presence_bitmask;         /*^ BITMASK ^*/
    rrc_l2_comm_info_t pdcp_comm_info;           /*^ M, 0, N, 0, 0 ^*/
    /* DU+FPA_integration fix starts */
    UInt32             count_wraparnd_thresh_dl;    /*^ O, RRC_RRM_PDCP_COUNT_WRAPARND_THRESH_DL_PRESENT, N, 0, 0 ^*/
    UInt32             count_wraparnd_thresh_ul;    /*^ O, RRC_RRM_PDCP_COUNT_WRAPARND_THRESH_UL_PRESENT, N, 0, 0 ^*/
    /* DU+FPA_integration fix ends */
}rrc_pdcp_cell_config_t;

#define RRC_RRM_ASSOCIATED_PDCP_INST_FIELD_PRESENT  0x01
#define RRC_RRM_PDCP_RX_DATA_PORT_PRESENT           0x02
typedef struct
{
    UInt8                      presence_bitmask;/*^ BITMASK ^*/
    rrc_l2_comm_info_t         s1u_comm_info;    /*^ M, 0, N, 0, 0 ^*/
    UInt8                      associated_pdcp_inst;/*^ O, RRC_RRM_ASSOCIATED_PDCP_INST_FIELD_PRESENT, N, 0 , 0 ^*/
    UInt16                     pdcp_rx_data_port;  /*^ O, RRC_RRM_PDCP_RX_DATA_PORT_PRESENT, N, 0, 0 ^*/
}rrc_s1u_cell_config_t;

#define RRC_RRM_PHYSICAL_LAYER_PARAM_TDD_CONFIG_PRESENT 0x01
typedef struct
{
    UInt16                     presence_bitmask;/*^ BITMASK ^*/
    rrc_tdd_config_info_t   tdd_ul_dl_config;/*^ O, RRC_RRM_PHYSICAL_LAYER_PARAM_TDD_CONFIG_PRESENT, N, 0, 0 ^*/
}rrc_phy_config_t;

typedef struct
{
    UInt8 plmn_id[MAX_PLMN_ID_BYTES]; /*^ M,0,OCTET_STRING,FIXED ^*/
}s1ap_plmn_identity_t;

typedef struct
{
    s1ap_plmn_identity_t plmn_identity;/*^ M, 0, N, 0, 0 ^*/

    UInt8    cell_identity[4];
    /*^ M, 0, OCTET_STRING, FIXED ^*/

}s1ap_cgi_eutra_t;

typedef enum
{
    RRM_RRC_CELL_RESERVED,
    RRM_RRC_CELL_NOT_RESERVED
}rrm_cell_res_for_operator_use_et;


typedef struct
{
    plmn_identity_t   plmn_identity;              /*^ M, 0, N, 0, 0 ^*/
    UInt8                cell_res_for_operator_use;
    /*^ M, 0, H, 1, 1 ^*/   /* rrm_cell_res_for_operator_use_et */

}plmn_identity_info_t;


typedef struct
{
    /* SPR_17664_start*/
    UInt8            count;      /*^ M, 0, B, 1, MAX_PLMN_ID_INFO_SIZE ^*/

    /* SPR_17664_end*/
    plmn_identity_info_t  plmn_identity_info[MAX_PLMN_ID_INFO_SIZE];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/

}plmn_id_info_list_t;


/******************************************************************************
 *   End of these types are shared CSC-UECC with RRM
 ******************************************************************************/

typedef enum
{
    TARGET_RAT_TYPE_UTRA,
    TARGET_RAT_TYPE_GERAN,
    TARGET_RAT_TYPE_CDMA2000_1XRTT,
    TARGET_RAT_TYPE_CDMA2000_HRPD,
    /* OUTGOING_IRAT_CHANGES s*/
    TARGET_RAT_TYPE_EUTRA
        /* OUTGOING_IRAT_CHANGES e*/
}target_rat_type_et;

/* Values for rrc_response_et, rrc_response_t */
typedef enum
{
#ifndef OAM_IPR
    FAILURE,
    SUCCESS,
#endif
    PARTIAL_SUCCESS,
    L3_FATAL
}rrc_response_et;

/* Values for rrc_response_et, rrc_response_t */
typedef enum
{
    ERAB_FAILURE,    
    ERAB_SUCCESS,
    ERAB_PARTIAL_SUCCESS,
    ERAB_FATAL
}rrc_erab_response_et;


typedef enum
{
    RRC_NO_ERROR,
    RRC_TIMER_EXPIRY,
    RRC_INTERACTION_WITH_OTHER_PROCEDURE,
    RRC_RADIO_LINK_FAILURE_TRIGGERED,
    RRC_RADIO_LINK_FAILURE_TRIGGERED_ROLLBACK_FAILURE,
    RRC_HANDOVER_TRIGGERED,
    RRC_HANDOVER_ROLLBACK_TRIGGERED_FAILURE,
    RRC_REESTABLISHMENT_TRIGGERED,
    RRC_REESTABLISHMENT_TRIGGERED_ROLLBACK_FAILURE,
    RRC_MEMORY_ALLOCATION_FAILURE,
    RRC_INVALID_RESPONSE_RECEIVED,
    RRC_INTERNAL_ERROR,
    RRC_UNKNOWN_ERAB_ID,
    RRC_UECC_INVALID_QOS_COMBINATION,
    RRC_UECC_NON_GBR_RAB_NOT_PRESENT,
    RRC_UECC_ERAB_RELEASE_FAILED,
    RRC_INVALID_RRM_MESSAGE_RECV,
    RRC_LLIM_RECONFIG_FAILURE,
    RRC_RRM_MEAS_CONFIG_ALREADY_ONGOING,
    SCELL_ADDITION_FAILED ,
    SCELL_MODIFICATION_FAILED,
    SCELL_DELETION_FAILED, 
    SCELL_CONFIG_FAILED,
    GNB_ERROR_CODE_LAST
}rrc_erab_error_codes_t;

#define S1AP_CELL_INFO_UPDATE_IND_CELL_ID_PRESENT      0x0001
#define S1AP_CELL_INFO_UPDATE_IND_TAC_PRESENT          0x0002
#define S1AP_CELL_INFO_UPDATE_IND_EMERGENCY_ID_PRESENT 0x0004
typedef struct _cell_area_info_t
{
    rrc_bitmask_t        bitmask;
    UInt8                   cell_id[CELL_ID_OCTET_SIZE];
    UInt8                   tac[TAC_OCTET_SIZE];
    UInt8                   emergency_id[EMERGENCY_AREA_SIZE];
}cell_area_info_t ;

typedef enum
{
    PAGE_SI,
    PAGE_ETWS,
    PAGE_CMAS,
    PAGE_SI_ETWS,
    PAGE_SI_CMAS,
    PAGE_ETWS_CMAS,
    PAGE_SI_ETWS_CMAS
}paging_type_et;


#define SIB_10_WARN_SEC_INFO_PRESENCE_FLAG      0x01

typedef struct
{
    UInt16       presence_bitmask;                          /*^ BITMASK ^*/
    UInt8        msg_id[MSG_ID_OCTET_SIZE];
    /*^ M, 0, OCTET_STRING, FIXED ^*/

    UInt8        serial_number[SERIAL_NUMBER_OCTET_SIZE];
    /*^ M, 0, OCTET_STRING, FIXED ^*/

    UInt8        warning_type[WARNING_TYPE_OCTET_SIZE];
    /*^ M, 0, OCTET_STRING, FIXED ^*/

    UInt8        warning_security_info[SECURITY_INFORMATION_OCTET_SIZE];
    /*^ O, 1, OCTET_STRING, FIXED ^*/

}sib_type_10_Info_t;

#define SIB_11_DATA_COD_SCHEME_PRESENCE_FLAG      0x01

typedef struct
{
    UInt16       presence_bitmask;              /*^ BITMASK ^*/
    UInt8        msg_id[MSG_ID_OCTET_SIZE];     /*^ M, 0, OCTET_STRING, FIXED ^*/
    UInt8        serial_number[SERIAL_NUMBER_OCTET_SIZE];
    /*^ M, 0, OCTET_STRING, FIXED ^*/
    /* SPR-18445 start */
    UInt16        warning_msg_size;      /*^ M, 0, H, 1, WARNING_MSG_OCTET_SIZE ^*/
    /* SPR-18445 stop */
    UInt8        warning_msg[WARNING_MSG_OCTET_SIZE];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/

    UInt8        data_coding_scheme[DATA_CODING_SCHEME_OCTET_SIZE];
    /*^ O, SIB_11_DATA_COD_SCHEME_PRESENCE_FLAG, OCTET_STRING, FIXED ^*/

}sib_type_11_Info_t;

typedef struct _rrc_csc_oam_stat_paging_t
{
    UInt32 pag_discardedNbr;
    /*^ M, 0, N, 0, 0 ^*/
    UInt32 pag_succNbr; 
    /*^ M, 0, N, 0, 0 ^*/
    /*CR 025 changes start*/    
    UInt32 pag_receivedNbr;
    /*^ M, 0, N, 0, 0 ^*/
    /*CR 025 changes stop*/    
} rrc_csc_oam_stat_paging_t;
#define SIB_12_DATA_COD_SCHEME_PRESENCE_FLAG      0x01

typedef struct
{
    UInt16       presence_bitmask;              /*^ BITMASK ^*/
    UInt8        msg_id[MSG_ID_OCTET_SIZE];     /*^ M, 0, OCTET_STRING, FIXED ^*/
    UInt8        serial_number[SERIAL_NUMBER_OCTET_SIZE];
    /*^ M, 0, OCTET_STRING, FIXED ^*/
    /* SPR-18445 start */
    UInt16        warning_msg_size;      /*^ M, 0, H, 1, WARNING_MSG_OCTET_SIZE ^*/
    /* SPR-18445 stop */
    UInt8        warning_msg[WARNING_MSG_OCTET_SIZE];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/

    UInt8        data_coding_scheme[DATA_CODING_SCHEME_OCTET_SIZE];
    /*^ O, SIB_12_DATA_COD_SCHEME_PRESENCE_FLAG, OCTET_STRING, FIXED ^*/

}sib_type_12_Info_t;


typedef struct
{
    plmn_identity_t              plmn_identity; /*^ M, 0, N, 0, 0 ^*/
    UInt8                                 location_area_code[2]; /*^ M, 0, OCTET_STRING, FIXED ^*/
}rrm_lai_info_t;

typedef struct
{
    UInt16                                bitmask; /*^ BITMASK ^*/
#define RRM_RNC_ROUTING_AREA_CODE_PRESENT               0X01
#define RRM_RNC_EXTENDED_RNC_ID_PRESENT                    0X02

    rrm_lai_info_t                 lai;  /*^ M, 0, N, 0, 0 ^*/
    UInt8                                 routing_area_code; 
    /*^ O, RRM_RNC_ROUTING_AREA_CODE_PRESENT, N, 0, 0 ^*/

    UInt16                               rnc_id; /*^ M, 0, H, 0, 4095 ^*/
    UInt16                               extended_rnc_id; 
    /*^ O, RRM_RNC_EXTENDED_RNC_ID_PRESENT, N, 4096, 65535 ^*/
}rrm_rnc_id_t;

typedef struct
{
    /*SPR_17664_start*/
    UInt32 num;    /*^ M, 0, H, 0, MAX_LAC_NUMOCTS ^*/
    /*SPR_17664_end*/
    UInt8  data[MAX_LAC_NUMOCTS];/*^ M, 0, OCTET_STRING, FIXED ^*/
}lac_t;

typedef struct
{
    /*SPR_17664_start*/
    UInt32 num;    /*^ M, 0, H, 0, MAX_PLMN_ID_NUMOCTS ^*/
    /*SPR_17664_end*/
    UInt8  data[MAX_PLMN_ID_NUMOCTS];/*^ M, 0, OCTET_STRING, FIXED ^*/
}plmn_identity_lai_t;

typedef struct
{
    plmn_identity_lai_t plmn_identity;  /*^ M, 0, N, 0, 0 ^*/
    lac_t           lac;                /*^ M, 0, N, 0, 0 ^*/
}registered_lai_t;


/* cr_220 timers added  */

/* Values for RLF Timer t301_r9 */
typedef enum
{
    RRC_RLF_T301_MS100,
    RRC_RLF_T301_MS200, 
    RRC_RLF_T301_MS300, 
    RRC_RLF_T301_MS400, 
    RRC_RLF_T301_MS600, 
    RRC_RLF_T301_MS1000, 
    RRC_RLF_T301_MS1500,
    RRC_RLF_T301_MS2000
}t301_r9_et;


/* Values for RLF Timer t310_r9 */
typedef enum
{
    RRC_RLF_T310_MS_0, 
    RRC_RLF_T310_MS_50, 
    RRC_RLF_T310_MS_100, 
    RRC_RLF_T310_MS_200, 
    RRC_RLF_T310_MS_500, 
    RRC_RLF_T310_MS_1000, 
    RRC_RLF_T310_MS_2000
}t310_r9_et;

/* Values for RLF Timer n310_r9 */
typedef enum
{
    RRC_RLF_N310_N1, 
    RRC_RLF_N310_N2, 
    RRC_RLF_N310_N3, 
    RRC_RLF_N310_N4, 
    RRC_RLF_N310_N6, 
    RRC_RLF_N310_N8, 
    RRC_RLF_N310_N10, 
    RRC_RLF_N310_N20
}n310_r9_et;

/* Values for RLF Timer t311_r9 */
typedef enum
{
    RRC_RLF_T311_MS_1000, 
    RRC_RLF_T311_MS_3000, 
    RRC_RLF_T311_MS_5000, 
    RRC_RLF_T311_MS_10000, 
    RRC_RLF_T311_MS_15000,
    RRC_RLF_T311_MS_20000, 
    RRC_RLF_T311_MS_30000
}t311_r9_et;

/* Values for RLF Timer n311_r9 */
typedef enum
{
    RRC_RLF_N311_N_1, 
    RRC_RLF_N311_N_2, 
    RRC_RLF_N311_N_3, 
    RRC_RLF_N311_N_4, 
    RRC_RLF_N311_N_5, 
    RRC_RLF_N311_N_6, 
    RRC_RLF_N311_N_8, 
    RRC_RLF_N311_N_10
}n311_r9_et;

typedef struct
{
    UInt8 t301_r9; /*^ M, 0, H, 0, 7 ^*/ /* t301_r9_et */

    UInt8 t310_r9; /*^ M, 0, H, 0, 6 ^*/ /* t310_r9_et */

    UInt8 n310_r9; /*^ M, 0, H, 0, 7 ^*/ /* n310_r9_et */               

    UInt8 t311_r9; /*^ M, 0, H, 0, 6 ^*/ /* t311_r9_et */             

    UInt8 n311_r9; /*^ M, 0, H, 0, 7 ^*/ /* n311_r9_et */             

}setup_t;

typedef struct
{

    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/

#define RLF_TIMERS_AND_CONSTANTS_SETUP_PRESENT 0x01

    setup_t setup;
    /*^ O, RLF_TIMERS_AND_CONSTANTS_SETUP_PRESENT ^*/

}rlf_timers_and_constants_r9_t;

typedef SInt32 sctp_sd_t;
#define X2AP_SCTP_ASSOC_MAX_RETRANS_PRESENT    0x01
#define X2AP_SCTP_VAL_COOKIE_LIFE_PRESENT      0x02
/* dscp_marking_start */
#define X2AP_OAM_DSCP_VALUE_PRESENT            0x04
/* dscp_marking_stop */
typedef struct
{
    UInt32   hbinterval;  /*^ M,0,N,0,0 ^*/
    UInt16   pathmaxrxt; /*^ M,0,N,0,0 ^*/
    UInt16   init_num_ostreams; /*^ M,0,N,0,0 ^*/
    UInt16   init_max_instreams; /*^ M,0,N,0,0 ^*/
    UInt16   init_max_attempts; /*^ M,0,N,0,0 ^*/
    UInt16   init_max_init_timeo; /*^ M,0,N,0,0 ^*/
    UInt32   rto_initial; /*^ M,0,N,0,0 ^*/
    UInt32   rto_max; /*^ M,0,N,0,0 ^*/
    UInt32   rto_min; /*^ M,0,N,0,0 ^*/
    /*sctp parameters start*/
    UInt16   bitmask;/*^ BITMASK ^*/
    UInt16   assoc_max_retrans;
    /*^ O, X2AP_SCTP_ASSOC_MAX_RETRANS_PRESENT,N,0,0 ^*/
    UInt32      valid_cookie_life;
    /*^ O, X2AP_SCTP_VAL_COOKIE_LIFE_PRESENT,N,0,0 ^*/
    /*sctp parameters stop*/
    /* dscp_marking_start */
    UInt8   x2ap_dscp_value;
    /*^ O,X2AP_OAM_DSCP_VALUE_PRESENT, H, 0, 63 ^*/
    /* dscp_marking_stop */
}x2ap_sctp_conf_info_t;
typedef struct
{
    UInt16     bitmask; /*^ BITMASK ^*/
#define X2AP_OAM_X2_HEALTH_MONITORING_TIMER_PRESENT 0x01    
    UInt16   sctp_connect_tim_val;  /*^ M,0,B,50,65535 ^*/
    UInt16   x2ap_csi_guard_tim_val; /*^ M,0,B,50,65535 ^*/
    UInt16   x2ap_time_to_wait_index; /*^ M,0,B,50,65535 ^*/
    UInt16   x2ap_setup_retry_tim_val; /*^ M,0,B,50,65535 ^*/
    UInt8    sctp_connect_retry_cnt; /*^ M,0,H,0,255 ^*/
    UInt8    x2ap_setup_retry_cnt; /*^ M,0,H,0,10 ^*/
    UInt8    eNB_Config_Update_retry_cnt; /*^ M,0,H,0,10 ^*/
    UInt16   eNB_Config_Update_retry_timer_val; /*^ M,0,B,50,65535 ^*/
    UInt8    eNB_Config_Update_time_to_wait_retry_cnt; /*^ M,0,H,0,10 ^*/
    UInt16   eNB_Config_Update_time_to_wait_offset; /*^ M,0,B,50,65535 ^*/
    UInt8    x2ap_enb_reset_retry_cnt; /*^ M,0,H,0,10 ^*/
    UInt16   x2ap_enb_reset_guard_tim_val; /*^ M,0,B,50,65535 ^*/
    UInt16   x2_setup_req_w_timer; /*^ M,0,B,50,65535 ^*/
    UInt16   x2ap_health_mon_time_int; /*^ M,0,H,0,65535 ^*/
    UInt16   x2ap_tim_to_wait_tim_val; /*^ M,0,H,0,65535 ^*/

}x2ap_con_tim_info_t;

typedef struct
{
    x2ap_sctp_conf_info_t  sctp_conf_param; /*^ M,0,N,0,0 ^*/
    x2ap_con_tim_info_t    timer_conf_info; /*^ M,0,N,0,0 ^*/
}x2ap_conf_param_t;

typedef struct
{
    UInt8 ip_addr[MAX_X2AP_IP_ADDRESS_LENGTH]; /*^ M,0,OCTET_STRING,FIXED ^*/
}x2_ip_addr_t;

/* IPV6 Start */
typedef struct
{
    UInt8 ipv6_addr[MAX_X2AP_IPV6_ADDRESS_LENGTH]; /*^ M,0,OCTET_STRING,FIXED ^*/
}x2_ipv6_addr_t;
/* IPV6 Stop */

typedef struct
{
    UInt8 eNB_id[MACRO_ENB_ID_OCTET_SIZE]; /*^ M,0,OCTET_STRING,FIXED ^*/
}macro_enb_id_t;


typedef struct
{
    UInt8 eNB_id[HOME_ENB_ID_OCTET_SIZE]; /*^ M,0,OCTET_STRING,FIXED ^*/
}home_enb_id_t;


typedef struct
{
    UInt8 presence_bitmask;    /*^ BITMASK ^*/

#define X2AP_OAM_MACRO_ENB_ID_PRESENT        0x01
#define X2AP_OAM_HOME_ENB_ID_PRESENT         0x02
    macro_enb_id_t  macro_enb_id; /*^ O,1,N,0,0 ^*/

    home_enb_id_t   home_enb_id; /*^ O,2,N,0,0 ^*/
}x2_enb_id_info_t;
typedef struct
{
    UInt8 plmn_id[MAX_PLMN_ID_BYTES]; /*^ M,0,OCTET_STRING,FIXED ^*/
}x2ap_plmn_identity_t;

typedef struct
{
    x2ap_plmn_identity_t  plmn_identity;  /*^ M,0,N,0,0 ^*/
    UInt8                    nr_cell_id[NR_ENB_ID_OCTET_SIZE];   /*^ M, 0, OCTET_STRING, FIXED ^*/
}x2_nr_cgi_t;

typedef struct
{

#define XNAP_PLMN_IDENTITY_MAX_BYTES     3

    /* PLMN Identity Bytes */
    UInt8   plmn_id_bytes [XNAP_PLMN_IDENTITY_MAX_BYTES];
    /*^ M, 0, OCTET_STRING, FIXED ^*/

} xnap_plmn_identity_t;


typedef struct
{
    xnap_plmn_identity_t  plmn_identity;  /*^ M,0,N,0,0 ^*/
    UInt8                    nr_cell_id[NR_ENB_ID_OCTET_SIZE];   /*^ M, 0, OCTET_STRING, FIXED ^*/
}_xn_nr_cgi_t;


typedef struct
{
    /*PLMN id */
    x2ap_plmn_identity_t plmn_identity; /*^ M,0,N,0,0 ^*/

    /* eNB id info */
    x2_enb_id_info_t     enb_id; /*^ M,0,N,0,0 ^*/
}x2_gb_enb_id_t;

typedef struct
{
    /*SPR 24250 Fix Start*/
    UInt8 x2_gnb_id_num_bits; /*^ M,0,H,22,32 ^*/
    /*SPR 24250 Fix End*/
    UInt8 x2_gnb_id[EN_GNB_ID_OCTET_SIZE];  /*^ M,0,OCTET_STRING,FIXED ^*/
}x2_gnb_id_t;

typedef struct
{
    x2ap_plmn_identity_t plmn_identity; /*^ M,0,N,0,0 ^*/
    x2_gnb_id_t x2_en_gnb_id;
    /*^ M,0,N,0,0 ^*/
}x2_gb_gnb_id_t;

typedef struct
{
    x2ap_plmn_identity_t  plmn_identity;  /*^ M,0,N,0,0 ^*/
    UInt8                     eutran_cell_id[HOME_ENB_ID_OCTET_SIZE]; /*^ M,0,OCTET_STRING,FIXED ^*/
}x2ap_ecgi_t;

typedef struct
{
    UInt8 tac[MAX_EUTRA_TAC_BYTES];  /*^ M,0,OCTET_STRING,FIXED ^*/
}x2ap_tac_t;

typedef struct
{
    /* SPR-18445 start */
    UInt8     data_length; /*^ M, 0, H, 0, RRC_MAX_IP_ADDR_LEN_IPV6  ^*/
    /* SPR-18445 stop */

    UInt8     data[RRC_MAX_IP_ADDR_LEN_IPV6];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/

}x2_trans_layer_addrs_t;

#define X2_EXTEND_TRANS_LAYER_ADDRS_IPSEC_ADDRS_PRESENT    0x01
#define X2_EXTEND_TRANS_LAYER_ADDRS_NUM_GTP_ADDRS_PRESENT  0x02
#define X2_EXTEND_TRANS_LAYER_ADDRS_GTP_ADDRS_PRESENT      0x04
typedef struct
{
    UInt16                          bitmask;    /*^ BITMASK ^*/

    x2_trans_layer_addrs_t ipsec_trans_layer_addrs;
    /*^ O,X2_EXTEND_TRANS_LAYER_ADDRS_IPSEC_ADDRS_PRESENT,N,0,0 ^*/

    UInt8                           num_tlas; 
    /* SPR_17664_start*/
    /*^ O,X2_EXTEND_TRANS_LAYER_ADDRS_NUM_GTP_ADDRS_PRESENT,B,1,MAX_NUM_ENB_X2AP_GTP_TLAS ^*/

    /* SPR_17664_end*/
    x2_trans_layer_addrs_t   gtp_trans_layer_addrs[MAX_NUM_ENB_X2AP_GTP_TLAS];  /*^ O,X2_EXTEND_TRANS_LAYER_ADDRS_GTP_ADDRS_PRESENT,OCTET_STRING,VARIABLE ^*/

}x2_extend_trans_layer_addrs_t;

/*Menb_WhiteList_Start*/
typedef struct
{
    /* eNB id info */
    x2_enb_id_info_t     enb_id; /*^ M,0,N,0,0 ^*/
}x2_Menb_gb_enb_id_t;

typedef struct
{
    UInt8                          num_peer_enb;     /*^ M,0,H,0,MAX_PEER_ENB ^*/
	x2_Menb_gb_enb_id_t              gb_enb_id[MAX_PEER_ENB]; /*^ M,0,OCTET_STRING,VARIABLE ^*/
}x2_Menb_gb_enb_id_list_info_t;


/* IPV6 Start */
#define X2_MENB_COMM_INFO_IPV6_NUM_ADDR_PRESENT       0x01
#define X2_MENB_COMM_INFO_IPV6_IP_ADDR_PRESENT        0x02
#define X2_MENB_COMM_INFO_IPV4_NUM_ADDR_PRESENT       0x04
#define X2_MENB_COMM_INFO_IPV4_IP_ADDR_PRESENT        0x08
typedef struct
{
    UInt8 bitmask;    /*^ BITMASK ^*/

    UInt8           num_ip_addr; /*^ M,0,H,0,MAX_X2AP_MENB_NUMIPADDR ^*/
    
    UInt8           num_ipv4_addr; /*^ O,X2_MENB_COMM_INFO_IPV4_NUM_ADDR_PRESENT,H,0,MAX_X2AP_MENB_NUMIPADDR ^*/
    
    /* ip addresses of Menbs */
    x2_ip_addr_t ip_addr[MAX_X2AP_MENB_NUMIPADDR];  /*^ O,X2_MENB_COMM_INFO_IPV4_IP_ADDR_PRESENT,OCTET_STRING,VARIABLE ^*/

    UInt8           num_ipv6_addr; 
    /*^ O,X2_MENB_COMM_INFO_IPV6_NUM_ADDR_PRESENT,H,0,MAX_X2AP_MENB_NUMIPADDR ^*/

    /* ip addresses of Menbs */
    x2_ipv6_addr_t ipv6_addr[MAX_X2AP_MENB_NUMIPADDR];  
    /*^ O,X2_MENB_COMM_INFO_IPV6_IP_ADDR_PRESENT,OCTET_STRING,VARIABLE ^*/

}x2_Menb_comm_info_t;
/*Menb_WhiteList_Stop*/

/* IPV6 Start */
#define X2_ENB_COMM_INFO_IPV6_NUM_ADDR_PRESENT       0x01
#define X2_ENB_COMM_INFO_IPV6_IP_ADDR_PRESENT        0x02
#define X2_ENB_COMM_INFO_EXT_NUM_TLAS_PRESENT        0x04
#define X2_ENB_COMM_INFO_EXT_TLAS_PRESENT            0x08
/* SPR 20633 changes Start */
#define X2_ENB_COMM_INFO_IPV4_NUM_ADDR_PRESENT       0x10
#define X2_ENB_COMM_INFO_IPV4_IP_ADDR_PRESENT        0x20
typedef struct
{
    UInt8 bitmask;    /*^ BITMASK ^*/
    /* SPR 20633 changes End */
    /* number of ip addr */
    /* SPR_17664_start */
    /* SPR 20633 changes Start */
    UInt8           num_ip_addr; /*^ O,X2_ENB_COMM_INFO_IPV4_NUM_ADDR_PRESENT,B,1,MAX_NUM_IP_ADDR ^*/
    /* SPR 20633 changes End */
    /* SPR_17664_end */
    /* ip addresses of MMEs */
    /* SPR 20633 changes Start */
    x2_ip_addr_t ip_addr[MAX_NUM_IP_ADDR];  /*^ O,X2_ENB_COMM_INFO_IPV4_IP_ADDR_PRESENT,OCTET_STRING,VARIABLE ^*/
    /* SPR 20633 changes End */

    /* port of MME with which SCTP association needs to be initiated
     * */
    UInt16       port;  /*^ M,0,N,0,0 ^*/


    UInt8           num_ipv6_addr; 
    /* SPR_17664_start */
    /*^ O,X2_ENB_COMM_INFO_IPV6_NUM_ADDR_PRESENT,B,1,MAX_NUM_IP_ADDR ^*/

    /* SPR_17664_end*/

    /* ip addresses of MMEs */
    x2_ipv6_addr_t ipv6_addr[MAX_NUM_IP_ADDR];  
    /*^ O,X2_ENB_COMM_INFO_IPV6_IP_ADDR_PRESENT,OCTET_STRING,VARIABLE ^*/


    UInt8           num_tlas; 
    /* SPR_17664_start*/
    /*^ O,X2_ENB_COMM_INFO_EXT_NUM_TLAS_PRESENT,B,1,MAX_NUM_ENB_X2AP_EXT_TLAS ^*/
    /* SPR_17664_end*/
    x2_extend_trans_layer_addrs_t extend_trans_layer_addrs[MAX_NUM_ENB_X2AP_EXT_TLAS];
    /*^ O,X2_ENB_COMM_INFO_EXT_TLAS_PRESENT,OCTET_STRING,VARIABLE ^*/

}x2_enb_comm_info_t;
/*IPV6 Stop*/
typedef struct
{
    UInt32 earfcn; /*^ M,0,H,0,MAX_EARFCN ^*/
}x2ap_earfcn_t;

typedef enum
{
    BW6 = 0,
    BW15,
    BW25,
    BW50,
    BW100
}x2ap_trnsmission_bdwidth_en;

/* BUG_7947 START */
typedef enum
{
    SA0 = 0,
    SA1,
    SA2,
    SA3,
    SA4,
    SA5,
    SA6
}x2ap_subframe_assn_et;

typedef enum
{
    SSP0 = 0,
    SSP2,
    SSP3,
    SSP4,
    SSP5,
    SSP6,
    SSP7,
    SSP8
}x2ap_special_subframe_patterns_et;
/* BUG_7947 STOP */

typedef enum
{
    NORMALL = 0,
    EXTENDED
}x2ap_cyclic_prefix_en;

/*SPR_6329 Start*/
typedef enum
{
    AN1 = 0,
    AN2 = 1,
    AN4=  2
}x2ap_num_antenna_port_et;
/*SPR_6329 Stop*/

typedef struct
{
    /* BUG_7947 START */
    UInt8                                 special_subframe_patterns; /*^ M,0,H,0,8 ^*/ /* x2ap_special_subframe_patterns_et */
    /* BUG_7947 STOP */
    UInt8                                 dl_cp; /*^ M,0,H,0,1 ^*/
    UInt8                                 ul_cp; /*^ M,0,H,0,1 ^*/
}x2ap_special_subframe_info_t;

typedef struct
{
    UInt32    nrscs; 
    /*^ M,0,N,0,0 ^*/
    UInt32    nrnrb;
    /*^ M,0,N,0,0 ^*/
}x2ap_nr_txbw_t;

typedef struct
{
    x2ap_earfcn_t ul_earfcn; /*^ M,0,N,0,0 ^*/
    x2ap_earfcn_t dl_earfcn; /*^ M,0,N,0,0 ^*/
    UInt8  ul_trnsmission_bdwidth; /*^ M,0,H,0,5 ^*/
    UInt8  dl_trnsmission_bdwidth; /*^ M,0,H,0,5 ^*/
}x2ap_fdd_info_t;

typedef struct
{
    x2ap_earfcn_t                earfcn;    /*^ M,0,N,0,0 ^*/
    UInt8                        trnsmission_bdwidth; /*^ M,0,H,0,5 ^*/
    /* BUG_7947 START */
    UInt8                        subframe_assn; /*^ M,0,H,0,6 ^*/ /* x2ap_subframe_assn_et */
    /* BUG_7947 STOP */
    x2ap_special_subframe_info_t special_subframe_info;     /*^ M,0,N,0,0 ^*/
}x2ap_tdd_info_t;

typedef struct 
{
    UInt8                           bitmask;   /*^ BITMASK ^*/
#define    X2AP_EUTRA_MODE_FDD   0x01
#define    X2AP_EUTRA_MODE_TDD   0x02
    x2ap_fdd_info_t     fdd_info;  /*^ O,X2AP_EUTRA_MODE_FDD,N,0,0 ^*/
    x2ap_tdd_info_t     tdd_info;  /*^ O,X2AP_EUTRA_MODE_TDD,N,0,0 ^*/
}x2ap_choice_eutra_mode_t;

typedef struct
{
    /* SPR_17664_start*/
    UInt8                     num_bcast_plmn_id;             /*^ M,0,B,1,MAX_NUM_BPLMN ^*/
    /* SPR_17664_end*/

    x2ap_plmn_identity_t  plmn_identity[MAX_NUM_BPLMN];  /*^ M,0,OCTET_STRING,VARIABLE ^*/
}x2ap_broadcast_plmn_t;


typedef struct
{
    x2ap_choice_eutra_mode_t    choice_eutra_mode;  /*^ M,0,N,0,0 ^*/
}x2ap_choice_eutra_mode_info_t;

typedef struct
{
    xnap_plmn_identity_t  plmn_identity;  /*^ M,0,N,0,0 ^*/
    UInt8                     eutran_cell_id[HOME_ENB_ID_OCTET_SIZE]; /*^ M,0,OCTET_STRING,FIXED ^*/
}xnap_ecgi_t;

typedef struct
{
    UInt32 earfcn; /*^ M,0,H,0,MAX_EARFCN ^*/
}xnap_earfcn_t;


typedef struct
{
    UInt8                bitmask;
    x2ap_ecgi_t      ecgi;   /*^ M,0,N,0,0 ^*/
    UInt32               pci;    /*^ M,0,N,0,0 ^*/
    x2ap_earfcn_t    earfcn; /*^ M,0,N,0,0 ^*/
}x2ap_neighbour_info_t;

typedef struct
{
    UInt8                bitmask;
    xnap_ecgi_t      ecgi;   /*^ M,0,N,0,0 ^*/
    UInt32               pci;    /*^ M,0,N,0,0 ^*/
    xnap_earfcn_t    earfcn; /*^ M,0,N,0,0 ^*/
}xnap_neighbour_info_t;


typedef struct
{
    x2ap_plmn_identity_t    plmn_id; /*^ M,0,N,0,0 ^*/
    UInt8                       mme_group_id[MAX_MME_GRP_BYTES]; /*^ M,0,OCTET_STRING,FIXED ^*/
}x2ap_gu_group_id_t;

typedef struct
{
    UInt16                         enb_neighbour_cell; /*^ M,0,H,0,MAX_NEIGHBOURS ^*/
    x2ap_neighbour_info_t       enb_neighbour_info[MAX_NEIGHBOURS]; /*^ M,0,OCTET_STRING,VARIABLE ^*/
    UInt16                         nr_neighbour_cell; /*^ M,0,H,0,MAX_NEIGHBOURS ^*/
    x2ap_neighbour_info_t       nr_neighbour_info[MAX_NEIGHBOURS]; /*^ M,0,OCTET_STRING,VARIABLE ^*/
}x2ap_nbour_cell_arry_t;
typedef struct
{
    /* SPR_17664_start*/
    UInt8                       num_gu_group_id;  /*^ M,0,H,0,MAX_ENB_POOLS^*/

    /* SPR_17664_end*/
    x2ap_gu_group_id_t      group_id_arr[MAX_ENB_POOLS]; /*^ M,0,OCTET_STRING,VARIABLE ^*/
}x2ap_gu_grp_ids_t;

typedef struct
{
#define X2AP_SUBFRAME_ALLOC_ONE_FRAME_INFO_PRESENT 0x01
#define X2AP_SUBFRAME_ALLOC_FOUR_FRAME_INFO_PRESENT 0x02
    UInt16 bitmask; /*^ BITMASK ^*/
    UInt8 oneframe[X2AP_SUBFRAME_ALLOC_ONE_FRAME_OCTET_SIZE]; /*^ O,X2AP_SUBFRAME_ALLOC_ONE_FRAME_INFO_PRESENT,OCTET_STRING,FIXED ^*/
    UInt8 fourframe[X2AP_SUBFRAME_ALLOC_FOUR_FRAME_OCTET_SIZE]; /*^ O,X2AP_SUBFRAME_ALLOC_FOUR_FRAME_INFO_PRESENT,OCTET_STRING,FIXED ^*/
}x2ap_subframe_allocation_t;

typedef struct
{
    UInt8 radioframe_alloc_period; /*^ M,0,H,0,5 ^*/
    UInt8 radioframe_alloc_offset; /*^ M,0,H,0,7 ^*/
    x2ap_subframe_allocation_t subframe_alloc; /*^ M,0,N,0,0 ^*/
}x2ap_mbsfn_info_t;

typedef struct
{
    /* SPR_17664_start*/
    UInt8 num_mbsfn; /*^ M,0,H,0,MAX_NUM_MBSFN ^*/

    /* SPR_17664_end*/
    x2ap_mbsfn_info_t mbsfn_info[MAX_NUM_MBSFN]; /*^ M,0,OCTET_STRING,VARIABLE ^*/
}x2ap_mbsfn_subframe_info_t;

typedef struct
{
#define X2AP_PRACH_CONFIG_INDEX_PRESENT 0x01
    UInt16 bitmask; /*^ BITMASK ^*/
    UInt16 root_sequence_index; /*^ M,0,H,0,837 ^*/
    UInt8 zero_correlation_zone_config; /*^ M,0,H,0,15 ^*/
    UInt8 high_speed_flag; /*^ M,0,H,0,1 ^*/
    UInt8 prach_frequency_offset; /*^ M,0,H,0,94 ^*/
    UInt8 prach_config_index;    /*^ O,X2AP_PRACH_CONFIG_INDEX_PRESENT,H,0,63 ^*/
}x2ap_prach_configuration_info_t;

typedef struct
{
    UInt8                                bitmask; /*^ BITMASK ^*/
    rrc_cell_index_t                     cell_id; /*^ M, 0, H, 0,MAX_CELL_INDEX ^*/    /* MAX_NUM_CELLS - 1 */
    x2_nr_cgi_t                          nr_cgi;  /*^ M,0,N,0,0 ^*/
}x2apOam_srvd_cell_info_t;

typedef struct
{
    x2apOam_srvd_cell_info_t      served_cell_info;     /*^ M,0,N,0,0 ^*/
    x2ap_nbour_cell_arry_t     nbour_cell_info;      /*^ M,0,N,0,0 ^*/
}x2apOam_srvd_cell_arry_t;

typedef struct
{
    UInt8                                bitmask; /*^ BITMASK ^*/
    UInt32                               pci; /*^ M,0,N,0,0 ^*/
    x2ap_ecgi_t                      cell_id; /*^ M,0,N,0,0 ^*/
    x2ap_tac_t                       track_area_code; /*^ M,0,N,0,0 ^*/
    x2ap_broadcast_plmn_t            broadcast_plmn_info; /*^ M,0,N,0,0 ^*/
    x2ap_choice_eutra_mode_info_t    choice_eutra_mode; /*^ M,0,N,0,0 ^*/
    /*SPR_6329 Start*/
    /*SPR_8176 Start*/
    /*SPR 13950 Fix Start  */
    UInt8                              num_antenna_port;  /*^O,NUM_ANTENNA_PORT_BITMASK,H,0,2 ^*/
    /*SPR 13950 Fix Stop  */
    /*SPR_8176 Stop*/
    /*SPR_6329 Stop*/
    x2ap_prach_configuration_info_t prach_config; /*^ O,X2AP_PRACH_CONFIG_INFO_PRESENT,N,0,0 ^*/
    x2ap_mbsfn_subframe_info_t mbsfn_subframe_info; /*^ O,X2AP_MBSFN_SUBFRAME_INFO_PRESENT,N,0,0 ^*/
    /*36423_CR0407_start*/
    UInt8    csg_identity[CSG_ID_OCTET_SIZE];/*^ O,X2AP_CSG_ID_INFO_PRESENT,OCTET_STRING,FIXED ^*/
    /*36423_CR0407_stop*/
}x2ap_srvd_cell_info_t;

typedef struct
{
    x2ap_srvd_cell_info_t      served_cell_info;     /*^ M,0,N,0,0 ^*/
    x2ap_nbour_cell_arry_t     nbour_cell_info;      /*^ M,0,N,0,0 ^*/
}x2ap_srvd_cell_arry_t;

typedef struct
{
    plmn_identity_t plmn_identity;/*^ M, 0, N, 0, 0 ^*/
    UInt8    cell_identity[4]; /*^ M, 0, OCTET_STRING, FIXED ^*/

}rrm_cell_global_id_eutra_t;

typedef struct
{
    plmn_identity_t       plmn_identity; /*^ M, 0, N, 0, 0 ^*/
    UInt8                                 tracking_area_code[2];   /*^ M, 0, OCTET_STRING, FIXED ^*/  
}rrm_tai_info_t;

typedef struct
{
    rrc_bitmask_t   bitmask;   /*^ BITMASK ^*/
#define EUTRAN_CELL_GLOBAL_IDENTITY_PRESENT   0x01

    plmn_identity_t plmn_identity;
    UInt8    cell_identity[4];
    /*^ M, 0, OCTET_STRING, FIXED ^*/ /* BIT STRING (SIZE (28)) */
    UInt8    ecgi[4];
    /*^ O, EUTRAN_CELL_GLOBAL_IDENTITY_PRESENT, OCTET_STRING, FIXED ^*/ /* BIT STRING (SIZE (28)) */
    UInt8    cell_type;    /*^ M, 0, B, 1, 2 ^*/ /* rrc_enb_id_et */
} eutra_globalEnb_ecgi_t;

typedef struct
{
    eutra_globalEnb_ecgi_t   global_enb_id; /*^ M, 0, N, 0, 0 ^*/
    rrm_tai_info_t           tracking_area_id ;    /*^ M, 0, N, 0, 0 ^*/
}rrm_enb_id_t ;

typedef struct
{
    UInt16                                bitmask; /*^ BITMASK ^*/
#define RRM_CGI_INFO_ROUTING_AREA_CODE                  0X01

    plmn_identity_t               plmn_identity; /*^ M, 0, N, 0, 0 ^*/
    UInt8                                 location_area_code[2]; /*^ M, 0, OCTET_STRING, FIXED ^*/
    UInt8                                 ci_info[2]; /*^ M, 0, OCTET_STRING, FIXED ^*/
    UInt8                                 routing_area_code;
    /*^ O, RRM_CGI_INFO_ROUTING_AREA_CODE, N, 0, 0 ^*/ 
}rrm_cgi_info_t;

/*CDMA2000_CSFB Start*/

typedef enum
{
    CELL_ID_NOT_INCLUDED_000 = 0,
    CELL_ID_1XRTT_001,
    CELL_ID_1XRTT_010,
    CELL_ID_1XRTT_011,
    CELL_ID_HRPD_100,
    CELL_ID_HRPD_101,
    CELL_ID_HRPD_110,
    CELL_ID_1XRTT_111
}cell_id_info_et;

typedef enum
{
    DELTAF_1 = 0,
    DELTAF0,
    DELTAF1,
    DELTAF2,
    DELTAF3,
    DELTAF4,
    DELTAF5,
    DELTAF6
}rrc_rrm_pucch_format3_et;

typedef enum
{
    DELTA_F1 = 0,
    DELTA_F2
}rrc_rrm_pucch_format1_bcs_et;

typedef struct
{
#define CDMA2000_1XRTT_CELL_ID_LENGTH 6
    /*BASEID: 2 OCTETS: cell id + sector id
SID: 15 bits (equiv to MarketId)
NID: 2 OCTET: equivalent to SWNO (switch number)
*/
    UInt8 cdma2000_1xrtt_cell_id[CDMA2000_1XRTT_CELL_ID_LENGTH];
    /*^ M,0,OCTET_STRING,FIXED ^*/
}cdma2000_1xrtt_cell_identifier_t;  /*(Ref:3GPP2 X.S0004-550-E v4.0,section 2.161)*/


typedef struct
{
#define MAX_SECTOR_ID_LENGTH 16
    /* SPR_17664_start*/
    UInt8 sector_id_length; /*^ M,0,B,16,MAX_SECTOR_ID_LENGTH ^*/

    /* SPR_17664_end*/
    UInt8 sector_id[MAX_SECTOR_ID_LENGTH]; /*^ M,0,OCTET_STRING,FIXED ^*/
}cdma2000_hrpd_sector_identifier_t; /*Ref:3GPP2 A.S0008-C v2.0,section 5.2.1.6*/
/*CDMA2000_CSFB Stop*/

/* CSR 00070260 Changes Start */
typedef struct
{
#define CDMA2000_1XRTT_REFERENCE_CELL_ID_LENGTH 5

    UInt8 cdma2000_1xrtt_ref_cell_id[CDMA2000_1XRTT_REFERENCE_CELL_ID_LENGTH];
    /*^ M,0,OCTET_STRING,FIXED ^*/
}cdma2000_1xrtt_ref_cell_identifier_t;


typedef struct
{
#define CDMA2000_HRPD_REFERENCE_SECTOR_ID_LENGTH 16

    UInt8 cdma2000_hrpd_ref_sector_id[CDMA2000_HRPD_REFERENCE_SECTOR_ID_LENGTH]; 
    /*^ M,0,OCTET_STRING,FIXED ^*/
}cdma2000_hrpd_ref_sector_identifier_t;
/* CSR 00070260 Changes Stop */

/*NGAP_BASED_HO_START*/
typedef struct 
{
    UInt8                   plmn_id_bytes[MAX_PLMN_ID_BYTES];
    /*^ M,0,OCTET_STRING,FIXED ^*/
}nr_plmn_identity_t;

typedef struct
{
    /* PLMN Identity */
    nr_plmn_identity_t      plmn_identity;

    /* TAC */
    UInt8                   tac[MAX_TAC_BYTES];
    /*^ M,0,OCTET_STRING,FIXED ^*/
}nr_tai_t;

typedef struct
{
    UInt8        count;                      /*^ M, 0, B, 2, MAX_MNC_OCTET_SIZE ^*/
    UInt8        mnc[MAX_MNC_OCTET_SIZE];    /*^ M, 0, OCTET_STRING, VARIABLE, H, 0, 9 ^*/
}rrc_mnc_t;


#define PLMN_IDENTITY_MCC_PRESENCE_FLAG     0x01
typedef struct _rrc_plmn_identity_t
{
    UInt16       presence_bitmask;       /*^ BITMASK ^*/
    UInt8        mcc[MCC_OCTET_SIZE];    /*^ O, 1, OCTET_STRING, FIXED, H, 0, 9 ^*/
    rrc_mnc_t     mnc;                    /*^ M, 0, N, 0, 0 ^*/
} rrc_plmn_identity_t;


typedef struct _rrc_nr_cell_identity_t
{
    UInt32 numbits;
    UInt8  data[5];
} rrc_nr_cell_identity_t;


typedef struct _rrc_ncgi_t 
{
    /* PLMN Identity */
    rrc_plmn_identity_t     plmn_identity;

    /* NR Cell Identity */
    rrc_nr_cell_identity_t  nr_cell_identity;

} rrc_ncgi_t;

/*NGAP_BASED_HO_STOP*/

typedef struct
{
#define RRC_RRM_TARGET_NR_CGI_INFO_PCI_PRESENT              0x01
#define RRC_RRM_TARGET_NR_CGI_INFO_CARRIER_FREQ_PRESENT     0x02
    /*NGAP_BASED_HO_START*/
#define RRC_RRM_TARGET_NR_CGI_INFO_CELL_INDEX_PRESENT       0x04
#define RRC_RRM_TARGET_NR_CGI_INFO_TAI_PRESENT              0x08
    /*NGAP_BASED_HO_STOP*/
    UInt16                     presence_bitmask;       /*^ BITMASK ^*/

    /*NGAP_BASED_HO_START*/
    rrc_cell_index_t           cell_index;
    /*^ O, RRC_RRM_TARGET_NR_CGI_INFO_CELL_INDEX_PRESENT, H, 0, MAX_CELL_INDEX ^*/

    nr_tai_t                   tai;
    /*^ O, RRC_RRM_TARGET_NR_CGI_INFO_TAI_PRESENT, N, 0, 0^*/
    /*NGAP_BASED_HO_START*/
    nr_global_cell_id_t        nr_cgi;
    /*^ M, 0, N, 0, 0 ^*/
    /* Intra du mobility code start */
    nr_pci_t                   pci;
    /*^ O, RRC_RRM_TARGET_NR_CGI_INFO_PCI_PRESENT, H, 0, 1007 ^*/
    UInt32                     carrier_freq;//SSB-Frequency
    /*^ O, RRC_RRM_TARGET_NR_CGI_INFO_CARRIER_FREQ_PRESENT, N, 0, 0 ^*/
    /* Intra du mobility code end */
}rrm_target_nr_cgi_info_t;


typedef struct
{
    UInt16                                bitmask; /*^ BITMASK ^*/   
#define RRM_TARGET_ID_ENB_ID_PRESENT   0X01
#define RRM_TARGET_ID_RNC_ID_PRESENT   0X02
#define RRM_TARGET_ID_CGI_PRESENT         0X04
#define RRM_TARGET_ID_CDMA2000_1XRTT_CELL_ID_PRESENT         0X08
#define RRM_TARGET_ID_CDMA2000_HRPD_SECTOR_ID_PRESENT         0X10
#define RRM_TARGET_ID_NR_CGI_INFO_PRESENT                     0x20

    rrm_enb_id_t                      enb_id; 
    /*^ O, RRM_TARGET_ID_ENB_ID_PRESENT, N, 0, 0 ^*/

    rrm_rnc_id_t                       rnc_id; 
    /*^ O, RRM_TARGET_ID_RNC_ID_PRESENT, N, 0, 0 ^*/

    rrm_cgi_info_t                     cgi; /*^ O, RRM_TARGET_ID_CGI_PRESENT, N, 0, 0 ^*/

    cdma2000_1xrtt_cell_identifier_t         cell_id_1xrtt; 
    /*^ O,RRM_TARGET_ID_CDMA2000_1XRTT_CELL_ID_PRESENT, N, 0, 0 ^*/

    cdma2000_hrpd_sector_identifier_t          sector_id_hrpd; 
    /*^ O,RRM_TARGET_ID_CDMA2000_HRPD_SECTOR_ID_PRESENT, N, 0, 0 ^*/

    rrm_target_nr_cgi_info_t                   nr_cgi_info;
    /*^ O, RRM_TARGET_ID_NR_CGI_INFO_PRESENT, N, 0, 0 ^*/

}rrm_target_id_t;

/*CDMA2000_CSFB_HO start*/
#define SIB8_NEW_SEG_GENERATE_THRESHOLD 100
#define W_F_SIB8_NEW_SEG_GENERATE 10

#define timespec_t struct timespec
typedef struct
{
    timespec_t timestamp;
    timespec_t cdma_time;
}sys_time_t;

typedef struct
{
    UInt16 num_of_elements;
    UInt16 sib8_sfn[MAX_SIB_INSTANCES];
}sib8_sfn_list_t;

/*CDMA2000_CSFB_HO stop*/

typedef struct
{
    UInt8 ip_addr[MAX_IP_ADDRESS_LENGTH]; /*^ M,0,OCTET_STRING,FIXED ^*/
}ip_addr_t;

/* IPV6 Start */
typedef struct
{
    UInt8 ipv6_addr[MAX_IPV6_ADDRESS_LENGTH];
    /*^ M,0,OCTET_STRING,FIXED ^*/
}ipv6_addr_t;

/* IPV6 Stop */

/*sctp parameters start*/

/* dscp_marking_start */
#define S1AP_OAM_DSCP_VALUE_PRESENT     0x01
/* dscp_marking_stop */
typedef struct
{
    UInt16  bitmask;/*^ BITMASK ^*/
    UInt32  init_max_attempts; /*^ M,0,N,0,0 ^*/
    UInt32  rto_initial; /*^ M,0,N,0,0 ^*/ 
    UInt32  rto_max; /*^ M,0,N,0,0 ^*/
    UInt32  rto_min; /*^ M,0,N,0,0 ^*/ 
    UInt16  assoc_max_retrans; /*^ M,0,N,0,0 ^*/ 
    UInt32     valid_cookie_life; /*^ M,0,N,0,0 ^*/ 
    UInt16  path_max_retrans; /*^ M,0,N,0,0 ^*/
    /* dscp_marking_start */
    UInt8   s1ap_dscp_value;
    /*^ O,S1AP_OAM_DSCP_VALUE_PRESENT, H, 0, 63 ^*/
    /* dscp_marking_stop */
}s1ap_sctp_conf_info_t;    

/*sctp parameters stop*/

/* IPV6 Start */
#define MME_COMM_INFO_IPV6_NUM_ADDR_PRESENT    0x01
#define MME_COMM_INFO_IPV6_ADDR_PRESENT        0x02
/* IPV6 Stop */
typedef struct
{
    /* number of ip addrs */
    /*SPR_17664_start */
    UInt8           num_ip_addr; /*^ M,0,H,0,MAX_NUM_IP_ADDR ^*/
    /*SPR_17664_end */

    /* ip addresses of MMEs */
    ip_addr_t  ip_addr[MAX_NUM_IP_ADDR]; /*^ M,0,OCTET_STRING,VARIABLE ^*/

    /* port of MME with which SCTP association needs to be initiated */
    UInt16       port;    /*^ M,0,N,0,0 ^*/

    /* num of streams to be setup between MME and enb */
    UInt16          num_streams; /*^ M,0,B,2,10 ^*/

    /* timer for SCTP connection recovery */
    UInt32          heart_beat_timer; /*^ M,0,N,0,0 ^*/

    /* release of MME (Rel8/Rel9/Rel10) */
    UInt8          rel_of_mme; /*^ M,0,H,0,2 ^*/ /* s1ap_oam_rel_of_mme_et */

    /* IPV6 Start */
    UInt16 bitmask; /*^ BITMASK ^*/
    /* IPV6 Stop */

    /* IPV6 Start */

    /* number of ipv6 addr */
    UInt8           num_ipv6_addr;
    /*SPR_17664_start */
    /*^ O,MME_COMM_INFO_IPV6_NUM_ADDR_PRESENT,B,1,MAX_NUM_IP_ADDR ^*/
    /*SPR_17664_end */
    /* IPV6 addresses of MMEs */
    ipv6_addr_t ipv6_addr[MAX_NUM_IP_ADDR];
    /*^ O,MME_COMM_INFO_IPV6_ADDR_PRESENT,OCTET_STRING,VARIABLE ^*/
    /* IPV6 Stop */
}mme_comm_info_t;

typedef struct
{
    UInt16 bitmask; /*^ BITMASK ^*/
    UInt8 ip_addr[IPV4_ADDRESS_LENGTH]; /*^ M,0,OCTET_STRING,FIXED ^*/
    UInt16 port; /*^ M,0,N,0,0 ^*/
} son_comm_info_t;

typedef struct
{
    rrc_bitmask_t         bitmask;                /*^ BITMASK ^*/
#define RRC_UE_INFO_MEAS_RESULT_RSRQ_PRESENT          0x01
    UInt8                    rsrp_result;
    /*^ M, 0, H, 0, 97 ^*/
    UInt8                    rsrq_result;
    /*^ O, RRC_UE_INFO_MEAS_RESULT_RSRQ_PRESENT, H, 0, 34 ^*/

}rrc_rlf_report_meas_result_serv_cell_t;

typedef struct
{
    plmn_identity_t plmn_identity;
    UInt8    cell_identity[4];
    /*^ M, 0, OCTET_STRING, FIXED ^*/ /* BIT STRING (SIZE (28)) */

} cell_global_id_eutra_t;

typedef struct
{
    UInt8    count;  /*^ M, 0, H, 0, 5 ^*/
    plmn_identity_t   cell_identity[5];   /*^ M, 0, OCTET_STRING, VARIABLE ^*/
}plmn_identity_list2_t;

typedef struct
{
    rrc_bitmask_t   bitmask;                              /*^ BITMASK ^*/

#define MEAS_RESULT_EUTRA_CGI_INFO_PLMN_IDENTITY_LIST_PRESENT   0x01

    cell_global_id_eutra_t    cell_global_id;
    UInt8    tracking_area_code[2];
    /*^ M, 0, OCTET_STRING, FIXED ^*/    /* BIT STRING (SIZE (16)) */

    plmn_identity_list2_t   plmn_identity_list;
    /*^ O, MEAS_RESULT_EUTRA_CGI_INFO_PLMN_IDENTITY_LIST_PRESENT ^*/

}meas_result_eutra_cgi_info_t;

typedef struct
{
    rrc_bitmask_t bitmask;                                /*^ BITMASK ^*/

#define MEAS_RESULT_EUTRA_MEAS_RESULT_RSRP_PRESENT      0x01
#define MEAS_RESULT_EUTRA_MEAS_RESULT_RSRQ_PRESENT      0x02

    UInt8    rsrp_result;
    /*^ O, MEAS_RESULT_EUTRA_MEAS_RESULT_RSRP_PRESENT, H, 0, 97 ^*/

    UInt8    rsrq_result;
    /*^ O, MEAS_RESULT_EUTRA_MEAS_RESULT_RSRQ_PRESENT, H, 0, 34 ^*/

}meas_result_eutra_meas_result_t;

typedef struct
{
    rrc_bitmask_t bitmask;                                /*^ BITMASK ^*/

#define MEAS_RESULT_EUTRA_MEAS_RESULT_CSG_MEM_STATUS_PRESENT    0x01
#define MEAS_RESULT_EUTRA_MEAS_RESULT_CSG_ID_PRESENT            0x02

    UInt8    csg_membershipStatus;
    /*^ O, MEAS_RESULT_EUTRA_MEAS_RESULT_CSG_MEM_STATUS_PRESENT, H, 0, 0 ^*/ /*rrc_csg_membership_status_et*/

    UInt8    csg_identity[CSG_ID_OCTET_SIZE]; /*^ O, MEAS_RESULT_EUTRA_MEAS_RESULT_CSG_ID_PRESENT, OCTET_STRING, FIXED ^*/

}meas_result_csg_info_t;

typedef struct
{
    rrc_bitmask_t   bitmask;                              /*^ BITMASK ^*/

#define MEAS_RESULT_EUTRA_CGI_INFO_PRESENT  0x01
#define MEAS_RESULT_EUTRA_CSG_INFO_PRESENT  0x02

    UInt16                               phys_cell_id;   /*^ M, 0, H, 0, 503 ^*/
    meas_result_eutra_cgi_info_t      cgi_info;
    /*^ O, MEAS_RESULT_EUTRA_CGI_INFO_PRESENT ^*/

    meas_result_eutra_meas_result_t   meas_result;

    meas_result_csg_info_t      eutra_csg_info;
    /*^ O, MEAS_RESULT_EUTRA_CSG_INFO_PRESENT ^*/
}meas_result_eutra_t;

typedef struct
{
    UInt8                    count;
    /* SPR_17664_start*/
    /*^ M, 0, H, 0, MAX_CELL_REPORT ^*/

    /* SPR_17664_end*/

    meas_result_eutra_t   meas_result_eutra[MAX_CELL_REPORT];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/

}meas_result_list_eutra_t;

typedef struct
{
    rrc_bitmask_t                 bitmask;                /*^ BITMASK ^*/
    UInt16                           carrier_freq;
    /*0..65535*/
    meas_result_list_eutra_t      meas_result_list_eutra;
    /*^ M, 0, N, 0, 0 ^*/
}rrc_meas_result2_eutra_t;

typedef struct
{
    UInt8                                count;     
    /* SPR_17664_start*/
    /*^ M, 0, B, 1, MAX_FREQ ^*/
    /* SPR_17664_end*/
    rrc_meas_result2_eutra_t          meas_result_eutra[MAX_FREQ];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/
} rrc_meas_result_list2_eutra_t;

typedef struct
{
    rrc_bitmask_t         bitmask;                /*^ BITMASK ^*/
#define MEAS_RESULT_UTRA_PHYS_CELL_ID_FDD_PRESENT   0x01
#define MEAS_RESULT_UTRA_PHYS_CELL_ID_TDD_PRESENT   0x02

    UInt16 fdd;  /*^ O, MEAS_RESULT_UTRA_PHYS_CELL_ID_FDD_PRESENT, H, 0, 511 ^*/
    UInt8 tdd;   /*^ O, MEAS_RESULT_UTRA_PHYS_CELL_ID_TDD_PRESENT, H, 0, 127 ^*/
}meas_result_utra_phys_cell_id_t;

typedef struct
{
    plmn_identity_t plmn_identity;
    UInt8    cell_identity[4]; /*^ M, 0, OCTET_STRING, FIXED ^*/   /* BIT STRING (SIZE (28)) */

}cell_global_id_utra_t;

typedef struct
{
    rrc_bitmask_t   bitmask;                              /*^ BITMASK ^*/

#define MEAS_RESULT_UTRA_CGI_INFO_PLMN_IDENTITY_LIST_PRESENT    0x01
#define MEAS_RESULT_UTRA_CGI_INFO_LOCATION_AREA_CODE_PRESENT    0x02
#define MEAS_RESULT_UTRA_CGI_INFO_ROUTING_AREA_CODE_PRESENT     0x04
    cell_global_id_utra_t    cell_global_id;
    UInt8    location_area_code[2];
    /*^ O, MEAS_RESULT_UTRA_CGI_INFO_LOCATION_AREA_CODE_PRESENT, OCTET_STRING, FIXED ^*/
    /* BIT STRING (SIZE (16)) */

    UInt8    routing_area_code;
    /*^ O, MEAS_RESULT_UTRA_CGI_INFO_ROUTING_AREA_CODE_PRESENT ^*/
    /* BIT STRING (SIZE (8)) */

    plmn_identity_list2_t   plmn_identity_list;
    /*^ O, MEAS_RESULT_UTRA_CGI_INFO_PLMN_IDENTITY_LIST_PRESENT ^*/

}meas_result_utra_cgi_info_t;

typedef struct
{
    rrc_bitmask_t bitmask;                                /*^ BITMASK ^*/

#define MEAS_RESULT_UTRA_MEAS_RESULT_RSCP_PRESENT      0x01
#define MEAS_RESULT_UTRA_MEAS_RESULT_ECN0_PRESENT      0x02

    SInt8    utra_rscp;
    /*^ O, MEAS_RESULT_UTRA_MEAS_RESULT_RSCP_PRESENT, B, -5, 91 ^*/

    UInt8    utra_ecn0;
    /*^ O, MEAS_RESULT_UTRA_MEAS_RESULT_ECN0_PRESENT, H, 0, 49 ^*/

}meas_result_utra_meas_result_t;

typedef struct
{
    rrc_bitmask_t   bitmask;                              /*^ BITMASK ^*/

#define MEAS_RESULT_UTRA_CGI_INFO_PRESENT   0x01
#define MEAS_RESULT_UTRA_CSG_INFO_PRESENT   0x02
    meas_result_utra_phys_cell_id_t   phys_cell_id;
    meas_result_utra_cgi_info_t       cgi_info;
    /*^ O, MEAS_RESULT_UTRA_CGI_INFO_PRESENT ^*/
    meas_result_csg_info_t            utra_csg_info;
    /*^ O, MEAS_RESULT_UTRA_CSG_INFO_PRESENT ^*/
    meas_result_utra_meas_result_t    meas_result;
}meas_result_utra_t;

typedef struct
{
    UInt8                    count;
    /* SPR_17664_start*/
    /*^ M, 0, H, 0, MAX_CELL_REPORT^*/
    /* SPR_17664_end*/
    meas_result_utra_t    meas_result_utra[MAX_CELL_REPORT];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/

}meas_result_list_utra_t;

typedef struct
{
    rrc_bitmask_t                bitmask;                /*^ BITMASK ^*/
    UInt16                          carrier_freq;
    /*^ M, 0, H, 0, 16383 ^*/
    meas_result_list_utra_t      meas_result_list_utra;
    /*^ M, 0, N, 0, 0 ^*/
}rrc_meas_result2_utra_t;

typedef struct
{
    UInt8         count;    
    /* SPR_17664_start*/
    /*^ M, 0, B, 1, MAX_FREQ ^*/
    /* SPR_17664_end*/
    rrc_meas_result2_utra_t       meas_result_utra[MAX_FREQ];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/
} rrc_meas_result_list2_utra_t;

typedef struct
{
    UInt16   arfcn;  /*^ M, 0, H, 0, 1023 ^*/
    UInt8    band_indicator;  /*^ M, 0, H, 0, 1 ^*/ /* rrc_rrm_carrier_freq_geran_band_indicator_et*/
}carrier_freq_geran_t;

typedef struct
{
    UInt8     network_colour_code; /*BIT STRING (SIZE (3))*/
    UInt8     base_station_colour_code; /*BIT STRING (SIZE (3))*/
}phys_cell_id_geran_t;

typedef struct
{
    plmn_identity_t plmn_identity;
    UInt8    location_area_code[2];
    /*^ M, 0, OCTET_STRING, FIXED ^*/  /* BIT STRING (SIZE (16)) */

    UInt8    cell_identity[2];
    /*^ M, 0, OCTET_STRING, FIXED ^*/  /* BIT STRING (SIZE (16)) */

}cell_global_id_geran_t;

typedef struct
{
    rrc_bitmask_t   bitmask;                              /*^ BITMASK ^*/

#define MEAS_RESULT_GERAN_CGI_INFO_ROUTING_AREA_CODE_PRESENT    0x01

    cell_global_id_geran_t    cell_global_id;
    UInt8    routing_area_code;
    /*^ O, MEAS_RESULT_GERAN_CGI_INFO_ROUTING_AREA_CODE_PRESENT ^*/
    /* BIT STRING (SIZE (8)) */

}meas_result_geran_cgi_info_t;

typedef struct
{
    UInt8    rssi;   /*^ M, MEAS_RESULT_UTRA_MEAS_RESULT_ECN0_PRESENT, H, 0, 63 ^*/
}meas_result_geran_meas_result_t;

typedef struct
{
    rrc_bitmask_t   bitmask;                              /*^ BITMASK ^*/

#define MEAS_RESULT_GERAN_CGI_INFO_PRESENT  0x01

    carrier_freq_geran_t  carrier_freq;
    phys_cell_id_geran_t  phys_cell_id;
    meas_result_geran_cgi_info_t      cgi_info;
    /*^ O, MEAS_RESULT_GERAN_CGI_INFO_PRESENT ^*/

    meas_result_geran_meas_result_t   meas_result;
}meas_result_geran_t;

typedef struct
{
    UInt8                    count;
    /*^ M, 0, H, 0, 8 ^*/

    meas_result_geran_t   meas_result_geran[MAX_CELL_REPORT];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/

}meas_result_list_geran_t;

typedef struct
{
    UInt8   band_class;     /*^ M, 0, H, 0, 31 ^*/ /* rrm_band_class_cdma2000_et */
    UInt16   arfcn;          /*^ M, 0, H, 0, 2047 ^*/
}carrier_freq_cdma2000_t;

typedef struct
{
    rrc_bitmask_t bitmask;                                /*^ BITMASK ^*/

#define CELL_GLOBAL_ID_CDMA2000_1XRTT_PRESENT       0x01
#define CELL_GLOBAL_ID_CDMA2000_HRPD_PRESENT        0x02

    UInt8    cell_global_id_1xrtt[6];
    /*^ O, CELL_GLOBAL_ID_CDMA2000_1XRTT_PRESENT, OCTET_STRING, FIXED ^*/
    /*BIT STRING (SIZE (47))*/

    UInt8    cell_global_id_hrpd[16];
    /*^ O, CELL_GLOBAL_ID_CDMA2000_HRPD_PRESENT, OCTET_STRING, FIXED ^*/
    /*BIT STRING (SIZE (128))*/

}cell_global_id_cdma2000_t;

typedef struct
{
    rrc_bitmask_t bitmask;                                /*^ BITMASK ^*/

#define MEAS_RESULT_CDMA2000_PILOT_PN_PHASE_PRESENT     0x01

    UInt16           pilot_pn_phase;
    /*^ O, MEAS_RESULT_CDMA2000_PILOT_PN_PHASE_PRESENT, H, 0, 32767 ^*/

    UInt8            pilot_strength;                         /*^ M, 0, H, 0, 63 ^*/
}meas_result_cdma2000_meas_result_t;

typedef struct
{
    rrc_bitmask_t   bitmask;                              /*^ BITMASK ^*/

#define MEAS_RESULT_CDMA2000_CGI_INFO_PRESENT   0x01

    UInt16                                   phy_cell_id;    /*^ M, 0, H, 0, 511 ^*/
    cell_global_id_cdma2000_t             cgi_info;
    /*^ O, MEAS_RESULT_CDMA2000_CGI_INFO_PRESENT ^*/

    meas_result_cdma2000_meas_result_t    meas_result;
}meas_result_cdma2000_t;

typedef struct
{
    UInt8                        count;
    /* SPR_17664_start*/
    /*^ M, 0, H, 0, MAX_CELL_REPORT ^*/
    /* SPR_17664_end*/
    meas_result_cdma2000_t    meas_result_cdma2000[MAX_CELL_REPORT];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/

}meas_result_list_cdma2000_t;

typedef struct
{
    UInt8                            pre_registration_status_hrpd;
    /*^ M, 0, H, 0, 1 ^*/ /* rrc_bool_et */

    meas_result_list_cdma2000_t   meas_result_list_cdma2000;
}meas_results_cdma2000_t;

typedef struct
{ 
    rrc_bitmask_t                 bitmask;                /*^ BITMASK ^*/
    carrier_freq_cdma2000_t       carrier_freq_cdma2000;
    /*^ M, 0, N, 0, 0 ^*/
    meas_results_cdma2000_t       meas_result_cdma2000;
    /*^ M, 0, N, 0, 0 ^*/
} rrc_meas_result2_cdma2000_t;

typedef struct
{
    UInt8                                 count;    
    /* SPR_17664_start*/
    /*^ M, 0, B, 1, MAX_FREQ ^*/
    /* SPR_17664_end*/
    rrc_meas_result2_cdma2000_t        meas_result_cdma2000[MAX_FREQ];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/
} meas_result_list2_cdma2000_t;

/* MeasResultServFreq-r10 changes start */
typedef struct
{
    UInt8    rsrp_result_r10;    /*^ M, 0, H, 0, 97 ^*/
    UInt8    rsrq_result_r10;    /*^ M, 0, H, 0, 34 ^*/
}meas_result_attr_t;

typedef struct
{
    UInt16                               phys_cell_id_r10;         /*^ M, 0, H, 0, 1007 ^*/
    meas_result_attr_t                best_neigh_cell_r10;          
}meas_result_best_neigh_cell_r10_t;

typedef struct 
{
    rrc_bitmask_t                   bitmask;                 /*^ BITMASK ^*/ 

#define RRM_MEAS_RESULT_SCELL_PRESENT                   0x01
#define RRM_MEAS_RESULT_BEST_NEIGH_CELL_PRESENT         0x02

    UInt8                              serv_cell_index_r10;    /*^ M, 0, H, 0, MAX_CELL_INDEX ^*/
    meas_result_attr_t              meas_result_scell_r10;
    /*^ O, RRM_MEAS_RESULT_SCELL_PRESENT ^*/

    meas_result_best_neigh_cell_r10_t   meas_result_best_neigh_cell_r10;
    /*^ O, RRM_MEAS_RESULT_BEST_NEIGH_CELL_PRESENT ^*/

}rrc_meas_result_serv_freq_r10_t;

typedef struct 
{
    /* SPR-18445 start */
    UInt8                               count;
    /*^ M, 0, H, 0, MAX_SERVING_CELL ^*/
    /* SPR-18445 stop */

    rrc_meas_result_serv_freq_r10_t     rrc_meas_result_serv_freq_r10[MAX_SERVING_CELL];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/

}rrc_meas_result_serv_freq_list_r10_t;
/* MeasResultServFreq-r10 changes stop */

typedef struct
{
    rrc_bitmask_t         bitmask;                /*^ BITMASK ^*/
#define RRC_UE_INFO_MEAS_RESULT_LIST_EUTRA_PRESENT          0x01
#define RRC_UE_INFO_MEAS_RESULT_LIST_UTRA_PRESENT           0x02
#define RRC_UE_INFO_MEAS_RESULT_LIST_GERAN_PRESENT          0x04
#define RRC_UE_INFO_MEAS_RESULT_LIST_CDMA2000_PRESENT       0x08
    rrc_meas_result_list2_eutra_t        meas_result_list_eutra;
    /*^ O, RRC_UE_INFO_MEAS_RESULT_LIST_EUTRA_PRESENT ^*/
    rrc_meas_result_list2_utra_t         meas_result_list_utra;
    /*^ O, RRC_UE_INFO_MEAS_RESULT_LIST_UTRA_PRESENT ^*/
    meas_result_list_geran_t             meas_result_list_geran;
    /*^ O, RRC_UE_INFO_MEAS_RESULT_LIST_GERAN_PRESENT ^*/
    meas_result_list2_cdma2000_t         meas_result_list2_cdma2000;
    /*^ O, RRC_UE_INFO_MEAS_RESULT_LIST_CDMA2000_PRESENT ^*/
}rrc_rlf_report_meas_result_neigh_cell_t;


typedef struct
{
    UInt8     data_length; /*^ M, 0, H, 0, 64  ^*/

    UInt8     data[64];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/
}rrc_rlf_dynamic_string_t;

typedef struct
{
    rrc_phys_cell_id_t  phys_cell_id;       /*^ M, 0, H, 0, 1007 ^*/
    UInt16                 carrier_freq;
    /*0..65535*/
}rrc_rlf_failed_pci_arfcn_t;


typedef struct
{
    rrc_bitmask_t                                       bitmask; /*^ BITMASK ^*/
#define RRC_RLF_FAILED_PCI_CELL_GLOBAL_ID_PRESENT          0x01
#define RRC_RLF_FAILED_PCI_ARFCN_PRESENT                   0x02
    rrm_cell_global_id_eutra_t                cell_global_id;
    /*^ O, RRC_RLF_FAILED_PCI_CELL_GLOBAL_ID_PRESENT ^*/
    rrc_rlf_failed_pci_arfcn_t            pci_arfcn;
    /*^ O, RRC_RLF_FAILED_PCI_ARFCN_PRESENT ^*/
}rrc_rlf_failed_pcellid_t;

typedef struct
{
    rrc_bitmask_t                                       bitmask; /*^ BITMASK ^*/
#define RRC_RLF_LOCATION_CORD_ELLIPSOID_POINT_PRESENT                   0x01
#define RRC_RLF_LOCATION_CORD_ELLIPSOID_POINT_ALTITUDE_PRESENT          0x02
    rrc_rlf_dynamic_string_t ellipsoid_point;
    /*^ O, RRC_RLF_LOCATION_CORD_ELLIPSOID_POINT_PRESENT ^*/
    rrc_rlf_dynamic_string_t ellipsoid_point_altitude;
    /*^ O, RRC_RLF_LOCATION_CORD_ELLIPSOID_POINT_ALTITUDE_PRESENT ^*/
}rrc_rlf_report_location_coordinates_t;

typedef struct
{
    rrc_bitmask_t                                       bitmask; /*^ BITMASK ^*/
#define RRC_RLF_LOCATION_INFO_HORIZON_VELOCITY_PRESENT          0x01
#define RRC_RLF_LOCATION_INFO_GNSS_TOD_MSEC_PRESENT             0x02
    rrc_rlf_report_location_coordinates_t location_coordiate;
    rrc_rlf_dynamic_string_t              horizontal_velocity;
    /*^ O, RRC_RLF_LOCATION_INFO_HORIZON_VELOCITY_PRESENT ^*/
    rrc_rlf_dynamic_string_t              gnss_tod_msec;
    /*^ O, RRC_RLF_LOCATION_INFO_GNSS_TOD_MSEC_PRESENT ^*/

}rrc_rlf_report_location_info_t;


typedef struct
{
    rrc_bitmask_t                                       bitmask; /*^ BITMASK ^*/
#define RRC_UE_INFO_MEAS_RESULT_NEIGH_CELLS_PRESENT          0x01
#define RRC_UE_INFO_REESTABLISMENT_CELLID_R10_PRESENT        0x02
#define RRC_UE_INFO_TIME_CONN_FAILURE_R10_PRESENT            0x04
#define RRC_UE_INFO_CONN_FAILURE_TYPE_R10_PRESENT            0x08
#define RRC_UE_INFO_RLF_REPORT_LOACTION_INFO_PRESENT         0x10
#define RRC_UE_INFO_FAILED_PCELLID_PRESENT                   0x20
#define RRC_UE_INFO_REESTABLISHMENT_CELLID_PRESENT           0x40
#define RRC_UE_INFO_TIME_CONN_FALURE_PRESENT                 0x80
#define RRC_UE_INFO_CONN_FALURE_TYPE_PRESENT                 0x100
#define RRC_UE_INFO_PREV_PCELLID_PRESENT                     0x200
    rrc_rlf_report_meas_result_serv_cell_t              meas_result_serv_cell;
    /*^ M, 0, N, 0, 0 ^*/
    rrc_rlf_report_meas_result_neigh_cell_t             meas_result_neigh_cell;
    /*^ O, RRC_UE_INFO_MEAS_RESULT_NEIGH_CELLS_PRESENT ^*/
    rrm_cell_global_id_eutra_t                          reestablishment_cellid_r10;
    /*^ O, RRC_UE_INFO_REESTABLISMENT_CELLID_R10_PRESENT ^*/
    UInt16                                                 time_conn_failure_r10;
    /*^ O, RRC_UE_INFO_TIME_CONN_FAILURE_R10_PRESENT ^*/
    UInt32                                                 connection_failure_type_r10;
    /*^ O, RRC_UE_INFO_CONN_FAILURE_TYPE_R10_PRESENT ^*/
    rrc_rlf_report_location_info_t                      location_info;
    /*^ O, RRC_UE_INFO_RLF_REPORT_LOACTION_INFO_PRESENT ^*/
    rrc_rlf_failed_pcellid_t              failed_pcellid;
    /*^ O, RRC_UE_INFO_FAILED_PCELLID_PRESENT ^*/
    rrm_cell_global_id_eutra_t               reestablish_cell_id;
    /*^ O, RRC_UE_INFO_REESTABLISHMENT_CELLID_PRESENT ^*/
    UInt16                                   time_conn_failure;
    /*^ O, RRC_UE_INFO_TIME_CONN_FALURE_PRESENT ^*/
    UInt32                                   conn_failure_type;
    /*^ O, RRC_UE_INFO_CONN_FALURE_TYPE_PRESENT ^*/
    rrm_cell_global_id_eutra_t            previous_pcell_id;
    /*^ O, RRC_UE_INFO_PREV_PCELLID_PRESENT ^*/
}rrc_rlf_report_t;

#define MAX_EXT_MODULES 9
#define MAX_LEN_COMM_INFO   22
/*SPR 22554 Fix Start*/
#define MAX_THREAD_NAME_LEN 20
/*SPR 22554 Fix End*/

typedef struct
{
    UInt8 mmegi[MMEGI_OCTET_SIZE];   /*^ M, 0, OCTET_STRING, FIXED ^*/
}s1ap_served_group_id_t;

typedef struct
{
    UInt8    mmec;   /*^ M,0,N,0,0 ^*/
}s1ap_served_mmec_t;

typedef struct
{
    /* SPR_17664_start*/
    UInt8                      num_served_plmns;  /*^ M,0,B,1,MAX_NUM_SERVED_PLMN ^*/
    /* SPR_17664_end*/
    s1ap_plmn_identity_t    plmn_identity [MAX_NUM_SERVED_PLMN];/*^ M,0,OCTET_STRING,VARIABLE ^*/


    /* SPR_17664_start*/
    UInt16                     num_served_group_ids; /*^ M,0,B,1,MAX_NUM_SERVED_GROUP_ID ^*/
    /* SPR_17664_end*/
    s1ap_served_group_id_t  served_group_id [MAX_NUM_SERVED_GROUP_ID];/*^ M,0,OCTET_STRING,VARIABLE ^*/

    /* SPR_17664_start*/
    UInt16                      num_served_mmecs;/*^ M,0,B,1,MAX_NUM_SERVED_MMEC ^*/
    /* SPR_17664_end*/
    s1ap_served_mmec_t      served_mmec [MAX_NUM_SERVED_MMEC];/*^ M,0,OCTET_STRING,VARIABLE ^*/

}s1ap_served_gummei_info_t;

typedef struct
{
#define S1AP_MME_NAME_PRESENT                  0x01
#define S1AP_SERVED_GUMMEI_INFO_PRESENT        0x02
#define S1AP_RELATIVE_MME_CAPACITY_PRESENT     0x04
    rrc_bitmask_t               bitmask;   /*^ BITMASK ^*/

    UInt8                          mme_name[MAX_MME_NAME];
    /*^ O, S1AP_MME_NAME_PRESENT, OCTET_STRING, FIXED ^*/   

    s1ap_served_gummei_info_t      served_gummei_info;
    /*^ O, S1AP_SERVED_GUMMEI_INFO_PRESENT, N, 0, 0 ^*/   

    UInt8                          relative_mme_capacity; 
    /*^ O, S1AP_RELATIVE_MME_CAPACITY_PRESENT, N, 0, 0 ^*/

}s1ap_mme_info_t;

#define RRC_ONE                  1
#define MAX_UE_XWAP_ID_BYTES     3
#define MAX_SSID_BYTES           32
#define MAX_BSSID_BYTES          6
#define MAX_HESSID_BYTES         6


/* Structure for storing UE XWAP Id value */
typedef struct
{
    /* Number of octets */
    UInt8   numocts;

    /* XWAP ID value */
    UInt8   xwapId[MAX_UE_XWAP_ID_BYTES];

}ue_xwap_id_t;

typedef struct 
{
    UInt8     numOctets;
    /*^ M, 0, B, 1, MAX_SSID_BYTES ^*/

    UInt8     data[MAX_SSID_BYTES];
    /*^ M, 0, OCTET_STRING, FIXED ^*/

}wlan_identifier_ssid_t;

typedef struct
{
    rrc_bitmask_t    bitmask;        /*^ BITMASK ^*/

#define WLAN_ID_SSID_PRESENT          0x01
#define WLAN_ID_BSSID_PRESENT         0x02
#define WLAN_ID_HESSID_PRESENT        0x04

    wlan_identifier_ssid_t    ssid;
    /*^ O, WLAN_ID_SSID_PRESENT ^*/

    UInt8                        bssid[MAX_BSSID_BYTES];
    /*^ O, WLAN_ID_BSSID_PRESENT, OCTET_STRING, FIXED ^*/

    UInt8                        hessid[MAX_HESSID_BYTES];
    /*^ O, WLAN_ID_HESSID_PRESENT, OCTET_STRING, FIXED ^*/

}wlan_identifier_t;

#define MAX_WLAN_ID      2 

/* COV_113081_Fix_Start */
#define SHORT_WT_ID_LEN  4
#define LONG_WT_ID_LEN   6
/* COV_113081_Fix_End */

/* Values for WT identifier type */
typedef enum
{
    WT_ID_TYPE_1,
    WT_ID_TYPE_2
}wt_identifier_type_et;

#define WT_IDENTIFIER_SHORT_WT_ID_PRESENT  0x01
#define WT_IDENTIFIER_LONG_WT_ID_PRESENT   0x02


/* WT Identifier */
typedef struct _wt_identifier_t
{
    rrc_bitmask_t      bitmask;    /*^ BITMASK ^*/

    UInt8                 plmn_id[MAX_PLMN_ID_BYTES];
    /*^ O, WT_IDENTIFIER_SHORT_WT_ID_PRESENT, OCTET_STRING, FIXED ^*/

    UInt8                 short_wt_id[SHORT_WT_ID_LEN];
    /*^ O, WT_IDENTIFIER_SHORT_WT_ID_PRESENT, OCTET_STRING, FIXED ^*/

    UInt8                 long_wt_id[LONG_WT_ID_LEN];
    /*^ O, WT_IDENTIFIER_LONG_WT_ID_PRESENT, OCTET_STRING, FIXED ^*/

}wt_identifier_t;

/* WT supported WLAN identifier list */
typedef struct _wlan_identifier_list_t
{
    UInt16                count;
    /*^ M, 0, H, 0, MAX_WLAN_ID ^*/

    wlan_identifier_t  supported_wlan_id[MAX_WLAN_ID];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/

}wlan_identifier_list_t;

/* Structure for storing connected WT data */
typedef struct _xwap_wt_info_t
{
    wt_identifier_t           wt_id;
    /*^ M, 0, N, 0, 0 ^*/

    wlan_identifier_list_t    wlan_identifier_list;
    /*^ M, 0, N, 0, 0 ^*/
    /* COV_113071_Fix_Start */
    UInt8                        link_status;
    /*^ M, 0, H, 0, 1 ^*/
    /* COV_113071_Fix_End */

}xwap_wt_info_t;


typedef enum
{
    RRM_ERAB_RECONFIG_FAIL,
    RRM_ERAB_RECONFIG_FAIL_WT_ADD,
    RRM_ERAB_RECONFIG_FAIL_WT_ASSOC,
    RRM_ERAB_RECONFIG_FAIL_RRC_RECONFIG,
    RRM_ERAB_RECONFIG_FAIL_UE_REL,
    RRM_ERAB_RECONFIG_FAIL_ENB_UE_REL,
    RRM_ERAB_RECONFIG_FAIL_CELL_DEL,
    RRM_ERAB_RECONFIG_FAIL_RLF,
    RRM_ERAB_RECONFIG_FAIL_HO,
    RRM_ERAB_RECONFIG_FAIL_S1AP_RESET,
    RRM_ERAB_RECONFIG_FAIL_RE_ESTABLISH,
    RRM_ERAB_RECONFIG_FAIL_MAX
}rrm_erab_reconfig_fail_cause_et;

typedef struct _drb_countMSB_info_t
{
    UInt16           bitmask; /*^ BITMASK ^*/
    UInt8            drb_Identity; /*^ M, 0, B, 1, 32 ^*/
    UInt32           countMSB_Uplink; /*^ M, 0, H, 0, 33554431 ^*/
    UInt32           countMSB_Downlink; /*^ M, 0, H, 0, 33554431 ^*/
}drb_countMSB_info_t;

typedef struct _drb_countMSB_info_list_t
{
    /* SPR_17664_start*/
    UInt8                         drb_count;    /*^ M, 0, B, 1, MAX_LC_COUNT ^*/
    /* SPR_17664_end*/
    drb_countMSB_info_t        drb_countMSB_info[MAX_LC_COUNT];  /*^ M,0,OCTET_STRING,VARIABLE ^*/  
}drb_countMSB_info_list_t;

typedef struct _drb_count_info_t
{
    UInt16           bitmask; /*^ BITMASK ^*/
    UInt8            drb_Identity; /*^ M, 0, B, 1, 32 ^*/
    UInt32           count_Uplink; /*^ M, 0, N, 0, 0 ^*/
    UInt32           count_Downlink; /*^ M, 0, N, 0, 0 ^*/
}drb_count_info_t;

typedef struct _drb_count_info_list_t
{
    /* SPR_17664_start*/
    UInt8                         drb_count;    /*^ M, 0, H, 0, MAX_LC_COUNT ^*/
    /* SPR_17664_end*/
    drb_count_info_t           drb_count_info[MAX_LC_COUNT];  /*^ M,0,OCTET_STRING,VARIABLE ^*/  
}drb_count_info_list_t;

typedef struct _drb_list_t
{
    /* SPR_17664_start*/
    UInt8                         drb_count;    /*^ M, 0, B, 1, MAX_LC_COUNT ^*/
    /* SPR_17664_end*/
    UInt8                         drb_Identity[MAX_LC_COUNT];
    /*^ M, 0, OCTET_STRING, VARIABLE, B, 1, 32^*/
}drb_list_t;

/*SPR 22572 changes start*/
/*code removed*/
/*SPR 22572 changes end*/

/*sctp parameters start*/
typedef struct
{
    UInt32 tv_sec;  /*^ M,0,N,0,0 ^*/
    UInt32 tv_usec; /*^ M,0,N,0,0 ^*/
}rrc_timeval_t;
/*sctp parameters stop*/

typedef struct
{
    rrc_phys_cell_id_t  phy_cell_id;
    /*^ M, 0, H, 0, 1007 ^*/

    UInt32   dl_carrier_freq;             
    /*^ M, 0, N, 0, 0 ^*/

} rrc_scell_Identification_t;

typedef struct
{
    rrc_bitmask_t              bitmask;     /*^ BITMASK ^*/
#define RRM_SCELL_CQI_REPORT_CONFIG_APERIODIC_PRESENT          0x01
#define RRM_SCELL_CQI_REPORT_CONFIG_PERIODIC_PRESENT           0x02
#define RRM_SCELL_CQI_REPORT_CONFIG_PMI_RI_REPORT_PRESENT      0x04

    UInt8  cqi_reporting_mode_aperiodic;
    /*^ O, RRM_SCELL_CQI_REPORT_CONFIG_APERIODIC_PRESENT, H, 0, 4 ^*/ /* cqi_reporting_mode_aperiodic_et */

    SInt8  nomPDSCH_RS_EPRE_Offset;
    /*^ M, 0, B, -1, 6 ^*/ 

    rrc_phy_cqi_report_periodic_r10_t    cqi_report_periodic_r10;
    /*^ O, RRM_SCELL_CQI_REPORT_CONFIG_PERIODIC_PRESENT, N, 0, 0 ^*/

    UInt8    cqi_report_pmi_ri_report_r10;
    /*^ O, RRM_SCELL_CQI_REPORT_CONFIG_PMI_RI_REPORT_PRESENT, H, 0, 0 ^*/

} rrc_cqi_report_config_scell_r10_t;

typedef struct
{
    UInt16                                bitmask; /*^ BITMASK ^*/
#define CANDIDATE_CELL_INFO_RSRP_PRESENT 0x01
#define CANDIDATE_CELL_INFO_RSRQ_PRESENT 0x02

    rrc_phys_cell_id_t        phy_cell_id; 
    /*^ M, 0, H, 0, 1007 ^*/
    UInt16                    carrier_freq; 
    /*^ M, 0, N, 0, 0 ^*/
    UInt8                     rsrp_result;    
    /*^ O, CANDIDATE_CELL_INFO_RSRP_PRESENT, H, 0, 97 ^*/
    UInt8                     rsrq_result;    
    /*^ O, CANDIDATE_CELL_INFO_RSRQ_PRESENT, H, 0, 34 ^*/
}candidate_cell_info_t;

typedef struct
{
    /* SPR-18445 start */
    UInt8 count; /*^ M, 0, B, 1, MAX_FREQ ^*/
    /* SPR-18445 stop */
    candidate_cell_info_t candidate_cell_info[MAX_FREQ]; 
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/
} candidate_cell_info_list_t;

typedef struct
{
    UInt16                                bitmask; /*^ BITMASK ^*/
#define RRM_CONFIG_EXT_CANDIDATE_CELL_INFO_LIST_PRESENT       0x01

    candidate_cell_info_list_t  candidate_cell_info_list; 
    /*^ O, RRM_CONFIG_EXT_CANDIDATE_CELL_INFO_LIST_PRESENT, N, 0, 0 ^*/

}rrm_config_t;
typedef struct
{
    rrc_bitmask_t              bitmask;     /*^ BITMASK ^*/
#define RRM_SCELL_DEDICATED_UL_CQI_CONFIG_SCELL_PRESENT          0x01

    rrc_cqi_report_config_scell_r10_t         cqi_report_config_scell;
    /*^ O, RRM_SCELL_DEDICATED_UL_CQI_CONFIG_SCELL_PRESENT ^*/

}rrc_radio_res_dedicated_scell_ul_config_t;

typedef struct
{
    rrc_bitmask_t              bitmask;     /*^ BITMASK ^*/
#define RRM_SCELL_DEDICATED_NON_UL_ANTENNA_INFO_PRESENT                           0x01
#define RRM_SCELL_DEDICATED_NON_UL_PDSCH_CONFIG_DEDICATED_PRESENT                 0x02

    rrc_antenna_info_dedicated_r10_t         antenna_info_dedicated_r10;
    /*^ O, RRM_SCELL_DEDICATED_NON_UL_ANTENNA_INFO_PRESENT ^*/

    rrc_phy_pdsch_configuration_dedicated_t     pdsch_configuration_dedicated;
    /*^ O, RRM_SCELL_DEDICATED_NON_UL_PDSCH_CONFIG_DEDICATED_PRESENT ^*/

}rrc_radio_res_dedicated_scell_non_ul_config_t;

typedef struct
{
    rrc_bitmask_t              bitmask;     /*^ BITMASK ^*/
#define RRM_RADIO_RES_CONFIG_DEDICATED_SCELL_NON_UL_CONFIG_PRESENT           0x01
#define RRM_RADIO_RES_CONFIG_DEDICATED_SCELL_UL_CONFIG_PRESENT               0x02

    rrc_radio_res_dedicated_scell_non_ul_config_t  radio_res_dedicated_scell_non_ul_config;             
    /*^ O, RRM_RADIO_RES_CONFIG_DEDICATED_SCELL_NON_UL_CONFIG_PRESENT, N, 0, 0 ^*/

    rrc_radio_res_dedicated_scell_ul_config_t  radio_res_dedicated_scell_ul_config;             
    /*^ O, RRM_RADIO_RES_CONFIG_DEDICATED_SCELL_UL_CONFIG_PRESENT, N, 0, 0 ^*/

}rrc_physical_config_dedicated_scell_t;

typedef struct
{
    rrc_bitmask_t              bitmask;     /*^ BITMASK ^*/
#define RRM_PHYSICAL_CONFIG_DEDICATED_SCELL_CONFIG_PRESENT      0x01

    rrc_physical_config_dedicated_scell_t     physical_config_dedicated_scell;
    /*^ O , RRM_PHYSICAL_CONFIG_DEDICATED_SCELL_CONFIG_PRESENT, N, 0, 0 ^*/
}rrc_radio_res_config_dedicated_scell_t;

typedef struct _rrc_mac_ue_category_v1020_t
{
    UInt8   ue_category_v1020; /*^ M, 0, B, 6, 8 ^*/
}rrc_mac_ue_category_v1020_t;

typedef struct _rrc_mac_n1pucch_an_cs_r10_t
{
    UInt16   rrc_mac_n1pucch_an_cs; /*^ M, 0, H, 0, 2047 ^*/
}rrc_mac_n1pucch_an_cs_r10_t;

typedef struct _rrc_mac_n1pucch_an_cs_list_r10_t
{
    rrc_counter_t           count;
    /*^ M, 0, TLV_SEQUENCE_COUNTER, NOT_PRESENT_IN_MESSAGE ^*/

    rrc_mac_n1pucch_an_cs_r10_t    rrc_mac_n1pucch_an_cs_r10[MAX_N1PUCCH_AN_CS];
    /*^ TLV, SEQUENCE, RRC_MAC_PUCCH_AN_CS_V1020 ^*/
}rrc_mac_n1pucch_an_cs_list_r10_t;

typedef struct _rrc_mac_pucch_channel_selection_config_v1020_t
{
    rrc_bitmask_t           optional_elems_present;
    /*^ M, 0, BITMASK, NOT_PRESENT_IN_MESSAGE ^*/


    UInt8  request_type;                               /*^ M, 0, H, 0, 1 ^*/

    rrc_counter_t           count;
    /*^ M, 0, TLV_SEQUENCE_COUNTER, NOT_PRESENT_IN_MESSAGE ^*/
    rrc_mac_n1pucch_an_cs_list_r10_t                    rrc_mac_n1pucch_an_cs_list_r10[MAX_N1PUCCH_AN_CS_LIST];
    /*^ TLV, SEQUENCE, RRC_MAC_N1PUCCH_AN_CS_LIST_R10 ^*/

}rrc_mac_pucch_channel_selection_config_v1020_t;

#define RRC_MAC_PUCCH_CHANNEL_SELECTION_CONFIG_V1020_PRESENT 0x01
typedef struct _rrc_mac_pucch_format_r10_t
{
    rrc_bitmask_t           optional_elems_present;
    /*^ M, 0, BITMASK, NOT_PRESENT_IN_MESSAGE ^*/

    rrc_mac_pucch_channel_selection_config_v1020_t     rrc_mac_pucch_channel_selection_config_v1020;
    /*^ TLV, RRC_MAC_PUCCH_CHANNEL_SELECTION_CONFIG_V1020, RRC_MAC_PUCCH_CHANNEL_SELECTION_CONFIG_V1020_PRESENT ^*/
}rrc_mac_pucch_format_r10_t;

#define RRC_MAC_MIMO_DL_TWO_LAYERS 2
#define RRC_MAC_MIMO_DL_FOUR_LAYERS 4
typedef struct _rrc_mac_supported_mimo_capability_dl_r10_t
{
    UInt8   num_Of_layer;  /*^ M, 0, B, 1, 4 ^*/
}rrc_mac_supported_mimo_capability_dl_r10_t;


typedef struct _rrc_mac_codebook_subset_restriction_v1020_t
{
    UInt8        cbsr_type;    /*^ M, 0, H, 0, 9 ^*/ /* codebook_subset_restriction_v1020_type_et */
    UInt8        cbsr_value[CBSR_MAX_VALUE_V1020]; /*^ M, O, OCTET_STRING, FIXED ^*/
}rrc_mac_codebook_subset_restriction_v1020_t;

typedef struct
{
    UInt8                           servCellIndex;
    /*^ M, 0, H, 0, 7 ^*/

    UInt8                           pdsch_start;
    /*^ M, 0, B, 1, 4 ^*/

} rrc_cross_carrier_scheduling_cell_info_other_t;

typedef struct
{
    UInt8  antenna_port_count_r10;
    /*^ M, 0, H, 0, 3 ^*/ /* rrc_rrm_csi_rs_r10_antennaPortCount_et */

    UInt8  resource_config;
    /*^ M, 0, H, 0, 31 ^*/ 

    UInt8  subframe_config;
    /*^ M, 0, H, 0, 154 ^*/ 

    SInt8  p_C; 
    /*^ M, 0, B, -8, 15 ^*/ 

} rrc_csi_rs_r10_setup_t;

typedef struct
{
    UInt8  zeroTxPowerTesource_configList[2];
    /*^ M, 0, OCTET_STRING, FIXED ^*/

    UInt8 zeroTxPowerSubframeConfig; 
    /*^ M, 0, H, 0, 154 ^*/ 

} rrc_zeroTxPowerCsi_setup_t;

typedef struct
{
    rrc_bitmask_t bitmask;    /*^ BITMASK ^*/
#define RRC_MAC_MAIN_CONFIG_V1020_SCELL_DEACTIVATION_TIMER_PRESENT    0x01
#define RRC_MAC_MAIN_CONFIG_V1020_EXTENDED_BSR_SIZES_PRESENT          0x02
#define RRC_MAC_MAIN_CONFIG_V1020_EXTENDED_PHR_PRESENT                0x04

    UInt8  scell_deactivation_timer;
    /*^ O, RRC_MAC_MAIN_CONFIG_V1020_SCELL_DEACTIVATION_TIMER_PRESENT, N, 0, 0 ^*/  /* scell_deactivation_timer_et */

    UInt8   extended_bsr_sizes;
    /*^ O, RRC_MAC_MAIN_CONFIG_V1020_EXTENDED_BSR_SIZES_PRESENT, H, 0, 0 ^*/  /* extended_bsr_sizes_et */

    UInt8   extended_phr;
    /*^ O, RRC_MAC_MAIN_CONFIG_V1020_EXTENDED_PHR_PRESENT, H, 0, 0 ^*/  /* extended_phr_et */

} rrc_mac_main_config_v1020_t;



typedef struct _uplink_power_control_common_v1020_t
{
    UInt8    pucch_format3_r10;
    /*^ M, 0, H, 0, 7 ^*/  /* rrc_rrm_pucch_format3_et */
    UInt8    pucch_format1_bcs_r10;
    /*^ M, 0, H, 0, 1 ^*/  /* rrc_rrm_pucch_format1_bcs_et */
}uplink_power_control_common_v1020_t;

#define MAX_BAND_WIDTH_COMB_R10 4

typedef struct _supported_band_width_combination_set_r10_t
{
    UInt8      count;
    /*^ M, 0, B, 1, 4 ^*/    /* MAX_BAND_WIDTH_COMB_R10 */
    UInt8      data[MAX_BAND_WIDTH_COMB_R10];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/    
}supported_band_width_combination_set_r10_t;

typedef struct _band_combination_parameters_ext_r10_t
{
#define RRC_RRM_SUPPORTED_BAND_WIDTH_COMB_SET_R10 0x01
    UInt16    presence_bitmask;       /*^ BITMASK ^*/
    supported_band_width_combination_set_r10_t supported_band_width_combination_set_r10;
    /*^ O, RRC_RRM_SUPPORTED_BAND_WIDTH_COMB_SET_R10, N, 0, 0 ^*/    
}band_combination_parameters_ext_r10_t;

typedef struct _supported_band_combination_ext_r10_ies_t
{
    /* SPR 20817 Fix Start */
    UInt8              count;     /*^ M, 0, B, 1,MAX_BAND_COMB_R10 ^*/   /* MAX_BAND_COMB_R10 */ 
    /* SPR 20817 Fix End */
    band_combination_parameters_ext_r10_t       band_combination_parameters_ext_r10[MAX_BAND_COMB_R10]; 
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/    
}supported_band_combination_ext_r10_ies_t;

typedef struct _rf_parameters_v1060_ies_t
{
    supported_band_combination_ext_r10_ies_t    supported_band_combination_ext_r10;
}rf_parameters_v1060_ies_t;

typedef struct _rrc_phy_scell_config_t
{
#define RRC_PHY_CONFIG_DEDICATED_SCELL_PRESENT 0x01
#define RRC_PHY_CONFIG_OPERATION_LIST_PRESENT  0x02    
    rrc_bitmask_t   bitmask;    /*^ BITMASK ^*/
    cell_index_t   cell_index; /*^ M, 0, H, 0, MAX_CELL_INDEX ^*/
    UInt8   operation_type; 
    /*^ O, RRC_PHY_CONFIG_OPERATION_LIST_PRESENT, H, 0, 2 ^*/  /*operation_type_et*/

    rrc_radio_res_config_dedicated_scell_t  radio_res_config_dedicated_scell;
    /*^ O, RRC_PHY_CONFIG_DEDICATED_SCELL_PRESENT ^*/
}rrc_phy_scell_config_t;

typedef struct _rrc_phy_scell_config_list_t
{
    /* SPR-18445 start */
    UInt8                     count;
    /*^ M, 0, B, 1, RRC_MAX_SCELL ^*/
    /* SPR-18445 stop */

    rrc_phy_scell_config_t rrc_phy_scell_config[RRC_MAX_SCELL];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/
}rrc_phy_scell_config_list_t;

typedef struct _rrc_mac_dl_num_harq_process_t
{
    UInt8   dl_num_harq_process; /*^ M, 0, B, 1, 15 ^*/
}rrc_mac_dl_num_harq_process_t;

typedef struct _rrc_mac_dl_init_mcs_t
{
    UInt8   dl_init_mcs; /*^ M, 0, H, 0, 28 ^*/
}rrc_mac_dl_init_mcs_t;

typedef struct _scell_deactivation_timer_t
{
    UInt8  scell_deactivation_timer; /*^ M, 0, H, 0, 128 ^*/
}scell_deactivation_timer_t;

typedef struct _rrc_mac_ca_config_error_t
{
    UInt8    cell_id; /*^ M, 0, H, 0, 7 ^*/
    UInt16   error_code;/*^ M, 0, B,7,7 ^*/
}rrc_mac_ca_config_error_t;

typedef struct _rrc_mac_ca_reconfig_error_t
{
    UInt8    cell_id; /*^ M, 0, H, 0, 7 ^*/
    UInt16   error_code;/*^ M, 0, B, 6, 6 ^*/
}rrc_mac_ca_reconfig_error_t;

typedef struct _rrc_mac_delete_ca_config_error_t
{
    UInt8    cell_id; /*^ M, 0, H, 0, 7 ^*/
    UInt16   error_code; /*^ M, 0, B, 6,6 ^*/
}rrc_mac_delete_ca_config_error_t;

typedef struct _scells_operation_list_t
{
    UInt8    chk_cellid_exist;
    UInt8    operation_type;
    /*CA start */
    UInt8    valid_ind; /* Used in case of rollback only*/
    /*CA end */
    UInt8    scell_to_add_after_deletion_flag;
}scells_operation_list_t;

typedef struct _rrc_mac_scell_rel_flag_t
{
    UInt8   scell_rel_flag; /*^ M, 0, H, 0, 1 ^*/
}rrc_mac_scell_rel_flag_t;

typedef enum 
{
    SCELL_NOT_ACTIVATED,
    SCELL_ACTIVATED
}scell_activate_status_et;

typedef struct _scell_activate_status_t
{
    UInt8 scellActivateStatus; /*^ M, 0, H, 0, 1 ^*//* scell_activate_status_et */                
} scell_activate_status_t;
/* SPR_18107 start */
typedef struct _rrc_mac_dl_earfcn_t
{
    UInt32 dlEarfcn; /*^ M, 0, H, 0, MAX_EARFCN ^*/
} rrc_mac_dl_earfcn_t;
/* SPR_18107 stop */
typedef enum
{
    RRC_RRM_INVAID_CONFIG = 0
}rrc_rrm_reestab_config_fail_cause_et;

typedef enum
{
    SCELL_NOT_EXISTS = 6,
    SCELL_NOT_RUNNING = 7
}rrc_mac_ca_config_error_code_et;

typedef enum
{
    SCELL_NO_ERROR,
    SCELL_ADD_FAILED ,
    SCELL_MOD_FAILED,
    SCELL_DEL_FAILED, 
    SCELL_CONFIG_FAIL
}scell_config_error_code_et;

typedef enum
{
    SF_160 = 0,
    SF_256 = 1,
    SF_320 = 2,
    SF_512 = 3,
    SF_640 = 4,
    SF_1024 = 5,
    SF_1280 = 6,
    SPARE_1 = 7
}meas_cycle_scell_r10_et;

#ifndef LOGGING_ENHANCEMENT_CELL_AND_UE_INDEX_STRUCT
#define LOGGING_ENHANCEMENT_CELL_AND_UE_INDEX_STRUCT
typedef struct _cell_and_ue_index
{
    cell_index_t  cell_index;
    ue_index_t ue_index;
} cell_and_ue_index;
#endif

/* This is used in debug GET Command */
typedef enum rrc_GetDebugTypeE
{
    RRC_GET_DEBUG_INFO_MEM_STATS, /* Mem Pool Statistics */
}rrc_DebugType;
typedef enum
{
    GET_MEM_POOL_STATS,
}rrc_oam_debug_info_req_et;
typedef enum
{
    WRONG_DEBUG_TYPE
}rrc_oam_debug_info_fail_cause_et;
/*spr 22474 end*/

#define M2AP_TWO                                2
#define MAX_NUM_OF_RESERVED_CELLS               255
#define MAX_CSA_PATTERN                         8

#define  M2AP_MAX_IP_ADDR_LENGTH                16
#define  M2AP_MAX_IPV6_ADDR_LENGTH              40
typedef struct
{
    UInt8 ipv6_addr[M2AP_MAX_IPV6_ADDR_LENGTH]; /*^ M,0,OCTET_STRING,FIXED ^*/
}m2ap_ipv6_addr_t;

typedef struct
{
    UInt8 ipv4_addr[M2AP_MAX_IP_ADDR_LENGTH]; /*^ M,0,OCTET_STRING,FIXED ^*/
}m2ap_ipv4_addr_t;
#define ENB_COMM_INFO_IPV6_NUM_ADDR_PRESENT       0x01
#define ENB_COMM_INFO_IPV6_IP_ADDR_PRESENT       0x02
typedef struct
{
    /* IPV6 Start */
    UInt8 bitmask; /*^ BITMASK ^*/
    /* IPV6 Stop */
    /* number of ipv6 addr */
    /* number of ip addr */
    UInt16 port; /*^ M,0,N,0,0 ^*/

    UInt8 num_ip_addr; /*^ M,0,H,0,3 ^*/

    m2ap_ipv4_addr_t ip_addr[MAX_NUM_IP_ADDR]; /*^ M,0,OCTET_STRING,VARIABLE ^*/

    UInt8 num_ipv6_addr;
    /*^ O,ENB_COMM_INFO_IPV6_NUM_ADDR_PRESENT,B,1,3 ^*/
    /* IPV6 addresses of eNB */

    m2ap_ipv6_addr_t ipv6_addr[MAX_NUM_IP_ADDR];
    /*^ O,ENB_COMM_INFO_IPV6_IP_ADDR_PRESENT,OCTET_STRING,VARIABLE ^*/
    /* IPV6 Stop */

}m2ap_enb_comm_info_t;

/*FJT_cp_tnl_info_src_change_S*/

/* Structure defining the configured IPv4 addresses */
typedef struct
{
    UInt8               num_ipv4_addr;
    /*^ M, 0, B, 1, MAX_NUM_IP_ADDR ^*/

    x2_ip_addr_t        ipv4_addr[NGAP_MAX_NUM_IP_ADDR];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/

} ngap_ipv4_addr_info_t;


/* Structure defining the configured IPv6 addresses */
typedef struct
{
    UInt8               num_ipv6_addr;
    /*^ M, 0, B, 1, MAX_NUM_IP_ADDR ^*/

    x2_ipv6_addr_t      ipv6_addr[NGAP_MAX_NUM_IP_ADDR];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/

} ngap_ipv6_addr_info_t;


/* Structure defining the socket communication specific
 * configuration to be used by NGAP */
typedef struct
{

#define NGAP_COMM_INFO_IPV4_ADDR_PRESENT      0x01
#define NGAP_COMM_INFO_IPV6_ADDR_PRESENT      0x02

    rrc_bitmask_t                   bitmask;
    /*^ BITMASK ^*/
    /* Configured IPv4 addresses for NGAP */
    ngap_ipv4_addr_info_t       ipv4_addr;
    /*^ O, NGAP_COMM_INFO_IPV4_ADDR_PRESENT, B, 1, NGAP_MAX_NUM_IP_ADDR ^*/

    /* Configured IPv6 addresses for NGAP */
    ngap_ipv6_addr_info_t       ipv6_addr;
    /*^ O, NGAP_COMM_INFO_IPV6_ADDR_PRESENT, B, 1, NGAP_MAX_NUM_IP_ADDR ^*/

} ngap_ip_comm_info_t;

/* Structure defining the socket communication specific
 * configuration to be used by AMF */
typedef struct
{
    /* Number of SCTP Streams To Be Used For a AMF Connection */
    UInt8                           num_sctp_streams;
    /*^ M, 0, N, 0, 0 ^*/

    /* Number of SCTP Association To Be Used For a AMF Connection */
    UInt8                           num_sctp_association;
    /*^ M, 0, N, 0, 0 ^*/

    /* NG Connection Mode to check whether connection
    *   need to be establised with one AMF IP or All
    */
    UInt8                           ng_connection_mode;
    /*^ M, 0, N, 0, 0 ^*/

    /* IP Information of Configured AMF */
    ngap_ip_comm_info_t             ngap_amf_ip_info;
    /*^ M, 0, N, 0, 0 ^*/

} ngap_amf_comm_info_t;

/* Structure defining amf communication info list*/
typedef struct 
{
    /*CSR_00162478_FIX_S*/
    UInt8                          amf_num;
    /*^ M, 0, H, 0, MAX_NUM_AMF_SUPPORTED ^*/
    /*CSR_00162478_FIX_E*/
    ngap_amf_comm_info_t           amf_comm_info[MAX_NUM_AMF_SUPPORTED];
    /*^ M, 0, OCTET_STRING, VARIABLE ^*/
}ngap_amf_comm_info_list_t;
/*FJT_cp_tnl_info_src_change_E*/

typedef enum
{
    MCCH_REPETITION_PERIOD_RF32,
    MCCH_REPETITION_PERIOD_RF64,
    MCCH_REPETITION_PERIOD_RF128,
    MCCH_REPETITION_PERIOD_RF256
}mcch_repetition_period_et;

typedef enum
{
    NOTIFICATION_REPETITION_COEFF_2,
    NOTIFICATION_REPETITION_COEFF_4
}notification_repetition_coeff_et;


typedef enum
{
    PDCCH_LENGTH_1 = 0,
    PDCCH_LENGTH_2
}pdcch_length_et;


typedef enum
{
    MCCH_MODIFICATION_PERIOD_512,
    MCCH_MODIFICATION_PERIOD_1024
}mcch_modification_period_et;

typedef enum
{
    SIGNALING_MCS_2,
    SIGNALING_MCS_7,
    SIGNALING_MCS_13,
    SIGNALING_MCS_19
}signalling_mcs_et;



typedef struct _m2ap_mac_csa_pattern_list_t
{
    UInt8               radio_frame_allocation_period; /*^ M, 0, H, 0, 5 ^*/ 
    /*radio_frame_allocation_period_et*/

    UInt8               radio_frame_allocation_offset; /*^ M, 0, H, 0, 7 ^*/ 
    UInt8               choice;   /*^ M, 0, H, 0, 1 ^*/
    UInt32              subframe_allocation; /*^ M, 0, N, 0, 0 ^*/

}m2ap_mac_csa_pattern_list_t;


typedef enum {
    subscription_information = 0,
    statistics
}ue_activity_behaviour_info_source_et;

typedef struct _expected_ue_activity_behaviour_t {
    rrc_bitmask_t                      bitmask;    /*^ BITMASK ^*/
#define UECC_LLIM_EXPECTED_ACTIVITY_PERIOD_PRESENT        0x01
#define UECC_LLIM_EXPECTED_IDLE_PERIOD_PRESENT            0x02
#define UECC_LLIM_SOURCE_OF_UE_ACTIVITY_BEHAVIOUR_PRESENT 0x04
    UInt32 expected_activity_period;
    UInt32 expected_idle_period;
    ue_activity_behaviour_info_source_et ue_activity_behaviour_info_source;
}expected_ue_activity_behaviour_t;


typedef enum {
    expected_ho_interval_sec15 = 0,
    expected_ho_interval_sec30,
    expected_ho_interval_sec60,
    expected_ho_interval_sec90,
    expected_ho_interval_sec120,
    expected_ho_interval_sec180,
    expected_ho_interval_long_time
} expected_ho_interval_et;

typedef struct _expected_ue_behaviour_t {
    rrc_bitmask_t                      bitmask;    /*^ BITMASK ^*/
#define UECC_LLIM_EXPECTED_ACTIVITY_PRESENT    0x01
#define UECC_LLIM_EXPECTED_HO_INTERVAL_PRESENT 0x02
    expected_ue_activity_behaviour_t   expected_ue_activity_behaviour;
    expected_ho_interval_et            expected_ho_interval;

} expected_ue_behaviour_t;

/* EN_DC_CHANGES_START */

typedef struct
{
    UInt32  earfcn; /*^ M,0,N,0,0 ^*/ 
}x2_nr_earfcn_t;


typedef struct
{
    /*SPR 24250 Fix Start*/
    UInt8 x2_gnb_id_num_bits; /*^ M,0,H,22,32 ^*/
    /*SPR 24250 Fix End*/
    UInt8 x2_en_gnb_id[EN_GNB_ID_OCTET_SIZE];  /*^ M, 0, OCTET_STRING, FIXED ^*/
}x2_en_gnb_id_t;

typedef struct
{
    plmn_identity_t plmn_identity; /*^ M,0,N,0,0 ^*/
    x2_en_gnb_id_t x2_en_gnb_id;  /*^ M,0,N,0,0 ^*/
}x2_en_gb_enb_id_t;

/* EN_DC_CHANGES_END */
typedef enum
{
    PDCP_AT_SGNB_PRESENT,
    PDCP_AT_SGNB_NOT_PRESENT
}pdcp_at_sgnb_et;

typedef enum
{
    NR_CONFIGURATION_N2,
    NR_CONFIGURATION_N3,
    NR_CONFIGURATION_N4
}nr_configuration_et;

typedef enum
{
    PARAM_SUPPORTED
}nr_parameters_support_et;

typedef enum
{
    RRC_LONG_DRX_CYCLE_MS10,
    RRC_LONG_DRX_CYCLE_MS20,
    RRC_LONG_DRX_CYCLE_MS32,
    RRC_LONG_DRX_CYCLE_MS40, 
    RRC_LONG_DRX_CYCLE_MS60, 
    RRC_LONG_DRX_CYCLE_MS64, 
    RRC_LONG_DRX_CYCLE_MS70, 
    RRC_LONG_DRX_CYCLE_MS80, 
    RRC_LONG_DRX_CYCLE_MS128,
    RRC_LONG_DRX_CYCLE_MS160,
    RRC_LONG_DRX_CYCLE_MS256, 
    RRC_LONG_DRX_CYCLE_MS320, 
    RRC_LONG_DRX_CYCLE_MS512, 
    RRC_LONG_DRX_CYCLE_MS640, 
    RRC_LONG_DRX_CYCLE_MS1024,
    RRC_LONG_DRX_CYCLE_MS1280,
    RRC_LONG_DRX_CYCLE_MS2048,
    RRC_LONG_DRX_CYCLE_MS2560, 
    RRC_LONG_DRX_CYCLE_MS5120,
    RRC_LONG_DRX_CYCLE_MS10240 
}rrc_oam_long_drx_cycle_length_et;

typedef enum
{
    RRC_SHORT_DRX_CYCLE_MS3,
    RRC_SHORT_DRX_CYCLE_MS4, 
    RRC_SHORT_DRX_CYCLE_MS5, 
    RRC_SHORT_DRX_CYCLE_MS6, 
    RRC_SHORT_DRX_CYCLE_MS7, 
    RRC_SHORT_DRX_CYCLE_MS8,
    RRC_SHORT_DRX_CYCLE_MS10,
    RRC_SHORT_DRX_CYCLE_MS14,
    RRC_SHORT_DRX_CYCLE_MS16, 
    RRC_SHORT_DRX_CYCLE_MS20, 
    RRC_SHORT_DRX_CYCLE_MS30, 
    RRC_SHORT_DRX_CYCLE_MS32,
    RRC_SHORT_DRX_CYCLE_MS35, 
    RRC_SHORT_DRX_CYCLE_MS40, 
    RRC_SHORT_DRX_CYCLE_MS64, 
    RRC_SHORT_DRX_CYCLE_MS80, 
    RRC_SHORT_DRX_CYCLE_MS128, 
    RRC_SHORT_DRX_CYCLE_MS160,
    RRC_SHORT_DRX_CYCLE_MS256,
    RRC_SHORT_DRX_CYCLE_MS320,
    RRC_SHORT_DRX_CYCLE_MS512,
    RRC_SHORT_DRX_CYCLE_MS640
}rrc_short_drx_cycle_length_et; 

/* Size of NR_MAX_BANDS is 1024 in 38.331 v f10 but taking it 
 * as 128 due to problem in stack */
#define NR_MAX_BANDS                      128 
/* Size of NR_MAX_BAND_COMBINATION & NR_RRC_MAX_BASEBAND_PROC_COMB is 65536 in
 * 38.331 v f10 but taking it as 64 due to problem in stack */
#define NR_MAX_BAND_COMBINATION           128
#define NR_RRC_MAX_BASEBAND_PROC_COMB     6 
//#define NR_RRC_BAND_COMBINATIONS_UL       8192
#define NR_RRC_BAND_COMBINATIONS_UL       81
#define NR_RRC_MAX_SIMULTANEOUS_BAND      32
#define NR_RRC_MAX_NO_SERVING_CELLS_EUTRA 6
#define NR_RRC_MAX_NO_SERVING_CELLS       6
#define NR_RRC_NUM_SUPPORTED_BW_PER_CC    16
#define NR_RRC_NUM_SUPPORTED_BW_COMBINATION_SET     4
#define NR_MAX_FEATURE_SETS_PER_BAND      128
#define NR_FR2_BAND_1                     257
#define NR_FR2_BAND_2                     258
#define NR_FR2_BAND_3                     260
#define NR_FR2_BAND_4                     261

/*********************** XNAP ******************/
typedef struct
{
    UInt16                         enb_neighbour_cell; /*^ M,0,H,0,MAX_NEIGHBOURS ^*/
    xnap_neighbour_info_t       enb_neighbour_info[MAX_NEIGHBOURS]; /*^ M,0,OCTET_STRING,VARIABLE ^*/
    UInt16                         nr_neighbour_cell; /*^ M,0,H,0,MAX_NEIGHBOURS ^*/
    xnap_neighbour_info_t       nr_neighbour_info[MAX_NEIGHBOURS]; /*^ M,0,OCTET_STRING,VARIABLE ^*/
}xnap_nbour_cell_arry_t;


typedef struct
{
    UInt8                                bitmask; /*^ BITMASK ^*/
    rrc_cell_index_t                     cell_id; /*^ M, 0, H, 0,MAX_CELL_INDEX ^*/    /* MAX_NUM_CELLS - 1 */
    _xn_nr_cgi_t                          nr_cgi;  /*^ M,0,N,0,0 ^*/
}xnapOam_srvd_cell_info_t;



typedef struct
{
    xnapOam_srvd_cell_info_t      served_cell_info;     /*^ M,0,N,0,0 ^*/
    xnap_nbour_cell_arry_t     nbour_cell_info;      /*^ M,0,N,0,0 ^*/
}xnapOam_srvd_cell_arry_t;


#define XNAP_SCTP_ASSOC_MAX_RETRANS_PRESENT    0x01
#define XNAP_SCTP_VAL_COOKIE_LIFE_PRESENT      0x02
/* dscp_marking_start */
#define XNAP_OAM_DSCP_VALUE_PRESENT            0x04
/* dscp_marking_stop */
#define INVALID_XNAP_UE_ID                     0xFFFF

typedef struct
{
    UInt32   hbinterval;  /*^ M,0,N,0,0 ^*/
    UInt16   pathmaxrxt; /*^ M,0,N,0,0 ^*/
    UInt16   init_num_ostreams; /*^ M,0,N,0,0 ^*/
    UInt16   init_max_instreams; /*^ M,0,N,0,0 ^*/
    UInt16   init_max_attempts; /*^ M,0,N,0,0 ^*/
    UInt16   init_max_init_timeo; /*^ M,0,N,0,0 ^*/
    UInt32   rto_initial; /*^ M,0,N,0,0 ^*/
    UInt32   rto_max; /*^ M,0,N,0,0 ^*/
    UInt32   rto_min; /*^ M,0,N,0,0 ^*/
    /*sctp parameters start*/
    UInt16   bitmask;/*^ BITMASK ^*/
    UInt16   assoc_max_retrans;
    /*^ O, X2AP_SCTP_ASSOC_MAX_RETRANS_PRESENT,N,0,0 ^*/
    UInt32      valid_cookie_life;
    /*^ O, X2AP_SCTP_VAL_COOKIE_LIFE_PRESENT,N,0,0 ^*/
    /*sctp parameters stop*/
    /* dscp_marking_start */
    UInt8   xnap_dscp_value;
    /*^ O,X2AP_OAM_DSCP_VALUE_PRESENT, H, 0, 63 ^*/
    /* dscp_marking_stop */
}xnap_sctp_conf_info_t;
typedef struct
{
    UInt16     bitmask; /*^ BITMASK ^*/
#define XNAP_TIME_TO_WAIT_INDEX_PRESENT             0x01
#define XNAP_OAM_XN_HEALTH_MONITORING_TIMER_PRESENT 0x02
    UInt16   sctp_connect_tim_val;  /*^ M,0,B,50,65535 ^*/
    UInt16   xnap_csi_guard_tim_val; /*^ M,0,B,50,65535 ^*/
    UInt16   xnap_time_to_wait_index; /*^ M,0,B,0,5 ^*/
    UInt16   xnap_setup_retry_tim_val; /*^ M,0,B,50,65535 ^*/
    UInt8    sctp_connect_retry_cnt; /*^ M,0,H,0,255 ^*/
    UInt8    xnap_setup_retry_cnt; /*^ M,0,H,0,10 ^*/
    UInt8    gNB_Config_Update_retry_cnt; /*^ M,0,H,0,10 ^*/
    UInt16   gNB_Config_Update_retry_timer_val; /*^ M,0,B,50,65535 ^*/
    UInt8    gNB_Config_Update_time_to_wait_retry_cnt; /*^ M,0,H,0,10 ^*/
    UInt16   gNB_Config_Update_time_to_wait_offset; /*^ M,0,B,50,65535 ^*/
    UInt8    xnap_gnb_reset_retry_cnt; /*^ M,0,H,0,10 ^*/
    UInt16   xnap_gnb_reset_guard_tim_val; /*^ M,0,B,50,65535 ^*/
    /*SON_ANR_FTR_S*/
    UInt16   xnap_gnb_removal_guard_tim_val; /*^ M,0,B,50,65535 ^*/
    /*SON_ANR_FTR_E*/
    UInt16   xn_setup_req_w_timer; /*^ M,0,B,50,65535 ^*/
    UInt16   xnap_health_mon_time_int; /*^ M,0,H,0,65535 ^*/
    UInt16   xnap_tim_to_wait_tim_val; /*^ M,0,H,0,65535 ^*/

}xnap_con_tim_info_t;

typedef struct
{
    xnap_sctp_conf_info_t  sctp_conf_param; /*^ M,0,N,0,0 ^*/
    xnap_con_tim_info_t    timer_conf_info; /*^ M,0,N,0,0 ^*/
}xnap_conf_param_t;


typedef struct
{
    UInt8 ipv6_addr[MAX_XNAP_IPV6_ADDRESS_LENGTH]; /*^ M,0,OCTET_STRING,FIXED ^*/
}xn_ipv6_addr_t;

typedef struct
{
    UInt8 ip_addr[MAX_XNAP_IP_ADDRESS_LENGTH]; /*^ M,0,OCTET_STRING,FIXED ^*/
}xn_ip_addr_t;

/* IPV6 Start */
#define XN_GNB_COMM_INFO_IPV6_NUM_ADDR_PRESENT       0x01
#define XN_GNB_COMM_INFO_IPV6_IP_ADDR_PRESENT        0x02
#define XN_GNB_COMM_INFO_IPV4_NUM_ADDR_PRESENT       0x04
#define XN_GNB_COMM_INFO_IPV4_IP_ADDR_PRESENT        0x08
/* SA_L3_GSAL-963_XN_HO_Fix_S*/
#define XN_GNB_COMM_INFO_XN_STATUS_PRESENT        0x10

typedef enum
{
    XN_HO_ALLOWED = 1, /*!< XN HO allowed */
    XN_HO_PROHIBITED, /*!< XN HO prohibited */
    XN_HO_UNDEFINED = 255 /*!< XN unavailable */
}xnap_cell_xn_ho_status_et;

typedef struct
{
    UInt8 bitmask;    /*^ BITMASK ^*/

    /* number of ip addr */
    UInt8           num_ip_addr; /*^ O,XN_GNB_COMM_INFO_IPV4_NUM_ADDR_PRESENT,B,1,MAX_NUM_IP_ADDR ^*/

    /* ip addresses of MMEs */
    xn_ip_addr_t ip_addr[MAX_NUM_IP_ADDR];  /*^ O,XN_GNB_COMM_INFO_IPV4_IP_ADDR_PRESENT,OCTET_STRING,VARIABLE ^*/

    /* port of AMF with which SCTP association needs to be initiated */
    UInt16       port;  /*^ M,0,N,0,0 ^*/

    /* number of ipv6 addr */
    UInt8           num_ipv6_addr;  /*^ O,XN_GNB_COMM_INFO_IPV6_NUM_ADDR_PRESENT,B,1,MAX_NUM_IP_ADDR ^*/

    /* ip addresses of MMEs */
    xn_ipv6_addr_t ipv6_addr[MAX_NUM_IP_ADDR]; /*^ O,XN_GNB_COMM_INFO_IPV6_IP_ADDR_PRESENT,OCTET_STRING,VARIABLE ^*/

    UInt8 xn_ho_status; /*^ O, XN_GNB_COMM_INFO_XN_STATUS_PRESENT, B, 1, 2 ^*/   /* xnap_cell_xn_ho_status_et */
}xn_gnb_comm_info_t;
/* SA_L3_GSAL-963_XN_HO_Fix_E*/

typedef struct 
{

    xnap_plmn_identity_t    plmn_id; /*^ M,0,N,0,0 ^*/
    UInt8                   amf_group_id[MAX_AMF_GRP_BYTES]; /*^ M,0,OCTET_STRING,FIXED ^*/

}xnap_gu_group_id_t;

typedef struct 
{

    UInt8                  num_gu_group_id;  /*^ M,0,H,0,MAX_ENB_POOLS^*/

    xnap_gu_group_id_t      group_id_arr[MAX_GNB_POOLS]; /*^ M,0,OCTET_STRING,VARIABLE ^*/

}xnap_gu_grp_ids_t;

/* the below macros used to sent alarm id */
#define NGAP_SCTP_CONNECTION BREAK_ALARM        11001
#define XnAP_LINK_BOUNCE_ALARM                  11002
#define F1AP_LINK_BOUNCE_ALARM                  11003
#define CPU_MEMORY_OVERLOAD_ALARM               11004
#define CELL_SETUP_FAIL_ALARM                   11005
#define NGAP_ERROR_IND_ALARM                    11006
#define F1AP_ERROR_IND_ALARM                    11007
#define XnAP_ERROR_IND_ALARM                    11008
#define F1AP_RESET_ALARM                        11009
#define NGAP_RESET_ALARM                        11010
#define XnAP_RESET_ALARM                        11011
#define CALL_PRE_EMPTION_LOAD_SCENARIO_ALARM    11013
#define GTPU_PATH_UPF_ADDRESS_FAIL_IND_ALARM    12001
#define GTPU_PATH_F1U_CONNECTION_FAIL_ALARM     12002
#define INTEGRITY_FAIL_ALARM                    12003
#define OAM_PROCESS_HB_FAIL_ALARM               15001
#define SW_CHANGE_FAIL_ALARM                    15002
#define PM_FILE_UPLOAD_SMO_ERROR_ALARM          15003
#define SMO_CONN_FAIL_ALARM                     15004
#define CM_FAIL_CONSTISTENCY_CHECK_SMO_ALARM    15005
#define ASN_DECODE_ERROR_F1AP_INTF_ALARM        11012
#define ASN_DECODE_ERROR_XnAP_INTF_ALARM       11014
#define ASN_DECODE_ERROR_NGAP_INTF_ALARM       11015
#define ASN_DECODE_ERROR_RRC_INTF_ALARM        11016
/*end of the alarm id's */


typedef enum
{
    NOTIFY_NEW_ALARM,
    NOTIFY_CHANGED_ALARM,
    NOTIFY_CLEARED_ALARM,
    NEW_NOTIFICATION
}alarm_notify_type_et;


typedef enum
{
    COMMUNICATIONS_ALARM,
        PROCESSING_ERROR_ALARM,
        MEMORY_MISMATCH,    
        CONFIGURATION_OR_CUSTOMIZATION_ERROR,
        ENVIRONMENTAL_ALARM,
        QUALITY_OF_SERVICE_ALARM,
        EQUIPMENT_ALARM,
        INTEGRITY_VIOLATION,
        OPERATIONAL_VIOLATION,
        PHYSICAL_VIOLATION,
        SECURITY_SERVICE_OF_MECHANISM_VIOLATION,
        TIME_DOMAIN_VIOLATION,
        NOTIFICATION_TYPE
}alarm_event_type_et;

typedef enum{
        COMMUNICATIONS_RECEIVE_FAILURE=4,
        COMMUNICATIONS_TRANSMIT_FAILURE,
        OUT_OF_MEMORY=103,
        SOFTWARE_ERROR=106,
        COMMUNICATIN_SUBSYSTEM_FAILURE=158,
        SOFTWARE_PROGRAM_ERROR=212,
        MESSAGE_OUT_OF_SEQUENCE=236,
        CONNECTION_ESTABLISHMENT_ERROR=365,
        UNAVAILABLE
}alarm_probable_cause_et;


typedef enum
{
    CRITICAL,
        MAJOR,
        MINOR,
        WARNING,
        INDETERMINATE,
        CLEARED

}FM_alarm_severity_et;

typedef enum
{
    EXPEDITED_ALARM,
        QUEUED_ALARM,
        LOGGED_ALARM,
        DISABLED_ALARM,
        REPORT_MECHANISM_UNDEFINED = -1

}alarm_report_mechanism_et;

/* NR Positioning Feature Start */
/* mem_optimization_fix_start*/
#define NR_RRC_MAX_NUM_TRP                (4*MAX_NUM_CELLS)
/* mem_optimization_fix_end */
#define MAX_NUM_TRP_SUPPORTED_IN_GNB      MAX_NUM_CELLS
/* NR Positioning Feature Stop */

#pragma pack(pop)

#endif /* _RRC_DEFINES_H_ */
