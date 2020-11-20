#include "uart7_com.h"
#include "main.h"
#include "cmsis_os.h"

extern UART_HandleTypeDef huart7;
extern osMessageQueueId_t msgtosendHandle;
extern osMessageQueueId_t msgtoreceiveHandle;




void uart_com(void *argument)
{
	for(;;)
	{
		unsigned char buffer[MAX_BUFFER_SIZE] = { 0 };
		if (osMessageQueueGetCount(msgtosendHandle) != 0){
			osMessageQueueGet(msgtosendHandle, &buffer, 0, osWaitForever);
			HAL_UART_Transmit(&huart7, buffer, MAX_BUFFER_SIZE, 10);
		}

		if (HAL_UART_Receive(&huart7, buffer, MAX_BUFFER_SIZE, 10) == HAL_OK){
			osMessageQueuePut(msgtoreceiveHandle, &buffer, 0, osWaitForever);
		}
	}
}
