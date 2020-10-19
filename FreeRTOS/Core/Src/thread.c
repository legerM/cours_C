/*
 * thread.c
 *
 *  Created on: Apr 24, 2020
 *      Author: mickaell
 */
#include "thread.h"
#include "cmsis_os2.h"
#include"local_button.h"
#include "send_to_serial.h"
osMessageQueueId_t sendToLog;
osSemaphoreId_t semaphore_led;
void thread_red_led(void * arg){
	while(1){
		LedRedOn();
		osDelay(400);
		LedRedOff();
		osDelay(400);
	}

}

void thread_blue_led(void * arg){
	char msg[12] = "hello,world";
	while(1){

		WaitForLocalButtonReleased();
		LedBlueOn();
		osDelay(400);
		LedBlueOff();
		osDelay(400);
		osSemaphoreRelease (semaphore_led);
		osMessageQueuePut(sendToLog,&msg,0,osWaitForever);
	}



}

void thread_green_led(void * arg){
	while(1){

		osSemaphoreAcquire (semaphore_led,osWaitForever);
		LedGreenOn();
		osDelay(400);
		LedGreenOff();

	}


}

void thread_serial(void * arg){
	char msg[12];
	while(1){
		osMessageQueueGet(sendToLog,&(msg),NULL,osWaitForever);
		sendToSerial(msg,12);

	}

}


