/*
 * driverFunc.h
 *
 *  Created on: Nov 18, 2020
 *      Author: mickaell
 */

#ifndef SRC_DRIVERFUNC_H_
#define SRC_DRIVERFUNC_H_
#include "cmsis_os.h"
#define TRUE 1
#define FALSE 0
#define HIGH_TIME_0 2
#define LOW_TIME_0 8
#define HIGH_TIME_1 10
#define LOW_TIME_1 4
#define MATRIX_ROW 8
#define MATRIX_COL 8


uint8_t translate_ASCII_To_int(char* colorValue);
int decode_message_for_send_frame(char* message_update_LED);
void update_matrix(char * message);
void init_matrix();
void set_chossen_LED();

#endif /* SRC_DRIVERFUNC_H_ */