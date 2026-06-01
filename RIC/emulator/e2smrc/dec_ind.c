
#include "head.h"
#define E2_ASN_OK 0


E2SM_RC_CallProcessID * decode_ric_callProcess_id(OSCTXT *asn1_ctx,E2SM_RC_CallProcessID *ric_call,e2ap_RICindication *pdu)
{

UInt16      asn_msg_len;

int m=0,c;
e2ap_RICindication_protocolIEs   *IEs=NULL;
e2ap_RICindication_protocolIEs_element   *IEs_ELe=NULL;
//OSRTSListNode                   *pnode=NULL;
OSRTDListNode *pnode = NULL;
e2ap_RICcallProcessID      *cpid=NULL;
int                           *crash=NULL;
                         



  ric_call=(E2SM_RC_CallProcessID*)rtxMemAllocTypeZ(asn1_ctx,E2SM_RC_CallProcessID);
  





printf("\n\ndecode_ric_callProcess_id initiated !!.\n");
IEs=&pdu->protocolIEs;
//asn1Print_e2ap_RICindication_protocolIEs("ProtocolIEs",IEs);
//printf("\n\nafter IEs=pdu->protocolIEs.tail \n%d	!!.\n",*crash);
//decode the Ric Indication header from the above elelment

pnode=IEs->tail;

IEs_ELe=pnode->data;
//IEs_ELe=IEs->tail;
//printf("\n\nafter IEs=pdu->protocolIEs.tail \n%d	!!.\n",*crash);
//if(IEs->value.t == T15e2ap___e2ap_RICindication_IEs_8)
//{
cpid=IEs_ELe->value.u._e2ap_RICindication_IEs_8;
if(cpid != NULL)
{




 if( RT_OK != pu_setBuffer(asn1_ctx,cpid->data ,E2CU_ASN1_BUFFER_LENGTH, TRUE))
                        {
                                printf("\n\npu_setBuffer failed.\n");
                        }
                        else
                                printf("\n\npu_setBuffer success.\n");
                        m=asn1PD_E2SM_RC_CallProcessID(asn1_ctx,ric_call);
                                printf("\n\nasn1PD_E2SM_RC_CallProcessID:%d.\n",m);

if(m!=0)
	printf("asn1PD_E2SM_RC_CallProcessID failed\n");

asn1Print_E2SM_RC_CallProcessID("CallProcessID",ric_call);

}
//}

return ric_call;

}





void decode_Ind_header(OSCTXT *asn1_ctx,E2SM_RC_IndicationHeader **header,e2ap_RICindication *pdu)
{

UInt16      asn_msg_len;

int m=0,c;
e2ap_RICindication_protocolIEs   *IEs=NULL;
e2ap_RICindication_protocolIEs_element   *IEs_ELe=NULL;
OSRTDListNode                   *pnode=NULL;
e2ap_RICindicationHeader      *ih=NULL;
int                           *crash=NULL;
                         
//e2ap_RICindicationType       *type=NULL;
e2ap_RICindicationType       type =0;


  *header=(E2SM_RC_IndicationHeader*)rtxMemAllocTypeZ(asn1_ctx,E2SM_RC_IndicationHeader);






  printf("\n\ndecode_ric_callProcess_id initiated !!.\n");
  IEs=&pdu->protocolIEs;
  asn1Print_e2ap_RICindication_protocolIEs("ProtocolIEs",IEs);
  //printf("\n\nafter IEs=pdu->protocolIEs.tail \n%d	!!.\n",*crash);
  pnode=IEs->tail;
  for(c=0;c<3;c++)
  {
	  pnode=pnode->prev;
  }
  IEs_ELe=pnode->data;
  type= IEs_ELe->value.u._e2ap_RICindication_IEs_5;

  if(type == 0)
  {
	 // return NULL;
	 *header = NULL;  
    return;
  }
  else
  {
	  pnode=IEs->tail;
	  for(c=0;c<2;c++)
	  {
		  pnode=pnode->prev;
	  }
	  IEs_ELe=pnode->data;

	  ih=IEs_ELe->value.u._e2ap_RICindication_IEs_6;
	  //decode the Ric Indication header from the above elelment


	  //IEs_ELe=IEs->tail;
	  //printf("\n\nafter IEs=pdu->protocolIEs.tail \n%d	!!.\n",*crash);
	  //if(IEs->value.t == T15e2ap___e2ap_RICindication_IEs_8)
	  //{
	  if(ih != NULL)
	  {




		  if( RT_OK != pu_setBuffer(asn1_ctx,ih->data ,E2CU_ASN1_BUFFER_LENGTH, TRUE))
		  {
			  printf("\n\npu_setBuffer failed.\n");
		  }
		  else
			  printf("\n\npu_setBuffer success.\n");
		  m=asn1PD_E2SM_RC_IndicationHeader(asn1_ctx,*header);
		  printf("\n\nasn1PD_E2SM_RC_CallProcessID:%d.\n",m);

		  if(m!=0)
			  printf("asn1PD_E2SM_RC_CallProcessID failed\n");

		  asn1Print_E2SM_RC_IndicationHeader("CallProcessID",*header);

	  }
	  //}
  }
 // return header;

}
