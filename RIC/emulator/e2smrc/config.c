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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "config.h"


/* ===================================================== */
/* Convert HEX string → byte array                       */
/* Example: "0A0001" → {0x0A,0x00,0x01}                   */
/* ===================================================== */
static uint16_t hex_to_bytes(const char *hex, uint8_t *out)
{
    uint16_t len = 0;

    while (hex[0] && hex[1])
    {
        char tmp[3];
        tmp[0] = hex[0];
        tmp[1] = hex[1];
        tmp[2] = '\0';

        out[len++] = (uint8_t)strtol(tmp, NULL, 16);
        hex += 2;
    }
    return len;
} 
/*static uint16_t hex_to_bytes(const char *hex, uint8_t *out)
{
    uint16_t len = 0;

    while (hex[0] && hex[1])
    {
        char tmp[3] = { hex[0], hex[1], '\0' };
        out[len++] = (uint8_t)strtol(tmp, NULL, 16);
        hex += 2;
    }
    return len;
} */

E2Config *load_config(const char *filename, int flag)
{
    static E2Config cfg;   // static storage
    FILE *fp;
    char line[256];

    /* If flag == 1, return already-loaded config */
    if (flag == 1)
    {
        return &cfg;
    }

    /* flag == 0 → read config file */
    memset(&cfg, 0, sizeof(E2Config));

    fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Error: Cannot open config file %s\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), fp))
    {
        /* Remove newline */
        line[strcspn(line, "\n")] = 0;

        char *key   = strtok(line, "=");
        char *value = strtok(NULL, "=");

        if (!key || !value)
            continue;

        if (strcmp(key, "RIC_REQUESTOR_ID") == 0)
            cfg.ricRequestorID = strtol(value, NULL, 10);

        else if (strcmp(key, "RIC_INSTANCE_ID") == 0)
            cfg.ricInstanceID = strtol(value, NULL, 10);

        else if (strcmp(key, "RAN_FUNCTION_ID") == 0)
            cfg.ranFunctionID = strtol(value, NULL, 10);

        else if (strcmp(key, "ADMITTED_ACTION_COUNT") == 0)
            cfg.admittedActionCount = strtol(value, NULL, 10);

        else if (strcmp(key, "ADMITTED_IE_ID") == 0)
            cfg.admittedIEID = strtol(value, NULL, 10);

        else if (strcmp(key, "CRITICALITY") == 0)
            cfg.criticality = strtol(value, NULL, 10);

        else if (strcmp(key, "ACTION_ID") == 0)
            cfg.actionID = strtol(value, NULL, 10);

        /* PLMN (HEX values) */
        else if (strcmp(key, "PLMN0") == 0)
            cfg.plmn[0] = (uint8_t)strtol(value, NULL, 16);

        else if (strcmp(key, "PLMN1") == 0)
            cfg.plmn[1] = (uint8_t)strtol(value, NULL, 16);

        else if (strcmp(key, "PLMN2") == 0)
            cfg.plmn[2] = (uint8_t)strtol(value, NULL, 16);

        /* AMF REGION */
        else if (strcmp(key, "AMF_REGION") == 0)
            cfg.amf_region = (uint8_t)strtol(value, NULL, 16);

        /* AMF SET */
        else if (strcmp(key, "AMF_SET") == 0)
            cfg.amf_set = (uint8_t)strtol(value, NULL, 16);

        /* AMF POINTER */
        else if (strcmp(key, "AMF_POINTER0") == 0)
            cfg.amf_pointer = (uint8_t)strtol(value, NULL, 16);

        /* RIC Action Type */
        else if (strcmp(key, "RIC_ACTION_TYPE") == 0)
            cfg.ricActionType = (uint32_t)strtol(value, NULL, 16);

        /* transactionID */
        //else if (strcmp(key, "TRANSACTION_ID") == 0)
           // cfg.transactionID = (uint32_t)strtol(value, NULL, 16);
        else if (!strcmp(key, "TRANSACTION_ID"))
          cfg.transactionID = strtol(value, NULL, 10);


        /* EVENT TRIGGER */
        else if (!strcmp(key, "EVENT_TRIGGER_DATA"))
            cfg.eventTriggerLen =
                hex_to_bytes(value, cfg.eventTrigger);

        /* ACTION DEFINITION */
        else if (!strcmp(key, "Action_Definition_DATA"))
            cfg.actionTriggerLen =
                hex_to_bytes(value, cfg.actionTrigger);
        
    }

    fclose(fp);
    return &cfg;
}


