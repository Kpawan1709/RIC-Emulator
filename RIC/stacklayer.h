/****************************************************************************/
/**  Copyright (C) 2006 Aricent Inc . All Rights Reserved */
/****************************************************************************/
/**                                                                        **/
/** Common Stack Porting Library - Conventions Library                     **/
/**                                                                        **/
/****************************************************************************/

#ifndef    _STACKLAYER_H_
#define    _STACKLAYER_H_

#include "cspl.h"

/** Constants ***************************************************************/
#define CV_OF_VERSION  0
#define CV_OF_FROM     1
#define CV_OF_TO       3
#define CV_OF_API      5
#define CV_OF_BUFLEN   7
#define CV_OF_SOPL     9
#define CV_OF_LENPL    11
#define CV_OF_PRIORITY 13
#define CV_OF_PAD      14
#define CV_HDRSIZE     16

/** Types *******************************************************************/
typedef struct    {
    UInt8    version;
    UInt16    from;
    UInt16    to;
    UInt16    api;
    SInt8    priority;
    unsigned int    paramlen;
    unsigned int    payloadlen;
} STACKAPIHDR;

typedef    struct    {
    unsigned int    
        bufsize, min, max, step;
    QMPOOL    pool;
} STACKCPOOL;

typedef    struct    {
    unsigned int    
        bufsize, min, max, step;
    QMPOOL    pool;
} STACKMPOOL;

/** Functions ***************************************************************/
unsigned int    
    cvApiParseHeader( UInt8 *buffer, unsigned int length, STACKAPIHDR *api );
unsigned int    
    cvApiParseHeaderEx( UInt8 *buffer, unsigned int length, STACKAPIHDR *api, int *cErr);
unsigned int    
    cvApiBuildHeader( UInt8 *buffer, STACKAPIHDR *api );
UInt8    *cvApiBegin( UInt8 *buffer, UInt8 version, UInt16 from, UInt16 to, UInt16 api, signed char priority );
UInt8    *cvApiEnd( UInt8 *buffer, UInt8 *end );
#define    cvApiData(p) ((UInt8 *)((UInt8 *)(p) + CV_HDRSIZE ))
void    cvApiAdjustIn( void *message );
unsigned int    
    cvApiAdjustOut( void *message );

int    cvContextPoolSetup( 
        STACKCPOOL *cpool, unsigned int bufsize, unsigned int min, 
        unsigned int max, unsigned int step);
#define cvContextPoolDelete(p) (qvMpoolDelete((p)->pool))
void    *cvContextAlloc( STACKCPOOL *cpool );
#define cvContextIndex(p,c)  (qvMpoolIndex((p)->pool, (c)))
#define cvContextLocate(p,n) (qvMpoolLocate((p)->pool, (n)))
#define cvContextFree        qvMpoolFree

int    cvMessagePoolSetup( 
        STACKMPOOL *mpool, unsigned int bufsize, unsigned int min, 
        unsigned int max, unsigned int step);
void    *cvMessageAlloc( STACKMPOOL *mpool );

void     qvLadderDump(unsigned short api_id,
        unsigned short src_id,
        unsigned short dst_id);
void    *cvGetBufferFrom( 
        QMODULE module, UInt16 api, unsigned int paramlen, unsigned int payloadlen );

void  *nameContextAlloc( STACKCPOOL *cpool );

extern int nameContextPoolSetup(
        STACKCPOOL *cpool, unsigned int bufsize, unsigned int min,
        unsigned int max, unsigned int step);
#endif

