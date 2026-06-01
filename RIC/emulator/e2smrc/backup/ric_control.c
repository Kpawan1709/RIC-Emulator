
#include "head.h"
#define E2_ASN_OK 0



/*



e2_return_et encode_ric_control_request1
(
 UInt8                                          **pp_asn_msg,
 UInt16                                         *p_asn_msg_len
)
{
   e2ap_E2AP_PDU                  e2ap_pdu;
   OSCTXT                         asn1_ctx;
   e2ap_RICcontrolRequest                       *p_asn_ric_control_request = NULL;
   e2_return_et                   response = E2_SUCCESS;
   E2SM_RC_RAN_CallProcess_ID   *p_call=NULL;
   UInt8   *p_event_msg=NULL,*p_head_msg=NULL,*p_msg=NULL;
   UInt16       *p_event_msg_len=malloc(sizeof(UInt16));
   UInt16       *p_head_msg_len=malloc(sizeof(UInt16));
   UInt16       *p_msg_len=malloc(sizeof(UInt16));









}*/






e2_return_et encode_ric_control_request
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len,
 GUAMI                                          myguami,
E2SM_RC_CallProcessID 			        *ric_call,
E2SM_RC_IndicationHeader                        *header
 )
{
   e2ap_E2AP_PDU                  e2ap_pdu;
   OSCTXT                         asn1_ctx;
   e2ap_RICcontrolRequest			*p_asn_ric_control_request = NULL;
   e2_return_et                   response = E2_SUCCESS;
   E2SM_RC_RAN_CallProcess_ID	*p_call=NULL;  
   UInt8   *p_event_msg=NULL,*p_head_msg=NULL,*p_msg=NULL;
   UInt16	*p_event_msg_len=malloc(sizeof(UInt16));
   UInt16	*p_head_msg_len=malloc(sizeof(UInt16));
   UInt16	*p_msg_len=malloc(sizeof(UInt16));

   if(E2_ASN_OK != rtInitContext(&asn1_ctx))
   {
           //   GNB_TRACE(GNB_ERROR, "ASN Context Initialization Failed");
           printf("\n\n\nASN Context Initialization Failed\n\n");
           response = E2_FAILURE;
           return response;
   }

   memset(&e2ap_pdu, 0, sizeof(e2ap_pdu));
	  
           e2ap_pdu.t = T_e2ap_E2AP_PDU_initiatingMessage;
           e2ap_pdu.u.initiatingMessage = rtxMemAllocTypeZ(&asn1_ctx,e2ap_InitiatingMessage);
	   e2ap_pdu.u.extElem1->numocts=0;
           if(NULL ==  e2ap_pdu.u.initiatingMessage)
           {
                   //   GNB_TRACE(GNB_ERROR, "Memory allocation falied for successfulOutcome");
                   printf("\n\n\nMemory allocation falied for successfulOutcome\n\n\n");
           }
 p_asn_ric_control_request =
                   rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICcontrolRequest);

           if(NULL == p_asn_ric_control_request)
           {
                   response = E2_FAILURE;
           }
           asn1SetTC_e2ap_InitiatingMessage_ricControl(
                           &asn1_ctx,
                           e2ap_pdu.u.initiatingMessage,
               		   p_asn_ric_control_request);
   
	   
	   e2ap_pdu.u.initiatingMessage->procedureCode=ASN1V_e2ap_id_RICcontrol;
	   //p_asn_ric_control_request = (struct e2ap_RICcontrolRequest_protocolIEs_element *)malloc(sizeof(struct e2ap_RICcontrolRequest_protocolIEs_element));
	//memset(p_asn_ric_control_request, 0, sizeof(struct e2ap_RICcontrolRequest_protocolIEs_element));
	  
	
   UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
   printf (" p_asn_msg : %p",p_asn_msg);
   if (NULL == p_asn_msg)
   {
	   printf("\n\n\nFailed !!\n\n");
		return E2_FAILURE;
   }
   memset(p_asn_msg,0,E2CU_ASN1_BUFFER_LENGTH);


   printf( "\n\n\nencode_ric_control_req\n\n");


	*pp_asn_msg =  p_asn_msg;
/* Init ASN.1 context */
   /* if(E2_ASN_OK != rtInitContext(&asn1_ctx))
    {
      printf("\n\n\nASN Context Initialization Failed\n\n");
	 response = E2_FAILURE;
       return response;
    }	*/
 
    // call process 
   p_call = malloc(sizeof(E2SM_RC_RAN_CallProcess_ID));

   *p_call = 156;  
   
   p_event_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
   memset(p_event_msg,0,E2CU_ASN1_BUFFER_LENGTH);
	

   if( RT_OK != pu_setBuffer(&asn1_ctx, p_event_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
         {
            printf("\n\nRAN_CallProcess_ID pu_setBuffer failed.\n");
            response = E2_FAILURE;
            
         }                                  
	else         
        printf("\nRAN_CallProcess_ID pu_setBuffer success.\n%d\n",*p_event_msg);

     int a =  asn1PE_E2SM_RC_RAN_CallProcess_ID(&asn1_ctx,*p_call);
       printf("\nasn1PE_E2SM_RC_RAN_CallProcess_ID==%d,%d\n",a,*p_event_msg);

	*p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);		
	printf("len=%d\n",*p_event_msg_len);
       for(a=0; a < *p_event_msg_len; a ++)
        {
          printf("%02x ", p_event_msg[a]);
        }
       a=0;

       //headers control
       E2SM_RC_ControlHeader        *p_header=NULL;
       UEID_GNB_CU_F1AP_ID_List      *f1ap_list=NULL;
   	UEID_GNB_CU_CP_F1AP_ID_Item   *f1ap_item=NULL;
	OSRTDListNode                   *pnode=NULL; 
	OSRTDListNode                   *pnode1=NULL; 
       p_head_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
   memset(p_head_msg,0,E2CU_ASN1_BUFFER_LENGTH);
       p_header  = malloc(sizeof(E2SM_RC_ControlHeader));
	memset(p_header,0,sizeof(E2SM_RC_ControlHeader));
	
	p_header->ric_controlHeader_formats.t=T_E2SM_RC_ControlHeader_ric_controlHeader_formats_controlHeader_Format1;
	
	p_header->ric_controlHeader_formats.u.controlHeader_Format1=malloc(sizeof(E2SM_RC_ControlHeader_Format1));
	p_header->ric_controlHeader_formats.u.controlHeader_Format1->m.ric_ControlDecisionPresent=1;
	p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.t=T_UEID_gNB_UEID;
//	p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID = ((UEID*)malloc(sizeof(UEID)));
//	p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.t=1;
	p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID=((malloc(sizeof(UEID_GNB))));
	p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->m.gNB_CU_UE_F1AP_ID_ListPresent=1;
	
	if(ric_call!=NULL)
	{	
	p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->amf_UE_NGAP_ID=ric_call->ric_callProcessID_formats.u.callProcessID_Format1->ric_callProcess_ID;
	}
	else
	{
	p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->amf_UE_NGAP_ID=1234;
	
	}

 p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->m.gNB_CU_UE_F1AP_ID_ListPresent=1;
        //p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->amf_UE_NGAP_ID=ric_call->ric_callProcessID_formats.u.callProcessID_Format1->ric_callProcess_ID;
        //p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->amf_UE_NGAP_ID=12345;
       // p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->data;

	
	if(header!=NULL)
	{	
	p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami=header->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->guami;
	}
	else
	{
	p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami=myguami;
	
	}
	/*p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami.pLMNIdentity.data[0]=0x23;
	p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami.pLMNIdentity.data[0]=0x31;
	p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami.pLMNIdentity.numocts=3;
   p_event_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
                printf("\n\n\n\n%p\n\n.\n",p_event_msg);
         if( RT_OK != pu_setBuffer(&asn1_ctx, &p_event_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
        {
                printf("\n\nControlMessage pu_setBuffer failed.\n");
                response = E2_FAILURE;
        }
        else
                printf("\nControlMessage pu_setBuffer success.\n\n");


        a=asn1PE_PLMNIdentity( &asn1_ctx,&p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami.pLMNIdentity);
	printf("\asn1PE_PLMNIdentity==%d,%d\n",a); 
                    //        printf("\ndata=%d.\n\n",*p_event_msg);
                                   *p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);

	p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami.pLMNIdentity.numocts=3;


         if( RT_OK != pu_setBuffer(&asn1_ctx, &p_event_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
        {
                printf("\n\nControlMessage pu_setBuffer failed.\n");
                response = E2_FAILURE;
        }
        else
                printf("\nControlMessage pu_setBuffer success.\n\n");



	a=asn1PE_AMFRegionID	
	printf("\nasn1PE_AMFRegionID==%d,%d\n",a);*/ 
	//p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami.aMFRegionID="0x02";

	 asn1Init_UEID_GNB_CU_F1AP_ID_List(&p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->gNB_CU_UE_F1AP_ID_List);


	rtxDListAllocNodeAndData(&asn1_ctx,
                                  UEID_GNB_CU_CP_F1AP_ID_Item,
                                  &pnode,&f1ap_item);

	if(header!=NULL)
	{	
	pnode1=header->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->gNB_CU_UE_F1AP_ID_List.head;
	f1ap_item=pnode->data;
	}
	else
	{
	f1ap_item=1234;	
	}
	//	f1ap_item->gNB_CU_UE_F1AP_ID=header->ric_indicationHeader_formats.indicationHeader_Format2->ueID.gNB_UEID->gNB_CU_UE_F1AP_ID_List;
  rtxDListAppendNode (&p_header->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->gNB_CU_UE_F1AP_ID_List,
                                        pnode);



	p_header->ric_controlHeader_formats.u.controlHeader_Format1->ric_Style_Type=3;
	p_header->ric_controlHeader_formats.u.controlHeader_Format1->ric_ControlAction_ID=101;

	printf("\n\n=header=====%p===========\n",(p_header->ric_controlHeader_formats.u.controlHeader_Format1));
	

	if( RT_OK != pu_setBuffer(&asn1_ctx, p_head_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
	{
   		printf("\n\nControlHeader pu_setBuffer failed.\n");
   		response = E2_FAILURE; 
	}
	else
       		printf("\nControlHeader pu_setBuffer success.\n\n");	

	int b =  asn1PE_E2SM_RC_ControlHeader(&asn1_ctx,p_header);
	printf("\nasn1PE_E2SM_RC_ControlHeader==%d,%d\n",a,*p_head_msg); 
	*p_head_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
	printf("len=%d\n",*p_head_msg_len);
	for(b=0; b < *p_head_msg_len; b ++)
	{
     		printf("%02x ", p_head_msg[b]);
	}
	b=0;
asn1Print_E2SM_RC_ControlHeader("Control header",p_header);	
	//control message
	E2SM_RC_ControlMessage	*msg=NULL;
   	p_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
   	memset(p_msg,0,E2CU_ASN1_BUFFER_LENGTH);
        msg = malloc(sizeof(E2SM_RC_ControlMessage));
	memset(msg,0,sizeof(E2SM_RC_ControlMessage));
	
	msg->ric_controlMessage_formats.t=T_E2SM_RC_ControlMessage_ric_controlMessage_formats_controlMessage_Format1;
	msg->ric_controlMessage_formats.u.controlMessage_Format1=malloc(sizeof(E2SM_RC_ControlMessage_Format1));
	msg->ric_controlMessage_formats.u.controlMessage_Format1->ranP_List;		
	
	E2SM_RC_ControlMessage_Format1_Item	*cmsg=NULL;
	OSRTDListNode        *Node1=NULL;
        rtxDListInit(&(msg->ric_controlMessage_formats.u.controlMessage_Format1->ranP_List));
	asn1Init_E2SM_RC_ControlMessage_Format1_ranP_List(&(msg->ric_controlMessage_formats.u.controlMessage_Format1->ranP_List));
	int loop =0 ;
    /*    for (loop = 0 ; loop < 2 ; loop++ )
	{
            rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_ControlMessage_Format1_Item,&Node1,&cmsg);

            memset(cmsg,0,sizeof(E2SM_RC_ControlMessage_Format1_Item));
	    
	//    cmsg->ranParameter_ID=0;
	    //cmsg->ranParameter_valueType.t=T_E2SM_RC_RANParameter_Value_valueInt;
	    //cmsg->ranParameter_valueType.u.valueInt=2;

	    rtxDListAppendNode (&(msg->ric_controlMessage_formats.u.controlMessage_Format1->ranP_List),Node1);
	 }*/
	
	printf("\n\n=controlmessage=====%p===========\n",(msg->ric_controlMessage_formats.u.controlMessage_Format1));
	

	if( RT_OK != pu_setBuffer(&asn1_ctx, p_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
	{
   		printf("\n\nControlMessage pu_setBuffer failed.\n");
   		response = E2_FAILURE; 
	}
	else
       		printf	("\nControlMessage pu_setBuffer success.\n%d\n",*p_msg);	

	int c =  asn1PE_E2SM_RC_ControlMessage(&asn1_ctx,msg);
	printf("\nasn1PE_E2SM_RC_ControlMessage==%d,%d\n",a,*p_msg); 
	*p_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
	printf("len=%d\n",*p_msg_len);
	for(c=0; c < *p_msg_len; c ++)
	{
     		printf("%02x ", p_msg[c]);
	}
	c=0;

    	p_asn_ric_control_request = ( e2ap_RICcontrolRequest *)malloc(sizeof(e2ap_RICcontrolRequest));
	printf("\nsize of e2ap_RICcontrolRequest: %ld bytes \n",sizeof(e2ap_RICcontrolRequest));
	memset(p_asn_ric_control_request, 0, sizeof(e2ap_RICcontrolRequest));

 	
	OSRTDListNode        *Node=NULL;		
	e2ap_RICcontrolRequest_protocolIEs_element	*Data=NULL;	
	Node=NULL;
	int i;
	e2ap_RICrequestID *_e2ap_RICcontrolRequest_IEs_1;
	e2ap_RANfunctionID _e2ap_RICcontrolRequest_IEs_2;
	e2ap_RICcallProcessID *_e2ap_RICcontrolRequest_IEs_3;
	e2ap_RICcontrolHeader *_e2ap_RICcontrolRequest_IEs_4;
	e2ap_RICcontrolAckRequest *_e2ap_RICcontrolRequest_IEs_6;
	rtxDListInit(&(p_asn_ric_control_request->protocolIEs));
	asn1Init_e2ap_RICcontrolRequest_protocolIEs(&(p_asn_ric_control_request->protocolIEs));
	for(i=0 ; i<=6; i++)
	{
	
		switch(i)
		{
		case 1:
		rtxDListAllocNodeAndData(&asn1_ctx,e2ap_RICcontrolRequest_protocolIEs_element,&Node,&Data);
		Data->id=ASN1V_e2ap_id_RICrequestID;
		Data->criticality=0;
		Data->value.t=1;
		Data->value.u._e2ap_RICcontrolRequest_IEs_1 = (e2ap_RICrequestID*)malloc(sizeof(e2ap_RICrequestID));
		memset(Data->value.u._e2ap_RICcontrolRequest_IEs_1, 0, sizeof(e2ap_RICrequestID));
		Data->value.u._e2ap_RICcontrolRequest_IEs_1->ricRequestorID=3;
		Data->value.u._e2ap_RICcontrolRequest_IEs_1->ricInstanceID=55068;
                 rtxDListAppendNode (&(p_asn_ric_control_request->protocolIEs),Node);

		break;
		case 2:
		rtxDListAllocNodeAndData(&asn1_ctx,e2ap_RICcontrolRequest_protocolIEs_element,&Node,&Data);
                Data->id=ASN1V_e2ap_id_RANfunctionID;
                Data->criticality=0;
                Data->value.t=2;
		Data->value.u._e2ap_RICcontrolRequest_IEs_2=2;
                rtxDListAppendNode (&(p_asn_ric_control_request->protocolIEs),Node);


		break;
		case 3:
		rtxDListAllocNodeAndData(&asn1_ctx,e2ap_RICcontrolRequest_protocolIEs_element,&Node,&Data);
		Data->id=ASN1V_e2ap_id_RICcallProcessID;
                Data->criticality=0;
                Data->value.t=3;
		Data->value.u._e2ap_RICcontrolRequest_IEs_3 = (e2ap_RICcallProcessID*)malloc(sizeof(e2ap_RICcallProcessID));
      		memset(Data->value.u._e2ap_RICcontrolRequest_IEs_3, 0, sizeof(e2ap_RICcallProcessID));
		Data->value.u._e2ap_RICcontrolRequest_IEs_3->numocts=*p_event_msg_len;
		Data->value.u._e2ap_RICcontrolRequest_IEs_3->data=(OSOCTET *)p_event_msg;
		rtxDListAppendNode (&(p_asn_ric_control_request->protocolIEs),Node);
		printf("-----------\n");
		asn1Print_E2SM_RC_RAN_CallProcess_ID("RAN_CallProcess_ID",p_call);
		printf("-----------------\n");
		break;
		case 4:
		 rtxDListAllocNodeAndData(&asn1_ctx,e2ap_RICcontrolRequest_protocolIEs_element,&Node,&Data);
                Data->id=ASN1V_e2ap_id_RICcontrolHeader;
                Data->criticality=0;
                Data->value.t=4;
		Data->value.u._e2ap_RICcontrolRequest_IEs_4=malloc(sizeof(e2ap_RICcontrolHeader));
		Data->value.u._e2ap_RICcontrolRequest_IEs_4->numocts=*p_head_msg_len;
		Data->value.u._e2ap_RICcontrolRequest_IEs_4->data=(OSOCTET *)p_head_msg;
		asn1Print_E2SM_RC_ControlHeader("ControlHeader",p_header);
		rtxDListAppendNode (&(p_asn_ric_control_request->protocolIEs),Node);
		break;

		case 5:
		rtxDListAllocNodeAndData(&asn1_ctx,e2ap_RICcontrolRequest_protocolIEs_element,&Node,&Data);
                Data->id=ASN1V_e2ap_id_RICcontrolMessage;
                Data->criticality=0;
                Data->value.t=5;
		Data->value.u._e2ap_RICcontrolRequest_IEs_5=malloc(sizeof(e2ap_RICcontrolMessage));
		Data->value.u._e2ap_RICcontrolRequest_IEs_5->numocts=*p_msg_len;
		Data->value.u._e2ap_RICcontrolRequest_IEs_5->data=(OSOCTET *)p_msg;
		asn1Print_E2SM_RC_ControlMessage("ControlMessage",msg);
		rtxDListAppendNode (&(p_asn_ric_control_request->protocolIEs),Node);
		break;

		case 6:
		rtxDListAllocNodeAndData(&asn1_ctx,e2ap_RICcontrolRequest_protocolIEs_element,&Node,&Data);
                Data->id=ASN1V_e2ap_id_RICcontrolAckRequest;
                Data->criticality=0;
                Data->value.t=T16e2ap___e2ap_RICcontrolRequest_IEs_6;
                Data->value.u._e2ap_RICcontrolRequest_IEs_6=e2ap_ack;
		rtxDListAppendNode (&(p_asn_ric_control_request->protocolIEs),Node);
		break;

	}

}

//	asn1Print_e2ap_RICcontrolRequest_protocolIEs_element("e2ap_RICcontrolRequest_protocolIEs_element",p_asn_ric_control_request);
	asn1PrtToStrm_e2ap_RICcontrolRequest(&asn1_ctx,"e2ap_RICcontrolRequest",p_asn_ric_control_request);


	   e2ap_pdu.u.initiatingMessage->value.u.ricControl=p_asn_ric_control_request;
	printf("\n\n\n\n");
	asn1Print_e2ap_E2AP_PDU("e2ap_pdu",&e2ap_pdu);
	*pp_asn_msg =  p_asn_msg;
	if( RT_OK != pu_setBuffer(&asn1_ctx, p_asn_msg,E2CU_ASN1_BUFFER_LENGTH, TRUE))
	{
   		printf("\n\nControlMessage pu_setBuffer failed.\n");
   		response = E2_FAILURE; 
	}


	   if (0 != asn1PE_e2ap_E2AP_PDU(&asn1_ctx, &e2ap_pdu))
         {
            rtxErrPrint(&asn1_ctx);
	 }

	printf("\nasn1PE_E2SM_RC_ControlMessage==%d,%d\n",a,*p_asn_msg); 
	*p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
	printf("len=%d\n",*p_asn_msg_len);

}
