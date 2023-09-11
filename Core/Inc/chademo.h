/*
 * chademo.h
 *
 *  Created on: Sep 7, 2023
 *      Author: User
 */

#ifndef INC_CHADEMO_H_
#define INC_CHADEMO_H_

typedef enum {
    OFF = 0,
    ON
} CHAdeMO_PIN_STATE_T;

void CHAdeMO_Process(void);

#endif /* INC_CHADEMO_H_ */
