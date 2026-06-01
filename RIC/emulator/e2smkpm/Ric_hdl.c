/** sctp_server **/

#define E2_ASN_OK 0

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
#include "e2sm_kpm_asn_enc_dec_3gpp.h"
 #include "rtsrc/rtPrint.h"
   #include "rtsrc/rtCopy.h"
 #include "rtsrc/rtPrintToString.h"
   #include "rtsrc/rtPrintToStream.h"
  #include "rtxsrc/rtxCharStr.h"
   #include "rtxsrc/rtxCommon.h"
#include <netinet/in.h>
#include <netinet/sctp.h>
#include <stdint.h>  // for uint8_t


 e2_return_et encode_ric_subscription_request
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len
)
{

   e2ap_E2AP_PDU                           e2ap_pdu;
   OSCTXT                                  asn1_ctx;
   e2ap_RICsubscriptionRequest            *p_asn_ric_subscription_request = NULL;
   e2_return_et                            response = E2_SUCCESS;

   struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
   UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg=NULL;
   UInt8   *p_event_msg1=NULL;
   UInt16  *p_event_msg_len=malloc(sizeof(UInt16));
   UInt16  *p_event_msg_len1=malloc(sizeof(UInt16));
   pvalue->ricRequestorID=123;
   pvalue->ricInstanceID=6;
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
      *p_value_ie2=3; 
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
        memset(p_value_ie3,0,sizeof(e2ap_RICsubscriptionDetails));
        if(NULL == p_value_ie3)
        {
          //  GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
          printf("\n\n\nMemory allocation failed !!\n\n\n"); 
	  response = E2_FAILURE;
          break;
        }

	e2ap_RICactions_ToBeSetup_List_element           *listE=NULL;

     int a=0;
	E2SM_KPM_EventTriggerDefinition 		*p_event=NULL;
     // E2SM_KPM_EventTriggerDefinition_Format1  *p_event=NULL;
	p_event=rtxMemAllocTypeZ(&asn1_ctx,E2SM_KPM_EventTriggerDefinition);                                                   
        memset(p_event,0,sizeof(E2SM_KPM_EventTriggerDefinition));
 //	p_event->t=1;

	//p_event->eventDefinition_formats=rtxMemAllocTypeZ(&asn1_ctx,E2SM_KPM_EventTriggerDefinition);                                                   
    //p_value_ie3->p_RICsubscriptionDetailsp_RICsubscriptionDetailsricEventTriggerDefinition=rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICeventTriggerDefinition);

	      //printf("\n\n=eveneventt=====%p===========\n",&(p_event->eventDefinition_formats.u.eventDefinition_Format1));
	printf("\n%p\n",&p_event);
	p_event->eventDefinition_formats.t=T_E2SM_KPM_EventTriggerDefinition_eventDefinition_formats_eventDefinition_Format1;
	      printf("\n\n=eveneventt=====%p===========\n",(p_event->eventDefinition_formats.u.eventDefinition_Format1));
	//p_event->eventDefinition_formats.u.eventDefinition_Format1=rtxMemAllocTypeZ(&asn1_ctx,E2SM_KPM_EventTriggerDefinition_Format1);                                                   
         //p_event->eventDefinition_formats.u.eventDefinition_Format1->reportingPeriod=25000; 
    
       p_event->extElem1.count=1;
	rtxDListInit(&(p_event->extElem1));
	 E2SM_KPM_EventTriggerDefinition_Format1          *format1=NULL;
      //   unsigned int bits=sizeof(E2SM_KPM_EventTriggerDefinition_Format1);
	 format1=rtxMemAllocTypeZ(&asn1_ctx,E2SM_KPM_EventTriggerDefinition_Format1);
	      printf("\n\n=format1=====%p===========\n",format1);
	p_event->eventDefinition_formats.u.eventDefinition_Format1=format1;                                                   
        //p_event->eventDefinition_formats.u.eventDefinition_Format1->reportingPeriod=25000; 

        format1->reportingPeriod=30000; 
       rtxDListInit(&(format1->extElem1));
	//	a=asn1Init_e2ap_RICeventTriggerDefinition(&p_value_ie3->ricEventTriggerDefinition);
     // printf("\n\n===asn1Init_e2ap_RICeventTriggerDefinition===a=%d===========\n",a);
     // p_event->reportingPeriod=25000;
	//	asn1Print_E2SM_KPM_EventTriggerDefinition("Event_trigger_definition",p_event);
       // a=asn1PE_E2SM_KPM_EventTriggerDefinition_eventDefinition_formats(&asn1_ctx,&p_event->eventDefinition_formats);
      //printf("\n\n===asn1PE_E2SM_KPM_EventTriggerDefinition_eventDefinition_formats===a=%d===========\n",a);

//	rtxDListInit(&(p_event->extElem1));
	
         p_event_msg=malloc(E2CU_ASN1_BUFFER_LENGTH);
	 asn1Print_E2SM_KPM_EventTriggerDefinition("Event_trigger_definition",p_event);
         if( RT_OK != pu_setBuffer(&asn1_ctx, p_event_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
         {
          //  GNB_TRACE(GNB_ERROR,"pu_setBuffer failed.");
            printf("\n\npu_setBuffer failed.\n");
            response = E2_FAILURE;
            break;
         }                                  
	else             
        printf("\npu_setBuffer success.\n\n");
	a=asn1PE_E2SM_KPM_EventTriggerDefinition(&asn1_ctx,p_event);
        printf("\n\n===asn1PE_E2SM_KPM_EventTriggerDefinition===a=%d===========\n",a);
        *p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
	printf("p_event_msg_len :%d\n\n",*p_event_msg_len);
	printf("p_event_msg : %x\n\n",*p_event_msg);
        for(a=0; a< *p_event_msg_len; a ++)
        {
          fprintf(stderr, "%02x ", p_event_msg[a]);
        }
	a=0;
         fprintf(stderr, "\n");
// assign p_event_msg to ricEventTriggerDefinition
        p_value_ie3->ricEventTriggerDefinition.numocts=*p_event_msg_len;
	p_value_ie3->ricEventTriggerDefinition.data=(OSOCTET *)p_event_msg;
 	printf("=====numocts : %d===\n\n\n", p_value_ie3->ricEventTriggerDefinition.numocts);
 	printf("=====data : %x===\n\n\n", *p_value_ie3->ricEventTriggerDefinition.data);
        for(a=0; a<p_value_ie3->ricEventTriggerDefinition.numocts; a ++)
        {
          fprintf(stderr, "%02x ", p_value_ie3->ricEventTriggerDefinition.data[a]);
        }
	a=0;
	
	
	E2SM_KPM_ActionDefinition		  *p_action=NULL;
        p_action=rtxMemAllocTypeZ(&asn1_ctx,E2SM_KPM_ActionDefinition);
	if(p_action==NULL)
	{
		printf("====Mem alloc failed !!======\n\n");
	}
	p_action->actionDefinition_formats.t=T_E2SM_KPM_ActionDefinition_actionDefinition_formats_actionDefinition_Format3;
        p_action->actionDefinition_formats.u.actionDefinition_Format3=rtxMemAllocTypeZ(&asn1_ctx, E2SM_KPM_ActionDefinition_Format3);	
	if(p_action->actionDefinition_formats.u.actionDefinition_Format3==NULL)
	{
		printf("=====Mem alloc failed !!========\n\n");
	}
	//asn1Print_E2SM_KPM_ActionDefinition("Action Definition",p_action);
        p_action->actionDefinition_formats.u.actionDefinition_Format3->granulPeriod=15000;
	p_action->ric_Style_Type=3;
	E2SM_KPM_MeasurementCondItem	              *meas=NULL;
//	E2SM_KPM_MeasurementType		*measType=NULL;
	E2SM_KPM_MatchingCondItem 		*Cond=NULL;
	
	int      a1=0;

	OSRTDListNode		*Node=NULL;
	OSRTDListNode	        *Node1=NULL;
			
        rtxDListInit(&(p_action->actionDefinition_formats.u.actionDefinition_Format3->measCondList));
        //asn1Init_e2ap_RANfunctionsID_List(&(p_action->actionDefinition_formats.u.actionDefinition_Format3->measCondList));
	asn1Init_E2SM_KPM_MatchingCondList(&(p_action->actionDefinition_formats.u.actionDefinition_Format3->measCondList));
        int loop =0 ;
        for (loop = 0 ; loop < 2 ; loop++ )
	{  
            rtxDListAllocNodeAndData(&asn1_ctx,
                  E2SM_KPM_MeasurementCondItem,
                  &Node,&meas);

            memset(meas ,0,sizeof(E2SM_KPM_MeasurementCondItem));
	    meas->measType.t=T_E2SM_KPM_MeasurementType_measID;
            if(loop==0)
	    {
	    rtxDListInit(&(meas->matchingCond));
        //    asn1Init_e2ap_RANfunctionsID_List(&(meas->matchingCond));
	    }
            switch(loop)
	    {
              case 0:
	asn1Init_E2SM_KPM_MatchingCondList(&(meas->matchingCond));
		meas->measType.u.measID=301;
            	rtxDListAllocNodeAndData(&asn1_ctx,
                  E2SM_KPM_MatchingCondItem,
                  &Node1,&Cond);
		  Cond->t=T_E2SM_KPM_MatchingCondItem_measLabel;
 		  Cond->u.measLabel=malloc(sizeof(E2SM_KPM_MeasurementLabel));
		  Cond->u.measLabel->m.noLabelPresent=1;
		  Cond->u.measLabel->noLabel=0;
 		  //Cond->u.testCondInfo->testType.u.gBR=1;
            	  rtxDListAppendNode (
                  &(meas->matchingCond),
                  Node1);		
                  break;
              case 1:
	    rtxDListInit(&(meas->matchingCond));
	asn1Init_E2SM_KPM_MatchingCondList(&(meas->matchingCond));
		meas->measType.u.measID=302;
            	rtxDListAllocNodeAndData(&asn1_ctx,
                  E2SM_KPM_MatchingCondItem,
                  &Node1,&Cond);
		  Cond->t=T_E2SM_KPM_MatchingCondItem_measLabel;
 		  Cond->u.measLabel=malloc(sizeof(E2SM_KPM_MeasurementLabel));
		  Cond->u.measLabel->m.noLabelPresent=1;
		  Cond->u.measLabel->noLabel=0;
		 // Cond->u.testCondInfo->testType.u.gBR=1;
		  rtxDListAppendNode (
                  &(meas->matchingCond),
                  Node1);
                  break;
            }

            rtxDListAppendNode (
                  &(p_action->actionDefinition_formats.u.actionDefinition_Format3->measCondList),
                  Node);
        }
//	asn1Print_E2SM_KPM_MeasurementInfoItem("Meas_Type_List",meas);

        rtxDListInit(&(p_value_ie3->ricAction_ToBeSetup_List));
        asn1Init_e2ap_RICactions_ToBeSetup_List(&(p_value_ie3->ricAction_ToBeSetup_List));

	Node1=NULL;
//	asn1Print_e2ap_RICactions_ToBeSetup_List("ricAction_ToBeSetup_List",&(p_value_ie3->ricAction_ToBeSetup_List));	
	a=0;
	
	asn1Print_E2SM_KPM_ActionDefinition("Action Definition",p_action);
        p_event_msg1=malloc(E2CU_ASN1_BUFFER_LENGTH);
	memset(p_event_msg1,'\0',E2CU_ASN1_BUFFER_LENGTH);
        if( RT_OK != pu_setBuffer(&asn1_ctx,p_event_msg1,E2CU_ASN1_BUFFER_LENGTH, TRUE))
	{
            printf("\n\npu_setBuffer failed.\n");
            response = E2_FAILURE;
            break;		
	}
        printf("\npu_setBuffer success.\n\n");
	p_action->ric_Style_Type=1;
	a=asn1PE_E2SM_KPM_ActionDefinition(&asn1_ctx,p_action);		
	printf("\n\n===asn1PE_E2SM_KPM_ActionDefinition===a=%d===========\n",a);
        *p_event_msg_len1 = (UInt16)pe_GetMsgLen(&asn1_ctx);
	printf("p_event_msg_len :%d\n\n",*p_event_msg_len1);
	printf("p_event_msg : %x\n\n",*p_event_msg1);
        for(a=0; a< *p_event_msg_len1; a ++)
        {
           fprintf(stderr, "%02x ", p_event_msg1[a]);
        }
	a=0;
        for (a = 0 ; a < 1 ; a++ )
	{  
            rtxDListAllocNodeAndData(&asn1_ctx,
                  e2ap_RICactions_ToBeSetup_List_element,
                  &Node1,&listE);

            memset(listE ,0,sizeof(e2ap_RICactions_ToBeSetup_List_element));
	    listE->id=19;
	    listE->criticality=1;
	    listE->value.t=T5e2ap___e2ap_RICaction_ToBeSetup_ItemIEs_1;
	    listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1=rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICaction_ToBeSetup_Item);
	    if( listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1 ==NULL)
		{
			printf("Malloc Failed !!\n\n\n");
			break;
		}
	    listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->m.ricActionDefinitionPresent=1;
	    listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->m.ricSubsequentActionPresent=1;
	    listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricSubsequentAction.ricSubsequentActionType=e2ap_continue_;
	    listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricSubsequentAction.ricTimeToWait=e2ap_w1ms;
	    listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionID=1;
	    listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionType=e2ap_report;
	    listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionDefinition.numocts=*p_event_msg_len1;
	    listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionDefinition.data=p_event_msg1;
	    
            switch(a)
	    {
              case 0:
                  break;
              case 1:
                  break;
            }

            rtxDListAppendNode (
                  &(p_value_ie3->ricAction_ToBeSetup_List),
                  Node1);
        }
//	p_value_ie3->ric_action_to_be_setup_element[0].ric_action_to_be_setup_list.ric_action_id =123;
//	p_value_ie3->ric_action_to_be_setup_element[0].ric_action_to_be_setup_list.ric_action_type =1;
	

    

      if (RT_OK != asn1Append_e2ap_RICsubscriptionRequest_protocolIEs_3(&asn1_ctx,&p_asn_ric_subscription_request->protocolIEs,p_value_ie3))
      {
       //  GNB_TRACE(GNB_ERROR, "Failed to Add IE3 !!");
        printf("\n\n\nFailed to Add IE3 !!\n\n\n"); 
//	response = E2_FAILURE;
       // break;
      }
       //  GNB_TRACE(GNB_INFO, " IE3 encoded");

      printf("\n\n\n IE3 encoded\n\n\n");
 	printf("=====numocts : %d===\n\n\n", p_value_ie3->ricEventTriggerDefinition.numocts);
 	printf("=====data : %x===\n\n\n", *p_value_ie3->ricEventTriggerDefinition.data);
	printf("p_event_msg : %s\n\n", listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionDefinition.data);
      /*   e2ap_E2nodeComponentConfigAdditionAck_List *p_value_ie5 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RANfunctionsID_List);
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
	 }*/

         /* ASN Encode message */
         if( RT_OK != pu_setBuffer(&asn1_ctx, p_asn_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
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
      for (loop = 0 ; loop < 2 ; loop++ ){  
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
                  p_data_ran_func_id->value.u._e2ap_RANfunctionID_ItemIEs_1->ranFunctionID = 3;
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
         e2ap_E2nodeComponentConfigAdditionAck_List *p_value_ie5 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RANfunctionsID_List);
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

   

    
int main()
{
    int Sockfd, connSock, ret, in, flags, datalen;
    struct sockaddr_in servaddr;
    struct sctp_initmsg initmsg;
    struct sctp_event_subscribe events;
    struct sctp_sndrcvinfo sndrcvinfo;

    UInt8   octet_bitstring[4196];  // Use uint8_t for the octet bitstring
    char* ip = "192.168.11.244";

UInt8                                          *pp_asn_msg=NULL,*pp_asn_msg1=NULL; 
 UInt16                                         p_asn_msg_len,p_asn_msg_len1;

 e2_return_et                            ret1=0;

 printf("============Starting RIC Emulator============\n\n\n");
 ret=encode_ric_subscription_request(&pp_asn_msg1,&p_asn_msg_len1);
 /** Create a socket **/
    Sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_SCTP);
    if (Sockfd == -1)
    {
        printf("Failed to create socket\n");
        perror("socket()");
        exit(1);
    }

    /** Name the socket **/
    bzero((void*)&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("10.1.103.57");
    servaddr.sin_port = htons(32222);

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
    connSock = accept(Sockfd, (struct sockaddr*)NULL, (int*)NULL);
    if (connSock == -1)
    {
        printf("accept() failed\n");
        perror("accept()");
        close(connSock);
        exit(EXIT_FAILURE);
    }
    else
    printf("New client connected....\n");
int i=0;
        int len;
    while (1)
    {
        // Clear the octet bitstring
        memset(octet_bitstring, 0, sizeof(UInt8));
        in = sctp_recvmsg(connSock,(void *)octet_bitstring,8196,
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
        // Modify how you input data for the octet bitstring
        /*printf("Enter data for the octet bitstring (in hexadecimal): ");
        for ( i = 0; i < 100; i++)
        {
            scanf("%02hhX", &octet_bitstring[i]);
        }
        datalen = 100;*/


            printf("==========Initiating Encoding of e2 setup response=========\n\n\n");
        /*Encode E2 setup respose */
     while(1)
	{
	if(pp_asn_msg==NULL)
	{
	ret=encode_e2_setup_response(&pp_asn_msg,&p_asn_msg_len);
        }
	ret = sctp_sendmsg(connSock,pp_asn_msg,p_asn_msg_len, NULL, 0, 0, 0, 0, 0, 0);
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
        printf("==========Initiating Encoding of RIC Subscription Request=========\n\n\n");
   while(1)
	{
	if(pp_asn_msg1==NULL)
	{
//	ret=encode_ric_subscription_request(&pp_asn_msg1,&p_asn_msg_len1);  
        }
	ret = sctp_sendmsg(connSock,pp_asn_msg1,p_asn_msg_len1, NULL, 0, 0, 0, 0, 0, 0);
        if (ret == -1)
        {
            printf("Error in sctp_sendmsg\n");
            perror("sctp_sendmsg()");
            sleep(1);
	    continue;
        }
	else
	{
	printf("RIC Subscription Request sent successfully !!\n\n");
	break;	
	}
	
    }
    while(1)
    {
       	memset(octet_bitstring, 0, sizeof(UInt8));
       	in = sctp_recvmsg(connSock, octet_bitstring, sizeof(UInt8),
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
       	}
    }
	while(1);	
    close(connSock);
    return 0;
}
