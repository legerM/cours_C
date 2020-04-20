/*
 * game_p4.c
 *
 *  Created on: Mar 30, 2020
 *      Author: mickaell
 */

#include "debug.h"
#include "game_p4.h"
#include <stdint.h>
#include <stdio.h>

int8_t matrix[COL_COUNT][LINE_COUNT];
int8_t g_token_top_selector = 4;
int8_t active_player = PLAYER_1;

//type Color RGB
typedef struct {
	int RValue;
	int GValue;
	int BValue;
} Color;

//le rgb des couleurs

const Color red = { 255, 0, 0 };
const Color green = { 0, 255, 0 };
const Color blue = { 0, 0, 255 };
const Color white = { 255, 255, 255 };
const Color purple = { 255, 0, 255 };
const Color yellow = { 255, 255, 0 };
const Color black = { 0, 0, 0 };


//matrice vide
void clear_matrix(void) {

	for (int8_t row = 0; row < LINE_COUNT; row++) {
		for (int8_t col = 0; col < COL_COUNT; col++) {
			matrix[col][row] = EMPTY_SPACE;
		}
	}
}

//initialise la matrice
void gp4_init(void) {

	clear_matrix();
}

//affiche la top line
void top_line_display(void) {
	printf("TOP     : ");
	for (int8_t col = 0; col < COL_COUNT; col++) {
		if (col == g_token_top_selector - 1 ) {
			printf("%d ", active_player);
		} else {
			printf("%d ", EMPTY_SPACE);
		}
	}
	printf("\n");
}

//affiche la matrice
void diplay_matrix(void) {

	for (int8_t row = 0; row < LINE_COUNT; row++) {
		printf("Ligne %d : ", row + 1);
		for (int8_t col = 0; col < COL_COUNT; col++) {
			printf("%d ", matrix[col][row]);
		}
		printf("\n");
	}
}

//affiche le jeu
void gp4_display(void) {
	top_line_display();
	diplay_matrix();

}

//change de joueur
void gp4_next_player(void) {

	if (active_player == PLAYER_1) {
		active_player = PLAYER_2;
		g_token_top_selector = 4;
	} else {
		active_player = PLAYER_1;
		g_token_top_selector = 4;
	}
	while (matrix[g_token_top_selector - 1 ][0] != EMPTY_SPACE) {
		g_token_top_selector += 1;

		if (g_token_top_selector  > (COL_COUNT)) {
			g_token_top_selector = 0;
		}
		else if (g_token_top_selector < 0){
			g_token_top_selector = COL_COUNT;
		}
	}

}

//deplace le jeton du joueur vers la droite et si il arrive en butée de droite se retrouve tout a gauche
void gp4_move_right(void) {
	g_token_top_selector++;
	if (g_token_top_selector > (COL_COUNT )) {
		g_token_top_selector = 0;
	}

}

//deplace le jeton du joueur vers la gauche et si il arrive en butée se retrouve tout a droite
void gp4_move_left(void) {
	g_token_top_selector--;
	if (g_token_top_selector < 0) {
		g_token_top_selector = COL_COUNT ;

	}

}

// valide le coup jouer par le joueur et verifie si il y a un jetons posé avant de validé
void gp4_play_token(void) {
	for (int8_t row = 0; row < LINE_COUNT; row++) {
		if (matrix[g_token_top_selector - 1][row] != 0) {
			matrix[g_token_top_selector - 1][row - 1] = active_player;
		}

	}

	if (matrix[g_token_top_selector - 1][LINE_COUNT - 1] == 0) {
		matrix[g_token_top_selector - 1][LINE_COUNT - 1] = active_player;
	}
	while (matrix[g_token_top_selector - 1][0] != EMPTY_SPACE) {
		g_token_top_selector += 1;

		if (g_token_top_selector > (COL_COUNT)) {
			g_token_top_selector = 0;
		}
		else if (g_token_top_selector < 0){
			g_token_top_selector = COL_COUNT ;
		}
	}

}

void gp4_test_phase(void) {
	gp4_display();
	gp4_play_token();
	printf("\n");
	gp4_display();
	gp4_next_player();
	printf("\n");
	gp4_display();
	gp4_move_left();
	printf("\n");
	gp4_display();
	gp4_move_right();
	printf("\n");
	gp4_display();
	gp4_play_token();
	printf("\n");
	gp4_display();
	gp4_next_player();
	printf("\n");
	gp4_display();
}
