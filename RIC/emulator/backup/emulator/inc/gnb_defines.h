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

#ifndef _GNB_DEFINES_H_
#define _GNB_DEFINES_H_
#include "gnb_composer_parser.h"

#define GNB_VERSION_ID          0x01
#define GNB_MAX_THREADS 12
#define DEFAULT_GNB_LOG_FILE    "gnb_main.log"

#define PNULL               NULL
#define GNB_NULL            0
#define MODULO_TWO(x)            ((x) & 1)
#define MODULO_FOUR(x)           ((x) & 3)
#define MODULO_EIGHT(x)          ((x) & 7)
#define MODULO_TEN(x)            ((x) % 10)
#define MODULO_SIXTEEN(x)        ((x) & 15)
#define MODULO_SIXTY_FOUR(x)     ((x) & 63)
#define MODULO_TWOFIFTYSIX(x)    ((x) & 255)
#define MODULO_ONEZEROTWOFOUR(x) ((x) & 1023)
#define MODULO_NUM(x, num)       ((x) % (num))

#define DIVIDE_BY_TWO(x) ((x) >> 1)
#define DIVIDE_BY_FOUR(x) ((x) >> 2)
#define DIVIDE_BY_EIGHT(x) ((x) >> 3)
#define DIVIDE_BY_SIXTEEN(x) ((x) >> 4)
#define DIVIDE_BY_THIRTY_TWO(x) ((x) >> 5)
#define DIVIDE_BY_SIXTY_FOUR(x) ((x) >> 6)
#define DIVIDE_BY_256(x) ((x) >> 8)
#define DIVIDE_BY_1024(x) ((x) >> 10)
#define DIVIDE_BY_4096(x) ((x) >> 12)

#define MULTIPLY_BY_TWO(x) ((x) << 1)
#define MULTIPLY_BY_FOUR(x) ((x) << 2)
#define MULTIPLY_BY_EIGHT(x) ((x) << 3)
#define MULTIPLY_BY_SIXTEEN(x) ((x) << 4)
#define MULTIPLY_BY_SIXTY_FOUR(x) ((x) << 6)
#define MULTIPLY_BY_ONEZEROTWOFOUR(x) ((x) << 10)
#define MODULO(x,d) ((x)&(d-1))

#define CONVERT_MEGA_BYTE_TO_BYTE(x)  (x * 1024 * 1024)

/* Find the minimum of two numbers */
#define MIN_TWO_NUM(A,B) ((A) < (B) ? (A) : (B) )
/* Find the maximum of two numbers */
#define MAX_TWO_NUM(A,B) ((A) > (B) ? (A) : (B) )

#if defined(__x86_64__) || defined(__aarch64__)
#define ADDR UInt64
#else
#define ADDR UInt32
#endif

#define STATIC static
#define    F1U_RELAY_MODE  0
#define    X2U_RELAY_MODE  1
#define    S1U_RELAY_MODE  2

/* This is for debugging only as the 1024 SFN wrap very early and 
 * makes it difficult to map the logs*/
#define MAX_SFN_24BITS (0x1000000)

/*******************************************************************************
 * MODULE IDs DEFINITION
 ******************************************************************************/
/* CU Module ID */
#define OAM_MODULE_ID     01  /* OAM Module ID     */
#define RRM_MODULE_ID     02  /* RRM Module ID     */
#define L3_MODULE_ID      03  /* L3 Module ID      */
#define SON_MODULE_ID     04  /* SON Module ID     */
#define PDCP_MODULE_ID    05  /* PDCP Module ID    */
#define NGU_MODULE_ID     06  /* NGU/X2U Module ID */
#define F1U_MODULE_ID     07  /* CU F1U Module ID  */
#define X2U_MODULE_ID     8  /*  CU X2U Module ID  */

#define GPS_MODULE_ID     50  /* CU GPS Module ID  */
#define KEC_MODULE_ID     51  /* CU KEC Module ID  */
#if defined (E2CU_MU_MIMO_CHANGES) || defined (E2_FRAMEWORK)
/*GQA-6413 beg*/
#define INTERNAL_RRM_MODULE_ID 9
/*GQA-6413 end*/
#define E2CU_MODULE_ID    (0x10 + 70)
#endif/*end of E2_FRAMEWORK*/

/* Fix for Arm O1 WERROR start*/
#ifdef O1_HDL_FRAMEWORK
#define O1_MODULE_ID      204
#endif
/* Fix for Arm O1 WERROR ends*/

#ifdef CBSD_SUPPORT
#define CBSD_MODULE_ID 204
#endif

/* DU Module ID */
#ifdef MAC_TEST_MODE
#define MAX_DU_MODULE     8
#else
#ifdef E2DU_FRAMEWORK
#define MAX_DU_MODULE     8
#else
#define MAX_DU_MODULE     6
#endif
#endif

#define DU_MODULE_ID_BASE 20
#define DUOAM_MODULE_ID   20  /* DU OAM Module ID     */
#define DUMGR_MODULE_ID   21  /* DU Manager Module ID */
#define MAC_MODULE_ID     22  /* MAC Module ID        */
#define RLC_MODULE_ID     23  /* RLC Module ID        */
#define DUF1U_MODULE_ID   24  /* DU F1U Module ID     */
#define DUPHY_MODULE_ID   25  /* DU PHY MODULE ID */
#define DUCLI_MODULE_ID   26  /* DU CLI MODULE ID */

#ifdef E2DU_FRAMEWORK
#define E2DU_MODULE_ID    27  /* E2DU MODULE ID */
#define RIC_E2DU_MODULE_ID     28  /* RIC MODULE ID */
#endif

#define GNB_MAX_EXTERNAL_MODULE_ID (DUCLI_MODULE_ID + 1)

#define CSM_MODULE_ID     100  /* CSM MODULE ID */ /* CSM_MODULE_CHANGES */
#ifdef KPI_STATS_SA
#define CONTROLLER_MODULE_ID        200
#define DUGPS_MODULE_ID               201
#endif

#ifdef O1_HDL_FRAMEWORK
#define O1DU_MODULE_ID      203
#endif

#ifdef TR069_DU_FRAMEWORK
#define TR069_DU_MODULE_ID     252
#endif

#define CG_NR_0		     0
#define CG_NR_1		     1
#define CG_NR_2		     2
#define CG_NR_3		     3
#define CG_NR_4		     4
#define CG_NR_5		     5
#define CG_NR_6		     6
#define CG_NR_7		     7
#define CG_NR_8		     8
#define CG_NR_9		     9
#define CG_NR_10	     10
#define CG_NR_11	     11
#define CG_NR_12	     12
#define CG_NR_13	     13
#define CG_NR_14	     14
#define CG_NR_15	     15
#define CG_NR_16	     16
#define CG_NR_17	     17
#define CG_NR_18	     18
#define CG_NR_19	     19
#define CG_NR_20	     20
#define CG_NR_21	     21
#define CG_NR_22	     22
#define CG_NR_23	     23
#define CG_NR_24	     24
#define CG_NR_25	     25
#define CG_NR_26	     26
#define CG_NR_27	     27
#define CG_NR_28	     28
#define CG_NR_29	     29
#define CG_NR_30	     30
#define CG_NR_31	     31
#define CG_NR_32	     32
#define CG_NR_64	     64
#define CG_NR_128	     128
#define CG_NR_256	     256
#define CG_NR_512	     512
#define CG_NR_1024	     1024
#define CG_NR_2048	     2048
#define CG_NR_4096	     4096
#define CG_NR_8192	     8192
#define CG_NR_16384	     16384
#define CG_NR_32768	     32768
#define CG_NR_65536	     65536
#define CG_NR_131072	     131072
#define CG_NR_262144	     262144
#define CG_NR_524288	     524288
#define CG_NR_1048576	     1048576
#define CG_NR_2097152	     2097152
#define CG_NR_4194304	     4194304
#define CG_NR_8388608	     8388608
#define CG_NR_16777216	     16777216
#define CG_NR_33554432	     33554432
#define CG_NR_67108864	     67108864
#define CG_NR_134217728	     134217728
#define CG_NR_268435456	     268435456
#define CG_NR_536870912	     536870912
#define CG_NR_1073741824     1073741824
#define CG_NR_2147483648LL   2147483648LL

#define CG_NR_34                         34
#define CG_NR_36                         36
#define CG_NR_38                         38
#define CG_NR_40                         40
#define CG_NR_43                         43
#define CG_NR_46                         46
#define CG_NR_49                         49
#define CG_NR_52                         52
#define CG_NR_55                         55
#define CG_NR_59                         59
#define CG_NR_62                         62
#define CG_NR_66                         66
#define CG_NR_71                         71
#define CG_NR_75                         75
#define CG_NR_80                         80
#define CG_NR_85                         85
#define CG_NR_91                         91
#define CG_NR_97                         97
#define CG_NR_103                        103
#define CG_NR_110                        110
#define CG_NR_117                        117
#define CG_NR_124                        124
#define CG_NR_132                        132
#define CG_NR_141                        141
#define CG_NR_150                        150
#define CG_NR_160                        160
#define CG_NR_170                        170
#define CG_NR_181                        181
#define CG_NR_193                        193
#define CG_NR_205                        205
#define CG_NR_218                        218
#define CG_NR_233                        233
#define CG_NR_248                        248
#define CG_NR_264                        264
#define CG_NR_281                        281
#define CG_NR_299                        299
#define CG_NR_318                        318
#define CG_NR_339                        339
#define CG_NR_361                        361
#define CG_NR_384                        384
#define CG_NR_409                        409
#define CG_NR_436                        436
#define CG_NR_464                        464
#define CG_NR_494                        494
#define CG_NR_526                        526
#define CG_NR_560                        560
#define CG_NR_597                        597
#define CG_NR_635                        635
#define CG_NR_677                        677
#define CG_NR_720                        720
#define CG_NR_767                        767
#define CG_NR_817                        817
#define CG_NR_870                        870
#define CG_NR_926                        926
#define CG_NR_987                        987
#define CG_NR_1051                       1051
#define CG_NR_1119                       1119
#define CG_NR_1191                       1191
#define CG_NR_1269                       1269
#define CG_NR_1351                       1351
#define CG_NR_1439                       1439
#define CG_NR_1532                       1532
#define CG_NR_1631                       1631
#define CG_NR_1737                       1737
#define CG_NR_1850                       1850
#define CG_NR_1970                       1970
#define CG_NR_2098                       2098
#define CG_NR_2234                       2234
#define CG_NR_2379                       2379
#define CG_NR_2533                       2533
#define CG_NR_2698                       2698
#define CG_NR_2873                       2873
#define CG_NR_3059                       3059
#define CG_NR_3258                       3258
#define CG_NR_3469                       3469
#define CG_NR_3694                       3694
#define CG_NR_3934                       3934
#define CG_NR_4189                       4189
#define CG_NR_4461                       4461
#define CG_NR_4751                       4751
#define CG_NR_5059                       5059
#define CG_NR_5387                       5387
#define CG_NR_5737                       5737
#define CG_NR_6109                       6109
#define CG_NR_6506                       6506
#define CG_NR_6928                       6928
#define CG_NR_7378                       7378
#define CG_NR_7857                       7857
#define CG_NR_8367                       8367
#define CG_NR_8910                       8910
#define CG_NR_9488                       9488
#define CG_NR_10104                      10104
#define CG_NR_10760                      10760
#define CG_NR_11458                      11458
#define CG_NR_12202                      12202
#define CG_NR_12994                      12994
#define CG_NR_13838                      13838
#define CG_NR_14736                      14736
#define CG_NR_15692                      15692
#define CG_NR_16711                      16711
#define CG_NR_17795                      17795
#define CG_NR_18951                      18951
#define CG_NR_20181                      20181
#define CG_NR_21491                      21491
#define CG_NR_22885                      22885
#define CG_NR_24371                      24371
#define CG_NR_25953                      25953
#define CG_NR_27638                      27638
#define CG_NR_29431                      29431
#define CG_NR_31342                      31342
#define CG_NR_33376                      33376
#define CG_NR_35543                      35543
#define CG_NR_37850                      37850
#define CG_NR_40307                      40307
#define CG_NR_42923                      42923
#define CG_NR_45709                      45709
#define CG_NR_48676                      48676
#define CG_NR_51836                      51836
#define CG_NR_55200                      55200
#define CG_NR_58784                      58784
#define CG_NR_62599                      62599
#define CG_NR_66663                      66663
#define CG_NR_70990                      70990
#define CG_NR_75598                      75598
#define CG_NR_80505                      80505
#define CG_NR_85730                      85730
#define CG_NR_91295                      91295
#define CG_NR_97221                      97221
#define CG_NR_103532                     103532
#define CG_NR_110252                     110252
#define CG_NR_117409                     117409
#define CG_NR_125030                     125030
#define CG_NR_133146                     133146
#define CG_NR_141789                     141789
#define CG_NR_150992                     150992
#define CG_NR_160793                     160793
#define CG_NR_171231                     171231
#define CG_NR_182345                     182345
#define CG_NR_194182                     194182
#define CG_NR_206786                     206786
#define CG_NR_220209                     220209
#define CG_NR_234503                     234503
#define CG_NR_249725                     249725
#define CG_NR_265935                     265935
#define CG_NR_283197                     283197
#define CG_NR_301579                     301579
#define CG_NR_321155                     321155
#define CG_NR_342002                     342002
#define CG_NR_364202                     364202
#define CG_NR_387842                     387842
#define CG_NR_413018                     413018
#define CG_NR_439827                     439827
#define CG_NR_468377                     468377
#define CG_NR_498780                     498780
#define CG_NR_531156                     531156
#define CG_NR_565634                     565634
#define CG_NR_602350                     602350
#define CG_NR_641449                     641449
#define CG_NR_683087                     683087
#define CG_NR_727427                     727427
#define CG_NR_774645                     774645
#define CG_NR_824928                     824928
#define CG_NR_878475                     878475
#define CG_NR_935498                     935498
#define CG_NR_996222                     996222
#define CG_NR_1060888                    1060888
#define CG_NR_1129752                    1129752
#define CG_NR_1203085                    1203085
#define CG_NR_1281179                    1281179
#define CG_NR_1364342                    1364342
#define CG_NR_1452903                    1452903
#define CG_NR_1547213                    1547213
#define CG_NR_1647644                    1647644
#define CG_NR_1754595                    1754595
#define CG_NR_1868488                    1868488
#define CG_NR_1989774                    1989774
#define CG_NR_2118933                    2118933
#define CG_NR_2256475                    2256475
#define CG_NR_2402946                    2402946
#define CG_NR_2558924                    2558924
#define CG_NR_2725027                    2725027
#define CG_NR_2901912                    2901912
#define CG_NR_3090279                    3090279
#define CG_NR_3290873                    3290873
#define CG_NR_3504487                    3504487
#define CG_NR_3731968                    3731968
#define CG_NR_3974215                    3974215
#define CG_NR_4232186                    4232186
#define CG_NR_4506902                    4506902
#define CG_NR_4799451                    4799451
#define CG_NR_5110989                    5110989
#define CG_NR_5442750                    5442750
#define CG_NR_5796046                    5796046
#define CG_NR_6172275                    6172275
#define CG_NR_6572925                    6572925
#define CG_NR_6999582                    6999582
#define CG_NR_7453933                    7453933
#define CG_NR_7937777                    7937777
#define CG_NR_8453028                    8453028
#define CG_NR_9001725                    9001725
#define CG_NR_9586039                    9586039
#define CG_NR_10208280                   10208280
#define CG_NR_10870913                   10870913
#define CG_NR_11576557                   11576557
#define CG_NR_12328006                   12328006
#define CG_NR_13128233                   13128233
#define CG_NR_13980403                   13980403
#define CG_NR_14887889                   14887889
#define CG_NR_15854280                   15854280
#define CG_NR_16883401                   16883401
#define CG_NR_17979324                   17979324
#define CG_NR_19146385                   19146385
#define CG_NR_20389201                   20389201
#define CG_NR_21172690                   21172690
#define CG_NR_23122088                   23122088
#define CG_NR_24622972                   24622972
#define CG_NR_26221280                   26221280
#define CG_NR_27923336                   27923336
#define CG_NR_29735857                   29735857
#define CG_NR_31666069                   31666069
#define CG_NR_33721553                   33721553
#define CG_NR_35910462                   35910462
#define CG_NR_38241455                   38241455
#define CG_NR_40723756                   40723756
#define CG_NR_43367187                   43367187
#define CG_NR_46182206                   46182206
#define CG_NR_49179951                   49179951
#define CG_NR_52372284                   52372284
#define CG_NR_55771835                   55771835
#define CG_NR_59392055                   59392055
#define CG_NR_63247269                   63247269
#define CG_NR_67352729                   67352729
#define CG_NR_71724679                   71724679
#define CG_NR_76380419                   76380419
#define CG_NR_81338368                   81338368


#define NR_ZERO		     0
#define INITIAL_BWP_INDEX 0
#define NR_ONE		     1
#define NR_TWO		     2
#define NR_THREE	     3
#define NR_FOUR		     4
#define NR_FIVE		     5
#define NR_SIX		     6
#define NR_SEVEN	     7
#define NR_EIGHT	     8
#define NR_NINE	 	     9
#define NR_TEN		     10
#define NR_ELEVEN	     11
#define NR_TWELVE	     12
#define NR_THIRTEEN	     13
#define NR_FOURTEEN	     14
#define NR_FIFTEEN	     15
#define NR_SIXTEEN	     16
#define NR_SEVENTEEN	     17
#define NR_TWENTY	     20
#define NR_TWENTY_FOUR   24
#define NR_TWENTY_FIVE   25
#define NR_THIRTY	     30
#define NR_THIRTY_ONE	 31
#define NR_THIRTY_TWO	 32
#define NR_FOURTY	     40
#define NR_FIFTY_ONE     51
#define NR_SIXTY	     60
#define NR_SIXTY_FOUR    64
#define NR_HUNDRED         100
#define NR_ONE_HUNDRED_SIX 106
#define NR_ONE_TWENTY      120
#define NR_TWO_FOURTY      240
#define NR_TWO_FIFTY_SIX   256
#define NR_TWO_FIFTY_SEVEN   257
#define NR_TWO_FIFTY_NINE  259
#define NR_TWO_SIXTY_ONE   261
#define NR_TWO_SIXTY_TWO   262

#define NR_THOUSAND     1000
#define NR_ONE_ZERO_TWO_FOUR  1024
#ifdef FAPI_10_01
#define NR_SIXTY_FOUR    64
#endif

#define NR_FAILURE           0
#define NR_SUCCESS           1
#define NR_PARTIAL_FAILURE   2
#define NR_PARTIAL_SUCCESS   2
#define CRC_DTX              NR_TWO

#define MAX_VALUE            0.25
#define NR_FALSE             0
#define NR_TRUE              1 

/* Header length of API header used between modules */
#define GNB_INTERFACE_API_HEADER_SIZE           16

/* Maximum radio bearers in one UE Context */
#define MIN_SRB             (01) /* SRB1,2,3...not includes SRB0 */
#define MAX_SRB             (03) /* SRB1,2,3...not includes SRB0 */
#define MIN_DRB             (1) /* DRB 1 - 32 */
#define MAX_DRB             (32) /* DRB 1 - 32 */
#define MAX_RB              (MAX_SRB + MAX_DRB) /* Max RB excluding SRB0 */
#define INVALID_DRB_ID      (255)

#define MAX_QFI             3
#define MAX_PDU_SESSION     256
#define MAX_QFI_VAL         64

#define MAX_SUPPORTED_DRB    16
#define DEFAULT_DRB_PER_UE   4

/* Maximum logical channels in one UE Context */
#define MIN_LC              (01)
#define MAX_LC              (32)

#define MAX_AM_LC           (31)
#define MAX_UM_LC           (28)
#define MAX_SUPPORTED_LC    (16)

/* GQA-3154 Fix Start */
#ifdef SUPPORT_2048UE_PER_DU
#define MAX_DU_UE_SUPPORTED    2048
#define MAX_NUM_UE_PER_CELL    512
#else
#define MAX_DU_UE_SUPPORTED    1024
#define MAX_NUM_UE_PER_CELL    1024
#endif
/* GQA-3154 Fix Stop */

#define MAX_NUM_CELL_PER_DU                 8

#define MAX_NUM_SCELL_PER_DU                (MAX_NUM_CELL_PER_DU - 1)
#define INVALID_SERV_CELL_INDEX             255
#define MAX_NUM_SERVING_CELL                32

/* csi_rs_narrow_beam_start */
#define MAX_NZP_RESOURCES_PER_SET_FOR_LA    4
#define MAX_CSI_IM_RESOURCES_PER_SET_FOR_LA 4
#define MAX_NARROW_BEAM_COUNT               31
#define MAX_WIDE_BEAM_COUNT                 32
#define MAX_NB_NEIGHBOUR_BEAM_COUNT         31
#define MAX_BEAM_COUNT_CSI_RS_ENABLED       32
/* csi_rs_narrow_beam_start */
/* csi_rs_l3_meas_changes_start */
#define CSIRS_MAX_RES_MOB                    1
/* csi_rs_l3_meas_changes_stop */

#ifdef SUPPORT_2048UE_PER_DU
#define MAX_UE_SUPPORTED    4096
#else
#define MAX_UE_SUPPORTED    3000
#endif

/*MAX UE in a batch for PURGE*/
#ifndef SMALLCELL_MEM_OPTIMIZATION
#define MAX_NUM_PURGE_UE_IN_BATCH 12000
#else
#define MAX_NUM_PURGE_UE_IN_BATCH 2
#endif
#ifndef SMALLCELL_MEM_OPTIMIZATION
#define MAX_NUM_DU_PURGE_UE_IN_BATCH 128
#else
#define MAX_NUM_DU_PURGE_UE_IN_BATCH 2
#endif

#define MAX_NUM_TRANSACTION_ID       65536
#define MAX_EARFCN                   65535
#define MAX_QCI                      256
#define MAX_SF_OUTOFSYNC             255

#define MAX_UINT32_VALUE  ((UInt32)4294967295U)
#define MAX_UINT64_VALUE  ((UInt64)0xFFFFFFFFFFFFFFFFU)

/* macros to define the MTU buffers */
#define MIN_MTU_SIZE_BUFFER       1500
#define MAX_MTU_SIZE_BUFFER       9000

/* The number of buffers are derived from the calculation based 
 * on 5 Gbps DL and 500 Mbps UL throughput requirements
 * Buffering of Discard Timer - 1500 ms
 * PDCP Reordering Timer - 3000 ms 
 *
 * DL Packets = 
 * ( 5 Gbps throughput / 1500 bytes packet ) * 1000 Discard Timer
 *
 * UL Packets = 
 * ( 500 Mbps throughput / 1500 bytes packet ) * 1000 Reordering Timer 
 *
 * NUM_MTU_BUFFERS = DL Packets + UL Packets */
#ifdef X86_TESTING
#ifdef MEM_CHECK_DOUBLE_FREE
#define NUM_MTU_BUFFERS           50
#define NUM_MTU_BUFFERS_1500      50
#else
#define NUM_MTU_BUFFERS           100000
#define NUM_MTU_BUFFERS_1500      100000
#endif
#else
#define NUM_MTU_BUFFERS           100000
#define NUM_MTU_BUFFERS_1500      460000
#endif

#define MSG_POOL_HIGH_WATERMARK         70
#define MSG_POOL_LOW_WATERMARK          60
#define MEM_POOL_HIGH_WATERMARK         70
#define MEM_POOL_LOW_WATERMARK          60

#define SOCKET_ERROR (-1)

/* UDP buffer size of 65,507 bytes (65,535 − 8 bytes UDP header − 
 * 20 bytes IP header, assuming no IP extension headers) */
#define MAX_SOCKET_BUFFER_SIZE    65507 

#ifndef NR_UESIM_TESTING
/* For DL throughput of 2 Gbps and 500 ms holding capacity*/
#define MAX_DU_DL_THROUGHPUT_BYTES  125000000
#define MAX_DU_UL_THROUGHPUT_BYTES  6250000 
#else
#define MAX_DU_DL_THROUGHPUT_BYTES  6250000
#define MAX_DU_UL_THROUGHPUT_BYTES  125000000 
#endif


#define MAX_CONTROL_BUFFERS      10

#define GNB_INVALID_LOG          0x00    /*Bitmask: 0000 0000*/
#define GNB_FATAL                0x01    /*Bitmask: 0000 0001*/
#define GNB_ERROR                0x02    /*Bitmask: 0000 0010*/
#define GNB_WARNING              0x04    /*Bitmask: 0000 0100*/
#define GNB_INFO                 0x08    /*Bitmask: 0000 1000*/
#define GNB_BRIEF                0x10    /*Bitmask: 0001 0000*/
#define GNB_DETAILED             0x20    /*Bitmask: 0010 0000*/
#define GNB_DETAILEDALL          0x40    /*Bitmask: 0100 0000*/
/* Currently mapped to GNB_INFO, In future, new log level will be defined */
#define GNB_HEXDUMP              0x08    /*Bitmask: 0000 1000*/ 
#define ALL_LOG_LEVEL            ( GNB_FATAL | GNB_ERROR | GNB_WARNING | GNB_INFO | GNB_BRIEF | GNB_DETAILED | GNB_DETAILEDALL )

#define GNB_ASN                 GNB_BRIEF
#define GNB_PROTOCOL_EVENT      GNB_DETAILED

#define IPV4_FLAG 1
#define IPV6_FLAG 2
#define IPV4_ADDR_SIZE 4
#define IPV6_ADDRESS_LENGTH       40
#define IPV4_ADDRESS_LENGTH       16 

#define API_HEADER_TRANSID_OFFSET   0
#define API_HEADER_SOURCEID_OFFSET  2
#define API_HEADER_DESTID_OFFSET    4
#define API_HEADER_MSGID_OFFSET     6
#define API_HEADER_MSGLEN_OFFSET    8
#define API_HEADER_CELL_ID_NIL      0

#define API_HEADER_CELL_INDEX_OFFSET 10


#define API_RRC_HEADER_RESERVE_1BYTE_OFFSET   11
#define API_RRC_HEADER_RESERVE_4BYTE_OFFSET   12


#define API_HEADER_PADDING_OFFSET   10
#define API_RRC_HEADER_CELL_INDEX_OFFSET   10
#define API_RRM_HEADER_CELL_INDEX_OFFSET   10
#define API_OAM_HEADER_CELL_INDEX_OFFSET   10

#define API_HEADER_API_ID_OFFSET    6

#define CELL_INDEX_OFFSET_INR(msg_p)   msg_p += 1

#define INVALID_CELL_INDEX           65535

#if   !(defined AMF_SIM_TESTING_ENABLE)
#define MAX_NUM_CELL                 32
#endif

#define API_HEADER_DO_NOT_CARE_CELL_INDEX  INVALID_CELL_INDEX

#define NR_GCC_UNUSED_PARAM(param) (void)param;

#define NR_MAX_PRB       275
#define MAX_SSB_POWER    50
#define MIN_SSB_POWER    -60

#define CONVERT_MBPS_TO_BPS    DIVIDE_BY_EIGHT( 1000*1000 )
#define BYTES_PER_SEC_TO_KILO_BITS_PER_SEC  125

#define NR_GET_U16BIT(p_buff) ((UInt16)(*(p_buff) << 8) | (UInt16)(*(p_buff + 1)))

/* to read a 24 bit value starting at the location p_buff */
#define NR_GET_U24BIT(p_buff) ((UInt32)(*(p_buff) << 16) | (UInt32)(*(p_buff + 1) << 8) | (UInt32)(*(p_buff + 2)))

/* to read a 32 bit value starting at the location p_buff */
#define NR_GET_U32BIT(p_buff) ((UInt32)(*(p_buff) << 24) | (UInt32)(*(p_buff + 1) << 16) | (UInt32)(*(p_buff + 2) << 8) | (UInt32)(*(p_buff + 3)))

/* to read a 40 bit value starting at the location p_buff */
#define NR_GET_U40BIT(p_buff) (((UInt64)(*(p_buff)) << 32) | (UInt64)(*(p_buff + 1) << 24) | (UInt64)(*(p_buff + 2) << 16) | (UInt64)(*(p_buff + 3) << 8) | (UInt64)(*(p_buff + 4)))

/* to read a 64 bit value starting at the location p_buff */
#define NR_GET_U64BIT(p_buff) ((UInt64)(*(p_buff) << 56) | (UInt64)(*(p_buff + 1) << 48) | (UInt64)(*(p_buff + 2) << 40) | (UInt64)(*(p_buff + 3) << 32) | (UInt64)(*(p_buff + 4) << 24) | (UInt64)(*(p_buff + 5) << 16) | (UInt64)(*(p_buff + 6) << 8) | (UInt64)(*(p_buff + 7)))

/* macros to set U16bit, U24bit, and U32bit values onto buffer */
/* p_buff must be typecast to a (U8bit *) before using these macros */

/* to write a 16 bit value starting from the location p_buff */
#define NR_SET_U16BIT(p_buff, val) *(p_buff) = (UInt8)((val) >> 8); *(p_buff + 1) = (UInt8)(val);

/* to write a 24 bit value starting from the location p_buff */
#define NR_SET_U24BIT(p_buff, val)  *(p_buff) = (UInt8)((val) >> 16); *(p_buff + 1) = (UInt8)((val) >> 8); *(p_buff + 2) = (UInt8)(val);

/* to write a 32 bit value starting from the location p_buff */
#define NR_SET_U32BIT(p_buff, val)   *(p_buff) = (UInt8)((val) >> 24); *(p_buff + 1) = (UInt8)((val) >> 16); *(p_buff + 2) = (UInt8)((val) >> 8);  *(p_buff + 3) = (UInt8)(val);

/* to write a 64 bit value starting from the location p_buff */
#define NR_SET_U64BIT(p_buff, val) *(p_buff) = (UInt8)((val) >> 56); *(p_buff + 1) = (UInt8)((val) >> 48); *(p_buff + 2) = (UInt8)((val) >> 40); *(p_buff + 3) = (UInt8)((val) >> 32); *(p_buff + 4) = (UInt8)((val) >> 24); *(p_buff + 5) = (UInt8)((val) >> 16); *(p_buff + 6) = (UInt8)((val) >> 8); *(p_buff + 7) = (UInt8)(val);

/*******************************************************************************
 * Common Enums
 ******************************************************************************/
typedef enum _gnb_debug_type_et
{
    /* Mem Pool Statistics */
    GET_DEBUG_INFO_MEM_STATS,

    /* Message Pool Statistics */
    GET_DEBUG_INFO_MSG_STATS

}gnb_debug_type_et;

/* Enum defining DC bearer type information */
typedef enum dc_bearer_e
{
    /* SCG_BEARER: when PDCP and RLC/MAC is present in Secondary Node, 
     * SgNB only, SN TERMINATED bearer. SCG bearer shall be used as default */
    SCG_BEARER          = 0,
    /* MCG_SPLIT_BEARER: when PDCP is present in Master Node only, 
     * RLC/MAC is present in Secondary Node, may present in Master Node
     * MN TERMINATED bearer */
    MCG_SPLIT_BEARER    = 1,
    /* SCG_SPLIT_BEARER: when PDCP is present in Secondary Node, SgNB only, 
     * RLC/MAC is present in both Secondary Node and Master Node.
     * SN TERMINATED bearer */
    SCG_SPLIT_BEARER    = 2,
    /* MCG_BEARER: when PDCP is present in Secondary Node and 
     * RLC/MAC is present in Master Node only.
     * SN TERMINATED bearer */
    MCG_BEARER          = 3,
    
    MAX_DC_BEARER       = 4,
    INVALID_DC_BEARER   = 255
}dc_bearer;
#endif   /* _GNB_DEFINES_H_ */
