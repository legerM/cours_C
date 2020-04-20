/*
 * thread.h
 *
 *  Created on: Apr 9, 2020
 *      Author: mickaell
 */

#ifndef THREAD_H_
#define THREAD_H_
#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4
#define PLAYER_1 5
#define PLAYER_2 6
#define PLAYER_COLOR_1 red
#define PLAYER_COLOR_2 green
#define BACKGROUND black
#define TAB_SIZE 6
#include"leds_control.h"
#include "FIFO.h"


void *thread_send(void *arg);
void *thread_read(void *arg);
void *thread_app(void *arg);
void compute_message(struct Element* message, pos_token_played_t* data);
void setledmatrix(struct Element *message);


#endif /* THREAD_H_ */
