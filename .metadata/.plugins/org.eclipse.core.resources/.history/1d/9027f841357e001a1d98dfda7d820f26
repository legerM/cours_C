/*
 * thread.h
 *
 *  Created on: Apr 9, 2020
 *      Author: mickaell
 */

#ifndef THREAD_H_
#define THREAD_H_
#define INC_VALUE 10
#define DEC_VALUE 15
#define PLAYER_COLOR red
#define BACKGROUND black
#define TAB_SIZE 7
#include"leds_control.h"
#include "FIFO.h"
void *thread_send(void *arg);
void *thread_read(void *arg);
void *thread_app(void *arg);
void set_all_black(void);
void set_number(int compteur);
void init_matrix(void);

typedef struct{
	int RValue;
	int GValue;
	int BValue;
}Color;








#endif /* THREAD_H_ */
