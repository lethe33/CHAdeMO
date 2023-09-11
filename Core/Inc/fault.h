/*
 * fault.h
 *
 *  Created on: Sep 6, 2023
 *      Author: User
 */

#include "main.h"
enum {
    // 0-9 comm fault
    FAULT_NONE = 0,
    FAULT_WATTMETER_COMMUNICATION,    // Ctrl B/D °Á°Ê Wattmeter comm error
    FAULT_POWERMODULE_COMMUNICATION,  // Ctrl B/D °Á°Ê PM comm error
    FAULT_UI_COMMUNICATION,           // Ctrl B/D °Á°Ê UI comm error
    FAULT_VEH_COMMUNICATION,          // Ctrl B/D °Á°Ê Vehicle comm error

    // 10-19 electronic fault
    FAULT_INPUT_UNDER_VOLTAGE = 10,
    FAULT_INPUT_OVER_VOLTAGE,
    FAULT_OUTPUT_OVER_VOLTAGE,
    FAULT_OUTPUT_OVER_CURRENT,
    FAULT_OVER_VOLTAGE_MAXIMIUM_BATTERY, // Veh side error Maximum battery
    FAULT_INPUT_VOLTAGE_TRIP,
    FAULT_DC_GROUND,
    FAULT_FUSE,

    // 20-29 temp fault
    FAULT_INTEGRITY_TEST_ERROR_COUPLER_TEMP_SENSOR = 20,
    FAULT_COUPLER_OVER_TEMPERATURE_IDLE,
    FAULT_COUPLER_OVER_TEMPERATURE_CHARGING,
    FAULT_FULL_POWER_SET,


    // 30-39 welding fault
    FAULT_MC1_WELDING = 30,
    FAULT_MC2_WELDING,
    FAULT_RELAY_LEAD_WELDING,
    FAULT_RELAY_FOLLOW_WELDING,
    FAULT_RELAY_MERGE_WELDING,
    FAULT_RELAY_ALL_ON_WELDING,

    // 40-49 CHAdeMO Event occur (not fault)
    FAULT_CHADEMO_EVENT_A_2 = 40,  // VehicleShiftPosition == 1
    FAULT_CHADEMO_EVENT_A_3,       // NormalStopRequestBeforeCharging
    FAULT_CHADEMO_EVENT_A_4,       // Ï∂©Ï†ÑÍ∏∞Ï∏° ?óê?ü¨ (EMG, Ï∂©Ï†ÑÍ∏∞Ïóê?ü¨, Î∞∞ÌÑ∞Î¶? ?†Å?ï©?Ñ± ?óê?ü¨)
    FAULT_CHADEMO_EVENT_A_5,       // Ï∞®ÎüâÏ∏? ?óê?ü¨ (VehicleFaultFlag 102.4.x or ChargingSystemError(102.5.2))
    FAULT_CHADEMO_EVENT_A_6,       // Ï∂©Ï†ÑÏ§? VehicleChargingEnabled ?ù¥ 0?ù¥ ?êòÍ±∞ÎÇò, VehicleShiftPosition?ù¥ 1?ù¥ ?êòÎ©? Î∞úÏÉù
    FAULT_CHADEMO_EVENT_A_7,       // Ï∂©Ï†ÑÏ§? Pilot ?ã†?ò∏Í∞? Í∫ºÏ??Î©? Î∞úÏÉù (Ï∂©Ï†Ñ?óàÍ∞??ã†?ò∏)
    FAULT_CHADEMO_EVENT_A_9,       // Ï∂©Ï†ÑÏ§? ChargingStopControl(109.5.5)Í∞? 1?ù¥?êòÎ©? Î∞úÏÉù

    // 50-59 CHAdeMO Timeout fault
    FAULT_TIMEOUT_CHADEMO_STATE_C_CAN_RX_CHECK = 50,                          // Sub01 RX ????ûÑ?ïÑ?õÉ
    FAULT_TIMEOUT_CHADEMO_STATE_C_CAN_TX_CHECK,                               // Sub01 TX ????ûÑ?ïÑ?õÉ
    FAULT_TIMEOUT_CHADEMO_STATE_C_CHG_EN_CHECK,                               // Sub02 ????ûÑ?ïÑ?õÉ
    FAULT_INSULATION_TEST_FAIL,                                               // Sub03 ????ûÑ?ïÑ?õÉ
    FAULT_TIMEOUT_CHADEMO_STATE_D_SUB_03_CHECK = FAULT_INSULATION_TEST_FAIL,  // Sub03 ????ûÑ?ïÑ?õÉ
    FAULT_TIMEOUT_CHADEMO_STATE_D_BAT_V_CHECK,                                // Sub03 ?õÑ Ï∞®ÎüâÎ∞∞ÌÑ∞Î¶¨Ï†Ñ?ïï 50?ù¥?ÉÅ?ù¥Í≥? VehicleStatus == 0?ù¥ ?ïÑ?ãå?ÉÅ?Éú?óê?Ñú Tiemout
    FAULT_TIMEOUT_CHADEMO_STATE_D_CHG_C_CHECK,                                // Sub03 ?õÑ Ï∞®Îüâ?öîÏ≤??†ÑÎ•òÍ?? 0?ùÑ Ï¥àÍ≥º?ïòÏß? ?ïäÍ≥? Timeout

    FAULT_PILOT_ON_BEFORE_CAN_RX,  // CHAdeMO error protocol
    FAULT_CONNECTOR_LOCK,               // chademo error protocol

    FAULT_LIST_END
};
void faultProcess(void);