#if defined (E2CU_QOS_CHANGES) || defined (E2CU_MU_MIMO_CHANGES)
#ifndef _E2CU_DEFINES_H_
#define _E2CU_DEFINES_H_

/*Basic types */
#include <sys/types.h>

/* CSPL types */
#include <cspl.h>
#include <stacklayer.h>


#define MAX_NUM_RIC         1
#define MAX_IP_ADDRESS_LENGTH           16
#define MAX_NUM_IP_ADDR                     3
#define MAX_IPV6_ADDRESS_LENGTH         40
/* IPV6 Start */
#define RIC_COMM_INFO_IPV6_NUM_ADDR_PRESENT    0x01
#define RIC_COMM_INFO_IPV6_ADDR_PRESENT        0x02
/*sctp parameters start*/
#define E2CU_SCTP_DEFAULT_RTO_INITIAL 3000
#define E2CU_SCTP_DEFAULT_RTO_MAX 6000
#define E2CU_SCTP_DEFAULT_RTO_MIN 1000
#define E2CU_SCTP_DEFAULT_ASSOC_MAX_RTX 10
#define E2CU_SCTP_DEFAULT_VAL_COOKIE_LIFE 60000
#define E2CU_SCTP_DEFAULT_PATH_MAX_RTX 5
#define E2CU_SCTP_DEFAULT_MAX_INIT_RTX 8
#define E2CU_SCTP_DEFAULT_INIT_TIMEOUT 0
#define SOCKET_DESC_SIZE       4
/* Value for External Module Ids */
#define E2CU_MIN_EXT_MODULE_ID   1
#define RIC_MODULE_ID   (E2CU_MIN_EXT_MODULE_ID + 1)
/*sctp parameters stop*/
/* E2_NODE_CHANGE */
#define MAX_PLMN_ID_BYTES   3
#define GNB_ID_OCTET_SIZE   4

#define E2CU_ZERO            0
#define E2CU_ONE             1
#define E2CU_TWO             2
#define E2CU_THREE           3
#define E2CU_FOUR            4
#define E2CU_FIVE            5
#define E2CU_SIX             6
#define E2CU_SEVEN           7
#define E2CU_EIGHT           8
#define E2CU_ONE_ZERO_ONE    101

typedef struct
{
    UInt8 ip_addr[MAX_IP_ADDRESS_LENGTH]; /*^ M,0,OCTET_STRING,FIXED ^*/
}ip_address_t;

typedef struct
{
    UInt8 ipv6_addr[MAX_IPV6_ADDRESS_LENGTH];
    /*^ M,0,OCTET_STRING,FIXED ^*/
}ipv6_address_t;


typedef struct
{
    UInt8        bitmask;    /*^ BITMASK ^*/
    UInt8        num_ip_addr;
    UInt8        ip_addr[MAX_IP_ADDRESS_LENGTH];
    UInt16       port;      /*^ M,0,N,0,0 ^*/
    UInt8        num_ipv6_addr; 
    UInt8        ipv6_addr[MAX_IPV6_ADDRESS_LENGTH];  
}e2cu_comm_info_t;

typedef struct
{
    UInt16  bitmask;            /*^ BITMASK ^*/
    UInt32  init_max_attempts;  /*^ M,0,N,0,0 ^*/
    UInt32  rto_initial;        /*^ M,0,N,0,0 ^*/
    UInt32  rto_max;            /*^ M,0,N,0,0 ^*/
    UInt32  rto_min;            /*^ M,0,N,0,0 ^*/
    UInt16  assoc_max_retrans;  /*^ M,0,N,0,0 ^*/
    UInt32  valid_cookie_life;  /*^ M,0,N,0,0 ^*/
    UInt16  path_max_retrans;   /*^ M,0,N,0,0 ^*/
    /* dscp_marking_start */
    UInt8   e2cu_dscp_value;    /*^ O,E2CU_OAM_DSCP_VALUE_PRESENT, H, 0, 63 ^*/
    /* dscp_marking_stop */
}e2cu_sctp_conf_info_t;

typedef struct
{
    UInt32 tv_sec;  /*^ M,0,N,0,0 ^*/
    UInt32 tv_usec; /*^ M,0,N,0,0 ^*/
}e2cu_timeval_t;

#endif
#endif

