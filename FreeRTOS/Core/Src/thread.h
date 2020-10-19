/*
 * thread.h
 *
 *  Created on: Apr 24, 2020
 *      Author: mickaell
 */
#include "local_leds.h"
#include <unistd.h>

#ifndef SRC_THREAD_H_
#define SRC_THREAD_H_

void thread_red_led(void * arg);
void thread_blue_led(void * arg);
void thread_green_led(void * arg);
void thread_serial(void * arg);


#endif /* SRC_THREAD_H_ */
