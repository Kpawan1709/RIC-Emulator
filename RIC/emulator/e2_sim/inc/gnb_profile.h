/******************************************************************************
*
*   FILE NAME:
*       gnb_profile.h
*
*   DESCRIPTION:
*       This is the header file which contains miscellaneous porting functions.
*
*   DATE            AUTHOR             REFERENCE       REASON
*   16 Aug 2018     Kranti Goyal      ---------       Initial
*
*   Copyright (c) 2018, Aricent Inc. All Rights Reserved
*
******************************************************************************/

#ifndef _GNB_PROFILE_H_
#define _GNB_PROFILE_H_

#include "gnb_types.h"
#ifdef GETSTATS_EL_CLOCKTIME 
#include "x86intrin.h"
#include "gnb_utils.h"
#endif

__inline__ unsigned long long rdtsc(void);
#define RDTSC_MAX ULLONG_MAX
#ifdef GETSTATS_EL_CLOCKTIME 
#define __rdtsc rdtsc

extern __thread unsigned long long g_prof_max_count[5][MAX_EL_COUNT];
extern __thread unsigned long long g_prof_cycle_count_sum[5][MAX_EL_COUNT];
extern __thread unsigned long long g_prof_packet_count[5][MAX_EL_COUNT];
extern __thread UInt8 g_stats_cycle_num[5][MAX_EL_COUNT];
extern __thread unsigned long long g_prof_start_count;
extern __thread unsigned long long g_prof_end_count;
extern __thread unsigned long long g_prof_cycle_count_used[5][MAX_EL_COUNT];
extern __thread unsigned long long g_prof_start_slot_diff;
extern __thread unsigned long long g_prof_end_slot_diff;
extern unsigned long long g_prof_start_sem_diff;
extern unsigned long long g_prof_end_sem_diff;
extern __thread unsigned long long g_tick_start_count;
extern __thread unsigned long long g_tick_end_count;
extern __thread unsigned long long g_tick_cycle_count_used;
extern __thread unsigned long long g_code_block_cycle_count_used;
extern __thread unsigned long long g_code_block_start_count;
extern __thread unsigned long long g_code_block_end_count;


#endif



extern SInt8 *mac_el_name[];

extern SInt8 *rlc_el_name[];

extern SInt8 *rlcl_el_name[];

extern SInt8 *gtpupr_el_name[];

extern SInt8 *pdcp_el_name[];
void clock_gettime_wrapper(ClockId clk_id,TimeSpec *ts_p);
#ifdef GETSTATS_EL_CLOCKTIME
#define PRINT_EL_STATS_BASED_ON_MODULE_ID(module_id, funcId, average, thread_id)\
{\
    UInt16 idx = g_debug_stats.p_stats->write_idx; \
    if(module_id == MAC) \
    { \
        idx = g_debug_stats.p_stats->mac_write_idx; \
    } \
    g_debug_stats.p_stats->el_stats[idx].cycle_info[module_id][funcId].avg_cycle_count[thread_id] = average; \
    g_debug_stats.p_stats->el_stats[idx].cycle_info[module_id][funcId].max_cycle_count[thread_id] = g_prof_max_count[module_id][funcId]; \
    g_debug_stats.p_stats->el_stats[idx].cycle_info[module_id][funcId].sum_cycle_count[thread_id] = g_prof_cycle_count_sum[module_id][funcId]; \
    g_debug_stats.p_stats->el_stats[idx].cycle_info[module_id][funcId].packet_count[thread_id] = g_prof_packet_count[module_id][funcId]; \
\
    /*while (1)*/ \
    {\
    switch(module_id)\
    {\
        case MAC:\
        {\
            LOG_MAC_INFO(MAC_OAM_INF,"Thread_id: %d Function_id: %s Average_cycle_count: %llu Maximum_cycle_count: %llu",\
                thread_id,\
                (SInt8 *)mac_el_name[funcId],\
                average,\
                g_prof_max_count[module_id][funcId]);\
        }\
        break;\
        /*
        case RLC:\
        {\
            LOG_RLC_INFO(RLC_OAM,\
                    "Thread_ID: %d Function ID: %s Average_cycle_count: %llu Maximum_cycle_count: %llu",\
                    thread_id, (SInt8 *)rlc_el_name[funcId],\
                    average,\
                    g_prof_max_count[module_id][funcId]);\
        }\
        break;\
        case GTPU_PR:\
        {\
            LOG_GTPUPR_INFO(F1U_OAM,\
                    "Thread_id: %d Function_id: %s Average_cycle_count: %llu Maximum_cycle_ount: %llu",\
                    thread_id, (SInt8 *)gtpupr_el_name[funcId],\
                    average, g_prof_max_count[module_id][funcId]);\
        }\
        break;\
        case RLC_LOWER:\
        {\
            LOG_RLCL_INFO(RLCL_RLC ,\
                    "Thread_id: %d Function_id: %s Average_cycle_count: %llu Maximum_cycle_count: %llu",\
                    thread_id, (SInt8 *)rlcl_el_name[funcId],\
                    average, g_prof_max_count[module_id][funcId]);\
        }\
        break;\
        case PDCP:\
        {\
            LOG_PDCP_INFO(PDCP_OAM ,\
                    "Thread_id: %d Function_id: %s Average_cycle_count: %llu Maximum_cycle_count: %llu",\
                    thread_id, (SInt8 *)pdcp_el_name[funcId],\
                    average, g_prof_max_count[module_id][funcId]);\
        }\
        break;\ */\
        default:\
        {\
            /* Nothing to do */\
        }\
        break;\
    }\
    }\
}

#endif

#ifdef GETSTATS_EL_CLOCKTIME 
#define RDTSC_AND_CLOCK_CODE_SECTION_START() \
{\
    do{\
        g_code_block_start_count = __rdtsc();\
    }while(0);\
}

#define RDTSC_AND_CLOCK_CODE_SECTION_END(segment_str) \
{\
    do {\
        g_code_block_end_count= __rdtsc();\
        if(g_code_block_start_count > g_code_block_end_count)\
        {\
            g_code_block_cycle_count_used = RDTSC_MAX - g_code_block_start_count + g_code_block_end_count;\
        }\
        else\
        {\
            g_code_block_cycle_count_used = g_code_block_end_count - g_code_block_start_count;\
        }\
        LOG_MAC_FATAL(MAC_OAM_INF,"[%s] Cycle_count: %llu Time: %llu us", (SInt8 *)segment_str, g_code_block_cycle_count_used, g_code_block_cycle_count_used/2200);\
    }while (0);\
}
#define RDTSC_AND_CLOCK_TICK_START() \
{\
    do{\
        g_tick_start_count = __rdtsc();\
    }while(0);\
}

#define RDTSC_AND_CLOCK_TICK_END() \
{\
    do {\
        g_tick_end_count= __rdtsc();\
        if(g_tick_start_count > g_tick_end_count)\
        {\
            g_tick_cycle_count_used = RDTSC_MAX - g_tick_start_count + g_tick_end_count;\
        }\
        else\
        {\
            g_tick_cycle_count_used = g_tick_end_count - g_tick_start_count;\
        }\
        LOG_MAC_FATAL(MAC_OAM_INF,"Slot Cycle_count: %llu", g_tick_cycle_count_used);\
    }while (0);\
}
#define  RDTSC_AND_CLOCK_START()\
{\
    do{\
        g_prof_start_count = __rdtsc();\
    }while (0);\
}
#define  RDTSC_AND_CLOCK_START_MAC(tti)\
{\
    do{\
        g_prof_start_count = __rdtsc();\
    }while (0);\
    tti = g_prof_start_count;\
}	
#define  RDTSC_AND_CLOCK_START_SLOT_DIFF()\
{\
    do{\
        g_prof_start_slot_diff = __rdtsc();\
    }while (0);\
}
#define  RDTSC_AND_CLOCK_START_SEM_DIFF()\
{\
    do{\
        g_prof_start_sem_diff = __rdtsc();\
    }while (0);\
}
#else
#define RDTSC_AND_CLOCK_CODE_SECTION_START()
#define RDTSC_AND_CLOCK_CODE_SECTION_END(seg_str)
#define RDTSC_AND_CLOCK_TICK_END() 
#define RDTSC_AND_CLOCK_TICK_START()
#define RDTSC_AND_CLOCK_START()
#define  RDTSC_AND_CLOCK_START_MAC(tti)
#define  RDTSC_AND_CLOCK_START_SLOT_DIFF()
#define  RDTSC_AND_CLOCK_START_SEM_DIFF()
#endif
#ifdef GETSTATS_EL_CLOCKTIME 
#define RDTSC_AND_CLOCK_END(funcId, module_id, thread_id, pkt_cnt)\
{\
    do {\
        g_prof_end_count= __rdtsc();\
        if(g_prof_start_count > g_prof_end_count)\
        {\
            g_prof_cycle_count_used[module_id][funcId] = RDTSC_MAX - g_prof_start_count + g_prof_end_count;\
        }\
        else\
        {\
            g_prof_cycle_count_used[module_id][funcId] = g_prof_end_count - g_prof_start_count;\
        }\
    }while (0);\
    if(g_prof_max_count[module_id][funcId] < g_prof_cycle_count_used[module_id][funcId])\
    {\
        g_prof_max_count[module_id][funcId] = g_prof_cycle_count_used[module_id][funcId];\
    }\
    g_prof_cycle_count_sum[module_id][funcId] += g_prof_cycle_count_used[module_id][funcId];\
    g_prof_packet_count[module_id][funcId] += pkt_cnt;\
    if( MAC == module_id ) { \
        g_debug_stats.p_stats->el_sfn_slot_stats[g_thd_cell_idx][thread_id][pkt_cnt].cycle_info[funcId] = g_prof_cycle_count_used[module_id][funcId]; \
        if( g_debug_stats.p_stats->max_cycle_info[funcId] < g_prof_cycle_count_used[module_id][funcId] )\
        {\
            g_debug_stats.p_stats->max_cycle_info[funcId] = g_prof_cycle_count_used[module_id][funcId];\
        }\
        {\
            LOG_MAC_FATAL(MAC_OAM_INF,"Function_id: %s Cycle_count: %llu Time: %llu us Maximum_cycle_count: %llu",\
                (SInt8 *)mac_el_name[funcId],\
                g_prof_cycle_count_used[module_id][funcId],\
                (g_prof_cycle_count_used[module_id][funcId]/2200),\
                g_prof_max_count[module_id][funcId]);\
        }\
    } \
    if((g_stats_cycle_num[module_id][funcId] + 1) == 100)\
    {\
        unsigned long long average = 0;\
        average = ((g_prof_cycle_count_sum[module_id][funcId])/100);\
        PRINT_EL_STATS_BASED_ON_MODULE_ID(module_id, funcId, average, thread_id);\
        g_prof_cycle_count_sum[module_id][funcId] = 0;\
        g_prof_max_count[module_id][funcId] = 0;\
        g_stats_cycle_num[module_id][funcId] = 0;\
        g_prof_packet_count[module_id][funcId] = 0;\
    }\
    else\
    {\
        g_stats_cycle_num[module_id][funcId]++;\
    }\
}
#define RDTSC_AND_CLOCK_END_SLOT_DIFF(funcId, module_id, thread_id, pkt_cnt)\
{\
    do {\
        g_prof_end_slot_diff = __rdtsc();\
        if(g_prof_start_slot_diff > g_prof_end_slot_diff)\
        {\
            g_prof_cycle_count_used[module_id][funcId] = RDTSC_MAX - g_prof_start_slot_diff + g_prof_end_slot_diff;\
        }\
        else\
        {\
            g_prof_cycle_count_used[module_id][funcId] = g_prof_end_slot_diff - g_prof_start_slot_diff;\
        }\
    }while (0);\
    if(g_prof_max_count[module_id][funcId] < g_prof_cycle_count_used[module_id][funcId])\
    {\
        g_prof_max_count[module_id][funcId] = g_prof_cycle_count_used[module_id][funcId];\
    }\
    g_prof_cycle_count_sum[module_id][funcId] += g_prof_cycle_count_used[module_id][funcId];\
    g_prof_packet_count[module_id][funcId] += pkt_cnt;\
    if( MAC == module_id ) { \
        g_debug_stats.p_stats->el_sfn_slot_stats[g_thd_cell_idx][thread_id][pkt_cnt].cycle_info[funcId] = g_prof_cycle_count_used[module_id][funcId]; \
        if( g_debug_stats.p_stats->max_cycle_info[funcId] < g_prof_cycle_count_used[module_id][funcId] )\
        {\
            g_debug_stats.p_stats->max_cycle_info[funcId] = g_prof_cycle_count_used[module_id][funcId];\
        }\
    } \
    if((g_stats_cycle_num[module_id][funcId] + 1) == 100)\
    {\
        unsigned long long average = 0;\
        average = ((g_prof_cycle_count_sum[module_id][funcId])/100);\
        PRINT_EL_STATS_BASED_ON_MODULE_ID(module_id, funcId, average, thread_id);\
        g_prof_cycle_count_sum[module_id][funcId] = 0;\
        g_prof_max_count[module_id][funcId] = 0;\
        g_stats_cycle_num[module_id][funcId] = 0;\
        g_prof_packet_count[module_id][funcId] = 0;\
    }\
    else\
    {\
        g_stats_cycle_num[module_id][funcId]++;\
    }\
}
#define RDTSC_AND_CLOCK_END_SEM_DIFF(funcId, module_id, thread_id, pkt_cnt)\
{\
    do {\
        g_prof_end_sem_diff = __rdtsc();\
        if(g_prof_start_sem_diff > g_prof_end_sem_diff)\
        {\
            g_prof_cycle_count_used[module_id][funcId] = RDTSC_MAX - g_prof_start_sem_diff + g_prof_end_sem_diff;\
        }\
        else\
        {\
            g_prof_cycle_count_used[module_id][funcId] = g_prof_end_sem_diff - g_prof_start_sem_diff;\
        }\
    }while (0);\
    if(g_prof_max_count[module_id][funcId] < g_prof_cycle_count_used[module_id][funcId])\
    {\
        g_prof_max_count[module_id][funcId] = g_prof_cycle_count_used[module_id][funcId];\
    }\
    g_prof_cycle_count_sum[module_id][funcId] += g_prof_cycle_count_used[module_id][funcId];\
    g_prof_packet_count[module_id][funcId] += pkt_cnt;\
    if( MAC == module_id ) { \
        g_debug_stats.p_stats->el_sfn_slot_stats[g_thd_cell_idx][thread_id][pkt_cnt].cycle_info[funcId] = g_prof_cycle_count_used[module_id][funcId]; \
        if( g_debug_stats.p_stats->max_cycle_info[funcId] < g_prof_cycle_count_used[module_id][funcId] )\
        {\
            g_debug_stats.p_stats->max_cycle_info[funcId] = g_prof_cycle_count_used[module_id][funcId];\
        }\
    } \
    if((g_stats_cycle_num[module_id][funcId] + 1) == 100)\
    {\
        unsigned long long average = 0;\
        average = ((g_prof_cycle_count_sum[module_id][funcId])/100);\
        PRINT_EL_STATS_BASED_ON_MODULE_ID(module_id, funcId, average, thread_id);\
        g_prof_cycle_count_sum[module_id][funcId] = 0;\
        g_prof_max_count[module_id][funcId] = 0;\
        g_stats_cycle_num[module_id][funcId] = 0;\
        g_prof_packet_count[module_id][funcId] = 0;\
    }\
    else\
    {\
        g_stats_cycle_num[module_id][funcId]++;\
    }\
}
#else
#define RDTSC_AND_CLOCK_END(funcId, module_id, thread_id, pkt_cnt)
#define RDTSC_AND_CLOCK_END_SLOT_DIFF(funcId, module_id, thread_id, pkt_cnt)
#define RDTSC_AND_CLOCK_END_SEM_DIFF(funcId, module_id, thread_id, pkt_cnt)
#endif





#endif
