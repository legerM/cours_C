/*
 * thread.c
 *
 *  Created on: Apr 9, 2020
 *      Author: mickaell
 */

#include<stdio.h>
#include <stdint.h>
#include <pthread.h>
#include<unistd.h>
#include"leds_control.h"
#include "FIFO.h"
#include <semaphore.h>
#include "thread.h"
#include "game_p4.h"


char recep_tab[5];


//Color matrix[COL_COUNT][LINE_COUNT];
Color matrix_led[COL_COUNT][LINE_COUNT + 1 ];
Color actual_display[COL_COUNT][LINE_COUNT + 1 ];
int8_t active_player;

//le rgb des couleurs
#pragma GCC diagnostic ignored "-Wunused-variable"
const Color red = { 255, 0, 0 };
const Color green = { 0, 255, 0 };
const Color blue = { 0, 0, 255 };
const Color white = { 255, 255, 255 };
const Color purple = { 255, 0, 255 };
const Color yellow = { 255, 255, 0 };
const Color black = { 0, 0, 0 };
#pragma GCC diagnostic warning "-Wunused-variable"

void *thread_read(void *arg) {

	while (1) {
		struct Element command;
		if (readbutton(recep_tab, 5) == LCRC_OK) {
			printf("%d %d %d %d \n", recep_tab[0], recep_tab[1], recep_tab[2],
					recep_tab[3]);
			if (recep_tab[0] == 'p') {
				if (recep_tab[1] == '1') {
					command.data.value[0] = PLAYER_1;
				} else if (recep_tab[1] == '2') {
					command.data.value[0] = PLAYER_2;
				}
				if (recep_tab[3] == 100) {

					if (recep_tab[2] == 'd') {
						command.data.value[1] = DOWN;
					}
					if (recep_tab[2] == 'u') {
						command.data.value[1] = UP;
					}
					if (recep_tab[2] == 'r') {
						command.data.value[1] = RIGHT;
					}
					if (recep_tab[2] == 'l') {
						command.data.value[1] = LEFT;
					}
					send_message(QUEUE_READ, &command, SIZEOFMESSAGE);
				}

			}
		}
	}

	return NULL;

}

void *thread_app(void *arg) {
	//	struct Element nb_value;
	//	nb_value.data.value[1]=0;
	active_player = 0;
	struct Element receive_value;
	struct Element send_value;
	pos_token_played_t played_token;
	while (1) {

		if (receive_message(QUEUE_READ, &receive_value, SIZEOFMESSAGE)) {
			//			printf("app %d %d \n", receive_value.data.value[0],
			//					receive_value.data.value[1]);
			if (receive_value.data.value[0] == active_player) {

				if (receive_value.data.value[1] == DOWN) {
					played_token = gp4_play_token();
					compute_message(&send_value, &played_token);
					send_message(QUEUE_SEND, &send_value, SIZEOFMESSAGE);
					played_token=gp4_next_player();
					if (active_player == PLAYER_1) {
						send_value.data.token.color = PLAYER_COLOR_1;
					}
					else if (active_player == PLAYER_2) {
						send_value.data.token.color = PLAYER_COLOR_2;
					}
				}

				if (receive_value.data.value[1] == RIGHT) {
					played_token = gp4_move_right();

				}
				if (receive_value.data.value[1] == LEFT) {
					played_token = gp4_move_left();

				}

			}

			if (active_player == 0) {

				gp4_init();
				gp4_display();
				active_player = PLAYER_1;
				played_token.beg_position.c = 0;
				played_token.beg_position.l = 0;
				played_token.end_position.l = 0;
				played_token.end_position.c = 3;
				send_value.data.token.color = PLAYER_COLOR_1;
			}
			gp4_display();
			compute_message(&send_value, &played_token);
			send_message(QUEUE_SEND, &send_value, SIZEOFMESSAGE);
		}

		//decompte(&receive_value, &nb_value);
	}

}

void *thread_send(void *arg) {
	struct Element value_compt;
	while (1) {
		if (receive_message(QUEUE_SEND, &value_compt, SIZEOFMESSAGE)) {
			printf(" display b %d%d  e %d%d \n",
					value_compt.data.token.position.beg_position.c,
					value_compt.data.token.position.beg_position.l,
					value_compt.data.token.position.end_position.c,
					value_compt.data.token.position.end_position.l);
			//			set_number(value_compt.data.value[1]);
			setledmatrix(&value_compt);

			for (int row = 0; row < 7; row++){
				for (int col = 0; col < 7; col++){
					if ((matrix_led[row][col].RValue == actual_display[row][col].RValue)
							&& (matrix_led[row][col].GValue == actual_display[row][col].GValue)
									&& (matrix_led[row][col].BValue == actual_display[row][col].BValue)) {
					} else {
						setLedColor((row + 1 ), (col + 1 ),
								matrix_led[row][col].RValue,
								matrix_led[row][col].GValue,
								matrix_led[row][col].BValue);
						actual_display[row ][col] = matrix_led[row ][col];
					}
				}
			}

		}
	}
}

void compute_message(struct Element* message, pos_token_played_t* data) {
	message->data.token.position.beg_position.l = data->beg_position.l;
	message->data.token.position.beg_position.c = data->beg_position.c;
	message->data.token.position.end_position.l = data->end_position.l;
	message->data.token.position.end_position.c = data->end_position.c;
}
//// pour le puissance 4

void setledmatrix(struct Element *message) {
	int beg_row = message->data.token.position.beg_position.l;
	int beg_col = message->data.token.position.beg_position.c;
	int end_row = message->data.token.position.end_position.l;
	int end_col = message->data.token.position.end_position.c;
	if (beg_row == 10 && beg_col == 10) {
	} else {
		matrix_led[beg_row ][beg_col] = BACKGROUND;
	}
	matrix_led[end_row ][end_col] = message->data.token.color;
}
