/*
 * fsm_auto.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Luong
 */

#include "fsm_auto.h"
#include "global.h"
#include "output_display.h"
#include "software_timer.h"
#include "button.h"
#include "main.h"

void fsm_auto_processing(){
	switch (status) {
		case AUTO_RED_GREEN:
			//auto
			if(timer0_flag==1){
				setTimer0(1000);

				printNumber=redDuration-numberCounter;
				UART_Print();


				if(++numberCounter == greenDuration){
					status=	AUTO_RED_YELLOW;
				}

//				turnOffAll();
//				turnOnOnlyRed(0);//ROAD 0
//				turnOnOnlyGreen(1);//ROAD 1
				turnOnRed1();
				turnOnGreen2();
			}
			//button 1
			if(isButtonPress(0)){
				status = MAN_RED;
				timer0_flag=1;//Reuse next status
				setTimer1(timeOutMan);//Timeout 5s
			}
			//button 4
			if(isButtonPress(3)){
				status_ped=PED_GO;
				setTimer1(4*redDuration*1000);//2 cycle
			}
			break;
		case AUTO_RED_YELLOW:
			if(timer0_flag==1){
				setTimer0(1000);

				printNumber=redDuration-numberCounter;
				UART_Print();

				if(++numberCounter == redDuration){
					status=	AUTO_GREEN_RED;
				}

//				turnOffAll();
//				turnOnOnlyRed(0);
//				turnOnOnlyYellow(1);
				turnOnRed1();
				turnOnYellow2();
			}
			//button 1
			if(isButtonPress(0)){
				status = MAN_RED;
				timer0_flag=1;//Reuse next status
				setTimer1(timeOutMan);//Timeout 5s
			}
			//button 4
			if(isButtonPress(3)){
				status_ped=PED_GO;
				setTimer1(4*redDuration*1000);//2 cycle
			}
			break;
		case AUTO_GREEN_RED:
			if(timer0_flag==1){
				setTimer0(1000);

				printNumber=2*redDuration-numberCounter;
				UART_Print();

				if(++numberCounter == (redDuration+greenDuration)){
					status=	AUTO_YELLOW_RED;
				}

//				turnOffAll();
//				turnOnOnlyGreen(0);
//				turnOnOnlyRed(1);
				turnOnGreen1();
				turnOnRed2();
			}
			//button 1
			if(isButtonPress(0)){
				status = MAN_RED;
				timer0_flag=1;//Reuse next status
				setTimer1(timeOutMan);//Timeout 5s
			}
			//button 4
			if(isButtonPress(3)){
				status_ped=PED_STOP;
				setTimer1(4*redDuration*1000);//2 cycle
			}
			break;
		case AUTO_YELLOW_RED:
			if(timer0_flag==1){
				setTimer0(1000);

				printNumber=2*redDuration-numberCounter;
				UART_Print();

				if(++numberCounter == (2*redDuration)){
					status=	AUTO_RED_GREEN;
					numberCounter=0;
				}

//				turnOffAll();
//				turnOnOnlyYellow(0);
//				turnOnOnlyRed(1);
				turnOnYellow1();
				turnOnRed2();
			}
			//button 1
			if(isButtonPress(0)){
				status = MAN_RED;
				timer0_flag=1;//Reuse next status
				setTimer1(timeOutMan);//Timeout 5s
			}
			//button 4
			if(isButtonPress(3)){
				status_ped=PED_STOP;
				setTimer1(4*redDuration*1000);//2 cycle
			}
			break;
		default:
			break;
	}
}

