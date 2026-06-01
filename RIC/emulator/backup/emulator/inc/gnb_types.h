/*******************************************************************************
*
*   FILE NAME:
*       gnb_defines.h
*
*   DESCRIPTION:
*       This file contains common types used across gNB layers.
*
*   DATE            AUTHOR      REFERENCE       REASON
*   09 Mar 2018     Chirantan   ---------       Initial
*
*   Copyright (c) 2018, Aricent Inc. All Rights Reserved
*
*******************************************************************************/

#ifndef _GNB_TYPES_H_
#define _GNB_TYPES_H_

#include <ctype.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/select.h>
#include <sys/eventfd.h>
#include <sys/socket.h>
#include <sys/resource.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/uio.h>
#include <sys/un.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <sys/epoll.h>
#include <sys/timerfd.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/sctp.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sched.h>
#include <string.h>
#include <math.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <execinfo.h>
#include <byteswap.h>
#include <limits.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
#include <mqueue.h>
#include <getopt.h>
#include <termios.h>
//#include <term.h>
#include <curl/curl.h>
#include <regex.h>

/*******************************************************************************
 * STANDARD DATA TYPES DEFINITION
 ******************************************************************************/

typedef unsigned char        UInt8;

typedef char                 SInt8;
typedef signed char          Int8;
typedef unsigned short       UInt16;
typedef signed short         SInt16;
typedef unsigned int         UInt32;
typedef signed int           SInt32;
typedef unsigned long        ULong32;
typedef signed long          SLong32;
typedef unsigned long long   UInt64;
typedef signed long long     SInt64;
typedef float                UDouble32;
typedef double               UDouble64;

typedef UInt8           gnb_return_t;
typedef size_t          gnb_size_t;
typedef UInt16          gnb_counter_t;
typedef UInt16          gnb_tag_t;
typedef UInt16          gnb_length_t;
typedef UInt64          tickType_t;

typedef SInt32 SocketType;
typedef struct sockaddr_in SockAddr;
typedef struct sctp_sndrcvinfo Sndrcvinfo;
typedef struct sockaddr_in6 sockAddrIn6;
typedef struct sockaddr_un  SockAddrUnix;
typedef struct iovec iovec_t;
typedef struct timespec TimeSpec;
typedef struct itimerval iTimerVal;
typedef struct hostent Hostent;
typedef clockid_t ClockId;

typedef struct itimerspec iTimerSpec;

typedef struct timeval timeVal;
typedef struct timezone timeZone;
typedef  fd_set fd_Set;
typedef  sigset_t sigSet_t;
typedef  eventfd_t eventFD_t;
typedef struct rlimit  rLimit;
typedef  struct shmid_ds  Shmid_Ds;


/*******************************************************************************
 * OTHER GLOBAL TYPEDEFS
 ******************************************************************************/
typedef pthread_mutex_t NR_SEM;
typedef sem_t           SEM_T;

typedef  mqd_t MQD_T;

#define IPV6_ADDR_SIZE 16

#define MAX_EL_COUNT    80

typedef struct HeaderInfoT
{
    UInt8 srcIp[IPV6_ADDR_SIZE];
    UInt8 destIp[IPV6_ADDR_SIZE];
}HeaderInfo;
#endif   /* _GNB_DEFINES_H_ */
