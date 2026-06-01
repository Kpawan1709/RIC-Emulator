/*******************************************************************************
 *
 *  ARICENT - 
 *  Copyright (C) 2018 Aricent Inc. All Rights Reserved.
 *
 *******************************************************************************
 *
 *  File Name : gnb_utils.h
 *
 *******************************************************************************
 *
 *  File Description : Header file for Utility functions used across modules
 *
 ******************************************************************************/
#ifndef _GNB_UTILS_H_
#define _GNB_UTILS_H_

/*******************************************************************************
 * Project Includes
 ******************************************************************************/
#include "gnb_defines.h"
#include "gnb_profile.h"

/*******************************************************************************
 * Exported Constants 
 ******************************************************************************/
#define STATS_SHM_KEY   34432
#define STATS_SHM_FLAGS (IPC_CREAT | 0666)
#define MAX_TTI_STATS   1000

/*******************************************************************************
 * Structure Typedefs 
 ******************************************************************************/
typedef enum
{
    MAC,
    PDCP,
    RLC,
    RLC_LOWER,
    GTPU_PR,
    MAX_MODULE_NAME
}module_name_et;

typedef struct pdcp_queue_stats_t
{
    /* array of 10 for maximum number of threads */
    UInt16         num_dl_packets_receiver_to_worker[10];
    UInt16         num_dl_packet_worker_to_sdu_queue[10];
    UInt16         num_dl_packet_drb_sdu_to_async[10];
    UInt16         num_dl_packet_srb_sdu_to_async[10];
    UInt16         num_dl_packet_async_to_f1_x2_worker[10];
    UInt16         num_dl_packet_to_x2[10];
    UInt16         num_dl_packet_to_du[10];
    UInt16         num_dl_packet_to_hw_queue[10];
    UInt16         num_dl_packet_from_hw_queue[10];
    UInt16         num_dl_s1_packet_to_pdcp[10];
    UInt16         num_dl_fwd_packet_to_pdcp[10];
    UInt16         num_dl_fwd_packet_from_pdcp[10];
    UInt16         num_dl_pdcp_sdu_buff_free;
    UInt16         num_poll_discard_packet[10];
    UInt16         num_poll_discard_packet_x2[10];

    UInt16         num_ul_packet_from_x2[10];
    UInt16         num_ul_packet_from_du[10];
    UInt16         num_ul_packet_worker_to_sdu_queue[10];
    UInt16         num_ul_packet_drb_pdu_to_async[10];
    UInt16         num_ul_packet_srb_pdu_to_async[10];
    UInt16         num_ul_packet_snd_to_s1[10];
    UInt16         num_ul_fwd_packet_to_pdcp[10];
    UInt16         num_ul_fwd_packet_from_pdcp[10];
    UInt16         num_ddds_packet_from_x2[10];
    UInt16         num_ddds_packet_from_du[10];
    UInt16         num_ddds_packet_in_pdcp_worker[10];
} pdcp_queue_stats;

#ifdef SHM_DEBUG_STATS

#define NUM_DL_PACKETS_RECEIVER_TO_WORKER(thd_idx){\
    g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
    num_dl_packets_receiver_to_worker[worker_thd_idx]++;\
}

#define NUM_DL_PACKET_WORKER_TO_SDU_QUEUE(thd_idx){\
    g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
    num_dl_packet_worker_to_sdu_queue[thd_idx]++;\
}

#define NUM_UL_PACKET_WORKER_TO_SDU_QUEUE(thd_idx){\
    g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
    num_ul_packet_worker_to_sdu_queue[thd_idx]++;\
}

#define NUM_DL_PACKET_DRB_SDU_TO_ASYNC(thd_idx){\
    g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
    num_dl_packet_drb_sdu_to_async[thd_idx]++;\
}

#define NUM_DL_PACKET_SRB_SDU_TO_ASYNC(thd_idx){\
    g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
    num_dl_packet_srb_sdu_to_async[thd_idx]++;\
}

#define NUM_DL_PACKET_ASYNC_TO_F1_X2_WORKER(thd_idx){\
    g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
    num_dl_packet_async_to_f1_x2_worker[thd_idx]++;\
}

#define NUM_DL_PACKET_TO_F1_X2(relay_type,thd_idx){\
    if( F1U_RELAY_MODE == relay_type ){\
        g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
        num_dl_packet_to_du[thd_idx]++; \
    }\
    else{\
        g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
        num_dl_packet_to_x2[thd_idx]++;\
    }\
}

#define NUM_DDDS_PACKETS_IN_PDCP_WORKER(thd_idx){\
    g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
    num_ddds_packet_in_pdcp_worker[thd_idx]++;\
}

#define NUM_DDDS_PACKETS_FROM_F1_X2(relay_type,thd_idx){\
    if( F1U_RELAY_MODE == relay_type ){\
        g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
        num_ddds_packet_from_du[thd_idx]++; \
    }\
    else{\
        g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
        num_ddds_packet_from_x2[thd_idx]++; \
    }\
}

#define NUM_UL_PACKET_FROM_F1_X2(relay_type,thd_idx){\
    if( X2U_RELAY_MODE == relay_type ){\
        g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
        num_ul_packet_from_x2[thd_idx]++;\
    }\
    else {\
        g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
        num_ul_packet_from_du[thd_idx]++;\
    }\
}

#define NUM_UL_PACKET_DRB_PDU_TO_ASYNC(thd_idx){\
    g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
            num_ul_packet_drb_pdu_to_async[thd_idx]++;\
}

#define NUM_UL_PACKET_SRB_PDU_TO_ASYNC(thd_idx){\
    g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
            num_ul_packet_srb_pdu_to_async[thd_idx]++;\
}

#define NUM_UL_PACKET_SND_TO_S1(thd_idx){\
    g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
                num_ul_packet_snd_to_s1[thd_idx]++;\
}
#define NUM_UL_FWD_PACKET_TO_PDCP(thd_idx){\
    g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
                num_ul_fwd_packet_to_pdcp[thd_idx]++;\
}
#define NUM_UL_FWD_PACKET_FROM_PDCP(thd_idx){\
    g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
                num_ul_fwd_packet_from_pdcp[thd_idx]++;\
}
#define NUM_DL_PACKET_TO_HW_QUEUE(thd_idx,num_packet){\
    g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
                num_dl_packet_to_hw_queue[thd_idx] += num_packet;\
}
#define NUM_DL_PACKET_FROM_HW_QUEUE(thd_idx){\
    g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
                num_dl_packet_from_hw_queue[thd_idx]++;\
}
#define NUM_DL_S1_PACKET_TO_PDCP(thd_idx){\
    g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
                num_dl_s1_packet_to_pdcp[thd_idx]++;\
}
#define NUM_DL_FWD_PACKET_TO_PDCP(thd_idx){\
    g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
                num_dl_fwd_packet_to_pdcp[thd_idx]++;\
}
#define NUM_DL_FWD_PACKET_FROM_PDCP(thd_idx){\
    g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
                num_dl_fwd_packet_from_pdcp[thd_idx]++;\
}
#define NUM_DL_PDCP_SDU_BUFF_FREE(){\
    g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
    num_dl_pdcp_sdu_buff_free++;\
}
#define NUM_POLL_DISCARD_PACKET(relay_type,thd_idx){\
    if( F1U_RELAY_MODE == relay_type ){\
        g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
        num_poll_discard_packet[thd_idx]++;\
    }\
    else {\
        g_debug_stats.p_stats->queue_stats[g_debug_stats.p_stats->write_idx].\
        num_poll_discard_packet_x2[thd_idx]++;\
    }\
}
#elif defined GETSTATS_EL_CLOCKTIME
#define NUM_SRB_DL_PACKET_RECV(thd_idx)
#define NUM_SRB_UL_PACKET_RECV(thd_idx)
#define NUM_S1_DL_PACKET_RECV_STATS(thd_idx)
#define NUM_DL_PACKETS_RECEIVER_TO_WORKER(thd_idx)
#define NUM_DL_PACKET_WORKER_TO_SDU_QUEUE(thd_idx)
#define NUM_UL_PACKET_WORKER_TO_SDU_QUEUE(thd_idx)
#define NUM_DL_PACKET_DRB_SDU_TO_ASYNC(thd_idx)
#define NUM_DL_PACKET_SRB_SDU_TO_ASYNC(thd_idx)
#define NUM_DL_PACKET_ASYNC_TO_F1_X2_WORKER(thd_idx)
#define NUM_DL_PACKET_TO_F1_X2(relay_type,thd_idx)
#define NUM_UL_PACKET_FROM_F1_X2(relay_type,thd_idx)
#define NUM_DDDS_PACKETS_IN_PDCP_WORKER(thd_idx)
#define NUM_UL_PACKET_DRB_PDU_TO_ASYNC(thd_idx)
#define NUM_UL_PACKET_SRB_PDU_TO_ASYNC(thd_idx)
#define NUM_DDDS_PACKETS_FROM_F1_X2(relay_type,thd_idx)
#define NUM_UL_PACKET_SND_TO_S1(thd_idx)                      
#define NUM_UL_FWD_PACKET_TO_PDCP(thd_idx)
#define NUM_UL_FWD_PACKET_FROM_PDCP(thd_idx)
#define NUM_DL_PACKET_TO_HW_QUEUE(thd_idx,num_packet)
#define NUM_DL_PACKET_FROM_HW_QUEUE(thd_idx)
#define NUM_DL_S1_PACKET_TO_PDCP(thd_idx)
#define NUM_DL_FWD_PACKET_TO_PDCP(thd_idx)
#define NUM_DL_FWD_PACKET_FROM_PDCP(thd_idx)
#define NUM_DL_PDCP_SDU_BUFF_FREE()
#define NUM_POLL_DISCARD_PACKET(relay_type,thd_idx)
#else
#define NUM_SRB_DL_PACKET_RECV(thd_idx)
#define NUM_SRB_UL_PACKET_RECV(thd_idx)
#define NUM_S1_DL_PACKET_RECV_STATS(thd_idx)
#define NUM_DL_PACKETS_RECEIVER_TO_WORKER(thd_idx)
#define NUM_DL_PACKET_WORKER_TO_SDU_QUEUE(thd_idx)
#define NUM_UL_PACKET_WORKER_TO_SDU_QUEUE(thd_idx)
#define NUM_DL_PACKET_DRB_SDU_TO_ASYNC(thd_idx)
#define NUM_DL_PACKET_SRB_SDU_TO_ASYNC(thd_idx)
#define NUM_DL_PACKET_ASYNC_TO_F1_X2_WORKER(thd_idx)
#define NUM_DL_PACKET_TO_F1_X2(relay_type,thd_idx)
#define NUM_DDDS_PACKETS_IN_PDCP_WORKER(thd_idx)
#define NUM_DDDS_PACKETS_FROM_F1_X2(relay_type,thd_idx)
#define NUM_UL_PACKET_FROM_F1_X2(relay_type,thd_idx)
#define NUM_UL_PACKET_DRB_PDU_TO_ASYNC(thd_idx)
#define NUM_UL_PACKET_SRB_PDU_TO_ASYNC(thd_idx)
#define NUM_UL_PACKET_SND_TO_S1(thd_idx)
#define NUM_UL_FWD_PACKET_TO_PDCP(thd_idx)
#define NUM_UL_FWD_PACKET_FROM_PDCP(thd_idx)
#define NUM_DL_PACKET_TO_HW_QUEUE(thd_idx,num_packet)
#define NUM_DL_PACKET_FROM_HW_QUEUE(thd_idx)
#define NUM_DL_S1_PACKET_TO_PDCP(thd_idx)
#define NUM_DL_FWD_PACKET_TO_PDCP(thd_idx)
#define NUM_DL_FWD_PACKET_FROM_PDCP(thd_idx)
#define NUM_DL_PDCP_SDU_BUFF_FREE()
#define NUM_POLL_DISCARD_PACKET(relay_type,thd_idx)
#endif

#ifdef GETSTATS_EL_CLOCKTIME 
typedef struct cycle_count_t
{
    UInt32         avg_cycle_count[10];
    UInt32         max_cycle_count[10];
    UInt32         sum_cycle_count[10];
    UInt32         packet_count[10];
} cycle_count;

typedef struct el_stats_t
{
    /* array of 10 for maximum number of threads */
    cycle_count    cycle_info[MAX_MODULE_NAME][80];
}el_stats;

typedef struct el_sfn_slot_stats_t
{
   UInt32    cycle_info[80];
}el_sfn_slot_stats;
#endif

typedef struct debug_stats_t
{
    UInt16           write_idx;
    UInt16           mac_write_idx;
    pdcp_queue_stats queue_stats[MAX_TTI_STATS];

#ifdef GETSTATS_EL_CLOCKTIME 
    el_stats                 el_stats[MAX_TTI_STATS];
    el_sfn_slot_stats        el_sfn_slot_stats[MAX_NUM_CELL_PER_DU][1024][80];
    UInt32                   max_cycle_info[80];
    UInt16                   slots_in_sfn;
    UInt8                    num_active_cells;
#endif
} debug_stats;

/* Global structure defining the shared memory for statistics */
typedef struct debug_stats_info_t
{
    SInt32 shm_id;
    debug_stats *p_stats;
} debug_stats_info;

extern debug_stats_info g_debug_stats;

/****************************************************************************
 * Function Name  : logBacktrace
 * Description    : This API logs the current stack backtrace.
 ****************************************************************************/
#define logBacktrace do {\
    UInt32 j,nptrs; \
    void *buffer[100] = {0}; \
    /* get the backtrace for received signal */ \
    nptrs = backtrace_wrapper(buffer, 100); \
    printf_wrapper("Received signal %d\n", signum); \
    for (j = 0; j < nptrs; j+=5) \
    { \
        printf_wrapper("0x%x\n", *(UInt32 *)buffer[j]); \
    } \
} while (0)

/*******************************************************************************
 * Function Prototypes 
 ******************************************************************************/

/*****************************************************************************
 * Function Name  : rdtsc_and_clock_start_count 
 * Description    : Start Timer for EL Stats
 ****************************************************************************/
void  rdtsc_and_clock_start_count(
         UInt16 funcId);

/*****************************************************************************
 * Function Name  : rdtsc_and_clock_end_count 
 * Description    : End Timer for EL Stats
 ****************************************************************************/
void rdtsc_and_clock_end_count(
         UInt16           funcId, 
         UInt16           *p_stats_cycle_num,
         UInt16           sfn,
         UInt16           slot);

/*****************************************************************************
 * Function Name  : setrlimit_of_core
 * Description    : Sets Limit of the core
 ****************************************************************************/
UInt32 setrlimit_of_core(void);

/****************************************************************************
 * Function Name  : set_fatal_signal_handlers
 * Description    : This API handles fatal signal received.
 ****************************************************************************/
void set_fatal_signal_handlers(void);

/****************************************************************************
 * Function Name  : handleFatalSignal
 * Description    : This API handles fatal signal received.
 ****************************************************************************/
void handleFatalSignal( SInt32 signum);
void handleSigInt( SInt32 signum);
void handleStopEvent( SInt32 signum );

/****************************************************************************
 * Function Name  : enable_debug_traceback
 * Description    : This API initialize the debugging for crash handling
 ****************************************************************************/
UInt32 enable_debug_traceback(void);

/****************************************************************************
 * Function Name  : init_shm_stats
 * Description    : This API opens the shared memory to dump statistics
 *                  for debugging
 ****************************************************************************/
void init_shm_stats(void);


#endif /* _GNB_UTILS_H_ */
