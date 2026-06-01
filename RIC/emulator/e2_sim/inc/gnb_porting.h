/******************************************************************************
*
*   FILE NAME:
*       gnb_porting.h
*
*   DESCRIPTION:
*       This is the header file which contains miscellaneous porting functions.
*
*   DATE            AUTHOR             REFERENCE       REASON
*   31 May 2018     Praneet Gupta      ---------       Initial
*
*   Copyright (c) 2018, Aricent Inc. All Rights Reserved
*
******************************************************************************/

#ifndef _GNB_PORTING_H_
#define _GNB_PORTING_H_

#include <gnb_types.h>
#include <gnb_defines.h>

#define BOOL_COMPARE_AND_SWAP(a,b,c) __sync_bool_compare_and_swap((SInt32 *)(a),(SInt32)(b),(SInt32)(c))
#if defined(__x86_64__) || defined(__aarch64__)
#define BOOL_COMPARE_AND_SWAP_ADDR(a,b,c) __sync_bool_compare_and_swap((SInt64 *)(a),(SInt64)(b),(SInt64)(c))
#else
#define BOOL_COMPARE_AND_SWAP_ADDR(a,b,c) __sync_bool_compare_and_swap((SInt32 *)(a),(SInt32)(b),(SInt32)(c))
#endif

#ifdef __PPC__
static inline void __sync_fetch_and_sub_ev16_lw(UInt16 *ptr, UInt16 value)
{
    UInt16 ret;
    __asm__ __volatile__ (
        "lwsync;"
        "1:"
        "lharx      %0,0,%3;"
        "subf       %0,%2,%0;"
        "sthcx.     %0,0,%3;"
        "bne        1b;"
        "lwsync;"
        : "+&b"(ret), "+m"(*ptr)
        : "r"(value), "r"(ptr)
        : "cc", "memory"
    );
    return;
}

static inline void __sync_fetch_and_add_ev16_lw(UInt16 *ptr, UInt16 value)
{
    UInt16 ret;
    __asm__ __volatile__ (
        "lwsync;"
        "1:"
        "lharx      %0,0,%3;"
        "add        %0,%2,%0;"
        "sthcx.     %0,0,%3;"
        "bne        1b;"
        "lwsync;"
        : "+&b"(ret), "+m"(*ptr)
        : "r"(value), "r"(ptr)
        : "cc", "memory"
    );
    return;
}

static inline void __sync_fetch_and_sub_ev32_lw(UInt32 *ptr, UInt32 value)
{
    UInt32 ret;
    __asm__ __volatile__ (
        "lwsync;"
        "1:"
        "lwarx      %0,0,%3;"
        "subf       %0,%2,%0;"
        "stwcx.     %0,0,%3;"
        "bne        1b;"
        "lwsync;"
        : "+&b"(ret), "+m"(*ptr)
        : "r"(value), "r"(ptr)
        : "cc", "memory"
    );
    return;
}

static inline void __sync_fetch_and_add_ev32_lw(UInt32 *ptr, UInt32 value)
{
    UInt32 ret;
    __asm__ __volatile__ (
        "lwsync;"
        "1:"
        "lwarx      %0,0,%3;"
        "add        %0,%2,%0;"
        "stwcx.     %0,0,%3;"
        "bne        1b;"
        "lwsync;"
        : "+&b"(ret), "+m"(*ptr)
        : "r"(value), "r"(ptr)
        : "cc", "memory"
    );
    return;
}

static inline void __sync_fetch_and_sub_ev64_lw(UInt64 *ptr, UInt64 value)
{
    UInt64 ret;
    __asm__ __volatile__ (
        "lwsync;"
        "1:"
        "ldarx      %0,0,%3;"
        "subf       %0,%2,%0;"
        "stdcx.     %0,0,%3;"
        "bne        1b;"
        "lwsync;"
        : "+&b"(ret), "+m"(*ptr)
        : "r"(value), "r"(ptr)
        : "cc", "memory"
    );
    return;
}

static inline void __sync_fetch_and_add_ev64_lw(UInt64 *ptr, UInt64 value)
{
    UInt64 ret;
    __asm__ __volatile__ (
        "lwsync;"
        "1:"
        "ldarx      %0,0,%3;"
        "add        %0,%2,%0;"
        "stdcx.     %0,0,%3;"
        "bne        1b;"
        "lwsync;"
        : "+&b"(ret), "+m"(*ptr)
        : "r"(value), "r"(ptr)
        : "cc", "memory"
    );
    return;
}

/* AND */
static inline void __sync_fetch_and_and_ev08_lw(UInt8 *ptr, UInt8 value)
{
    UInt8 ret;
    __asm__ __volatile__ (
        "lwsync;"
        "1:"
        "lbarx      %0,0,%3;"
        "and        %0,%2,%0;"
        "stbcx.     %0,0,%3;"
        "bne        1b;"
        "lwsync;"
        : "+&b"(ret), "+m"(*ptr)
        : "r"(value), "r"(ptr)
        : "cc", "memory"
    );
    return;
}

static inline void __sync_fetch_and_and_ev16_lw(UInt16 *ptr, UInt16 value)
{
    UInt16 ret;
    __asm__ __volatile__ (
        "lwsync;"
        "1:"
        "lharx      %0,0,%3;"
        "and        %0,%2,%0;"
        "sthcx.     %0,0,%3;"
        "bne        1b;"
        "lwsync;"
        : "+&b"(ret), "+m"(*ptr)
        : "r"(value), "r"(ptr)
        : "cc", "memory"
    );
    return;
}

static inline void __sync_fetch_and_and_ev32_lw(UInt32 *ptr, UInt32 value)
{
    UInt32 ret;
    __asm__ __volatile__ (
        "lwsync;"
        "1:"
        "lwarx      %0,0,%3;"
        "and        %0,%2,%0;"
        "stwcx.     %0,0,%3;"
        "bne        1b;"
        "lwsync;"
        : "+&b"(ret), "+m"(*ptr)
        : "r"(value), "r"(ptr)
        : "cc", "memory"
    );
    return;
}

static inline void __sync_fetch_and_and_ev64_lw(UInt64 *ptr, UInt64 value)
{
    UInt64 ret;
    __asm__ __volatile__ (
        "lwsync;"
        "1:"
        "ldarx      %0,0,%3;"
        "and        %0,%2,%0;"
        "stdcx.     %0,0,%3;"
        "bne        1b;"
        "lwsync;"
        : "+&b"(ret), "+m"(*ptr)
        : "r"(value), "r"(ptr)
        : "cc", "memory"
    );
    return;
}

/* OR */
static inline void __sync_fetch_and_or_ev08_lw(UInt8 *ptr, UInt8 value)
{
    UInt8 ret;
    __asm__ __volatile__ (
        "lwsync;"
        "1:"
        "lbarx      %0,0,%3;"
        "or         %0,%2,%0;"
        "stbcx.     %0,0,%3;"
        "bne        1b;"
        "lwsync;"
        : "+&b"(ret), "+m"(*ptr)
        : "r"(value), "r"(ptr)
        : "cc", "memory"
    );
    return;
}

static inline void __sync_fetch_and_or_ev16_lw(UInt16 *ptr, UInt16 value)
{
    UInt16 ret;
    __asm__ __volatile__ (
        "lwsync;"
        "1:"
        "lharx      %0,0,%3;"
        "or         %0,%2,%0;"
        "sthcx.     %0,0,%3;"
        "bne        1b;"
        "lwsync;"
        : "+&b"(ret), "+m"(*ptr)
        : "r"(value), "r"(ptr)
        : "cc", "memory"
    );
    return;
}

static inline void __sync_fetch_and_or_ev32_lw(UInt32 *ptr, UInt32 value)
{
    UInt32 ret;
    __asm__ __volatile__ (
        "lwsync;"
        "1:"
        "lwarx      %0,0,%3;"
        "or         %0,%2,%0;"
        "stwcx.     %0,0,%3;"
        "bne        1b;"
        "lwsync;"
        : "+&b"(ret), "+m"(*ptr)
        : "r"(value), "r"(ptr)
        : "cc", "memory"
    );
    return;
}

static inline void __sync_fetch_and_or_ev64_lw(UInt64 *ptr, UInt64 value)
{
    UInt64 ret;
    __asm__ __volatile__ (
        "lwsync;"
        "1:"
        "ldarx      %0,0,%3;"
        "or         %0,%2,%0;"
        "stdcx.     %0,0,%3;"
        "bne        1b;"
        "lwsync;"
        : "+&b"(ret), "+m"(*ptr)
        : "r"(value), "r"(ptr)
        : "cc", "memory"
    );
    return;
}

#endif


#ifndef __x86_64__
#define FETCH_AND_OR(a,b)  __atomic_fetch_or(a,b,__ATOMIC_SEQ_CST)
#define FETCH_AND_AND(a,b) __atomic_fetch_and(a,b,__ATOMIC_SEQ_CST)
#define FETCH_AND_ADD(a,b) __atomic_fetch_add(a,b,__ATOMIC_SEQ_CST)
#define FETCH_AND_SUB(a,b) __atomic_fetch_sub(a,b,__ATOMIC_SEQ_CST)
#define SUB_AND_FETCH(a,b) __atomic_sub_fetch(a,b,__ATOMIC_SEQ_CST)
#define ADD_AND_FETCH(a,b) __atomic_add_fetch(a,b,__ATOMIC_SEQ_CST)
#define FETCH_AND_ADD_EV64(a,b) __atomic_fetch_add(a,b,__ATOMIC_SEQ_CST)
#define FETCH_AND_SUB_EV64(a,b) __atomic_fetch_sub(a,b,__ATOMIC_SEQ_CST)
#define FETCH_AND_ADD_EV32(a,b) __atomic_fetch_add(a,b,__ATOMIC_SEQ_CST)
#define FETCH_AND_SUB_EV32(a,b) __atomic_fetch_sub(a,b,__ATOMIC_SEQ_CST)
#define FETCH_AND_ADD_EV16(a,b) FETCH_AND_ADD(a,b)
#define FETCH_AND_SUB_EV16(a,b) FETCH_AND_SUB(a,b)
#define FETCH_AND_AND_EV08(a,b) FETCH_AND_AND(a,b)
#define FETCH_AND_AND_EV16(a,b) FETCH_AND_AND(a,b)
#define FETCH_AND_AND_EV32(a,b) FETCH_AND_AND(a,b)
#define FETCH_AND_AND_EV64(a,b) FETCH_AND_AND(a,b)
#define FETCH_AND_OR_EV08(a,b) FETCH_AND_OR(a,b)
#define FETCH_AND_OR_EV16(a,b) FETCH_AND_OR(a,b)
#define FETCH_AND_OR_EV32(a,b) FETCH_AND_OR(a,b)
#define FETCH_AND_OR_EV64(a,b) FETCH_AND_OR(a,b)
#endif
#define PTHREAD_MUTEX_INIT(a,b) pthread_mutex_init( a, b )  
#define PTHREAD_MUTEX_LOCK(a)   pthread_mutex_lock( a ) 
#define PTHREAD_MUTEX_UNLOCK(a) pthread_mutex_unlock( a )

#if defined(__x86_64__)
static inline void atomic64_inc( volatile int64_t *src)
{
    asm volatile(
            "lock ; "
            "incq %[src]"
            : [src] "=m" (*src)   /* output */
            : "m" (src)          /* input */);
}
static inline void atomic64_dec(volatile int64_t *src)
{
    asm volatile(
            "lock ; "
            "decq %[src]"
            : [src] "=m" (*src)   /* output */
            : "m" (src)          /* input */
            );
}

static inline int64_t atomic64_add_return(volatile int64_t *src, int64_t inc)
{
    int64_t prev = inc;

    asm volatile(
            "lock ; "
            "xaddq %[prev], %[src]"
            : [prev] "+r" (prev),   /* output */
            [src] "=m" (*src)
            : "m" (src)          /* input */
            );
    return prev + inc;
}
static inline int64_t atomic64_sub_return(volatile int64_t *v, int64_t dec)
{
    return atomic64_add_return(v, -dec);
}
static inline int64_t atomic64_return_add(volatile int64_t *src, int64_t inc)
{
    int64_t prev = inc;

    asm volatile(
            "lock ; "
            "xaddq %[prev], %[src]"
            : [prev] "+r" (prev),   /* output */
            [src] "=m" (*src)
            : "m" (src)          /* input */
            );
    return prev ;
}
static inline int64_t atomic64_return_sub(volatile int64_t *v, int64_t dec)
{
    return atomic64_return_add(v, -dec);
}

#define FETCH_AND_ADD(a,b) atomic64_return_add((volatile int64_t *)a,(int64_t)b)
#define FETCH_AND_SUB(a,b) atomic64_return_sub((volatile int64_t *)a,(int64_t)b)
#define SUB_AND_FETCH(a,b) atomic64_sub_return((volatile int64_t *)a,(int64_t)b)
#define ADD_AND_FETCH(a,b) atomic64_add_return((volatile int64_t *)a,(int64_t)b)
#define FETCH_AND_ADD_EV64(a,b) atomic64_return_add((volatile int64_t *)a,(int64_t)b)
#define FETCH_AND_SUB_EV64(a,b) atomic64_return_sub((volatile int64_t *)a,(int64_t)b)
#define FETCH_AND_ADD_EV32(a,b) atomic64_return_add((volatile int64_t *)a,(int64_t)b)
#define FETCH_AND_SUB_EV32(a,b) atomic64_return_sub((volatile int64_t *)a,(int64_t)b)
#define FETCH_AND_ADD_EV16(a,b) FETCH_AND_ADD(a,b)
#define FETCH_AND_SUB_EV16(a,b) FETCH_AND_SUB(a,b)
#define FETCH_AND_AND(a,b) __sync_fetch_and_and(a,b)
#define FETCH_AND_OR(a,b) __sync_fetch_and_or(a,b)
#define FETCH_AND_AND_EV08(a,b) FETCH_AND_AND(a,b)
#define FETCH_AND_AND_EV16(a,b) FETCH_AND_AND(a,b)
#define FETCH_AND_AND_EV32(a,b) FETCH_AND_AND(a,b)
#define FETCH_AND_AND_EV64(a,b) FETCH_AND_AND(a,b)
#define FETCH_AND_OR_EV08(a,b) FETCH_AND_OR(a,b)
#define FETCH_AND_OR_EV16(a,b) FETCH_AND_OR(a,b)
#define FETCH_AND_OR_EV32(a,b) FETCH_AND_OR(a,b)
#define FETCH_AND_OR_EV64(a,b) FETCH_AND_OR(a,b)
#endif

#ifdef __PPC__
#ifndef MBAR_INST
#define MBAR_INST "lwsync;"
#endif
#define _Mbar() { __asm__ __volatile__ (MBAR_INST ::: "memory"); }
#else
#define MBAR_INST ""
#define _Mbar() { __sync_synchronize(); }
#endif

#ifdef __PPC__
#ifndef MBAR_INST
#define MBAR_INST "lwsync;"
#endif
#define _Mbar() { __asm__ __volatile__ (MBAR_INST ::: "memory"); }
#else
#define MBAR_INST ""
#define _Mbar() { __sync_synchronize(); }
#endif

/*LOG2 will provide only ceil value*/
#define LOG2(VAL) (UInt32)(8*sizeof (UInt64) - __builtin_clzll(VAL) - 1)
#define SET_BITS_COUNT(VAL) __builtin_popcountll(VAL)
#define SET_BITS_COUNT_INT(VAL) __builtin_popcount(VAL)
#define FFS(VAL) (UInt32)(__builtin_ffsll(VAL))
#define FFS_INT(VAL) (UInt8)(__builtin_ffs(VAL))
#define FFS_LONG(VAL) (UInt8)(__builtin_ffsl(VAL))

#define MIN(X,Y) ((X) < (Y) ?  (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ?  (X) : (Y))

/* X is dividend and Y is divisor*/
#define ROUND(X,Y)  (((X) + ((Y / 2))) / (Y))

extern SInt32 recvfrom_wrapper(SInt32 sockFD, void * msgBuf, UInt32 msg_len, SInt32 flag,SockAddr *sockAddr_p,socklen_t addrlen );
extern void cpu_zero_wrapper (cpu_set_t *set);
extern void cpu_set_wrapper (int cpu, cpu_set_t *set);
extern void qsort_wrapper (void *base, gnb_size_t mem, gnb_size_t size,int (*compar)(const void *, const void *));
extern SInt32 kill_wrapper(pid_t pid, SInt32 sig);
extern SInt32 pthread_setspecific_wrapper(pthread_key_t key, const void *value);
extern SInt32 bind_wrapper(SInt32 sockfd, const SockAddr *addr, socklen_t addrlen);
extern UInt16 sendmsg_wrapper6( struct iovec *io_vec, UInt16 num_segments,SInt32 client, sockAddrIn6 server );
#define VA_START va_start
#define VA_END va_end
#define VA_ARG va_arg
#define QSORT qsort 
#define GNB_CPU_ZERO        CPU_ZERO
typedef struct tm Tm;
typedef struct in_addr InAddr;
typedef struct ifaddrs ifAddrs;
typedef struct sched_param  SchedParam;
typedef struct sockaddr  SockAddr_genric;
typedef struct sctp_sndrcvinfo  sctp_sndrcv;

extern UInt8 g_sfn_log_level;
extern void* memcpy_wrapper(void *dest, const void *src, gnb_size_t n);

extern SInt32 gettimeofday_wrapper(timeVal *tv,  timeZone *tz);
extern SInt32 fclose_wrapper(FILE *fd);
extern SInt32 shmget_wrapper(UInt32 key, gnb_size_t size, SInt32 shmflg);
extern void bzero_wrapper(void *s, gnb_size_t n);
extern void *malloc_wrapper(gnb_size_t size);
extern void free_wrapper(void *m);
extern void lteFD_CLR(SInt32 fd, fd_set *set);
extern SInt32 FD_ISSET_WRAPPER(SInt32 fd, fd_set *set);
extern void FD_SET_WRAPPER(SInt32 fd, fd_set *set);
extern void FD_ZERO_WRAPPER(fd_set *set);
extern UInt16 htons_wrapper (UInt16 hostshort);
extern UInt32 htonl_wrapper(UInt32 hostlong);
extern UInt32 ntohl_wrapper(UInt32 netshort);
extern UInt16 ntohs_wrapper(UInt16 netshort);
extern SInt32 socket_wrapper(SInt32 domain, SInt32 type, SInt32 protocol);
extern gnb_size_t strlen_wrapper(const SInt8 *s);
extern SInt32  strcmp_wrapper( const SInt8 *s1, const SInt8 *s2);
extern SInt32  strncmp_wrapper( const SInt8 *s1, const SInt8 *s2, gnb_size_t n );
extern SInt32 snprintf_wrapper(SInt8 *s, gnb_size_t n, const SInt8  *format, ...);
extern SInt32 printf_wrapper(const SInt8 *fmt, ...);
extern SInt32 setrlimit_wrapper(SInt32 resource, const rLimit *rlim);
extern in_addr_t inet_addr_wrapper(const char *cp);
extern SInt32 getrlimit_wrapper(SInt32 resource, rLimit *rlim);
extern SInt32 memcmp_wrapper(const void *s1, const void *s2, gnb_size_t n);
extern SInt32 setsockopt_wrapper(SInt32 sockfd, SInt32 level, SInt32 optname,const void *optval, SInt32 optlen);
extern SInt32 close_wrapper(SInt32 fd);
extern void *shmat_wrapper(SInt32 shmid, const void *shmaddr, SInt32 shmflg);
extern void* memset_wrapper(void *s, SInt32 c, gnb_size_t n);
extern void  *memmove_wrapper(void *d, void *s, gnb_size_t n);

extern char* strerror_wrapper(UInt32 err);
extern pid_t fork_wrapper(void);
extern char *fgets_wrapper(char *s, UInt32 size, FILE *stream);
extern UInt32  execve_wrapper(const  char  *filename,  char  *const argv [], char *const envp[]);
extern FILE *fopen_wrapper(const SInt8 *filename , const SInt8 *mode );
extern SInt32 atoi_wrapper(const UInt8 *nptr);
extern UInt64 atoill_wrapper(const UInt8 *nptr);
extern UDouble32 atof_wrapper(const UInt8 *nptr);
extern void exit_wrapper(SInt32 n);
extern SInt8* strchr_wrapper(const SInt8 *s, SInt32 c);
extern SInt32 raise_wrapper(SInt32 sig);
extern  __sighandler_t signal_wrapper (SInt32 signum, void (*handler)(int));
extern SInt8 *strcpy_wrapper(SInt8 *dest, const SInt8 *src);
extern char *strstr_wrapper(const char *haystack, const char *needle);
extern UDouble32 ceilf_wrapper(UDouble32 x);
extern void usleep_wrapper(UInt32 uSec);
extern SInt8 *strcat_wrapper(SInt8 *dest, const SInt8 *src);
extern SInt8 *strncat_wrapper(SInt8 *dest, const SInt8 *src, UInt32 n);
extern SInt8 *strtok_wrapper(SInt8 *str, const SInt8 *delim);
extern SInt8 *strncpy_wrapper( SInt8 *dest, const SInt8 *src, gnb_size_t n );
extern gnb_size_t  strnlen_wrapper( const SInt8 *s1, gnb_size_t max_len );
extern void abort_wrapper(void);
extern UDouble64  log10_wrapper(UDouble64 x);
extern UDouble64  log2_wrapper(UDouble64 x);
extern UDouble32 atan_wrapper(UDouble32 x);
extern UDouble32 atan2_wrapper(UDouble32 y, UDouble32 x);
extern UInt8 isnan_wrapper(UDouble64 x);
extern UDouble64  log_wrapper(UDouble64 x);
extern UDouble64 ceil_wrapper(UDouble64 x);
extern UDouble64 floor_wrapper(UDouble64 x);
extern SInt32 abs_wrapper(SInt32 j);
extern SInt32 ffs_wrapper(SInt32 j);
extern SInt32 nanosleep_wrapper(const TimeSpec *req, TimeSpec *rem);
extern SInt32 syscall_SYS_gettid_wrapper(void);
extern SInt32 pow_wrapper(double x, double y);
extern UDouble64 pow_wrapper_double(double x, double y);
extern SInt32 sched_setaffinity_wrapper(pid_t pid, gnb_size_t cpusetsize,cpu_set_t *mask);
extern void clock_gettime_wrapper(ClockId clk_id,TimeSpec *ts_p);
extern inline ULong32 get_time_diff(TimeSpec *start, TimeSpec *end);
extern void perror_wrapper (SInt8 *str);
extern SInt32 pselect_wrapper(SInt32 nfds, fd_Set *readfds, fd_Set *writefds, fd_Set *exceptfds, const TimeSpec *timeout,const sigSet_t *sigmask);

extern UInt64 strtol_wrapper(const UInt8* str, UInt8** endptr, UInt8 base);
extern SInt32 eventfd_initialize_wrapper(UInt32 initVal,SInt32 flag);
extern SInt32 eventfd_read_wrapper(SInt32 fd, eventFD_t *value);
extern UInt32 setitimer_wrapper(SInt32 which, const iTimerVal *new_value,iTimerVal *old_value);
extern SInt32 inet_aton_wrapper(const SInt8 *cp, void *inp);
extern SInt32 fflush_wrapper(FILE *stream);
extern SInt32 mq_unlink_wrapper(const char *name);
extern SInt32 select_wrapper(SInt32 nfds, fd_Set *readfds, fd_Set *writefds,fd_Set *exceptfds, timeVal *timeout);
extern SInt32 pthread_mutex_lock_wrapper(pthread_mutex_t *mutex);
extern SInt32 shmctl_wrapper(int shmid, int cmd, Shmid_Ds *buf);
extern SInt32 pthread_cond_signal_wrapper(pthread_cond_t *cond);
extern SInt32 mlockall_wrapper(SInt32 flags);
extern SInt32 scanf_wrapper(const char *format);
extern SInt32 open2_wrapper(const char *pathname, SInt32 flags);
extern SInt32 open3_wrapper(const char *pathname,SInt32 flags, mode_t mode);
extern SInt32 eventfd_write_wrapper(SInt32 fd, eventFD_t value);
extern SInt32 fcntl2_wrapper(SInt32 fd, SInt32 cmd);
extern SInt32 fcntl3_wrapper(SInt32 fd, SInt32 cmd1,SInt32 cmd2);
extern SInt32 bind_ipv6_wrapper(SInt32 sockfd, const sockAddrIn6 *addr, SInt32 addrlen);
extern SInt32 bind_ntl_wrapper(SInt32 hntl, SInt32 sockfd, const SockAddr *addr, SInt32 addrlen);
extern SInt32 sendto_wrapper(SInt32 sockfd, const void *buf, gnb_size_t len, SInt32 flags,const SockAddr *dest_addr, socklen_t addrlen);
extern SInt32 sendto_ipv6_wrapper(SInt32 sockfd, const void *buf, UInt32 len, SInt32 flags,const  sockAddrIn6 *dest_addr, SInt32 addrlen);
extern SInt32 backtrace_wrapper(void **buffer,SInt32 size);
extern Hostent  *gethostbyname_wrapper(const SInt8 *name);
extern SInt32 getpid_wrapper(void);
extern SInt32 inet_pton_wrapper (SInt32 domain, const SInt8 * peerTgInfV6, void *inp);
extern SInt32 bind_wrapper_addr6(SInt32 sockfd, const sockAddrIn6 *addr, SInt32 addrlen);
extern UInt16 bswap_16_wrapper(UInt16 x);
extern UInt32 bswap_32_wrapper(UInt32 x);
extern UInt16 sendmsg_wrapper( struct iovec *io_vec, UInt16 num_segments,SInt32 client, SockAddr server );
extern SInt16 recvmsg_wrapper( SInt32 fd,UInt8 *msgbuf,UInt16 msglen,HeaderInfo *hdrInfo,UInt8 ipType);
extern void FD_CLR_WRAPPER(SInt32 fd, fd_Set *set);
extern SInt32 timerfd_create_wrapper(SInt32 clock_id, SInt32 flags);
extern SInt32 timerfd_settime_wrapper(SInt32 fd, SInt32 flags,iTimerSpec* new_value,iTimerSpec* old_value);
extern ssize_t read_wrapper(SInt32 fd,void* buf,gnb_size_t count);

extern void *realloc_wrapper(void *ptr, size_t size);
extern SInt32 rrm_recvfrom_wrapper(SInt32 sockFD, void * msgBuf, UInt32 msg_len, SInt32 flag,SockAddr_genric *sockAddr_p,socklen_t *addrlen );
extern SInt32 oam_atoi_wrapper(const char *nptr);
extern SInt32 rrm_atoi_wrapper(char *nptr);
extern void oam_perror_wrapper (const char *str);
long oam_strtol_wrapper(const char *str, char** endptr, int base);
extern SInt32 rrm_bind_wrapper(SInt32 sockfd, const SockAddr_genric *addr, socklen_t addrlen);
extern SInt32 rrm_sendto_wrapper(SInt32 sockfd, const void *buf, gnb_size_t len, SInt32 flags,const SockAddr_genric *dest_addr, socklen_t addrlen);
extern void  *pthread_getspecific_wrapper(pthread_key_t key);
extern SInt32 vfprintf_wrapper(FILE *stream,const char *p_format, va_list arg);
extern UDouble32 nearbyintf_wrapper(UDouble32 value);
extern UDouble32 fabsf_wrapper(UDouble32 value);
extern UDouble32 roundf_wrapper(UDouble32 value);
extern UInt32 round_wrapper(UDouble32 value);
extern Tm *localtime_wrapper(const time_t *timep);
extern time_t time_wrapper(time_t *t);
extern UDouble64 difftime_wrapper(time_t time1,time_t time0);
extern SInt8 *inet_ntop_wrapper(SInt32 af,const void *src,char *dst,socklen_t size);
extern SInt8 *strdup_wrapper(const SInt8 *s);
extern  SInt32 ftell_wrapper(FILE *stream);
extern  SInt32 fread_wrapper(void *ptr, UInt32 size, UInt32 nmemb, FILE *stream);
extern SInt32 fseek_wrapper(FILE *stream, UInt32 offset, UInt32 whence);
extern size_t strftime_wrapper(SInt8 *s, size_t max, const SInt8 *format, const struct tm *tm);
extern SInt32 puts_wrapper(const SInt8 *s);
extern SInt8 *inet_ntoa_wrapper(InAddr in);
extern SInt8 *ctime_wrapper(const time_t *timep);
extern Tm *gmtime_wrapper(const time_t *timep);
extern Tm *localtime_r_wrapper(const time_t *timep, struct tm *result);
extern SInt8 *getcwd_wrapper(SInt8 *buf, size_t size);
extern size_t fwrite_wrapper(const void *ptr, size_t size, size_t nmemb, FILE *stream);
extern SInt32 getaddrinfo_wrapper(const char *node, const char *service,
		 const struct addrinfo *hints,struct addrinfo **res);
extern SInt32 vsnprintf_wrapper(SInt8 *str, size_t size, const SInt8 *format, va_list ap);
extern SInt32 vsprintf_wrapper(SInt8 *str, const SInt8 *format, va_list ap);         
extern SInt32 vsscanf_wrapper(const SInt8 *str, const SInt8 *format, va_list ap);
extern SInt32 sscanf_wrapper(const char *str, const char *format, ...);
extern SInt32 strncasecmp_wrapper(const SInt8 *str1, const SInt8 *str2, size_t count);
extern SInt32 strcasecmp_wrapper(const SInt8 *str1, const SInt8 *str2);
extern SInt32 system_wrapper(const SInt8 *string);
extern SInt32 getifaddrs_wrapper(ifAddrs **ifap);
extern void freeifaddrs_wrapper(ifAddrs *ifa);
extern SInt32 ioctl_wrapper(SInt32 desc, SInt32 request, ...);
extern SInt32 remove_wrapper(const SInt8 *filename);
extern pid_t waitpid_wrapper(pid_t pid, SInt32 *status, SInt32 options);
extern UInt32 atol_wrapper(const SInt8 *str);
extern UInt32 getnameinfo_wrapper(const struct sockaddr *sa, socklen_t salen,    
			SInt8 *host, size_t hostlen,
			SInt8 *serv, size_t servlen, SInt32 flags);
extern UInt64 strtoull_wrapper(const SInt8* str, SInt8** endPtr, SInt32 base);
extern ULong32 strtoul_wrapper(const SInt8* str, SInt8** endPtr, SInt32 base);
extern SInt8 *strrchr_wrapper(const SInt8 *str, int c);
extern SInt32 pthread_attr_setstacksize_wrapper(pthread_attr_t *attr, size_t stacksize);
extern SInt32 pthread_attr_getstacksize_wrapper(pthread_attr_t *attr, size_t *stacksize);
extern SInt8 *strtok_r_wrapper(SInt8 *str, const SInt8 *delim, SInt8 **save_ptr);
extern void freeaddrinfo_wrapper(struct addrinfo *res);
extern UInt32 isdigit_wrapper(UInt32 c);
extern UInt32 isspace_wrapper(UInt32 c);
extern UInt32 isupper_wrapper(UInt32 c);
extern  UInt32 islower_wrapper(UInt32 c);
extern void sleep_wrapper(SInt32 time);
extern SInt32 chmod_wrapper(const SInt8 *p_pathname, mode_t mode);
extern FILE *popen_wrapper(const SInt8 *command, const SInt8 *mode);
extern UInt32 pclose_wrapper(FILE *stream);
extern UInt32 fileno_wrapper(FILE *stream);
extern UInt32 rename_wrapper(const SInt8 *old_filename, const SInt8 *new_filename);
extern pid_t setsid_wrapper(void);
extern pid_t getppid_wrapper(void);
extern SInt32 tolower_wrapper(SInt32 c);
extern void assert_wrapper(UInt32 expression);
extern void oam_assert_wrapper(char * const expression);
extern size_t strspn_wrapper(const SInt8 *s, const SInt8 *accept);
extern UInt32 regcomp_wrapper(regex_t *preg, const SInt8 *regex, UInt32 cflags);
extern void regfree_wrapper(regex_t *preg);
extern SInt32 feof_wrapper(FILE *stream);
extern SInt32 getc_wrapper(FILE *stream);
extern ssize_t write_wrapper(UInt32 fd, const void *buf, size_t count);
extern UInt32 isprint_wrapper(UInt32 c);
extern UInt32 tcgetattr_wrapper(SInt32 fd, struct termios *termios_p);
extern SInt32 tcsetattr_wrapper(SInt32 fd, SInt32 optional_actions,
				const struct termios *termios_p);
extern UInt32 sigemptyset_wrapper(sigset_t *set);
extern UInt32 sigaction_wrapper(UInt32 signum, const struct sigaction *act,
				struct sigaction *oldact);        
extern UInt32 pthread_attr_destroy_wrapper(pthread_attr_t *attr);
extern SInt32 pthread_attr_init_wrapper(pthread_attr_t *attr);
extern SInt32 pthread_attr_setinheritsched_wrapper(pthread_attr_t *attr,SInt32 inheritsched);
extern SInt32 pthread_attr_setschedparam_wrapper(pthread_attr_t *attr,SchedParam *param);
extern SInt32 pthread_attr_setschedpolicy_wrapper(pthread_attr_t *attr,SInt32 policy);
extern SInt32 pthread_cancel_wrapper(pthread_t thread);
extern SInt32 pthread_cond_signal_wrapper(pthread_cond_t *cond);
extern SInt32 pthread_cond_wait_wrapper(pthread_cond_t* cond,pthread_mutex_t* mutex);
extern SInt32 pthread_mutex_unlock_wrapper(pthread_mutex_t *mutex);
extern SInt32 accept_wrapper(SInt32 sockfd,SockAddr_genric *addr,socklen_t *addrlen);
extern SInt32 connect_wrapper(SInt32 sockfd, const SockAddr_genric *addr, socklen_t addrlen);
extern SInt32 listen_wrapper(SInt32 sockfd,SInt32 backlog);
extern SInt32 getsockopt_wrapper(SInt32 sockfd,SInt32 level,SInt32 optname,void *optval,socklen_t *optlen);
extern void fprintf_wrapper(FILE *stream, const SInt8 *format, ...);
extern void va_end_wrapper(va_list ap);
extern UInt16 pthread_setname_np_wrapper(pthread_t *thread,UInt8 *threadName);
extern SInt32 getsockname_wrapper(SInt32 sockfd, struct sockaddr *addr, socklen_t *addrlen);
extern UInt16 pthread_setname_np_wrapper(pthread_t *thread, UInt8 *threadName);
extern void srand_wrapper(SInt32 seed);           	
extern SInt32 sprintf_wrapper(SInt8 *s, const SInt8  *format, ...);

extern SInt8 get_core_num_offset_based(UInt64 *bitmap_temp, UInt64 bitmap, 
        UInt64 bitmap_offset);
extern SInt8 get_core_num(UInt64 *bitmap_temp, UInt64 bitmap);
#endif /* _GNB_PORTING_H_ */
