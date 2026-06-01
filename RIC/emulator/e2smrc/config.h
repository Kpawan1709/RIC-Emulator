#ifndef CONFIG_H
#define CONFIG_H
#include <stdint.h>

/**typedef struct {
    int ricRequestorID;
    int ricInstanceID;
    int ranFunctionID;
    int admittedActionCount;
    int admittedIEID;
    int criticality;
    int actionID;
} E2Config; **/


typedef struct
{
    int ricRequestorID;
    int ricInstanceID;
    int ranFunctionID;
    int admittedActionCount;
    int admittedIEID;
    int criticality;
    int actionID;

   // uint32_t ric_requestor_id;
    //uint32_t ric_instance_id;

   // uint32_t ran_function_id;

    /* PLMN */
    uint8_t  plmn[3];

    /* GUAMI */
    uint8_t  amf_region;
    uint16_t amf_set;
    uint8_t  amf_pointer;

    /* Event / Action */
    uint32_t event_trigger_id;
    uint32_t interface_proc_id_1;
    uint32_t interface_proc_id_2;

    //uint32_t ric_action_id;
    uint32_t ricActionType;
    uint32_t ricSubsequentActionType;
    uint32_t ran_param_id_fmt1;
    uint32_t ran_param_id_fmt3;

    /* Event Trigger */
    uint8_t  eventTrigger[256];
    uint16_t eventTriggerLen;

    /* Action Trigger */
    uint8_t  actionTrigger[256];
    uint16_t actionTriggerLen;

    /*transactionID*/
    uint32_t transactionID;


} E2Config;

//void load_config(const char *filename, E2Config *cfg);
//E2Config *load_config(const char *filename, int flag);
/**
 * Load configuration from file or return cached config
 * @param filename Config file path (used only when flag == 0)
 * @param flag 0 = load from file, 1 = return cached config pointer
 * @return Pointer to E2Config structure (static storage)
*/
E2Config *load_config(const char *filename, int flag);
//void load_config(const char *filename, E2Config *cfg);
//int load_config(const char *filename, E2Config *cfg, int flag);

#endif

