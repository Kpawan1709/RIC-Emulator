
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include "e2_utils.h"
#include <sys/time.h>
#include "e2ap_asn_enc_dec_3gpp.h"
#include "e2sm_rc_asn_enc_dec_3gpp.h"
#include "e2sm_kpm_asn_enc_dec_3gpp.h"
#include "e2sm_asn_enc_dec_3gpp.h"

#include "rtsrc/rtPrint.h"
#include "rtsrc/rtCopy.h"
#include "rtsrc/rtPrintToString.h"
#include "rtsrc/rtPrintToStream.h"
#include "rtxsrc/rtxCharStr.h"
#include "rtxsrc/rtxCommon.h"
#include <netinet/in.h>
#include <netinet/sctp.h>
#include <stdint.h>  

e2_return_et encode_ric_control_request
(
 UInt8                                          **pp_asn_msg,
 UInt16                                         *p_asn_msg_len,
 GUAMI                                          myguami,
E2SM_RC_CallProcessID                           *ric_call,
E2SM_RC_IndicationHeader                        *header
 );

E2SM_RC_CallProcessID* decode_ric_callProcess_id(OSCTXT *asn1_ctx,E2SM_RC_CallProcessID *ric_call,e2ap_RICindication *pdu);
void decode_Ind_header(OSCTXT *asn1_ctx,E2SM_RC_IndicationHeader **header,e2ap_RICindication *pdu);

