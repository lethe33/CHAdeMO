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
    FAULT_WATTMETER_COMMUNICATION,    // Ctrl B/D ��� Wattmeter comm error
    FAULT_POWERMODULE_COMMUNICATION,  // Ctrl B/D ��� PM comm error
    FAULT_UI_COMMUNICATION,           // Ctrl B/D ��� UI comm error
    FAULT_VEH_COMMUNICATION,          // Ctrl B/D ��� Vehicle comm error

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
    FAULT_CHADEMO_EVENT_A_4,       // 충전기측 ?��?�� (EMG, 충전기에?��, 배터�? ?��?��?�� ?��?��)
    FAULT_CHADEMO_EVENT_A_5,       // 차량�? ?��?�� (VehicleFaultFlag 102.4.x or ChargingSystemError(102.5.2))
    FAULT_CHADEMO_EVENT_A_6,       // 충전�? VehicleChargingEnabled ?�� 0?�� ?��거나, VehicleShiftPosition?�� 1?�� ?���? 발생
    FAULT_CHADEMO_EVENT_A_7,       // 충전�? Pilot ?��?���? 꺼�??�? 발생 (충전?���??��?��)
    FAULT_CHADEMO_EVENT_A_9,       // 충전�? ChargingStopControl(109.5.5)�? 1?��?���? 발생

    // 50-59 CHAdeMO Timeout fault
    FAULT_TIMEOUT_CHADEMO_STATE_C_CAN_RX_CHECK = 50,                          // Sub01 RX ????��?��?��
    FAULT_TIMEOUT_CHADEMO_STATE_C_CAN_TX_CHECK,                               // Sub01 TX ????��?��?��
    FAULT_TIMEOUT_CHADEMO_STATE_C_CHG_EN_CHECK,                               // Sub02 ????��?��?��
    FAULT_INSULATION_TEST_FAIL,                                               // Sub03 ????��?��?��
    FAULT_TIMEOUT_CHADEMO_STATE_D_SUB_03_CHECK = FAULT_INSULATION_TEST_FAIL,  // Sub03 ????��?��?��
    FAULT_TIMEOUT_CHADEMO_STATE_D_BAT_V_CHECK,                                // Sub03 ?�� 차량배터리전?�� 50?��?��?���? VehicleStatus == 0?�� ?��?��?��?��?��?�� Tiemout
    FAULT_TIMEOUT_CHADEMO_STATE_D_CHG_C_CHECK,                                // Sub03 ?�� 차량?���??��류�?? 0?�� 초과?���? ?���? Timeout

    FAULT_PILOT_ON_BEFORE_CAN_RX,  // CHAdeMO error protocol
    FAULT_CONNECTOR_LOCK,               // chademo error protocol

    FAULT_LIST_END
};
void faultProcess(void);