/*
 * fsm_manual.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Luong
 */

#include "fsm_manual.h"
#include "global.h"
#include "output_display.h"
#include "software_timer.h"
#include "button.h"

int timeOut = 10000;

void fsm_manual_processing(){
	switch (status) {
		case MAN_RED:
			//button 1
			if(isButtonPress(0)){
				setTimer1(timeOut);
				status = MAN_GREEN;
				timer0_flag=1;
			}
			//button 2
			if(isButtonPress(1)){
				setTimer1(timeOut);
				redDuration++;
			}
			//button 3
			if(isButtonPress(2)){
				setTimer1(timeOut);
				redDuration--;
			}
			//Time out 10s
			if(timer1_flag==1){
				status = AUTO_RED_GREEN;
				numberCounter=0;
				timer0_flag=1;
			}
			//TODO
			if(timer0_flag==1){
				setTimer0(500);
//				blinkAllRedLed();
				blinkAllRed();
			}
			break;
		case MAN_GREEN:
			//button 1
			if(isButtonPress(0)){
				setTimer1(timeOut);
				status = MAN_YELLOW;
				timer0_flag=1;
			}
			//button 2
			if(isButtonPress(1)){
				setTimer1(timeOut);
				greenDuration++;
			}
			//button 3
			if(isButtonPress(2)){
				setTimer1(timeOut);
				greenDuration--;
			}
			//Time out 10s
			if(timer1_flag==1){
				status = AUTO_RED_GREEN;
				numberCounter=0;
				timer0_flag=1;
			}
			//TODO
			if(timer0_flag==1){
				setTimer0(500);
//				blinkAllGreenLed();
				blinkAllGreen();
			}
			break;
		case MAN_YELLOW:
			//button 1
			if(isButtonPress(0)){
				timer1_flag=1;
				status = AUTO_RED_GREEN;
				numberCounter=0;
				timer0_flag=1;
			}
			//button 2
			if(isButtonPress(1)){
				setTimer1(timeOut);
				yellowDuration++;
			}
			//button 3
			if(isButtonPress(2)){
				setTimer1(timeOut);
				yellowDuration--;
			}
			//Time out 10s
			if(timer1_flag==1){
				status = AUTO_RED_GREEN;
				numberCounter=0;
				timer0_flag=1;
			}
			//TODO
			if(timer0_flag==1){
				setTimer0(500);
//				blinkAllYellowLed();
				blinkAllYellow();
			}
			break;
		default:
			break;
	}
}

