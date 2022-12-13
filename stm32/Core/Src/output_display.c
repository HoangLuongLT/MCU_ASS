/*
 * output_display.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Luong
 */

#include "output_display.h"
#include "main.h"

int ledR=1;
int ledY=1;
int ledG=1;

void turnOnRed1(){
	HAL_GPIO_WritePin(TL1_1_GPIO_Port, TL1_1_Pin, 1);
	HAL_GPIO_WritePin(TL1_2_GPIO_Port, TL1_2_Pin, 0);
}
void turnOnGreen1(){
	HAL_GPIO_WritePin(TL1_1_GPIO_Port, TL1_1_Pin, 0);
	HAL_GPIO_WritePin(TL1_2_GPIO_Port, TL1_2_Pin, 1);
}
void turnOnYellow1(){
	HAL_GPIO_WritePin(TL1_1_GPIO_Port, TL1_1_Pin, 1);
	HAL_GPIO_WritePin(TL1_2_GPIO_Port, TL1_2_Pin, 1);
}
void turnOff1(){
	HAL_GPIO_WritePin(TL1_1_GPIO_Port, TL1_1_Pin, 0);
	HAL_GPIO_WritePin(TL1_2_GPIO_Port, TL1_2_Pin, 0);
}

void turnOnRed2(){
	HAL_GPIO_WritePin(TL2_1_GPIO_Port, TL2_1_Pin, 0);
	HAL_GPIO_WritePin(TL2_2_GPIO_Port, TL2_2_Pin, 1);
}
void turnOnGreen2(){
	HAL_GPIO_WritePin(TL2_1_GPIO_Port, TL2_1_Pin, 1);
	HAL_GPIO_WritePin(TL2_2_GPIO_Port, TL2_2_Pin, 0);
}
void turnOnYellow2(){
	HAL_GPIO_WritePin(TL2_1_GPIO_Port, TL2_1_Pin, 1);
	HAL_GPIO_WritePin(TL2_2_GPIO_Port, TL2_2_Pin, 1);
}
void turnOff2(){
	HAL_GPIO_WritePin(TL2_1_GPIO_Port, TL2_1_Pin, 0);
	HAL_GPIO_WritePin(TL2_2_GPIO_Port, TL2_2_Pin, 0);
}

void blinkAllRed(){
	if(ledR==1){
		turnOnRed1();
		turnOnRed2();
	}
	else{
		turnOff1();
		turnOff2();
	}
	ledR=!ledR;
}
void blinkAllGreen(){
	if(ledG==1){
		turnOnGreen1();
		turnOnGreen2();
	}
	else{
		turnOff1();
		turnOff2();
	}
	ledG=!ledG;
}
void blinkAllYellow(){
	if(ledY==1){
		turnOnYellow1();
		turnOnYellow2();
	}
	else{
		turnOff1();
		turnOff2();
	}
	ledY=!ledY;
}
void pedStop(){
	HAL_GPIO_WritePin(PL_1_GPIO_Port, PL_1_Pin, 1);
	HAL_GPIO_WritePin(PL_2_GPIO_Port, PL_2_Pin, 0);
}
void pedGo(){
	HAL_GPIO_WritePin(PL_1_GPIO_Port, PL_1_Pin, 0);
	HAL_GPIO_WritePin(PL_2_GPIO_Port, PL_2_Pin, 1);

}
void pedOff(){
	HAL_GPIO_WritePin(PL_1_GPIO_Port, PL_1_Pin, 0);
	HAL_GPIO_WritePin(PL_2_GPIO_Port, PL_2_Pin, 0);
}

void blinkPA51s(){
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}
