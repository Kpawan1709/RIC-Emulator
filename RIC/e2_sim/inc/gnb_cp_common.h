/***************************************************************************
 *
 *  ARICENT -
 *
 *  Copyright (c) 2018 Aricent.
 *
 ****************************************************************************
 * File Details
 * ------------
 *  File Name $
 ****************************************************************************
 *
 *  File Description : The file gnb_cp_common.h contains the prototypes 
 *                     for composing/parsing basic data types.
 *
 ****************************************************************************/
#ifndef _GNB_CP_COMMON_H_
#define _GNB_CP_COMMON_H_

#include "gnb_porting.h"

#define GNB_CP_TRACE(log_level,str,...) \
    gnb_cp_trace((SInt8*)__FILE__,(SInt8*)__func__,__LINE__,log_level,\
            (SInt8*)str,##__VA_ARGS__)

extern void gnb_cp_trace(SInt8* fileName,SInt8* funcName,UInt32 lineNo,
        UInt8 logLevel,SInt8* str,...);

gnb_return_t
gnb_cp_pack_UInt8
(
    void    *p_dest,
    void    *p_src,
    char    *varname
);

gnb_return_t
gnb_cp_pack_UInt16
(
    void    *p_dest,
    void    *p_src,
    char    *varname
);

gnb_return_t
gnb_cp_pack_to_little_endian_UInt16
(
    void    *p_dest,
    void    *p_src,
    char    *varname
);

gnb_return_t
gnb_cp_pack_to_little_endian_UInt32
(
    void    *p_dest,
    void    *p_src,
    char    *varname
);

gnb_return_t
gnb_cp_pack_UInt64
(
    void    *p_dest,
    void    *p_src,
    char    *varname
);

gnb_return_t
gnb_cp_pack_UInt32
(
    void    *p_dest,
    void    *p_src,
    char    *varname
);

gnb_return_t
gnb_cp_pack_SInt8
(
    void    *p_dest,
    void    *p_src,
    char    *varname
);

gnb_return_t
gnb_cp_pack_SInt16
(
    void    *p_dest,
    void    *p_src,
    char    *varname
);

gnb_return_t
gnb_cp_pack_SInt32
(
    void    *p_dest,
    void    *p_src,
    char    *varname
);


gnb_return_t
gnb_cp_pack_UDouble32
(
    void    *p_dest,
    void    *p_src,
    char    *varname
);

gnb_return_t
gnb_cp_unpack_UDouble32
(
 void *p_dest,
 void *p_src,
 char *varname
 );


gnb_return_t
gnb_cp_unpack_UInt8
(
    void    *p_dest,
    void    *p_src,
    char    *varname
);

gnb_return_t
gnb_cp_unpack_UInt16
(
    void    *p_dest,
    void    *p_src,
    char    *varname
);

gnb_return_t
gnb_cp_unpack_UInt64
(
    void    *p_dest,
    void    *p_src,
    char    *varname
);

gnb_return_t
gnb_cp_unpack_UInt32
(
    void    *p_dest,
    void    *p_src,
    char    *varname
);

gnb_return_t
gnb_cp_unpack_SInt8
(
    void    *p_dest,
    void    *p_src,
    char    *varname
);

gnb_return_t
gnb_cp_unpack_SInt16
(
    void    *p_dest,
    void    *p_src,
    char    *varname
);

gnb_return_t
gnb_cp_unpack_SInt32
(
    void    *p_dest,
    void    *p_src,
    char    *varname
);

void print_hex_dump(UInt8 *msg_buf, SInt32 msg_len);

#define PRINT_HEX_DUMP(a,b) print_hex_dump(a,b)

#endif /* _GNB_CP_COMMON_H_ */

