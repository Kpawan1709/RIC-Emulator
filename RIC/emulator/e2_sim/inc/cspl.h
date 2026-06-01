/****************************************************************************/
/**  Copyright (C) 2018 Aricent Inc . All Rights Reserved */
/****************************************************************************/
/**                                                                        **/
/** Common Stack Porting Library - Interface Definition                    **/
/**                                                                        **/
/****************************************************************************/

#ifndef	_CSPL_H_
#define	_CSPL_H_

#include	"ylib.h"

/* Defining Version of CSPL Release */
#define qvRelVer	htonl( (1<<24) | (5<<16) | (0<<8) )

/* minimum buffer of 8 bytes */
#define MINBUF_BITS        (3)
#define MINBUF             (1<<(MINBUF_BITS))
#define MINBUF_MASK        (MINBUF - 1)
#define MINBUF_INDEX(val)  ((sizeof(unsigned int) * 8) - __builtin_clz(((val + MINBUF_MASK) & (~MINBUF_MASK)) - 1) - MINBUF_BITS)
#define NVARPOOL           27
#define NVARMSGPOOL    27
#define NVARMEMPOOL    27

#define PAGESIZE           4096
#define POOL_SIZE_TO_FENCE 2048
#define MAX_POOLS	   64
#define MAX_VAL_U32	   4294967295U

/** Types *******************************************************************/
#if defined(__x86_64__) || defined(__aarch64__)
#define U32_64_Bit U32Long
#else
#define U32_64_Bit U32
#endif

typedef	struct	{
	unsigned long	s;
	unsigned long	us;
}	QTIME;

typedef	struct	{
	unsigned char	*base;
	unsigned int	size;
}	QSEGMENT;

typedef	void		*QMODULE;
typedef	void		*QTIMER;
typedef	void		*QLOCK;
typedef	void		*QDRIVER;
typedef void		**QVMPOOLSET;
typedef void        *QMPOOL;
typedef void        *QMPOOLSET;

/* Structure defined for the Named Pools */
typedef struct  named_pool_alloc_t
{
    void    *pool;
    UInt32  size;
} named_pool_alloc, *LP_named_pool_alloc;


typedef	struct	{
	unsigned long	ntimers;
	unsigned long	nmodules;
	unsigned long	npctls;
	unsigned long	nqmsg;
}	QTUNING;

typedef struct {
	unsigned int	bufsize;
	unsigned int	nbufs;
}	QPOOLTUNING;
	
typedef struct {
	unsigned int	opt;
	unsigned long	npools;
	QPOOLTUNING	qpt[MAX_POOLS];
}	QPOOLSETTUNING;	


typedef	struct	{
	void	*(*malloc)(gnb_size_t);
	void	(*free)(void *);
	void	*(*newkey)(void);
	void	*(*getkey)(void *);
	void	(*setkey)(void *, void *);
	void	*(*newlock)(void);
	void	(*destroylock)(void *);
	void	(*lock)(void *);
	void	(*unlock)(void *);
	int	(*vprintf)(const char *, va_list);
	int	(*iprintf)(const char *, va_list);
	void	(*abort)(void);
}	QSYSOP;

#ifdef POOL_DEFINED_LOCK_IMPL
typedef	struct	{
	void	*(*newlock)(void);
	void	(*destroylock)(void *);
	void	(*lock)(void *);
	void	(*unlock)(void *);
}	QPOOLSYSOP;
#endif

struct QSHELL;
typedef	struct	QSHELL QSHELL;
struct	QSHELL {
	void	(*timedwait)( void *, const QTIME * );
	void	(*send)( void *, const void *, QMODULE, QMODULE, void *, unsigned int );
	void	*(*receive)( void *, QMODULE *, QMODULE *, signed char * );
	void	*(*open)(void *);
	void	(*close)(void *);
	void	*(*hash)(void *, void *);
};

struct QWAIT;
typedef	struct	QWAIT QWAIT;
struct	QWAIT {
	void	*(*newchannel)(void);
	void	(*sleep)(void *, const QTIME *);
	void	(*wakeup)(void *);
	void	(*walltime)( QTIME * );
};

typedef struct	QMANIFEST {
	const char	*name;
	unsigned long
		service;

	struct	{
		void	*(*early)(void *);
		void	*(*late)(void *); 
	} init;

	struct {
		SInt32	(*message)(void *, void *); 
		void	(*timer)(QTIMER, void *, void *); 
	} handler;

	struct	{
		void	*(*pack)( QMODULE, void *, UInt32 * );
		void	*(*unpack)( QMODULE, void * );
		void	*(*alloc)( QMODULE, UInt32 );
	} method;

	const unsigned long *destinations;
} QMANIFEST;


typedef struct	QADAPTER {
	void	*(*init)(QMODULE, void *);
	void	*(*pack)( QMODULE, void *, UInt32 * );
	void	*(*unpack)( QMODULE, void * );
	void	*(*alloc)( QMODULE, UInt32 );
	void	*(*in)(void *, QMODULE *, QMODULE *); 
	void	*(*out)(void *, QMODULE *, QMODULE *);

	const unsigned long *destinations;
} QADAPTER;

#ifdef CSPL_TWO_LOCK_IMPL
#ifdef CSPL_LOCKLESS_IMPL

typedef struct queue_head {
    YPNODE  *top; /**< Stack top */
    UInt64 cnt; /**< Modification counter for avoiding ABA problem */
}queue_head;

typedef struct yqueue_t {
    /** List head */
    struct queue_head head __attribute__((aligned(16)));
    /** List len */
    UInt64 len;
} YQUEUE;
#else
typedef struct queue_t
{
    YPNODE *tail;
    YPNODE *head;
    QLOCK head_lock;
    QLOCK tail_lock;
    YPNODE divider;
}YQUEUE;
#endif
#endif
typedef    struct    qpool {
    unsigned long    magic;
    unsigned int     size, nbuf, alloc, peakVal;
    YLIST            chunks;
#ifdef CSPL_TWO_LOCK_IMPL
    YQUEUE           *queue;
#else
    YPOOL            list;
#endif
    QLOCK            lock;
#ifdef POOL_DEFINED_LOCK_IMPL
    QPOOLSYSOP           op;
#endif
} qpool;

typedef    struct    qbuf {
    union {
        YPNODE    __header__;
        qpool    *pool;
    } u;
    unsigned short incarnation;
    unsigned char  allocated;
    char  *func;
    unsigned int   line;
#ifdef MEM_FENCING
    void *protectaddr;
#endif
#ifdef CSPL_LEAK_DEBUG
    int nptrs;
/* Max. No. of frames in Backtrace */
#define MAX_FRAMES_IN_BT 10
    void *buffer[MAX_FRAMES_IN_BT];
#endif
} qbuf;

#define		LOGGER_MODULE_ID	999
#define		LOGGER_API_SIZE		6

/** Library Initialization **************************************************/

void	qvInit( const QTUNING *t, const QSYSOP *op, unsigned char extendPool );
void	qvInitEx( const QTUNING *t, const QSYSOP *op, unsigned char extendPool,int *cErr);
QDRIVER	qvNewDriver( void );
QDRIVER	qvNewDriverEx(int *cErr);
QDRIVER	qvDriverStart(QDRIVER driver, void (*wakeupfn)(void *), void *arg);
#define	qvDriver(w,a)	(qvDriverStart(qvNewDriver(),(w),(a)))
#define	qvSimpleInit(t,op)	(qvInit((t),(op),1), qvDriver(0,0))
void qvPoolStats(void);
int extendPool(void *qpool, unsigned int nbuf);
void qvAllFreeFromMemPool(void *qv);

/* Task common memory pools *************************************************/

/** Constants **/
#define	__BUFMAGIC	0xACE12E92
#define	__POOLMAGIC	0xCA98362D



typedef struct {
    unsigned int    bufsize;
    unsigned int    nbufs;
    unsigned int    nalloc;
}   QPOOLTUNINGINFO;

typedef struct {
    unsigned long   npools;
    QPOOLTUNINGINFO qpt[MAX_POOLS];
}   QPOOLSETTUNINGINFO;


typedef	struct	qmessage {
	YSNODE	__header__;

	QMODULE	owner, sender, receiver;
	int	priority;
	unsigned int size;
	YLIST	buffers;
} qmessage;

typedef	struct	qpseg {
	unsigned int	refcount;
	unsigned char	*data;
	unsigned int	size;
	void		(*free)(void *, void *);
	void		*freearg;
} qpseg;

typedef    struct    qchunk {
    YLNODE    __header__;
    unsigned int    nbuf;
    unsigned int    line;
    char*           func;
} qchunk;

typedef	struct	qpctl {
	YLNODE	__header__;

	qpseg		*segment;
	unsigned char	*start;
	unsigned char	*end;
} qpctl;

/* This structure provides the POOL stats */
typedef struct poolStatsT 
{
    /* size of the buffer allocated in this pool */
    UInt32  bufSize; 
    /* Total number of Buffers in this pool */
    UInt32  numOfBuf; 
    /* Total number of Buffers allocated from this pool */
    UInt32  numOfAllocBuf; 
    /* Peak of Total number of Buffers allocated from this 
     * pool during the system is running */
    UInt32  numOfPeakBuf; /*^ M, 0 ^*/

}poolStats;


/* This structure provides the MEM POOL stats */
typedef struct csplMemPoolStatsT 
{
    poolStats  stats[NVARPOOL]; 
} csplMemPoolStats;

/* This structure provides the named MEM POOL stats */
typedef struct named_pool_stats_t
{
    poolStats  stats[NVARPOOL]; 
} named_pool_stats, *LP_named_pool_stats;

/* This structure provides the MSG POOL stats */
typedef struct csplMsgPoolStatsT 
{
    /* This array is terminated when bufSize is 0 for an 
     * entry, other entries are not valid */
    poolStats  stats[NVARPOOL]; 
    poolStats  qpctlStats; 
    /* The QMSG stats */
    poolStats  qmsgStats; 
} csplMsgPoolStats;

/* task common memory pools structures */
extern unsigned int qvGetQMessageSize(void);
extern void    qvMsgPoolDelete( QMPOOL Q );
extern unsigned int qvMsgPoolBufferSize(QMPOOL Q);
extern void __qvMsgPoolDecrease(QMPOOL Q, unsigned int nbufs);


#define qvPoolSetFree(buffer)      (qvPoolFree(buffer))
#define qvMsgPoolSetFree(buffer)   (qvMsgFree(buffer))

QMPOOLSET qvPoolSetCreate(QPOOLSETTUNING *t, int *cErr);
void    *qvPoolSetAlloc(QMPOOLSET rpd, unsigned int size,unsigned int *psize, int *cErr);
unsigned int qvPoolSetExtend(QMPOOLSET rpd, QPOOLSETTUNING *t, int *cErr);
unsigned int    qvPoolSetDelete( QMPOOLSET rpd, int *cErr);
unsigned int qvPoolSetSize(QMPOOLSET rpd, QPOOLSETTUNINGINFO *t, int *cErr);


/** Malloc Emulation ********************************************************/
void	*qvAlloc(unsigned int size, unsigned int *psize);
#if defined(CSPL_LEAK_DEBUG_LITE) 
void displayMemPoolStatsCspl(void);
void qvPrintMemPoolAllocBuffers();
#endif
void qvPoolCreate( unsigned int size, unsigned int nbuf,const char *func, const unsigned int line );
void	*qvAllocEx(unsigned int size, unsigned int *psize, int *cErr, const char *func, const unsigned int line);
void	qvFree( void *p, const char *func, const unsigned int line );
unsigned int qvPoolIndexEx( void* Q, void *buffer, int *cErr);
void    *qvPoolLocateEx( void* Q, unsigned int indexparam, int *cErr);
unsigned int qvPoolSize(void* Q, unsigned int *p_alloc);
extern void    deletePool( void  *Q );
extern void qvPoolFree ( void *buf,const char* func, unsigned int line );
/** Access to System Memory Allocation **************************************/
void	*qvSysMalloc(unsigned int size);
void	qvSysFree( void *p );

/** Message Buffer Management ***********************************************/
QMPOOL	qvMsgPoolCreate( unsigned int attrsize, unsigned int nbuf );
QMPOOL	qvMsgPoolCreateEx( unsigned int attrsize, unsigned int nbuf, int *cErr);
unsigned int
	qvMsgPoolSize( QMPOOL Q, unsigned int *p_alloc );
int	qvMsgPoolExtend( QMPOOL Q, unsigned int nbuf );
int	qvMsgPoolExtendEx( QMPOOL Q, unsigned int nbuf, int *cErr);
QMPOOL	qvMsgPoolOf(const void *buffer);
void	*qvMsgAlloc(QMPOOL pool, unsigned int headroom, 
		unsigned int tailroom, unsigned int attrsize);
void	*qvMsgAllocEx(QMPOOL pool, unsigned int headroom, 
		unsigned int tailroom, unsigned int attrsize, int *cErr);
#define	qvMsgAllocFromPool(pool)		qvMsgAlloc((pool),0,0,0)
#define	qvMsgAllocFromPoolEx(pool, cErr)	qvMsgAllocEx((pool),0,0,0, cErr)
#define	qvMsgAllocBySize(size)			qvMsgAlloc(0,0,0,(size))
#define	qvMsgAllocBySizeEx(size, cErr)		qvMsgAllocEx(0,0,0,(size), cErr)


void	qvMsgFree(void *buffer);
void	qvMsgFreeEx(void *buffer,int *cErr);
unsigned int	
	qvMsgSize(const void *buffer, UInt32 *attrsize);
unsigned char	
	*qvMsgReserve(void *buffer, int where, unsigned int count);
unsigned char	
	*qvMsgReserveEx(void *buffer, int where, unsigned int count, int *cErr);
unsigned char	
	*qvMsgInsert(void *buffer, int where, unsigned char *data, unsigned int count);
unsigned char	
	*qvMsgInsertEx(void *buffer, int where, unsigned char *data, unsigned int count, int *cErr);
unsigned char	
	*qvMsgInsertExternal(void *buffer, int where, unsigned char *data, 
		unsigned int count, 
		void (*freefn)(void *, void *), void *freearg);
unsigned char	
	*qvMsgInsertExternalEx(void *buffer, int where, unsigned char *data, 
		unsigned int count, 
		void (*freefn)(void *, void *), void *freearg, int *cErr);
int	qvMsgRemove(void *buffer, int where, unsigned int count);
int	qvMsgRemoveEx(void *buffer, int where, unsigned int count, int *cErr);
int	qvMsgExtract(const void *buffer, int where, unsigned char *data, unsigned int count);
int	qvMsgExtractEx(const void *buffer, int where, unsigned char *data, unsigned int count, int *cErr);
void	*qvMsgClone(const void *buffer);
void	*qvMsgCloneEx(const void *buffer, int *cErr);
void	*qvMsgCopy(void *tobuffer, const void *frombuffer, unsigned int attrsize);
void	*qvMsgCopyEx(void *tobuffer, const void *frombuffer, unsigned int attrsize, int *cErr);
void	*qvMsgSplit(void *buffer, unsigned int offset, void *tobuffer);
void	*qvMsgSplitEx(void *buffer, unsigned int offset, void *tobuffer, int *cErr);
void	*qvMsgJoin(void *buffer, void *append);
void	*qvMsgJoinEx(void *buffer, void *append, int *cErr);
void	*qvMsgPack(void *buffer, unsigned int headroom, unsigned int tailroom);
void	*qvMsgPackEx(void *buffer, unsigned int headroom, unsigned int tailroom, int *cErr);
unsigned int
	qvMsgSegCount( const void *buffer );
void	*qvMsgSegNext( const void *buffer, void *last, QSEGMENT *segment );

/* Pool Specific functions */
int	qvCsplPoolsExtend( QTUNING *t, int *cErr);
void 	qvPoolSort( QMPOOLSET Q, int n );

/** Timer Management ********************************************************/
const QTIME	
	*qvNow(QTIME *T);
int	qvTimeDiff(const QTIME *A, const QTIME *B, QTIME *result);
QTIMER	qvTimerStart(const QTIME *duration, void *data, int repeat);
QTIMER	qvTimerStartEx(const QTIME *duration, void *data, int repeat, int *cErr);
void	qvTimerStop(QTIMER T, QTIME *ptime );
void	qvTimerStopEx(QTIMER T, QTIME *ptime, int *cErr );
int	qvModuleTimerStop(QTIMER T, QTIME *ptime, int *cErr );
int	qvTimerRunning(QTIMER T);
void	*qvTimerData(QTIMER T);
int qvTimerRemaining(QTIMER T,QTIME *rem);
QTIMER	qvModuleTimerStart(QMODULE module,const QTIME *duration, 
					void *data, int repeat, int *cErr);

QTIMER	qvAbsoluteTimerStart(QMODULE module,const QTIME *expiry, void *data, int repeat, int *cErr);
#define qvAbsoluteTimerStop(T,ptime,pErr)		(qvModuleTimerStop((T),(ptime),(pErr)))

/** Scheduling **************************************************************/
int	qvPending(QDRIVER driver);
QMODULE	qvModuleAttach( 
		QDRIVER	driver,
		const char *name,
		void *(*init)(void *), 
		SInt32 (*msgfn)(void *, void *), 
		void (*tmrfn)(QTIMER, void *, void *), 
		void *initarg,
		unsigned long service,
		int timer_tuning,
		int *cErr);
QMODULE	qvModuleCreate( 
		const char *name,
		void *(*init)(void *), 
		SInt32 (*msgfn)(void *, void *), 
		void (*tmrfn)(QTIMER, void *, void *), 
		void *initarg,
		unsigned long service);
void	*qvModuleContext( QMODULE module );
QMODULE	qvSelf( void );
QDRIVER	qvThisDriver( void );
void	*qvThisContext( void );
void	*qvThisMessage( void );
QTIMER	qvThisTimer( void );
#define	qvName()	(qvGetServiceName(qvSelf()))
void	qvSetMethods( QMODULE module, const void *m );
const void	
	*qvGetMethods( QMODULE module );

const QTIME	*qvSchedule( const QTIME * );
void	qvWakeup(QDRIVER driver);

/** Messaging ***************************************************************/
QMODULE qvGetService( unsigned long name );
QMODULE qvGetServiceEx( unsigned long name, int *cErr);
unsigned long
	qvGetServiceName( QMODULE service );
void	qvSetFilter( QMODULE module, 
		void *(*in)(void *, QMODULE *, QMODULE *), 
		void *(*out)(void *, QMODULE *, QMODULE *) );
QMODULE	qvSetDispatch( unsigned long name, 
		int (*func)(void *, void *, QMODULE, QMODULE), void *data );
QMODULE	qvSetDispatchEx( unsigned long name, 
		int (*func)(void *, void *, QMODULE, QMODULE), void *data, int *cErr);
void	qvSetImmediate( unsigned long name, int* cErr);
void	qvDeliver(QMODULE from, QMODULE to, int priority, void *message );
void	qvDeliverEx(QMODULE from, QMODULE to, int priority, void *message, int *cErr);
void	qvSend(QMODULE to, int priority, void *message);
void	qvSendEx(QMODULE to, int priority, void *message, int *cErr);
QMODULE	qvFrom( const void *message );
QMODULE	qvTo( const void *message );
int	qvPriority( const void *message );

/** Locks *******************************************************************/
QLOCK	qvNewLock( void );
void	qvLock( QLOCK lock );
void	qvUnlock( QLOCK lock );
void	qvDestroyLock( QLOCK lock );

#ifdef POOL_DEFINED_LOCK_IMPL
static inline QLOCK qvPoolNewLock( void *Q )
{
    qpool *pool = (qpool *)Q;
    return (QLOCK)pool->op.newlock();
}
static inline void qvPoolLock( void *Q, QLOCK lock )
{ 
    qpool *pool = (qpool *)Q;
    pool->op.lock((void *)lock);
}
static inline void qvPoolUnlock( void *Q, QLOCK lock )
{
    qpool *pool = (qpool *)Q;
    pool->op.unlock((void *)lock);
}
static inline void qvPoolDestroyLock( void *Q, QLOCK lock )
{
    qpool *pool = (qpool *)Q;
    pool->op.destroylock((void *)lock);
}
#endif

/** Tracing *****************************************************************/
int	qvPrintf( const char *format, ...);
void	qvDump( const unsigned char *buf, unsigned int n, unsigned long style );
int	qvLog( int level, const char *format, ...);
void	qvLogDump( int level, const unsigned char *buf, unsigned int n, unsigned long style );
void	qvLogLevel( unsigned char level );
/* GDB Fix - add U8 qvGetLogLevel( void ) to fix unresolved in L3 module */
unsigned char qvGetLogLevel( void );
#ifdef MEM_FENCING_LITE
void (*p_write_cspl_string)(void *p, const char* func, const unsigned int line, const char* func_old, const unsigned int line_old, unsigned long long fencing_start);
#endif

#ifdef MODULE_LOGGING
void qvSetModuleLogLevel(QMODULE m,unsigned char level);
unsigned char qvGetModuleLogLevel(QMODULE m);
#endif
void	qvLogTime( const QTIME *T );

int	qvPrintfVa( const char *format, va_list A);
int	qvLogVa( int level, const char *format, va_list A);

enum {
	QVLOG_NONE = 0,
	QVLOG_CRITICAL = 1,
	QVLOG_MAJOR = 2,
	QVLOG_MINOR = 3,
	QVLOG_INFO = 4,
	QVLOG_DETAIL = 5,
	QVLOG_DUMP = 6,
	QVLOG_LIBRARY = 255
};

/** Error Handling **********************************************************/
void	qvPanic( const char *format, ... );
void	qvWarning( const char *format, ... );
void	qvAbort(void);
#define qvAssert(d)      (void)( (d) || (__qvAssert__(__FILE__,__LINE__,#d),0) )
#define __qvAssert__(a,b,c)      qvPanic("[%s:%u] Assertion Failed <%s>", a, b, c )

#define   GNB_ASSERT(exp)
#define   nrPanic(format, ...) qvPanic(format, ##__VA_ARGS__)
//#define   GNB_ASSERT(exp) qvAssert(exp)

/** Manifest ****************************************************************/
/* Values of timer_tuning param for module-timer pool.  */
#define QV_TPOOL_EXT	0
#define QV_TPOOL_NONE	-1

QMODULE	qvRegister( QDRIVER driver, const char *name, 
		unsigned int service, const QMANIFEST *methods, void *data);
QMODULE	qvRegisterEx( QDRIVER driver, const char *name, 
		unsigned int service, const QMANIFEST *methods, void *data,
		int timer_tuning, int *cErr);
void	*qvMsgAllocFromModule( QMODULE module, unsigned int size );
void	qvIncoming( QMODULE from, QMODULE to, signed int priority, void *message );
QMODULE	qvSetOutgoing( unsigned long service, 
		int (*outgoing)(void *, void *, QMODULE, QMODULE, unsigned int), void *calldata );
void	qvAdapt( QMODULE module, const QADAPTER *adapter, void *data );
void	*qvAdaptData( QMODULE module );

/** Skeleton Encapsulating Shell ********************************************/
QMODULE	qvSetDestination( unsigned long service, const QSHELL *, void *listener, void *data );


/*void	qvSetImmediate( unsigned long name, int* cErr );*/
void	qvRun( const QSHELL *, void *listener, const QWAIT *W, int policy );
void	qvInputLoop( const QSHELL *, void *listener );
void	qvDriverLoop( QDRIVER driver, const QWAIT *W );
#define	qvOpen(s,d) (((QSHELL *)s)->open((d)))
#define	qvClose(s,d) (((QSHELL *)s)->close((d)))

/** Library Level Debugging *************************************************/
unsigned int 	__qvPoolStatus(QMPOOL pool);
unsigned int	__qvHoldStatus(QDRIVER driver);
unsigned int	__qvQueueStatus(QDRIVER driver);
void	__qvLibraryStatus(void);

/*unsigned int    qvGetQMessageSize(void);
void            qvMsgPoolDelete( QMPOOL Q );
unsigned int    qvMsgPoolBufferSize(QMPOOL Q);
void            __qvMsgPoolDecrease(QMPOOL Q, unsigned int nbufs);*/


/** Error Codes and some description ********************************************/
/* Each API functions, Initializes 'cErr' to QVERROR_NONE.
	So, Internally called functions need not reset this again.
	This is done to avoid unnecesary checks in the system. */
enum {
	QVERROR_NONE = 0,
	QVERROR_GENERIC,
	QVERROR_INVALID_SRV,
	QVERROR_TIMER_NOT_OWNER,
	QVERROR_TIMER_NOT_RUNNING,
	QVERROR_SYS_ALLOC_FAIL,
	QVERROR_MEM_POOL_EXHAUSTED,
	QVERROR_TIMER_ALLOC_FAIL,
	QVERROR_MODULE_ALLOC_FAIL,
	QVERROR_PCTL_ALLOC_FAIL,
	QVERROR_MEM_ALLOC_ILLEGAL_SIZE,
	QVERROR_MEM_ILLEGAL_LOCATION,
	QVERROR_MEM_ILLEGAL_INDEX,
	QVERROR_MEM_UNALLOCATED_BUFFER,
	QVERROR_MEM_ALLOCATED_BUFFER,
	QVERROR_MEM_ILLEGAL_BUFFER,
	QVERROR_MEM_ILLEGAL_POOL,
	QVERROR_INVALID_ARGUMENT
};
int getMemPoolStatsInShm( unsigned int poolIndex, unsigned int *allocBuf, unsigned int *peakAllocBuf );
//int getMsgPoolStatsInShm( unsigned int poolIndex, unsigned int *allocBuf, unsigned int *peakAllocBuf );
//int getQMsgPoolStatsInShm( unsigned int *allocBuf, unsigned int *peakAllocBuf );
//int getQpctlPoolStatsInShm( unsigned int *allocBuf, unsigned int *peakAllocBuf );
int getMsgPoolStats( unsigned int poolIndex, unsigned int *allocBuf, unsigned int *peakAllocBuf );
int getQMsgPoolStats( unsigned int *allocBuf, unsigned int *peakAllocBuf );
int getQpctlPoolStats( unsigned int *allocBuf, unsigned int *peakAllocBuf );
unsigned int getQMessageSize(void);
unsigned int getQpctlSize(void);

void prepareCSPLMemPoolStats(csplMemPoolStats *csplMemPoolStats_p);
void* qvPoolCreateAndReturn (unsigned int size, unsigned int nbuf);
#ifdef POOL_DEFINED_LOCK_IMPL
void* qvPoolCreateAndReturnWithOps(unsigned int size, unsigned int nbuf, const QPOOLSYSOP *op);
#endif
void *qvPoolAlloc(void *pool, const char* func, const unsigned int line );

unsigned int getPoolIndex( void* Q, void *buffer);
unsigned int get_pool_index( unsigned int size );
unsigned int qvMemPoolGetUsagePercentage( unsigned int pool_index );
unsigned int get_mem_pool_usage_percentage( named_pool_alloc *pool_buffer_p,
        UInt8 max_pool_size, UInt8 pool_index );
void *allocMemFromNamedPool( named_pool_alloc *pool_buffer_p, 
        UInt8 max_pool_size, UInt32 size, const char* func, 
        const unsigned int line );

void *mac_rlcl_allocMemFromNamedPool( named_pool_alloc *pool_buffer_p, 
        UInt8 max_pool_size, UInt32 size, const char* func, 
        const unsigned int line );

inline void mac_rlcl_get_named_pool_status(UInt32 *total, UInt32 *in_use, 
        UInt32 *peak_val, named_pool_alloc *pool_buffer_p);

int get_pool_stats( void *q, UInt8 valid_idx, 
        LP_named_pool_stats pool_stats_p );

#ifdef CSPL_TWO_LOCK_IMPL
#define MAX_RE_TRY 16
#ifdef CSPL_LOCKLESS_IMPL

/*****************************************************************************
 *  * FUNCTION: init_queue
 *   
 *    DESCRIPTION:
 *                This function create a queue ,initialize head & tail 
 *                to same node, new locks are created for tail & head and
 *                returns pointer of the newly created queue
 *        
 *     ARGS: None
 *               
 *     RETURNS:
 *            pointer o the Queues
 *           
 ******************************************************************************/ 
inline static YQUEUE * init_queue ()
{
   YQUEUE *q = (YQUEUE *) malloc(sizeof(YQUEUE));

   q->len = 0;
   q->head.top = 0;
   q->head.cnt = 0;
   q->len = 0;
  
   return q;
}

/*****************************************************************************
 *   FUNCTION: enqueue
 *   
 *   DESCRIPTION:
 *     This function push a node in the tail of queue
 *  
 *   ARGS: q - Pointer to Queue 
 *            node:  pointer of node which to be inserted on the queue
 *   RETURNS:
 *           none
 *  
 * *****************************************************************************/
inline static UInt8 enqueue(YQUEUE *q, YPNODE *node)
{
    UInt8 try_count = MULTIPLY_BY_TWO(MAX_RE_TRY);
    struct queue_head new_head, old_head;

    if(PNULL != q && PNULL != node)
    {
        /* If incase there is any context switch while direct assignment, 
         * will get corrected while __atomic_compare_exchange.
         * Using atomic load increases CPU utilization */
        //__atomic_load((queue_head *)&q->head, (queue_head *)&old_head, __ATOMIC_SEQ_CST);
        old_head = q->head;
        new_head.top = node;
        while(try_count--)
        {
            new_head.cnt = old_head.cnt + 1;
            node->link = old_head.top;

            if(__atomic_compare_exchange((queue_head *)&q->head,
                          (queue_head *)&old_head,
                          (queue_head *)&new_head,
                          NR_FALSE,
                          __ATOMIC_SEQ_CST,
                          __ATOMIC_SEQ_CST))
            {
                __atomic_add_fetch((UInt64 *)&q->len, 1, __ATOMIC_SEQ_CST);
                return NR_SUCCESS;
            }
        }
    }
    return NR_FAILURE;
}

/*****************************************************************************
 *  * FUNCTION: dequeue
 *
 *    DESCRIPTION:
 *            This function pop a node from the head of queue
 * 
 * ARGS: q - Pointer to Queue 
 *         
 * RETURNS:
 *   Pointer of the node
 * 
 ******************************************************************************/
inline static YPNODE * dequeue(YQUEUE *q)
{
    struct queue_head new_head, old_head;
    UInt8 try_count = MULTIPLY_BY_TWO(MAX_RE_TRY);

    if(PNULL != q)
    {
        /* If incase there is any context switch while direct assignment, 
         * will get corrected while __atomic_compare_exchange.
         * Using atomic load increases CPU utilization */
        //__atomic_load((queue_head *)&q->head, (queue_head *)&old_head, __ATOMIC_SEQ_CST);
        old_head = q->head;

        while(try_count--)
        {
            /* Check if list is empty */
            if(PNULL == old_head.top)
            {
                 break;
            }
            new_head.top = (YPNODE *)old_head.top->link;
            new_head.cnt = old_head.cnt + 1;
            if(__atomic_compare_exchange((queue_head *)&q->head,
                          (queue_head *)&old_head,
                          (queue_head *)&new_head,
                          NR_FALSE,
                          __ATOMIC_SEQ_CST,
                          __ATOMIC_SEQ_CST))
            {
                __atomic_sub_fetch((UInt64 *)&q->len, 1, __ATOMIC_SEQ_CST);
                return old_head.top;
            }
        }
    }
    return PNULL;
}

/*****************************************************************************
 *  * FUNCTION: queue_count
 *
 *    DESCRIPTION:
 *            This function returns the number of elements in the Queue
 * 
 * ARGS: q - Pointer to Queue 
 *         
 * RETURNS:
 *   Number of nodes in the queue
 * 
 ******************************************************************************/
inline static UInt32 queue_count(YQUEUE *q)
{
    UInt64 count=0;
    if(PNULL != q)
    {
        __atomic_load ((UInt64 *)&q->len, (UInt64 *)&count, __ATOMIC_SEQ_CST);
    }
    return count;
}
#else
/*****************************************************************************
 * FUNCTION: enqueue
 *
 * DESCRIPTION:
 *           This function push a node in the tail of queue
 *
 * ARGS: q - Pointer to Queue 
 *          temp:  pointer of node which to be inserted on the queue
 * RETURNS:
 *           none
 *
 *****************************************************************************/
inline static void enqueue(YQUEUE *q,YPNODE *temp)
{
   temp->link = NULL;
  
   qvLock(q->tail_lock);
   q->tail->link = temp;
   q->tail = temp;
   qvUnlock(q->tail_lock);
}

/*****************************************************************************
 * FUNCTION: dequeue
 *
 * DESCRIPTION:
 *           This function pop a node from the head of queue
 *
 * ARGS: q - Pointer to Queue 
 *          
 * RETURNS:
 *           Pointer of the node
 *
 *****************************************************************************/

inline static YPNODE * dequeue(YQUEUE *q)
{
  YPNODE *old_head,*new_head;
  UInt8 try_count = MAX_RE_TRY;

  while(try_count--)
  {
      qvLock(q->head_lock);
      old_head = q->head;
      new_head = old_head->link;
      /* head node cannot be NULL because always divider node present */      
      if(new_head == NULL)
      {
          qvUnlock(q->head_lock);
          return 0;
      }
      q->head = new_head;
      qvUnlock(q->head_lock);

      /* This means the divider node is at head, push the divider to end of list */
      if (old_head == &q->divider) 
      {
          enqueue(q,old_head);
          continue;
      }
      old_head->link = &q->divider;
      return old_head;
  }
  return NULL;
}

/*****************************************************************************
 * FUNCTION: init_queue
 *
 * DESCRIPTION:
 *           This function create a queue ,initialize head & tail 
 *           to same node, new locks are created for tail & head and
 *           returns pointer of the newly created queue
 *
 * ARGS: None
 *       
 * RETURNS:
 *           pointer o the Queues
 *
 *****************************************************************************/ 
inline static YQUEUE * init_queue ()
{
   YQUEUE *Q = (YQUEUE *) malloc_wrapper(sizeof(YQUEUE));

   Q->divider.link = NULL;
   Q->head = (YPNODE *)&Q->divider;
   Q->tail = (YPNODE *)&Q->divider;

   Q->head_lock = qvNewLock();
   Q->tail_lock = qvNewLock();
   return Q;
}
#endif
#endif

unsigned char qvPoolGetAllocationStatus(void* buffer);

/*****************************************************************************
* * FUNCTION: getPoolLocate
* *
* * DESCRIPTION:
* *             Used to retrieve the pointer to a buffer in a pool based on the
* *             index of this buffer in that pool. Buffer returned only
* *             if it is allocated.
* *
* * ARGS:
* *           pool            Pointer to the pool
* *           index           Index of buffer in a pool.
* *
* * RETURNS:
* *                   Pointer to the buffer.
* *
*******************************************************************************/
static inline void *getPoolLocate( void* Q, unsigned int indexparam)
{
    return qvPoolLocateEx(Q, indexparam, 0);
}

/*****************************************************************************
 * * FUNCTION: getPoolSequence
 * *
 * * DESCRIPTION:
 * *                 This function returns the unique number depending upon
 * *                 the number of times 'buffer' has been allocated.
 * *
 * * ARGS:
 * *                 buffer, Pointer to the buffer.
 * *
 * * RETURNS:
 * *
 * ******************************************************************************/
static inline unsigned short getPoolSequence( void *buffer )
{
    unsigned char   *c = (unsigned char *)buffer;
    qbuf   *q = (qbuf *)(void *)(c - YALIGN(sizeof(qbuf), ALIGN_OFFSET ));

    return q->incarnation;
}


#endif /*_CSPL_H_*/
