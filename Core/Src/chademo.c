/*
 * chademo.c
 *
 *  Created on: Sep 7, 2023
 *      Author: User
 */

#include "chademo.h"

#include <stdio.h>

#include "gpio.h"
#include "iwdg.h"
#include "koolcharge.h"
#include "main.h"
#include "tim.h"
#include "usart.h"

// can init

// value declaration
CHAdeMO_PIN_STATE_T CHAdeMO_Output_D1;
CHAdeMO_PIN_STATE_T CHAdeMO_Output_D2;
CHAdeMO_PIN_STATE_T CHAdeMO_Output_SOL;

CHAdeMO_PIN_STATE_T CHAdeMO_Input_PILOT;  // PILOT, opto-Coupler(j)
CHAdeMO_PIN_STATE_T CHAdeMO_Input_SOL;    // LATCH INPUT
CHAdeMO_PIN_STATE_T CHAdeMO_Input_DCGF;

CHAdeMO_PIN_STATE_T HighCurrentControlFlag;
CHAdeMO_PIN_STATE_T HighVoltageControlFlag;
CHAdeMO_PIN_STATE_T DynamicControlFlag;

// function define
uint16_t get_ChargingCurrentRequest(void) {
    uint16_t res1 = 1;
    return res1;
}

void CHAdeMO_Select_ChargeMode(void) {
    CHAdeMO_Output_D1 = OFF;
}
void CHAdeMO_Monitoring(void) {}
void CHAdeMO_Status_Refresh(void) {}
void CHAdeMO_Sub_01_Process(void) {}
void CHAdeMO_Sub_02_Process(void) {}
void CHAdeMO_Sub_03_Process(void) {}
void CHAdeMO_Sub_04_Process(void) {}
void CHAdeMO_Sub_05_Process(void) {}
void CHAdeMO_Sub_06_Process(void) {}
void CHAdeMO_StateProcess(void) {}

// state machine
void CHAdeMO_Process(void) {
    CHAdeMO_Select_ChargeMode();
    CHAdeMO_Monitoring();
    CHAdeMO_Status_Refresh();
    CHAdeMO_Sub_01_Process();
    CHAdeMO_Sub_02_Process();
    CHAdeMO_Sub_03_Process();
    CHAdeMO_Sub_04_Process();
    CHAdeMO_Sub_05_Process();
    CHAdeMO_Sub_06_Process();
    CHAdeMO_StateProcess();
}
