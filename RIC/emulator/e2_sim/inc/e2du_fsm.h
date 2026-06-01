/******************************************************************************
**  FILE NAME     :  e2cu_fsm.h
**
**  DESCRIPTION   :  This file contains the function prototypes for E2CU Module
**
**     Copyright (C) 2018 Aricent Inc . All Rights Reservfsm
******************************************************************************/
#ifndef _E2CU_FSM_H_
#define _E2CU_FSM_H_

/****************************************************************************
 * Header File Includes
 ****************************************************************************/
#include "ric_md.h"
#include "e2du_global_ctx.h"

/****************************************************************************
 * Extern definitions
 ****************************************************************************/
extern const SInt8 * E2CU_FSM_STATES_NAMES[];
extern const SInt8 * E2CU_FSM_EVENTS_NAMES[];

/****************************************************************************
 * Macro definitions
 ****************************************************************************/

#define E2CU_FSM_INIT(p_ctx) \
    do{\
        (p_ctx)->current_state = E2DU_INIT; \
    } \
    while (0)

#define E2CU_GET_FSM_STATE(gb_ctx) ((gb_ctx)->current_state)

#define E2CU_SET_FSM_STATE(gb_ctx,new_state) do{\
    (gb_ctx)->current_state=(new_state);\
    }while(0)

/****************************************************************************
 * Enumeration Definitions
 ****************************************************************************/
typedef enum
{
    E2DU_INIT,                      /* Initial state */
    E2DU_STATE_W_FOR_COMM_PROV_REQ, /* Waiting for comm/provision request */
    E2DU_STATE_ACTIVE,              /* Active state */
    E2DU_STATE_RESET,              /* Resst state */
    E2DU_NUM_OF_STATES              /* Number of states */
}e2cu_state_et;

/****************************************************************************
 * Types Definitions
 ****************************************************************************/
//typedef void (*e2cu_fsm_ret)(e2cu_gb_context_t *, void *);

/****************************************************************************
 * Function Prototypes
 ****************************************************************************/
/*void e2cu_fsm_process_event
(
    e2cu_gb_context_t *,
    e2cu_event_et,
    UInt16,
    void *
);*/

#endif /* _E2CU_FSM_H_ */

