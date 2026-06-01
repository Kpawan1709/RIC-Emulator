/****************************************************************************
 *
 *  ARICENT -
 * 
 *  Copyright (c) 2018 Aricent.
 *
 ****************************************************************************
 * File Name : logging.h
 *
 ****************************************************************************
 *
 *  File Description :
 *  This is the header file of logging framework includes
 *  data structure used for logging
 *
 ****************************************************************************/
#ifndef LOGGING_H 
#define LOGGING_H

#include "gnb_porting.h"
#include "gnb_utils.h"

/****************************************************************************
 * Project Includes
 ****************************************************************************/

/****************************************************************************
 * Exported Includes
 ****************************************************************************/



/****************************************************************************
 * Exported Definitions
 ****************************************************************************/
#define FILE_HEADER_STRING        "*** WARNING - DO NOT MODIFY FILE CONTENTS ***" 
#define TRACE_START_STRING        "*** TRACING STARTED ***" 

#define TRACE_SECTION_SIZE        4
#define WRITE_OFFSET_SIZE         4
#define ROTATED_FLAG_SIZE         1 

#define INVALID_LOG_ID            0
#define L2_LOG_LOST               255
/*
 * File Header Size = 9 Bytes  (Trace Section Size 4 Byte, write offset 4 Byte,
 *                              isRotated Flag 1 Byte) + 1(for null character)
 */
/*#define LOG_FILE_HEADER_SIZE     TRACE_SECTION_SIZE + WRITE_OFFSET_SIZE + \
                                 ROTATED_FLAG_SIZE + strlen(FILE_HEADER_STRING) + 1*/
#define MAX_INIT_BUFF_SIZE    32 

#define MAX_LOG_AREAS_PER_STACK     999
#define NR_MAX_FILE_NAME_SIZE       255
#define MAX_LOG_MEMORY_SIZE         5242880 /* 5 MB */
#define MAX_THREAD_NAME_SIZE        255
#define MAX_STACKS                  10

#define MAX_LOG_LENGTH              565
#define MAX_FAPI_LOG_LENGTH         1565
#define MAX_NEW_ERROR_MSG_SIZE      80

#define DEFAULT_INT_VALUE 0 
#define DEFAULT_FLOAT_VALUE 0.0 
#define FUNCTION_NAME __func__
#define FILE_NAME __FILE__
#define LINE_NUMBER __LINE__
#define FNAME "FUNCTION" 
#define EVENT "EVENT" 
#define FILENAME "FILE"
#define NEW_BIN_LOG 0XABCDABCD

#define MAX_PDCP_WORKER_THREADS      10
#define MAX_PDCP_MASTER_THREADS      2
#define MAX_PDCP_ASYNC_THREADS       10

#define PERRORMSG(errorMsg)\
{\
    SInt8  eMsg[MAX_NEW_ERROR_MSG_SIZE];\
    snprintf_wrapper(eMsg,MAX_NEW_ERROR_MSG_SIZE,"[%s] %s !!",__func__,errorMsg);\
    perror_wrapper(eMsg);\
}

/*
 * Defines the name of shared memory log regions that application thread 
 * shall use to register with logging library via logger_init function
 */
#ifdef NR_UESIM_TESTING
#define NR_L2_LOG_REGION_RLC_NAME                        "UE_RLC_REGION"
#define NR_L2_LOG_REGION_RLCL_NAME                       "UE_RLCL_REGION"
#define NR_L2_LOG_REGION_RLC_MASTER_NAME                 "UE_RLC_MASTER_REGION"
#define NR_L2_LOG_REGION_RLC_ACCUMULATOR_NAME            "UE_RLC_ACCUMULATOR_REGION"
#define NR_L2_LOG_REGION_RLC_WORKER_NAME                 "UE_RLC_WORKER_REGION"
#define NR_L2_LOG_REGION_PDCP_MASTER_NAME                "UE_PDCP_MASTER_REGION"
#define NR_L2_LOG_REGION_PDCP_WORKER_NAME                "UE_PDCP_WORKER_REGION"
#define NR_L2_LOG_REGION_PDCP_ACC_NAME                   "UE_PDCP_ACC_REGION"
#else
#define NR_L2_LOG_REGION_RLC_NAME                        "RLC_REGION"
#define NR_L2_LOG_REGION_RLCL_NAME                       "RLCL_REGION"
#define NR_L2_LOG_REGION_RLC_MASTER_NAME                 "RLC_MASTER_REGION"
#define NR_L2_LOG_REGION_RLC_ACCUMULATOR_NAME            "RLC_ACCUMULATOR_REGION"
#define NR_L2_LOG_REGION_RLC_WORKER_NAME                 "RLC_WORKER_REGION"
#define NR_L2_LOG_REGION_SDAP_WORKER_NAME                "SDAP_WORKER_REGION"
#define NR_L2_LOG_REGION_F1_WORKER_NAME                  "F1_WORKER_REGION"
#define NR_L2_LOG_REGION_F1_DU_WORKER_NAME               "F1_DU_WORKER_REGION"
#define NR_L2_LOG_REGION_X2_WORKER_NAME                  "X2_WORKER_REGION"
#define NR_L2_LOG_REGION_CU_RECEIVER_NAME                "RECEIVER_CU_REGION"
#define NR_L2_LOG_REGION_DU_RECEIVER_NAME                "RECEIVER_DU_REGION"
#define NR_L2_LOG_REGION_CU_GTPU_NAME                    "PR_CU_REGION"
#define NR_L2_LOG_REGION_DU_GTPU_NAME                    "PR_DU_REGION"
#define NR_L2_LOG_REGION_PDCP_GTPU_NAME                  "PDCP_GTPU_REGION"
#define NR_L2_LOG_REGION_PR_ACC_NAME                     "PR_ACC_REGION"
#define NR_L2_LOG_REGION_SECURITY_NAME                   "SECURITY_REGION"
#define NR_L2_LOG_REGION_PDCP_MASTER_NAME                "PDCP_MASTER_REGION"
#define NR_L2_LOG_REGION_PDCP_WORKER_NAME                "PDCP_WORKER_REGION"
#define NR_L2_LOG_REGION_PDCP_WORKER_AFTER_SEC_NAME      "PDCP_WORKER_AFTER_SEC_REGION"
#define NR_L2_LOG_REGION_PDCP_WORKER_EGRESS_NAME         "PDCP_WORKER_EGRESS_REGION"
#define NR_L2_LOG_REGION_PDCP_ACC_NAME                   "PDCP_ACC_REGION"
#define NR_L2_LOG_REGION_MAC_NAME                        "MAC_REGION"
#define NR_L2_LOG_REGION_MAC_SLOT_HDLR_THD_NAME          "MAC_SLOT_HDLR_THD_REGION"
#define NR_L2_LOG_REGION_MAC_GBL_SCHED_THD_NAME          "MAC_GBL_SCHED_THD_REGION"
#define NR_L2_LOG_REGION_MAC_UL_SCHED_THD_NAME           "MAC_UL_SCHED_THD_REGION"
#define NR_L2_LOG_REGION_MAC_DL_SCHED_THD_NAME           "MAC_DL_SCHED_THD_REGION"
#define NR_L2_LOG_REGION_MAC_PDCCH_ALLOC_THD_NAME        "MAC_PDCCH_ALLOC_THD_REGION"
#define NR_L2_LOG_REGION_MAC_TX_CTRL_DATA_THD_NAME       "MAC_TX_CTRL_DATA_THD_REGION"
#define NR_L2_LOG_REGION_MAC_NON_CRIT1_THD_NAME          "MAC_NON_CRIT1_THD_REGION"
#define NR_L2_LOG_REGION_MAC_STRATEGY_THD_NAME          "MAC_STRATEGY_THD_REGION"
#define NR_L2_LOG_REGION_MAC_LP_THD_NAME                 "MAC_LP_THD_REGION"
#endif
/*
 * Defines the id of shared memory log regions that application thread 
 * shall use to register with logging library via logger_init function
 */

enum {
#ifdef NR_UESIM_TESTING
    /*UESim should use different areas w.r.t to gNB stack*/
    NR_UESIM_REGION_START = 120,
#endif
    NR_L2_LOG_PDCP_ASYNC_ID ,
    NR_L2_LOG_REGION_GTPU_CU = (NR_L2_LOG_PDCP_ASYNC_ID + MAX_PDCP_ASYNC_THREADS),
    NR_L2_LOG_REGION_GTPU_DU,
    NR_L2_LOG_REGION_PDCP_GTPU,
    NR_L2_LOG_REGION_PDCP_ACC,
    NR_L2_LOG_REGION_PR_ACC = (NR_L2_LOG_REGION_PDCP_ACC + MAX_PDCP_WORKER_THREADS),
    NR_L2_LOG_REGION_DU_PR_ACC,
    NR_L2_LOG_REGION_PDCP_MASTER,
    NR_L2_LOG_REGION_PDCP_WORKER = (NR_L2_LOG_REGION_PDCP_MASTER + MAX_PDCP_MASTER_THREADS),
    NR_L2_LOG_REGION_F1_WORKER = (NR_L2_LOG_REGION_PDCP_WORKER + MAX_PDCP_WORKER_THREADS),
    NR_L2_LOG_REGION_F1_DU_WORKER = (NR_L2_LOG_REGION_F1_WORKER + MAX_PDCP_WORKER_THREADS),
    NR_L2_LOG_REGION_X2_WORKER = (NR_L2_LOG_REGION_F1_DU_WORKER + MAX_PDCP_WORKER_THREADS),
    NR_L2_LOG_REGION_SDAP_WORKER = (NR_L2_LOG_REGION_X2_WORKER + MAX_PDCP_WORKER_THREADS),
    NR_L2_LOG_REGION_RECEIVER_CU,
    NR_L2_LOG_REGION_RECEIVER_DU,
    NR_L2_LOG_REGION_RLC,
    NR_L2_LOG_REGION_RLC_MASTER,
    NR_L2_LOG_REGION_RLC_ACCUMULATOR,
    NR_L2_LOG_REGION_RLC_WORKER,
    NR_L2_LOG_REGION_RLCL = (NR_L2_LOG_REGION_RLC_WORKER + MAX_PDCP_WORKER_THREADS),
    NR_L2_LOG_REGION_MAC,
#ifndef NR_UESIM_TESTING
    NR_L2_LOG_REGION_MAC_SLOT_HDLR_THD,
    NR_L2_LOG_REGION_MAC_GBL_SCHED_THD = NR_L2_LOG_REGION_MAC_SLOT_HDLR_THD + MAX_NUM_CELL_PER_DU,
    NR_L2_LOG_REGION_MAC_UL_SCHED_THD = NR_L2_LOG_REGION_MAC_GBL_SCHED_THD + MAX_NUM_CELL_PER_DU,
    NR_L2_LOG_REGION_MAC_DL_SCHED_THD = NR_L2_LOG_REGION_MAC_UL_SCHED_THD + MAX_NUM_CELL_PER_DU,
    NR_L2_LOG_REGION_MAC_PDCCH_ALLOC_THD = NR_L2_LOG_REGION_MAC_DL_SCHED_THD + MAX_NUM_CELL_PER_DU,
    NR_L2_LOG_REGION_MAC_STRATEGY_ALLOC_THD = NR_L2_LOG_REGION_MAC_PDCCH_ALLOC_THD + MAX_NUM_CELL_PER_DU,
    NR_L2_LOG_REGION_MAC_TX_CTRL_DATA_THD = NR_L2_LOG_REGION_MAC_STRATEGY_ALLOC_THD + MAX_NUM_CELL_PER_DU,
    NR_L2_LOG_REGION_MAC_NON_CRIT1_THD = NR_L2_LOG_REGION_MAC_TX_CTRL_DATA_THD + MAX_NUM_CELL_PER_DU,
    NR_L2_LOG_REGION_MAC_LP_THD,
#ifdef MULTI_PDCP_WORKER
    NR_L2_LOG_REGION_PDCP_AFTER_SEC_WORKER = NR_L2_LOG_REGION_MAC_LP_THD + MAX_NUM_CELL_PER_DU,
    NR_L2_LOG_REGION_PDCP_EGRESS_WORKER = NR_L2_LOG_REGION_PDCP_AFTER_SEC_WORKER + MAX_PDCP_WORKER_THREADS,
    NR_L2_LOG_REGION_MAX
#else    
    NR_L2_LOG_REGION_MAX = NR_L2_LOG_REGION_MAC_LP_THD + MAX_NUM_CELL_PER_DU
#endif
#else 
    NR_UESIM_MAC_LP_THD,
    NR_UESIM_MAC_PHY_RECV_THD,
    NR_UESIM_MAC_PHY_RECV_THD_1,
    NR_UESIM_MAC_HP_CELL_0,
    NR_UESIM_MAC_HP_CELL_1,
    NR_UESIM_MAC_HP_CELL_2,
    NR_UESIM_MAC_HP_CELL_3,
    NR_UESIM_MAC_HP_CELL_4,
    NR_UESIM_MAC_HP_CELL_5,
    NR_UESIM_MAC_HP_CELL_6,
    NR_UESIM_MAC_HP_CELL_7,
    NR_UESIM_MAC_DEMUX_THD,
    NR_UESIM_MAC_DEMUX_THD_1,
    NR_UESIM_MAC_DEMUX_THD_2,
    NR_UESIM_MAC_DEMUX_THD_3,
#ifdef MULTI_PDCP_WORKER
    NR_L2_LOG_REGION_PDCP_AFTER_SEC_WORKER,
    NR_L2_LOG_REGION_PDCP_EGRESS_WORKER,
#endif
    NR_L2_LOG_REGION_MAX
    /****UESIM THREAD IDs END***/
#endif
};

/********************************************************
 *        Definitions for Log Categories
 *******************************************************/

#define    L2_SYS_FAIL                     (0x0000000000000001)
#define    MAC_L1_INF (2 * L2_SYS_FAIL)
#define    MAC_UL_HARQ (2 * MAC_L1_INF)
#define    MAC_RACH (2 * MAC_UL_HARQ)
#define    MAC_RRC_INF (2 * MAC_RACH)
#define    MAC_OAM_INF (2 * MAC_RRC_INF)
#define    MAC_DUMGR_INF (2 * MAC_OAM_INF)
#define    MAC_RLC_INF (2 * MAC_DUMGR_INF)
#define    MAC_DL_Strategy (2 * MAC_RLC_INF)
#define    MAC_UL_Strategy (2 * MAC_DL_Strategy)
#define    MAC_PDSCH (2 * MAC_UL_Strategy)
#define    MAC_PDCCH (2 * MAC_PDSCH)
#define    MAC_PUSCH (2 * MAC_PDCCH)
#define    MAC_PUCCH (2 * MAC_PUSCH)
#define    MAC_BCCH (2 * MAC_PUCCH)
#define    MAC_PCCH (2 * MAC_BCCH)
#define    MAC_CCCH (2 * MAC_PCCH)
#define    MAC_DL_HARQ (2 * MAC_CCCH)
#define    MAC_CQI (2 * MAC_DL_HARQ)
#define    MAC_SRS (2 * MAC_CQI)
#define    MAC_TB_UL (2*MAC_SRS)
#define    MAC_TB_DL (2 * MAC_TB_UL)
#define    MAC_DL_PC (2 * MAC_TB_DL)
#define    MAC_UL_PC (2 * MAC_DL_PC)
#define    MAC_DRX  ( 2*MAC_UL_PC )
#define    MAC_MEAS_GAP (2*MAC_DRX)
#define    MAC_MEAS_HANDLER ( 2 * MAC_MEAS_GAP )
#define    MAC_UL_CSI (2 * MAC_MEAS_HANDLER)
#define    MAC_DEMUX (2 * MAC_UL_CSI)
#define    MAC_DL_SPS_STRATEGY (2 * MAC_DEMUX)
#define    MAC_UL_SPS_STRATEGY (2 * MAC_DL_SPS_STRATEGY)
#define    MAC_SCHEDULER       (2ull * MAC_UL_SPS_STRATEGY)
#define    MAC_ATB             (2ull * MAC_SCHEDULER)
#define    MAC_TA (2ull * MAC_ATB)
#define    DL_RESOURCE_MGR (2ull * MAC_TA)
#define    MAC_ENCODER (2ull * DL_RESOURCE_MGR)
#define    MAC_TRANSMITTER (2ull * MAC_ENCODER)
#define    MAC_MULTIPLEXER (2ull * MAC_TRANSMITTER)
#define    MAC_RECEIVER (2ull * MAC_MULTIPLEXER)
#define    MAC_LA (2ull * MAC_RECEIVER)
#define    MAC_CSIRS (2ull * MAC_LA)
#define    MAC_SYNC_LOSS (2 * MAC_CSIRS)
#define    MAC_DMRS (2 * MAC_SYNC_LOSS)
#define    MAC_KPI (2 * MAC_DMRS)
#define    MAC_CG  (2 * MAC_KPI)
#define    MAX_MAC_CATEGORY MAC_CG

#define    MAX_MAC_LOG_CATEGORY ( 2ull * (MAX_MAC_CATEGORY))
#define    ALL_MAC_LOG_CATEGORY ((2ull *  MAX_MAC_LOG_CATEGORY) - 1ull)

/* RLC Log Categories */
#define RLC_OAM    (0x0000000080000000)
#define RLC_DUM    (0x0000000040000000)
#define RLC_RRM    (0x0000000020000000)
#define RLC_F1U    (0x0000000010000000)
#define RLC_MAC    (0x0000000008000000)
#define RLC_AM     (0x0000000004000000)
#define RLC_UM     (0x0000000002000000)
#define RLC_TX     (0x0000000001000000)
#define RLC_RX     (0x0000000000800000)
#define RLC_TIMER  (0x0000000000400000)

#define ALL_RLC_LOG_CATEGORY (RLC_OAM | RLC_DUM | RLC_RRM | \
       RLC_F1U | RLC_MAC | RLC_AM | RLC_UM | RLC_TX |       \
       RLC_RX | RLC_TIMER )

/* RLCL Log Categories */
#define RLCL_RLC    (0x8000000000000)
#define RLCL_MAC    (0x4000000000000)
#define RLCL_AM     (0x2000000000000)
#define RLCL_UM     (0x1000000000000)
#define RLCL_TX     (0x0800000000000)

#define ALL_RLCL_LOG_CATEGORY (RLCL_RLC | RLCL_MAC | RLCL_AM | \
       RLCL_UM | RLCL_TX )

/* PDCP Log Categories */
#define    PDCP_RRC        (0x0000000000000001ull)
#define    PDCP_OAM        (0x0000000000000002ull)
#define    PDCP_RRM        (0x0000000000000004ull) 
#define    PDCP_TX         (0x0000000000000008ull)
#define    PDCP_RX         (0x0000000000000010ull) 
#define    PDCP_INTEGRITY  (0x0000000000000020ull)
#define    PDCP_CIPHERING  (0x0000000000000040ull)
#define    PDCP_ROHC       (0x0000000000000080ull)
#define    PDCP_DDDS       (0x0000000000000100ull)

#define    ALL_PDCP_LOG_CATEGORY (PDCP_RRC | PDCP_OAM | PDCP_RRM | \
        PDCP_TX | PDCP_RX | PDCP_INTEGRITY | PDCP_CIPHERING | PDCP_ROHC | \
        PDCP_DDDS )

/* Packet Relay + eGTPu logging Categories*/
#define   PR_GTPU_OAM       (0x0000000000000001ull)
#define   PR_GTPU_CONTROL   (0x0000000000000002ull)
#define   PR_GTPU_DL_DATA   (0x0000000000000004ull)
#define   PR_GTPU_UL_DATA   (0x0000000000000008ull)
#define   PR_GTPU_COMMON    (0x0000000000000010ull)
#define   PR_GTPU_HO_DATA   (0x0000000000000020ull)
#define   X2U_RELAY         (0x0000000000000040ull)
#define   F1U_OAM           (0x0000000100000000ull)
#define   F1U_RRC           (0x0000000200000000ull)
#define   F1U_DL_DATA       (0x0000000400000000ull)
#define   F1U_UL_DATA       (0x0000000800000000ull)

#define ALL_PR_LOG_CATEGORY (PR_GTPU_OAM | PR_GTPU_CONTROL | PR_GTPU_DL_DATA | \
        PR_GTPU_UL_DATA | PR_GTPU_COMMON | PR_GTPU_HO_DATA | F1U_OAM | \
        F1U_RRC | F1U_DL_DATA | F1U_UL_DATA | X2U_RELAY )

/*This special category has been created for composer parser trace
 *and used only in gnb_cp_trace. It is common for all Layer2 module 
 *(MAC,RLC,PDCP).
 */
#define INTF_COMPOSER_PARSER_CAT (0x1000000800000000ull)

#define LOG_MAX_ID 2000 
#define MAX_LOG_STR_VALUES 2
#define MAX_LOG_STR_LEN 41
#define MAX_FAPI_INT_LOG_STR_LEN 1024
#define MAX_LOG_INFO_STR_LEN 36
#define MAX_LOG_INT_VALUES 5
#define MAX_LOG_FLOAT_VALUES 2
#define MAX_LOG_LEVEL_STR_LEN 16
#define MAX_LOG_AREA_STR_LEN 16
#define MAX_LOG_DIS_STR_LEN 128
#define MAX_LOG_DEF_STR_VALUES MAX_LOG_INT_VALUES + \
                               MAX_LOG_FLOAT_VALUES + \
                               MAX_LOG_STR_VALUES

typedef struct LogShmHeader
{
    UInt32 traceSectionSize;
    UInt32 writeOffset;
    UInt32 readOffset;
    UInt32 lostLogCount;
    UInt64 log_index;
    UInt8  rotatedFlag;
}LogShmHeader;

#define LOG_FILE_HEADER_SIZE sizeof(LogShmHeader)
/***************NEW LOGGING FRAMEWORK CHANGES START********************/
typedef struct LogReaderParamValuesT {
    ADDR  str;
    ADDR  fileName;
    ADDR  funcName;
    UInt64  timestampUsec;     
    time_t  timestampSec;
    UInt32  lineNo;
    UInt32  logId;
    UInt8   logModule;
    UInt8   logLevel;
    UInt16 slots_in_sfn;
    cell_index_t cell_index;
    time_in_ms_t  globalTick;     
    UInt64  logCategory;
    UInt64  log_index;
    UInt64  intValues[MAX_LOG_INT_VALUES];    
#if defined UBUNTU_OS_DIST 
    /* logging changes ubuntu + */
    ADDR base_address;
    /* logging changes ubuntu - */
#endif
} LogReaderParamValues;
/***************NEW LOGGING FRAMEWORK CHANGES END********************/

typedef struct ttiULLoggingInfoT
{
    UInt32 logid;
    UInt32 tbSize;
    UInt16 systemFrame;
    UInt16 rnti;
    UInt16 UEID;
    UInt8 pduType;
    UInt8 subframe;
    UInt8 numOfRBs;
    UInt8 RBStart;
    UInt8 rv;
    UInt8 txIndicator;
    UInt8 mcsIndex;
    UInt8 modType;
    UInt8 reserve;
    UInt8 reserve1;
    UInt8 reserve2;
    UInt8 reserve3;
    UInt8 reserve4;
    UInt8 reserve5;
    UInt8 reserve6;
    UInt8 reserve7;
    UInt8 reserve8;
    UInt8 reserve9;
    UInt8 reserve10;
    UInt8 reserve11;
    UInt8 reserve12;
    UInt8 reserve13;
    UInt8 reserve14;
    UInt8 reserve15;
    UInt8 reserve16;
    UInt8 reserve17;
    UInt8 reserve18;
    UInt8 reserve19;
    UInt8 reserve20;
    UInt8 reserve21;
    UInt8 reserve22;
    UInt8 reserve23;
    UInt8 reserve24;
    UInt8 reserve25;
    UInt8 reserve26;
    UInt8 reserve27;
    UInt8 reserve28;
    UInt8 reserve29;
    UInt8 reserve30;
    UInt8 reserve31;
    UInt8 reserve32;
    UInt8 reserve33;
    UInt8 reserve34;
    UInt8 reserve35;
    UInt8 reserve36;
    UInt8 reserve37;
    UInt8 reserve38;
    UInt8 reserve39;
    UInt8 reserve40;
    UInt8 reserve41;
    UInt8 reserve42;
} ttiULLoggingInfo;

typedef struct ttiDciLoggingInfoT
{
    UInt32 logid;
    UInt32 rbCoding;
    UInt32 tbSize1;
    UInt32 tbSize2; 
    UInt32 dlQueueLoad;
    UInt32 ulBSR;
    UInt16 systemFrame;
    UInt16 rnti;
    UInt16 ueID;
    UInt8 subframe;
    UInt8 numOfRBs;
    UInt8 dciFormat;
    UInt8 numOfLayers;
    UInt8 numOfTB;
    UInt8 harqID;
    UInt8 rv1;
    UInt8 rv2;
    UInt8 ndi1;
    UInt8 ndi2;
    UInt8 ratPolicy;
    UInt8 tpc;
    UInt8 transmissionScheme;
    UInt8 rntiType;
    UInt8 mcsIndex1;
    UInt8 mcsIndex2; 
    UInt8 cceIndex;
    UInt8 aggregationLevel;
    UInt8 searchSpace;
    UInt8 reserve;
    UInt8 reserve1;
    UInt8 reserve2;
    UInt8 reserve3;
    UInt8 reserve4;
    UInt8 reserve5;
    UInt8 reserve6;
    UInt8 reserve7;
    UInt8 reserve8;
    UInt8 reserve9;
    UInt8 reserve10;
    UInt8 reserve11;
    UInt8 reserve12;
    UInt8 reserve13;
    UInt8 reserve14;
    UInt8 reserve15;
} ttiDciLoggingInfo;

typedef struct Log_FAPI_Msg_st {
    UInt32  logId;     
    UInt32  timestampSec;
    UInt32  timestampUsec;     
    UInt32  globalTick;     
    UInt32  intValue;     
    SInt8   strFuncName[MAX_LOG_STR_LEN]; 
    SInt8   strMessage[MAX_FAPI_INT_LOG_STR_LEN]; 
} Log_FAPI_st;

typedef struct LogDefValuesT {
    UInt32  logId;
    UInt32  logLevel;
    UInt64  logCategory;
    SInt8   log_str[MAX_LOG_DIS_STR_LEN];
    SInt8   strValues[MAX_LOG_DEF_STR_VALUES][MAX_LOG_INFO_STR_LEN];
} LogDefValues;


#define MAX_LOGGER_TYPE_STR_LEN 32
#define MAX_LOG_FILES_ALLOWED   100
#define MAX_LOG_FILES_DEFAULT   10
typedef struct lteL2LogOptionT
{
    /* Stores the name of the binary */
    SInt8 binName[NAME_MAX]; 
    char mac_file_name[NAME_MAX];
    char rlc_file_name[NAME_MAX];

    char gtpu_file_name[NAME_MAX];
    SInt32 l2gtpuflag;

    char logger_option[MAX_LOGGER_TYPE_STR_LEN];
    char logFileSize[MAX_LOGGER_TYPE_STR_LEN];
    char numFile[MAX_LOGGER_TYPE_STR_LEN];
    SInt32 shmSize;
    SInt32 loglevel;
    /* Core to be used for bin_reader module */
    UInt8 bin_reader_core;
    UInt8 du_id;
}lteL2LogOption;

/* Logging structure for storing the timer values */
typedef struct LogMetaData
{
    struct timeval timestamp;
    time_in_ms_t currentTick;
    UInt16 slots_in_sfn;
}LogMetaData;

extern LogMetaData logMetaData[MAX_NUM_CELL_PER_DU];

/* Global variables - used in macro so defines as extern */
extern lteL2LogOption l2Input;
extern UInt32 macloglevelEnabled_g[MAX_NUM_CELL_PER_DU];
extern UInt32 pdcploglevelEnabled_g;
extern UInt32 rlcloglevelEnabled_g;
extern UInt32 rlclloglevelEnabled_g;
extern UInt32 gtpuloglevelEnabled_g;
extern UInt32 syncloglevelEnabled_g;
extern UInt64 logCategoryEnabled_g; 
extern UInt64 maclogCategoryEnabled_g[MAX_NUM_CELL_PER_DU]; 
extern UInt64 pdcplogCategoryEnabled_g; 
extern UInt64 rlclogCategoryEnabled_g; 
extern UInt64 rlcllogCategoryEnabled_g;
extern UInt64 gtpulogCategoryEnabled_g; 
extern UInt64 synclogCategoryEnabled_g;

extern LogDefValues logCommValues[LOG_MAX_ID];
extern SInt8* logLevelStrValues[];
extern SInt8* logModuleStrValues[];
#ifdef SHM_PRINT_ENABLED

typedef struct ttiCELLLoggingInfoT
{
    UInt32 logid;
    UInt8 cellID;
    UInt8 reserve;
} ttiCellLoggingInfo;

typedef struct ttiUELoggingInfoT
{
    UInt32 logid;
    UInt16 ueID;
    UInt8 reserve;
} ttiUELoggingInfo;
#endif

#define LOG_FAPI_MSG(logId, size)   NULL;

/***************NEW LOGGING FRAMEWORK CHANGES START*****************************/
#ifdef LOG_PRINT_ENABLED

#ifdef ATTRIBUTE_COMP
void l2_log_check( UInt8 logLevel, UInt8 logModule, UInt64 logCategory,
        SInt8* str,...)__attribute__( ( format (printf, 4, 5 ) ) );
#define LOG_PRINT(logLev,logModule,logCat,str,...) l2_log_check(logLev,logModule,logCat,str, ## __VA_ARGS__);

#else
#ifdef SHM_PRINT_ENABLED
#define LOG_PRINT(logLev,logModule,logCat,str,...)\
    print_log((SInt8*)__FILE__,(SInt8*)__func__,__LINE__,logLev,logModule,logCat,(SInt8*)str,##__VA_ARGS__);
#elif (defined CONSOLE_PRINT_ENABLED)
#define LOG_PRINT(logLev,logModule,logCat,str,...)\
    console_print_log((SInt8*)__FILE__,(SInt8*)__func__,__LINE__,logLev,logModule,logCat,(SInt8*)str,##__VA_ARGS__);
#else
#define LOG_PRINT(logLev,logModule,logCat,str,...)
#endif
#endif

/********************MAC LOGS DEFINATION START******************************/
#ifdef NR_MAC_LOG_FATAL_ENABLE    
#define LOG_MAC_FATAL(logCat,str,...)\
do\
{\
    if((macloglevelEnabled_g[g_thd_cell_idx] & GNB_FATAL) &&\
       (maclogCategoryEnabled_g[g_thd_cell_idx] & logCat))\
    {\
        LOG_PRINT(GNB_FATAL,LOGMAC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_MAC_FATAL(logCat,str,...)
#endif

#ifdef NR_MAC_LOG_ERROR_ENABLE    
#define LOG_MAC_ERROR(logCat,str,...)\
do\
{\
    if((macloglevelEnabled_g[g_thd_cell_idx] & GNB_ERROR) &&\
       (maclogCategoryEnabled_g[g_thd_cell_idx] & logCat))\
    {\
        LOG_PRINT(GNB_ERROR,LOGMAC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_MAC_ERROR(logCat,str,...)
#endif

#ifdef NR_MAC_LOG_WARNING_ENABLE    
#define LOG_MAC_WARNING(logCat,str,...)\
do\
{\
    if((macloglevelEnabled_g[g_thd_cell_idx] & GNB_WARNING) &&\
       (maclogCategoryEnabled_g[g_thd_cell_idx] & logCat))\
    {\
        LOG_PRINT(GNB_WARNING,LOGMAC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_MAC_WARNING(logCat,str,...)
#endif

#ifdef NR_MAC_LOG_INFO_ENABLE    
#define LOG_MAC_INFO(logCat,str,...)\
do\
{\
    if((macloglevelEnabled_g[g_thd_cell_idx] & GNB_INFO) &&\
       (maclogCategoryEnabled_g[g_thd_cell_idx] & logCat))\
    {\
        LOG_PRINT(GNB_INFO,LOGMAC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_MAC_INFO(logCat,str,...)
#endif

#ifdef NR_MAC_LOG_BRIEF_ENABLE    
#define LOG_MAC_BRIEF(logCat,str,...)\
do\
{\
    if((macloglevelEnabled_g[g_thd_cell_idx] & GNB_BRIEF) &&\
       (maclogCategoryEnabled_g[g_thd_cell_idx] & logCat))\
    {\
        LOG_PRINT(GNB_BRIEF,LOGMAC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_MAC_BRIEF(logCat,str,...)
#endif

#ifdef NR_MAC_LOG_DEBUG_ENABLE    
#define LOG_MAC_DEBUG(logCat,str,...)\
do\
{\
    if((macloglevelEnabled_g[g_thd_cell_idx] & GNB_DETAILED) &&\
       (maclogCategoryEnabled_g[g_thd_cell_idx] & logCat))\
    {\
        LOG_PRINT(GNB_DETAILED,LOGMAC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_MAC_DEBUG(logCat,str,...)
#endif

#ifdef NR_MAC_LOG_TTI_DEBUG_ENABLE    
#define LOG_MAC_TTI_DEBUG(logCat,str,...)\
do\
{\
    if((macloglevelEnabled_g[g_thd_cell_idx] & GNB_DETAILEDALL) &&\
       (maclogCategoryEnabled_g[g_thd_cell_idx] & logCat))\
    {\
        LOG_PRINT(GNB_DETAILEDALL,LOGMAC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_MAC_TTI_DEBUG(logCat,str,...)
#endif

/********************MAC LOGS DEFINATION END******************************/

/********************RLC LOGS DEFINATION START******************************/
#ifdef NR_RLC_LOG_FATAL_ENABLE    
#define LOG_RLC_FATAL(logCat,str,...)\
do\
{\
    if((rlcloglevelEnabled_g & GNB_FATAL) &&\
       (rlclogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_FATAL,LOGRLC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_RLC_FATAL(logCat,str,...)
#endif

#ifdef NR_RLC_LOG_ERROR_ENABLE    
#define LOG_RLC_ERROR(logCat,str,...)\
do\
{\
    if((rlcloglevelEnabled_g & GNB_ERROR) &&\
       (rlclogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_ERROR,LOGRLC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_RLC_ERROR(logCat,str,...)
#endif

#ifdef NR_RLC_LOG_WARNING_ENABLE    
#define LOG_RLC_WARNING(logCat,str,...)\
do\
{\
    if((rlcloglevelEnabled_g & GNB_WARNING) &&\
       (rlclogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_WARNING,LOGRLC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_RLC_WARNING(logCat,str,...)
#endif

#ifdef NR_RLC_LOG_INFO_ENABLE    
#define LOG_RLC_INFO(logCat,str,...)\
do\
{\
    if((rlcloglevelEnabled_g & GNB_INFO) &&\
       (rlclogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_INFO,LOGRLC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_RLC_INFO(logCat,str,...)
#endif

#ifdef NR_RLC_LOG_BRIEF_ENABLE    
#define LOG_RLC_BRIEF(logCat,str,...)\
do\
{\
    if((rlcloglevelEnabled_g & GNB_BRIEF) &&\
       (rlclogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_BRIEF,LOGRLC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_RLC_BRIEF(logCat,str,...)
#endif

#ifdef NR_RLC_LOG_DEBUG_ENABLE    
#define LOG_RLC_DEBUG(logCat,str,...)\
do\
{\
    if((rlcloglevelEnabled_g & GNB_DETAILED) &&\
       (rlclogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_DETAILED,LOGRLC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_RLC_DEBUG(logCat,str,...)
#endif

#ifdef NR_RLC_LOG_TTI_DEBUG_ENABLE    
#define LOG_RLC_TTI_DEBUG(logCat,str,...)\
do\
{\
    if((rlcloglevelEnabled_g & GNB_DETAILEDALL) &&\
       (rlclogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_DETAILEDALL,LOGRLC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_RLC_TTI_DEBUG(logCat,str,...)
#endif
/********************RLC LOGS DEFINATION END******************************/

/********************PDCP LOGS DEFINATION START******************************/
#ifdef NR_PDCP_LOG_FATAL_ENABLE    
#define LOG_PDCP_FATAL(logCat,str,...)\
do\
{\
    if((pdcploglevelEnabled_g & GNB_FATAL) &&\
       (pdcplogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_FATAL,LOGPDCP,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_PDCP_FATAL(logCat,str,...)
#endif

#ifdef NR_PDCP_LOG_ERROR_ENABLE    
#define LOG_PDCP_ERROR(logCat,str,...)\
do\
{\
    if((pdcploglevelEnabled_g & GNB_ERROR) &&\
       (pdcplogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_ERROR,LOGPDCP,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_PDCP_ERROR(logCat,str,...)
#endif

#ifdef NR_PDCP_LOG_WARNING_ENABLE    
#define LOG_PDCP_WARNING(logCat,str,...)\
do\
{\
    if((pdcploglevelEnabled_g & GNB_WARNING) &&\
       (pdcplogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_WARNING,LOGPDCP,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_PDCP_WARNING(logCat,str,...)
#endif

#ifdef NR_PDCP_LOG_INFO_ENABLE    
#define LOG_PDCP_INFO(logCat,str,...)\
do\
{\
    if((pdcploglevelEnabled_g & GNB_INFO) &&\
       (pdcplogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_INFO,LOGPDCP,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_PDCP_INFO(logCat,str,...)
#endif

#ifdef NR_PDCP_LOG_BRIEF_ENABLE    
#define LOG_PDCP_BRIEF(logCat,str,...)\
do\
{\
    if((pdcploglevelEnabled_g & GNB_BRIEF) &&\
       (pdcplogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_BRIEF,LOGPDCP,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_PDCP_BRIEF(logCat,str,...)
#endif

#ifdef NR_PDCP_LOG_DEBUG_ENABLE    
#define LOG_PDCP_DEBUG(logCat,str,...)\
do\
{\
    if((pdcploglevelEnabled_g & GNB_DETAILED) &&\
       (pdcplogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_DETAILED,LOGPDCP,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_PDCP_DEBUG(logCat,str,...)
#endif

#ifdef NR_PDCP_LOG_TTI_DEBUG_ENABLE    
#define LOG_PDCP_TTI_DEBUG(logCat,str,...)\
do\
{\
    if((pdcploglevelEnabled_g & GNB_DETAILEDALL) &&\
       (pdcplogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_DETAILEDALL,LOGPDCP,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_PDCP_TTI_DEBUG(logCat,str,...)
#endif
/********************PDCP LOGS DEFINATION END******************************/

/********************RLCL LOGS DEFINATION START******************************/
#ifdef NR_RLCL_LOG_FATAL_ENABLE
#define LOG_RLCL_FATAL(logCat,str,...)\
do\
{\
    if((rlclloglevelEnabled_g & GNB_FATAL) &&\
       (rlcllogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_FATAL,LOGRLCL,logCat,str,##__VA_ARGS__)\
    }\
}while(0)
#else
#define LOG_RLCL_FATAL(logCat,str,...)
#endif

#ifdef NR_RLCL_LOG_ERROR_ENABLE
#define LOG_RLCL_ERROR(logCat,str,...)\
do\
{\
    if((rlclloglevelEnabled_g & GNB_ERROR) &&\
       (rlcllogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_ERROR,LOGRLCL,logCat,str,##__VA_ARGS__)\
    }\
}while(0)
#else
#define LOG_RLCL_ERROR(logCat,str,...)
#endif

#ifdef NR_RLCL_LOG_WARNING_ENABLE
#define LOG_RLCL_WARNING(logCat,str,...)\
do\
{\
    if((rlclloglevelEnabled_g & GNB_WARNING) &&\
       (rlcllogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_WARNING,LOGRLCL,logCat,str,##__VA_ARGS__)\
    }\
}while(0)
#else
#define LOG_RLCL_WARNING(logCat,str,...)
#endif

#ifdef NR_RLCL_LOG_INFO_ENABLE
#define LOG_RLCL_INFO(logCat,str,...)\
do\
{\
    if((rlclloglevelEnabled_g & GNB_INFO) &&\
       (rlcllogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_INFO,LOGRLCL,logCat,str,##__VA_ARGS__)\
    }\
}while(0)
#else
#define LOG_RLCL_INFO(logCat,str,...)
#endif

#ifdef NR_RLCL_LOG_BRIEF_ENABLE
#define LOG_RLCL_BRIEF(logCat,str,...)\
do\
{\
    if((rlclloglevelEnabled_g & GNB_BRIEF) &&\
       (rlcllogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_BRIEF,LOGRLCL,logCat,str,##__VA_ARGS__)\
    }\
}while(0)
#else
#define LOG_RLCL_BRIEF(logCat,str,...)
#endif

#ifdef NR_RLCL_LOG_DEBUG_ENABLE
#define LOG_RLCL_DEBUG(logCat,str,...)\
do\
{\
    if((rlclloglevelEnabled_g & GNB_DETAILED) &&\
       (rlcllogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_DETAILED,LOGRLCL,logCat,str,##__VA_ARGS__)\
    }\
}while(0)
#else
#define LOG_RLCL_DEBUG(logCat,str,...)
#endif

#ifdef NR_RLCL_LOG_TTI_DEBUG_ENABLE
#define LOG_RLCL_TTI_DEBUG(logCat,str,...)\
do\
{\
    if((rlclloglevelEnabled_g & GNB_DETAILEDALL) &&\
       (rlcllogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_DETAILEDALL,LOGRLCL,logCat,str,##__VA_ARGS__)\
    }\
}while(0)
#else
#define LOG_RLCL_TTI_DEBUG(logCat,str,...)
#endif
/********************RLCL LOGS DEFINATION END******************************/

/********************GTPUPR LOGS DEFINATION START******************************/
#ifdef NR_GTPUPR_LOG_FATAL_ENABLE    
#define LOG_GTPUPR_FATAL(logCat,str,...)\
do\
{\
    if((gtpuloglevelEnabled_g & GNB_FATAL) &&\
       (gtpulogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_FATAL,LOGGTPUPR,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_GTPUPR_FATAL(logCat,str,...)
#endif

#ifdef NR_GTPUPR_LOG_ERROR_ENABLE    
#define LOG_GTPUPR_ERROR(logCat,str,...)\
do\
{\
    if((gtpuloglevelEnabled_g & GNB_ERROR) &&\
       (gtpulogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_ERROR,LOGGTPUPR,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_GTPUPR_ERROR(logCat,str,...)
#endif

#ifdef NR_GTPUPR_LOG_WARNING_ENABLE    
#define LOG_GTPUPR_WARNING(logCat,str,...)\
do\
{\
    if((gtpuloglevelEnabled_g & GNB_WARNING) &&\
       (gtpulogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_WARNING,LOGGTPUPR,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_GTPUPR_WARNING(logCat,str,...)
#endif

#ifdef NR_GTPUPR_LOG_INFO_ENABLE    
#define LOG_GTPUPR_INFO(logCat,str,...)\
do\
{\
    if((gtpuloglevelEnabled_g & GNB_INFO) &&\
       (gtpulogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_INFO,LOGGTPUPR,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_GTPUPR_INFO(logCat,str,...)
#endif

#ifdef NR_GTPUPR_LOG_BRIEF_ENABLE    
#define LOG_GTPUPR_BRIEF(logCat,str,...)\
do\
{\
    if((gtpuloglevelEnabled_g & GNB_BRIEF) &&\
       (gtpulogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_BRIEF,LOGGTPUPR,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_GTPUPR_BRIEF(logCat,str,...)
#endif

#ifdef NR_GTPUPR_LOG_DEBUG_ENABLE    
#define LOG_GTPUPR_DEBUG(logCat,str,...)\
do\
{\
    if((gtpuloglevelEnabled_g & GNB_DETAILED) &&\
       (gtpulogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_DETAILED,LOGGTPUPR,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_GTPUPR_DEBUG(logCat,str,...)
#endif

#ifdef NR_GTPUPR_LOG_TTI_DEBUG_ENABLE    
#define LOG_GTPUPR_TTI_DEBUG(logCat,str,...)\
do\
{\
    if((gtpuloglevelEnabled_g & GNB_DETAILEDALL) &&\
       (gtpulogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_DETAILEDALL,LOGGTPUPR,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_GTPUPR_TTI_DEBUG(logCat,str,...)
#endif
/********************GTPUPR LOGS DEFINATION END******************************/

/********************SYNC LOGS DEFINATION START******************************/
#ifdef NR_SYNC_LOG_FATAL_ENABLE    
#define LOG_SYNC_FATAL(logCat,str,...)\
do\
{\
    if((syncloglevelEnabled_g & GNB_FATAL) &&\
       (synclogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_FATAL,LOGSYNC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_SYNC_FATAL(logCat,str,...)
#endif

#ifdef NR_SYNC_LOG_ERROR_ENABLE    
#define LOG_SYNC_ERROR(logCat,str,...)\
do\
{\
    if((syncloglevelEnabled_g & GNB_ERROR) &&\
       (synclogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_ERROR,LOGSYNC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_SYNC_ERROR(logCat,str,...)
#endif

#ifdef NR_SYNC_LOG_WARNING_ENABLE    
#define LOG_SYNC_WARNING(logCat,str,...)\
do\
{\
    if((syncloglevelEnabled_g & GNB_WARNING) &&\
       (synclogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_WARNING,LOGSYNC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_SYNC_WARNING(logCat,str,...)
#endif

#ifdef NR_SYNC_LOG_INFO_ENABLE    
#define LOG_SYNC_INFO(logCat,str,...)\
do\
{\
    if((syncloglevelEnabled_g & GNB_INFO) &&\
       (synclogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_INFO,LOGSYNC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_SYNC_INFO(logCat,str,...)
#endif

#ifdef NR_SYNC_LOG_BRIEF_ENABLE    
#define LOG_SYNC_BRIEF(logCat,str,...)\
do\
{\
    if((syncloglevelEnabled_g & GNB_BRIEF) &&\
       (synclogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_BRIEF,LOGSYNC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_SYNC_BRIEF(logCat,str,...)
#endif

#ifdef NR_SYNC_LOG_DEBUG_ENABLE    
#define LOG_SYNC_DEBUG(logCat,str,...)\
do\
{\
    if((syncloglevelEnabled_g & GNB_DETAILED) &&\
       (synclogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_DETAILED,LOGSYNC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_SYNC_DEBUG(logCat,str,...)
#endif

#ifdef NR_SYNC_LOG_TTI_DEBUG_ENABLE    
#define LOG_SYNC_TTI_DEBUG(logCat,str,...)\
do\
{\
    if((syncloglevelEnabled_g & GNB_DETAILEDALL) &&\
       (synclogCategoryEnabled_g & logCat))\
    {\
        LOG_PRINT(GNB_DETAILEDALL,LOGSYNC,logCat,str,##__VA_ARGS__)\
    }\
}while(0)    
#else
#define LOG_SYNC_TTI_DEBUG(logCat,str,...)
#endif
/********************SYNC LOGS DEFINATION END******************************/

#else

#define LOG_PRINT(logLev,logModule,logCat,str,...)

/***************MAC LOGS*************************/
#define LOG_MAC_FATAL(logCat,str,...)
#define LOG_MAC_ERROR(logCat,str,...)
#define LOG_MAC_WARNING(logCat,str,...)
#define LOG_MAC_INFO(logCat,str,...)
#define LOG_MAC_BRIEF(logCat,str,...)
#define LOG_MAC_DEBUG(logCat,str,...)
#define LOG_MAC_TTI_DEBUG(logCat,str,...)
/***************RLC LOGS*************************/
#define LOG_RLC_FATAL(logCat,str,...)
#define LOG_RLC_ERROR(logCat,str,...)
#define LOG_RLC_WARNING(logCat,str,...)
#define LOG_RLC_INFO(logCat,str,...)
#define LOG_RLC_BRIEF(logCat,str,...)
#define LOG_RLC_DEBUG(logCat,str,...)
#define LOG_RLC_TTI_DEBUG(logCat,str,...)

/***************RLCL LOGS*************************/
#define LOG_RLCL_FATAL(logCat,str,...)
#define LOG_RLCL_ERROR(logCat,str,...)
#define LOG_RLCL_WARNING(logCat,str,...)
#define LOG_RLCL_INFO(logCat,str,...)
#define LOG_RLCL_BRIEF(logCat,str,...)
#define LOG_RLCL_DEBUG(logCat,str,...)
#define LOG_RLCL_TTI_DEBUG(logCat,str,...)

/***************PDCP LOGS*************************/
#define LOG_PDCP_FATAL(logCat,str,...)
#define LOG_PDCP_ERROR(logCat,str,...)
#define LOG_PDCP_WARNING(logCat,str,...)
#define LOG_PDCP_INFO(logCat,str,...)
#define LOG_PDCP_BRIEF(logCat,str,...)
#define LOG_PDCP_DEBUG(logCat,str,...)
#define LOG_PDCP_TTI_DEBUG(logCat,str,...)

/***************GTPU PR LOGS*************************/
#define LOG_GTPUPR_FATAL(logCat,str,...)
#define LOG_GTPUPR_ERROR(logCat,str,...)
#define LOG_GTPUPR_WARNING(logCat,str,...)
#define LOG_GTPUPR_INFO(logCat,str,...)
#define LOG_GTPUPR_BRIEF(logCat,str,...)
#define LOG_GTPUPR_DEBUG(logCat,str,...)
#define LOG_GTPUPR_TTI_DEBUG(logCat,str,...)


/***************SYNC  LOGS*************************/
#define LOG_SYNC_FATAL(logCat,str,...)
#define LOG_SYNC_ERROR(logCat,str,...)
#define LOG_SYNC_WARNING(logCat,str,...)
#define LOG_SYNC_INFO(logCat,str,...)
#define LOG_SYNC_BRIEF(logCat,str,...)
#define LOG_SYNC_DEBUG(logCat,str,...)
#define LOG_SYNC_TTI_DEBUG(logCat,str,...)

#endif

/****************************************************************************
 * Exported Types
 ****************************************************************************/
typedef enum  
{
    LOGGER_FAILURE,
    LOGGER_SUCCESS
}logger_et;

enum
{
     LOGMAC=0x1,
     LOGPDCP=0x2,
     LOGRLC=0x4,
     LOGGTPUPR=0x8,
     LOGSYNC=0x10,
     LOGRLCL=0x20
};

#define ALL_LOG_LEVEL_SET ((2 * GNB_DETAILEDALL) - 1)
/*
 * Structure Used to store thread specific log info 
 */
typedef struct 
{
    void *p_shmptr;
    UInt32 file_size;
    UInt32 log_module;
    cell_index_t cell_index;
}log_info_t;


/****************************************************************************
 * Exported Constants
 ****************************************************************************/

/****************************************************************************
 * Exported Variables
 ****************************************************************************/
extern __thread UInt16 g_thd_cell_idx;
/****************************************************************************
 * Exported Functions
 ****************************************************************************/

/*
 * Used to initialize logger, By default all log area will be disabled,
 * thread_id(0,1,2...MAX_THREADS) should be unique to log file name
 */


logger_et logger_init(UInt32 thread_id, UInt32 log_module, SInt8 *p_log_file_name,UInt32 shmSize);
UInt32 cell_logger_init(UInt32 thread_id, cell_index_t cell_index, UInt32 log_module, SInt8 *p_log_file_name,UInt32 shmSize);

void enable_log_level(UInt32* log_level_var,UInt32 logLevel);
void enable_log_category(UInt64* log_category_var, UInt64 log_category);
UInt32 get_module_log_level(UInt32 log_module, cell_index_t cell_index);
/*
 * This function will register stack and log area. 
 */

/*
 * This function will deregister a log area of stack. 
 */

/*
 * This function is used to dump log in shared memory segment.
 */

void verifyLogArray(void);

#ifdef SHM_PRINT_ENABLED
void * prepare_tti_logs(void); 
#endif
void gnb_cp_trace(SInt8* fileName,SInt8* funcName,UInt32 lineNo,
        UInt8 logLevel,SInt8* str,...);
void print_log(SInt8* fileName,SInt8* funcName,UInt32 lineNo,
		UInt8 logLevel,UInt8 logModule,UInt64 logCategory,SInt8* str,...);
void console_print(UInt32 logId, UInt32 logLevel,UInt64 logCategory,
        time_in_ms_t globalTick,UInt32 intValOne,UInt32 intValTwo,UInt32 intValThree,
        UInt32 intValFour,UInt32 intValFive,
        const SInt8 *strValOne,const SInt8 *strValTwo);


/*****************************************************************************
 * Function Name  : start_log_reader
 * Description    : This function initializes the log reader for
 *                  execution schedulers.
 *****************************************************************************/
void start_log_reader(lteL2LogOption *l2Input_p,
        SInt8*             p_log_file_name);

/*****************************************************************************
 * Function Name  : get_pdcp_log_category_str_values
 * Description    : This function returns the string corresponding to 
 *                  received log category for PDCP module.
 *****************************************************************************/
const SInt8 *get_pdcp_log_category_str_values( UInt64 log_category );

/*****************************************************************************
 * Function Name  : get_pr_log_category_str_values
 * Description    : This function returns the string corresponding to 
 *                  received log category for PR module.
 *****************************************************************************/
const SInt8 *get_pr_log_category_str_values( UInt64 log_category );

/*****************************************************************************
 * Function Name  : prepare_log_reader_inputs
 * Description    : This function prepares the input for the log reader
 *****************************************************************************/
void prepare_log_reader_inputs( lteL2LogOption *l2_input_p, 
        SInt8* bin_name_p, UInt32* log_level_var);

/*****************************************************************************
 * Function Name  : prepareFileName
 * Description    : Prepare shared memory name for logging
 *****************************************************************************/
void prepareFileName( SInt8 *shm_region_name_p, UInt32 name_len, SInt8 *str_p,
        UInt8 index );

pid_t get_mainThreadPid_g(void);
pid_t get_du_binreader_pid(UInt8 index);
void set_du_binreader_pid(UInt8 index, pid_t value);
void change_cell_index_in_logging(cell_index_t cell_index);
UInt64 GetTimeStamp(void);
#endif
