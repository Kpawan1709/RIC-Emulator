/** sctp_server **/

#define E2_ASN_OK 0
#define RIC_PORT 32222

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




//  *****************  e2 setup resopnse ********************** //

 e2_return_et encode_ric_subscription_response
(
    UInt8   **pp_asn_msg,
    UInt16  *p_asn_msg_len
)
{
    e2ap_E2AP_PDU                      e2ap_pdu;
    OSCTXT                             asn1_ctx;
    e2ap_RICsubscriptionResponse       *p_asn_ric_subscription_response = NULL;
    e2_return_et                      response = E2_SUCCESS;

    struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
    UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
    UInt8   *p_event_msg=malloc(E2CU_ASN1_BUFFER_LENGTH);
    UInt8   *p_event_msg1=malloc(E2CU_ASN1_BUFFER_LENGTH);
    UInt16  *p_event_msg_len=malloc(sizeof(UInt16));
    UInt16  *p_event_msg_len1=malloc(sizeof(UInt16));
    pvalue->ricRequestorID=1;
    pvalue->ricInstanceID=55068;

    printf (" p_asn_msg : %p",p_asn_msg);
   if (NULL == p_asn_msg)
   {
	   //GNB_TRACE(GNB_ERROR, "Memory Allocation for p_asn_msg Failed !!");
	   printf("\n\n\nFailed !!\n\n");
	   return E2_FAILURE;
   }
   memset(p_asn_msg,0,sizeof(UInt8));


   //GNB_TRACE(GNB_INFO, "encode_e2_subscription_req");
   printf( "\n\n\nencode_e2_subscription_req\n\n");
   *pp_asn_msg =  p_asn_msg;


   /* Init ASN.1 context */
   if(E2_ASN_OK != rtInitContext(&asn1_ctx))
   {
	   //   GNB_TRACE(GNB_ERROR, "ASN Context Initialization Failed");
	   printf("\n\n\nASN Context Initialization Failed\n\n");
	   response = E2_FAILURE;
	   return response;
   }
   do
   {
	   memset(&e2ap_pdu, 0, sizeof(e2ap_pdu));

	   e2ap_pdu.t = T_e2ap_E2AP_PDU_successfulOutcome;
	   e2ap_pdu.u.successfulOutcome = rtxMemAllocTypeZ(&asn1_ctx,e2ap_SuccessfulOutcome);

	   if(NULL ==  e2ap_pdu.u.successfulOutcome)
	   {
		   //   GNB_TRACE(GNB_ERROR, "Memory allocation falied for successfulOutcome");
		   printf("\n\n\nMemory allocation falied for successfulOutcome\n\n\n");
		   response = E2_FAILURE;
		   break;
	   }
	   p_asn_ric_subscription_response =
		   rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICsubscriptionResponse);

	   if(NULL == p_asn_ric_subscription_response)
	   {
		   response = E2_FAILURE;
		   break;
	   }
     asn1SetTC_e2ap_SuccessfulOutcome_ricSubscription(
			   &asn1_ctx,
			   e2ap_pdu.u.successfulOutcome,
			   p_asn_ric_subscription_response);


      if (RT_OK != asn1Append_e2ap_RICsubscriptionResponse_protocolIEs_1(&asn1_ctx,&p_asn_ric_subscription_response->protocolIEs,pvalue))
	   {
		   //        GNB_TRACE(GNB_ERROR, "Failed to Add IE1 !!");
		   printf("\n\nFailed to Add IE1 !!\n\n"); 
		   response = E2_FAILURE;
		   break;
	   }
	   //GNB_TRACE(GNB_INFO, " IE1 encoded");
	   printf("\n\n\n IE1 encoded\n\n\n"); 
	   e2ap_RANfunctionID *p_value_ie2 =NULL;
	   p_value_ie2 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RANfunctionID);

	   if(NULL == p_value_ie2)
	   {
		   // GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
		   printf("\n\n\nMemory allocation failed !!\n\n\n"); 
		   response = E2_FAILURE;
		   break;
	   }
	   *p_value_ie2=2; 
	   

	   if (RT_OK != asn1Append_e2ap_RICsubscriptionResponse_protocolIEs_2(&asn1_ctx,&p_asn_ric_subscription_response->protocolIEs,*p_value_ie2))
	   {
		   //   GNB_TRACE(GNB_ERROR, "Failed to Add IE2 !!");
		   response = E2_FAILURE;
		   break;
	   }
	   //GNB_TRACE(GNB_INFO, " IE2 encoded");
      printf("\n\n\n IE2 encoded\n\n\n");

      e2ap_RICaction_Admitted_List *p_value =NULL;
	   p_value = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICaction_Admitted_List);

	   if(NULL == p_value)
	   {
		   // GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
		   printf("\n\n\nMemory allocation failed !!\n\n\n"); 
		   response = E2_FAILURE;
		   break;
	   }
     // e2ap_RICactions_ToBeSetup_List_element           *listE=NULL;

     // OSRTDListNode *Node1 = NULL;
      //E2SM_RC_ActionDefinition *action = NULL;
      //e2ap_RICaction_Admitted_List_element *amittedlist = NULL;

      OSRTDListNode  *Node1 = NULL;
      e2ap_RICaction_Admitted_List_element *list = NULL;



      // Example assuming it should be ricAction_Admitted_List:
     rtxDListInit(p_value);
     asn1Init_e2ap_RICaction_Admitted_List(p_value);

      int a =0 ;
      for (a = 0 ; a < 1 ; a++ )
      {
         rtxDListAllocNodeAndData(&asn1_ctx,
               e2ap_RICaction_Admitted_List_element,
               &Node1, &list);
         //memset(list ,0,sizeof(e2ap_RICaction_Admitted_List_element));

         list->id=14;
         list->criticality=0;
         list->value.t=T7e2ap___e2ap_RICaction_Admitted_ItemIEs_1;
         list->value.u._e2ap_RICaction_Admitted_ItemIEs_1=rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICaction_Admitted_Item);  
         list->value.u._e2ap_RICaction_Admitted_ItemIEs_1->ricActionID = 1;
        
         rtxDListAppendNode (
            p_value,
            Node1);
      }  

      if (RT_OK != asn1Append_e2ap_RICsubscriptionResponse_protocolIEs_3(&asn1_ctx,&p_asn_ric_subscription_response->protocolIEs,p_value))
	   {
		   //   GNB_TRACE(GNB_ERROR, "Failed to Add IE3 !!");
		   response = E2_FAILURE;
		   break;
	   }
      printf("\n\n\n IE3 encoded\n\n\n");

   
   } while (0);

   asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);

   return response;
}


int main()
{
    int Sockfd, connSock1,connSock, ret, in,in1, flags, datalen;
    struct sockaddr_in servaddr;
    struct sctp_initmsg initmsg;
    struct sctp_event_subscribe events;
    struct sctp_sndrcvinfo sndrcvinfo;
    //GUAMI  *myguami=NULL;
    UInt8   octet_bitstring[4196];  // Use uint8_t for the octet bitstring
    char* ip = "192.168.166.22";
                                   //myguami=malloc(sizeof(GUAMI));
		e2ap_InitiatingMessage            *Initiating=NULL;

		E2SM_RC_CallProcessID             *ric_call=NULL;
UInt8                                          *pp_asn_msg=NULL,*pp_asn_msg1=NULL,pp_asn_msg2=NULL; 
 UInt16                                         p_asn_msg_len,p_asn_msg_len1,p_asn_msg_len2;

E2SM_RC_IndicationHeader                           *header=NULL;

 e2_return_et                            ret1=0;

    printf("============Starting RIC Emulator============\n\n\n");
   //ret=encode_ric_subscription_request(&pp_asn_msg1,&p_asn_msg_len1,myguami);
   ret=encode_ric_subscription_response(&pp_asn_msg1,&p_asn_msg_len1);
	//ret=encode_ric_subscription_request(&pp_asn_msg1,&p_asn_msg_len1,myguami); 
//	ret=encode_e2_setup_failure(&pp_asn_msg,&p_asn_msg_len);

/*	sleep(5);
	ret=encode_ric_subscription_request(&pp_asn_msg1,&p_asn_msg_len1,myguami); 
	sleep(5);
	ret=encode_ric_subscription_request(&pp_asn_msg1,&p_asn_msg_len1,myguami); 
	sleep(5);
        ret=encode_ric_control_request(&pp_asn_msg1,&p_asn_msg_len1,*myguami);*/
//	ret=encode_ric_control_request(&pp_asn_msg,&p_asn_msg_len);
 
	//ret=encode_ric_subscription_request(&pp_asn_msg1,&p_asn_msg_len1);  
  /** Create a socket **/
    Sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_SCTP);
    if (Sockfd == -1)
    {						// change this code completely 1) write sctp client code 2)add subscription response code and call it from main

        printf("Failed to create socket\n");
        perror("socket()");
        exit(1);
    }

    /** Name the socket **/
    bzero((void*)&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("10.1.103.57");
    servaddr.sin_port = htons(RIC_PORT);

    /** bind the socket **/
    ret = bind(Sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    if (ret == -1)
    {
        printf("Bind failed\n");
        perror("bind()");
        close(Sockfd);
        exit(1);
    }

    /* Specify that a maximum of 5 streams will be available per socket */
    memset(&initmsg, 0, sizeof(initmsg));
    initmsg.sinit_num_ostreams = 5;
    initmsg.sinit_max_instreams = 5;
    initmsg.sinit_max_attempts = 4;
    ret = setsockopt(Sockfd, IPPROTO_SCTP, SCTP_INITMSG, &initmsg, sizeof(initmsg));
    if (ret == -1)
    {
        printf("setsockopt() failed\n");
        perror("setsockopt()");
        close(Sockfd);
        exit(1);
    }

    /** listen to socket **/
    ret = listen(Sockfd, 5);
    if (ret == -1)
    {
        printf("listen() failed\n");
        perror("listen()");
        close(Sockfd);
        exit(1);
    }

    printf("Awaiting a new connection\n");
    connSock1 = accept(Sockfd, (struct sockaddr*)NULL, (int*)NULL);
    if (connSock1 == -1)
    {
        printf("accept() failed\n");
        perror("accept()");
        close(connSock);
        exit(EXIT_FAILURE);
    }
    else
    printf("New client1 connected....\n");
   /* connSock = accept(Sockfd, (struct sockaddr*)NULL, (int*)NULL);
    if (connSock == -1)
    {
        printf("accept() failed\n");
        perror("accept()");
        close(connSock);
        exit(EXIT_FAILURE);
    }
    else
    printf("New client2 connected....\n");*/
int i=0;
        int len;
    while (1)
    {
        // Clear the octet bitstring
        memset(octet_bitstring, 0, sizeof(UInt8));
        in = sctp_recvmsg(connSock1,(void *)octet_bitstring,8196,
                          NULL, 0, 0, 0);
        if (in == -1)
        {
            printf("Error in sctp_recvmsg\n");
            perror("sctp_recvmsg()");
	    sleep(1);
            continue;
        }
        else
        {
            printf("Length of Data received: %d\n", in);
            printf("Data : ");  // Modify how you print the octet bitstring
            for ( i = 0; i < in; i++)
            {
                printf("%02X ", octet_bitstring[i]);
            }
            printf("\n");
	    break;
        }
    }
   e2ap_E2AP_PDU                      e2ap_pdu;
   OSCTXT                             asn1_ctx;
   
    if(E2_ASN_OK != rtInitContext(&asn1_ctx))
    {
    //   GNB_TRACE(GNB_ERROR, "ASN Context Initialization Failed");
      printf("\n\n\nASN Context Initialization Failed\n\n");
    }
     if (E2_ASN_OK !=
            pu_setBuffer(&asn1_ctx, (OSUINT8 *)octet_bitstring, in, E2_TRUE))
        {
            //GNB_TRACE(GNB_ERROR, "Failed pu_setBuffer for RIC SUbscription Response");
            printf("==========Failed pu_setBuffer for RIC SUbscription Response=========\n\n\n");
        }
        E2_MEMSET(&e2ap_pdu, E2_ZERO, sizeof(e2ap_pdu));

    asn1PD_e2ap_E2AP_PDU(&asn1_ctx,&e2ap_pdu);
    asn1Print_e2ap_E2AP_PDU("e2ap_pdu",&e2ap_pdu);
            printf("==========Initiating Encoding of e2 setup response=========\n\n\n");
        /*Encode E2 setup respose */
	pp_asn_msg=NULL;
     while(1)
	{
	if(pp_asn_msg==NULL)
	   {
	ret=encode_e2_setup_response(&pp_asn_msg,&p_asn_msg_len);
           }
	ret = sctp_sendmsg(connSock1,pp_asn_msg,p_asn_msg_len, NULL, 0, 0, 0, 0, 0, 0);
        if (ret == -1)
           {
            printf("Error in sctp_sendmsg\n");
            perror("sctp_sendmsg()");
            sleep(1);
	    continue;
           }
	else
	   {
		printf("E2 Setup Response sent successfully !!\n\n");
		break;
	   }
   }
        printf("==========Initiating Encoding of RIC Subscription Response=========\n\n\n");

	/*                          RIC SUB _ 1                                       */


   while(1)
	{
	if(pp_asn_msg1==NULL)
	{
	ret=encode_ric_subscription_response(&pp_asn_msg1,&p_asn_msg_len1);  
	//	ret=encode_ric_control_request(&pp_asn_msg1,&p_asn_msg_len1,*myguami,ric_call,header);
    }
	ret = sctp_sendmsg(connSock1,pp_asn_msg1,p_asn_msg_len1, NULL, 0, 0, 0, 0, 0, 0);
        if (ret == -1)
        {
            printf("Error in sctp_sendmsg\n");
            perror("sctp_sendmsg()");
            sleep(1);
	    continue;
        }
	else
	{
	printf("RIC Subscription Response for 1st Report service  sent successfully !!\n\n");
	break;	
	}
	
    }
    if(E2_ASN_OK != rtInitContext(&asn1_ctx))
    {
    //   GNB_TRACE(GNB_ERROR, "ASN Context Initialization Failed");
      printf("\n\n\nASN Context Initialization Failed\n\n");
    }
    int c=0; 
    e2ap_RICindication  *N=NULL;   
    while(1)
    {
	printf("\nStart receiving..\n");
       	memset(octet_bitstring, 0, sizeof(UInt8));
       	in = sctp_recvmsg(connSock1,(void *)octet_bitstring,8196,
                         NULL, 0, 0, 0);
	
	printf("\nvalidation for  receiving..\n");
       	if (in <= 0)
       	{
            	printf("Error in sctp_recvmsg\n");
            	perror("sctp_recvmsg()");
	    	sleep(1);	
	    	continue;
        }
	//printf("\n  receiving.. done\n");
       	else
       	{
      		printf("Length of Data received: %d\n", in);
      		printf("Data : ");  // Modify how you print the octet bitstring
       		for ( i = 0; i < in; i++)
       		{
              		printf("%02X ", octet_bitstring[i]);
      		}
      		printf("\n");
                if (E2_ASN_OK !=
                 pu_setBuffer(&asn1_ctx, (OSUINT8 *)octet_bitstring, in, E2_TRUE))
                {
            //GNB_TRACE(GNB_ERROR, "Failed pu_setBuffer for RIC SUbscription Request");
                printf("==========Failed pu_setBuffer for RIC SUbscription Response=========\n\n\n");
                }
    	        E2_MEMSET(&e2ap_pdu, E2_ZERO, sizeof(e2ap_pdu));
//		int      *q=NULL;
//		printf("%d",*q);
                asn1PD_e2ap_E2AP_PDU(&asn1_ctx,&e2ap_pdu);
                asn1Print_e2ap_E2AP_PDU("e2ap_pdu",&e2ap_pdu);
		if(c!=0)
		{
			/*apply decoding logic here */
			printf("\n\n======%p======\n",e2ap_pdu);
		}
		c++;
       	}
	
	printf("\ncompletionreceiving..\n");
	if(c==1)
		break;
    }










  
    rtFreeContext(&asn1_ctx);

  
	while(1);	
    close(connSock);
    return 0;
}
