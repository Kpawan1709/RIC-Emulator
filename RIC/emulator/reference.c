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
  // memset(p_asn_msg, 0, E2CU_ASN1_BUFFER_LENGTH);



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
	 int c=0;
          //c= asn1PE_e2ap_E2nodeComponentConfigAdditionAck_List(&asn1_ctx, p_value_ie5);
          //printf("\n\n===asn1PE_e2ap_E2nodeComponentConfigAdditionAck_List===a=%d===========\n",c);
          c= asn1PE_e2ap_E2setupResponse(&asn1_ctx, p_asn_e2_setup_response);
          printf("\n\n===asn1PE_e2ap_E2setupResponse===a=%d===========\n",c);


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

//  ***************** ric subscription resopnse ********************** //

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


   //GNB_TRACE(GNB_INFO, "encode_e2_subscription_response");
   printf( "\n\n\nencode_e2_subscription_response\n\n");
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


   } while (0);

  // asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);


   return response;
}


//  *****************  e2ap_RICsubscriptionDeleteResponse ********************** //

 e2_return_et encode_ric_subscription_delete_response
(
    UInt8   **pp_asn_msg,
    UInt16  *p_asn_msg_len
)
{
    e2ap_E2AP_PDU                         e2ap_pdu;
    OSCTXT                                 asn1_ctx;
    e2ap_RICsubscriptionDeleteResponse     *p_asn_ric_subscription_delete_response = NULL;
    e2_return_et                           response = E2_SUCCESS;

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


   //GNB_TRACE(GNB_INFO, "encode_e2ap_RICsubscriptionDeleteResponse");
   printf( "\n\n\nencode_e2ap_RICsubscriptionDeleteResponse\n\n");
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
       p_asn_ric_subscription_delete_response =
		   rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICsubscriptionDeleteResponse);

	   if(NULL == p_asn_ric_subscription_delete_response)
	   {
		   response = E2_FAILURE;
		   break;
	   }
     asn1SetTC_e2ap_SuccessfulOutcome_ricSubscriptionDelete(
			   &asn1_ctx,
			   e2ap_pdu.u.successfulOutcome,
               p_asn_ric_subscription_delete_response);


      if (RT_OK != asn1Append_e2ap_RICsubscriptionDeleteResponse_protocolIEs_1(&asn1_ctx,&p_asn_ric_subscription_delete_response->protocolIEs,pvalue))
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


	   if (RT_OK != asn1Append_e2ap_RICsubscriptionDeleteResponse_protocolIEs_2(&asn1_ctx,&p_asn_ric_subscription_delete_response->protocolIEs,*p_value_ie2))
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

    }while (0);
    return response;
}

// *********************** e2ap_RICsubscriptionDeleteRequired ************************** //

e2_return_et encode_RIC_subscription_Delete_Required
(
 UInt8                                          **pp_asn_msg,
 UInt16                                         *p_asn_msg_len
)
{

   e2ap_E2AP_PDU                           e2ap_pdu;
   OSCTXT                                  asn1_ctx;
   e2ap_RICsubscriptionDeleteRequired     *p_asn_RIC_subscription_Delete_Required = NULL;
   e2_return_et                            response = E2_SUCCESS;

   struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
   UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg1=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt16  *p_event_msg_len=malloc(sizeof(UInt16));
   UInt16  *p_event_msg_len1=malloc(sizeof(UInt16));
   int a=0;

   OSRTDListNode *node1 = NULL;
   e2ap_RICsubscriptionDeleteRequired_protocolIEs_element *pvalue1 = NULL;



   OSRTDListNode *Node2 = NULL;
   e2ap_RICsubscription_List_withCause_element *pvalue2= NULL;



   //OSRTDListNode *Node3 = NULL;
   //e2ap_RICsubscription_withCause_Item *pvalue3 = NULL;

   printf (" p_asn_msg : %p",p_asn_msg);
   if (NULL == p_asn_msg)
   {
	   //GNB_TRACE(GNB_ERROR, "Memory Allocation for p_asn_msg Failed !!");
	   printf("\n\n\nFailed !!\n\n");
	   return E2_FAILURE;
   }
   memset(p_asn_msg,0,sizeof(UInt8));


   //GNB_TRACE(GNB_INFO, "encode_e2_subscription_req");
   printf( "\n\n\nencode_RIC_subscription_Delete_Required\n\n");
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

      /* ===== CRITICAL: Set procedure code, criticality, and discriminator ===== */
      e2ap_pdu.u.initiatingMessage->procedureCode = 12;
      e2ap_pdu.u.initiatingMessage->criticality = e2ap_reject;

     // asn1SetTC_e2ap_InitiatingMessage_ricSubscriptionDeleteRequired(&asn1_ctx, e2ap_pdu.u.initiatingMessage,NULL);

      e2ap_pdu.u.initiatingMessage->value.t = T1e2ap__ricSubscriptionDeleteRequired;
      e2ap_pdu.u.initiatingMessage->value.u.ricSubscriptionDeleteRequired =
         rtxMemAllocTypeZ(&asn1_ctx, e2ap_RICsubscriptionDeleteRequired);

      if (!e2ap_pdu.u.initiatingMessage->value.u.ricSubscriptionDeleteRequired)
      {
         printf("Memory allocation failed for RICsubscriptionDeleteRequired\n");
         response = E2_FAILURE;
         break;
      }

      asn1Init_e2ap_RICsubscriptionDeleteRequired(
         e2ap_pdu.u.initiatingMessage->value.u.ricSubscriptionDeleteRequired);

      e2ap_RICsubscriptionDeleteRequired *pvalue =
         e2ap_pdu.u.initiatingMessage->value.u.ricSubscriptionDeleteRequired;

      rtxDListInit(&pvalue->protocolIEs);

      /* ===== Create ProtocolIEs element ===== */

        // rtxMemAllocTypeZ(&asn1_ctx, e2ap_RICsubscriptionDeleteRequired_protocolIEs_element);
      rtxDListAllocNodeAndData(&asn1_ctx,
                      e2ap_RICsubscriptionDeleteRequired_protocolIEs_element,
                         &node1,
                        &pvalue1);


      if (!pvalue1)
      {
         printf("Memory allocation failed for ProtocolIE\n");
         response = E2_FAILURE;
         break;
      }

      pvalue1->id = 4;
      pvalue1->criticality = e2ap_ignore;
      pvalue1->value.t = T13e2ap___e2ap_RICsubscriptionDeleteRequired_IEs_1;

      pvalue1->value.u._e2ap_RICsubscriptionDeleteRequired_IEs_1 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICsubscription_List_withCause);
      if(NULL == pvalue1->value.u._e2ap_RICsubscriptionDeleteRequired_IEs_1)
      {
         printf("Memory allocation failed for ProtocolIE\n");
         response = E2_FAILURE;
         break;
      }


      OSRTDList *tempList = (OSRTDList*)rtxMemAllocType(&asn1_ctx, OSRTDList);
      if(NULL == tempList)
      {
         printf("Memory allocation failed for list structure\n");
         response = E2_FAILURE;
         break;
      }
      rtxDListInit(tempList);

       pvalue1->value.u._e2ap_RICsubscriptionDeleteRequired_IEs_1 =
          (e2ap_RICsubscription_List_withCause*)tempList;

      printf("Allocated list at: %p\n", pvalue1->value.u._e2ap_RICsubscriptionDeleteRequired_IEs_1);
      printf("List head: %p\n", tempList);



         //pvalue2 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICsubscription_List_withCause_element);
         rtxDListAllocNodeAndData(&asn1_ctx,
                           e2ap_RICsubscription_List_withCause_element,
                              &Node2,
                              &pvalue2);

         if(NULL == pvalue2)
         {
               printf("Memory allocation failed for ProtocolIE\n");
            response = E2_FAILURE;
            break;
         }

            //e2ap_RICsubscription_List_withCause *pvalue2 = pvalue1->value.u._e2ap_RICsubscriptionDeleteRequired_IEs_1;


         pvalue2->id = 1;
         pvalue2->criticality = e2ap_ignore;

         pvalue2->value.t = T14e2ap___e2ap_RICsubscription_withCause_ItemIEs_1;


         pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICsubscription_withCause_Item);
         if(NULL == pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1)
         {
            response = E2_FAILURE;
            break;
         }

        // asn1Print_e2ap_RICsubscription_List_withCause_element("list2", pvalue2);


          //OSRTDList *tempList1 = (OSRTDList*)rtxMemAllocType(&asn1_ctx, OSRTDList);
         //if(NULL == tempList1)
         //{
           // printf("Memory allocation failed for list structure\n");
           // response = E2_FAILURE;
          //  break;
         //}
         //rtxDListInit(tempList1);

         //pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1 =
           // (e2ap_RICsubscription_List_withCause*)tempList1;

         //printf("Allocated list at: %p\n", pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1);
         //printf("List head: %p\n", tempList1);



         //OSRTDListNode *Node3 = NULL;
         //e2ap_RICsubscription_withCause_Item *pvalue3= NULL;
         //pvalue3 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICsubscription_withCause_Item);

               // pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1;
          //  rtxDListAllocNodeAndData(&asn1_ctx,
                  //         e2ap_RICsubscription_withCause_Item,
                //              &Node3,
              //                &pvalue3);
            //if(NULL == pvalue3)
            //{
             //  printf("\n\n alloc failed for pvalue3 \n");
            //response = E2_FAILURE;
            //break;
           // }

         /* ===== RICrequestID ===== */
         pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1->ricRequestID.ricRequestorID =1;
         pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1->ricRequestID.ricInstanceID = 55068;

         /* ===== RANfunctionID ===== */
         pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1->ranFunctionID = 2;

         /* ===== Cause ===== */
        // pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1->cause.t = T_e2ap_Cause_misc;
        // pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1->cause.u.misc = e2ap_unspecified;



         switch(a)
         {
            case 0:
            pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1->cause.t = T_e2ap_Cause_misc;
            pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1->cause.u.misc = e2ap_control_processing_overload;
            break;

            case 1:
            pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1->cause.t = T_e2ap_Cause_misc;
            pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1->cause.u.misc = e2ap_hardware_failure;
            break;

            case 2:
            pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1->cause.t = T_e2ap_Cause_misc;
            pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1->cause.u.misc = e2ap_om_intervention;
            break;

            case 3:
            pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1->cause.t = T_e2ap_Cause_misc;
            pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1->cause.u.misc = e2ap_unspecified;
            default:break;
         }



         printf("\n\n after asn1print \n");
        // asn1Print_e2ap_RICsubscription_withCause_Item("list3",pvalue3);

        // rtxDListAppendNode(&pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1,Node3);

         //pvalue2->value.u._e2ap_RICsubscription_withCause_ItemIEs_1 = Node3;

        // rtxDListAppendNode(&pvalue1->value.u._e2ap_RICsubscriptionDeleteRequired_IEs_1,Node2);
         rtxDListAppendNode(pvalue1->value.u._e2ap_RICsubscriptionDeleteRequired_IEs_1, Node2);


      rtxDListAppendNode(&pvalue->protocolIEs,node1);

      //asn1Print_e2ap_RICsubscriptionDeleteRequired_protocolIEs_element("test2",pvalue1);
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





   } while (0);


 //  asn1Print_e2ap_RICsubscription_List_withCause_element("list2", pvalue2);
  // asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);

   return response;
}

int main()
{
    int Sockfd, connSock1,connSock, ret, in,in1, flags, datalen;
    struct sockaddr_in servaddr;
    struct sctp_initmsg initmsg;
    struct sctp_event_subscribe events;
    struct sctp_sndrcvinfo sndrcvinfo;
    GUAMI  *myguami=NULL;
    UInt8   octet_bitstring[4196];  // Use uint8_t for the octet bitstring
    char* ip = "192.168.166.22";
    myguami=malloc(sizeof(GUAMI));
    e2ap_InitiatingMessage            *Initiating=NULL;

    E2SM_RC_CallProcessID             *ric_call=NULL;
    UInt8                             *pp_asn_msg=NULL,*pp_asn_msg1=NULL,pp_asn_msg2=NULL; 
    UInt16                            p_asn_msg_len,p_asn_msg_len1,p_asn_msg_len2;

    E2SM_RC_IndicationHeader         *header=NULL;

     e2_return_et                            ret1=0;

    printf("============Starting RIC Emulator============\n\n\n");
    //ret=encode_ric_subscription_request(&pp_asn_msg1,&p_asn_msg_len1,myguami);
     ret=encode_e2_setup_response(&pp_asn_msg1,&p_asn_msg_len1);
    
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
    servaddr.sin_addr.s_addr = inet_addr("10.1.210.205");
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

 e2ap_E2AP_PDU    pdu;
    OSCTXT                                  asn1_ctx;
   
    if(E2_ASN_OK != rtInitContext(&asn1_ctx))
    {
    //   GNB_TRACE(GNB_ERROR, "ASN Context Initialization Failed");
      printf("\n\n\nASN Context Initialization Failed\n\n");
    }
     if (E2_ASN_OK !=
            pu_setBuffer(&asn1_ctx, (OSUINT8 *)octet_bitstring, in, E2_TRUE))
        {
            //GNB_TRACE(GNB_ERROR, "Failed pu_setBuffer for RIC SUbscription Request");
            printf("==========Failed pu_setBuffer for RIC SUbscription Request=========\n\n\n");
        }
        E2_MEMSET(&pdu, E2_ZERO, sizeof(pdu));

    asn1PD_e2ap_E2AP_PDU(&asn1_ctx,&pdu);
    asn1Print_e2ap_E2AP_PDU("e2ap_pdu",&pdu);


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

      printf("==========Initiating Encoding of ric subscription response=========\n\n\n");
        /*Encode ric subscription respose */
        pp_asn_msg=NULL;
     while(1)
        {
        if(pp_asn_msg==NULL)
           {
         ret=encode_ric_subscription_response(&pp_asn_msg,&p_asn_msg_len);
         //ret=encode_ric_subscription_request(&pp_asn_msg,&p_asn_msg_len,myguami);

      }
          // ret = sctp_sendmsg(Sockfd,pp_asn_msg,p_asn_msg_len, NULL, 0, 0, 0, 0, 0, 0);
           ret = sctp_sendmsg(connSock1, pp_asn_msg, p_asn_msg_len, NULL, 0, 0, 0, 0, 0, 0);

        if (ret == -1)
           {
            printf("Error in sctp_sendmsg\n");
            perror("sctp_sendmsg()");
            sleep(1);
            continue;
           }
        else
           {
                printf("Ric subscription response sent successfully !!\n\n");
                break;
           }
        }
     //while(1)
      printf("==========Initiating Encoding of e2ap_RICsubscriptiondeleteresponse=========\n\n\n");
        /*Encode e2ap_RICsubscriptiondeleteresponse */
        pp_asn_msg=NULL;
        while(1)
        {
                if(pp_asn_msg==NULL)
                {
		        ret=encode_ric_subscription_delete_response(&pp_asn_msg,&p_asn_msg_len);
                       // ret=encode_RIC_subscription_Delete_Required(&pp_asn_msg,&p_asn_msg_len);
                        //ret=encode_e2_setup_response(&pp_asn_msg,&p_asn_msg_len);
                        //ret=encode_ric_subscription_request(&pp_asn_msg,&p_asn_msg_len,myguami);
                }
               // ret = sctp_sendmsg(Sockfd,pp_asn_msg,p_asn_msg_len, NULL, 0, 0, 0, 0, 0, 0);
               ret = sctp_sendmsg(connSock1, pp_asn_msg, p_asn_msg_len, NULL, 0, 0, 0, 0, 0, 0);

               if (ret == -1)
               {
                       printf("Error in sctp_sendmsg\n");
                       perror("sctp_sendmsg()");
                       sleep(1);
                       continue;
               }
               else
               {
                       printf("e2ap RIC subscription Delete Response sent successfully !!\n\n");
                       break;
               }

        }

    rtFreeContext(&asn1_ctx);
    while(1);
    close(connSock);
    return 0;
}


