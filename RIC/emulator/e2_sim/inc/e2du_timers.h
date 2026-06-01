/******************************************************************************
*
*   FILE NAME: e2cu_timers.h
*
*   DESCRIPTION: This file contains E2CU timers definitions.
*
*   Copyright (c) 2018, Aricent Inc. All Rights Reserved
*
******************************************************************************/
#ifndef _E2CU_TIMERS_H_
#define _E2CU_TIMERS_H_

/* e2cu_sctp_changes */
#define  E2CU_TIMER_CONN_RECOVERY_DEFAULT_DURATION      7000 /* in ms */
#define  SCTP_W_CONNECT_DEFAULT_TIMER_DURATION          1000 /* in ms */ /* amit_sctp_timer_changes */
#define  E2_SETUP_RESPONSE_TIMER_DURATION               2500

/* e2cu_cleanup */

typedef enum
{
    E2CU_OAM_INIT_TIMER,
    E2CU_SCTP_CONN_TIMER,
    E2CU_RIC_SCTP_CONN_REC_TIMER,
    E2CU_RIC_SCTP_CONNECT_TIMER,
#ifdef E2DU_KPM_CHANGES
    E2DU_OAM_KPM_TIMER,
#endif
    E2_SETUP_RESPONSE_TIMER
} e2cu_timer_type_et;

#pragma pack(push, 1)

typedef struct
{
    e2cu_timer_type_et  timer_type;
    UInt8               auto_delete;
    UInt32              transaction_id;    
    void                *p_timer_specific_data;
    UInt8               ric_id; // /* e2cu_sctp_changes */
} e2cu_timer_buf_t;

#pragma pack(pop)

#endif /* _E2CU_TIMERS_H_ */

