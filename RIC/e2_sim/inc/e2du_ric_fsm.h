/******************************************************************************
 *
 *  ARICENT -
 *
 *  Copyright (C) 2009 Aricent Inc. All Rights Reserved.
 *
 ******************************************************************************
 *
 *  $Id: e2cu_ric_fsm.h
 *
 ******************************************************************************
 *
 *  File Description : This file comtains the function prototypes for E2CU 
                       RIC Module FSM
 ******************************************************************************/


/******************************************************************************
 * Standard Library Includes
 *****************************************************************************/

/******************************************************************************
 * Project Includes
 *****************************************************************************/

#ifndef INCLUDED_RIC_FSM_H
#define INCLUDED_RIC_FSM_H

/****************************************************************************
 * Header File Includes
 ****************************************************************************/
#include "e2du_global_ctx.h"
#include "sctp_wrappers.h"
#include "e2du_timers.h"

/******************************************************************************
  Private Definitions
 *****************************************************************************/

#define RIC_GET_FSM_STATE(gb_ric_ctx) gb_ric_ctx->current_ric_state

#define RIC_SET_FSM_STATE(gb_ric_ctx,new_state) \
    gb_ric_ctx->current_ric_state=new_state

#define RIC_FSM_EVENT_TRACE(state, event) \
    GNB_TRACE(GNB_INFO, "[STATE:%s] [EVENT:%s]", \
            RIC_FSM_STATES_NAMES[(state)], \
            RIC_FSM_EVENTS_NAMES[(event)])

/******************************************************************************
  Private Types
 *****************************************************************************/

typedef enum
{
    RIC_IDLE,                           /* This is the initial state of RIC FSM */
    RIC_W_E2_SETUP_RESP,                /* Waiting for E2 Setup RSP request */
    RIC_ACTIVE,                         /* S1AP association between E2-CU and RIC is active */
    RIC_W_SCTP_CONN_RECOVERY,           /* After detecting connection failure a timer is started to wait for SCTP connection recovery.*/
    RIC_W_CONNECT_SUCCESSFUL,           /* Wait for connection RIC after connection failure */
    RIC_W_SCTP_CONNECT,                 /* Wait for sctp connection after receiving error code EINPROGRESS*/
    RIC_NUM_OF_STATES,                  /* Number of states */
    RIC_INVALID_STATE                   /* Invalid State */
}ric_state_et;

typedef enum
{
    RIC_EVENT_E2_SETUP_RESP_TIMER_EXPIRY,       /* This event is triggered on expiry of timer started when E2 SETUP REQUEST is sent*/
    RIC_EVENT_SCTP_CONN_FAILURE_IND,            /* failure of SCTP association */
    RIC_EVENT_SCTP_CONN_RECOVERY_IND,           /* Recovery of SCTP assoc after failure.*/
    RIC_EVENT_SCTP_CONN_REC_TIMER_EXPIRY,       /* Expiry of guard timer that was started after detection of SCTP assoc failure*/
    RIC_EVENT_SCTP_CONNECT_TIMER_EXPIRY,        /* Expiry of timer started upon failure of sctp connect has expired. */
//    RIC_EVENT_SCTP_SHUTDOWN,
    RIC_EVENT_SCTP_ASSOC_UP,                    /* SCTP association is UP */
    RIC_EVENT_SCTP_ASSOC_DOWN,                  /* SCTP association is DOWN */
    RIC_NUM_OF_EVENTS,                          /* Number of Events */
    RIC_INVALID_EVENT                           /* Invalid Event */
}ric_event_et;

typedef void (*ric_fsm_ret)(
        void   *,
        void   * ,
        e2cu_gb_context_t* ,
        ric_context_t*);

typedef enum {
    RIC_FAILURE,
    RIC_SUCCESS
} ric_return_et;

/* Values for ric_bool_et, e2_bool_t */
#define ric_bool_et  e2_bool_et
#define RIC_FALSE    E2_FALSE
#define RIC_TRUE     E2_TRUE

void  e2cu_establish_ric_connection(
        e2cu_gb_context_t     * p_e2cu_gb_ctx,
        ric_context_t         * p_ric_ctx);
/****************************************************************************
 * Function Prototypes
 ****************************************************************************/

void  ric_fsm_e2_setup_rsp_timer_expiry (
        void                * timer_id,
        void                * p_timer_buf,
        e2cu_gb_context_t   * p_e2cu_gb_ctx,
        ric_context_t       * pric_ctx);

void ric_fsm_process_event(
        ric_event_et         event_id,
        void                 * param1,
        void                 * param2,
        e2cu_gb_context_t    * p_e2cu_gb_ctx,
        ric_context_t        * p_ric_ctx);

typedef void (*ric_fsm_ret)(
        void   *,
        void   * ,
        e2cu_gb_context_t* ,
        ric_context_t*);


void ric_fsm_invalid_event_handler(
        void   *,
        void   * ,
        e2cu_gb_context_t* ,
        ric_context_t*);

void  ric_fsm_sctp_conn_failure_ind(
        void   *,
        void   * ,
        e2cu_gb_context_t* ,
        ric_context_t*);

void  ric_fsm_sctp_conn_rec_ind(
        void   *,
        void   * ,
        e2cu_gb_context_t* ,
        ric_context_t*);

void  ric_fsm_sctp_conn_rec_timer_expiry(
        void   *,
        void   * ,
        e2cu_gb_context_t* ,
        ric_context_t*);

void  ric_fsm_sctp_connect_timer_expiry(
        void   *,
        void   * ,
        e2cu_gb_context_t* ,
        ric_context_t*);

void  ric_fsm_w_sctp_connect_event_handler(
        void   *,
        void   * ,
        e2cu_gb_context_t* ,
        ric_context_t*);

void  ric_fsm_sctp_re_conn_try_failure_ind(
        void                * p_api,
        void                * p_msg,
        e2cu_gb_context_t   * p_e2cu_gb_ctx,
        ric_context_t       * p_ric_ctx);

void  ric_fsm_sctp_assoc_up_event_handler(
        void   *,
        void   * ,
        e2cu_gb_context_t* ,
        ric_context_t*);

void  ric_fsm_sctp_assoc_down_event_handler(
        void   *,
        void   * ,
        e2cu_gb_context_t* ,
        ric_context_t*);

void delete_sctp_sd_from_tree(
        e2cu_gb_context_t *p_e2cu_gb_ctx,
        ric_context_t *p_ric_ctx);

#endif /* INCLUDED_RIC_FSM_H */
/* e2cu_ric_fsm.h */

