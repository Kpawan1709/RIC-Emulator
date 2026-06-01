
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
#include "config.h"  // for uint8_t

//#include "head.h"
E2SM_RC_CallProcessID *  decode_ric_callProcess_id(OSCTXT *asn1_ctx,E2SM_RC_CallProcessID *ric_call,e2ap_RICindication *pdu);
e2_return_et encode_ric_subscription_request5
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len,
 GUAMI                                          *myguami
);

e2_return_et encode_ric_subscription_request4
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len,
 GUAMI                                          *myguami
);

 e2_return_et encode_ric_subscription_request3
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len,
 GUAMI                                          *myguami
);

 e2_return_et encode_ric_subscription_request2
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len,
 GUAMI                                          *myguami
);

e2_return_et encode_ric_subscription_request1
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len,
 GUAMI                                          *myguami
);

//*****************************e2ap_RICindication2   **********************************
e2_return_et encode_ric_indication2
(
    UInt8   **pp_asn_msg,
    UInt16  *p_asn_msg_len
);
// *****************  e2smrc RIC CONTROL ACKNOWLEDGE1 ********************** //

e2_return_et encode_ric_control_acknowledge1
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len
);

//  *****************  e2smrc control request1 ********************** //
e2_return_et encode_ric_control_request1
(
    UInt8   **pp_asn_msg,
    UInt16  *p_asn_msg_len
);


//  *****************  e2smrc setup indication ********************** //
e2_return_et encode_ric_indication1
(
    UInt8   **pp_asn_msg,
    UInt16  *p_asn_msg_len
    //GUAMI   *myguami
);


 e2_return_et encode_reset_request
(
 UInt8                                          **pp_asn_msg,
 UInt16                                         *p_asn_msg_len
);


e2_return_et encode_RIC_subscription_Delete_Required
(
 UInt8                                          **pp_asn_msg,
 UInt16                                         *p_asn_msg_len
);

e2_return_et encode_reset_response
(
    UInt8   **pp_asn_msg,
    UInt16  *p_asn_msg_len
);

e2_return_et encode_E2node_Configuration_Update
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len
);

e2_return_et encode_e2ap_E2connection_Update
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len
);

e2_return_et encode_e2ap_ErrorIndication
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len
);

e2_return_et encode_e2ap_RICserviceUpdate
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len
);

 e2_return_et encode_ric_subscription_request
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len,
 GUAMI                                          *myguami
)

{  

   // Load dynamic values:
  // E2Config cfg = {0};
   //load_config("config.txt", &cfg);
   //E2Config     cfg;
   //load_config("config.txt", &cfg, 0);
   E2Config *cfg = load_config(NULL,1);


   e2ap_E2AP_PDU                           e2ap_pdu;
   OSCTXT                                  asn1_ctx;
   e2ap_RICsubscriptionRequest            *p_asn_ric_subscription_request = NULL;
   e2_return_et                            response = E2_SUCCESS;
   

   //struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
   UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg1=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt16  *p_event_msg_len=malloc(sizeof(UInt16));
   UInt16  *p_event_msg_len1=malloc(sizeof(UInt16));
   //pvalue->ricRequestorID=1;
  // pvalue->ricInstanceID=55068;
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

	   e2ap_pdu.t = T_e2ap_E2AP_PDU_initiatingMessage;
	   e2ap_pdu.u.initiatingMessage = rtxMemAllocTypeZ(&asn1_ctx,e2ap_InitiatingMessage);

	   if(NULL ==  e2ap_pdu.u.initiatingMessage)
	   {
		   //   GNB_TRACE(GNB_ERROR, "Memory allocation falied for successfulOutcome");
		   printf("\n\n\nMemory allocation falied for successfulOutcome\n\n\n");
		   response = E2_FAILURE;
		   break;
	   }
	   p_asn_ric_subscription_request =
		   rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICsubscriptionRequest);

	   if(NULL == p_asn_ric_subscription_request)
	   {
		   response = E2_FAILURE;
		   break;
	   }
	   asn1SetTC_e2ap_InitiatingMessage_ricSubscription(
			   &asn1_ctx,
			   e2ap_pdu.u.initiatingMessage,
			   p_asn_ric_subscription_request);

      struct e2ap_RICrequestID *pvalue = rtxMemAllocTypeZ(&asn1_ctx, struct e2ap_RICrequestID);
      
      pvalue->ricRequestorID = cfg->ricRequestorID;
      pvalue->ricInstanceID  = cfg->ricInstanceID;
    


	   if (RT_OK != asn1Append_e2ap_RICsubscriptionRequest_protocolIEs_1(&asn1_ctx,&p_asn_ric_subscription_request->protocolIEs,pvalue))
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
	   *p_value_ie2=cfg->ranFunctionID; 
	   /* p_value_ie2->pLMN_Identity.data[0] = 0;
	      p_value_ie2->pLMN_Identity.data[1] = 1;
	      p_value_ie2->pLMN_Identity.data[2] = 2;
	      p_value_ie2->pLMN_Identity.numocts = 3;
	      p_value_ie2->ric_ID.data[0] =0;
	      p_value_ie2->ric_ID.data[1] =1;
	      p_value_ie2->ric_ID.data[2] =2;
	      p_value_ie2->ric_ID.data[3] =3;
	      p_value_ie2->ric_ID.numbits = 20;*/

	   if (RT_OK != asn1Append_e2ap_RICsubscriptionRequest_protocolIEs_2(&asn1_ctx,&p_asn_ric_subscription_request->protocolIEs,*p_value_ie2))
	   {
		   //   GNB_TRACE(GNB_ERROR, "Failed to Add IE2 !!");
		   response = E2_FAILURE;
		   break;
	   }
	   //GNB_TRACE(GNB_INFO, " IE2 encoded");


	   printf("\n\n\n IE2 encoded\n\n\n"); 
	   /*Encode IE_3 RAN function List*/
	   e2ap_RICsubscriptionDetails *p_value_ie3 = NULL;
	   p_value_ie3 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICsubscriptionDetails);
	   memset(p_value_ie3,0,sizeof(e2ap_RICsubscriptionDetails));//avoid using memset before using error handling
	   if(NULL == p_value_ie3)
	   {
		   //  GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
		   printf("\n\n\nMemory allocation failed !!\n\n\n"); 
		   response = E2_FAILURE;
		   break;
	   }
	 	
	   e2ap_RICactions_ToBeSetup_List_element           *listE=NULL;

	   int a=0;
	   E2SM_RC_EventTrigger 		*p_event=NULL;
	   E2SM_RC_EventTrigger 		*p_event1=NULL;
      
	   // E2SM_KPM_EventTriggerDefinition_Format1  *p_event=NULL;
	   p_event=rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_EventTrigger);                                                   
	   memset(p_event,0,sizeof(E2SM_RC_EventTrigger));
	   p_event1=rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_EventTrigger);                                                   
	   memset(p_event1,0,sizeof(E2SM_RC_EventTrigger));
	   //	p_event->t=1;

	   //p_event->eventDefinition_formats=rtxMemAllocTypeZ(&asn1_ctx,E2SM_KPM_EventTriggerDefinition);                                                   
	   //p_value_ie3->p_RICsubscriptionDetailsp_RICsubscriptionDetailsricEventTriggerDefinition=rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICeventTriggerDefinition);

	   //printf("\n\n=eveneventt=====%p===========\n",&(p_event->eventDefinition_formats.u.eventDefinition_Format1));
	   printf("\n%p\n",&p_event);
	   p_event->ric_eventTrigger_formats.t=T_E2SM_RC_EventTrigger_ric_eventTrigger_formats_eventTrigger_Format1;
	   p_event->ric_eventTrigger_formats.u.eventTrigger_Format1=malloc(sizeof(E2SM_RC_EventTrigger_Format1));
	   /*Identify the structure traversal and operate as per the requirement*/
	   p_event->ric_eventTrigger_formats.u.eventTrigger_Format1->m.globalAssociatedUEInfoPresent=0;

	   E2SM_RC_EventTrigger_Format1_Item          *event_item=NULL;
	  OSRTDListNode        *Node=NULL;
	static int flag=0;
        int ver=0;	
	/* Initialise this list and take appropriate structure item to append into the list   */
   	//if(flag!=0)
	//pvalue->ricRequestorID=flag+1;
        rtxDListInit(&(p_event->ric_eventTrigger_formats.u.eventTrigger_Format1->message_List));
        asn1Init_E2SM_RC_EventTrigger_Format1_message_List(&(p_event->ric_eventTrigger_formats.u.eventTrigger_Format1->message_List));
	
	switch(flag)
		{
                 case 0:
		 case 1:
	         	    	  flag++;
				  rtxDListAllocNodeAndData(&asn1_ctx,
        	        	  E2SM_RC_EventTrigger_Format1_Item,
        	        	  &Node,&event_item);
		
			    event_item->m.messageDirectionPresent=1;
	    		    event_item->m.associatedUEInfoPresent=0;
			    event_item->m.associatedUEEventPresent=0;
	 	  	    event_item->m.logicalORPresent=0;
	    
			    event_item->messageDirection=E2SM_RC_outgoing;
			    event_item->ric_eventTriggerCondition_ID=2;
			    event_item->messageType.t=T_E2SM_RC_MessageType_Choice_messageType_Choice_NI;
			    event_item->messageType.u.messageType_Choice_NI=malloc(sizeof(E2SM_RC_MessageType_Choice_NI));
			    event_item->messageType.u.messageType_Choice_NI->m.nI_IdentifierPresent=1;
			    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.t=T_InterfaceIdentifier_nG;
			    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG=malloc(sizeof(InterfaceID_NG));
			    
			    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[0]=cfg->plmn[0];
			    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[1]=cfg->plmn[1];
			    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[2]=cfg->plmn[2];
			    //event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[0]=0x12;
			    //event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[1]=0x23;
			    //event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[2]=0x31;
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.numocts=3;
   			    memset(p_event_msg,0,E2CU_ASN1_BUFFER_LENGTH);
         		    if( RT_OK != pu_setBuffer(&asn1_ctx, p_event_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
         		    {
            				printf("\n\npu_setBuffer failed.\n");
           			 	response = E2_FAILURE;
            				break;
         		    }                                  
			    else             
        			printf("\npu_setBuffer success.\n\n");
			   ver= asn1PE_PLMNIdentity(&asn1_ctx,&(event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity)); 
		//		   printf("\nasn1PE_PLMNIdentity=%d.\n\n",ver);
		//		   printf("\ndata=%d.\n\n",*p_event_msg);
        			   *p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
		//		   printf("\nasn1PE_PLMNIdentity--len=%d.\n\n",*p_event_msg_len);
			   // event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[0]=p_event_msg[0];
			   // event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[1]=p_event_msg[1];
			   // event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[2]=p_event_msg[2];
				    
				    
   			    memset(p_event_msg,0,E2CU_ASN1_BUFFER_LENGTH);
         		    if( RT_OK != pu_setBuffer(&asn1_ctx, p_event_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
         		    {
            				printf("\n\npu_setBuffer failed.\n");
           			 	response = E2_FAILURE;
            				break;
         		    }                                  
			    else             
        			printf("\npu_setBuffer success.\n\n");
				    
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFRegionID.numbits=8;
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFRegionID.data[0]=cfg->amf_region;//0X02
				ver=asn1PE_AMFRegionID (&asn1_ctx,(event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFRegionID)); 
		//		   printf("\nasn1PE_AMFRegionID=%d.\n\n",ver);
        			   *p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
		//		   printf("\nasn1PE_AMFRegionID--len=%d.\n\n",*p_event_msg_len);
				//    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFRegionID.data[0]=p_event_msg[0];
				   //printf("%d",11/0);
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFSetID.numbits=10;
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFSetID.data[0]=cfg->amf_set;//0xF1;


				    
   			    memset(p_event_msg,0,E2CU_ASN1_BUFFER_LENGTH);
         		    if( RT_OK != pu_setBuffer(&asn1_ctx, p_event_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
         		    {
            				printf("\n\npu_setBuffer failed.\n");
           			 	response = E2_FAILURE;
            				break;
         		    }                                  
			    else             
        			printf("\npu_setBuffer success.\n\n");

			
				ver=asn1PE_AMFSetID (&asn1_ctx,event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFSetID);
							
		//		   printf("\nasn1PE_AMFSetID=%d.\n\n",ver);
        			   *p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
		//		   printf("\nasn1PE_AMFSetID--len=%d.\n\n",*p_event_msg_len);
			//	    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFSetID.data[0]=p_event_msg[0];
			//	    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFSetID.data[1]=p_event_msg[1];
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFPointer.numbits=6;
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFPointer.data[0]=cfg->amf_pointer;   //0x01;
				   // event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFPointer.data[1]=cfg.amf_pointer[1];//0x23;
				    //event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFPointer.data[2]=cfg.amf_pointer[2];//0x34;

				    
   			    memset(p_event_msg,0,E2CU_ASN1_BUFFER_LENGTH);
         		    if( RT_OK != pu_setBuffer(&asn1_ctx, p_event_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
         		    {
            				printf("\n\npu_setBuffer failed.\n");
           			 	response = E2_FAILURE;
            				break;
         		    }                                  
			    else             
        			printf("\npu_setBuffer success.\n\n");

				ver=asn1PE_AMFPointer(&asn1_ctx,event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFPointer);
		//		   printf("\nasn1PE_AMFPointer=%d.\n\n",ver);
        			   *p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
		//		   printf("\nasn1PE_AMFPointer--len=%d.\n\n",*p_event_msg_len);
			// 	    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFPointer.data[0]=p_event_msg[0];
				   //*myguami=event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami;
				    event_item->messageType.u.messageType_Choice_NI->m.nI_MessagePresent=1;
				    if(flag==1)
				    event_item->messageType.u.messageType_Choice_NI->nI_Message.interfaceProcedureID=41;
				    else
				    event_item->messageType.u.messageType_Choice_NI->nI_Message.interfaceProcedureID=28;
				    printf("\n\nInterface : %d\n",event_item->messageType.u.messageType_Choice_NI->nI_Message.interfaceProcedureID);
		   
				   event_item->messageType.u.messageType_Choice_NI->nI_Message.messageType=initiatingMessage;
		   
					rtxDListAppendNode (
					&(p_event->ric_eventTrigger_formats.u.eventTrigger_Format1->message_List),
					Node);
				    break;
			case 5:
				    flag++;
				    memset(p_event,0,sizeof(E2SM_RC_EventTrigger));
				    printf("\n%p\n",&p_event);
				    p_event->ric_eventTrigger_formats.t=T_E2SM_RC_EventTrigger_ric_eventTrigger_formats_eventTrigger_Format2;
		//		    printf("\n\n=eventevent=====%p===========\n",(p_event->	ric_eventTrigger_formats.u.eventTrigger_Format2));

				    p_event->ric_eventTrigger_formats.u.eventTrigger_Format2=rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_EventTrigger_Format2);;

				    p_event->ric_eventTrigger_formats.u.eventTrigger_Format2->ric_callProcessType_ID=6;
				    p_event->ric_eventTrigger_formats.u.eventTrigger_Format2->ric_callProcessBreakpoint_ID=1;	
				    asn1Print_E2SM_RC_EventTrigger("E2SM_RC_EventTrigger",p_event);
				    break;
			}
		 //   event_item->messageType.u.messageType_Choice_NI->nI_Identifier.t=T_InterfaceIdentifier_nG;
		    
		 /*   event_item->messageType.u.messageType_Choice_NI->nI_Type=nG;
		    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG=malloc(sizeof(InterfaceID_NG)) ;
		    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.numocts=3;
		    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[0]=0x12;
		    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[1]=0x31;
		    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[2]=0x23;
	*/

	 /* if(flag==0)
		    { 
		    event_item->messageType.u.messageType_Choice_NI->nI_Message.interfaceProcedureID=41;
		    flag++;
		    }
		    else
		    {*/
			
    /*
     */ 

		//printf("=====numocts : %d===\n\n\n", p_value_ie3->ricEventTriggerDefinition.numocts);
		memset(p_event_msg1,0,E2CU_ASN1_BUFFER_LENGTH);
	//memset(p_event_msg,0,8199);
         if( RT_OK != pu_setBuffer(&asn1_ctx, p_event_msg1,E2CU_ASN1_BUFFER_LENGTH, TRUE))
         {
          //  GNB_TRACE(GNB_ERROR,"pu_setBuffer failed.");
            printf("\n\npu_setBuffer failed.\n");
            response = E2_FAILURE;
            break;
         }                                  
	else             
        printf("\npu_setBuffer success.\n\n");
	a=asn1PE_E2SM_RC_EventTrigger(&asn1_ctx,p_event);
        printf("\n\n===asn1PE_E2SM_RC_EventTrigger===a=%d===========\n",a);
        *p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
	printf("p_event_msg_len :%d\n\n",*p_event_msg_len);
//	printf("p_event_msg : %x\n\n",*p_event_msg);
        for(a=0; a< ((*p_event_msg_len)); a ++)
        {
          fprintf(stderr, "%02x ", p_event_msg1[a]);
        }
	a=0;
         fprintf(stderr, "\n");
// assign p_event_msg to ricEventTriggerDefinition

p_value_ie3->ricEventTriggerDefinition.data=p_event_msg1;
p_value_ie3->ricEventTriggerDefinition.numocts=*p_event_msg_len;

	if(flag == 3)
	{
		flag++;
	//	*p_event_msg1="0x0a00000500000000107535200000103aa2682200";
		p_event_msg1[0]=10;
		p_event_msg1[1]=0;
		p_event_msg1[2]=0;
		p_event_msg1[3]=5;
		p_event_msg1[4]=0;
		p_event_msg1[5]=0;
		p_event_msg1[6]=0;
		p_event_msg1[7]=0;
		p_event_msg1[8]=16;
		p_event_msg1[9]=117;
		p_event_msg1[10]=53;
		p_event_msg1[11]=32;
		p_event_msg1[12]=0;
		p_event_msg1[13]=0;
		p_event_msg1[14]=16;
		p_event_msg1[15]=58;
		p_event_msg1[16]=162;
		p_event_msg1[17]=104;
		p_event_msg1[18]=34;
		p_event_msg1[19]=0;
        	
		for(a=0; a<20; a ++)
       	 	{
          		fprintf(stderr, "%02x ", p_event_msg1[a]);
        	}
		 asn1Print_E2SM_RC_EventTrigger ("Event_trigger_definition",p_event);//p_event_msg1
		a=0;
        p_value_ie3->ricEventTriggerDefinition.numocts=20;
	p_value_ie3->ricEventTriggerDefinition.data=(OSOCTET *)p_event_msg1; 
	asn1Print_E2SM_RC_EventTrigger("test Event",p_event);//p_event_msg1
	}
	else if(flag ==4)
	{ 
      	 	//p_value_ie3->ricEventTriggerDefinition.numocts=*p_event_msg_len;
		//p_value_ie3->ricEventTriggerDefinition.data=(OSOCTET *)p_event_msg1;
	//	*p_event_msg1="0x0a00000200000200106aad200000103aa2682200";
		p_event_msg1[0]=10;
		p_event_msg1[1]=0;
		p_event_msg1[2]=0;
		p_event_msg1[3]=2;
		p_event_msg1[4]=0;
		p_event_msg1[5]=0;
		p_event_msg1[6]=2;
		p_event_msg1[7]=0;
		p_event_msg1[8]=16;
		p_event_msg1[9]=106;
		p_event_msg1[10]=173;
		p_event_msg1[11]=32;
		p_event_msg1[12]=0;
		p_event_msg1[13]=0;
		p_event_msg1[14]=16;
		p_event_msg1[15]=58;
		p_event_msg1[16]=162;
		p_event_msg1[17]=104;
		p_event_msg1[18]=34;
		p_event_msg1[19]=0;
		for(a=0; a<20; a ++)
       	 	{
          		fprintf(stderr, "%02x ", p_event_msg1[a]);
        	}
		a=0;
        p_value_ie3->ricEventTriggerDefinition.numocts=20;
	p_value_ie3->ricEventTriggerDefinition.data=(OSOCTET *)p_event_msg1;
 	} 
	printf("=====numocts : %d===\n\n\n", p_value_ie3->ricEventTriggerDefinition.numocts);
 	printf("=====data : %x===\n\n\n", *p_value_ie3->ricEventTriggerDefinition.data);
   for(a=0; a<p_value_ie3->ricEventTriggerDefinition.numocts; a ++)
     {
         fprintf(stderr, "%02x ", p_value_ie3->ricEventTriggerDefinition.data[a]);
      }
	a=0; 
   /* Event Trigger OCTET STRING */
//   p_value_ie3->ricEventTriggerDefinition.data =
  //      (OSOCTET *)cfg->eventTrigger;

//   p_value_ie3->ricEventTriggerDefinition.numocts =
  //      cfg->eventTriggerLen;

   /* Debug print */
  for (int i = 0; i < cfg->eventTriggerLen; i++)
   {
      printf("%02X ", cfg->eventTrigger[i]);
   }
   printf("\n"); 
   int r;
  // r=asn1PD_E2SM_RC_EventTrigger(&asn1_ctx, &p_value_ie3->ricEventTriggerDefinition);
   //printf("\nasn1PD_E2SM_RC_EventTrigger definition=%d.\n",r);                             
      
    
	int                   m=0;
	OSRTDListNode        *Node1=NULL;
	OSRTDListNode        *Node3=NULL;
	a=0;
	E2SM_RC_ActionDefinition           *action=NULL;
	action=rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_ActionDefinition);
	E2SM_RC_ActionDefinition_Format3_Item            *format3_item=NULL;
	E2SM_RC_ActionDefinition_Format1_Item            *format1_item=NULL;

	rtxDListInit(&(p_value_ie3->ricAction_ToBeSetup_List));
	asn1Init_e2ap_RICactions_ToBeSetup_List(&(p_value_ie3->ricAction_ToBeSetup_List));
        for (a = 0 ; a < 1 ; a++ )
	{  
            rtxDListAllocNodeAndData(&asn1_ctx,
                  e2ap_RICactions_ToBeSetup_List_element,
                  &Node1,&listE);

            memset(listE ,0,sizeof(e2ap_RICactions_ToBeSetup_List_element));
	    listE->id=19;
	    listE->criticality=1;
	    //listE->value.t=T5e2ap___e2ap_RICaction_ToBeSetup_ItemIEs_1;
	    listE->value.t=T5e2ap___e2ap_RICaction_ToBeSetup_ItemIEs_1;
	    listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1=rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICaction_ToBeSetup_Item);
	    if( listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1 ==NULL)
		{
			printf("Malloc Failed !!\n\n\n");
			break;
		}
	    
            switch(flag)
	    {
              case 1:
	      case 2:		
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->extElem1.count=0;
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->m.ricActionDefinitionPresent=1;
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->m.ricSubsequentActionPresent=1;
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricSubsequentAction.ricSubsequentActionType=cfg->ricSubsequentActionType;//e2ap_continue_;
			
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricSubsequentAction.ricTimeToWait=e2ap_w1ms;
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionID=cfg->actionID;
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionType=cfg->ricActionType;//e2ap_report;
			action->ric_actionDefinition_formats.t=T_E2SM_RC_ActionDefinition_ric_actionDefinition_formats_actionDefinition_Format1;
			action->ric_actionDefinition_formats.u.actionDefinition_Format1=rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_ActionDefinition_Format1);
			rtxDListInit(&(action->ric_actionDefinition_formats.u.actionDefinition_Format1->ranP_ToBeReported_List));
                  	asn1Init_E2SM_RC_ActionDefinition_Format1_ranP_ToBeReported_List(&(action->ric_actionDefinition_formats.u.actionDefinition_Format1->ranP_ToBeReported_List));
			
            		rtxDListAllocNodeAndData(&asn1_ctx,
                  		E2SM_RC_ActionDefinition_Format1_Item,
                  		&Node3,&format1_item);
			format1_item->m.ranParameter_DefinitionPresent=0;
			format1_item->ranParameter_ID=2;
			
            		rtxDListAppendNode (
                  	&(action->ric_actionDefinition_formats.u.actionDefinition_Format1->ranP_ToBeReported_List),
                  	Node3);
         		if( RT_OK != pu_setBuffer(&asn1_ctx, p_event_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
         		{
            			printf("\n\npu_setBuffer failed.\n");
            			response = E2_FAILURE;
            			break;
         		}
			else
            			printf("\n\npu_setBuffer success.\n");
			m=asn1PE_E2SM_RC_ActionDefinition(&asn1_ctx,action);                                 
            			printf("\nasn1PE_E2SM_RC_ActionDefinition=%d.\n",m);
        		*p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
				
				/*p_event_msg="0x0001010000000001";
                        	 p_event_msg[0] = 0;
                        	 p_event_msg[1] = 1;
                        	 p_event_msg[2] = 1;
                        	 p_event_msg[3] = 0;
                        	 p_event_msg[4] = 0;
                        	 p_event_msg[5] = 0;
                        	 p_event_msg[6] = 0;
                        	 p_event_msg[7] = 1;
        			 printf("\n=======Action definition=========\n");
		  		 for(a=0; a<8; a ++)
        			 {
	          			fprintf(stderr, "%02x ", p_event_msg[a]);
        			 }
				
				listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionDefinition.numocts=8;	
	        		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionDefinition.data=(OSOCTET *)p_event_msg;	*/

        	listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionDefinition.data=(OSOCTET *)cfg->actionTrigger;	
         listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionDefinition.numocts=cfg->actionTriggerLen;
         /* Debug print */
         for (int i = 0; i < cfg->actionTriggerLen; i++)
         {
            printf("%02X ", cfg->actionTrigger[i]);
         }
         printf("\n"); 
         
     
         //ver =asn1PD_E2SM_RC_ActionDefinition(&asn1_ctx,listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1);
         //printf("\n ver=%d.\n\n",ver);    
        // m=asn1PD_E2SM_RC_ActionDefinition(&asn1_ctx,listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1); 
        // printf("\nasn1PD_E2SM_RC_ActionDefinition=%d.\n",m);                             

         
   



 
            
			break;
              case 3:
			
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->m.ricActionDefinitionPresent=1;
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->m.ricSubsequentActionPresent=1;
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionID=1;
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricSubsequentAction.ricSubsequentActionType=e2ap_continue_;
			
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricSubsequentAction.ricTimeToWait=e2ap_w1ms;
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionType=e2ap_insert;
			action->ric_Style_Type=4;
			action->ric_actionDefinition_formats.t=T_E2SM_RC_ActionDefinition_ric_actionDefinition_formats_actionDefinition_Format3;
			action->ric_actionDefinition_formats.u.actionDefinition_Format3=rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_ActionDefinition_Format3);
			action->ric_actionDefinition_formats.u.actionDefinition_Format3->m.ueIDPresent=0;
			action->ric_actionDefinition_formats.u.actionDefinition_Format3->ric_InsertIndication_ID=1;
			rtxDListInit(&(action->ric_actionDefinition_formats.u.actionDefinition_Format3->ranP_InsertIndication_List));
                  	asn1Init_E2SM_RC_ActionDefinition_Format3_ranP_InsertIndication_List(&(action->ric_actionDefinition_formats.u.actionDefinition_Format3->ranP_InsertIndication_List));

            		rtxDListAllocNodeAndData(&asn1_ctx,
                  		E2SM_RC_ActionDefinition_Format3_Item,
                  		&Node3,&format3_item);
			format3_item->m.ranParameter_DefinitionPresent=0;
			format3_item->ranParameter_ID=24;
			
            		rtxDListAppendNode (
                  	&(action->ric_actionDefinition_formats.u.actionDefinition_Format1->ranP_ToBeReported_List),
                  	Node3);
         		if( RT_OK != pu_setBuffer(&asn1_ctx, p_event_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
         		{
            			printf("\n\npu_setBuffer failed.\n");
            			response = E2_FAILURE;
            			break;
         		}
			else
            			printf("\n\npu_setBuffer success.\n");
			m=asn1PE_E2SM_RC_ActionDefinition(&asn1_ctx,action);                                 
            			printf("\nasn1PE_E2SM_RC_ActionDefinition=%d.\n",m);
        		*p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
            			printf("\nMessage len =%d.\n",*p_event_msg_len);
            			printf("\nMessage  =%d.\n",*p_event_msg_len);
        		for(a=0; a< ((*p_event_msg_len)); a ++)
        		{
          		fprintf(stderr, "%02x ", p_event_msg[a]);
        		}
			a=0;
        		printf("\n\n=======Action definition====%d=====\n",flag);
			if(flag == 3)
			{
				//*p_event_msg="0x00010440000000000017";
                        	 p_event_msg[0] = 0;
                        	 p_event_msg[3] = 64;
                        		 
                        	 p_event_msg[9] = 23;
            			printf("\nMessage  =%d.\n",*p_event_msg_len);
        			for(a=0; a< ((*p_event_msg_len)); a ++)
        			{
          				fprintf(stderr, "%02x ", p_event_msg[a]);
        			}
		        	listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionDefinition.numocts=10;	
		        	listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionDefinition.data=(OSOCTET *)p_event_msg;	
		        }
			if(flag == 4)
			{
				//*p_event_msg="0x00010340000000000006";
                        	 p_event_msg[0] = 0;
                        	 p_event_msg[3] = 64;
                        		 
                        	 p_event_msg[9] = 23;
            			printf("\nMessage  =%d.\n",*p_event_msg_len);
        			for(a=0; a< ((*p_event_msg_len)); a ++)
        			{
          				fprintf(stderr, "%02x ", p_event_msg[a]);
        			}
		        	listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionDefinition.numocts=10;	
		        	listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionDefinition.data=(OSOCTET *)p_event_msg;	
		        }
			break;
            }
           asn1Print_E2SM_RC_ActionDefinition("Action definition",action);
            rtxDListAppendNode (
                  &(p_value_ie3->ricAction_ToBeSetup_List),
                  Node1);
        }
	//p_value_ie3->ric_action_to_be_setup_element[0].ric_action_to_be_setup_list.ric_action_id =123;
	//p_value_ie3->ric_action_to_be_setup_element[0].ric_action_to_be_setup_list.ric_action_type =1;
	

    

      if (RT_OK != asn1Append_e2ap_RICsubscriptionRequest_protocolIEs_3(&asn1_ctx,&p_asn_ric_subscription_request->protocolIEs,p_value_ie3))
      {
       //  GNB_TRACE(GNB_ERROR, "Failed to Add IE3 !!");
        printf("\n\n\nFailed to Add IE3 !!\n\n\n"); 
//	response = E2_FAILURE;
       // break;
      }
        printf("\n\n\nsuccessfully to Add IE3 !!\n\n\n"); 
       //  GNB_TRACE(GNB_INFO, " IE3 encoded");


         /* ASN Encode message */
         if( RT_OK != pu_setBuffer(&asn1_ctx, p_asn_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
         {
          //  GNB_TRACE(GNB_ERROR,"pu_setBuffer failed.");
            response = E2_FAILURE;
            break;
         }    
	asn1PrtToStrm_e2ap_E2AP_PDU(&asn1_ctx, "e2ap_pdu", &e2ap_pdu);                                           
        // GNB_TRACE(GNB_INFO, " After pu_setBuffer");
         if (0 != asn1PE_e2ap_E2AP_PDU(&asn1_ctx, &e2ap_pdu))
         {
            rtxErrPrint(&asn1_ctx);
          //  GNB_TRACE(GNB_INFO, "ASN1 encoding of E2 Setup Request failed.");
            response = E2_FAILURE;
            break;
         }
         else
         {
            *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
             if(RT_OK == asn1PrtToStrm_e2ap_E2AP_PDU(&asn1_ctx, "e2ap_pdu", &e2ap_pdu))
             {
               // GNB_TRACE(GNB_INFO, "asn1PrtToStrm_e2ap_E2AP_PDU success !!");
                printf("\n\n\nasn1PrtToStrm_e2ap_E2AP_PDU success !!\n\n\n");
		response = E2_SUCCESS;
             }
             else
             {
                //GNB_TRACE(GNB_INFO, "asn1PrtToStrm_e2ap_E2AP_PDU failure !!");
                printf("\n\n\nasn1PrtToStrm_e2ap_E2AP_PDU failure !!\n\n\n");
                response = E2_FAILURE;
             }
         }
         /* testing purpose printing HEX DUMP */
         int i;
         fprintf(stderr, "value of p_asn_msg_len is %d \n", *p_asn_msg_len);
         for(i=0; i< *p_asn_msg_len; i ++)
         {
            fprintf(stderr, "%02x ", p_asn_msg[i]);
         }
         fprintf(stderr, "\n");

     }while(0);
    return response;

}


//  *****************  e2 setup indication ********************** //


e2_return_et encode_ric_indication
(
    UInt8   **pp_asn_msg,
    UInt16  *p_asn_msg_len
    //GUAMI   *myguami
)
{
    e2ap_E2AP_PDU                      e2ap_pdu;
    OSCTXT                             asn1_ctx;
    e2ap_RICindication                *p_asn_e2ap_RICindication = NULL;
    e2_return_et                      response = E2_SUCCESS;

   // struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
    UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
    UInt8   *p_event_msg=malloc(E2CU_ASN1_BUFFER_LENGTH);
    UInt8   *p_event_msg1=malloc(E2CU_ASN1_BUFFER_LENGTH);
    UInt16  *p_event_msg_len=malloc(sizeof(UInt16));
    UInt16  *p_event_msg_len1=malloc(sizeof(UInt16));
   // pvalue->ricRequestorID=1;
  //  pvalue->ricInstanceID=55068;

    printf (" p_asn_msg : %p",p_asn_msg);
   if (NULL == p_asn_msg)
   {
	   //GNB_TRACE(GNB_ERROR, "Memory Allocation for p_asn_msg Failed !!");
	   printf("\n\n\nFailed !!\n\n");
	   return E2_FAILURE;
   }
   memset(p_asn_msg,0,sizeof(UInt8));


   //GNB_TRACE(GNB_INFO, "encode_ric_indication");
   printf( "\n\n\nencode_ric_indication\n\n");
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

	   e2ap_pdu.t = T_e2ap_E2AP_PDU_initiatingMessage;
	   e2ap_pdu.u.initiatingMessage = rtxMemAllocTypeZ(&asn1_ctx,e2ap_InitiatingMessage);

	   if(NULL ==  e2ap_pdu.u.initiatingMessage)
	   {
		   //   GNB_TRACE(GNB_ERROR, "Memory allocation falied for successfulOutcome");
		   printf("\n\n\nMemory allocation falied for successfulOutcome\n\n\n");
		   response = E2_FAILURE;
		   break;
	   }
	   p_asn_e2ap_RICindication =
		   rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICindication);

	   if(NULL == p_asn_e2ap_RICindication)
	   {
		   response = E2_FAILURE;
		   break;
	   }
	   asn1SetTC_e2ap_InitiatingMessage_ricIndication(
			   &asn1_ctx,
			   e2ap_pdu.u.initiatingMessage,
			   p_asn_e2ap_RICindication);
      struct e2ap_RICrequestID *pvalue = rtxMemAllocTypeZ(&asn1_ctx, struct e2ap_RICrequestID);
      
      pvalue->ricRequestorID = 1;
      pvalue->ricInstanceID  = 55068;
    

	   if (RT_OK != asn1Append_e2ap_RICindication_protocolIEs_1(&asn1_ctx,&p_asn_e2ap_RICindication->protocolIEs,pvalue))
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
	   

	   if (RT_OK != asn1Append_e2ap_RICindication_protocolIEs_2(&asn1_ctx,&p_asn_e2ap_RICindication->protocolIEs,*p_value_ie2))
	   {
		   //   GNB_TRACE(GNB_ERROR, "Failed to Add IE2 !!");
		   response = E2_FAILURE;
		   break;
	   }
	   //GNB_TRACE(GNB_INFO, " IE2 encoded");
      printf("\n\n\n IE2 encoded\n\n\n");


      e2ap_RICactionID *p_value_ie3 =NULL;
	   p_value_ie3 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICactionID);

	   if(NULL == p_value_ie3)
	   {
		   // GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
		   printf("\n\n\nMemory allocation failed !!\n\n\n"); 
		   response = E2_FAILURE;
		   break;
	   }
      *p_value_ie3=1; 

      if (RT_OK != asn1Append_e2ap_RICindication_protocolIEs_3(&asn1_ctx,&p_asn_e2ap_RICindication->protocolIEs,*p_value_ie3))
	   {
		   //   GNB_TRACE(GNB_ERROR, "Failed to Add IE2 !!");
		   response = E2_FAILURE;
		   break;
	   }
	   //GNB_TRACE(GNB_INFO, " IE3 encoded");
      printf("\n\n\n IE3 encoded\n\n\n");



      e2ap_RICindicationType *p_value_ie4 =NULL;
	   p_value_ie4 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICindicationType);

	   if(NULL == p_value_ie4)
	   {
		   // GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
		   printf("\n\n\nMemory allocation failed !!\n\n\n"); 
		   response = E2_FAILURE;
		   break;
	   }
      *p_value_ie4=0; 

      if (RT_OK != asn1Append_e2ap_RICindication_protocolIEs_5(&asn1_ctx,&p_asn_e2ap_RICindication->protocolIEs,*p_value_ie4))
	   {
		   //   GNB_TRACE(GNB_ERROR, "Failed to Add IE5 !!");
		   response = E2_FAILURE;
		   break;
	   }
	   //GNB_TRACE(GNB_INFO, " IE4 encoded");
      printf("\n\n\n IE4 encoded\n\n\n");

      e2ap_RICindicationHeader *p_value_ie5 = NULL;
	   p_value_ie5 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICindicationHeader);
	  // memset(p_value_ie3,0,sizeof(e2ap_RICindicationHeader));//avoid using memset before using error handling
	   if(NULL == p_value_ie5)
	   {
		   //  GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
		   printf("\n\n\nMemory allocation failed !!\n\n\n"); 
		   response = E2_FAILURE;
		   break;
	   }
     // OSRTDListNode              *Node1  = NULL;
      E2SM_KPM_IndicationHeader *p_event = NULL;
      p_event = rtxMemAllocTypeZ(&asn1_ctx, E2SM_KPM_IndicationHeader);


     // rtxDListAllocNodeAndData(&asn1_ctx, E2SM_KPM_IndicationHeader, &Node1, &p_event);
      if(NULL == p_event)
      {
         //GNB_TRACE(GNB_ERROR, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n"); 
         response = E2_FAILURE;
         break;
      }
      p_event->indicationHeader_formats.t = T_E2SM_KPM_IndicationHeader_indicationHeader_formats_indicationHeader_Format1;
      p_event->indicationHeader_formats.u.indicationHeader_Format1 = rtxMemAllocTypeZ(&asn1_ctx,E2SM_KPM_IndicationHeader_Format1);

      if(NULL == p_event->indicationHeader_formats.u.indicationHeader_Format1)
      {
         //GNB_TRACE(GNB_ERROR, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n"); 
         response = E2_FAILURE;
         break;
      }
      //asn1Init_E2SM_KPM_IndicationHeader_Format1(p_event->indicationHeader_formats.u.indicationHeader_Format1);

      p_event->indicationHeader_formats.u.indicationHeader_Format1->m.fileFormatversionPresent =0;
      p_event->indicationHeader_formats.u.indicationHeader_Format1->m.senderNamePresent=0;
      p_event->indicationHeader_formats.u.indicationHeader_Format1->m.senderTypePresent=0;
      p_event->indicationHeader_formats.u.indicationHeader_Format1->m.vendorNamePresent=0;
     // printf("\nAllocated p_event at: %p\n", p_event);

      p_event->indicationHeader_formats.u.indicationHeader_Format1->colletStartTime.numocts=4;
      p_event->indicationHeader_formats.u.indicationHeader_Format1->colletStartTime.data[0]=0x00;
      p_event->indicationHeader_formats.u.indicationHeader_Format1->colletStartTime.data[1]=0x00;
      p_event->indicationHeader_formats.u.indicationHeader_Format1->colletStartTime.data[2]=0x00;
      p_event->indicationHeader_formats.u.indicationHeader_Format1->colletStartTime.data[3]=0x00;

     //asn1Init_E2SM_KPM_IndicationHeader_Format1(&p_event->indicationHeader_formats.u.indicationHeader_Format1->extElem1);
      rtxDListInit(
        &p_event->indicationHeader_formats.u.indicationHeader_Format1->extElem1);
      p_event->indicationHeader_formats.u.indicationHeader_Format1->extElem1.count = 0;
      p_event->indicationHeader_formats.u.indicationHeader_Format1->extElem1.head = NULL;
      p_event->indicationHeader_formats.u.indicationHeader_Format1->extElem1.tail = NULL;



   


      int ver=0;
      OSRTDListNode        *Node1 = NULL;
      e2ap_GlobalE2node_ID *list =NULL;
	   //list = rtxMemAllocTypeZ(&asn1_ctx,e2ap_GlobalE2node_ID);
      rtxDListAllocNodeAndData(&asn1_ctx,e2ap_GlobalE2node_ID , &Node1, &list);

	   if(NULL == list)
	   {
		   // GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
		   printf("\n\n\nMemory allocation failed !!\n\n\n"); 
		   response = E2_FAILURE;
		   break;
	   }

      list->t = T_e2ap_GlobalE2node_ID_gNB;
      list->u.gNB = rtxMemAllocTypeZ(&asn1_ctx,e2ap_GlobalE2node_gNB_ID);
     // asn1Init_e2ap_GlobalE2node_gNB_ID(list->u.gNB);
      
      list->u.gNB->m.global_en_gNB_IDPresent = 0;
      list->u.gNB->m.gNB_CU_UP_IDPresent = 1;
      list->u.gNB->m.gNB_DU_IDPresent = 0;

      // PLMN
      list->u.gNB->global_gNB_ID.plmn_id.numocts = 3;
      list->u.gNB->global_gNB_ID.plmn_id.data[0] = 0x00;
      list->u.gNB->global_gNB_ID.plmn_id.data[1] = 0xf1;
      list->u.gNB->global_gNB_ID.plmn_id.data[2] = 0x10;

         // GNB_ID
      list->u.gNB->global_gNB_ID.gnb_id.t = T_e2ap_GNB_ID_Choice_gnb_ID;
      list->u.gNB->global_gNB_ID.gnb_id.u.gnb_ID =rtxMemAllocTypeZ(&asn1_ctx, ASN1BitStr32);
      list->u.gNB->global_gNB_ID.gnb_id.u.gnb_ID->numbits = 32;
      list->u.gNB->global_gNB_ID.gnb_id.u.gnb_ID->data[0] = 0x00;
      list->u.gNB->global_gNB_ID.gnb_id.u.gnb_ID->data[1] = 0x00;
      list->u.gNB->global_gNB_ID.gnb_id.u.gnb_ID->data[2] = 0x00;
      list->u.gNB->global_gNB_ID.gnb_id.u.gnb_ID->data[3] = 0xd1;

      // Configure gNB_CU_UP_ID
      list->u.gNB->gNB_CU_UP_ID = 32;

      // Encode gNB ID
      memset(p_event_msg, 0, E2CU_ASN1_BUFFER_LENGTH);
      if (RT_OK != pu_setBuffer(&asn1_ctx, p_event_msg, E2CU_ASN1_BUFFER_LENGTH, TRUE))
      {
         printf("\n\npu_setBuffer failed.\n");
         response = E2_FAILURE;
         break;
      }
      else
      printf("\npu_setBuffer success.\n\n");

      ver = asn1PE_e2ap_GNB_ID_Choice(&asn1_ctx, &list->u.gNB->global_gNB_ID.gnb_id);
      printf("\n ver=%d.\n\n", ver);


      printf("\n=== Adding GlobalE2node_ID (gNB) ===\n");


      

     


     // OSRTDList       *list2 = NULL;
    //  list2 = rtxMemAllocTypeZ(&asn1_ctx, OSRTDList);
    //  rtxDListInit(list2);
    //  rtxDListAppendNode(list2, Node1);

      
     rtxDListAppendNode(&p_event->indicationHeader_formats.u.indicationHeader_Format1->extElem1, Node1);


      asn1Print_E2SM_KPM_IndicationHeader("TEST",p_event);
            asn1Print_e2ap_GlobalE2node_ID("TEST",list);

    // abort();


      

      

        

      
      if (RT_OK != asn1Append_e2ap_RICindication_protocolIEs_6(&asn1_ctx,&p_asn_e2ap_RICindication->protocolIEs,p_value_ie5))
	   {
		   //   GNB_TRACE(GNB_ERROR, "Failed to Add IE6 !!");
		   response = E2_FAILURE;
		   break;
	   }
	   //GNB_TRACE(GNB_INFO, " IE5 encoded");
      printf("\n\n\n IE5 encoded\n\n\n");


    
   } while (0);

   asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);

   return response;
}

//   ********************** e2 setup request ******************* //

e2_return_et encode_e2_setup_request
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len
)
{
   struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));

   e2ap_E2AP_PDU                           e2ap_pdu;
   OSCTXT                                  asn1_ctx;
   e2ap_E2setupRequest                     *p_asn_e2_setup_request= NULL;
   e2_return_et                            response = E2_SUCCESS;
 

   UInt8   *p_event_msg=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg1=malloc(E2CU_ASN1_BUFFER_LENGTH);

   UInt16  *p_event_msg_len=malloc(sizeof(UInt16));

   UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
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

      e2ap_pdu.t = T_e2ap_E2AP_PDU_initiatingMessage;
	   e2ap_pdu.u.initiatingMessage = rtxMemAllocTypeZ(&asn1_ctx,e2ap_InitiatingMessage);

       if(NULL ==  e2ap_pdu.u.initiatingMessage)
       {
      //   GNB_TRACE(GNB_ERROR, "Memory allocation falied for initiatingMessage");
        printf("\n\n\nMemory allocation falied for initiatingMessage\n\n\n");
	     response = E2_FAILURE;
         break;
       }

        p_asn_e2_setup_request =
           rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2setupRequest);
       if(NULL == p_asn_e2_setup_request)
       {
           response = E2_FAILURE;
           break;
       }

       
       asn1SetTC_e2ap_InitiatingMessage_e2setup(
                       &asn1_ctx,
                       e2ap_pdu.u.initiatingMessage,
                       p_asn_e2_setup_request);

      if (RT_OK != asn1Append_e2ap_E2setupRequest_protocolIEs_1(&asn1_ctx,&p_asn_e2_setup_request->protocolIEs,E2CU_ONE))
      {
        	printf("\n\nFailed to Add IE1 !!\n\n"); 
	      response = E2_FAILURE;
               break;
      }
      printf("\n\n\n IE1 encoded\n\n\n");



      e2ap_GlobalE2node_ID *list =NULL;
	   list = rtxMemAllocTypeZ(&asn1_ctx,e2ap_GlobalE2node_ID);

	   if(NULL == list)
	   {
		   // GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
		   printf("\n\n\nMemory allocation failed !!\n\n\n"); 
		   response = E2_FAILURE;
		   break;
	   }

      list->t = T_e2ap_GlobalE2node_ID_gNB;
      list->u.gNB = rtxMemAllocTypeZ(&asn1_ctx,e2ap_GlobalE2node_gNB_ID);
      asn1Init_e2ap_GlobalE2node_gNB_ID(list->u.gNB);

      e2ap_GlobalE2node_gNB_ID *gnb = list->u.gNB;

     
      list->u.gNB->m.global_en_gNB_IDPresent = 0;
      list->u.gNB->m.gNB_CU_UP_IDPresent = 0;
      list->u.gNB->m.gNB_DU_IDPresent = 0;

      // PLMN
      list->u.gNB->global_gNB_ID.plmn_id.numocts = 3;
      list->u.gNB->global_gNB_ID.plmn_id.data[0] = 0x00;
      list->u.gNB->global_gNB_ID.plmn_id.data[1] = 0xf1;
      list->u.gNB->global_gNB_ID.plmn_id.data[2] = 0x10;

      // GNB_ID
      list->u.gNB->global_gNB_ID.gnb_id.t = T_e2ap_GNB_ID_Choice_gnb_ID;
      list->u.gNB->global_gNB_ID.gnb_id.u.gnb_ID =rtxMemAllocTypeZ(&asn1_ctx, ASN1BitStr32);
      list->u.gNB->global_gNB_ID.gnb_id.u.gnb_ID->numbits = 32;
      list->u.gNB->global_gNB_ID.gnb_id.u.gnb_ID->data[0] = 0x00;
      list->u.gNB->global_gNB_ID.gnb_id.u.gnb_ID->data[1] = 0x00;
      list->u.gNB->global_gNB_ID.gnb_id.u.gnb_ID->data[2] = 0x00;
      list->u.gNB->global_gNB_ID.gnb_id.u.gnb_ID->data[3] = 0xd1;
               

      if (RT_OK != asn1Append_e2ap_E2setupRequest_protocolIEs_2(&asn1_ctx,&p_asn_e2_setup_request->protocolIEs,list))
      {
         printf("\n\nFailed to Add IE2 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      printf("\n\n\n IE2 encoded\n\n\n");


      e2ap_RANfunctionsID_List *p_value_ie3 = NULL;
      p_value_ie3 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RANfunctionsID_List);
      //memset(p_value_ie3,0,sizeof(e2ap_RANfunctionsID_List));

      if(NULL == p_value_ie3)
      {
       //  GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
        printf("\n\n\nMemory allocation failed !!\n\n\n"); 
	     response = E2_FAILURE;
        break;
      } 

      OSRTDListNode  *fun_id = NULL;
      e2ap_RANfunctions_List_element  *e2ap_func_id= NULL;

      //rtxDListInit(p_value_ie3);
      asn1Init_e2ap_RANfunctionsID_List(p_value_ie3);
      
      int loop =0 ;
      for (loop = 0 ; loop < 1 ; loop++ ){  
        // rtxDListAllocNodeAndData(&asn1_ctx,
        //    e2ap_RANfunctionsID_List_element,
         //      &fun_id, &e2ap_func_id);
         rtxDListAllocNodeAndData(&asn1_ctx,e2ap_RANfunctions_List_element,
            &fun_id,&e2ap_func_id);
        // memset(e2ap_func_id ,0,sizeof(e2ap_RANfunctionsID_List_element));

         e2ap_func_id->id = 8;
         e2ap_func_id->criticality = 0;
         e2ap_func_id->value.t = T42e2ap___e2ap_RANfunction_ItemIEs_1;
         e2ap_func_id->value.u._e2ap_RANfunction_ItemIEs_1= rtxMemAllocTypeZ(&asn1_ctx,e2ap_RANfunction_Item);
         e2ap_func_id->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionID = 2;

   
         //rtxDListInit(&e2ap_func_id->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionDefinition);
         asn1Init_e2ap_RANfunctionDefinition(&e2ap_func_id->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionDefinition);
         
         



            // Allocate and populate the E2SM-RC RAN function definition
            OSRTDListNode *def_node = NULL;
            E2SM_RC_RANFunctionDefinition *p_event = NULL;

            rtxDListAllocNodeAndData(&asn1_ctx,
                                    E2SM_RC_RANFunctionDefinition,
                                    &def_node, &p_event);

            //E2SM_RC_RANFunctionDefinition *p_event = NULL;
         // p_event = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_RANFunctionDefinition);
            if(NULL == p_event)
            {
               printf("\n\n\nMemory allocation failed for E2SM-RC definition!!\n\n\n");
               response = E2_FAILURE;
               break;
            }
            asn1Init_E2SM_RC_RANFunctionDefinition(p_event);


            // Set the presence flags based on what capabilities you support
            p_event->m.ranFunctionDefinition_EventTriggerPresent = 1;
            p_event->m.ranFunctionDefinition_ReportPresent = 1;
            p_event->m.ranFunctionDefinition_InsertPresent = 1;
            p_event->m.ranFunctionDefinition_ControlPresent = 1;
            p_event->m.ranFunctionDefinition_PolicyPresent = 0;


            int ver =0;
            // unsigned char buffer[4096]; // Larger buffer
            
            // Initialize and populate the RAN function name
            memset(p_event_msg, 0, E2CU_ASN1_BUFFER_LENGTH);
            pu_setBuffer(&asn1_ctx, p_event_msg, E2CU_ASN1_BUFFER_LENGTH, TRUE);

            asn1Init_RANfunction_Name(&p_event->ranFunction_Name);
            p_event->ranFunction_Name.ranFunction_ShortName = "ORAN-E2SM-RC";
            p_event->ranFunction_Name.ranFunction_E2SM_OID = "1.3.6.1.4.1.53148.1.1.2.3";  // E2SM-RC OID
            p_event->ranFunction_Name.ranFunction_Description = "RAN Control";

               ver = asn1PE_RANfunction_Name(&asn1_ctx, &p_event->ranFunction_Name);
                     printf("\n ver=%d.\n\n",ver);
         //asn1Print_RANfunction_Name("test1",&p_event->ranFunction_Name);



      

            // Initialize E2SM_RC_RANFunctionDefinition_EventTrigger
            E2SM_RC_RANFunctionDefinition_EventTrigger *p_event_trigger = NULL;
            p_event_trigger = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_RANFunctionDefinition_EventTrigger);

            if(NULL == p_event_trigger)
            {
               printf("\n\n\nMemory allocation failed for E2SM-RC event trigger!!\n\n\n");
               response = E2_FAILURE;
               break;
            }

            p_event_trigger->m.ran_L2Parameters_ListPresent = 0;
            p_event_trigger->m.ran_CallProcessTypes_ListPresent = 1;
            p_event_trigger->m.ran_UEIdentificationParameters_ListPresent = 0;
            p_event_trigger->m.ran_CellIdentificationParameters_ListPresent = 0;

            // Initialize ric_EventTriggerStyle_List
            asn1Init_E2SM_RC_RANFunctionDefinition_EventTrigger_ric_EventTriggerStyle_List(
            &p_event_trigger->ric_EventTriggerStyle_List);

            // Add one EventTriggerStyle item
         // OSRTDListNode *styleNode;
         // E2SM_RC_RANFunctionDefinition_EventTrigger_Style_Item *styleItem;

            //rtxDListAllocNodeAndData(&asn1_ctx,
            //   E2SM_RC_RANFunctionDefinition_EventTrigger_Style_Item,
            //  &styleNode, &styleItem);
            
               // Add EventTriggerStyle[0]
               
               OSRTDListNode *styleNode1;
               E2SM_RC_RANFunctionDefinition_EventTrigger_Style_Item *styleItem1;

               rtxDListAllocNodeAndData(&asn1_ctx,
                  E2SM_RC_RANFunctionDefinition_EventTrigger_Style_Item,
                  &styleNode1, &styleItem1);

               styleItem1->ric_EventTriggerStyle_Type = 1;
               styleItem1->ric_EventTriggerStyle_Name = "Message Event";
               styleItem1->ric_EventTriggerFormat_Type = 1;

               rtxDListAppendNode(&p_event_trigger->ric_EventTriggerStyle_List, styleNode1);

               // Add EventTriggerStyle[1]
               OSRTDListNode *styleNode2;
               E2SM_RC_RANFunctionDefinition_EventTrigger_Style_Item *styleItem2;

               rtxDListAllocNodeAndData(&asn1_ctx,
                  E2SM_RC_RANFunctionDefinition_EventTrigger_Style_Item,
                  &styleNode2, &styleItem2);

               styleItem2->ric_EventTriggerStyle_Type = 2;
               styleItem2->ric_EventTriggerStyle_Name = "Call Process break point";
               styleItem2->ric_EventTriggerFormat_Type = 2;

               rtxDListAppendNode(&p_event_trigger->ric_EventTriggerStyle_List, styleNode2);


               //define the EventTrigger_ran_CallProcessTypes_List
               asn1Init_E2SM_RC_RANFunctionDefinition_EventTrigger_ran_CallProcessTypes_List
               (&p_event_trigger->ran_CallProcessTypes_List);

               // Add one CallProcessTypes item[0]
               OSRTDListNode *callNode;
               E2SM_RC_RANFunctionDefinition_EventTrigger_CallProcess_Item *callItem;

               rtxDListAllocNodeAndData(&asn1_ctx,
               E2SM_RC_RANFunctionDefinition_EventTrigger_CallProcess_Item,
               &callNode, &callItem);


               callItem->callProcessType_ID = 6;
               callItem->callProcessType_Name = "PDU Session Management";

               asn1Init_E2SM_RC_RANFunctionDefinition_EventTrigger_CallProcess_Item_callProcessBreakpoints_List(&callItem->callProcessBreakpoints_List);

               // Add one CallProcessBreakpoints item
               OSRTDListNode *breakNode;
               E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item *breakItem;

               rtxDListAllocNodeAndData(&asn1_ctx,
               E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item,
               &breakNode, &breakItem);


               breakItem->callProcessBreakpoint_ID = 1;
               breakItem->callProcessBreakpoint_Name = "PDU Session Resource Setup";

            // asn1Init_E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item_ran_CallProcessBreakpointParameters_List(&breakItem->ran_CallProcessBreakpointParameters_List);
               rtxDListAppendNode(&callItem->callProcessBreakpoints_List, breakNode);
               rtxDListAppendNode(&p_event_trigger->ran_CallProcessTypes_List, callNode);

               // Add one CallProcessTypes item[1]
               OSRTDListNode *callNode1;
               E2SM_RC_RANFunctionDefinition_EventTrigger_CallProcess_Item *callItem1;

               rtxDListAllocNodeAndData(&asn1_ctx,
               E2SM_RC_RANFunctionDefinition_EventTrigger_CallProcess_Item,
               &callNode1, &callItem1);


               callItem1->callProcessType_ID = 1;
               callItem1->callProcessType_Name = "UE Context Management";

               asn1Init_E2SM_RC_RANFunctionDefinition_EventTrigger_CallProcess_Item_callProcessBreakpoints_List(&callItem1->callProcessBreakpoints_List);

               // Add one CallProcessBreakpoints item[1]
               OSRTDListNode *breakNode1;
               E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item *breakItem1;

               rtxDListAllocNodeAndData(&asn1_ctx,
               E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item,
               &breakNode1, &breakItem1);


               breakItem1->callProcessBreakpoint_ID = 1;
               breakItem1->callProcessBreakpoint_Name = "UE Context Setup";

            // asn1Init_E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item_ran_CallProcessBreakpointParameters_List(&breakItem->ran_CallProcessBreakpointParameters_List);
               rtxDListAppendNode(&callItem1->callProcessBreakpoints_List, breakNode1);
               rtxDListAppendNode(&p_event_trigger->ran_CallProcessTypes_List, callNode1);


               // Add one CallProcessTypes item[2]
               OSRTDListNode *callNode2;
               E2SM_RC_RANFunctionDefinition_EventTrigger_CallProcess_Item *callItem2;

               rtxDListAllocNodeAndData(&asn1_ctx,
               E2SM_RC_RANFunctionDefinition_EventTrigger_CallProcess_Item,
               &callNode2, &callItem2);


               callItem2->callProcessType_ID = 3;
               callItem2->callProcessType_Name = "Mobility Management";

               asn1Init_E2SM_RC_RANFunctionDefinition_EventTrigger_CallProcess_Item_callProcessBreakpoints_List(&callItem2->callProcessBreakpoints_List);

               // Add one CallProcessBreakpoints item[1]
               OSRTDListNode *breakNode2;
               E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item *breakItem2;

               rtxDListAllocNodeAndData(&asn1_ctx,
               E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item,
               &breakNode2, &breakItem2);


               breakItem2->callProcessBreakpoint_ID = 3;
               breakItem2->callProcessBreakpoint_Name = "Handover Resource Allocation";

            // asn1Init_E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item_ran_CallProcessBreakpointParameters_List(&breakItem->ran_CallProcessBreakpointParameters_List);
               rtxDListAppendNode(&callItem2->callProcessBreakpoints_List, breakNode2);           
               rtxDListAppendNode(&p_event_trigger->ran_CallProcessTypes_List, callNode2);

               ver =  asn1PE_E2SM_RC_RANFunctionDefinition_EventTrigger(&asn1_ctx, p_event_trigger);
               printf("\n\n\nver=%d\n\n\n",ver);

            //  asn1Print_E2SM_RC_RANFunctionDefinition_EventTrigger("test2", p_event_trigger);
               // Link event trigger into definition
            p_event->ranFunctionDefinition_EventTrigger = *p_event_trigger;


            //Initialize E2SM_RC_RANFunctionDefinition_Report
            E2SM_RC_RANFunctionDefinition_Report *p_event_report = NULL;
            p_event_report = rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_RANFunctionDefinition_Report);

            if(NULL == p_event_report)
            {
               printf("\n\n\nMemory allocation failed for E2SM-RC event trigger!!\n\n\n");
               response = E2_FAILURE;
               break;
            }

           // asn1Init_E2SM_RC_RANFunctionDefinition_Report(&p_event_report->ric_ReportStyle_List);
            asn1Init_E2SM_RC_RANFunctionDefinition_Report(p_event_report);

            // Add one ReportStyle item
            OSRTDListNode *reportNode;
            E2SM_RC_RANFunctionDefinition_Report_Item *reportItem;

            rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_RANFunctionDefinition_Report_Item,
            &reportNode, &reportItem);

            reportItem->ric_ReportStyle_Type = 1;
            reportItem->ric_ReportStyle_Name = "Message copy";
            reportItem->ric_SupportedEventTriggerStyle_Type = 1;
            reportItem->ric_ReportActionFormat_Type = 1;
            reportItem->ric_IndicationHeaderFormat_Type = 1;
            reportItem->ric_IndicationMessageFormat_Type = 1;

            reportItem->m.ran_ReportParameters_ListPresent = 1;

            //Intialize ran_ReportParameters_List
            asn1Init_E2SM_RC_RANFunctionDefinition_Report_Item_ran_ReportParameters_List(&reportItem->ran_ReportParameters_List);
            //rtxDListInit(&reportItem->ran_ReportParameters_List);

            // Parameter list
               struct {
                  int id;
                  const char* name;
               } params[] = {
                  {6, "NR CGI"},
                  {4, "UE ID"},
                  {3, "RRC message"},
                  {2, "NI Message"}
               };

               int numParams = sizeof(params) / sizeof(params[0]);

               // Initialize list first
               asn1Init_E2SM_RC_RANFunctionDefinition_Report_Item_ran_ReportParameters_List(
                  &reportItem->ran_ReportParameters_List);

               for (int i = 0; i < numParams; i++) {
                  OSRTDListNode *reportParamNode;
                  E2SM_RC_Report_RANParameter_Item *reportParamItem = NULL;

                  // Allocate node + data
                  rtxDListAllocNodeAndData(&asn1_ctx,
                                                E2SM_RC_Report_RANParameter_Item,
                                                &reportParamNode,
                                                &reportParamItem); 

                  // Zero initialize all fields
                  memset(reportParamItem, 0, sizeof(E2SM_RC_Report_RANParameter_Item));

                  // Fill required fields
                  reportParamItem->ranParameter_ID = params[i].id;
                  reportParamItem->ranParameter_name = params[i].name;

                  // Mark optional definition absent
                  reportParamItem->m.ranParameter_DefinitionPresent = 0;

                  // Append node to list
                  rtxDListAppendNode(&reportItem->ran_ReportParameters_List, reportParamNode);
               }


            rtxDListAppendNode(&p_event_report->ric_ReportStyle_List,reportNode);

            //Encode E2SM_RC_RANFunctionDefinition_Report
            memset(p_event_msg,0,E2CU_ASN1_BUFFER_LENGTH);
            if( RT_OK != pu_setBuffer(&asn1_ctx, p_event_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
            {
               printf("\n\npu_setBuffer failed.\n");
               response = E2_FAILURE;
               break;
            }                                  
            else
            printf("\npu_setBuffer success.\n\n");

            ver = asn1PE_E2SM_RC_RANFunctionDefinition_Report(&asn1_ctx, p_event_report);
            printf("\n ver=%d.\n\n",ver);

         // asn1Print_E2SM_RC_RANFunctionDefinition_Report("test3", p_event_report);
            // Link report into definition
            p_event->ranFunctionDefinition_Report = *p_event_report;  
            //  rtxDListAppendNode(&reportParamItem, reportParamNode);
            //rtxDListAppendNode(&reportItem->ran_ReportParameters_List, reportParamNode);
            //rtxDListAppendNode(p_event_report, reportNode);
                     // asn1Print_E2SM_RC_RANFunctionDefinition_Report_Item("test4", reportItem);




            //intialize E2SM_RC_RANFunctionDefinition_Insert 
            E2SM_RC_RANFunctionDefinition_Insert *p_event_insert = NULL;
            p_event_insert = rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_RANFunctionDefinition_Insert); 

            if(NULL == p_event_insert)
            {
               printf("\n\n\nMemory allocation failed for E2SM-RC event insert!!\n\n\n");
               response = E2_FAILURE;
               break;
            }
            rtxDListInit(&p_event_insert->extElem1);
            asn1Init_E2SM_RC_RANFunctionDefinition_Insert_ric_InsertStyle_List(&p_event_insert->ric_InsertStyle_List);

            //Add one insert style item[0]
            OSRTDListNode *insertNode;
            E2SM_RC_RANFunctionDefinition_Insert_Item *insertItem = NULL;
            
            rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_RANFunctionDefinition_Insert_Item,
            &insertNode, &insertItem);

            rtxDListInit(&insertItem->extElem1);

            insertItem->ric_InsertStyle_Type = 4;
            insertItem->ric_InsertStyle_Name = "Radio Access Control Request";
            insertItem->ric_SupportedEventTriggerStyle_Type = 1;
            insertItem->ric_ActionDefinitionFormat_Type = 3;
            insertItem->ric_IndicationHeaderFormat_Type = 2;
            insertItem->ric_IndicationMessageFormat_Type = 5;
            insertItem->ric_CallProcessIDFormat_Type = 1;

            insertItem->m.ric_InsertIndication_ListPresent = 1;
            asn1Init_E2SM_RC_RANFunctionDefinition_Insert_Item_ric_InsertIndication_List(&insertItem->ric_InsertIndication_List);

            //Add one insert indication item
            OSRTDListNode *insertIndicationNode;
            E2SM_RC_RANFunctionDefinition_Insert_Indication_Item *insertIndicationItem = NULL;
            
            rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_RANFunctionDefinition_Insert_Indication_Item,
            &insertIndicationNode, &insertIndicationItem);

            rtxDListInit(&insertIndicationItem->extElem1);
            insertIndicationItem->ric_InsertIndication_ID = 4;
            insertIndicationItem->ric_InsertIndication_Name = "Radio admission control";
            

            insertIndicationItem->m.ran_InsertIndicationParameters_ListPresent = 1;

            
            asn1Init_E2SM_RC_RANFunctionDefinition_Insert_Indication_Item_ran_InsertIndicationParameters_List(&insertIndicationItem->ran_InsertIndicationParameters_List);

               // Define all parameter IDs and names
               struct {
                  int id;
                  const char* name;
               } 
               ranParams[] = {
                  {24, "List of PDU sessions for admission"},
                  {25, "PDU session Item for admission"},
                  {26, "PDU Session ID"},
                  {27, "List of QoS flows in the PDU Session"},
                  {28, "QoS flow Item"},
                  {29, "QoS flow Identifier"},
                  {30, "QoS flow"},
                  {15001, "5QI"},
                  {15004, "NG-RAN DRB Allocation and Retention Priority"},
                  {15005, "Priority Level"},
                  {15006, "Pre-emption Capability"},
                  {15007, "Pre-emption Vulnerability"},
                  {15009, "QoS parameters for GBR flows in NG-RAN Bearer"},
                  {15010, "Maximum Flow Bit Rate Downlink"},
                  {15011, "Guaranteed Flow Bit Rate Downlink"},
                  {15012, "Maximum Packet Loss Rate Downlink"},
                  {15013, "Maximum Flow Bit Rate Uplink"},
                  {15014, "Guaranteed Flow Bit Rate Uplink"}
               };

               int insertNumParams = sizeof(ranParams) / sizeof(ranParams[0]);

               for (int i = 0; i < insertNumParams; i++) {
                  OSRTDListNode *paramNode;
                  E2SM_RC_InsertIndication_RANParameter_Item *paramItem = NULL;

                  rtxDListAllocNodeAndData(&asn1_ctx,
                     E2SM_RC_InsertIndication_RANParameter_Item,
                     &paramNode, &paramItem);

                  // Zero initialize all fields
                  memset(paramItem, 0, sizeof(E2SM_RC_InsertIndication_RANParameter_Item));

                  rtxDListInit(&paramItem->extElem1);
                  paramItem->ranParameter_ID = ranParams[i].id;
                  paramItem->ranParameter_name = ranParams[i].name;

                  // Mark optional definition absent
                  paramItem->m.ranParameter_DefinitionPresent = 0;

                  rtxDListAppendNode(&insertIndicationItem->ran_InsertIndicationParameters_List, paramNode);
               }
            rtxDListAppendNode(&insertItem->ric_InsertIndication_List,insertIndicationNode);

            rtxDListAppendNode(&p_event_insert->ric_InsertStyle_List,insertNode);


            //Add one insert style item[0]
            OSRTDListNode *insertNode1;
            E2SM_RC_RANFunctionDefinition_Insert_Item *insertItem1 = NULL;
            
            rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_RANFunctionDefinition_Insert_Item,
            &insertNode1, &insertItem1);

            insertItem1->ric_InsertStyle_Type = 3;
            insertItem1->ric_InsertStyle_Name = "Connected Mode Mobility Request";
            insertItem1->ric_SupportedEventTriggerStyle_Type = 1;
            insertItem1->ric_ActionDefinitionFormat_Type = 3;
            insertItem1->ric_IndicationHeaderFormat_Type = 2;
            insertItem1->ric_IndicationMessageFormat_Type = 5;
            insertItem1->ric_CallProcessIDFormat_Type = 1;

            insertItem1->m.ric_InsertIndication_ListPresent = 1;
            asn1Init_E2SM_RC_RANFunctionDefinition_Insert_Item_ric_InsertIndication_List(&insertItem1->ric_InsertIndication_List);

            //Add one insert indication item
            OSRTDListNode *insertIndicationNode1;
            E2SM_RC_RANFunctionDefinition_Insert_Indication_Item *insertIndicationItem1 = NULL;
            
            rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_RANFunctionDefinition_Insert_Indication_Item,
            &insertIndicationNode1, &insertIndicationItem1);

            insertIndicationItem1->ric_InsertIndication_ID = 1;
            insertIndicationItem1->ric_InsertIndication_Name = "Handover Control request";

            insertIndicationItem1->m.ran_InsertIndicationParameters_ListPresent = 1;

            
            asn1Init_E2SM_RC_RANFunctionDefinition_Insert_Indication_Item_ran_InsertIndicationParameters_List(&insertIndicationItem1->ran_InsertIndicationParameters_List);

               // Define all parameter IDs and names
               struct {
                  int id;
                  const char* name;
               } 
               ranParam[] = {
                  {7, "List of PDU sessions for handover"},
                  {8, "PDU session Item for handover"},
                  {9, "PDU Session ID"},
                  {10, "List of QoS flows in the PDU Session"},
                  {11, "QoS flow Item"},
                  {12, "QoS flow Identifier"},
                  {22, "QoS flow"},
                  {15001, "5QI"},
                  {15004, "NG-RAN DRB Allocation and Retention Priority"},
                  {15005, "Priority Level"},
                  {15006, "Pre-emption Capability"},
                  {15007, "Pre-emption Vulnerability"},
                  {15009, "QoS parameters for GBR flows in NG-RAN Bearer"},
                  {15010, "Maximum Flow Bit Rate Downlink"},
                  {15011, "Guaranteed Flow Bit Rate Downlink"},
                  {15012, "Maximum Packet Loss Rate Downlink"},
                  {15013, "Maximum Flow Bit Rate Uplink"},
                  {15014, "Guaranteed Flow Bit Rate Uplink"}
               };

               int insertNumParam = sizeof(ranParam) / sizeof(ranParam[0]);

               for (int i = 0; i < insertNumParam; i++) {
                  OSRTDListNode *paramNode;
                  E2SM_RC_InsertIndication_RANParameter_Item *paramItem = NULL;

                  rtxDListAllocNodeAndData(&asn1_ctx,
                     E2SM_RC_InsertIndication_RANParameter_Item,
                     &paramNode, &paramItem);

                  // Zero initialize all fields
                  memset(paramItem, 0, sizeof(E2SM_RC_InsertIndication_RANParameter_Item));

                  //asn1Init_E2SM_RC_InsertIndication_RANParameter_Item(paramItem); 

                  paramItem->ranParameter_ID = ranParam[i].id;
                  paramItem->ranParameter_name = ranParam[i].name;

                  // Mark optional definition absent
                  paramItem->m.ranParameter_DefinitionPresent = 0;

                  rtxDListAppendNode(&insertIndicationItem1->ran_InsertIndicationParameters_List, paramNode);
               }
               rtxDListAppendNode(&insertItem1->ric_InsertIndication_List,insertIndicationNode1);

            rtxDListAppendNode(&p_event_insert->ric_InsertStyle_List,insertNode1);

            ver = asn1PE_E2SM_RC_RANFunctionDefinition_Insert(&asn1_ctx, p_event_insert);
            printf("\n ver=%d.\n\n",ver);

            // Encode E2SM_RC_RANFunctionDefinition_Insert
            memset(p_event_msg,0,E2CU_ASN1_BUFFER_LENGTH);
            if( RT_OK != pu_setBuffer(&asn1_ctx, p_event_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
            {
               printf("\n\npu_setBuffer failed.\n");
               response = E2_FAILURE;
               break;
            }
            else             
               printf("\npu_setBuffer success.\n\n");

            //asn1Print_E2SM_RC_RANFunctionDefinition_Insert("test4", p_event_insert);

            p_event->ranFunctionDefinition_Insert = *p_event_insert;




            //inatialize E2SM_RC_RANFunctionDefinition_Control

            E2SM_RC_RANFunctionDefinition_Control *p_event_control = NULL;


            p_event_control = rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_RANFunctionDefinition_Control);

            if(NULL == p_event_control)
            {
               printf("\n\n\nMemory allocation failed for E2SM-RC event trigger!!\n\n\n");
               response = E2_FAILURE;
               break;
            }

            asn1Init_E2SM_RC_RANFunctionDefinition_Control_ric_ControlStyle_List(&p_event_control->ric_ControlStyle_List);

               // Add one ControlStyle item[0]
               OSRTDListNode *controlNode;
               E2SM_RC_RANFunctionDefinition_Control_Item *controlItem;

               rtxDListInit(&p_event_control->extElem1);
               rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_RANFunctionDefinition_Control_Item,
               &controlNode, &controlItem);

               rtxDListInit(&controlItem->extElem1);
               controlItem->ric_ControlStyle_Type = 3;
               controlItem->ric_ControlStyle_Name = "Connected mode mobility control";
               controlItem->ric_ControlHeaderFormat_Type = 1;
               controlItem->ric_ControlMessageFormat_Type = 1;
               controlItem->ric_ControlOutcomeFormat_Type = 1;

               controlItem->m.ric_ControlAction_ListPresent = 1;
               controlItem->m.ran_ControlOutcomeParameters_ListPresent = 1;

               asn1Init_E2SM_RC_RANFunctionDefinition_Control_Item_ric_ControlAction_List(&controlItem->ric_ControlAction_List);

               // Add one ControlAction item
               OSRTDListNode *actionNode;
               E2SM_RC_RANFunctionDefinition_Control_Action_Item *actionItem;

               rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_RANFunctionDefinition_Control_Action_Item,
               &actionNode, &actionItem);
               rtxDListInit(&actionItem->extElem1);

                  actionItem->ric_ControlAction_ID = 1;
                  actionItem->ric_ControlAction_Name = "Handover Control";

                  actionItem->m.ran_ControlActionParameters_ListPresent = 1;
                  asn1Init_E2SM_RC_RANFunctionDefinition_Control_Action_Item_ran_ControlActionParameters_List(&actionItem->ran_ControlActionParameters_List);

                  // Define all parameter IDs and names
                  struct{
                     int id;
                     const char* name;
                  } 
                  rancontrolparams[] = {
                  {7, "List of PDU sessions for handover"},
                  {8, "PDU session Item for handover"},
                  {9, "PDU Session ID"},
                  {10, "List of QoS flows in the PDU Session"},
                  {11, "QoS flow Item"},
                  {12, "QoS flow Identifier"},
                  {22, "QoS flow"},
                  {15001, "5QI"},
                  {15004, "NG-RAN DRB Allocation and Retention Priority"},
                  {15005, "Priority Level"},
                  {15006, "Pre-emption Capability"},
                  {15007, "Pre-emption Vulnerability"},
                  {15009, "QoS parameters for GBR flows in NG-RAN Bearer"},
                  {15010, "Maximum Flow Bit Rate Downlink"},
                  {15011, "Guaranteed Flow Bit Rate Downlink"},
                  {15012, "Maximum Packet Loss Rate Downlink"},
                  {15013, "Maximum Flow Bit Rate Uplink"},
                  {15014, "Guaranteed Flow Bit Rate Uplink"}
               };

               int controlNUmParams = sizeof(rancontrolparams) / sizeof(rancontrolparams[0]);

               for (int i = 0; i < controlNUmParams; i++) {
                  OSRTDListNode *paramNode;
                  E2SM_RC_ControlAction_RANParameter_Item *paramItem = NULL;

                  rtxDListAllocNodeAndData(&asn1_ctx,
                     E2SM_RC_ControlAction_RANParameter_Item,
                     &paramNode, &paramItem);

                  // Zero initialize all fields
                  memset(paramItem, 0, sizeof(E2SM_RC_ControlAction_RANParameter_Item));

                  
                  rtxDListInit(&paramItem->extElem1);
                  paramItem->ranParameter_ID = rancontrolparams[i].id;
                  paramItem->ranParameter_name = rancontrolparams[i].name;

                  // Mark optional definition absent
                  paramItem->m.ranParameter_DefinitionPresent = 0;

                  rtxDListAppendNode(&actionItem->ran_ControlActionParameters_List, paramNode);
               }

               rtxDListAppendNode(&controlItem->ric_ControlAction_List,actionNode);

               asn1Init_E2SM_RC_RANFunctionDefinition_Control_Item_ran_ControlOutcomeParameters_List(&controlItem->ran_ControlOutcomeParameters_List);

               // Add one ControlAction item
               OSRTDListNode *outcomeNode;
               E2SM_RC_ControlOutcome_RANParameter_Item *outcomeItem;

               rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_ControlOutcome_RANParameter_Item,
               &outcomeNode, &outcomeItem);
               rtxDListInit(&outcomeItem->extElem1);

                  outcomeItem->ranParameter_ID = 1;
                  outcomeItem->ranParameter_name = "ReceivedTimestamp";

                  outcomeItem->m.ranParameter_DefinitionPresent = 0;
                  rtxDListAppendNode(&controlItem->ran_ControlOutcomeParameters_List, outcomeNode);

            rtxDListAppendNode(&p_event_control->ric_ControlStyle_List,controlNode);


            // Add one ControlStyle item[0]
               OSRTDListNode *controlNode1;
               E2SM_RC_RANFunctionDefinition_Control_Item *controlItem1;

               rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_RANFunctionDefinition_Control_Item,
               &controlNode1, &controlItem1);

               controlItem1->ric_ControlStyle_Type = 4;
               controlItem1->ric_ControlStyle_Name = "Radio Access Control";
               controlItem1->ric_ControlHeaderFormat_Type = 1;
               controlItem1->ric_ControlMessageFormat_Type = 1;
               controlItem1->ric_ControlOutcomeFormat_Type = 1;

               controlItem1->m.ric_ControlAction_ListPresent = 1;
               controlItem1->m.ran_ControlOutcomeParameters_ListPresent = 1;

               asn1Init_E2SM_RC_RANFunctionDefinition_Control_Item_ric_ControlAction_List(&controlItem1->ric_ControlAction_List);

               // Add one ControlAction item
               OSRTDListNode *actionNode1;
               E2SM_RC_RANFunctionDefinition_Control_Action_Item *actionItem1;

               rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_RANFunctionDefinition_Control_Action_Item,
               &actionNode1, &actionItem1);

                  actionItem1->ric_ControlAction_ID = 1;
                  actionItem1->ric_ControlAction_Name = "UE Admission Control";

                  actionItem1->m.ran_ControlActionParameters_ListPresent = 1;
                  asn1Init_E2SM_RC_RANFunctionDefinition_Control_Action_Item_ran_ControlActionParameters_List(&actionItem1->ran_ControlActionParameters_List);


                  // Define all parameter IDs and names
                  struct{
                     int id;
                     const char* name;
                  } 
                  rancontrolparam[] = {
                  {24, "List of PDU sessions for admission"},
                  {25, "PDU session Item for admission"},
                  {26, "PDU Session ID"},
                  {27, "List of QoS flows in the PDU Session"},
                  {28, "QoS flow Item"},
                  {29, "QoS flow Identifier"},
                  {30, "QoS flow"},
                  {15001, "5QI"},
                  {15004, "NG-RAN DRB Allocation and Retention Priority"},
                  {15005, "Priority Level"},
                  {15006, "Pre-emption Capability"},
                  {15007, "Pre-emption Vulnerability"},
                  {15009, "QoS parameters for GBR flows in NG-RAN Bearer"},
                  {15010, "Maximum Flow Bit Rate Downlink"},
                  {15011, "Guaranteed Flow Bit Rate Downlink"},
                  {15012, "Maximum Packet Loss Rate Downlink"},
                  {15013, "Maximum Flow Bit Rate Uplink"},
                  {15014, "Guaranteed Flow Bit Rate Uplink"}
               };

               int controlNUmParam = sizeof(rancontrolparam) / sizeof(rancontrolparam[0]);

               for (int i = 0; i < controlNUmParam; i++) {
                  OSRTDListNode *paramNode;
                  E2SM_RC_ControlAction_RANParameter_Item *paramItem = NULL;

                  rtxDListAllocNodeAndData(&asn1_ctx,
                     E2SM_RC_ControlAction_RANParameter_Item,
                     &paramNode, &paramItem);
                  // Zero initialize all fields
                  memset(paramItem, 0, sizeof(E2SM_RC_ControlAction_RANParameter_Item));


                  rtxDListInit(&paramItem->extElem1);
                  paramItem->ranParameter_ID = rancontrolparam[i].id;
                  paramItem->ranParameter_name = rancontrolparam[i].name;

                  // Mark optional definition absent
                  paramItem->m.ranParameter_DefinitionPresent = 0;


                  rtxDListAppendNode(&actionItem1->ran_ControlActionParameters_List, paramNode);
               }

               rtxDListAppendNode(&controlItem1->ric_ControlAction_List,actionNode1);

               asn1Init_E2SM_RC_RANFunctionDefinition_Control_Item_ran_ControlOutcomeParameters_List(&controlItem1->ran_ControlOutcomeParameters_List);

               // Add one ControlAction item
               OSRTDListNode *outcomeNode1;
               E2SM_RC_ControlOutcome_RANParameter_Item *outcomeItem1;

               rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_ControlOutcome_RANParameter_Item,
               &outcomeNode1, &outcomeItem1);

                  outcomeItem1->ranParameter_ID = 1;
                  outcomeItem1->ranParameter_name = "ReceivedTimestamp";

               rtxDListAppendNode(&controlItem1->ran_ControlOutcomeParameters_List, outcomeNode1);

            rtxDListAppendNode(&p_event_control->ric_ControlStyle_List,controlNode1);

            ver = asn1PE_E2SM_RC_RANFunctionDefinition_Control(&asn1_ctx, p_event_control);
            printf("\n ver=%d.\n\n",ver);
            // Encode E2SM_RC_RANFunctionDefinition_Insert
            memset(p_event_msg,0,E2CU_ASN1_BUFFER_LENGTH);
            if( RT_OK != pu_setBuffer(&asn1_ctx, p_event_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
            {
               printf("\n\npu_setBuffer failed.\n");
               response = E2_FAILURE;
               break;
            }
            else             
               printf("\npu_setBuffer success.\n\n");

               


            //asn1Print_E2SM_RC_RANFunctionDefinition_Control("test5", p_event_control);

            p_event->ranFunctionDefinition_Control = *p_event_control;

            // Encode E2SM_RC_RANFunctionDefinition_Insert
            memset(p_event_msg,0,E2CU_ASN1_BUFFER_LENGTH);
            if( RT_OK != pu_setBuffer(&asn1_ctx, p_event_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
            {
               printf("\n\npu_setBuffer failed.\n");
               response = E2_FAILURE;
               break;
            }
            else             
               printf("\npu_setBuffer success.\n\n");
            int a=0;
            ver =asn1PE_E2SM_RC_RANFunctionDefinition(&asn1_ctx, p_event);
            printf("\n ver=%d.\n\n",ver);

            asn1Print_E2SM_RC_RANFunctionDefinition("ranfunction", p_event);

            // Encode E2SM_RC_RANFunctionDefinition_Insert
            memset(p_event_msg,0,E2CU_ASN1_BUFFER_LENGTH);
            if( RT_OK != pu_setBuffer(&asn1_ctx, p_event_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
            {
               printf("\n\npu_setBuffer failed.\n");
               response = E2_FAILURE;
               break;
            }
            else             
            printf("\npu_setBuffer success.\n\n");
            a=asn1PE_E2SM_RC_RANFunctionDefinition(&asn1_ctx,p_event);
            printf("\n\n===asn1PE_E2SM_RC_EventTrigger===a=%d===========\n",a);
            *p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
            printf("p_event_msg_len :%d\n\n",*p_event_msg_len);
            //	printf("p_event_msg : %x\n\n",*p_event_msg);
            for(a=0; a< ((*p_event_msg_len)); a ++)
            {
               fprintf(stderr, "%02x ", p_event_msg[a]);
            }
            a=0;
               fprintf(stderr, "\n");
            *p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
            e2ap_func_id->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionDefinition.data = p_event_msg;
            e2ap_func_id->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionDefinition.numocts = *p_event_msg_len;
         //  UInt8  *ran_func_def_buf = NULL;
         // UInt16  ran_func_def_len = 0;
          //  /* ranFunctionDefinition is OCTET STRING */
         //e2ap_func_id->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionDefinition.data = (OSOCTET *)ran_func_def_buf;
         //e2ap_func_id->value.u._e2ap_RANfunction_ItemIEs_1 ->ranFunctionDefinition.numocts = ran_func_def_len;

            //abort();
          //  rtxDListAppendNode(&e2ap_func_id->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionDefinition,def_node);
         }
         e2ap_func_id->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionRevision = 1;
         e2ap_func_id->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionOID = "1.3.6.1.4.1.53148.1.1.2.3";
         

         rtxDListAppendNode (p_value_ie3,
            fun_id);

      if (RT_OK != asn1Append_e2ap_E2setupRequest_protocolIEs_3(&asn1_ctx,&p_asn_e2_setup_request->protocolIEs,p_value_ie3))
      {
       //  GNB_TRACE(GNB_ERROR, "Failed to Add IE3 !!");
        printf("\n\n\nFailed to Add IE3 !!\n\n\n"); 
	     response = E2_FAILURE;
         break;
      }
       //  GNB_TRACE(GNB_INFO, " IE3 encoded");

      printf("\n\n\n IE3 encoded\n\n\n");




        

    

      e2ap_E2nodeComponentConfigAddition_List *p_value_ie4 = NULL;
      p_value_ie4 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2nodeComponentConfigAddition_List);
      //memset(p_value_ie3,0,sizeof(e2ap_RANfunctionsID_List));

      if(NULL == p_value_ie4)
      {
       //  GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
        printf("\n\n\nMemory allocation failed !!\n\n\n"); 
	     response = E2_FAILURE;
        break;
      } 

      OSRTDListNode  *Node1 = NULL;
      e2ap_E2nodeComponentConfigAddition_List_element  *e2ap_e2node = NULL;

      //OSRTDListNode *comp_node;
      //e2ap_E2nodeComponentConfiguration *comp_item = NULL;

      //rtxDListInit(p_value_ie3);
      asn1Init_e2ap_E2nodeComponentConfigAddition_List(p_value_ie4);
      
      int loop1 =0 ;
      for (loop1 = 0 ; loop1 < 1 ; loop1++ ){  
         rtxDListAllocNodeAndData(&asn1_ctx,
            e2ap_E2nodeComponentConfigAddition_List_element,
               &Node1, &e2ap_e2node);
        //memset(e2ap_func_id ,0,sizeof(e2ap_RANfunctionsID_List_element));

         e2ap_e2node->id = 50;
         e2ap_e2node->criticality = 0;
         e2ap_e2node->value.t = T30e2ap___e2ap_E2nodeComponentConfigAddition_ItemIEs_1;
         e2ap_e2node->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2nodeComponentConfigAddition_Item);
         e2ap_e2node->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1->e2nodeComponentInterfaceType = e2ap_f1;
         e2ap_e2node->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1->e2nodeComponentID.t = 
            T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeF1;
         e2ap_e2node->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1->e2nodeComponentID.u.e2nodeComponentInterfaceTypeF1 =
            rtxMemAllocTypeZ(&asn1_ctx, e2ap_E2nodeComponentInterfaceF1);
         e2ap_e2node->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1->e2nodeComponentID.u.e2nodeComponentInterfaceTypeF1->gNB_DU_ID = 1;

        // rtxDListInit(&e2ap_e2node->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1->e2nodeComponentConfiguration);
        // asn1Init_e2ap_RANfunctionDefinition(&e2ap_e2node->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1->e2nodeComponentConfiguration);

           // Step 2 — Initialize the configuration list
        //rtxDListInit(&e2ap_e2node->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1->e2nodeComponentConfiguration);
        //asn1Init_e2ap_E2nodeComponentConfiguration(&e2ap_e2node->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1->e2nodeComponentConfiguration);

 
            
            
         //rtxDListAllocNodeAndData(&asn1_ctx,
                     //    e2ap_E2nodeComponentConfiguration, 
                       //  &comp_node,
                       //  &comp_item);
 
        // e2ap_E2nodeComponentConfiguration *comp_item = NULL;
         //  comp_item = rtxMemAllocTypeZ(&asn1_ctx, e2ap_E2nodeComponentConfiguration);

         //if (comp_item == NULL) {
          //  printf("Memory allocation failed for E2nodeComponentConfiguration!\n");
           // response = E2_FAILURE;
           // break;
        // }
       //  printf("comp_node : %p\n",comp_node);

         /* Initialize structure */
         //asn1Init_e2ap_E2nodeComponentConfiguration(comp_item);


         


         //comp_item->e2nodeComponentRequestPart.numocts = 61;
         //comp_item->e2nodeComponentRequestPart.data;


        // int m;
			//m=(asn1PE_e2ap_E2nodeComponentConfiguration,&asn1_ctx,comp_item);                                 
         //   			printf("\nasn1PE_e2ap_E2nodeComponentConfiguration=%d.\n",m);
        	//	*p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);

          e2ap_e2node->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1
        ->e2nodeComponentConfiguration.e2nodeComponentRequestPart.numocts = 60;
           e2ap_e2node->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1
        ->e2nodeComponentConfiguration.e2nodeComponentRequestPart.data = p_event_msg;
				

         printf("\n\npu_setBuffer success.\n");

         //request part data (61 bytes)
        // *p_event_msg="00150038000004001b00090000f11050000000d10052400b0400354720674e422d43550066001000000031320000f110000010080102030015400100";
         p_event_msg[0] = 0;
         p_event_msg[1] = 21;
         p_event_msg[2] = 0;
         p_event_msg[3] = 56;
         p_event_msg[4] = 0;
         p_event_msg[5] = 0;
         p_event_msg[6] = 4;
         p_event_msg[7] = 0;                         
         p_event_msg[8] = 27;
         p_event_msg[9] = 0;
         p_event_msg[10] = 9;
         p_event_msg[11] = 0;
         p_event_msg[12] = 0;
         p_event_msg[13] = 241;
         p_event_msg[14] = 16;
         p_event_msg[15] = 80;
         p_event_msg[16] = 0;
         p_event_msg[17] = 0;
         p_event_msg[18] = 0;
         p_event_msg[19] = 209;
         p_event_msg[20] = 0;
         p_event_msg[21] = 82;
         p_event_msg[22] = 64;
         p_event_msg[23] = 11;
         p_event_msg[24] = 4;
         p_event_msg[25] = 0;
         p_event_msg[26] = 53;
         p_event_msg[27] = 71;
         p_event_msg[28] = 32;
         p_event_msg[29] = 103;
         p_event_msg[30] = 78;
         p_event_msg[31] = 66;
         p_event_msg[32] = 45;
         p_event_msg[33] = 67;
         p_event_msg[34] = 85;
         p_event_msg[35] = 0;
         p_event_msg[36] = 102;
         p_event_msg[37] = 0;
         p_event_msg[38] = 16;
         p_event_msg[39] = 0;
         p_event_msg[40] = 0;
         p_event_msg[41] = 0;
         p_event_msg[42] = 49;
         p_event_msg[43] = 50;
         p_event_msg[44] = 0;
         p_event_msg[45] = 0;
         p_event_msg[46] = 241;
         p_event_msg[47] = 16;
         p_event_msg[48] = 0;
         p_event_msg[49] = 0;
         p_event_msg[50] = 16;
         p_event_msg[51] = 8;
         p_event_msg[52] = 1;
         p_event_msg[53] = 2;
         p_event_msg[54] = 3;
         p_event_msg[55] = 0;
         p_event_msg[56] = 21;
         p_event_msg[57] = 64;
         p_event_msg[58] = 1;
         p_event_msg[59] = 0;

         // Debug print request part
         int b;
         fprintf(stderr, "Request Part (60 bytes): ");
         for (b = 0; b < 60; b++) {
            fprintf(stderr, "%02x ", p_event_msg[b]);
         }
         b=0;
         fprintf(stderr, "\n");




        // e2ap_e2node->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1
       // ->e2nodeComponentConfiguration.e2nodeComponentRequestPart.data = (OSOCTET *)p_event_msg;

       // e2ap_e2node->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1
       // ->e2nodeComponentConfiguration.e2nodeComponentRequestPart.numocts = 60;

       //  printf("DEBUG: RequestPart assigned - numocts=%d, data=%p\n", 
              // comp_item->e2nodeComponentRequestPart.numocts,
              // comp_item->e2nodeComponentRequestPart.data);


         
            
         //response part data (58 bytes)
        // *p_event_msg1 = "201500350000040001000e05806f70656e3567732d616d663000600008000000f11002004000564001ff0050000b0000f11000001000000000";
         p_event_msg1[0] = 32;
         p_event_msg1[1] = 21;
         p_event_msg1[2] = 0;                      
         p_event_msg1[3] = 53;
         p_event_msg1[4] = 0;
         p_event_msg1[5] = 0;
         p_event_msg1[6] = 4;
         p_event_msg1[7] = 0;
         p_event_msg1[8] = 1;
         p_event_msg1[9] = 0;
         p_event_msg1[10] = 14;
         p_event_msg1[11] = 5;
         p_event_msg1[12] = 128;
         p_event_msg1[13] = 111;
         p_event_msg1[14] = 112;
         p_event_msg1[15] = 101;
         p_event_msg1[16] = 110;
         p_event_msg1[17] = 53;
         p_event_msg1[18] = 103;
         p_event_msg1[19] = 115;
         p_event_msg1[20] = 45;
         p_event_msg1[21] = 97;
         p_event_msg1[22] = 109;
         p_event_msg1[23] = 102;
         p_event_msg1[24] = 48;
         p_event_msg1[25] = 0;
         p_event_msg1[26] = 96;
         p_event_msg1[27] = 0;
         p_event_msg1[28] = 8;
         p_event_msg1[29] = 0;
         p_event_msg1[30] = 0;
         p_event_msg1[31] = 0;
         p_event_msg1[32] = 241;
         p_event_msg1[33] = 16;
         p_event_msg1[34] = 2;
         p_event_msg1[35] = 0;
         p_event_msg1[36] = 64;
         p_event_msg1[37] = 0;
         p_event_msg1[38] = 86;
         p_event_msg1[39] = 64;
         p_event_msg1[40] = 1;
         p_event_msg1[41] = 255;
         p_event_msg1[42] = 0;
         p_event_msg1[43] = 80;
         p_event_msg1[44] = 0;
         p_event_msg1[45] = 11;
         p_event_msg1[46] = 0;
         p_event_msg1[47] = 0;
         p_event_msg1[48] = 241;
         p_event_msg1[49] = 16;
         p_event_msg1[50] = 0;
         p_event_msg1[51] = 0;
         p_event_msg1[52] = 16;
         p_event_msg1[53] = 0;
         p_event_msg1[54] = 0;
         p_event_msg1[55] = 0;
         p_event_msg1[56] = 0;
       //  p_event_msg1[57] = 0;

         // Debug print response part
         fprintf(stderr, "Response Part (57 bytes): ");
         for (int c = 0; c < 57; c++) {
            fprintf(stderr, "%02x ", p_event_msg1[c]);
         }
         fprintf(stderr, "\n");

         // Assign response part - MUST set numocts BEFORE data pointer
        // comp_item->e2nodeComponentResponsePart.numocts = 58;
         //comp_item->e2nodeComponentResponsePart.data = (OSOCTET *)p_event_msg1;


         e2ap_e2node->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1
        ->e2nodeComponentConfiguration.e2nodeComponentResponsePart.data = (OSOCTET *)p_event_msg1;

        e2ap_e2node->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1
       ->e2nodeComponentConfiguration.e2nodeComponentResponsePart.numocts = 57;

        


        // printf("DEBUG: ResponsePart assigned - numocts=%d, data=%p\n", 
             //  comp_item->e2nodeComponentResponsePart.numocts,
             //  comp_item->e2nodeComponentResponsePart.data);

         // Verify assignments before appending
         //if (comp_item->e2nodeComponentRequestPart.data == NULL || 
          //  comp_item->e2nodeComponentResponsePart.data == NULL) {
          //  printf("ERROR: Data pointers are NULL after assignment!\n");
           // response = E2_FAILURE;
           // break;
         //}


         //rtxDListAppendNode(&e2ap_e2node->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1->e2nodeComponentConfiguration, comp_node);

      }
     // asn1Print_e2ap_E2nodeComponentConfigAddition_List_element("test1",e2ap_e2node);
      rtxDListAppendNode (p_value_ie4,
            Node1);
         asn1Print_e2ap_E2nodeComponentConfigAddition_List("e2node",p_value_ie4);
      if (RT_OK != asn1Append_e2ap_E2setupRequest_protocolIEs_4(&asn1_ctx,&p_asn_e2_setup_request->protocolIEs,p_value_ie4))
      {
       //  GNB_TRACE(GNB_ERROR, "Failed to Add IE4 !!");
        printf("\n\n\nFailed to Add IE4 !!\n\n\n"); 
        response = E2_FAILURE;
        break;
      }
      printf("\n\n\n IE4 encoded\n\n\n");



      /* ASN Encode message */
        if( RT_OK != pu_setBuffer(&asn1_ctx, p_asn_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
        {
          //  GNB_TRACE(GNB_ERROR,"pu_setBuffer failed.");
            response = E2_FAILURE;
            break;
         }
        asn1PrtToStrm_e2ap_E2AP_PDU(&asn1_ctx, "e2ap_pdu", &e2ap_pdu);
        // GNB_TRACE(GNB_INFO, " After pu_setBuffer");
         if (0 != asn1PE_e2ap_E2AP_PDU(&asn1_ctx, &e2ap_pdu))
         {
            rtxErrPrint(&asn1_ctx);
          //  GNB_TRACE(GNB_INFO, "ASN1 encoding of E2 Setup Request failed.");
            response = E2_FAILURE;
            break;
         }

         else
         {
            *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
             if(RT_OK == asn1PrtToStrm_e2ap_E2AP_PDU(&asn1_ctx, "e2ap_pdu", &e2ap_pdu))
             {
               // GNB_TRACE(GNB_INFO, "asn1PrtToStrm_e2ap_E2AP_PDU success !!");
                printf("\n\n\nasn1PrtToStrm_e2ap_E2AP_PDU success !!\n\n\n");
                response = E2_SUCCESS;
             }
             else
             {
                //GNB_TRACE(GNB_INFO, "asn1PrtToStrm_e2ap_E2AP_PDU failure !!");
                printf("\n\n\nasn1PrtToStrm_e2ap_E2AP_PDU failure !!\n\n\n");
                response = E2_FAILURE;
             }
         }

         /* testing purpose printing HEX DUMP */
            int i;
            fprintf(stderr, "value of p_asn_msg_len is %d \n", *p_asn_msg_len);
            for(i=0; i< *p_asn_msg_len; i ++)
            {
                  fprintf(stderr, "%02x ", p_asn_msg[i]);

            }
         //   *p_asn_msg_len = 3115;
         //   p_asn_msg  = (UInt16 *)"00 01 00 8c 26 00 00 04 00 31 00 02 00 01 00 03 00 09 00 00 f1 10 50 00 00 00 d0 00 0a 00 8b 5e 00 00 08 40 8b 58 00 00 02 8b 35 78 05 80 4f 52 41 4e 2d 45 32 53 4d 2d 52 43 00 00 18 31 2e 33 2e 36 2e 31 2e 34 2e 31 2e 35 33 31 34 38 2e 31 2e 31 2e 32 2e 33 05 00 52 41 4e 20 43 6f 6e 74 72 6f 6c 20 20 01 01 06 00 4d 65 73 73 61 67 65 20 45 76 65 6e 74 01 01 00 01 02 0b 80 43 61 6c 6c 20 50 72 6f 63 65 73 73 20 62 72 65 61 6b 20 70 6f 69 6e 74 01 02 00 02 00 00 05 0a 80 50 44 55 20 53 65 73 73 69 6f 6e 20 4d 61 6e 61 67 65 6d 65 6e 74 00 00 00 00 00 0c 80 50 44 55 20 53 65 73 73 69 6f 6e 20 52 65 73 6f 75 72 63 65 20 53 65 74 75 70 00 00 00 0a 00 55 45 20 43 6f 6e 74 65 78 74 20 4d 61 6e 61 67 65 6d 65 6e 74 00 00 00 00 00 07 80 55 45 20 43 6f 6e 74 65 78 74 20 53 65 74 75 70 00 00 02 09 00 4d 6f 62 69 6c 69 74 79 20 4d 61 6e 61 67 65 6d 65 6e 74 00 00 00 00 02 0d 80 48 61 6e 64 6f 76 65 72 20 52 65 73 6f 75 72 63 65 20 41 6c 6c 6f 63 61 74 69 6f 6e 00 80 01 01 05 80 4d 65 73 73 61 67 65 20 63 6f 70 79 01 01 01 01 01 01 01 01 00 03 00 05 02 80 4e 52 20 43 47 49 00 03 02 00 55 45 20 49 44 00 02 05 00 52 52 43 20 6d 65 73 73 61 67 65 00 01 04 80 4e 49 20 4d 65 73 73 61 67 65 02 80 01 04 0d 80 52 61 64 69 6f 20 41 63 63 65 73 73 20 43 6f 6e 74 72 6f 6c 20 52 65 71 75 65 73 74 01 01 01 03 00 00 40 00 03 0b 00 52 61 64 69 6f 20 61 64 6d 69 73 73 69 6f 6e 20 63 6f 6e 74 72 6f 6c 00 11 00 17 10 80 4c 69 73 74 20 6f 66 20 50 44 55 20 73 65 73 73 69 6f 6e 73 20 66 6f 72 20 61 64 6d 69 73 73 69 6f 6e 00 18 0e 80 50 44 55 20 73 65 73 73 69 6f 6e 20 49 74 65 6d 20 66 6f 72 20 61 64 6d 69 73 73 69 6f 6e 00 19 06 80 50 44 55 20 53 65 73 73 69 6f 6e 20 49 44 00 1a 11 80 4c 69 73 74 20 6f 66 20 51 6f 53 20 66 6c 6f 77 73 20 69 6e 20 74 68 65 20 50 44 55 20 53 65 73 73 69 6f 6e 00 1b 06 00 51 6f 53 20 66 6c 6f 77 20 49 74 65 6d 00 1c 09 00 51 6f 53 20 66 6c 6f 77 20 49 64 65 6e 74 69 66 69 65 72 00 1d 03 80 51 6f 53 20 66 6c 6f 77 10 3a 98 01 80 35 51 49 20 10 3a 9b 15 80 4e 47 2d 52 41 4e 20 44 52 42 20 41 6c 6c 6f 63 61 74 69 6f 6e 20 61 6e 64 20 52 65 74 65 6e 74 69 6f 6e 20 50 72 69 6f 72 69 74 79 10 3a 9c 06 80 50 72 69 6f 72 69 74 79 20 4c 65 76 65 6c 10 3a 9d 0a 80 50 72 65 2d 65 6d 70 74 69 6f 6e 20 43 61 70 61 62 69 6c 69 74 79 10 3a 9e 0e 00 50 72 65 2d 65 6d 70 74 69 6f 6e 20 56 75 6c 6e 65 72 61 62 69 6c 69 74 79 20 20 20 20 10 3a a0 16 00 51 6f 53 20 70 61 72 61 6d 65 74 65 72 73 20 66 6f 72 20 47 42 52 20 66 6c 6f 77 73 20 69 6e 20 4e 47 2d 52 41 4e 20 42 65 61 72 65 72 10 3a a1 0e 80 4d 61 78 69 6d 75 6d 20 46 6c 6f 77 20 42 69 74 20 52 61 74 65 20 44 6f 77 6e 6c 69 6e 6b 10 3a a2 10 00 47 75 61 72 61 6e 74 65 65 64 20 46 6c 6f 77 20 42 69 74 20 52 61 74 65 20 44 6f 77 6e 6c 69 6e 6b 10 3a a3 10 00 4d 61 78 69 6d 75 6d 20 50 61 63 6b 65 74 20 4c 6f 73 73 20 52 61 74 65 20 44 6f 77 6e 6c 69 6e 6b 10 3a a4 0d 80 4d 61 78 69 6d 75 6d 20 46 6c 6f 77 20 42 69 74 20 52 61 74 65 20 55 70 6c 69 6e 6b 10 3a a5 0f 00 47 75 61 72 61 6e 74 65 65 64 20 46 6c 6f 77 20 42 69 74 20 52 61 74 65 20 55 70 6c 69 6e 6b 01 02 01 05 01 01 40 01 03 0f 00 43 6f 6e 6e 65 63 74 65 64 20 4d 6f 64 65 20 4d 6f 62 69 6c 69 74 79 20 52 65 71 75 65 73 74 01 01 01 03 00 00 40 00 00 0b 80 48 61 6e 64 6f 76 65 72 20 43 6f 6e 74 72 6f 6c 20 72 65 71 75 65 73 74 00 11 00 06 10 00 4c 69 73 74 20 6f 66 20 50 44 55 20 73 65 73 73 69 6f 6e 73 20 66 6f 72 20 68 61 6e 64 6f 76 65 72 00 07 0e 00 50 44 55 20 73 65 73 73 69 6f 6e 20 49 74 65 6d 20 66 6f 72 20 68 61 6e 64 6f 76 65 72 00 08 06 80 50 44 55 20 53 65 73 73 69 6f 6e 20 49 44 00 09 11 80 4c 69 73 74 20 6f 66 20 51 6f 53 20 66 6c 6f 77 73 20 69 6e 20 74 68 65 20 50 44 55 20 53 65 73 73 69 6f 6e 00 0a 06 00 51 6f 53 20 66 6c 6f 77 20 49 74 65 6d 00 0b 09 00 51 6f 53 20 66 6c 6f 77 20 49 64 65 6e 74 69 66 69 65 72 00 15 03 80 51 6f 53 20 66 6c 6f 77 10 3a 98 01 80 35 51 49 20 10 3a 9b 15 80 4e 47 2d 52 41 4e 20 44 52 42 20 41 6c 6c 6f 63 61 74 69 6f 6e 20 61 6e 64 20 52 65 74 65 6e 74 69 6f 6e 20 50 72 69 6f 72 69 74 79 10 3a 9c 06 80 50 72 69 6f 72 69 74 79 20 4c 65 76 65 6c 10 3a 9d 0a 80 50 72 65 2d 65 6d 70 74 69 6f 6e 20 43 61 70 61 62 69 6c 69 74 79 10 3a 9e 0c 00 50 72 65 2d 65 6d 70 74 69 6f 6e 20 56 75 6c 6e 65 72 61 62 69 6c 69 74 79 10 3a a0 16 00 51 6f 53 20 70 61 72 61 6d 65 74 65 72 73 20 66 6f 72 20 47 42 52 20 66 6c 6f 77 73 20 69 6e 20 4e 47 2d 52 41 4e 20 42 65 61 72 65 72 10 3a a1 0e 80 4d 61 78 69 6d 75 6d 20 46 6c 6f 77 20 42 69 74 20 52 61 74 65 20 44 6f 77 6e 6c 69 6e 6b 10 3a a2 10 00 47 75 61 72 61 6e 74 65 65 64 20 46 6c 6f 77 20 42 69 74 20 52 61 74 65 20 44 6f 77 6e 6c 69 6e 6b 10 3a a3 10 00 4d 61 78 69 6d 75 6d 20 50 61 63 6b 65 74 20 4c 6f 73 73 20 52 61 74 65 20 44 6f 77 6e 6c 69 6e 6b 10 3a a4 0d 80 4d 61 78 69 6d 75 6d 20 46 6c 6f 77 20 42 69 74 20 52 61 74 65 20 55 70 6c 69 6e 6b 10 3a a5 0f 00 47 75 61 72 61 6e 74 65 65 64 20 46 6c 6f 77 20 42 69 74 20 52 61 74 65 20 55 70 6c 69 6e 6b 01 02 01 05 01 01 02 a0 01 03 0f 00 43 6f 6e 6e 65 63 74 65 64 20 6d 6f 64 65 20 6d 6f 62 69 6c 69 74 79 20 63 6f 6e 74 72 6f 6c 00 00 40 00 00 07 80 48 61 6e 64 6f 76 65 72 20 43 6f 6e 74 72 6f 6c 00 11 00 06 10 00 4c 69 73 74 20 6f 66 20 50 44 55 20 73 65 73 73 69 6f 6e 73 20 66 6f 72 20 68 61 6e 64 6f 76 65 72 00 07 0e 00 50 44 55 20 73 65 73 73 69 6f 6e 20 49 74 65 6d 20 66 6f 72 20 68 61 6e 64 6f 76 65 72 00 08 06 80 50 44 55 20 53 65 73 73 69 6f 6e 20 49 44 00 09 11 80 4c 69 73 74 20 6f 66 20 51 6f 53 20 66 6c 6f 77 73 20 69 6e 20 74 68 65 20 50 44 55 20 53 65 73 73 69 6f 6e 00 0a 06 00 51 6f 53 20 66 6c 6f 77 20 49 74 65 6d 00 0b 09 00 51 6f 53 20 66 6c 6f 77 20 49 64 65 6e 74 69 66 69 65 72 00 15 03 80 51 6f 53 20 66 6c 6f 77 10 3a 98 01 80 35 51 49 20 10 3a 9b 15 80 4e 47 2d 52 41 4e 20 44 52 42 20 41 6c 6c 6f 63 61 74 69 6f 6e 20 61 6e 64 20 52 65 74 65 6e 74 69 6f 6e 20 50 72 69 6f 72 69 74 79 10 3a 9c 06 80 50 72 69 6f 72 69 74 79 20 4c 65 76 65 6c 10 3a 9d 0a 80 50 72 65 2d 65 6d 70 74 69 6f 6e 20 43 61 70 61 62 69 6c 69 74 79 10 3a 9e 0c 00 50 72 65 2d 65 6d 70 74 69 6f 6e 20 56 75 6c 6e 65 72 61 62 69 6c 69 74 79 10 3a a0 16 00 51 6f 53 20 70 61 72 61 6d 65 74 65 72 73 20 66 6f 72 20 47 42 52 20 66 6c 6f 77 73 20 69 6e 20 4e 47 2d 52 41 4e 20 42 65 61 72 65 72 10 3a a1 0e 80 4d 61 78 69 6d 75 6d 20 46 6c 6f 77 20 42 69 74 20 52 61 74 65 20 44 6f 77 6e 6c 69 6e 6b 10 3a a2 10 00 47 75 61 72 61 6e 74 65 65 64 20 46 6c 6f 77 20 42 69 74 20 52 61 74 65 20 44 6f 77 6e 6c 69 6e 6b 10 3a a3 10 00 4d 61 78 69 6d 75 6d 20 50 61 63 6b 65 74 20 4c 6f 73 73 20 52 61 74 65 20 44 6f 77 6e 6c 69 6e 6b 10 3a a4 0d 80 4d 61 78 69 6d 75 6d 20 46 6c 6f 77 20 42 69 74 20 52 61 74 65 20 55 70 6c 69 6e 6b 10 3a a5 0f 00 47 75 61 72 61 6e 74 65 65 64 20 46 6c 6f 77 20 42 69 74 20 52 61 74 65 20 55 70 6c 69 6e 6b 01 01 01 01 01 01 00 00 00 08 00 52 65 63 65 69 76 65 64 54 69 6d 65 73 74 61 6d 70 50 01 04 09 80 52 61 64 69 6f 20 41 63 63 65 73 73 20 43 6f 6e 74 72 6f 6c 00 00 40 00 00 09 80 55 45 20 41 64 6d 69 73 73 69 6f 6e 20 43 6f 6e 74 72 6f 6c 00 11 00 17 10 80 4c 69 73 74 20 6f 66 20 50 44 55 20 73 65 73 73 69 6f 6e 73 20 66 6f 72 20 61 64 6d 69 73 73 69 6f 6e 00 18 0e 80 50 44 55 20 73 65 73 73 69 6f 6e 20 49 74 65 6d 20 66 6f 72 20 61 64 6d 69 73 73 69 6f 6e 00 19 06 80 50 44 55 20 53 65 73 73 69 6f 6e 20 49 44 00 1a 11 80 4c 69 73 74 20 6f 66 20 51 6f 53 20 66 6c 6f 77 73 20 69 6e 20 74 68 65 20 50 44 55 20 53 65 73 73 69 6f 6e 00 1b 06 00 51 6f 53 20 66 6c 6f 77 20 49 74 65 6d 00 1c 09 00 51 6f 53 20 66 6c 6f 77 20 49 64 65 6e 74 69 66 69 65 72 00 1d 03 80 51 6f 53 20 66 6c 6f 77 10 3a 98 01 80 35 51 49 20 10 3a 9b 15 80 4e 47 2d 52 41 4e 20 44 52 42 20 41 6c 6c 6f 63 61 74 69 6f 6e 20 61 6e 64 20 52 65 74 65 6e 74 69 6f 6e 20 50 72 69 6f 72 69 74 79 10 3a 9c 06 80 50 72 69 6f 72 69 74 79 20 4c 65 76 65 6c 10 3a 9d 0a 80 50 72 65 2d 65 6d 70 74 69 6f 6e 20 43 61 70 61 62 69 6c 69 74 79 10 3a 9e 0e 00 50 72 65 2d 65 6d 70 74 69 6f 6e 20 56 75 6c 6e 65 72 61 62 69 6c 69 74 79 20 20 20 20 10 3a a0 16 00 51 6f 53 20 70 61 72 61 6d 65 74 65 72 73 20 66 6f 72 20 47 42 52 20 66 6c 6f 77 73 20 69 6e 20 4e 47 2d 52 41 4e 20 42 65 61 72 65 72 10 3a a1 0e 80 4d 61 78 69 6d 75 6d 20 46 6c 6f 77 20 42 69 74 20 52 61 74 65 20 44 6f 77 6e 6c 69 6e 6b 10 3a a2 10 00 47 75 61 72 61 6e 74 65 65 64 20 46 6c 6f 77 20 42 69 74 20 52 61 74 65 20 44 6f 77 6e 6c 69 6e 6b 10 3a a3 10 00 4d 61 78 69 6d 75 6d 20 50 61 63 6b 65 74 20 4c 6f 73 73 20 52 61 74 65 20 44 6f 77 6e 6c 69 6e 6b 10 3a a4 0d 80 4d 61 78 69 6d 75 6d 20 46 6c 6f 77 20 42 69 74 20 52 61 74 65 20 55 70 6c 69 6e 6b 10 3a a5 0f 00 47 75 61 72 61 6e 74 65 65 64 20 46 6c 6f 77 20 42 69 74 20 52 61 74 65 20 55 70 6c 69 6e 6b 01 01 01 01 01 01 00 00 00 08 00 52 65 63 65 69 76 65 64 54 69 6d 65 73 74 61 6d 70 00 01 00 00 18 31 2e 33 2e 36 2e 31 2e 34 2e 31 2e 35 33 31 34 38 2e 31 2e 31 2e 32 2e 33 00 32 00 80 a8 00 00 00 33 00 80 a1 00 05 20 61 6d 66 31 2e 61 6d 66 2e 35 67 63 2e 6d 6e 63 31 32 33 2e 6d 63 63 31 32 33 2e 33 67 70 70 6e 65 74 77 6f 72 6b 2e 6f 72 67 00 3c 00 15 00 38 00 00 04 00 1b 00 09 00 00 f1 10 50 00 00 00 d0 00 52 40 0b 04 00 35 47 20 67 4e 42 2d 43 55 00 66 00 10 00 00 00 31 32 00 00 f1 10 00 00 10 08 01 02 03 00 15 40 01 00 35 20 15 00 31 00 00 04 00 01 00 05 01 00 41 4d 46 00 60 00 08 00 00 00 f1 10 ca fe 00 00 56 40 01 ff 00 50 00 10 00 00 f1 10 00 01 10 08 01 02 03 10 00 00 00 00";

            fprintf(stderr, "\n");


   } while (0);

   // asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);
    return response;
}


// *****************  RIC CONTROL ACKNOWLEDGE ********************** //

  e2_return_et encode_ric_control_acknowledge
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len
)
{

   e2ap_E2AP_PDU                           e2ap_pdu;
   OSCTXT                                  asn1_ctx;
   e2ap_RICcontrolAcknowledge             *p_asn_e2ap_RICcontrolAcknowledge = NULL;
   e2_return_et                            response = E2_SUCCESS;

   struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
   UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg1=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt16  *p_event_msg_len=malloc(sizeof(UInt16));
   UInt16  *p_event_msg_len1=malloc(sizeof(UInt16));
   pvalue->ricRequestorID=3;
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
	   e2ap_pdu.u.successfulOutcome = rtxMemAllocTypeZ(&asn1_ctx, e2ap_SuccessfulOutcome);

	   if(NULL ==  e2ap_pdu.u.successfulOutcome)
	   {
		   //   GNB_TRACE(GNB_ERROR, "Memory allocation falied for successfulOutcome");
		   printf("\n\n\nMemory allocation falied for successfulOutcome\n\n\n");
		   response = E2_FAILURE;
		   break;
	   }
      p_asn_e2ap_RICcontrolAcknowledge = 
		   rtxMemAllocTypeZ(&asn1_ctx, e2ap_RICcontrolAcknowledge);

	   if(NULL == p_asn_e2ap_RICcontrolAcknowledge)
	   {
		   response = E2_FAILURE;
		   break;
	   }
	   asn1SetTC_e2ap_SuccessfulOutcome_ricControl(
			   &asn1_ctx,
			   e2ap_pdu.u.successfulOutcome,
            p_asn_e2ap_RICcontrolAcknowledge);

      if (RT_OK != asn1Append_e2ap_RICcontrolAcknowledge_protocolIEs_1(&asn1_ctx,&p_asn_e2ap_RICcontrolAcknowledge->protocolIEs,pvalue))
	   {
		   //        GNB_TRACE(GNB_ERROR, "Failed to Add IE1 !!");
		   printf("\n\nFailed to Add IE1 !!\n\n"); 
		   response = E2_FAILURE;
		   break;
	   }
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
	   

	   if (RT_OK != asn1Append_e2ap_RICcontrolAcknowledge_protocolIEs_2(&asn1_ctx,&p_asn_e2ap_RICcontrolAcknowledge->protocolIEs,*p_value_ie2))
	   {
		   //   GNB_TRACE(GNB_ERROR, "Failed to Add IE2 !!");
		   response = E2_FAILURE;
		   break;
	   }
	   //GNB_TRACE(GNB_INFO, " IE2 encoded");
      printf("\n\n\n IE2 encoded\n\n\n");


      e2ap_RICcallProcessID *p_value_ie3 = NULL;
	   p_value_ie3 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICcallProcessID);
	   if(NULL == p_value_ie3)
	   {
		   //  GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
		   printf("\n\n\nMemory allocation failed !!\n\n\n"); 
		   response = E2_FAILURE;
		   break;
	   }

      int ver;

      E2SM_RC_ControlMessage *con_msg = NULL;
      con_msg = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_ControlMessage);
      if (!con_msg)
      {
         printf("Memory allocation failed for E2SM_RC_ControlMessage\n");
         response = E2_FAILURE;
         return response;
      }
      printf("\nAllocated con_msg at: %p\n", con_msg);


     OSRTDListNode *ranitem_list;
     E2SM_RC_ControlMessage_Format1_Item *ranitem = NULL;

     
     E2SM_RC_RANParameter_STRUCTURE *ranP_Structure = NULL;
     ranP_Structure = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_RANParameter_STRUCTURE);
     if (!ranP_Structure)
     {
        printf("Memory allocation failed for E2SM_RC_RANParameter_STRUCTURE\n");
        response = E2_FAILURE;
        return response;
     }
    
     OSRTDListNode *ranP_item_list;
     E2SM_RC_RANParameter_STRUCTURE_Item *ranP_item = NULL; 

    E2SM_RC_RANParameter_STRUCTURE *ranP_Structure1 = NULL;
    ranP_Structure1 = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_RANParameter_STRUCTURE);
    if (!ranP_Structure1)
    {
      printf("Memory allocation failed for E2SM_RC_RANParameter_STRUCTURE\n");
      response = E2_FAILURE;
      return response;
    }


        OSRTDListNode *ranP_item1_list;
        E2SM_RC_RANParameter_STRUCTURE_Item *ranP_item1 = NULL;

      E2SM_RC_RANParameter_STRUCTURE *ranP_Structure2 = NULL;
      ranP_Structure2 = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_RANParameter_STRUCTURE);
      if (!ranP_Structure2)
      {
         printf("Memory allocation failed for E2SM_RC_RANParameter_STRUCTURE\n");
         response = E2_FAILURE;
         return response;
      }

      OSRTDListNode *ranP_item2_list;
      E2SM_RC_RANParameter_STRUCTURE_Item *ranP_item2 = NULL;

      E2SM_RC_RANParameter_Value *ranP_Value2 = NULL;
      ranP_Value2 = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_RANParameter_Value);
      if (!ranP_Value2)
      {
         printf("Memory allocation failed for E2SM_RC_RANParameter_Value\n");
         response = E2_FAILURE;
         return response;
      }

      // Set control message format type
      con_msg->ric_controlMessage_formats.t =
         T_E2SM_RC_ControlMessage_ric_controlMessage_formats_controlMessage_Format1;

      con_msg->ric_controlMessage_formats.u.controlMessage_Format1 =
         rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_ControlMessage_Format1);

      if (!con_msg->ric_controlMessage_formats.u.controlMessage_Format1)
      {
         printf("Memory allocation failed for E2SM_RC_ControlMessage_Format1\n");
         response = E2_FAILURE;
         return response;
      }

     rtxDListInit(&con_msg->ric_controlMessage_formats.u.controlMessage_Format1->ranP_List);



     //ranitem = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_ControlMessage_Format1_Item);
     rtxDListAllocNodeAndData(&asn1_ctx,
                       E2SM_RC_ControlMessage_Format1_Item, 
                         &ranitem_list,
                        &ranitem);
     if (!ranitem)
     {
        printf("Memory allocation failed for E2SM_RC_ControlMessage_Format1_Item\n");
        response = E2_FAILURE;
        return response;
     }
     printf("\nAllocated ranitem at: %p\n", ranitem);

     ranitem->ranParameter_ID = 1;
     ranitem->ranParameter_valueType.t =T_E2SM_RC_RANParameter_ValueType_ranP_Choice_Structure;

     ranitem->ranParameter_valueType.u.ranP_Choice_Structure = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_RANParameter_ValueType_Choice_Structure);
     if (!ranitem->ranParameter_valueType.u.ranP_Choice_Structure)
     {
        printf("Memory allocation failed for E2SM_RC_RANParameter_ValueType_Choice_Structure\n");
        response = E2_FAILURE;
        return response;
     }


    // ver = asn1PE_E2SM_RC_ControlMessage_Format1(&asn1_ctx,ranitem);
      //      printf("\n ver=%d.\n\n",ver);
     ranP_Structure->m.sequence_of_ranParametersPresent=1;

     rtxDListInit(&ranP_Structure->sequence_of_ranParameters);

     
     
     //ranP_item = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_RANParameter_STRUCTURE_Item);
     rtxDListAllocNodeAndData(&asn1_ctx,
                       E2SM_RC_RANParameter_STRUCTURE_Item, 
                         &ranP_item_list,
                        &ranP_item);
     if (!ranP_item)
     {
        printf("Memory allocation failed for E2SM_RC_RANParameter_STRUCTURE_Item\n");
        response = E2_FAILURE;
        return response;
     }
     ranP_item->ranParameter_ID = 2;
     ranP_item->ranParameter_valueType =  rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_RANParameter_ValueType);
     if (!ranP_item->ranParameter_valueType)
     {
        printf("Memory allocation failed for E2SM_RC_RANParameter_STRUCTURE_Item\n");
        response = E2_FAILURE;
        return response;
     }

     ranP_item->ranParameter_valueType->t =T_E2SM_RC_RANParameter_ValueType_ranP_Choice_Structure;


    ranP_item->ranParameter_valueType->u.ranP_Choice_Structure = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_RANParameter_ValueType_Choice_Structure);
    if (!ranP_item->ranParameter_valueType->u.ranP_Choice_Structure)
    {
      printf("Memory allocation failed for E2SM_RC_RANParameter_ValueType_Choice_Structure\n");
      response = E2_FAILURE;
      return response;
    }

    ranP_Structure1->m.sequence_of_ranParametersPresent=1;

    rtxDListInit(&ranP_Structure1->sequence_of_ranParameters);

  

    //ranP_item1 = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_RANParameter_STRUCTURE_Item);
    rtxDListAllocNodeAndData(&asn1_ctx,
                       E2SM_RC_RANParameter_STRUCTURE_Item, 
                         &ranP_item1_list,
                        &ranP_item1);
    if (!ranP_item1)
    {
      printf("Memory allocation failed for E2SM_RC_RANParameter_STRUCTURE_Item\n");
      response = E2_FAILURE;
      return response;
    }
    ranP_item1->ranParameter_ID = 3;
    ranP_item1->ranParameter_valueType =  rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_RANParameter_ValueType);
     if (!ranP_item1->ranParameter_valueType)
     {
        printf("Memory allocation failed for E2SM_RC_RANParameter_STRUCTURE_Item\n");
        response = E2_FAILURE;
        return response;
     }

    ranP_item1->ranParameter_valueType->t =T_E2SM_RC_RANParameter_ValueType_ranP_Choice_Structure;

    ranP_item1->ranParameter_valueType->u.ranP_Choice_Structure = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_RANParameter_ValueType_Choice_Structure);
    if (!ranP_item1->ranParameter_valueType->u.ranP_Choice_Structure)
    {
      printf("Memory allocation failed for E2SM_RC_RANParameter_ValueType_Choice_Structure\n");
      response = E2_FAILURE;
      return response;
    }

  
    ranP_Structure2->m.sequence_of_ranParametersPresent=1;

    rtxDListInit(&ranP_Structure2->sequence_of_ranParameters);

    
    //ranP_item2 = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_RANParameter_STRUCTURE_Item);
    rtxDListAllocNodeAndData(&asn1_ctx,
                       E2SM_RC_RANParameter_STRUCTURE_Item, 
                         &ranP_item2_list,
                        &ranP_item2);
    if (!ranP_item2)
    {
      printf("Memory allocation failed for E2SM_RC_RANParameter_STRUCTURE_Item\n");
      response = E2_FAILURE;
      return response;
    }
    ranP_item2->ranParameter_ID = 4;
    ranP_item2->ranParameter_valueType =  rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_RANParameter_ValueType);
     if (!ranP_item2->ranParameter_valueType)
     {
        printf("Memory allocation failed for E2SM_RC_RANParameter_STRUCTURE_Item\n");
        response = E2_FAILURE;
        return response;
     }

    ranP_item2->ranParameter_valueType->t = T_E2SM_RC_RANParameter_ValueType_ranP_Choice_ElementFalse;

    ranP_item2->ranParameter_valueType->u.ranP_Choice_ElementFalse = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_RANParameter_ValueType_Choice_ElementFalse);
    if (!ranP_item2->ranParameter_valueType->u.ranP_Choice_ElementFalse)
    {
      printf("Memory allocation failed for E2SM_RC_RANParameter_ValueType_Choice_ElementFalse\n");
      response = E2_FAILURE;
      return response;
    }
    ranP_item2->ranParameter_valueType->u.ranP_Choice_ElementFalse->m.ranParameter_valuePresent=1;
    

    

    
 
    ranP_Value2->t = T_E2SM_RC_RANParameter_Value_valueOctS;

    //ranP_Value2->u.valueOctS = rtxMemAllocTypeZ(&asn1_ctx,OSOCTET);
    ranP_Value2->u.valueOctS = rtxMemAllocTypeZ(&asn1_ctx,OSDynOctStr);


    //ranP_Value2->u.valueOctS = rtxMemAllocTypeZ(&asn1_ctx, ASN1DynOctStr);

    if (!ranP_Value2->u.valueOctS)
    {
      printf("Memory allocation failed for OCTET_STRING\n");
      response = E2_FAILURE;
      return response;
    }
    //ranP_Value2->u.valueOctS->numocts = 9;
  
    //ranP_Value2->u.valueOctS->data[0] = 0;
      // Prepare the data
    //ranP_Value2->u.valueOctS->data = rtxMemAlloc(&asn1_ctx, 9);
    //abort();

    // Allocate separate buffer for octet string data (managed by ASN.1 context)
    UInt8 *p_octstr_data = (UInt8*)rtxMemAlloc(&asn1_ctx, 9);
    if (!p_octstr_data)
    {
      printf("Memory allocation failed for octet string data\n");
      response = E2_FAILURE;
      return response;
    }

    // Set the octet string data values
    p_octstr_data[0] = 0;
    p_octstr_data[1] = 55;  
    p_octstr_data[2] = 52;  
    p_octstr_data[3] = 55;   
    p_octstr_data[4] = 22;   
    p_octstr_data[5] =184;   
    p_octstr_data[6] = 206;  
    p_octstr_data[7] = 241;  
    p_octstr_data[8] = 8;  

    // Debug print the octet string
    fprintf(stderr, "E2SM_RC_RANParameter_Value valueOctS (9 bytes): ");
    for (int b = 0; b < 9; b++) {
       fprintf(stderr, "%02x ", p_octstr_data[b]);
    }
    fprintf(stderr, "\n");

    // Set the OSDynOctStr fields
    ranP_Value2->u.valueOctS->numocts = 9;
    ranP_Value2->u.valueOctS->data = (const OSOCTET*)p_octstr_data;

    //ver =asn1PE_E2SM_RC_RANParameter_Value(&asn1_ctx, ranP_Value2);
      // printf("\n ver=%d.\n\n",ver);

    






    ranP_item2->ranParameter_valueType->u.ranP_Choice_ElementFalse->ranParameter_value = *ranP_Value2;

    rtxDListAppendNode(&ranP_Structure2->sequence_of_ranParameters,ranP_item2_list);
    ranP_item1->ranParameter_valueType->u.ranP_Choice_Structure->ranParameter_Structure = *ranP_Structure2;

    rtxDListAppendNode(&ranP_Structure1->sequence_of_ranParameters,ranP_item1_list);
    ranP_item->ranParameter_valueType->u.ranP_Choice_Structure->ranParameter_Structure = *ranP_Structure1;

     

     rtxDListAppendNode(&ranP_Structure->sequence_of_ranParameters,ranP_item_list);
     ranitem->ranParameter_valueType.u.ranP_Choice_Structure->ranParameter_Structure = *ranP_Structure;


     rtxDListAppendNode (&con_msg->ric_controlMessage_formats.u.controlMessage_Format1->ranP_List, ranitem_list);
    // ver =asn1PE_E2SM_RC_ControlMessage(&asn1_ctx, con_msg);
         //   printf("\n ver=%d.\n\n",ver);
      con_msg->ric_controlMessage_formats.u.controlMessage_Format1->ranP_List.tail=NULL;

      // Encode E2SM_RC_RANFunctionDefinition_Insert
      memset(p_event_msg,0,E2CU_ASN1_BUFFER_LENGTH);
      if( RT_OK != pu_setBuffer(&asn1_ctx, p_event_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
      {
         printf("\n\npu_setBuffer failed.\n");
         response = E2_FAILURE;
         break;
      }
      else
      printf("\npu_setBuffer success.\n\n");
      int a=0;
      ver =asn1PE_E2SM_RC_ControlMessage(&asn1_ctx,con_msg);
      printf("\n ver=%d.\n\n",ver);    
      asn1Print_E2SM_RC_ControlMessage("test", con_msg);

      printf("\npu_setBuffer success.\n\n");
            a=asn1PE_E2SM_RC_ControlMessage(&asn1_ctx,con_msg);
            printf("\n\n===asn1PE_E2SM_RC_ControlMessage===a=%d===========\n",a);
            *p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
            printf("p_event_msg_len :%d\n\n",*p_event_msg_len);
            //	printf("p_event_msg : %x\n\n",*p_event_msg);
            for(a=0; a< ((*p_event_msg_len)); a ++)
            {
               fprintf(stderr, "%02x ", p_event_msg[a]);
            }
            a=0;
               fprintf(stderr, "\n");

            

            
      

    


      if (RT_OK != asn1Append_e2ap_RICcontrolAcknowledge_protocolIEs_3(&asn1_ctx,&p_asn_e2ap_RICcontrolAcknowledge->protocolIEs,p_value_ie3))
      {
         //GNB_TRACE(GNB_ERROR, "Failed to Add IE3 !!");
         response = E2_FAILURE;
         break;
      }
      printf("\n\n\n IE3 encoded\n\n\n");









   } while (0);
   asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);
   return response;
}







//  *****************  ric_subscription_response ********************** //

e2_return_et encode_ric_subscription_response
(
    UInt8   **pp_asn_msg,
    UInt16  *p_asn_msg_len
)

{
   // Load dynamic values:
   //E2Config cfg = {0};
   //load_config("config.txt", &cfg);
   //E2Config *cfg;
   //load_config("config.txt", &cfg, 0);
   E2Config *cfg = load_config(NULL, 1);
   //E2Config                        *cfg;
   e2ap_E2AP_PDU                      e2ap_pdu;
   OSCTXT                             asn1_ctx;
   e2ap_RICsubscriptionResponse       *p_asn_ric_subscription_response = NULL;
   e2_return_et                      response = E2_SUCCESS;

   //struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
    UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
    UInt8   *p_event_msg=malloc(E2CU_ASN1_BUFFER_LENGTH);
    UInt8   *p_event_msg1=malloc(E2CU_ASN1_BUFFER_LENGTH);
    UInt16  *p_event_msg_len=malloc(sizeof(UInt16));
    UInt16  *p_event_msg_len1=malloc(sizeof(UInt16));
   // pvalue->ricRequestorID=cfg.ricRequestorID;
   // pvalue->ricInstanceID=cfg.ricInstanceID;

  // UInt8 *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);

   //memset(p_asn_msg, 0, E2CU_ASN1_BUFFER_LENGTH);


   printf (" p_asn_msg : %p",p_asn_msg);
   if (NULL == p_asn_msg)
   {
	   //GNB_TRACE(GNB_ERROR, "Memory Allocation for p_asn_msg Failed !!");
	   printf("\n\n\nFailed !!\n\n");
	   return E2_FAILURE;
   }
   memset(p_asn_msg,0,E2CU_ASN1_BUFFER_LENGTH);


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

      struct e2ap_RICrequestID *pvalue = rtxMemAllocTypeZ(&asn1_ctx, struct e2ap_RICrequestID);
      
      pvalue->ricRequestorID = cfg->ricRequestorID;
      pvalue->ricInstanceID  = cfg->ricInstanceID;
    


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
	   *p_value_ie2=cfg->ranFunctionID; 
	   

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

         list->id=cfg->admittedIEID;
         list->criticality=cfg->criticality;
         list->value.t=T7e2ap___e2ap_RICaction_Admitted_ItemIEs_1;
         list->value.u._e2ap_RICaction_Admitted_ItemIEs_1=rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICaction_Admitted_Item);  
         list->value.u._e2ap_RICaction_Admitted_ItemIEs_1->ricActionID = cfg->actionID;
        
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






/****************************************************************************
 *
 *
 *
 *	setup failure
 *
 *
 * ************************************************************************/



e2_return_et encode_e2_setup_failure
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len
)
{

e2ap_E2AP_PDU                           e2ap_pdu;
   OSCTXT                                  asn1_ctx;
   e2ap_E2setupFailure                     *p_asn_e2_setup_failure = NULL;
   e2_return_et                            response = E2_SUCCESS;





    UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
   printf (" p_asn_msg : %p",p_asn_msg);
   if (NULL == p_asn_msg)
   {
           //GNB_TRACE(GNB_ERROR, "Memory Allocation for p_asn_msg Failed !!");
           printf("\n\n\nFailed !!\n\n");
                return E2_FAILURE;
   }
   memset(p_asn_msg,0,sizeof(UInt8));


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

       e2ap_pdu.t = T_e2ap_E2AP_PDU_unsuccessfulOutcome;
       e2ap_pdu.u.unsuccessfulOutcome = rtxMemAllocTypeZ(&asn1_ctx, e2ap_UnsuccessfulOutcome);

       if(NULL ==  e2ap_pdu.u.unsuccessfulOutcome)
       {
	
        printf("\n\n\nMemory allocation falied for successfulOutcome\n\n\n");
	  response = E2_FAILURE;
          break;

	}
       p_asn_e2_setup_failure =
           rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2setupFailure);
       if(NULL == p_asn_e2_setup_failure)
       {
           response = E2_FAILURE;
           break;
       }

       asn1SetTC_e2ap_UnsuccessfulOutcome_e2setup(
                       &asn1_ctx,
                       e2ap_pdu.u.unsuccessfulOutcome,
                       p_asn_e2_setup_failure);

     if (RT_OK != asn1Append_e2ap_E2setupResponse_protocolIEs_1(&asn1_ctx,&p_asn_e2_setup_failure->protocolIEs,E2CU_ONE))
     {
        	printf("\n\nFailed to Add IE1 !!\n\n"); 
	      response = E2_FAILURE;
               break;
      }
	
      OSRTDListNode  *p_node = NULL;
      OSRTDListNode  *p_node1 = NULL;
      e2ap_E2setupFailure_protocolIEs_element  *p_data= NULL;
      e2ap_E2setupFailure_protocolIEs_element  *p_data1= NULL;


	  rtxDListInit(&p_asn_e2_setup_failure->protocolIEs);
      asn1Init_e2ap_E2setupFailure_protocolIEs(&p_asn_e2_setup_failure->protocolIEs);
      int loop =0 ;
      for (loop = 0 ; loop <= 1 ; loop++ ){

	if(loop == 0)
	{	
          rtxDListAllocNodeAndData(&asn1_ctx,
                  e2ap_E2setupFailure_protocolIEs_element,
                  &p_node, &p_data);
	
		p_data->value.t=T22e2ap___e2ap_E2setupFailureIEs_1;
		p_data->value.u._e2ap_E2setupFailureIEs_1=1;
	 rtxDListAppendNode (
                  &p_asn_e2_setup_failure->protocolIEs,
                  p_node);
	}
	else
	{
	 rtxDListAllocNodeAndData(&asn1_ctx,
                  e2ap_E2setupFailure_protocolIEs_element,
                  &p_node1, &p_data1);

                p_data1->value.t=T22e2ap___e2ap_E2setupFailureIEs_2;
                p_data1->value.u._e2ap_E2setupFailureIEs_2=rtxMemAllocTypeZ(&asn1_ctx,e2ap_Cause);
		p_data1->value.u._e2ap_E2setupFailureIEs_2->t=T_e2ap_Cause_misc;
		p_data1->value.u._e2ap_E2setupFailureIEs_2->u.misc=e2ap_unspecified;

         rtxDListAppendNode (
                  &p_asn_e2_setup_failure->protocolIEs,
                  p_node1);
	
	
	}
  
    }

         if( RT_OK != pu_setBuffer(&asn1_ctx, p_asn_msg,
                       E2CU_ASN1_BUFFER_LENGTH, TRUE))
         {
          //  GNB_TRACE(GNB_ERROR,"pu_setBuffer failed.");
            response = E2_FAILURE;
            break;
         }                                               
        // GNB_TRACE(GNB_INFO, " After pu_setBuffer");
         if (0 != asn1PE_e2ap_E2AP_PDU(&asn1_ctx, &e2ap_pdu))
         {
            rtxErrPrint(&asn1_ctx);
          //  GNB_TRACE(GNB_INFO, "ASN1 encoding of E2 Setup Request failed.");
            response = E2_FAILURE;
            break;
         }
         else
         {
            *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
             if(RT_OK == asn1PrtToStrm_e2ap_E2AP_PDU(&asn1_ctx, "e2ap_pdu", &e2ap_pdu))
             {
               // GNB_TRACE(GNB_INFO, "asn1PrtToStrm_e2ap_E2AP_PDU success !!");
                printf("\n\n\nasn1PrtToStrm_e2ap_E2AP_PDU success !!\n\n\n");
		response = E2_SUCCESS;
             }
             else
             {
                //GNB_TRACE(GNB_INFO, "asn1PrtToStrm_e2ap_E2AP_PDU failure !!");
                printf("\n\n\nasn1PrtToStrm_e2ap_E2AP_PDU failure !!\n\n\n");
                response = E2_FAILURE;
             }
         }

    }while(0);

    return response;
}

/************************************************************************************************
 *
 *
 *		encode setup response
 *
 *
 *
 * ***********************************************************************************************/



e2_return_et encode_e2_setup_response
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len
)
{

   e2ap_E2AP_PDU                           e2ap_pdu;
   OSCTXT                                  asn1_ctx;
   e2ap_E2setupResponse                     *p_asn_e2_setup_response = NULL;
   e2_return_et                            response = E2_SUCCESS;


   UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
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
       e2ap_pdu.u.successfulOutcome = rtxMemAllocTypeZ(&asn1_ctx, e2ap_SuccessfulOutcome);

       if(NULL ==  e2ap_pdu.u.successfulOutcome)
       {
      //   GNB_TRACE(GNB_ERROR, "Memory allocation falied for successfulOutcome");
        printf("\n\n\nMemory allocation falied for successfulOutcome\n\n\n");
	  response = E2_FAILURE;
          break;
       }
       p_asn_e2_setup_response =
           rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2setupResponse);

       if(NULL == p_asn_e2_setup_response)
       {
           response = E2_FAILURE;
           break;
       }

       asn1SetTC_e2ap_SuccessfulOutcome_e2setup(
                       &asn1_ctx,
                       e2ap_pdu.u.successfulOutcome,
                       p_asn_e2_setup_response);
      

     if (RT_OK != asn1Append_e2ap_E2setupResponse_protocolIEs_1(&asn1_ctx,&p_asn_e2_setup_response->protocolIEs,E2CU_ONE))
     {
       //        GNB_TRACE(GNB_ERROR, "Failed to Add IE1 !!");
        	printf("\n\nFailed to Add IE1 !!\n\n"); 
	      response = E2_FAILURE;
               break;
      }
      //GNB_TRACE(GNB_INFO, " IE1 encoded");
      printf("\n\n\n IE1 encoded\n\n\n");
      e2ap_GlobalRIC_ID *p_value_ie2 = GNB_PNULL;
      p_value_ie2 = rtxMemAllocTypeZ(&asn1_ctx, e2ap_GlobalRIC_ID);
      
      if(GNB_PNULL == p_value_ie2)
      {
        // GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
        printf("\n\n\nMemory allocation failed !!\n\n\n"); 
	response = E2_FAILURE;
         break;
      }
      memset(p_value_ie2,0,sizeof(e2ap_GlobalRIC_ID));
     
     p_value_ie2->pLMN_Identity.data[0] = 0;
     p_value_ie2->pLMN_Identity.data[1] = 1;
     p_value_ie2->pLMN_Identity.data[2] = 2;
     p_value_ie2->pLMN_Identity.numocts = 3;
     p_value_ie2->ric_ID.data[0] =0;
     p_value_ie2->ric_ID.data[1] =1;
     p_value_ie2->ric_ID.data[2] =2;
     p_value_ie2->ric_ID.data[3] =3;
     p_value_ie2->ric_ID.numbits = 20;

      if (RT_OK != asn1Append_e2ap_E2setupResponse_protocolIEs_2(&asn1_ctx,&p_asn_e2_setup_response->protocolIEs,p_value_ie2))
      {
       //   GNB_TRACE(GNB_ERROR, "Failed to Add IE2 !!");
          response = E2_FAILURE;
          break;
      }
      //GNB_TRACE(GNB_INFO, " IE2 encoded");


      printf("\n\n\n IE2 encoded\n\n\n");
      /*Encode IE_3 RAN function List*/
      e2ap_RANfunctionsID_List *p_value_ie3 = NULL;
      p_value_ie3 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RANfunctionsID_List);
      memset(p_value_ie3,0,sizeof(e2ap_RANfunctionsID_List));
      if(NULL == p_value_ie3)
      {
       //  GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
        printf("\n\n\nMemory allocation failed !!\n\n\n"); 
	response = E2_FAILURE;
         break;
      }                                                        
      OSRTDListNode  *p_node_ran_func_id = NULL;
      e2ap_RANfunctionsID_List_element  *p_data_ran_func_id= NULL;

      rtxDListInit(p_value_ie3);
      asn1Init_e2ap_RANfunctionsID_List(p_value_ie3);
      int loop =0 ;
      for (loop = 0 ; loop < 1 ; loop++ ){  
          rtxDListAllocNodeAndData(&asn1_ctx,
                  e2ap_RANfunctionsID_List_element,
                  &p_node_ran_func_id, &p_data_ran_func_id);

           memset(p_data_ran_func_id ,0,sizeof(e2ap_RANfunctionsID_List_element));

          p_data_ran_func_id->id = ASN1V_e2ap_id_RANfunctionID_Item;
          p_data_ran_func_id->criticality = e2ap_reject;
          p_data_ran_func_id->value.t=T43e2ap___e2ap_RANfunctionID_ItemIEs_1;
          p_data_ran_func_id->value.u._e2ap_RANfunctionID_ItemIEs_1= rtxMemAllocTypeZ(&asn1_ctx,e2ap_RANfunctionID_Item);
          switch(loop){
              case 0:
                  p_data_ran_func_id->value.u._e2ap_RANfunctionID_ItemIEs_1->ranFunctionID = 2;
                  p_data_ran_func_id->value.u._e2ap_RANfunctionID_ItemIEs_1->ranFunctionRevision =1;
                  break;
              case 1:
                  p_data_ran_func_id->value.u._e2ap_RANfunctionID_ItemIEs_1->ranFunctionID = 101;
                  p_data_ran_func_id->value.u._e2ap_RANfunctionID_ItemIEs_1->ranFunctionRevision =1;
                  break;
          }

          rtxDListAppendNode (
                  p_value_ie3,
                  p_node_ran_func_id);
      }

      if (RT_OK != asn1Append_e2ap_E2setupResponse_protocolIEs_3(&asn1_ctx,&p_asn_e2_setup_response->protocolIEs,p_value_ie3))
      {
       //  GNB_TRACE(GNB_ERROR, "Failed to Add IE3 !!");
        printf("\n\n\nFailed to Add IE3 !!\n\n\n"); 
	response = E2_FAILURE;
         break;
      }
       //  GNB_TRACE(GNB_INFO, " IE3 encoded");

      printf("\n\n\n IE3 encoded\n\n\n");
         //e2ap_E2nodeComponentConfigAdditionAck_List *p_value_ie5 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RANfunctionsID_List);
         e2ap_E2nodeComponentConfigAdditionAck_List *p_value_ie5 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2nodeComponentConfigAdditionAck_List);
         
	 OSRTDListNode  *p_node_comp_ack = NULL;
         e2ap_E2nodeComponentConfigAdditionAck_List_element  *p_data_comp_ack= NULL;

         rtxDListInit(p_value_ie5);
         asn1Init_e2ap_E2nodeComponentConfigAdditionAck_List(p_value_ie5);

         for (loop = 0 ; loop < 1 ; loop++ ){  
             rtxDListAllocNodeAndData(&asn1_ctx,
                     e2ap_E2nodeComponentConfigAdditionAck_List_element,
                     &p_node_comp_ack,&p_data_comp_ack);
             memset(p_data_comp_ack,E2_ZERO,sizeof(e2ap_E2nodeComponentConfigAdditionAck_List_element));
             p_data_comp_ack->value.t=T35e2ap___e2ap_E2nodeComponentConfigAdditionAck_ItemIEs_1;
	    p_data_comp_ack->value.u._e2ap_E2nodeComponentConfigAdditionAck_ItemIEs_1= 
            rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2nodeComponentConfigAdditionAck_Item);
             memset(p_data_comp_ack->value.u._e2ap_E2nodeComponentConfigAdditionAck_ItemIEs_1,
            E2_ZERO,sizeof(e2ap_E2nodeComponentConfigAdditionAck_Item));
	    p_data_comp_ack->id=51;
             switch(loop){
                 case 0:
                     p_data_comp_ack->value.u._e2ap_E2nodeComponentConfigAdditionAck_ItemIEs_1->\
                       e2nodeComponentInterfaceType = 3;
                     p_data_comp_ack->value.u._e2ap_E2nodeComponentConfigAdditionAck_ItemIEs_1-> \
                       e2nodeComponentID.u.e2nodeComponentInterfaceTypeF1 = 
                      rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2nodeComponentInterfaceF1); 
                     memset(p_data_comp_ack->value.u._e2ap_E2nodeComponentConfigAdditionAck_ItemIEs_1->\
                       e2nodeComponentID.u.e2nodeComponentInterfaceTypeF1, 
                     E2_ZERO, sizeof(e2ap_E2nodeComponentInterfaceF1));
                     p_data_comp_ack->value.u._e2ap_E2nodeComponentConfigAdditionAck_ItemIEs_1->e2nodeComponentID.t=\
                        T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeF1;
                     p_data_comp_ack->value.u._e2ap_E2nodeComponentConfigAdditionAck_ItemIEs_1->\
                        e2nodeComponentID.u.e2nodeComponentInterfaceTypeF1->gNB_DU_ID = 0;
                     p_data_comp_ack->value.u._e2ap_E2nodeComponentConfigAdditionAck_ItemIEs_1->\
                        e2nodeComponentConfigurationAck.updateOutcome = e2ap_success;
                     break;
             }

             rtxDListAppendNode (
                     p_value_ie5,
                     p_node_comp_ack);
         }


	 if (RT_OK != asn1Append_e2ap_E2setupResponse_protocolIEs_5
            (&asn1_ctx,&p_asn_e2_setup_response->protocolIEs,p_value_ie5))
	 {
	//	 GNB_TRACE(GNB_ERROR, "Failed to Add IE4 !!");
		 response = E2_FAILURE;
		 break;
	 }

         /* ASN Encode message */
         if( RT_OK != pu_setBuffer(&asn1_ctx, p_asn_msg,
                       E2CU_ASN1_BUFFER_LENGTH, TRUE))
         {
          //  GNB_TRACE(GNB_ERROR,"pu_setBuffer failed.");
            response = E2_FAILURE;
            break;
         }                                               
        // GNB_TRACE(GNB_INFO, " After pu_setBuffer");
         if (0 != asn1PE_e2ap_E2AP_PDU(&asn1_ctx, &e2ap_pdu))
         {
            rtxErrPrint(&asn1_ctx);
          //  GNB_TRACE(GNB_INFO, "ASN1 encoding of E2 Setup Request failed.");
            response = E2_FAILURE;
            break;
         }
         else
         {
            *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
             if(RT_OK == asn1PrtToStrm_e2ap_E2AP_PDU(&asn1_ctx, "e2ap_pdu", &e2ap_pdu))
             {
               // GNB_TRACE(GNB_INFO, "asn1PrtToStrm_e2ap_E2AP_PDU success !!");
                printf("\n\n\nasn1PrtToStrm_e2ap_E2AP_PDU success !!\n\n\n");
		response = E2_SUCCESS;
             }
             else
             {
                //GNB_TRACE(GNB_INFO, "asn1PrtToStrm_e2ap_E2AP_PDU failure !!");
                printf("\n\n\nasn1PrtToStrm_e2ap_E2AP_PDU failure !!\n\n\n");
                response = E2_FAILURE;
             }
         }
         /* testing purpose printing HEX DUMP */
         int i;
         fprintf(stderr, "value of p_asn_msg_len is %d \n", *p_asn_msg_len);
         for(i=0; i< *p_asn_msg_len; i ++)
         {
            fprintf(stderr, "%02x ", p_asn_msg[i]);
         }
         fprintf(stderr, "\n");

     }while(0);

    return response;
}  


/******************************e2ap_RICsubscriptionDeleteRequest********************************* */
 e2_return_et encode_ric_subscription_delete_request
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len
 //GUAMI                                          *myguami
)

{
   E2Config *cfg = load_config(NULL, 1);
   e2ap_E2AP_PDU                           e2ap_pdu;
   OSCTXT                                  asn1_ctx;
   e2ap_RICsubscriptionDeleteRequest       *p_asn_ric_subscription_delete_request = NULL;
   e2_return_et                            response = E2_SUCCESS;

   //struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
   UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg1=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt16  *p_event_msg_len=malloc(sizeof(UInt16));
   UInt16  *p_event_msg_len1=malloc(sizeof(UInt16));
   
   printf (" p_asn_msg : %p",p_asn_msg);
   if (NULL == p_asn_msg)
   {
	   //GNB_TRACE(GNB_ERROR, "Memory Allocation for p_asn_msg Failed !!");
	   printf("\n\n\nFailed !!\n\n");
	   return E2_FAILURE;
   }
   memset(p_asn_msg,0,sizeof(UInt8));


   //GNB_TRACE(GNB_INFO, "encode_e2_subscription_delete_req");
   printf( "\n\n\nencode_e2_subscription_delete_req\n\n");
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

	   e2ap_pdu.t = T_e2ap_E2AP_PDU_initiatingMessage;
	   e2ap_pdu.u.initiatingMessage = rtxMemAllocTypeZ(&asn1_ctx,e2ap_InitiatingMessage);

	   if(NULL ==  e2ap_pdu.u.initiatingMessage)
	   {
		   //   GNB_TRACE(GNB_ERROR, "Memory allocation falied for successfulOutcome");
		   printf("\n\n\nMemory allocation falied for successfulOutcome\n\n\n");
		   response = E2_FAILURE;
		   break;
	   }
	   p_asn_ric_subscription_delete_request=
		   rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICsubscriptionDeleteRequest);

	   if(NULL == p_asn_ric_subscription_delete_request)
	   {
		   response = E2_FAILURE;
		   break;
	   }
	   asn1SetTC_e2ap_InitiatingMessage_ricSubscriptionDelete(
			   &asn1_ctx,
			   e2ap_pdu.u.initiatingMessage,
            p_asn_ric_subscription_delete_request);

      struct e2ap_RICrequestID *pvalue = rtxMemAllocTypeZ(&asn1_ctx, struct e2ap_RICrequestID);
      pvalue->ricRequestorID=cfg->ricRequestorID;
      pvalue->ricInstanceID=cfg->ricInstanceID;


	   if (RT_OK != asn1Append_e2ap_RICsubscriptionDeleteRequest_protocolIEs_1(&asn1_ctx,&p_asn_ric_subscription_delete_request->protocolIEs,pvalue))
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
	   *p_value_ie2=cfg->ranFunctionID;//2; 
	

	   if (RT_OK != asn1Append_e2ap_RICsubscriptionDeleteRequest_protocolIEs_2(&asn1_ctx,&p_asn_ric_subscription_delete_request->protocolIEs,*p_value_ie2))
	   {
		   //   GNB_TRACE(GNB_ERROR, "Failed to Add IE2 !!");
		   response = E2_FAILURE;
		   break;
	   }
	   //GNB_TRACE(GNB_INFO, " IE2 encoded");


	   printf("\n\n\n IE2 encoded\n\n\n"); 

        /* ASN Encode message */
         if( RT_OK != pu_setBuffer(&asn1_ctx, p_asn_msg,
                       E2CU_ASN1_BUFFER_LENGTH, TRUE))
         {
          //  GNB_TRACE(GNB_ERROR,"pu_setBuffer failed.");
            response = E2_FAILURE;
            break;
         }                                               
        // GNB_TRACE(GNB_INFO, " After pu_setBuffer");
         if (0 != asn1PE_e2ap_E2AP_PDU(&asn1_ctx, &e2ap_pdu))
         {
            rtxErrPrint(&asn1_ctx);
          //  GNB_TRACE(GNB_INFO, "ASN1 encoding of E2 Setup Request failed.");
            response = E2_FAILURE;
            break;
         }
         else
         {
            *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
             if(RT_OK == asn1PrtToStrm_e2ap_E2AP_PDU(&asn1_ctx, "e2ap_pdu", &e2ap_pdu))
             {
               // GNB_TRACE(GNB_INFO, "asn1PrtToStrm_e2ap_E2AP_PDU success !!");
                printf("\n\n\nasn1PrtToStrm_e2ap_E2AP_PDU success !!\n\n\n");
		response = E2_SUCCESS;
             }
             else
             {
                //GNB_TRACE(GNB_INFO, "asn1PrtToStrm_e2ap_E2AP_PDU failure !!");
                printf("\n\n\nasn1PrtToStrm_e2ap_E2AP_PDU failure !!\n\n\n");
                response = E2_FAILURE;
             }
         }
         /* testing purpose printing HEX DUMP */
         int i;
         fprintf(stderr, "value of p_asn_msg_len is %d \n", *p_asn_msg_len);
         for(i=0; i< *p_asn_msg_len; i ++)
         {
            fprintf(stderr, "%02x ", p_asn_msg[i]);
         }
         fprintf(stderr, "\n");

   }while(0);
   //asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);
   return response;
}


/*int asn1PD_e2ap_E2AP_PDU (OSCTXT* pctxt, e2ap_E2AP_PDU* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   OSBOOL extbit = FALSE;
   ASN1OpenType openType;

   RTXCTXTPUSHTYPENAME (pctxt, "E2AP-PDU");*/

   /* extension bit */

 /*  stat = DEC_BIT (pctxt, &extbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   if (!extbit) {
      stat = rtxDecBits (pctxt, &ui, 2);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
      else pvalue->t = ui + 1;
       printf("======================ui :case - %d==========\n=======================================\n ",ui);
      switch (ui) {*/
         /* initiatingMessage */
     /*    case 0:
            RTXCTXTPUSHELEMNAME (pctxt, "initiatingMessage");

            pvalue->u.initiatingMessage = rtxMemAllocType (pctxt,
               e2ap_InitiatingMessage);

            if (pvalue->u.initiatingMessage == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_e2ap_InitiatingMessage (pvalue->u.initiatingMessage);
                                                                                              
  stat = asn1PD_e2ap_InitiatingMessage (pctxt, pvalue->u.initiatingMessage);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            RTXCTXTPOPELEMNAME (pctxt);

            break;*/

         /* successfulOutcome */
       /*  case 1:

            printf("Debug=====In successful outcome==============\n");
            RTXCTXTPUSHELEMNAME (pctxt, "successfulOutcome");

            pvalue->u.successfulOutcome = rtxMemAllocType (pctxt,
               e2ap_SuccessfulOutcome);

            if (pvalue->u.successfulOutcome == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_e2ap_SuccessfulOutcome (pvalue->u.successfulOutcome);

            stat = asn1PD_e2ap_SuccessfulOutcome (pctxt, pvalue->u.successfulOutcome);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            RTXCTXTPOPELEMNAME (pctxt);

            break;*/

         /* unsuccessfulOutcome */
       /* case 2:
            RTXCTXTPUSHELEMNAME (pctxt, "unsuccessfulOutcome");

            pvalue->u.unsuccessfulOutcome = rtxMemAllocType (pctxt,
               e2ap_UnsuccessfulOutcome);

            if (pvalue->u.unsuccessfulOutcome == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_e2ap_UnsuccessfulOutcome (pvalue->u.unsuccessfulOutcome);

            stat = asn1PD_e2ap_UnsuccessfulOutcome (pctxt, pvalue->u.unsuccessfulOutcome);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            RTXCTXTPOPELEMNAME (pctxt);

            break;

         default:
            return LOG_RTERR (pctxt, RTERR_INVOPT);
      }
   }
   else {
      stat = pd_SmallNonNegWholeNumber (pctxt, &ui);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
      else pvalue->t = ui + 4;

      if (pvalue->t < 4) return LOG_RTERR (pctxt, RTERR_INVOPT);

      stat = PD_BYTE_ALIGN (pctxt);
  if (stat != 0) return LOG_RTERR (pctxt, stat);

      RTXCTXTPUSHELEMNAME (pctxt, "...");

      stat = pd_OpenType (pctxt, &openType.data, &openType.numocts);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      pvalue->u.extElem1 = rtxMemAllocType (pctxt, ASN1OpenType);

      if (pvalue->u.extElem1 == NULL)
         return LOG_RTERR (pctxt, RTERR_NOMEM);

      pvalue->u.extElem1->data = openType.data;
      pvalue->u.extElem1->numocts = openType.numocts;

      RTXCTXTPOPELEMNAME (pctxt);

   }

   RTXCTXTPOPTYPENAME (pctxt);

   return (stat);
}*/











#define SERVER_IP   "10.1.3.84"   // Same IP your server binds to
#define SERVER_PORT 36422        // Must match server's RIC_PORT
#define BUFFER_SIZE 8196

int main()
{
   int sockfd, connSock1, ret;
   struct sockaddr_in servaddr;
   struct sctp_initmsg initmsg;
   UInt8   octet_bitstring[4196];  // Use uint8_t for the octet bitstring
   GUAMI                          *myguami=NULL;
   E2SM_RC_IndicationHeader       *header=NULL;
   e2ap_SuccessfulOutcome         *successfulOutcome=NULL;
   E2SM_RC_CallProcessID          *ric_call=NULL;

   // Variables for encoded ASN.1 message
   uint8_t *pp_asn_msg = NULL;
   uint16_t p_asn_msg_len = 0;

   //while(1)
   //{
      // ===== Encode the RIC Subscription Response =====
      //ret=encode_ric_subscription_response(&pp_asn_msg,&p_asn_msg_len); 
      ret=encode_e2_setup_request(&pp_asn_msg,&p_asn_msg_len); 
      //if (ret != 0 || p_asn_msg_len == 0) 
      //{
      // printf("Encoding failed! ret=%d, length=%d\n", ret, p_asn_msg_len);
         //return EXIT_FAILURE;
      //}
      printf("Encoded e2setup request (%d bytes)\n", p_asn_msg_len);

      // ===== Create SCTP socket =====
      sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_SCTP);
      if (sockfd < 0)
      {
         perror("socket");
         sleep(2);
         //continue;
         exit(EXIT_FAILURE);
      }

      /******************************************/
      /* SO_REUSEADDR                           */
      /******************************************/

      int opt = 1;

      setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,
         &opt,sizeof(opt));

      /******************************************/
      /* SCTP EVENTS                            */
      /******************************************/

      struct sctp_event_subscribe events;

      memset(&events, 0, sizeof(events));

      events.sctp_data_io_event      = 1;
      events.sctp_association_event  = 1;
      events.sctp_shutdown_event     = 1;

      setsockopt(sockfd,IPPROTO_SCTP,SCTP_EVENTS,
         &events,sizeof(events));

      // ===== Configure SCTP INIT parameters =====
      memset(&initmsg, 0, sizeof(initmsg));
      initmsg.sinit_num_ostreams = 5;
      initmsg.sinit_max_instreams = 5;
      initmsg.sinit_max_attempts = 4;

      ret = setsockopt(sockfd, IPPROTO_SCTP, SCTP_INITMSG, &initmsg, sizeof(initmsg));
      if (ret < 0)
      {
         perror("setsockopt");
         close(sockfd);
         sleep(2);
         //continue;
         exit(EXIT_FAILURE);
      }

      // ===== Set server address =====
      memset(&servaddr, 0, sizeof(servaddr));
      servaddr.sin_family = AF_INET;
      servaddr.sin_port = htons(SERVER_PORT);
      if (inet_pton(AF_INET, SERVER_IP, &servaddr.sin_addr) <= 0)
     /* {
         perror("inet_pton");
         close(sockfd);
         sleep(2);
         continue;
         //exit(EXIT_FAILURE);
      } */

      if(ret < 0)
      {
         perror("setsockopt SCTP_INITMSG");
         close(sockfd);
         
         if(pp_asn_msg)
         {
            free(pp_asn_msg);
            pp_asn_msg = NULL;
         }
         sleep(2);
         //continue;
         exit(EXIT_FAILURE);
      }

      /*************************************************/
      /* SERVER ADDRESS                                */
      /*************************************************/

      memset(&servaddr, 0, sizeof(servaddr));
      servaddr.sin_family = AF_INET;
      servaddr.sin_port   = htons(SERVER_PORT);
      
      if(inet_pton(AF_INET,SERVER_IP,&servaddr.sin_addr) <= 0)
      {
         perror("inet_pton");
         close(sockfd);
         
         if(pp_asn_msg)
         {
            free(pp_asn_msg);
            pp_asn_msg = NULL;
         }

         sleep(2);
         //continue;
         exit(EXIT_FAILURE);

      }

      // ===== Connect to SCTP server =====
      if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
      {
         perror("connect");
         close(sockfd);
         sleep(2);
        // continue;
        exit(EXIT_FAILURE);
      }
      connSock1 = sockfd; 
      printf("Connected to SCTP server %s:%d\n", SERVER_IP, SERVER_PORT);

      // ===== Send the encoded RIC Subscription Response =====
      if (p_asn_msg_len > 0)
      {
         ret = sctp_sendmsg(sockfd,pp_asn_msg, p_asn_msg_len,
         NULL, 0,      // connected socket, no destination
         0,           // PPID (can set appropriate protocol ID)
         0,           // flags
         0, 0, 0);    // stream, timetolive, context
         
         if (ret < 0)
         {
            perror("sctp_sendmsg");
            free(pp_asn_msg);
            close(sockfd);
            sleep(2);
            //continue;
            exit(EXIT_FAILURE);
         }
         printf("Sent %d bytes to server\n", ret);
      }
      else 
      {
         printf("Nothing to send, aborting\n");
         free(pp_asn_msg);
         close(sockfd);
         sleep(2);
         //continue;
         return EXIT_FAILURE;
      }

      // ===== Receive optional server response =====
      uint8_t buffer[BUFFER_SIZE];
      ret = sctp_recvmsg(sockfd, buffer, sizeof(buffer), NULL, 0, 0, 0);
      if (ret > 0) 
      {
         printf("Received %d bytes from server:\n", ret);
         for (int i = 0; i < ret; i++)
         printf("%02X ", buffer[i]);
         printf("\n");
      } 
      else if (ret == 0)
      {
         printf("Server closed connection.\n");
      } 
      else
      {
         perror("sctp_recvmsg");
      }

      e2ap_E2AP_PDU    pdu;
      OSCTXT                                  asn1_ctx;
      int i,in,ip= 0;
      if(E2_ASN_OK != rtInitContext(&asn1_ctx))
      {
         //GNB_TRACE(GNB_ERROR, "ASN Context Initialization Failed");
         printf("\n\n\nASN Context Initialization Failed\n\n");
      }
      if (E2_ASN_OK != pu_setBuffer(&asn1_ctx, (OSUINT8 *)octet_bitstring, in, E2_TRUE))
      {
         //GNB_TRACE(GNB_ERROR, "Failed pu_setBuffer for RIC SUbscription Request");
         printf("==========Failed pu_setBuffer for RIC SUbscription Request=========\n\n\n");
      }
      E2_MEMSET(&pdu, E2_ZERO, sizeof(pdu));

      asn1PD_e2ap_E2AP_PDU(&asn1_ctx,&pdu);
      asn1Print_e2ap_E2AP_PDU("e2ap_pdu",&pdu);

      printf(" Waiting for next messages...\n");

      while(1)
      {
         memset(octet_bitstring, 0, sizeof(octet_bitstring));

         in = sctp_recvmsg(connSock1,(void *)octet_bitstring,BUFFER_SIZE,
                  NULL, 0, 0, 0);

         if (in <= 0)
         {
            printf("Connection lost → reconnect\n");
            close(connSock1);
            break;
         }

         printf("Received %d bytes\n", in);
      }

      close(connSock1);

      if(pp_asn_msg)
      {
         free(pp_asn_msg);
         pp_asn_msg=NULL;
      }

     // sleep(2);
  // }
  while(1);
  // ===== Cleanup =====
  close(connSock1);
  free(pp_asn_msg);
  return 0;
}





