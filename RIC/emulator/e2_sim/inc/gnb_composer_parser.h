/*******************************************************************************
*
*   FILE NAME:
*      gnb_composer_parser.h
*
*   DESCRIPTION:
*       This file contains common typedef for composer parser files.
*
*   DATE            AUTHOR      REFERENCE       REASON
*   05 Sep 2018     Kranti   ---------       Initial
*
*   Copyright (c) 2018, Aricent Inc. All Rights Reserved
*
*******************************************************************************/

#ifndef _GNB_COMPOSER_PARSER_H_
#define _GNB_COMPOSER_PARSER_H_

#include "gnb_types.h"
/*******************************************************************************
 * OTHER GLOBAL TYPEDEFS
 ******************************************************************************/
typedef UInt64   time_in_ms_t;
typedef UInt16   ue_index_t;
typedef UInt16   cell_index_t;
typedef UInt16   nr_pci_t;
typedef UInt32   nr_arfcn_t;
typedef UInt16   counter_t;
typedef UInt16   bitmask_t; /* Bitmask for message structure */
typedef UInt8    srb_id_t; /* SRB=0,1,2,3 */
typedef UInt8    drb_id_t; /* DRB 4-32 */
typedef UInt8    bool_t;
typedef UInt32      bitmask_u32_t;
typedef UInt16      gnb_module_id_t;

#endif   /*_GNB_COMPOSER_PARSER_H_ */
