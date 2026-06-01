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
#include <stdint.h>  // for uint8_t
//#include "head.h"
 E2SM_RC_CallProcessID *  decode_ric_callProcess_id(OSCTXT *asn1_ctx,E2SM_RC_CallProcessID *ric_call,e2ap_RICindication *pdu);

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




   } while (0);

   
   asn1Print_e2ap_RICsubscription_List_withCause_element("list2", pvalue2);
   asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);

   return response;
}


//  *****************  e2ap_ResetRequest ********************** //

e2_return_et encode_reset_request
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len
)
{

   e2ap_E2AP_PDU                           e2ap_pdu;
   OSCTXT                                  asn1_ctx;
   e2ap_ResetRequest                      *p_asn_e2ap_ResetRequest = NULL;
   e2_return_et                            response = E2_SUCCESS;

   struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
   UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg1=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt16  *p_event_msg_len=malloc(sizeof(UInt16));
   UInt16  *p_event_msg_len1=malloc(sizeof(UInt16));
   int a=0;
 
   printf (" p_asn_msg : %p",p_asn_msg);
   if (NULL == p_asn_msg)
   {
	   //GNB_TRACE(GNB_ERROR, "Memory Allocation for p_asn_msg Failed !!");
	   printf("\n\n\nFailed !!\n\n");
	   return E2_FAILURE;
   }
   memset(p_asn_msg,0,sizeof(UInt8));


   //GNB_TRACE(GNB_INFO, "encode_reset_request");
   printf( "\n\n\nencode_reset_request\n\n");
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


       p_asn_e2ap_ResetRequest =
           rtxMemAllocTypeZ(&asn1_ctx, e2ap_ResetRequest);
       if(NULL == p_asn_e2ap_ResetRequest)
       {
           response = E2_FAILURE;
           break;
       }

       
      asn1SetTC_e2ap_InitiatingMessage_reset(
                       &asn1_ctx,
                       e2ap_pdu.u.initiatingMessage,
                       p_asn_e2ap_ResetRequest);

      if (RT_OK != asn1Append_e2ap_ResetRequest_protocolIEs_1(&asn1_ctx,&p_asn_e2ap_ResetRequest->protocolIEs,E2CU_ONE))
      {
        	printf("\n\nFailed to Add IE1 !!\n\n"); 
	      response = E2_FAILURE;
               break;
      }
      printf("\n\n\n IE1 encoded\n\n\n");

      e2ap_Cause *pvalue1 = NULL;
      pvalue1 = rtxMemAllocTypeZ(&asn1_ctx, e2ap_Cause);
      if(NULL == pvalue1)
      {
         response = E2_FAILURE;
         break;
      }

       int loop =0;
      switch (loop)
      {
         case 0:
         pvalue1->t =T_e2ap_Cause_misc;
         pvalue1->u.misc = e2ap_control_processing_overload; 
         break;

         case 1:
         pvalue1->t =T_e2ap_Cause_misc;
         pvalue1->u.misc = e2ap_hardware_failure; 
         break;

         case 2:
         pvalue1->t =T_e2ap_Cause_misc;
         pvalue1->u.misc = e2ap_om_intervention; 
         break;

         case 3:
         pvalue1->t =T_e2ap_Cause_misc;
         pvalue1->u.misc = e2ap_unspecified; 
         default:
         break;      
      }

      if (RT_OK != asn1Append_e2ap_ResetRequest_protocolIEs_2(&asn1_ctx,&p_asn_e2ap_ResetRequest->protocolIEs,pvalue1))
      {
         printf("\n\nFailed to Add IE2 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      printf("\n\n\n IE2 encoded\n\n\n");
      //rtxDListAppendNode(&pvalue->protocolIEs, node1);
   }
   while(0);

   asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);


   return response;
}



//  *****************  e2ap_ResetResponse ********************** //
e2_return_et encode_reset_response
(
    UInt8   **pp_asn_msg,
    UInt16  *p_asn_msg_len
)

{
    e2ap_E2AP_PDU                      e2ap_pdu;
    OSCTXT                             asn1_ctx;
    e2ap_ResetResponse                *p_asn_e2ap_ResetResponse = NULL;
    e2_return_et                      response = E2_SUCCESS;

    struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
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


   //GNB_TRACE(GNB_INFO, "encode_reset_response");
   printf( "\n\n\nencode_reset_response\n\n");
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

      p_asn_e2ap_ResetResponse =
           rtxMemAllocTypeZ(&asn1_ctx,e2ap_ResetResponse);
       if(NULL == p_asn_e2ap_ResetResponse)
       {
           response = E2_FAILURE;
           break;
       }

       
      asn1SetTC_e2ap_SuccessfulOutcome_reset(
                       &asn1_ctx,
                       e2ap_pdu.u.initiatingMessage,
                       p_asn_e2ap_ResetResponse);

      if (RT_OK != asn1Append_e2ap_ResetResponse_protocolIEs_1(&asn1_ctx,&p_asn_e2ap_ResetResponse->protocolIEs,E2CU_ONE))
      {
        	printf("\n\nFailed to Add IE1 !!\n\n"); 
	      response = E2_FAILURE;
               break;
      }
      printf("\n\n\n IE1 encoded\n\n\n");


      //OSRTDListNode                           *node1 = NULL;
     // e2ap_ResetResponse_protocolIEs_element  *pvalue1 = NULL;
     // rtxDListAllocNodeAndData(&asn1_ctx,
      //   e2ap_ResetResponse_protocolIEs_element,
      //   &node1,&pvalue1);
      //pvalue1->id = 2;
     // pvalue1->criticality = e2ap_reject;
     // pvalue1->value.t = T40e2ap___e2ap_ResetResponseIEs_2;
     // pvalue1->value.u._e2ap_ResetResponseIEs_2 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_CriticalityDiagnostics);

     e2ap_CriticalityDiagnostics *pvalue1 = NULL;
     pvalue1 =rtxMemAllocTypeZ(&asn1_ctx,e2ap_CriticalityDiagnostics);

     if(NULL == pvalue1)
     {
      printf("\n\n\nMemory allocation falied for pvalue1\n\n\n");
      response = E2_FAILURE;
      break;
   }
    

      pvalue1->m.procedureCodePresent =1;
      pvalue1->m.triggeringMessagePresent =1;
      pvalue1->m.procedureCriticalityPresent = 1;
      pvalue1->m.ricRequestorIDPresent = 1;
      pvalue1->m.iEsCriticalityDiagnosticsPresent = 1;

      pvalue1->procedureCode = 12;
      pvalue1->triggeringMessage = 1;
      pvalue1->procedureCriticality = e2ap_reject;
      //e2ap_RICrequestID
      pvalue1->ricRequestorID.ricRequestorID = 1;
      pvalue1->ricRequestorID.ricInstanceID = 55068;

      //e2ap_CriticalityDiagnostics_IE_List

      rtxDListInit(&pvalue1->iEsCriticalityDiagnostics);

      OSRTDListNode                        *node2 = NULL;
      e2ap_CriticalityDiagnostics_IE_Item  *pvalue2 = NULL;

     // pvalue2 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_CriticalityDiagnostics_IE_Item);

      rtxDListAllocNodeAndData(&asn1_ctx,
         e2ap_CriticalityDiagnostics_IE_Item,
         &node2,&pvalue2);

      pvalue2->iECriticality = e2ap_reject;
      pvalue2->iE_ID = 2;
      pvalue2->typeOfError = e2ap_not_understood;

      rtxDListAppendNode(&pvalue1->iEsCriticalityDiagnostics, node2);

      asn1Print_e2ap_CriticalityDiagnostics_IE_Item("TEST",&pvalue2);
      //asn1Print_e2ap_CriticalityDiagnostics("TEST",&pvalue1->value.u._e2ap_ResetResponseIEs_2->iEsCriticalityDiagnostics);
     if (RT_OK != asn1Append_e2ap_ResetResponse_protocolIEs_2(&asn1_ctx,&p_asn_e2ap_ResetResponse->protocolIEs,pvalue1))
      {
        	printf("\n\nFailed to Add IE2 !!\n\n"); 
	      response = E2_FAILURE;
               break;
      }
      printf("\n\n\n IE2 encoded\n\n\n");

   }
   while(0);
   asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);

   return response;
}







// ********************** e2ap_E2nodeConfigurationUpdate ********************* //

e2_return_et encode_E2node_Configuration_Update
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len
)
{

   e2ap_E2AP_PDU                           e2ap_pdu;
   OSCTXT                                  asn1_ctx;
   e2ap_E2nodeConfigurationUpdate          *p_asn_E2node_Configuration_Update = NULL;
   e2_return_et                            response = E2_SUCCESS;

   //struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
   UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg1=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt16  *p_event_msg_len=malloc(sizeof(UInt16));
   UInt16  *p_event_msg_len1=malloc(sizeof(UInt16));
   int a=0;
 
   printf (" p_asn_msg : %p",p_asn_msg);
   if (NULL == p_asn_msg)
   {
	   //GNB_TRACE(GNB_ERROR, "Memory Allocation for p_asn_msg Failed !!");
	   printf("\n\n\nFailed !!\n\n");
	   return E2_FAILURE;
   }
   memset(p_asn_msg,0,sizeof(UInt8));


   //GNB_TRACE(GNB_INFO, "encode_E2node_Configuration_Update");
   printf( "\n\n\nencode_E2node_Configuration_Update\n\n");
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




      p_asn_E2node_Configuration_Update=
           rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2nodeConfigurationUpdate);
       if(NULL == p_asn_E2node_Configuration_Update)
       {
           response = E2_FAILURE;
           break;
       }

       
      asn1SetTC_e2ap_InitiatingMessage_e2nodeConfigurationUpdate(
                       &asn1_ctx,
                       e2ap_pdu.u.initiatingMessage,
                       p_asn_E2node_Configuration_Update);

      if (RT_OK != asn1Append_e2ap_E2nodeConfigurationUpdate_protocolIEs_1(&asn1_ctx,&p_asn_E2node_Configuration_Update->protocolIEs,E2CU_ONE))
      {
        	printf("\n\nFailed to Add IE1 !!\n\n"); 
	      response = E2_FAILURE;
               break;
      }
      printf("\n\n\n IE1 encoded\n\n\n");





      
      e2ap_GlobalE2node_ID *liste =NULL;
	   liste = rtxMemAllocTypeZ(&asn1_ctx,e2ap_GlobalE2node_ID);

	   if(NULL == liste)
	   {
		   // GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
		   printf("\n\n\nMemory allocation failed !!\n\n\n"); 
		   response = E2_FAILURE;
		   break;
	   }

      liste->t = T_e2ap_GlobalE2node_ID_gNB;
      liste->u.gNB = rtxMemAllocTypeZ(&asn1_ctx,e2ap_GlobalE2node_gNB_ID);
      asn1Init_e2ap_GlobalE2node_gNB_ID(liste->u.gNB);

      e2ap_GlobalE2node_gNB_ID *gnb = liste->u.gNB;

     
      liste->u.gNB->m.global_en_gNB_IDPresent = 0;
      liste->u.gNB->m.gNB_CU_UP_IDPresent = 0;
      liste->u.gNB->m.gNB_DU_IDPresent = 0;

      // PLMN
      liste->u.gNB->global_gNB_ID.plmn_id.numocts = 3;
      liste->u.gNB->global_gNB_ID.plmn_id.data[0] = 0x00;
      liste->u.gNB->global_gNB_ID.plmn_id.data[1] = 0xf1;
      liste->u.gNB->global_gNB_ID.plmn_id.data[2] = 0x10;

      // GNB_ID
      liste->u.gNB->global_gNB_ID.gnb_id.t = T_e2ap_GNB_ID_Choice_gnb_ID;
      liste->u.gNB->global_gNB_ID.gnb_id.u.gnb_ID =rtxMemAllocTypeZ(&asn1_ctx, ASN1BitStr32);
      liste->u.gNB->global_gNB_ID.gnb_id.u.gnb_ID->numbits = 32;
      liste->u.gNB->global_gNB_ID.gnb_id.u.gnb_ID->data[0] = 0x00;
      liste->u.gNB->global_gNB_ID.gnb_id.u.gnb_ID->data[1] = 0x00;
      liste->u.gNB->global_gNB_ID.gnb_id.u.gnb_ID->data[2] = 0x00;
      liste->u.gNB->global_gNB_ID.gnb_id.u.gnb_ID->data[3] = 0xd1;
               

      if (RT_OK != asn1Append_e2ap_E2nodeConfigurationUpdate_protocolIEs_2(&asn1_ctx,&p_asn_E2node_Configuration_Update->protocolIEs,liste))
      {
         printf("\n\nFailed to Add IE2 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      printf("\n\n\n IE2 encoded\n\n\n");

      e2ap_E2nodeComponentConfigAddition_List *list1 =NULL;
      list1 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2nodeComponentConfigAddition_List);

      if(NULL == list1)
      {
         //GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n"); 
         response = E2_FAILURE;
         break;
      }

      //rtxDListInit(list1);
      asn1Init_e2ap_E2nodeComponentConfigAddition_List(list1);

      OSRTDListNode                                     *node2 = NULL;
      e2ap_E2nodeComponentConfigAddition_List_element   *pvalue2 =NULL;

     // pvalue2 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2nodeComponentConfigAddition_List_element);
      rtxDListAllocNodeAndData(&asn1_ctx,
                          e2ap_E2nodeComponentConfigAddition_List_element, 
                              &node2,
                              &pvalue2);
      if(NULL == pvalue2)
      {
         //GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n"); 
         response = E2_FAILURE;
         break;
      }
      pvalue2->id =1;
      pvalue2->criticality = e2ap_reject;
      pvalue2->value.t = T30e2ap___e2ap_E2nodeComponentConfigAddition_ItemIEs_1;
      pvalue2->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2nodeComponentConfigAddition_Item);

      pvalue2->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1->e2nodeComponentInterfaceType=e2ap_f1;
      pvalue2->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1->e2nodeComponentID.t =T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeF1;

      pvalue2->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1->e2nodeComponentID.u.e2nodeComponentInterfaceTypeF1 =
      rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2nodeComponentInterfaceF1);

      pvalue2->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1->e2nodeComponentID.u.e2nodeComponentInterfaceTypeF1->gNB_DU_ID = 1;


      pvalue2->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1
        ->e2nodeComponentConfiguration.e2nodeComponentRequestPart.numocts = 60;
      pvalue2->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1
        ->e2nodeComponentConfiguration.e2nodeComponentRequestPart.data = p_event_msg;
				

         printf("\n\npu_setBuffer success.\n");

         //request part data (61 bytes)
         *p_event_msg="00150038000004001b00090000f11050000000d10052400b0400354720674e422d43550066001000000031320000f110000010080102030015400100";
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


         pvalue2->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1
          ->e2nodeComponentConfiguration.e2nodeComponentResponsePart.data = (OSOCTET *)p_event_msg1;

         pvalue2->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_1
          ->e2nodeComponentConfiguration.e2nodeComponentResponsePart.numocts = 57;

      rtxDListAppendNode(list1,node2);

      asn1Print_e2ap_E2nodeComponentConfigAddition_List_element("TEST2",pvalue2);

     // asn1Print_e2ap_E2nodeComponentConfigAddition_List("TEST1",list1);


      if (RT_OK != asn1Append_e2ap_E2nodeConfigurationUpdate_protocolIEs_3(&asn1_ctx,&p_asn_E2node_Configuration_Update->protocolIEs,list1))
      {
         printf("\n\nFailed to Add IE3 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      printf("\n\n\n IE3 encoded\n\n\n");


      e2ap_E2nodeComponentConfigUpdate_List *list2= NULL;
      list2 = rtxMemAllocType(&asn1_ctx, e2ap_E2nodeComponentConfigUpdate_List);
      if (NULL == list2)
      {
         //  GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n"); 
         response = E2_FAILURE;
         break;
      }
      rtxDListInit(list2);

      OSRTDListNode                                  *node3 = NULL;
      e2ap_E2nodeComponentConfigUpdate_List_element  *pvalue3= NULL;

      pvalue3 = rtxMemAllocType(&asn1_ctx, e2ap_E2nodeComponentConfigUpdate_List_element);
      if (NULL == pvalue3)
      {
         //  GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n"); 
         response = E2_FAILURE;
         break;
      }
      pvalue3->id = 4;
      pvalue3->criticality = e2ap_reject;
      pvalue3->value.t = T31e2ap___e2ap_E2nodeComponentConfigUpdate_ItemIEs_1;
      pvalue3->value.u._e2ap_E2nodeComponentConfigUpdate_ItemIEs_1 = rtxMemAllocType(&asn1_ctx, e2ap_E2nodeComponentConfigUpdate_Item);

      if (NULL == pvalue3->value.u._e2ap_E2nodeComponentConfigUpdate_ItemIEs_1)
      {
         //  GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n"); 
         response = E2_FAILURE;
         break;
      }
      pvalue3->value.u._e2ap_E2nodeComponentConfigUpdate_ItemIEs_1->e2nodeComponentInterfaceType=e2ap_f1;
      pvalue3->value.u._e2ap_E2nodeComponentConfigUpdate_ItemIEs_1->e2nodeComponentID.t=T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeF1;
      pvalue3->value.u._e2ap_E2nodeComponentConfigUpdate_ItemIEs_1->e2nodeComponentID.u.e2nodeComponentInterfaceTypeF1 =
      rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2nodeComponentInterfaceF1);

      pvalue3->value.u._e2ap_E2nodeComponentConfigUpdate_ItemIEs_1->e2nodeComponentID.u.e2nodeComponentInterfaceTypeF1->gNB_DU_ID = 1;


      pvalue3->value.u._e2ap_E2nodeComponentConfigUpdate_ItemIEs_1
        ->e2nodeComponentConfiguration.e2nodeComponentRequestPart.numocts = 60;
      pvalue3->value.u._e2ap_E2nodeComponentConfigUpdate_ItemIEs_1
        ->e2nodeComponentConfiguration.e2nodeComponentRequestPart.data = p_event_msg;
				

         printf("\n\npu_setBuffer success.\n");

         //request part data (61 bytes)
         *p_event_msg="00150038000004001b00090000f11050000000d10052400b0400354720674e422d43550066001000000031320000f110000010080102030015400100";
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
         int d;
         fprintf(stderr, "Request Part (60 bytes): ");
         for (d = 0; d < 60; d++) {
            fprintf(stderr, "%02x ", p_event_msg[d]);
         }
         b=0;
         fprintf(stderr, "\n");


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
         for (int e = 0; e < 57; e++) {
            fprintf(stderr, "%02x ", p_event_msg1[e]);
         }
         fprintf(stderr, "\n");

      


         pvalue3->value.u._e2ap_E2nodeComponentConfigUpdate_ItemIEs_1
          ->e2nodeComponentConfiguration.e2nodeComponentResponsePart.data = (OSOCTET *)p_event_msg1;

         pvalue3->value.u._e2ap_E2nodeComponentConfigUpdate_ItemIEs_1
          ->e2nodeComponentConfiguration.e2nodeComponentResponsePart.numocts = 57;

      rtxDListAppendNode(list2, node2);

     // asn1Print_e2ap_E2nodeComponentConfigAddition_List_element("TEST3",pvalue3);



      if (RT_OK != asn1Append_e2ap_E2nodeConfigurationUpdate_protocolIEs_4(&asn1_ctx,&p_asn_E2node_Configuration_Update->protocolIEs,list2))
      {
         printf("\n\nFailed to Add IE4 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      printf("\n\n\n IE4 encoded\n\n\n");

      e2ap_E2nodeComponentConfigRemoval_List *list3 = NULL;
      list3 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2nodeComponentConfigRemoval_List);
      if (NULL == list3)
      {
         printf("\n\nFailed to allocate memory for IE5 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      rtxDListInit(list3);

      OSRTDListNode                                   *node4 = NULL;
      e2ap_E2nodeComponentConfigRemoval_List_element  *pvalue4= NULL;

      //pvalue4 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2nodeComponentConfigRemoval_List_element);
     rtxDListAllocNodeAndData(&asn1_ctx,
                          e2ap_E2nodeComponentConfigRemoval_List_element, 
                              &node4,
                              &pvalue4);     
      if (NULL == pvalue4)
      {
         printf("\n\nFailed to allocate memory for IE5 !!\n\n");
         response = E2_FAILURE;
         break;
      }

      pvalue4->id = 5;
      pvalue4->criticality = e2ap_reject;
      pvalue4->value.t = T32e2ap___e2ap_E2nodeComponentConfigRemoval_ItemIEs_1;
      pvalue4->value.u._e2ap_E2nodeComponentConfigRemoval_ItemIEs_1 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2nodeComponentConfigRemoval_Item);

      if (NULL == pvalue4->value.u._e2ap_E2nodeComponentConfigRemoval_ItemIEs_1)
      {
         printf("\n\nFailed to allocate memory for IE5 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      pvalue4->value.u._e2ap_E2nodeComponentConfigRemoval_ItemIEs_1->e2nodeComponentInterfaceType=e2ap_f1;

      pvalue4->value.u._e2ap_E2nodeComponentConfigRemoval_ItemIEs_1->e2nodeComponentID.t= T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeF1;
      pvalue4->value.u._e2ap_E2nodeComponentConfigRemoval_ItemIEs_1->e2nodeComponentID.u.e2nodeComponentInterfaceTypeF1 =
      rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2nodeComponentInterfaceF1);

      pvalue4->value.u._e2ap_E2nodeComponentConfigRemoval_ItemIEs_1->e2nodeComponentID.u.e2nodeComponentInterfaceTypeF1->gNB_DU_ID = 1;

      rtxDListAppendNode(list3, node4);

      if (RT_OK != asn1Append_e2ap_E2nodeConfigurationUpdate_protocolIEs_5(&asn1_ctx,&p_asn_E2node_Configuration_Update->protocolIEs,list3))
      {
         printf("\n\nFailed to Add IE5 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      printf("\n\n\n IE5 encoded\n\n\n");

      e2ap_E2nodeTNLassociationRemoval_List *list4 = NULL;
      list4 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2nodeTNLassociationRemoval_List);
      if (NULL == list4)
      {
         printf("\n\nFailed to allocate memory for IE6 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      rtxDListInit(list4);

      OSRTDListNode                                   *node5 = NULL;
      e2ap_E2nodeTNLassociationRemoval_List_element  *pvalue5= NULL;

      //pvalue5 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2nodeTNLassociationRemoval_List_element);
     rtxDListAllocNodeAndData(&asn1_ctx,
                          e2ap_E2nodeTNLassociationRemoval_List_element, 
                              &node5,
                              &pvalue5);     
      if (NULL == pvalue5)
      {
         printf("\n\nFailed to allocate memory for IE6 !!\n\n");
         response = E2_FAILURE;
         break;
      }

      pvalue5->id = 6;
      pvalue5->criticality = e2ap_reject;
      pvalue5->value.t = T33e2ap___e2ap_E2nodeTNLassociationRemoval_ItemIEs_1;
      pvalue5->value.u._e2ap_E2nodeTNLassociationRemoval_ItemIEs_1 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2nodeTNLassociationRemoval_Item);

      if (NULL == pvalue5->value.u._e2ap_E2nodeTNLassociationRemoval_ItemIEs_1)
      {
         printf("\n\nFailed to allocate memory for IE6 !!\n\n");
         response = E2_FAILURE;
         break;
      }

      pvalue5->value.u._e2ap_E2nodeTNLassociationRemoval_ItemIEs_1->tnlInformation.m.tnlPortPresent =0;
     // pvalue5->value.u._e2ap_E2nodeTNLassociationRemoval_ItemIEs_1->tnlInformation.tnlAddress = 

      rtxDListAppendNode(list4, node5);


   if (RT_OK != asn1Append_e2ap_E2nodeConfigurationUpdate_protocolIEs_6(&asn1_ctx,&p_asn_E2node_Configuration_Update->protocolIEs,list4))
   {
      printf("\n\nFailed to Add IE6 !!\n\n");
      response = E2_FAILURE;
      break;
   }
   printf("\n\n\n IE6 encoded\n\n\n");
       
  // rtxDListAppendNode(&p_asn_E2node_Configuration_Update->protocolIEs,node1);
      //asn1Print_e2ap_E2nodeConfigurationUpdate("TEST1",p_value);

   } while (0);

   asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);
   return response;
}


// ********************** e2ap_E2connectionUpdate ********************* //

e2_return_et encode_e2ap_E2connection_Update
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len
)
{

   e2ap_E2AP_PDU                           e2ap_pdu;
   OSCTXT                                  asn1_ctx;
   e2ap_E2connectionUpdate                 *p_asn_e2ap_E2connectionUpdate = NULL;
   e2_return_et                            response = E2_SUCCESS;

   //struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
   UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg1=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt16  *p_event_msg_len=malloc(sizeof(UInt16));
   UInt16  *p_event_msg_len1=malloc(sizeof(UInt16));
   int a=0;
 
   printf (" p_asn_msg : %p",p_asn_msg);
   if (NULL == p_asn_msg)
   {
	   //GNB_TRACE(GNB_ERROR, "Memory Allocation for p_asn_msg Failed !!");
	   printf("\n\n\nFailed !!\n\n");
	   return E2_FAILURE;
   }
   memset(p_asn_msg,0,sizeof(UInt8));


   //GNB_TRACE(GNB_INFO, "encode_e2ap_E2connection_Update");
   printf( "\n\ne2ap_E2connectionUpdate\n\n\n");
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




      p_asn_e2ap_E2connectionUpdate=
           rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2connectionUpdate);
       if(NULL ==  p_asn_e2ap_E2connectionUpdate)
       {
           response = E2_FAILURE;
           break;
       }

       
      asn1SetTC_e2ap_InitiatingMessage_e2connectionUpdate(
                       &asn1_ctx,
                       e2ap_pdu.u.initiatingMessage,
                       p_asn_e2ap_E2connectionUpdate);

      if (RT_OK != asn1Append_e2ap_E2connectionUpdate_protocolIEs_1(&asn1_ctx,&p_asn_e2ap_E2connectionUpdate->protocolIEs,E2CU_ONE))
      {
        	printf("\n\nFailed to Add IE1 !!\n\n"); 
	      response = E2_FAILURE;
               break;
      }
      printf("\n\n\n IE1 encoded\n\n\n");

      e2ap_E2connectionUpdate_List  *list1 = NULL;
      list1 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2connectionUpdate_List);

      
      if(NULL == list1)
      {
         printf("\n\nFailed to allocate memory for IE2 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      rtxDListInit(list1);


      OSRTDListNode                         *node1 = NULL;
      e2ap_E2connectionUpdate_List_element  *pvalue1 = NULL;

     // pvalue1 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2connectionUpdate_List_element);
      rtxDListAllocNodeAndData(&asn1_ctx,
                  e2ap_E2connectionUpdate_List_element, 
                              &node1,
                              &pvalue1);   

      if(NULL == pvalue1)
      {
         printf("\n\nFailed to allocate memory for IE2 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      pvalue1->id =2;
      pvalue1->criticality =e2ap_ignore;
      pvalue1->value.t = T24e2ap___e2ap_E2connectionUpdate_ItemIEs_1;
      pvalue1->value.u._e2ap_E2connectionUpdate_ItemIEs_1 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2connectionUpdate_Item);
      if(NULL == pvalue1->value.u._e2ap_E2connectionUpdate_ItemIEs_1)
      {
         printf("\n\nFailed to allocate memory for IE2 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      pvalue1->value.u._e2ap_E2connectionUpdate_ItemIEs_1->tnlInformation.m.tnlPortPresent = 0;

      //pvalue1->value.u._e2ap_E2connectionUpdate_ItemIEs_1->tnlInformation.tnlAddress = ;
      //pvalue1->value.u._e2ap_E2connectionUpdate_ItemIEs_1->tnlInformation.tnlPort = ;

      pvalue1->value.u._e2ap_E2connectionUpdate_ItemIEs_1->tnlUsage =e2ap_ric_service;


     rtxDListAppendNode(list1,node1);
     asn1Print_e2ap_E2connectionUpdate_List("TEST1",list1);

      if (RT_OK != asn1Append_e2ap_E2connectionUpdate_protocolIEs_2(&asn1_ctx,&p_asn_e2ap_E2connectionUpdate->protocolIEs,list1))
      {
         printf("\n\nFailed to Add IE2 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      printf("\n\n\n IE2 encoded\n\n\n");


      e2ap_E2connectionUpdateRemove_List  *list2 = NULL;
      list2 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2connectionUpdateRemove_List);
      if(NULL == list2)
      {
         printf("\n\nFailed to allocate memory for IE3 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      rtxDListInit(list2);
           
      OSRTDListNode                                *node2 = NULL;
      e2ap_E2connectionUpdateRemove_List_element  *pvalue2 = NULL;

     // pvalue2 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2connectionUpdateRemove_List_element);
      rtxDListAllocNodeAndData(&asn1_ctx,
                  e2ap_E2connectionUpdateRemove_List_element, 
                              &node2,
                              &pvalue2);

      if(NULL == pvalue2)
      {
         printf("\n\nFailed to allocate memory for IE3 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      pvalue2->id =3;
      pvalue2->criticality =e2ap_ignore;
      pvalue2->value.t = T25e2ap___e2ap_E2connectionUpdateRemove_ItemIEs_1;
      pvalue2->value.u._e2ap_E2connectionUpdateRemove_ItemIEs_1 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_E2connectionUpdateRemove_Item);
      if(NULL == pvalue2->value.u._e2ap_E2connectionUpdateRemove_ItemIEs_1)
      {
         printf("\n\nFailed to allocate memory for IE3 !!\n\n");
         response = E2_FAILURE;
         break;
      }

      pvalue2->value.u._e2ap_E2connectionUpdateRemove_ItemIEs_1->tnlInformation.m.tnlPortPresent = 0;
      //pvalue2->value.u._e2ap_E2connectionUpdateRemove_ItemIEs_1->tnlInformation.tnlAddress = ;
      //pvalue2->value.u._e2ap_E2connectionUpdateRemove_ItemIEs_1->tnlInformation.tnlPort = ;
     // pvalue2->value.u._e2ap_E2connectionUpdateRemove_ItemIEs_1->tnlUsage =e2ap_ric_service;

      rtxDListAppendNode(list2,node2);
      asn1Print_e2ap_E2connectionUpdateRemove_List("TEST2",list2);

      if (RT_OK != asn1Append_e2ap_E2connectionUpdate_protocolIEs_3(&asn1_ctx,&p_asn_e2ap_E2connectionUpdate->protocolIEs,list2))
      {
         printf("\n\nFailed to Add IE3 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      printf("\n\n\n IE3 encoded\n\n\n");





   } while (0);
   asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);
   return response;
}



//***************************** e2ap_ErrorIndication **********************************

e2_return_et encode_e2ap_ErrorIndication
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len
)
{

   e2ap_E2AP_PDU                           e2ap_pdu;
   OSCTXT                                  asn1_ctx;
   e2ap_ErrorIndication                   *p_asn_e2ap_ErrorIndication = NULL;
   e2_return_et                            response = E2_SUCCESS;

   //struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
   UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg1=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt16  *p_event_msg_len=malloc(sizeof(UInt16));
   UInt16  *p_event_msg_len1=malloc(sizeof(UInt16));
   int a=0;
 
   printf (" p_asn_msg : %p",p_asn_msg);
   if (NULL == p_asn_msg)
   {
	   //GNB_TRACE(GNB_ERROR, "Memory Allocation for p_asn_msg Failed !!");
	   printf("\n\n\nFailed !!\n\n");
	   return E2_FAILURE;
   }
   memset(p_asn_msg,0,sizeof(UInt8));


   //GNB_TRACE(GNB_INFO, "e2ap_ErrorIndication");
   printf( "\n\ne2ap_ErrorIndication\n\n\n");
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




      p_asn_e2ap_ErrorIndication =
           rtxMemAllocTypeZ(&asn1_ctx,e2ap_ErrorIndication);
       if(NULL ==  p_asn_e2ap_ErrorIndication)
       {
           response = E2_FAILURE;
           break;
       }

       
      asn1SetTC_e2ap_InitiatingMessage_errorIndication(
                       &asn1_ctx,
                       e2ap_pdu.u.initiatingMessage,
                       p_asn_e2ap_ErrorIndication);

      if (RT_OK != asn1Append_e2ap_ErrorIndication_protocolIEs_1(&asn1_ctx,&p_asn_e2ap_ErrorIndication->protocolIEs,E2CU_ONE))
      {
        	printf("\n\nFailed to Add IE1 !!\n\n"); 
	      response = E2_FAILURE;
               break;
      }
      printf("\n\n\n IE1 encoded\n\n\n");

      e2ap_RICrequestID  *pvalue = NULL;
      pvalue = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICrequestID);
      if(NULL ==  pvalue)
      {
         response = E2_FAILURE;
         break;
      }

      pvalue->ricRequestorID = 1;
      pvalue->ricInstanceID = 55068;
      if (RT_OK != asn1Append_e2ap_ErrorIndication_protocolIEs_2(&asn1_ctx,&p_asn_e2ap_ErrorIndication->protocolIEs,pvalue))
      {
         printf("\n\nFailed to Add IE2 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      printf("\n\n\n IE2 encoded\n\n\n");

      e2ap_RANfunctionID *pvalue1 = NULL;

      pvalue1 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RANfunctionID);
      if(NULL ==  pvalue1)
      {
         response = E2_FAILURE;
         break;
      }

      pvalue1 =2;
      if (RT_OK != asn1Append_e2ap_ErrorIndication_protocolIEs_3(&asn1_ctx,&p_asn_e2ap_ErrorIndication->protocolIEs,pvalue1))
      {
         printf("\n\nFailed to Add IE3 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      printf("\n\n\n IE3 encoded\n\n\n");

      e2ap_Cause *pvalue2 = NULL;

      pvalue2 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_Cause);
      if(NULL ==  pvalue2)
      {
         response = E2_FAILURE;
         break;
      }

     // pvalue2->t=T_e2ap_Cause_misc;
      int loop =0;
      switch (loop)
      {
         case 0:
         pvalue2->t =T_e2ap_Cause_misc;
         pvalue2->u.misc = e2ap_control_processing_overload; 
         break;

         case 1:
         pvalue2->t =T_e2ap_Cause_misc;
         pvalue2->u.misc = e2ap_hardware_failure; 
         break;

         case 2:
         pvalue2->t =T_e2ap_Cause_misc;
         pvalue2->u.misc = e2ap_om_intervention; 
         break;

         case 3:
         pvalue2->t =T_e2ap_Cause_misc;
         pvalue2->u.misc = e2ap_unspecified; 
         default:
         break;      
      }


      if (RT_OK != asn1Append_e2ap_ErrorIndication_protocolIEs_4(&asn1_ctx,&p_asn_e2ap_ErrorIndication->protocolIEs,pvalue2))
      {
         printf("\n\nFailed to Add IE4 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      printf("\n\n\n IE4 encoded\n\n\n");





   } while (0);
   asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);
   return response;
}




//***************************** e2ap_RICserviceUpdate **********************************

e2_return_et encode_e2ap_RICserviceUpdate
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len
)
{

   e2ap_E2AP_PDU                           e2ap_pdu;
   OSCTXT                                  asn1_ctx;
   e2ap_RICserviceUpdate                   *p_asn_e2ap_RICserviceUpdate = NULL;
   e2_return_et                            response = E2_SUCCESS;

   //struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
   UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg1=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt16  *p_event_msg_len=malloc(sizeof(UInt16));
   UInt16  *p_event_msg_len1=malloc(sizeof(UInt16));
   int a=0;
 
   printf (" p_asn_msg : %p",p_asn_msg);
   if (NULL == p_asn_msg)
   {
	   //GNB_TRACE(GNB_ERROR, "Memory Allocation for p_asn_msg Failed !!");
	   printf("\n\n\nFailed !!\n\n");
	   return E2_FAILURE;
   }
   memset(p_asn_msg,0,sizeof(UInt8));


   //GNB_TRACE(GNB_INFO, "e2ap_RICserviceUpdate");
   printf( "\n\n e2ap_RICserviceUpdate\n\n\n");
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




      p_asn_e2ap_RICserviceUpdate =
           rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICserviceUpdate);
       if(NULL ==  p_asn_e2ap_RICserviceUpdate)
       {
           response = E2_FAILURE;
           break;
       }

       
      asn1SetTC_e2ap_InitiatingMessage_ricServiceUpdate(
                       &asn1_ctx,
                       e2ap_pdu.u.initiatingMessage,
                       p_asn_e2ap_RICserviceUpdate);

      if (RT_OK != asn1Append_e2ap_RICserviceUpdate_protocolIEs_1(&asn1_ctx,&p_asn_e2ap_RICserviceUpdate->protocolIEs,E2CU_ONE))
      {
        	printf("\n\nFailed to Add IE1 !!\n\n"); 
	      response = E2_FAILURE;
               break;
      }
      printf("\n\n\n IE1 encoded\n\n\n");

      e2ap_RANfunctions_List  *flist = NULL;
      flist =rtxMemAllocTypeZ(&asn1_ctx,e2ap_RANfunctions_List);
      if(NULL ==  flist)
      {
         printf("\n\n\nMemory allocation falied for list1\n\n\n");
         response = E2_FAILURE;
         break;
      }

      asn1Init_e2ap_RANfunctionsID_List(flist);

      OSRTDListNode                   *node = NULL;
      e2ap_RANfunctions_List_element  *pvalue= NULL;
      int a =0 ;
      for (a = 0 ; a < 1 ; a++ )
      {
         rtxDListAllocNodeAndData(&asn1_ctx,e2ap_RANfunctions_List_element,
                  &node,&pvalue);
         if(NULL ==  node)
         {
            printf("\n\n\nMemory allocation falied for node\n\n\n");
            response = E2_FAILURE;
            break;
         }
         pvalue->id =8;
         pvalue->criticality = 0;
         pvalue->value.t = T42e2ap___e2ap_RANfunction_ItemIEs_1;
         pvalue->value.u._e2ap_RANfunction_ItemIEs_1 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RANfunction_Item);
         if(NULL ==  pvalue->value.u._e2ap_RANfunction_ItemIEs_1)
         {
            printf("\n\n\nMemory allocation falied for pvalue\n\n\n");
            response = E2_FAILURE;
            break;
         }
         pvalue->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionID =2;

         rtxDListInit(&pvalue->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionDefinition);
         asn1Init_e2ap_RANfunctionDefinition(&pvalue->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionDefinition);

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

            asn1Init_E2SM_RC_RANFunctionDefinition_Report(&p_event_report->ric_ReportStyle_List);

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

          

            //abort();
           

         pvalue->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionDefinition.data = p_event_msg;
         pvalue->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionDefinition.numocts = *p_event_msg_len;
      rtxDListAppendNode(&pvalue->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionDefinition,def_node);
      }
      pvalue->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionRevision = 1;
      pvalue->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionOID = "1.3.6.1.4.1.53148.1.1.2.3";



      rtxDListAppendNode(flist,node);
      if (RT_OK != asn1Append_e2ap_RICserviceUpdate_protocolIEs_2(&asn1_ctx,&p_asn_e2ap_RICserviceUpdate->protocolIEs,flist))
      {
         printf("\n\nFailed to Add IE2 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      printf("\n\n\n IE2 encoded\n\n\n");




      e2ap_RANfunctions_List  *flist1 = NULL;
      flist1 =rtxMemAllocTypeZ(&asn1_ctx,e2ap_RANfunctions_List);
      if(NULL ==  flist1)
      {
         printf("\n\n\nMemory allocation falied for list1\n\n\n");
         response = E2_FAILURE;
         break;
      }

      asn1Init_e2ap_RANfunctionsID_List(flist1);

      OSRTDListNode                   *node1 = NULL;
      e2ap_RANfunctions_List_element  *pvalue1= NULL;
      int c =0 ;
      for (c = 0 ; c < 1 ; c++ )
      {
         rtxDListAllocNodeAndData(&asn1_ctx,e2ap_RANfunctions_List_element,
                  &node1,&pvalue1);
         if(NULL ==  node1)
         {
            printf("\n\n\nMemory allocation falied for node\n\n\n");
            response = E2_FAILURE;
            break;
         }
         pvalue1->id =8;
         pvalue1->criticality = 0;
         pvalue1->value.t = T42e2ap___e2ap_RANfunction_ItemIEs_1;
         pvalue1->value.u._e2ap_RANfunction_ItemIEs_1 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RANfunction_Item);
         if(NULL ==  pvalue1->value.u._e2ap_RANfunction_ItemIEs_1)
         {
            printf("\n\n\nMemory allocation falied for pvalue\n\n\n");
            response = E2_FAILURE;
            break;
         }
         pvalue1->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionID =2;

         rtxDListInit(&pvalue1->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionDefinition);
         asn1Init_e2ap_RANfunctionDefinition(&pvalue1->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionDefinition);

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

            asn1Init_E2SM_RC_RANFunctionDefinition_Report(&p_event_report->ric_ReportStyle_List);

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

          

            //abort();
           

         pvalue1->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionDefinition.data = p_event_msg;
         pvalue1->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionDefinition.numocts = *p_event_msg_len;
      rtxDListAppendNode(&pvalue1->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionDefinition,def_node);
      }
      pvalue1->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionRevision = 1;
      pvalue1->value.u._e2ap_RANfunction_ItemIEs_1->ranFunctionOID = "1.3.6.1.4.1.53148.1.1.2.3";



      rtxDListAppendNode(flist1,node1);
      if (RT_OK != asn1Append_e2ap_RICserviceUpdate_protocolIEs_3(&asn1_ctx,&p_asn_e2ap_RICserviceUpdate->protocolIEs,flist1))
      {
         printf("\n\nFailed to Add IE3 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      printf("\n\n\n IE3 encoded\n\n\n");







      e2ap_RANfunctionsID_List  *flist2 = NULL;
      flist2 =rtxMemAllocTypeZ(&asn1_ctx,e2ap_RANfunctionsID_List);
      if(NULL ==  flist2)
      {
         printf("\n\n\nMemory allocation falied for list2\n\n\n");
         response = E2_FAILURE;
         break;
      }

      asn1Init_e2ap_RANfunctionsID_List(flist2);

      OSRTDListNode                     *node3 = NULL;
      e2ap_RANfunctionsID_List_element  *pvalue3= NULL;
      int b =0 ;
      for (b = 0 ; b < 1 ; b++ )
      {
         rtxDListAllocNodeAndData(&asn1_ctx,e2ap_RANfunctionsID_List_element,
                  &node3,&pvalue3);
         if(NULL ==  node3)
         {
            printf("\n\n\nMemory allocation falied for node2\n\n\n");
            response = E2_FAILURE;
            break;
         }
         pvalue3->id =8;
         pvalue3->criticality = 0;
         pvalue3->value.t = T43e2ap___e2ap_RANfunctionID_ItemIEs_1;
         pvalue3->value.u._e2ap_RANfunctionID_ItemIEs_1 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RANfunction_Item);
         if(NULL ==  pvalue3->value.u._e2ap_RANfunctionID_ItemIEs_1)
         {
            printf("\n\n\nMemory allocation falied for pvalue3\n\n\n");
            response = E2_FAILURE;
            break;
         }
         pvalue3->value.u._e2ap_RANfunctionID_ItemIEs_1->ranFunctionID =2;
         pvalue3->value.u._e2ap_RANfunctionID_ItemIEs_1->ranFunctionRevision = 1;
      }
      rtxDListAppendNode(flist2,node3);
      if (RT_OK != asn1Append_e2ap_RICserviceUpdate_protocolIEs_4(&asn1_ctx,&p_asn_e2ap_RICserviceUpdate->protocolIEs,flist2))
      {
         printf("\n\nFailed to Add IE4 !!\n\n");
         response = E2_FAILURE;
         break;
      }
      printf("\n\n\n IE4 encoded\n\n\n");


   } while (0);
   asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);
   return response;
}


//  *****************  e2smrc setup indication ********************** //
e2_return_et encode_ric_indication1
(
    UInt8   **pp_asn_msg,
    UInt16  *p_asn_msg_len
)
{
    e2ap_E2AP_PDU                      e2ap_pdu;
    OSCTXT                             asn1_ctx;
    e2ap_RICindication                *p_asn_e2ap_RICindication = NULL;
    e2_return_et                      response = E2_SUCCESS;

    struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
    UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
    UInt8   *p_event_msg=malloc(E2CU_ASN1_BUFFER_LENGTH);
    UInt8   *p_event_msg1=malloc(E2CU_ASN1_BUFFER_LENGTH);
    UInt8   *p_event_msg2=malloc(E2CU_ASN1_BUFFER_LENGTH);
    UInt16  *p_event_msg_len=malloc(sizeof(UInt16));
    UInt16  *p_event_msg_len1=malloc(sizeof(UInt16));
    UInt16  *p_event_msg_len2=malloc(sizeof(UInt16));
    UInt16  *p_event_len1=malloc(sizeof(UInt16));

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

      e2ap_RICindicationHeader   *p_value_ie7 =NULL;
      p_value_ie7 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICindicationHeader);

      if(NULL == p_value_ie7)
      {
         // GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      asn1Init_e2ap_RICindicationHeader(p_value_ie7);

      OSRTDListNode                       *Node1 = NULL;
      E2SM_RC_IndicationHeader            *p_value_ie7_1 =NULL;
      int b,list=0;

      rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_IndicationHeader,
          &Node1, &p_value_ie7_1);

      if(NULL == p_value_ie7_1)
      {
         // GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      asn1Init_E2SM_RC_IndicationHeader(p_value_ie7_1);

      p_value_ie7_1->ric_indicationHeader_formats.t=T_E2SM_RC_IndicationHeader_ric_indicationHeader_formats_indicationHeader_Format2;
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2 = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_IndicationHeader_Format2);

      if(NULL == p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2)
      {
         // GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.t = T_UEID_gNB_UEID;
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID = rtxMemAllocTypeZ(&asn1_ctx, UEID_GNB);

      if(NULL == p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID)
      {
         // GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      asn1Init_UEID_GNB(p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID);

      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->m.gNB_CU_UE_F1AP_ID_ListPresent = 1;
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->m.gNB_CU_CP_UE_E1AP_ID_ListPresent = 0; 
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->m.ran_UEIDPresent = 0;
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->m.m_NG_RAN_UE_XnAP_IDPresent = 0;
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->m.globalGNB_IDPresent = 0;

      //amf_UE_NGAP_ID
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->amf_UE_NGAP_ID = 1;

      //pLMNIdentity
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->guami.pLMNIdentity.data[0]=0x11;
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->guami.pLMNIdentity.data[1]=0x22;
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->guami.pLMNIdentity.data[2]=0x33;
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->guami.pLMNIdentity.numocts = 3;

      //AMFRegionID
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->guami.aMFRegionID.numbits = 8;
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->guami.aMFRegionID.data[0] = 0x2;

      //aMFSetID
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->guami.aMFSetID.numbits = 10;
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->guami.aMFSetID.data[0] = 0xF1;

      //aMFPointer
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->guami.aMFPointer.numbits = 6;
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->guami.aMFPointer.data[0] = 0x01;
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->guami.aMFPointer.data[1] = 0x23;
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->guami.aMFPointer.data[2] = 0x34;

      //UEID_GNB_CU_F1AP_ID_List
      asn1Init_UEID_GNB_CU_F1AP_ID_List(
      &p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->gNB_CU_UE_F1AP_ID_List);

      // Allocate and populate the UEID_GNB_CU_CP_F1AP_ID_Item
      OSRTDListNode                       *listnode = NULL;
      UEID_GNB_CU_CP_F1AP_ID_Item          *pvalue = NULL;

      rtxDListAllocNodeAndData(&asn1_ctx, UEID_GNB_CU_CP_F1AP_ID_Item,&listnode, &pvalue);
      if(NULL == pvalue)
      {
         // GNB_TRACE(GNB_INFO, "Memory allocation failed !!");   
         printf("\n\n\nMemory allocation failed !!\n\n\n");
         response = E2_FAILURE;
         break;
      }

      pvalue->gNB_CU_UE_F1AP_ID = 1;

      //append the UEID_GNB_CU_CP_F1AP_ID_Item to the list
      rtxDListAppendNode(&p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ueID.u.gNB_UEID->gNB_CU_UE_F1AP_ID_List, listnode); 
      
      asn1Print_E2SM_RC_IndicationHeader("E2SM_RC_IndicationHeader", p_value_ie7_1);


      // Encode RICindicationHeader_Format2
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ric_InsertStyle_Type = 32;
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format2->ric_InsertIndication_ID = 1;


      // Encode E2SM_RC_RANFunctionDefinition_Insert
      memset(p_event_msg2,0,E2CU_ASN1_BUFFER_LENGTH);
      if( RT_OK != pu_setBuffer(&asn1_ctx, p_event_msg2,E2CU_ASN1_BUFFER_LENGTH, TRUE))
      {
         printf("\n\npu_setBuffer failed.\n");
         response = E2_FAILURE;
         break;
      }
      else             
      printf("\npu_setBuffer success.\n\n");
      b=asn1PE_E2SM_RC_IndicationHeader(&asn1_ctx, p_value_ie7_1);
      printf("\n\n===asn1PE_E2SM_RC_IndicationHeader===a=%d===========\n",b);
      *p_event_msg_len2 = (UInt16)pe_GetMsgLen(&asn1_ctx);
      printf("p_event_msg_len2 :%d\n\n",*p_event_msg_len2);
      //	printf("p_event_msg : %x\n\n",*p_event_msg);
      for(b=0; b< ((*p_event_msg_len2)); b ++)
      {
         fprintf(stderr, "%02x ", p_event_msg2[b]);
      }
      b=0;
      fprintf(stderr, "\n");

      
      p_value_ie7->data = p_event_msg2; 
      p_value_ie7->numocts = *p_event_msg_len2;


      //GNB_TRACE(GNB_INFO, " IE5 encoded");
      printf("\n\n\n IE5 encoded\n\n\n");


      if (RT_OK != asn1Append_e2ap_RICindication_protocolIEs_6(&asn1_ctx,&p_asn_e2ap_RICindication->protocolIEs,p_value_ie7))
      {
         //   GNB_TRACE(GNB_ERROR, "Failed to Add IE6 !!");
         response = E2_FAILURE;
         break;
      }


      e2ap_RICindicationMessage *p_value_ie5 = NULL;
	   p_value_ie5 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICindicationMessage);

      if(NULL == p_value_ie5)
      {
         // GNB_TRACE(GNB_INFO, "Memory allocation failed !!");   
         printf("\n\n\nMemory allocation failed !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      //rtxDListInit(p_value_ie5);
      asn1Init_e2ap_RICindicationMessage(p_value_ie5);
      int a=0;
      

      // Allocate and populate the E2SM-RC-IndicationMessage
      OSRTDListNode                       *def_node1 = NULL;
      E2SM_RC_IndicationMessage           *p_event = NULL;
      rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_IndicationMessage,
         &def_node1, &p_event);

      if (def_node1 == NULL)
      {
         //GNB_TRACE(GNB_ERROR, "Failed to allocate E2SM-RC-IndicationMessage !!");
         printf("\n\n\nFailed to allocate E2SM-RC-IndicationMessage !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      asn1Init_E2SM_RC_IndicationMessage(p_event);
      p_event->ric_indicationMessage_formats.t=T_E2SM_RC_IndicationMessage_ric_indicationMessage_formats_indicationMessage_Format5; 
      p_event->ric_indicationMessage_formats.u.indicationMessage_Format5 = rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_IndicationMessage_Format5);
      if(NULL == p_event->ric_indicationMessage_formats.u.indicationMessage_Format5)
      {
         //GNB_TRACE(GNB_ERROR, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      asn1Init_E2SM_RC_IndicationMessage_Format5_ranP_Requested_List
         (&p_event->ric_indicationMessage_formats.u.indicationMessage_Format5->ranP_Requested_List);

      OSRTDListNode                            *def_node2 = NULL;  
      E2SM_RC_IndicationMessage_Format5_Item   *p_format5 = NULL;

      rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_IndicationMessage_Format5_Item,
         &def_node2, &p_format5);

      p_format5->ranParameter_ID = 1;
      p_format5->ranParameter_valueType.t = T_E2SM_RC_RANParameter_ValueType_ranP_Choice_ElementFalse;
      p_format5->ranParameter_valueType.u.ranP_Choice_ElementFalse = 
          rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_RANParameter_ValueType_Choice_ElementFalse);

      if(NULL == p_format5->ranParameter_valueType.u.ranP_Choice_ElementFalse)
      {
         //GNB_TRACE(GNB_ERROR, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      p_format5->ranParameter_valueType.u.ranP_Choice_ElementFalse->m.ranParameter_valuePresent = 1;
      p_format5->ranParameter_valueType.u.ranP_Choice_ElementFalse->ranParameter_value.t = T_E2SM_RC_RANParameter_Value_valueOctS;

      p_event_msg1[0] = 32;
      p_event_msg1[1] = 41;
      p_event_msg1[2] = 0;
      p_event_msg1[3] = 15;
      p_event_msg1[4] = 0;
      p_event_msg1[5] = 0;
      p_event_msg1[6] = 2;
      p_event_msg1[7] = 0;
      p_event_msg1[8] = 10;
      p_event_msg1[9] = 64;
      p_event_msg1[10] = 2;
      p_event_msg1[11] = 0;
      p_event_msg1[12] = 18;
      p_event_msg1[13] = 0;
      p_event_msg1[14] = 85;
      p_event_msg1[15] = 64;
      p_event_msg1[16] = 2;
      p_event_msg1[17] = 0;
      p_event_msg1[18] = 3;



      // Debug print ranparameter value part
      fprintf(stderr, "RAN Parameter Value Part (19 bytes): ");
      for (int e = 0; e < 19; e++) {
         fprintf(stderr, "%02x ", p_event_msg1[e]);
      }
      fprintf(stderr, "\n");

      p_format5->ranParameter_valueType.u.ranP_Choice_ElementFalse->ranParameter_value.u.valueOctS = rtxMemAllocTypeZ(&asn1_ctx, OSDynOctStr);
      p_format5->ranParameter_valueType.u.ranP_Choice_ElementFalse->ranParameter_value.u.valueOctS->data = p_event_msg1;
      p_format5->ranParameter_valueType.u.ranP_Choice_ElementFalse->ranParameter_value.u.valueOctS->numocts = 19;

      
      rtxDListAppendNode(&p_event->ric_indicationMessage_formats.u.indicationMessage_Format5->ranP_Requested_List,def_node2); 
     // asn1Print_E2SM_RC_IndicationMessage_Format5_ranP_Requested_List("ranP_Requested_List",
       //  &p_event->ric_indicationMessage_formats.u.indicationMessage_Format5->ranP_Requested_List);
       
      asn1Print_E2SM_RC_IndicationMessage("E2SM_RC_IndicationMessage", p_event);

     // Encode E2SM_RC_RANFunctionDefinition_Insert
      memset(p_event_msg1,0,E2CU_ASN1_BUFFER_LENGTH);
      if( RT_OK != pu_setBuffer(&asn1_ctx, p_event_msg1,E2CU_ASN1_BUFFER_LENGTH, TRUE))
      {
         printf("\n\npu_setBuffer failed.\n");
         response = E2_FAILURE;
         break;
      }
      else             
      printf("\npu_setBuffer success.\n\n");
      a=asn1PE_E2SM_RC_IndicationMessage(&asn1_ctx,p_event);
      printf("\n\n===asn1PE_E2SM_RC_IndicationMessage===a=%d===========\n",a);
      *p_event_msg_len1 = (UInt16)pe_GetMsgLen(&asn1_ctx);
      printf("p_event_msg_len :%d\n\n",*p_event_msg_len1);
      //	printf("p_event_msg : %x\n\n",*p_event_msg);
      for(a=0; a< ((*p_event_msg_len1)); a ++)
      {
         fprintf(stderr, "%02x ", p_event_msg1[a]);
      }
      a=0;
      fprintf(stderr, "\n");



      p_value_ie5->data=p_event_msg1;
      p_value_ie5->numocts=*p_event_msg_len1;

      p_event->ric_indicationMessage_formats.t=T_E2SM_RC_IndicationMessage_ric_indicationMessage_formats_indicationMessage_Format2;
       
      p_event->ric_indicationMessage_formats.u.indicationMessage_Format2 = rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_IndicationMessage_Format2);
      if(NULL == p_event->ric_indicationMessage_formats.u.indicationMessage_Format5)
      {
         //GNB_TRACE(GNB_ERROR, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      asn1Init_E2SM_RC_IndicationMessage_Format2_ueParameter_List
         (&p_event->ric_indicationMessage_formats.u.indicationMessage_Format2->ueParameter_List);

      OSRTDListNode                            *def_Node = NULL;  
      E2SM_RC_IndicationMessage_Format2_Item   *pformat1 = NULL;

      rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_IndicationMessage_Format2_Item,
         &def_Node, &pformat1);

    // pformat1->ueID.t=T_UEID_gNB_UEID;
    // pformat1->ueID.u.gNB_UEID=1;


     asn1Init_E2SM_RC_IndicationMessage_Format2_Item_ranP_List(
         &pformat1->ranP_List);

      OSRTDListNode                                         *def_Node1 = NULL;  
      E2SM_RC_IndicationMessage_Format2_RANParameter_Item   *pformat2 = NULL;

      rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_IndicationMessage_Format2_RANParameter_Item,
         &def_Node1, &pformat2);
      pformat2->ranParameter_ID = 1;
     // pformat2->ranParameter_valueType = 1;

     rtxDListAppendNode(&pformat1->ranP_List,def_Node1);

      rtxDListAppendNode(&p_event->ric_indicationMessage_formats.u.indicationMessage_Format2->ueParameter_List,def_Node);


     // asn1Print_E2SM_RC_IndicationMessage("E2SM_RC_IndicationMessage", p_event);

      int d=0;
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
      d=asn1PE_E2SM_RC_IndicationMessage(&asn1_ctx,p_event);
      printf("\n\n===asn1PE_E2SM_RC_IndicationMessage===a=%d===========\n",d);
      *p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
      printf("p_event_msg_len :%d\n\n",*p_event_msg_len);
      //	printf("p_event_msg : %x\n\n",*p_event_msg);
      for(d=0; d< ((*p_event_msg_len)); d ++)
      {
         fprintf(stderr, "%02x ", p_event_msg[d]);
      }
      d=0;
      fprintf(stderr, "\n");

    //  p_value_ie5->data=p_event_msg1;
     // p_value_ie5->numocts=*p_event_msg_len;

      //GNB_TRACE(GNB_INFO, " IE6 encoded");
      printf("\n\n\n IE6 encoded\n\n\n");
      //p_value_ie5->data=(OSOCTET *)p_event_msg1;
      //p_value_ie5->numocts=*p_event_msg_len;

      //rtxDListAppendNode(p_value_ie5,def_node1);
        
      
      //abort();


      if (RT_OK != asn1Append_e2ap_RICindication_protocolIEs_7(&asn1_ctx,&p_asn_e2ap_RICindication->protocolIEs,p_value_ie5))
      {
         //   GNB_TRACE(GNB_ERROR, "Failed to Add IE5 !!");
         printf("\n\n\nFailed to Add IE5 !!\n\n\n");
         response = E2_FAILURE;
         break;
      }

      e2ap_RICcallProcessID  *p_value_ie6 = NULL;
      p_value_ie6 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICcallProcessID);
      if(NULL == p_value_ie6)
      {
         //GNB_TRACE(GNB_ERROR, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      int c=0;

      //rtxDListInit(p_value_ie6);
      asn1Init_e2ap_RICcallProcessID(p_value_ie6);

      OSRTDListNode                *def_node3 = NULL;
      E2SM_RC_CallProcessID         *p_event1 = NULL;
      rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_CallProcessID,
         &def_node3, &p_event1);

      p_event1->ric_callProcessID_formats.t = T_E2SM_RC_CallProcessID_ric_callProcessID_formats_callProcessID_Format1;
      p_event1->ric_callProcessID_formats.u.callProcessID_Format1 = rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_CallProcessID_Format1);

      p_event1->ric_callProcessID_formats.u.callProcessID_Format1->ric_callProcess_ID = 1;

     // p_event1->ric_callProcessID_formats.t = T_E2SM_RC_CallProcessID_ric_callProcessID_formats_callProcessID_Format1;
     // p_event1->ric_callProcessID_formats.u.callProcessID_Format1->ric_callProcess_ID = 1;

      asn1Print_E2SM_RC_CallProcessID("E2SM_RC_CallProcessID", p_event1);

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
      c=asn1PE_E2SM_RC_CallProcessID(&asn1_ctx,p_event);
      printf("\n\n===asn1PE_E2SM_RC_CallProcessID===a=%d===========\n",c);
      *p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
      printf("p_event_msg_len :%d\n\n",*p_event_msg_len);
      //	printf("p_event_msg : %x\n\n",*p_event_msg);
      for(c=0; c< ((*p_event_msg_len)); c ++)
      {
         fprintf(stderr, "%02x ", p_event_msg[c]);
      }
      c=0;
      fprintf(stderr, "\n");



      p_value_ie6->data=p_event_msg;
      p_value_ie6->numocts=*p_event_msg_len;








     //rtxDListAppendNode(p_value_ie6,def_node3);

      if (RT_OK != asn1Append_e2ap_RICindication_protocolIEs_8(&asn1_ctx,&p_asn_e2ap_RICindication->protocolIEs,p_value_ie6))
      {
         //GNB_TRACE(GNB_ERROR, "Failed to Add IE6 !!");
         printf("\n\n\nFailed to Add IE6 !!\n\n\n");
         response = E2_FAILURE;
         break;
      }


   } while (0);
   asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);
   return response;
}



//  *****************  e2smrc ric control ********************** //
e2_return_et encode_ric_control_request1
(
    UInt8   **pp_asn_msg,
    UInt16  *p_asn_msg_len
)
{
    e2ap_E2AP_PDU                      e2ap_pdu;
    OSCTXT                             asn1_ctx;
    e2ap_RICcontrolRequest            *p_asn_e2ap_RICcontrolRequest = NULL;
    e2_return_et                      response = E2_SUCCESS;

    //struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
    UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
    UInt8   *p_event_msg=malloc(E2CU_ASN1_BUFFER_LENGTH);
    UInt8   *p_event_msg1=malloc(E2CU_ASN1_BUFFER_LENGTH);
    UInt8   *p_event_msg2=malloc(E2CU_ASN1_BUFFER_LENGTH);
    UInt16  *p_event_msg_len=malloc(sizeof(UInt16));
    UInt16  *p_event_msg_len1=malloc(sizeof(UInt16));
    UInt16  *p_event_msg_len2=malloc(sizeof(UInt16));
    UInt16  *p_event_len1=malloc(sizeof(UInt16));
    int c=0;

    

    printf (" p_asn_msg : %p",p_asn_msg);
   if (NULL == p_asn_msg)
   {
	   //GNB_TRACE(GNB_ERROR, "Memory Allocation for p_asn_msg Failed !!");
	   printf("\n\n\nFailed !!\n\n");
	   return E2_FAILURE;
   }
   memset(p_asn_msg,0,sizeof(UInt8));


   //GNB_TRACE(GNB_INFO, "encode_control_request");
   printf( "\n\n\nencode_control_request\n\n");
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
	   p_asn_e2ap_RICcontrolRequest =
		   rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICcontrolRequest);

	   if(NULL ==p_asn_e2ap_RICcontrolRequest )
	   {
		   response = E2_FAILURE;
		   break;
	   }
	   asn1SetTC_e2ap_InitiatingMessage_ricControl(
			   &asn1_ctx,
			   e2ap_pdu.u.initiatingMessage,
			   p_asn_e2ap_RICcontrolRequest);

      struct e2ap_RICrequestID *pvalue = rtxMemAllocTypeZ(&asn1_ctx, struct e2ap_RICrequestID);
      pvalue->ricRequestorID=1;
      pvalue->ricInstanceID=55068;


	   if (RT_OK != asn1Append_e2ap_RICcontrolRequest_protocolIEs_1(&asn1_ctx,&p_asn_e2ap_RICcontrolRequest->protocolIEs,pvalue))
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
	   

	   if (RT_OK != asn1Append_e2ap_RICcontrolRequest_protocolIEs_2(&asn1_ctx,&p_asn_e2ap_RICcontrolRequest->protocolIEs,*p_value_ie2))
	   {
		   //   GNB_TRACE(GNB_ERROR, "Failed to Add IE2 !!");
		   response = E2_FAILURE;
		   break;
	   }
	   //GNB_TRACE(GNB_INFO, " IE2 encoded");
      printf("\n\n\n IE2 encoded\n\n\n");


      e2ap_RICcallProcessID       *p_value_ie3 =NULL;
      p_value_ie3 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICcallProcessID); 

      if(NULL == p_value_ie3)
      {
         //GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n"); 
         response = E2_FAILURE;
         break;
      }
      asn1Init_e2ap_RICcallProcessID(p_value_ie3);

      OSRTDListNode                *Node1 = NULL;
      E2SM_RC_CallProcessID        *callProcessID = NULL;
      rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_CallProcessID,
         &Node1, &callProcessID);

      callProcessID->ric_callProcessID_formats.t = T_E2SM_RC_CallProcessID_ric_callProcessID_formats_callProcessID_Format1;
      callProcessID->ric_callProcessID_formats.u.callProcessID_Format1 = rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_CallProcessID_Format1);

      callProcessID->ric_callProcessID_formats.u.callProcessID_Format1->ric_callProcess_ID = 1;

      asn1Print_E2SM_RC_CallProcessID("E2SM_RC_CallProcessID", callProcessID);

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
      c=asn1PE_E2SM_RC_CallProcessID(&asn1_ctx, callProcessID);
      printf("\n\n===asn1PE_E2SM_RC_CallProcessID===a=%d===========\n",c);
      *p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
      printf("p_event_msg_len :%d\n\n",*p_event_msg_len);
      //	printf("p_event_msg : %x\n\n",*p_event_msg);
      for(c=0; c< ((*p_event_msg_len)); c ++)
      {
         fprintf(stderr, "%02x ", p_event_msg[c]);
      }
      c=0;
      fprintf(stderr, "\n");

      p_value_ie3->data=p_event_msg;
      p_value_ie3->numocts=*p_event_msg_len;


      if (RT_OK != asn1Append_e2ap_RICcontrolRequest_protocolIEs_3(&asn1_ctx,&p_asn_e2ap_RICcontrolRequest->protocolIEs,p_value_ie3))
      {
         //GNB_TRACE(GNB_ERROR, "Failed to Add IE3 !!");
         response = E2_FAILURE;
         break;
      }
      //GNB_TRACE(GNB_INFO, " IE3 encoded");
      printf("\n\n\n IE3 encoded\n\n\n");

      e2ap_RICcontrolHeader       *p_value_ie4 =NULL;
      p_value_ie4 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICcontrolHeader);

      if(NULL == p_value_ie4)
      {
         //GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n"); 
         response = E2_FAILURE;
         break;
      }
      asn1Init_e2ap_RICcontrolHeader(p_value_ie4);
      
      OSRTDListNode            *Node2 = NULL;
      E2SM_RC_ControlHeader    *controlHeader = NULL;
      rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_ControlHeader,
         &Node2, &controlHeader);
      
      controlHeader->ric_controlHeader_formats.t = T_E2SM_RC_ControlHeader_ric_controlHeader_formats_controlHeader_Format1;
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1 = rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_ControlHeader_Format1);
      if(NULL == controlHeader->ric_controlHeader_formats.u.controlHeader_Format1)
      {
         //GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n"); 
         response = E2_FAILURE;
         break;
      }

      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->m.ric_ControlDecisionPresent =0;

      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.t = T_UEID_gNB_UEID;
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID = rtxMemAllocTypeZ(&asn1_ctx,UEID_GNB);
      if(NULL == controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID)
      {
         //GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n"); 
         response = E2_FAILURE;
         break;
      }
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->m.gNB_CU_UE_F1AP_ID_ListPresent = 1;
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->m.gNB_CU_CP_UE_E1AP_ID_ListPresent = 0;
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->m.ran_UEIDPresent = 0;
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->m.m_NG_RAN_UE_XnAP_IDPresent = 0;
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->m.globalGNB_IDPresent = 0;

      //amf_UE_NGAP_ID
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->amf_UE_NGAP_ID = 1;
      //PLMNIdentity
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami.pLMNIdentity.numocts =3;
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami.pLMNIdentity.data[0] =0x11;
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami.pLMNIdentity.data[1] =0x22;
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami.pLMNIdentity.data[2] =0x33;
      //aMFSetID
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami.aMFSetID.numbits =10;
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami.aMFSetID.data[0] =0xF1;
      //aMFRegionID
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami.aMFRegionID.numbits =8;
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami.aMFRegionID.data[0] =0x02;
      //aMFPointer
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami.aMFPointer.numbits =6;
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami.aMFPointer.data[0] =0x01;
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami.aMFPointer.data[1] =0x23;
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->guami.aMFPointer.data[1] =0x34;

      //UEID_GNB_CU_F1AP_ID_List
      asn1Init_UEID_GNB_CU_F1AP_ID_List(&controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->gNB_CU_UE_F1AP_ID_List);
      
       // Allocate and populate the UEID_GNB_CU_CP_F1AP_ID_Item
      OSRTDListNode                       *listnode1 = NULL;
      UEID_GNB_CU_CP_F1AP_ID_Item          *pvalue1 = NULL;

      rtxDListAllocNodeAndData(&asn1_ctx, UEID_GNB_CU_CP_F1AP_ID_Item,&listnode1, &pvalue1);
      if(NULL == pvalue1)
      {
         // GNB_TRACE(GNB_INFO, "Memory allocation failed !!");   
         printf("\n\n\nMemory allocation failed !!\n\n\n");
         response = E2_FAILURE;
         break;
      }

      pvalue1->gNB_CU_UE_F1AP_ID = 1;

      //append the UEID_GNB_CU_CP_F1AP_ID_Item to the list
      rtxDListAppendNode(&controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ueID.u.gNB_UEID->gNB_CU_UE_F1AP_ID_List, listnode1);
      
      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ric_Style_Type = 1;

      controlHeader->ric_controlHeader_formats.u.controlHeader_Format1->ric_ControlAction_ID = 1;


      asn1Print_E2SM_RC_ControlHeader("E2SM_RC_ControlHeader", controlHeader);

      if (RT_OK != asn1Append_e2ap_RICcontrolRequest_protocolIEs_4(&asn1_ctx,&p_asn_e2ap_RICcontrolRequest->protocolIEs,p_value_ie4))
      {
         //GNB_TRACE(GNB_ERROR, "Failed to Add IE4 !!");
         response = E2_FAILURE;
         break;
      }
      //GNB_TRACE(GNB_INFO, " IE4 encoded");
      printf("\n\n\n IE4 encoded\n\n\n");


      e2ap_RICcontrolMessage       *p_value_ie5 =NULL;
      p_value_ie5 = rtxMemAllocTypeZ(&asn1_ctx, e2ap_RICcontrolMessage);

      if(NULL == p_value_ie5)
      {
         //GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n"); 
         response = E2_FAILURE;
         break;
      }
      asn1Init_e2ap_RICcontrolMessage(p_value_ie5);

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
    

      
      
      if (RT_OK != asn1Append_e2ap_RICcontrolRequest_protocolIEs_5(&asn1_ctx,&p_asn_e2ap_RICcontrolRequest->protocolIEs,p_value_ie5))
      {
         //GNB_TRACE(GNB_ERROR, "Failed to Add IE5 !!");
         printf("\n\n\nFailed to Initialize IE5 !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      //GNB_TRACE(GNB_INFO, " IE5 encoded");
      printf("\n\n\n IE5 encoded\n\n\n");

   }while(0);
   asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);
   return response;
}




// *****************  e2smrc RIC CONTROL ACKNOWLEDGE ********************** //

e2_return_et encode_ric_control_acknowledge1
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

      asn1Init_e2ap_RICcallProcessID(p_value_ie3);

      OSRTDListNode                *Node1 = NULL;
      E2SM_RC_CallProcessID        *callProcessID = NULL;
      int c=0;
      rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_CallProcessID,
         &Node1, &callProcessID);

      callProcessID->ric_callProcessID_formats.t = T_E2SM_RC_CallProcessID_ric_callProcessID_formats_callProcessID_Format1;
      callProcessID->ric_callProcessID_formats.u.callProcessID_Format1 = rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_CallProcessID_Format1);

      callProcessID->ric_callProcessID_formats.u.callProcessID_Format1->ric_callProcess_ID = 1;

      asn1Print_E2SM_RC_CallProcessID("E2SM_RC_CallProcessID", callProcessID);

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
      c=asn1PE_E2SM_RC_CallProcessID(&asn1_ctx, callProcessID);
      printf("\n\n===asn1PE_E2SM_RC_CallProcessID===a=%d===========\n",c);
      *p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
      printf("p_event_msg_len :%d\n\n",*p_event_msg_len);
      //	printf("p_event_msg : %x\n\n",*p_event_msg);
      for( c=0; c< ((*p_event_msg_len)); c ++)
      {
         fprintf(stderr, "%02x ", p_event_msg[c]);
      }
      c=0;
      fprintf(stderr, "\n");

      p_value_ie3->data=p_event_msg;
      p_value_ie3->numocts=*p_event_msg_len;
      
      if (RT_OK != asn1Append_e2ap_RICcontrolAcknowledge_protocolIEs_3(&asn1_ctx,&p_asn_e2ap_RICcontrolAcknowledge->protocolIEs,p_value_ie3))
      {
         //GNB_TRACE(GNB_ERROR, "Failed to Add IE3 !!"); 
         printf("\n\n\nFailed to Add IE3 !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      //GNB_TRACE(GNB_INFO, " IE3 encoded");
      printf("\n\n\n IE3 encoded\n\n\n");

      e2ap_RICcontrolOutcome   *p_value_ie4 = NULL;
      p_value_ie4 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICcontrolOutcome);
      if(NULL == p_value_ie4)
      {
         //GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n"); 
         response = E2_FAILURE;
         break;
      }
      asn1Init_e2ap_RICcontrolOutcome(p_value_ie4);

      OSRTDListNode              *Node2 = NULL;
      E2SM_RC_ControlOutcome     *controlOutcome = NULL;
      rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_ControlOutcome,
         &Node2, &controlOutcome);
      if(NULL == controlOutcome)
      {
         //GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n"); 
         response = E2_FAILURE;
         break;
      }
      controlOutcome->ric_controlOutcome_formats.t = T_E2SM_RC_ControlOutcome_ric_controlOutcome_formats_controlOutcome_Format1;
      controlOutcome->ric_controlOutcome_formats.u.controlOutcome_Format1 = rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_ControlOutcome_Format1);
      if(NULL == controlOutcome->ric_controlOutcome_formats.u.controlOutcome_Format1)
      {
         //GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n"); 
         response = E2_FAILURE;
         break;
      }
      asn1Init_E2SM_RC_ControlOutcome_Format1_ranP_List(controlOutcome->ric_controlOutcome_formats.u.controlOutcome_Format1);
      

      OSRTDListNode                             *Node3 = NULL;
      E2SM_RC_ControlOutcome_Format1_Item       *controlOutcome_Format1= NULL;

      rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_ControlOutcome_Format1_Item,
         &Node3, &controlOutcome_Format1);
      if(NULL == controlOutcome_Format1)
      {
         //GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n"); 
         response = E2_FAILURE;
         break;
      }
      controlOutcome_Format1->ranParameter_ID = 1;
      controlOutcome_Format1->ranParameter_value.t = T_E2SM_RC_RANParameter_Value_valueOctS;
      controlOutcome_Format1->ranParameter_value.u.valueOctS = rtxMemAllocTypeZ(&asn1_ctx,OSDynOctStr);
      if(NULL == controlOutcome_Format1->ranParameter_value.u.valueOctS)
      {
         //GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n"); 
         response = E2_FAILURE;
         break;
      }
    
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
      controlOutcome_Format1->ranParameter_value.u.valueOctS->numocts = 9;
      controlOutcome_Format1->ranParameter_value.u.valueOctS->data = (const OSOCTET*)p_octstr_data;

      rtxDListAppendNode(&controlOutcome->ric_controlOutcome_formats.u.controlOutcome_Format1->ranP_List, Node3);
      asn1Print_E2SM_RC_ControlOutcome_Format1_Item("E2SM_RC_ControlOutcome_Format1_Item", controlOutcome_Format1);

      //rtxDListAppendNode(&controlOutcome->ric_controlOutcome_formats.u.controlOutcome_Format1->ranP_List, Node2);
      asn1Print_E2SM_RC_ControlOutcome("E2SM_RC_ControlOutcome", controlOutcome);

      if (RT_OK != asn1Append_e2ap_RICcontrolAcknowledge_protocolIEs_4(&asn1_ctx,&p_asn_e2ap_RICcontrolAcknowledge->protocolIEs,p_value_ie4))
      {
         //GNB_TRACE(GNB_ERROR, "Failed to Add IE4 !!"); 
         printf("\n\n\nFailed to Add IE4 !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      //GNB_TRACE(GNB_INFO, " IE4 encoded");
      printf("\n\n\n IE4 encoded\n\n\n");





      
   }while(0);
   asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);
   return response;
}



/***************************e2smrc ric_subscription_request1*************************/

e2_return_et encode_ric_subscription_request1
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len,
 GUAMI                                          *myguami
)

{

   e2ap_E2AP_PDU                           e2ap_pdu;
   OSCTXT                                  asn1_ctx;
   e2ap_RICsubscriptionRequest            *p_asn_ric_subscription_request = NULL;
   e2_return_et                            response = E2_SUCCESS;

  // struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
   UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg1=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt16  *p_event_msg_len=malloc(sizeof(UInt16));
   UInt16  *p_event_msg_len1=malloc(sizeof(UInt16));
   //pvalue->ricRequestorID=1;
 //  pvalue->ricInstanceID=55068;
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
      pvalue->ricRequestorID=1;
      pvalue->ricInstanceID=55068;

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
	   *p_value_ie2=2; 
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

      	   if(NULL == p_value_ie3)
	   {
		   //  GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
		   printf("\n\n\nMemory allocation failed !!\n\n\n"); 
		   response = E2_FAILURE;
		   break;
	   }
	 	

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
			    
			    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[0]=0x11;
			    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[1]=0x22;
			    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[2]=0x33;
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
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFRegionID.data[0]=0x2;
				ver=asn1PE_AMFRegionID (&asn1_ctx,(event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFRegionID)); 
		//		   printf("\nasn1PE_AMFRegionID=%d.\n\n",ver);
        			   *p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
		//		   printf("\nasn1PE_AMFRegionID--len=%d.\n\n",*p_event_msg_len);
				//    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFRegionID.data[0]=p_event_msg[0];
				   //printf("%d",11/0);
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFSetID.numbits=10;
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFSetID.data[0]=0xF1;


				    
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
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFPointer.data[0]=0x01;
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFPointer.data[1]=0x23;
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFPointer.data[2]=0x34;

				    
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
			case 2:
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

		 asn1Print_E2SM_RC_EventTrigger ("Event_trigger_definition",p_event);
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


      OSRTDListNode                                    *Node1=NULL;
      e2ap_RICactions_ToBeSetup_List_element           *listE=NULL;

      rtxDListInit(&(p_value_ie3->ricAction_ToBeSetup_List));
   	asn1Init_e2ap_RICactions_ToBeSetup_List(&(p_value_ie3->ricAction_ToBeSetup_List));

      rtxDListAllocNodeAndData(&asn1_ctx,
                  e2ap_RICactions_ToBeSetup_List_element,
                  &Node1,&listE);

      //memset(listE ,0,sizeof(e2ap_RICactions_ToBeSetup_List_element));
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

      listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->m.ricActionDefinitionPresent=1;
	   listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->m.ricSubsequentActionPresent=1;
	   listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionID=1;
	   listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricSubsequentAction.ricSubsequentActionType=e2ap_continue_;		
	   listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricSubsequentAction.ricTimeToWait=e2ap_w1ms;
	   listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionType=e2ap_insert;

	   a=0;
	   E2SM_RC_ActionDefinition           *action=NULL;
	   action=rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_ActionDefinition);
      if( action ==NULL)
      {
         printf("Malloc Failed !!\n\n\n");
         break;
      }
      action->ric_Style_Type=4;
      action->ric_actionDefinition_formats.t=T_E2SM_RC_ActionDefinition_ric_actionDefinition_formats_actionDefinition_Format3;
		action->ric_actionDefinition_formats.u.actionDefinition_Format3=rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_ActionDefinition_Format3);
		action->ric_actionDefinition_formats.u.actionDefinition_Format3->m.ueIDPresent=0;
		action->ric_actionDefinition_formats.u.actionDefinition_Format3->ric_InsertIndication_ID=1;
      rtxDListInit(&(action->ric_actionDefinition_formats.u.actionDefinition_Format3->ranP_InsertIndication_List));
      asn1Init_E2SM_RC_ActionDefinition_Format3_ranP_InsertIndication_List(
         &(action->ric_actionDefinition_formats.u.actionDefinition_Format3->ranP_InsertIndication_List));
      OSRTDListNode                                    *Node2=NULL;
      E2SM_RC_ActionDefinition_Format3_Item           *listE2=NULL;
      listE2=rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_ActionDefinition_Format3_Item);
      rtxDListAllocNodeAndData(&asn1_ctx,
                  E2SM_RC_ActionDefinition_Format3_Item,
                  &Node2,&listE2);
      listE2->m.ranParameter_DefinitionPresent=0;
      listE2->ranParameter_ID=1;
     rtxDListAppendNode(&(action->ric_actionDefinition_formats.u.actionDefinition_Format3->ranP_InsertIndication_List),Node2);

      asn1Print_E2SM_RC_ActionDefinition("Action definition",action);  

      rtxDListAppendNode(&(p_value_ie3->ricAction_ToBeSetup_List),Node1);



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
     // int a=0;
      ver =asn1PE_E2SM_RC_ActionDefinition(&asn1_ctx,action);
      printf("\n ver=%d.\n\n",ver);    
      asn1Print_E2SM_RC_ActionDefinition("test", action);

      printf("\npu_setBuffer success.\n\n");
      a=asn1PE_E2SM_RC_ActionDefinition(&asn1_ctx,action);
      printf("\n\n===asn1PE_E2SM_RC_ActionDefinition===a=%d===========\n",a);
      *p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
      printf("p_event_msg_len :%d\n\n",*p_event_msg_len);
      //	printf("p_event_msg : %x\n\n",*p_event_msg);
      for(a=0; a< ((*p_event_msg_len)); a ++)
      {
         fprintf(stderr, "%02x ", p_event_msg[a]);
      }
      a=0;
      fprintf(stderr, "\n");

  
      listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionDefinition.data=p_event_msg;
      listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionDefinition.numocts=*p_event_msg_len;





		




      if (RT_OK != asn1Append_e2ap_RICsubscriptionRequest_protocolIEs_3(&asn1_ctx,&p_asn_ric_subscription_request->protocolIEs,p_value_ie3))
      {
         //GNB_TRACE(GNB_ERROR, "Failed to Add IE3 !!");
         printf("\n\n\nFailed to Add IE3 !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      //GNB_TRACE(GNB_INFO, " IE3 encoded");


   }while(0);
   asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);
   return response;
}

//*****************************e2ap_RICindication2   **********************************
e2_return_et encode_ric_indication2
(
    UInt8   **pp_asn_msg,
    UInt16  *p_asn_msg_len
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
    UInt8   *p_event_msg2=malloc(E2CU_ASN1_BUFFER_LENGTH);
    UInt16  *p_event_msg_len=malloc(sizeof(UInt16));
    UInt16  *p_event_msg_len1=malloc(sizeof(UInt16));
    UInt16  *p_event_msg_len2=malloc(sizeof(UInt16));
    UInt16  *p_event_len1=malloc(sizeof(UInt16));

   // pvalue->ricRequestorID=1;
   // pvalue->ricInstanceID=55068;

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

      e2ap_RICindicationHeader   *p_value_ie7 =NULL;
      p_value_ie7 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICindicationHeader);

      if(NULL == p_value_ie7)
      {
         // GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      asn1Init_e2ap_RICindicationHeader(p_value_ie7);


      OSRTDListNode                       *Node1 = NULL;
      E2SM_RC_IndicationHeader            *p_value_ie7_1 =NULL;
      int b,list=0;

      rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_IndicationHeader,
          &Node1, &p_value_ie7_1);

      if(NULL == p_value_ie7_1)
      {
         // GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      asn1Init_E2SM_RC_IndicationHeader(p_value_ie7_1);


      p_value_ie7_1->ric_indicationHeader_formats.t=T_E2SM_RC_IndicationHeader_ric_indicationHeader_formats_indicationHeader_Format1;
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format1 = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_IndicationHeader_Format1);

      if(NULL == p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format1)
      {
         // GNB_TRACE(GNB_INFO, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format1->m.ric_eventTriggerCondition_IDPresent = 0;
     // p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format1->ric_eventTriggerCondition_ID = 1;
     // p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format1->extElem1  = rtxMemAllocTypeZ(&asn1_ctx, OSRTDList);
     rtxDListInit(&p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format1->extElem1);

     p_value_ie7_1->ric_indicationHeader_formats.u.indicationHeader_Format1->extElem1.count =96;
     // rtxDListAppendNode(&p_value_ie7,&Node1);

      //rtxDListAppendNode(&p_value_ie7,&Node1);

      asn1Print_E2SM_RC_IndicationHeader("RICindicationHeader", p_value_ie7_1);
      

      p_value_ie7->data =p_event_msg;
      p_value_ie7->numocts = 96;


      p_event_msg[0]  = 0;
      p_event_msg[1]  = 5;
      p_event_msg[2]  = 64;
      p_event_msg[3]  = 93;
      p_event_msg[4]  = 0;
      p_event_msg[5]  = 0;
      p_event_msg[6]  = 8;
      p_event_msg[7]  = 0;
      p_event_msg[8]  = 29;
      p_event_msg[9]  = 0;
      p_event_msg[10] = 5;
      p_event_msg[11] = 0;
      p_event_msg[12] = 0;
      p_event_msg[13] = 0;
      p_event_msg[14] = 0;
      p_event_msg[15] = 0;

      p_event_msg[16] = 0;
      p_event_msg[17] = 5;
      p_event_msg[18] = 0;
      p_event_msg[19] = 2;
      p_event_msg[20] = 0;
      p_event_msg[21] = 0;
      p_event_msg[22] = 0;
      p_event_msg[23] = 15;
      p_event_msg[24] = 0;
      p_event_msg[25] = 1;
      p_event_msg[26] = 0;
      p_event_msg[27] = 0;
      p_event_msg[28] = 27;
      p_event_msg[29] = 0;
      p_event_msg[30] = 2;
      p_event_msg[31] = 0;

      p_event_msg[32] = 1;
      p_event_msg[33] = 0;
      p_event_msg[34] = 28;
      p_event_msg[35] = 0;
      p_event_msg[36] = 1;
      p_event_msg[37] = 0;
      p_event_msg[38] = 0;
      p_event_msg[39] = 25;
      p_event_msg[40] = 0;
      p_event_msg[41] = 4;
      p_event_msg[42] = 3;
      p_event_msg[43] = 12;
      p_event_msg[44] = 1;
      p_event_msg[45] = 0;
      p_event_msg[46] = 0;
      p_event_msg[47] = 26;

      p_event_msg[48] = 0;
      p_event_msg[49] = 40;
      p_event_msg[50] = 39;
      p_event_msg[51] = 0;
      p_event_msg[52] = 0;
      p_event_msg[53] = 2;
      p_event_msg[54] = 0;
      p_event_msg[55] = 2;
      p_event_msg[56] = 42;
      p_event_msg[57] = 0;
      p_event_msg[58] = 0;
      p_event_msg[59] = 0;
      p_event_msg[60] = 0;
      p_event_msg[61] = 42;
      p_event_msg[62] = 0;
      p_event_msg[63] = 9;

      p_event_msg[64] = 0;
      p_event_msg[65] = 0;
      p_event_msg[66] = 241;
      p_event_msg[67] = 16;
      p_event_msg[68] = 0;
      p_event_msg[69] = 0;
      p_event_msg[70] = 0;
      p_event_msg[71] = 0;
      p_event_msg[72] = 0;
      p_event_msg[73] = 0;
      p_event_msg[74] = 3;
      p_event_msg[75] = 42;
      p_event_msg[76] = 0;
      p_event_msg[77] = 12;
      p_event_msg[78] = 4;
      p_event_msg[79] = 0;

      p_event_msg[80] = 49;
      p_event_msg[81] = 0;
      p_event_msg[82] = 0;
      p_event_msg[83] = 241;
      p_event_msg[84] = 16;
      p_event_msg[85] = 2;
      p_event_msg[86] = 0;
      p_event_msg[87] = 64;
      p_event_msg[88] = 0;
      p_event_msg[89] = 0;
      p_event_msg[90] = 0;
      p_event_msg[91] = 20;
      p_event_msg[92] = 0;
      p_event_msg[93] = 3;
      p_event_msg[94] = 2;
      p_event_msg[95] = 0;
      p_event_msg[96] = 48;

      // Debug print indication header
     // int b;
      fprintf(stderr, "header: ");
      for (b = 0; b < 97; b++) {
         fprintf(stderr, "%02x ", p_event_msg[b]);
      }
      b=0;
      fprintf(stderr, "\n"); 

      if (RT_OK != asn1Append_e2ap_RICindication_protocolIEs_6(&asn1_ctx,&p_asn_e2ap_RICindication->protocolIEs,p_value_ie7))
      {
         //   GNB_TRACE(GNB_ERROR, "Failed to Add IE6 !!");
         response = E2_FAILURE;
         break;
      }
      //GNB_TRACE(GNB_INFO, " IE6 encoded");
      printf("\n\n\n IE6 encoded\n\n\n");


      e2ap_RICindicationMessage *p_value_ie5 = NULL;
	   p_value_ie5 = rtxMemAllocTypeZ(&asn1_ctx,e2ap_RICindicationMessage);

      if(NULL == p_value_ie5)
      {
         // GNB_TRACE(GNB_INFO, "Memory allocation failed !!");   
         printf("\n\n\nMemory allocation failed !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      //rtxDListInit(p_value_ie5);
      asn1Init_e2ap_RICindicationMessage(p_value_ie5);



      // Allocate and populate the E2SM-RC-IndicationMessage
      OSRTDListNode                       *def_node1 = NULL;
      E2SM_RC_IndicationMessage           *p_event = NULL;
      rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_IndicationMessage,
         &def_node1, &p_event);

      if (def_node1 == NULL)
      {
         //GNB_TRACE(GNB_ERROR, "Failed to allocate E2SM-RC-IndicationMessage !!");
         printf("\n\n\nFailed to allocate E2SM-RC-IndicationMessage !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      asn1Init_E2SM_RC_IndicationMessage(p_event);
      p_event->ric_indicationMessage_formats.t=T_E2SM_RC_IndicationMessage_ric_indicationMessage_formats_indicationMessage_Format1; 
      p_event->ric_indicationMessage_formats.u.indicationMessage_Format1 = rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_IndicationMessage_Format1);
      if(NULL == p_event->ric_indicationMessage_formats.u.indicationMessage_Format1)
      {
         //GNB_TRACE(GNB_ERROR, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      asn1Init_E2SM_RC_IndicationMessage_Format1_ranP_Reported_List
         (&p_event->ric_indicationMessage_formats.u.indicationMessage_Format1->ranP_Reported_List);

      OSRTDListNode                            *def_node2 = NULL;  
      E2SM_RC_IndicationMessage_Format1_Item   *p_format5 = NULL;

      rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_IndicationMessage_Format1_Item,
         &def_node2, &p_format5);

      p_format5->ranParameter_ID = 1;
      p_format5->ranParameter_valueType.t = T_E2SM_RC_RANParameter_ValueType_ranP_Choice_ElementFalse;
      p_format5->ranParameter_valueType.u.ranP_Choice_ElementFalse = 
          rtxMemAllocTypeZ(&asn1_ctx,E2SM_RC_RANParameter_ValueType_Choice_ElementFalse);

      if(NULL == p_format5->ranParameter_valueType.u.ranP_Choice_ElementFalse)
      {
         //GNB_TRACE(GNB_ERROR, "Memory allocation failed !!");
         printf("\n\n\nMemory allocation failed !!\n\n\n");
         response = E2_FAILURE;
         break;
      }
      p_format5->ranParameter_valueType.u.ranP_Choice_ElementFalse->m.ranParameter_valuePresent = 1;
      p_format5->ranParameter_valueType.u.ranP_Choice_ElementFalse->ranParameter_value.t = T_E2SM_RC_RANParameter_Value_valueOctS;

      p_event_msg1[0]  = 0;
      p_event_msg1[1]  = 5;
      p_event_msg1[2]  = 64;
      p_event_msg1[3]  = 93;
      p_event_msg1[4]  = 0;
      p_event_msg1[5]  = 0;
      p_event_msg1[6]  = 8;
      p_event_msg1[7]  = 0;
      p_event_msg1[8]  = 29;
      p_event_msg1[9]  = 0;
      p_event_msg1[10] = 5;
      p_event_msg1[11] = 0;
      p_event_msg1[12] = 0;
      p_event_msg1[13] = 0;
      p_event_msg1[14] = 0;
      p_event_msg1[15] = 0;

      p_event_msg1[16] = 0;
      p_event_msg1[17] = 5;
      p_event_msg1[18] = 0;
      p_event_msg1[19] = 2;
      p_event_msg1[20] = 0;
      p_event_msg1[21] = 0;
      p_event_msg1[22] = 0;
      p_event_msg1[23] = 15;
      p_event_msg1[24] = 0;
      p_event_msg1[25] = 1;
      p_event_msg1[26] = 0;
      p_event_msg1[27] = 0;
      p_event_msg1[28] = 27;
      p_event_msg1[29] = 0;
      p_event_msg1[30] = 2;
      p_event_msg1[31] = 0;

      p_event_msg1[32] = 1;
      p_event_msg1[33] = 0;
      p_event_msg1[34] = 28;
      p_event_msg1[35] = 0;
      p_event_msg1[36] = 1;
      p_event_msg1[37] = 0;
      p_event_msg1[38] = 0;
      p_event_msg1[39] = 25;
      p_event_msg1[40] = 0;
      p_event_msg1[41] = 4;
      p_event_msg1[42] = 3;
      p_event_msg1[43] = 12;
      p_event_msg1[44] = 1;
      p_event_msg1[45] = 0;
      p_event_msg1[46] = 0;
      p_event_msg1[47] = 26;

      p_event_msg1[48] = 0;
      p_event_msg1[49] = 40;
      p_event_msg1[50] = 39;
      p_event_msg1[51] = 0;
      p_event_msg1[52] = 0;
      p_event_msg1[53] = 2;
      p_event_msg1[54] = 0;
      p_event_msg1[55] = 2;
      p_event_msg1[56] = 42;
      p_event_msg1[57] = 0;
      p_event_msg1[58] = 0;
      p_event_msg1[59] = 0;
      p_event_msg1[60] = 0;
      p_event_msg1[61] = 42;
      p_event_msg1[62] = 0;
      p_event_msg1[63] = 9;

      p_event_msg1[64] = 0;
      p_event_msg1[65] = 0;
      p_event_msg1[66] = 241;
      p_event_msg1[67] = 16;
      p_event_msg1[68] = 0;
      p_event_msg1[69] = 0;
      p_event_msg1[70] = 0;
      p_event_msg1[71] = 0;
      p_event_msg1[72] = 0;
      p_event_msg1[73] = 0;
      p_event_msg1[74] = 3;
      p_event_msg1[75] = 42;
      p_event_msg1[76] = 0;
      p_event_msg1[77] = 12;
      p_event_msg1[78] = 4;
      p_event_msg1[79] = 0;

      p_event_msg1[80] = 49;
      p_event_msg1[81] = 0;
      p_event_msg1[82] = 0;
      p_event_msg1[83] = 241;
      p_event_msg1[84] = 16;
      p_event_msg1[85] = 2;
      p_event_msg1[86] = 0;
      p_event_msg1[87] = 64;
      p_event_msg1[88] = 0;
      p_event_msg1[89] = 0;
      p_event_msg1[90] = 0;
      p_event_msg1[91] = 20;
      p_event_msg1[92] = 0;
      p_event_msg1[93] = 3;
      p_event_msg1[94] = 2;
      p_event_msg1[95] = 0;
      p_event_msg1[96] = 48;



      // Debug print ranparameter value part
      fprintf(stderr, "RAN Parameter Value Part (97 bytes): ");
      for (int e = 0; e < 97; e++) {
         fprintf(stderr, "%02x ", p_event_msg1[e]);
      }
      fprintf(stderr, "\n");

      p_format5->ranParameter_valueType.u.ranP_Choice_ElementFalse->ranParameter_value.u.valueOctS = rtxMemAllocTypeZ(&asn1_ctx, OSDynOctStr);
      p_format5->ranParameter_valueType.u.ranP_Choice_ElementFalse->ranParameter_value.u.valueOctS->data = p_event_msg1;
      p_format5->ranParameter_valueType.u.ranP_Choice_ElementFalse->ranParameter_value.u.valueOctS->numocts=97;

      
      rtxDListAppendNode(&p_event->ric_indicationMessage_formats.u.indicationMessage_Format1->ranP_Reported_List,def_node2); 
     // asn1Print_E2SM_RC_IndicationMessage_Format5_ranP_Requested_List("ranP_Requested_List",
       //  &p_event->ric_indicationMessage_formats.u.indicationMessage_Format5->ranP_Requested_List);
       
      asn1Print_E2SM_RC_IndicationMessage("E2SM_RC_IndicationMessage", p_event);

     // Encode E2SM_RC_RANFunctionDefinition_Insert
      memset(p_event_msg1,0,E2CU_ASN1_BUFFER_LENGTH);
      if( RT_OK != pu_setBuffer(&asn1_ctx, p_event_msg1,E2CU_ASN1_BUFFER_LENGTH, TRUE))
      {
         printf("\n\npu_setBuffer failed.\n");
         response = E2_FAILURE;
         break;
      }
      else             
      printf("\npu_setBuffer success.\n\n");
      int a=asn1PE_E2SM_RC_IndicationMessage(&asn1_ctx,p_event);
      printf("\n\n===asn1PE_E2SM_RC_IndicationMessage===a=%d===========\n",a);
      *p_event_msg_len1 = (UInt16)pe_GetMsgLen(&asn1_ctx);
      printf("p_event_msg_len :%d\n\n",*p_event_msg_len1);
      //	printf("p_event_msg : %x\n\n",*p_event_msg);
      for(a=0; a< ((*p_event_msg_len1)); a ++)
      {
         fprintf(stderr, "%02x ", p_event_msg1[a]);
      }
      a=0;
      fprintf(stderr, "\n");



      p_value_ie5->data=p_event_msg1;
      p_value_ie5->numocts=*p_event_msg_len1;
 
      
     //abort();
     /* total length = 96 bytes : index 0 to 95 */

     /**  p_event_msg[0]  = 0;
      p_event_msg[1]  = 5;
      p_event_msg[2]  = 64;
      p_event_msg[3]  = 93;
      p_event_msg[4]  = 0;
      p_event_msg[5]  = 0;
      p_event_msg[6]  = 8;
      p_event_msg[7]  = 0;
      p_event_msg[8]  = 29;
      p_event_msg[9]  = 0;
      p_event_msg[10] = 5;
      p_event_msg[11] = 0;
      p_event_msg[12] = 0;
      p_event_msg[13] = 0;
      p_event_msg[14] = 0;
      p_event_msg[15] = 0;

      p_event_msg[16] = 0;
      p_event_msg[17] = 5;
      p_event_msg[18] = 0;
      p_event_msg[19] = 2;
      p_event_msg[20] = 0;
      p_event_msg[21] = 0;
      p_event_msg[22] = 0;
      p_event_msg[23] = 15;
      p_event_msg[24] = 0;
      p_event_msg[25] = 1;
      p_event_msg[26] = 0;
      p_event_msg[27] = 0;
      p_event_msg[28] = 27;
      p_event_msg[29] = 0;
      p_event_msg[30] = 2;
      p_event_msg[31] = 0;

      p_event_msg[32] = 1;
      p_event_msg[33] = 0;
      p_event_msg[34] = 28;
      p_event_msg[35] = 0;
      p_event_msg[36] = 1;
      p_event_msg[37] = 0;
      p_event_msg[38] = 0;
      p_event_msg[39] = 25;
      p_event_msg[40] = 0;
      p_event_msg[41] = 4;
      p_event_msg[42] = 3;
      p_event_msg[43] = 12;
      p_event_msg[44] = 1;
      p_event_msg[45] = 0;
      p_event_msg[46] = 0;
      p_event_msg[47] = 26;

      p_event_msg[48] = 0;
      p_event_msg[49] = 40;
      p_event_msg[50] = 39;
      p_event_msg[51] = 0;
      p_event_msg[52] = 0;
      p_event_msg[53] = 2;
      p_event_msg[54] = 0;
      p_event_msg[55] = 2;
      p_event_msg[56] = 42;
      p_event_msg[57] = 0;
      p_event_msg[58] = 0;
      p_event_msg[59] = 0;
      p_event_msg[60] = 0;
      p_event_msg[61] = 42;
      p_event_msg[62] = 0;
      p_event_msg[63] = 9;

      p_event_msg[64] = 0;
      p_event_msg[65] = 0;
      p_event_msg[66] = 241;
      p_event_msg[67] = 16;
      p_event_msg[68] = 0;
      p_event_msg[69] = 0;
      p_event_msg[70] = 0;
      p_event_msg[71] = 0;
      p_event_msg[72] = 0;
      p_event_msg[73] = 0;
      p_event_msg[74] = 3;
      p_event_msg[75] = 42;
      p_event_msg[76] = 0;
      p_event_msg[77] = 12;
      p_event_msg[78] = 4;
      p_event_msg[79] = 0;

      p_event_msg[80] = 49;
      p_event_msg[81] = 0;
      p_event_msg[82] = 0;
      p_event_msg[83] = 241;
      p_event_msg[84] = 16;
      p_event_msg[85] = 2;
      p_event_msg[86] = 0;
      p_event_msg[87] = 64;
      p_event_msg[88] = 0;
      p_event_msg[89] = 0;
      p_event_msg[90] = 0;
      p_event_msg[91] = 20;
      p_event_msg[92] = 0;
      p_event_msg[93] = 3;
      p_event_msg[94] = 2;
      p_event_msg[95] = 0;
      p_event_msg[96] = 48;

      // Debug print indication header
     // int b;
      fprintf(stderr, "header: ");
      for (b = 0; b < 97; b++) {
         fprintf(stderr, "%02x ", p_event_msg[b]);
      }
      b=0;
      fprintf(stderr, "\n");

      p_value_ie5->data =p_event_msg;
      p_value_ie5->numocts = 96;  ***/
     
      if (RT_OK != asn1Append_e2ap_RICindication_protocolIEs_7(&asn1_ctx,&p_asn_e2ap_RICindication->protocolIEs,p_value_ie5))
      {
         //GNB_TRACE(GNB_ERROR, "Failed to Add IE7 !!");
         response = E2_FAILURE;
         break;
      }
      //GNB_TRACE(GNB_INFO, " IE7 encoded");
      printf("\n\n\n IE7 encoded\n\n\n");

   }while(0);
   asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);
   return response;
}



/***************************ric_subscription_request2*************************/

 e2_return_et encode_ric_subscription_request2
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len,
 GUAMI                                          *myguami
)

{

   e2ap_E2AP_PDU                           e2ap_pdu;
   OSCTXT                                  asn1_ctx;
   e2ap_RICsubscriptionRequest            *p_asn_ric_subscription_request = NULL;
   e2_return_et                            response = E2_SUCCESS;

  // struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
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
      
      pvalue->ricRequestorID = 1;
      pvalue->ricInstanceID  = 55068;


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
	   *p_value_ie2=2; 
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
			    
			   // event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[0]=0x11;
			   // event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[1]=0x22;
			   // event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[2]=0x33;
			    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[0]=0x12;
			    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[1]=0x23;
			    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[2]=0x31;
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
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFRegionID.data[0]=0x2;
				ver=asn1PE_AMFRegionID (&asn1_ctx,(event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFRegionID)); 
		//		   printf("\nasn1PE_AMFRegionID=%d.\n\n",ver);
        			   *p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
		//		   printf("\nasn1PE_AMFRegionID--len=%d.\n\n",*p_event_msg_len);
				//    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFRegionID.data[0]=p_event_msg[0];
				   //printf("%d",11/0);
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFSetID.numbits=10;
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFSetID.data[0]=0xF1;


				    
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
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFPointer.data[0]=0x01;
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFPointer.data[1]=0x23;
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFPointer.data[2]=0x34;

				    
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
			case 2:
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

		asn1Print_E2SM_RC_EventTrigger ("Event_trigger_definition",p_event);
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


      OSRTDListNode                                    *Node1=NULL;
      e2ap_RICactions_ToBeSetup_List_element           *listE=NULL;

      int                   m=0;
	//OSRTDListNode        *Node1=NULL;
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
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricSubsequentAction.ricSubsequentActionType=e2ap_continue_;
			
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricSubsequentAction.ricTimeToWait=e2ap_w1ms;
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionID=1;
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionType=e2ap_report;
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
				
				*p_event_msg="0x0001010000000001";
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
	        		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionDefinition.data=(OSOCTET *)p_event_msg;	
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
				*p_event_msg="0x00010440000000000017";
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
				*p_event_msg="0x00010340000000000006";
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
         response = E2_FAILURE;
         break;
      }
      //GNB_TRACE(GNB_INFO, " IE3 encoded");
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

     }while(0);
    // asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);
    return response;

}


/***************************ric_subscription_request3*************************/

 e2_return_et encode_ric_subscription_request3
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len,
 GUAMI                                          *myguami
)

{

   e2ap_E2AP_PDU                           e2ap_pdu;
   OSCTXT                                  asn1_ctx;
   e2ap_RICsubscriptionRequest            *p_asn_ric_subscription_request = NULL;
   e2_return_et                            response = E2_SUCCESS;

 //  struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
   UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg1=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt16  *p_event_msg_len=malloc(sizeof(UInt16));
   UInt16  *p_event_msg_len1=malloc(sizeof(UInt16));
  // pvalue->ricRequestorID=2;
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
      
      pvalue->ricRequestorID = 1;
      pvalue->ricInstanceID  = 55068;
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
	   *p_value_ie2=2; 
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
			    
			   // event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[0]=0x11;
			   // event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[1]=0x22;
			   // event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[2]=0x33;
			    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[0]=0x12;
			    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[1]=0x23;
			    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.pLMNIdentity.data[2]=0x31;
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
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFRegionID.data[0]=0x2;
				ver=asn1PE_AMFRegionID (&asn1_ctx,(event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFRegionID)); 
		//		   printf("\nasn1PE_AMFRegionID=%d.\n\n",ver);
        			   *p_event_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
		//		   printf("\nasn1PE_AMFRegionID--len=%d.\n\n",*p_event_msg_len);
				//    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFRegionID.data[0]=p_event_msg[0];
				   //printf("%d",11/0);
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFSetID.numbits=10;
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFSetID.data[0]=0xF1;


				    
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
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFPointer.data[0]=0x01;
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFPointer.data[1]=0x23;
				    event_item->messageType.u.messageType_Choice_NI->nI_Identifier.u.nG->guami.aMFPointer.data[2]=0x34;

				    
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
				    event_item->messageType.u.messageType_Choice_NI->nI_Message.interfaceProcedureID=28;
				    else
				    event_item->messageType.u.messageType_Choice_NI->nI_Message.interfaceProcedureID=41;
				    printf("\n\nInterface : %d\n",event_item->messageType.u.messageType_Choice_NI->nI_Message.interfaceProcedureID);
		   
				   event_item->messageType.u.messageType_Choice_NI->nI_Message.messageType=initiatingMessage;
		   
					rtxDListAppendNode (
					&(p_event->ric_eventTrigger_formats.u.eventTrigger_Format1->message_List),
					Node);
				    break;
			case 2:
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

		asn1Print_E2SM_RC_EventTrigger ("Event_trigger_definition",p_event);
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


      OSRTDListNode                                    *Node1=NULL;
      e2ap_RICactions_ToBeSetup_List_element           *listE=NULL;

      int m=0;
      //OSRTDListNode        *Node1=NULL;
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
               listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricSubsequentAction.ricSubsequentActionType=e2ap_continue_;
            
               listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricSubsequentAction.ricTimeToWait=e2ap_w1ms;
               listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionID=1;
               listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionType=e2ap_report;
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
               
               *p_event_msg="0x0001010000000001";
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
                  listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionDefinition.data=(OSOCTET *)p_event_msg;	
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
               *p_event_msg="0x00010440000000000017";
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
               *p_event_msg="0x00010340000000000006";
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
         response = E2_FAILURE;
         break;
      }
      //GNB_TRACE(GNB_INFO, " IE3 encoded");
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

     }while(0);
    // asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);
    return response;

}




/***************************ric_subscription_request4*************************/

 e2_return_et encode_ric_subscription_request4
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len,
 GUAMI                                          *myguami
)

{

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
 //  pvalue->ricRequestorID=3;
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
      
      pvalue->ricRequestorID = 1;
      pvalue->ricInstanceID  = 55068;
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
	   *p_value_ie2=2; 
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


      int a = 0;

     /* E2SM_RC_EventTrigger *p_event  = NULL;
      E2SM_RC_EventTrigger *p_event1 = NULL;

      /* Allocate EventTrigger */
      /*p_event = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_EventTrigger);
      p_event1 = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_EventTrigger);

      if (!p_event || !p_event1)
      {
         printf("Memory allocation failed\n");
         response = E2_FAILURE;
         break;
      }
      p_event->ric_eventTrigger_formats.t =T_E2SM_RC_EventTrigger_ric_eventTrigger_formats_eventTrigger_Format2;
      p_event->ric_eventTrigger_formats.u.eventTrigger_Format2 = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_EventTrigger_Format2);
      /*p_event->ric_eventTrigger_formats.u.eventTrigger_Format2->m.associatedE2NodeInfoPresent = 1;
      p_event->ric_eventTrigger_formats.u.eventTrigger_Format2->m.associatedUEInfoPresent = 0;
      p_event->ric_eventTrigger_formats.u.eventTrigger_Format2->ric_callProcessType_ID = 3;
      p_event->ric_eventTrigger_formats.u.eventTrigger_Format2->ric_callProcessBreakpoint_ID = 3;

      rtxDListInit(&p_event->ric_eventTrigger_formats.u.eventTrigger_Format2->associatedE2NodeInfo);

      /* Create RANParameter Testing Item */
     /* E2SM_RC_RANParameter_Testing_Item *event_item = NULL;
      OSRTDListNode                     *Node = NULL;

      rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_RANParameter_Testing_Item,&Node, &event_item);
      event_item->ranParameter_ID = 27310;
      event_item->ranParameter_Type.t =T_E2SM_RC_RANParameter_Testing_Item_ranParameter_Type_ranP_Choice_Structure;
      event_item->ranParameter_Type.u.ranP_Choice_Structure =rtxMemAllocTypeZ(&asn1_ctx,
          E2SM_RC_RANParameter_Testing_Item_Choice_Structure);

      rtxDListInit(&event_item->ranParameter_Type.u.ranP_Choice_Structure->ranParameter_Structure);
     // asn1Init_E2SM_RC_RANParameter_Testing_STRUCTURE(&event_item->ranParameter_Type.u.ranP_Choice_Structure);
      
      OSRTDListNode                     *Node2 = NULL;
      E2SM_RC_RANParameter_Testing_Item *event_item1 = NULL;
      
      rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_RANParameter_Testing_Item,&Node2,&event_item1);
      
      event_item1->ranParameter_ID = 15011;
      event_item1->ranParameter_Type.t = T_E2SM_RC_RANParameter_Testing_Item_ranParameter_Type_ranP_Choice_ElementFalse;
     // rtxDListInit(&event_item1->ranParameter_Type.u.ranP_Choice_ElementFalse);

     event_item1->ranParameter_Type.u.ranP_Choice_ElementFalse =rtxMemAllocTypeZ(&asn1_ctx,
          E2SM_RC_RANParameter_Testing_Item_Choice_ElementFalse);

      event_item1->ranParameter_Type.u.ranP_Choice_ElementFalse->m.ranParameter_ValuePresent = 1;
      event_item1->ranParameter_Type.u.ranP_Choice_ElementFalse->m.logicalORPresent          = 0;
     // event_item1->ranParameter_Type.u.ranP_Choice_ElementFalse.m.ranParameter_ValuePresent = 1;

      event_item1->ranParameter_Type.u.ranP_Choice_ElementFalse->ranParameter_TestCondition.t =
            T_E2SM_RC_RANParameter_TestingCondition_ranP_Choice_comparison;

      event_item1->ranParameter_Type.u.ranP_Choice_ElementFalse->ranParameter_TestCondition.u.ranP_Choice_comparison =E2SM_RC_greaterthan;

      event_item1->ranParameter_Type.u.ranP_Choice_ElementFalse ->ranParameter_Value.t = T_E2SM_RC_RANParameter_Value_valueReal;
      event_item1->ranParameter_Type.u.ranP_Choice_ElementFalse->ranParameter_Value.u.valueReal = 0.0;

      rtxDListAppendNode(&event_item->ranParameter_Type.u.ranP_Choice_Structure->ranParameter_Structure,Node2);
      
      
      rtxDListAppendNode(&p_event->ric_eventTrigger_formats.u.eventTrigger_Format2->associatedE2NodeInfo,
            Node);

		asn1Print_E2SM_RC_EventTrigger ("Event_trigger_definition",p_event);
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
      p_value_ie3->ricEventTriggerDefinition.numocts=*p_event_msg_len; **/
	
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
		asn1Print_E2SM_RC_EventTrigger ("Event_trigger_definition",p_event_msg1);
		a=0;p_value_ie3->ricEventTriggerDefinition.numocts=20;
      p_value_ie3->ricEventTriggerDefinition.data=(OSOCTET *)p_event_msg1; 
      asn1Print_E2SM_RC_EventTrigger("test Event",p_event_msg1);
	


      OSRTDListNode                                    *Node1=NULL;
      e2ap_RICactions_ToBeSetup_List_element           *listE=NULL;
      int m,flag=0;
      //OSRTDListNode        *Node1=NULL;
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
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricSubsequentAction.ricSubsequentActionType=e2ap_continue_;
			
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricSubsequentAction.ricTimeToWait=e2ap_w1ms;
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionID=1;
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionType=e2ap_report;
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
				
				*p_event_msg="0x0001010000000001";
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
	        		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionDefinition.data=(OSOCTET *)p_event_msg;	
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
				*p_event_msg="0x00010440000000000017";
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
				*p_event_msg="0x00010340000000000006";
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
         response = E2_FAILURE;
         break;
      }
      //GNB_TRACE(GNB_INFO, " IE3 encoded");
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

     }while(0);
    // asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);
    return response;

}


/***************************ric_subscription_request5*************************/

 e2_return_et encode_ric_subscription_request5
(
 UInt8                                          **pp_asn_msg,   
 UInt16                                         *p_asn_msg_len,
 GUAMI                                          *myguami
)

{

   e2ap_E2AP_PDU                           e2ap_pdu;
   OSCTXT                                  asn1_ctx;
   e2ap_RICsubscriptionRequest            *p_asn_ric_subscription_request = NULL;
   e2_return_et                            response = E2_SUCCESS;

  // struct e2ap_RICrequestID                        *pvalue=malloc(sizeof( struct e2ap_RICrequestID ));
   UInt8   *p_asn_msg = malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt8   *p_event_msg1=malloc(E2CU_ASN1_BUFFER_LENGTH);
   UInt16  *p_event_msg_len=malloc(sizeof(UInt16));
   UInt16  *p_event_msg_len1=malloc(sizeof(UInt16));
 //  pvalue->ricRequestorID=5;
 //  pvalue->ricInstanceID=55068;
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
      
      pvalue->ricRequestorID = 1;
      pvalue->ricInstanceID  = 55068;

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
	   *p_value_ie2=2; 
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


      int a = 0;

      E2SM_RC_EventTrigger *p_event  = NULL;
      E2SM_RC_EventTrigger *p_event1 = NULL;

      /* Allocate EventTrigger */
      p_event = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_EventTrigger);
      p_event1 = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_EventTrigger);

      if (!p_event || !p_event1)
      {
         printf("Memory allocation failed\n");
         response = E2_FAILURE;
         break;
      }
      p_event->ric_eventTrigger_formats.t =T_E2SM_RC_EventTrigger_ric_eventTrigger_formats_eventTrigger_Format2;
      p_event->ric_eventTrigger_formats.u.eventTrigger_Format2 = rtxMemAllocTypeZ(&asn1_ctx, E2SM_RC_EventTrigger_Format2);
      p_event->ric_eventTrigger_formats.u.eventTrigger_Format2->m.associatedE2NodeInfoPresent = 1;
      p_event->ric_eventTrigger_formats.u.eventTrigger_Format2->m.associatedUEInfoPresent = 0;
      p_event->ric_eventTrigger_formats.u.eventTrigger_Format2->ric_callProcessType_ID = 3;
      p_event->ric_eventTrigger_formats.u.eventTrigger_Format2->ric_callProcessBreakpoint_ID = 3;

      rtxDListInit(&p_event->ric_eventTrigger_formats.u.eventTrigger_Format2->associatedE2NodeInfo);

      /* Create RANParameter Testing Item */
      E2SM_RC_RANParameter_Testing_Item *event_item = NULL;
      OSRTDListNode                     *Node = NULL;

      rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_RANParameter_Testing_Item,&Node, &event_item);
      event_item->ranParameter_ID = 27310;
      event_item->ranParameter_Type.t =T_E2SM_RC_RANParameter_Testing_Item_ranParameter_Type_ranP_Choice_Structure;
      event_item->ranParameter_Type.u.ranP_Choice_Structure =rtxMemAllocTypeZ(&asn1_ctx,
          E2SM_RC_RANParameter_Testing_Item_Choice_Structure);

      rtxDListInit(&event_item->ranParameter_Type.u.ranP_Choice_Structure->ranParameter_Structure);
     // asn1Init_E2SM_RC_RANParameter_Testing_STRUCTURE(&event_item->ranParameter_Type.u.ranP_Choice_Structure);
      
      OSRTDListNode                     *Node2 = NULL;
      E2SM_RC_RANParameter_Testing_Item *event_item1 = NULL;
      
      rtxDListAllocNodeAndData(&asn1_ctx,E2SM_RC_RANParameter_Testing_Item,&Node2,&event_item1);
      
      event_item1->ranParameter_ID = 15011;
      event_item1->ranParameter_Type.t = T_E2SM_RC_RANParameter_Testing_Item_ranParameter_Type_ranP_Choice_ElementFalse;
     // rtxDListInit(&event_item1->ranParameter_Type.u.ranP_Choice_ElementFalse);

     event_item1->ranParameter_Type.u.ranP_Choice_ElementFalse =rtxMemAllocTypeZ(&asn1_ctx,
          E2SM_RC_RANParameter_Testing_Item_Choice_ElementFalse);

      event_item1->ranParameter_Type.u.ranP_Choice_ElementFalse->m.ranParameter_ValuePresent = 1;
      event_item1->ranParameter_Type.u.ranP_Choice_ElementFalse->m.logicalORPresent          = 0;
     // event_item1->ranParameter_Type.u.ranP_Choice_ElementFalse.m.ranParameter_ValuePresent = 1;

      event_item1->ranParameter_Type.u.ranP_Choice_ElementFalse->ranParameter_TestCondition.t =
            T_E2SM_RC_RANParameter_TestingCondition_ranP_Choice_comparison;

      event_item1->ranParameter_Type.u.ranP_Choice_ElementFalse->ranParameter_TestCondition.u.ranP_Choice_comparison =E2SM_RC_greaterthan;

      event_item1->ranParameter_Type.u.ranP_Choice_ElementFalse ->ranParameter_Value.t = T_E2SM_RC_RANParameter_Value_valueReal;
      event_item1->ranParameter_Type.u.ranP_Choice_ElementFalse->ranParameter_Value.u.valueReal = 0.0;

      rtxDListAppendNode(&event_item->ranParameter_Type.u.ranP_Choice_Structure->ranParameter_Structure,Node2);
      
      
      rtxDListAppendNode(&p_event->ric_eventTrigger_formats.u.eventTrigger_Format2->associatedE2NodeInfo,
            Node);

		asn1Print_E2SM_RC_EventTrigger ("Event_trigger_definition",p_event);
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


      OSRTDListNode                                    *Node1=NULL;
      e2ap_RICactions_ToBeSetup_List_element           *listE=NULL;
      int m,flag,ver=0;

      //OSRTDListNode        *Node1=NULL;
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
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricSubsequentAction.ricSubsequentActionType=e2ap_continue_;
			
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricSubsequentAction.ricTimeToWait=e2ap_w1ms;
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionID=1;
	    		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionType=e2ap_report;
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
				
				*p_event_msg="0x0001010000000001";
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
	        		listE->value.u._e2ap_RICaction_ToBeSetup_ItemIEs_1->ricActionDefinition.data=(OSOCTET *)p_event_msg;	
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
				*p_event_msg="0x00010440000000000017";
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
				*p_event_msg="0x00010340000000000006";
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
         response = E2_FAILURE;
         break;
      }
      //GNB_TRACE(GNB_INFO, " IE3 encoded");
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

     }while(0);
     //asn1Print_e2ap_E2AP_PDU("TEST",&e2ap_pdu);
    return response;

}
