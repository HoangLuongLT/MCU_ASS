/*
 * global.h
 *
 *  Created on: Dec 13, 2022
 *      Author: Luong
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define AUTO_RED_GREEN 1
#define AUTO_RED_YELLOW 2
#define AUTO_GREEN_RED 3
#define AUTO_YELLOW_RED 4

extern int status;
extern int status_ped;
extern int status_buzzer;
extern int numberCounter;

extern int led;

extern int printNumber;

int timeOutMan;

extern int dutyCycle;

extern int redDuration;
extern int greenDuration;
extern int yellowDuration;

#define MAN_RED		12
#define MAN_GREEN	13
#define MAN_YELLOW 	14

#define UNABLE		20
#define PED_STOP	21
#define PED_GO		22

#define BUZ_ON		30
#define BUZ_OFF		31

#endif /* INC_GLOBAL_H_ */
