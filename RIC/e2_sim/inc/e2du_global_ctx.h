/****************************************************************************
 *
 *  ARICENT -
 *
 *  Copyright (C) 2009 Aricent Inc. All Rights Reserved.
 *
 ****************************************************************************
 *
 *  $Id: e2cu_global_ctx.h,v 1.7 2010/10/13 07:04:06 gur57180 Exp $
 *
 ****************************************************************************
 *
 *  File Description : This file contains all the necessary declarations for
 *                     e2cu module global context.
 *
****************************************************************************/

#ifndef _E2CU_GLB_CTX_H_
#define _E2CU_GLB_CTX_H_

/****************************************************************************
 * Project Includes
 ****************************************************************************/
#include "e2du_defines.h"
#include "search_tree_wrap.h"
#include "e2_utils.h"
#include "shell.h"

/****************************************************************************
 * Exported Definitions
 ****************************************************************************/

typedef SInt32 sctp_sd_t;
typedef struct _sctp_sd_search_node_t
{
    /* CSPL nodeAnchor */
    search_tree_node_t nodeAnchor;
    /* The value of sctp socket descriptor */
    sctp_sd_t sctp_sd;
    /*This ricId of the RIC whose corresponding sctp socket desc is sctp_sd */
    UInt8 ricId;

}sctp_sd_search_node_t;


#define E2CU_LAST_SELECTED_MMEGI_PRESENT 0x01
#define E2CU_SCTP_CONFIG_PARAMS_PRESENT  0x02
#define E2CU_SCTP_DEFAULT_MAX_INIT_RTX 8   /* e2cu_sctp_changes */
#define E2CU_SCTP_DEFAULT_ASSOC_MAX_RTX 10
#define E2CU_SCTP_DEFAULT_VAL_COOKIE_LIFE 60000
#define E2CU_SCTP_DEFAULT_RTO_INITIAL 3000
#define E2CU_SCTP_DEFAULT_RTO_MAX 6000
#define E2CU_SCTP_DEFAULT_RTO_MIN 1000
#define E2CU_SCTP_DEFAULT_INIT_TIMEOUT 0
#define E2CU_OAM_DSCP_VALUE_PRESENT     0x01
#define E2CU_LAST_SELECTED_MMEGI_PRESENT 0x01
#define E2CU_SCTP_CONFIG_PARAMS_PRESENT  0x02

/* IPV6 Start */
#define E2CU_COMM_INFO_IPV6_NUM_ADDR_PRESENT    0x01
#define E2CU_COMM_INFO_IPV6_ADDR_PRESENT        0x02
#define E2CU_COMM_INFO_IPV4_NUM_ADDR_PRESENT    0x04
#define E2CU_COMM_INFO_IPV4_ADDR_PRESENT        0x08

#endif  /* _E2CU_GLB_CTX_H_ */


