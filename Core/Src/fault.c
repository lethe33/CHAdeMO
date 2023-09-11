/*
 * fault.c
 *
 *  Created on: Sep 6, 2023
 *      Author: User
 */

#include "fault.h"

#include "gpio.h"
#include "iwdg.h"
#include "main.h"
#include "tim.h"

uint8_t faultCode[ID_LIST_END];
uint8_t FaultFlag[ID_LIST_END];

void setFaultCode(uint8_t CH, uint16_t code_no) {
    faultCode[CH] = code_no;
}
uint16_t getFaultCode(uint8_t CH, uint16_t array_no) {
    return faultCode[CH];
}
void faultProcess(void) {
    for (uint8_t CH = ID_LEFT; CH < ID_LIST_END; CH++) {
        if (FaultFlag[CH] == 0) {
            if (faultCode[CH] != 0) {
                FaultFlag[CH] = 1;
                setTimerSEC(TIME_SEC_FAULT_RESET + (CH - 1), 10);
                // fw ¡æ ui code
            }
        } else {
            if (getTimerSEC(TIME_SEC_FAULT_RESET + (CH - 1)) == 0) {
                FaultFlag[CH] = 0;
            }
            /*
            1. CAN init
            2. LED init
            3. fw ¡æ ui info (fault 0, ready 1)
            */
        }
    }
}
