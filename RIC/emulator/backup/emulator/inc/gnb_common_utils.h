/******************************************************************************
 *
 *   FILE NAME:
 *       gnb_common_utils.h
 *
 *   DESCRIPTION:
 *       This is the header file which contains miscellaneous porting functions.
 *
 *   DATE            AUTHOR             REFERENCE       REASON
 *   1 June 2018     Parvez Alam      ---------       Initial
 *
 *   Copyright (c) 2018, Aricent Inc. All Rights Reserved
 *
 ******************************************************************************/

#ifndef _GNB_COMMON_UTILS_H_
#define _GNB_COMMON_UTILS_H_

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/resource.h>
#include "gnb_defines.h"
#include "lteLogger.h"
//#include "misc.h"
#include "cspl.h"
#include "rrc_protocol_events.h"
#include "gnb_porting.h"
#include "rrc_defines.h"
#ifdef RRM_UT_FRAMEWORK
#include "advlogging.h"
#endif

#define MAX_MAC_ADDR_LENGTH               32
#define MAX_PORT_LENGTH                   6

#define ZERO                           0
#define HUNDRED                        100
#define MAX_STR_IP           64

#define RRC_UECC_STATS_SHM_KEY   3878
#define RRC_UECC_STATS_SHM_CREATE_FLAGS (IPC_CREAT | 0666)
#define RRC_UECC_STATS_SHM_LOCATE_FLAGS (0666)
#define MTC_LENGTH_SIZE 128

typedef struct sockaddr_in SockAddr;
typedef struct timeval timeVal;
typedef struct timezone timeZone;
typedef struct sockaddr_in6 sockAddrIn6;
typedef struct rlimit     rLimit;
//UInt32 init_stack_flag = 0; //FALSE
typedef YLIST list_t;
typedef YLNODE list_node_t ;
typedef UInt16             gnb_module_id_t;
YLNODE* list_pop_head(list_t *pList);
typedef const struct
{
    SInt8* thrd_info;
}oamh_health_monitor_desriptors_t;

void gnb_set_loglevel( UInt8 new_log_level   /* New RRC log level */);
UInt8 gnb_get_loglevel( void );
UInt16  get_ue_index(void);
UInt8   get_cell_index(void);
void set_cell_and_ue_index(cell_index_t cell_index, ue_index_t ue_index);
void set_cell_index(cell_index_t cell_index);
void set_ue_index(ue_index_t ue_index);
void rrc_generate_protocol_events(UInt8 log_level, void *p_api);
void rrc_update_health_monitor_variable( UInt32 health_monitor_event);

rrc_return_et rrc_check_cspl_header ( UInt8 *p_api);
rrc_return_et rrc_check_logger_type(UInt32 log_level);


UInt8 gnb_get_loglevel();



#define SET_CELL_INDEX(value) set_cell_index(value)
#define SET_CELL_AND_UE_INDEX(cell_index, ue_index) set_cell_and_ue_index(cell_index, ue_index)
#define GET_CELL_INDEX()      get_cell_index()
#define GET_UE_INDEX()        get_ue_index()
#define SET_UE_INDEX(value)   set_ue_index(value)
/* MEM_FENCING_LITE Fix Start */
#define rrc_mem_get(size)     rrc_mem_Get(size, __func__, __LINE__)
#define rrc_mem_free(p_buffer)  rrc_mem_Free(p_buffer, __func__, __LINE__)
/* MEM_FENCING_LITE Fix Stop */

const char* gnb_get_module_name(gnb_module_id_t); 
const char* gnb_get_api_name(UInt16,  gnb_module_id_t srcModuleId, gnb_module_id_t dstModuleId);

extern const char* extModuleName[];
extern const char* intModuleName[];
extern const char* rrc_pdcp_api_name[];
extern const char* rrc_pdcp_api_name[];
extern const char* rrc_s1u_api_name[];
extern const char* rrc_f1u_api_name[];
extern const char* rrc_rrm_api_name[];
extern const char* rrc_oam_api_name[];
extern const char* x2ap_oam_api_name[];
extern const char* f1ap_oam_api_name[];
/* CSR_00162022 Fix S*/
extern const char* ngap_oam_api_name[];
extern const char* xnap_oam_api_name[];
/* CSR_00162022 Fix E*/
extern const char* x2ap_rrm_api_name[];
extern const char* ngap_rrm_api_name[];
extern const char* xnap_rrm_api_name[];
extern const char* xnap_uecc_api_name[];
extern const char* xnap_csc_api_name[];
extern const char* ngap_son_api_name[];
extern const char* xnap_son_api_name[];
extern const char* csc_llim_api_name[];
extern const char* uecc_llim_api_name[];
extern const char* oamh_api_name[];
extern const char* csc_uecc_api_name[];
extern const char* x2ap_uecc_api_name[];
extern const char* x2ap_csc_api_name[];
extern const char* x2ap_sctp_api_name[];
extern const char* xnap_sctp_api_name[];
extern const char* ueccmd_uecc_api_name[];

typedef enum
{
    EVENT_VALUE_NO_X2_CONN_EXISTED=0,
    EVENT_VALUE_X2_CONN_LOST=1
}x2_conn_release_cause;

typedef enum
{
    EVENT_VALUE_SUCCESS=0,
    EVENT_VALUE_FAILURE=1,
    EVENT_VALUE_INVALID_FAMILY=2
}rrc_sctp_setup_result_et;

typedef enum
{
    EVENT_VALUE_MME=0,
    EVENT_VALUE_EXTERNAL_ENB=1
}rrc_sctp_endpoint_type_et;     //used to determine sctp endpoint type

typedef enum
{
    EVENT_VALUE_S_TMSI=0,
    EVENT_VALUE_RANDOM_VALUE=1
}rrc_conn_req_identifier_et;

typedef enum
{
    EVENT_VALUE_LOCAL=0,
    EVENT_VALUE_REMOTE=1
}rrc_conn_sctp_cause_et;    

#if defined(__x86_64__) || defined(__aarch64__)
#define UInt32_64_Bit unsigned long 
#else
#define UInt32_64_Bit unsigned int
#endif


void
gnb_msg_mem_free
(
 void *p_buffer /* Pointer to buffer which will be freed */
 );

void gnb_sys_mem_free
(
 void *p_buffer /* Pointer to buffer which will be freed */
 );

void* gnb_sys_mem_get
(
 rrc_size_t size /* Size of buffer which will be allocated */
 );

#ifdef MEM_FENCING_LITE
void write_cspl_string(void *p, const char* func, const unsigned int line, const char* func_old, const unsigned int line_old, unsigned long long fencing_start);
#endif


void rtPrintToStringDecrIndent();

void*
gnb_msg_mem_get
(
 gnb_size_t size /* Size of buffer which will be allocated */
 );


UInt8
gnb_send_message
(
 void            *p_msg,     /* Message that will be passed */
 gnb_module_id_t dst_module  /* Module id for which message will be passed */
 );


void*
rrc_asn_mem_get
(
 gnb_size_t size
 );

void
rrc_asn_mem_free
(
 void *p_buffer /* Pointer to buffer which will be freed */
 );


void rrc_free(void *p_var);

typedef enum
{
    MESSAGE_DIRECTION_RECEIVED=0,
    MESSAGE_DIRECTION_SEND=1
}rrc_message_direction_et;


#define RRC_MSG_RECVD "***************"
#define MAX_ASN_PRINT_BUFF_SIZE                 600000
/*BUG 604 changes start*/
#define RRC_INTRA_CELL_HO_PROC_CODE             0xFD
/*BUG 604 changes stop*/
#define RRC_INTER_CELL_HO_CANCEL_PROC_CODE      0xFE
#define RRC_INTER_CELL_HO_PROC_CODE             0xFF
/* Bug 8198 Fix Start */
#define RRC_INVALID_ESTABLISHMENT_CAUSE 0xFF
#define RRC_INVALID_MME_ID 0xFF
#define RRC_INVALID_REL_OF_MME 0xFF

#ifdef RRM_UT_FRAMEWORK
AdvL_ContextIndex        g_advl_ctxt_gnb;
#endif

void list_delete_node(list_t *pList, list_node_t *pNode);
list_node_t *list_first_node(const list_t *pList);
void list_push_tail(list_t *pList, list_node_t *pNode);
void list_push_head(list_t *pList, list_node_t *pNode);
list_node_t * list_next_node(const list_node_t *pNode);
UInt32 list_count(list_t *pList);

//#define GNB_ASSERT(exp)
void gnb_assert
(
 void* file,
 UInt32 line,
 void* expression
 );
typedef struct timespec TimeSpec;

SInt32 gettimeofday_wrapper(timeVal *tv,  timeZone *tz);
SInt32 fClose(FILE *fd);
SInt32 shmget_wrapper(UInt32 key, size_t size, SInt32 shmflg);
void bzero_wrapper(void *s, size_t n);
void *malloc_wrapper(size_t size);
SInt32 gettimeofday_wrapper(timeVal *tv,  timeZone *tz);
void lteFD_CLR(SInt32 fd, fd_set *set);

#define GNB_DRV_TRACE(log_level, format, ...) \
    GNB_LOG((const SInt8*)"CMES UDP Driver", log_level, format, ##__VA_ARGS__)
typedef struct _rrc_uecc_instance_stats_info_t
{
    UInt16 active_ue_count;
} rrc_uecc_instance_stats_info_t;

typedef struct _rrc_uecc_info_t
{
    UInt8  count;
    rrc_uecc_instance_stats_info_t     rrc_uecc_instance_stats[MAX_UECC_INSTANCES];
}rrc_uecc_info_t;


typedef struct _rrc_uecc_stats_info_t
{
    SInt32             rrc_shm_id;
    rrc_uecc_info_t   *p_rrc_uecc_info;
} rrc_uecc_stats_info_t;

rrc_uecc_stats_info_t g_rrc_uecc_stats;
rrc_return_et init_uecc_shared_mem_stats( void );
SInt32 select_wrapper(SInt32 nfds, fd_set *readfds, fd_set *writefds,
        fd_set *exceptfds, timeVal *timeout);

SInt32 lteFD_ISSET(SInt32 fd, fd_set *set);
void lteFD_SET(SInt32 fd, fd_set *set);
void lteFD_ZERO(fd_set *set);
UInt16 htons_wrapper (UInt16 hostshort);
UInt32 htonl_wrapper(UInt32 hostlong);
UInt32 ntohl_wrapper(UInt32 netshort);
UInt16 ntohs_wrapper(UInt16 netshort);
SInt32 socket_wrapper(SInt32 domain, SInt32 type, SInt32 protocol);
size_t strlen_wrapper(const SInt8 *s);
SInt32 snprintf_wrapper(SInt8 *s, size_t n, const SInt8  *format, ...);
SInt32 printf_wrapper(const SInt8 *fmt, ...);
SInt32 setrlimit_wrapper(SInt32 resource, const rLimit *rlim);
in_addr_t inet_addr_wrapper(const char *cp);
SInt32 getrlimit_wrapper(SInt32 resource, rLimit *rlim);
SInt32 memcmp_wrapper(const void *s1, const void *s2, size_t n);
SInt32 setsockopt_wrapper(SInt32 sockfd, SInt32 level, SInt32 optname,const void *optval, SInt32 optlen);
SInt32 close_wrapper(SInt32 fd);
void *shmat_wrapper(SInt32 shmid, const void *shmaddr, SInt32 shmflg);
void* memset_wrapper(void *s, SInt32 c, size_t n);
void clock_gettime_real_time(TimeSpec *ts_p);
#ifdef ALM_FRWK
#define ALARM_MSG_GNB(src_module_id,alarm_id,criticality,cause_id)    ALARM_MSG(src_module_id,alarm_id,criticality)
#define ALARM_FMT_MSG_GNB    ALARM_FMT_MSG
#else
#define ALARM_MSG_GNB(src_module_id, alarm_id, criticality,cause_id)
#define ALARM_FMT_MSG_GNB(src_module_id, alarm_id, criticality , ...)
#endif


extern const SInt8 *gnb_log_facility_name;
/* MEM_FENCING_LITE Fix Start */
void*
rrc_mem_Get
(
 gnb_size_t size, /* Size of buffer which will be allocated */
 const char *func, 
 const unsigned int line
 );

void
rrc_mem_Free
(
 void *p_buffer, /* Pointer to buffer which will be freed */
 const char *func, 
 const unsigned int line
 );
/* MEM_FENCING_LITE Fix Stop */
void gnb_trace_dbg(
        const SInt8* facility_name,UInt8 log_level,
        const char* format, ...);

lgr_log_level_et gnb_map_log_level(UInt8 log_level);

#define GNB_TRACE_DBG(facility_name,log_level,format, ...)   gnb_trace_dbg(facility_name, log_level, format, ## __VA_ARGS__);

#define GNB_TRACE_ASN(log_level, format, ...) \
    GNB_LOG_ASN(gnb_log_facility_name, log_level, format, ##__VA_ARGS__)

#ifdef GNB_DEBUG
#define GNB_UT_TRACE_ENTER() \
    GNB_TRACE(GNB_DETAILED, "Enterning function: %s, in file: %s \n", \
            __FUNCTION__, __FILE__)

#define GNB_UT_TRACE_EXIT() \
    GNB_TRACE(GNB_DETAILED, "Exiting function: %s, in file: %s \n", \
            __FUNCTION__, __FILE__)
#else
#define GNB_UT_TRACE_ENTER()
#define GNB_UT_TRACE_EXIT()
#endif

#ifdef RRM_UT_FRAMEWORK
#define GNB_LOG(facility_name, log_level, format, ...) \
{\
    AdvL_LogTarget logTarget = LogTarget_None; \
    if(LogSuccess == check_log_level(g_advl_ctxt_gnb, (AdvL_LogLevel)log_level, &logTarget)) {\
        write_log_message(g_advl_ctxt_gnb, (AdvL_LogLevel)log_level, __FILE__, __LINE__, \
                __func__ , (const char*)facility_name, GET_CELL_INDEX(), GET_UE_INDEX(), (const char*)format, ##__VA_ARGS__); \
    }\
}

#define GNB_LOG_ASN(facility_name, log_level, format, ...) \
{\
    AdvL_LogTarget logTarget = LogTarget_None; \
    if(LogSuccess == check_log_level(g_advl_ctxt_gnb, (AdvL_LogLevel)log_level, &logTarget)) {\
        write_log_message_asn(g_advl_ctxt_gnb, (AdvL_LogLevel)log_level, __FILE__, __LINE__, \
                __func__ , (const char*)facility_name, GET_CELL_INDEX(), GET_UE_INDEX(), (const char*)format, ##__VA_ARGS__); \
    }\
}
#else
#define GNB_LOG(facility_name, log_level, format, ...) \
{\
    lgr_log_level_et logLevel = LGR_TRACE; \
    UInt8 log_level_bitmask = 0;\
    logLevel = gnb_map_log_level(log_level);\
    log_level_bitmask = gnb_get_loglevel();\
    if((log_level & log_level_bitmask) ){\
        print_log_message((UInt32)logLevel, __FILE__, __LINE__, __func__,\
                (const char*)facility_name, GET_CELL_INDEX(), GET_UE_INDEX(), LGR_TRUE, (const char*)format, ##__VA_ARGS__); \
    }\
}

#define GNB_LOG_ASN(facility_name, log_level, format, ...) \
{\
    lgr_log_level_et logLevel = LGR_TRACE; \
    logLevel = gnb_map_log_level(log_level);\
    print_log_message((UInt32)logLevel, __FILE__, __LINE__, __func__,\
            (const char*)facility_name, GET_CELL_INDEX(), GET_UE_INDEX(), LGR_TRUE, (const char*)format, ##__VA_ARGS__); \
}
#endif

void gnb_cp_trace(SInt8* fileName,SInt8* funcName,UInt32 lineNo,
        UInt8 logLevel,SInt8* str,...);

#define GNB_TRACE(log_level, format, ...) \
    GNB_LOG(gnb_log_facility_name, log_level, format, ##__VA_ARGS__)

#define GNB_COMP_PARSE     GNB_DETAILEDALL            
#define GNB_PNULL          NULL
#define GNB_P_NULL ( (void*)0)




#ifndef LOGGING_ENHANCEMENT_CELL_AND_UE_INDEX_STRUCT
#define LOGGING_ENHANCEMENT_CELL_AND_UE_INDEX_STRUCT
typedef struct _cell_and_ue_index
{
    cell_index_t  cell_index;
    ue_index_t ue_index;
} cell_and_ue_index;
#endif
void*
gnb_msg_mem_get
(
 gnb_size_t size /* Size of buffer which will be allocated */
 );

#endif /* _GNB_COMMON_UTILS_H_ */
