#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ref_weight = 19000;
int ref_width = 200;
int ref_length = 500;
int ref_height = 200;
int value_weight;
int value_width;
int value_length;
int value_height;
int weight_input;
int width_input;
int length_input;
int height_input;
int tolerance;


bool in_range(value, ref, tolerance) {
	int val_min;
	int val_max;
	val_min = ref - (ref * tolerance / 100);
	val_max = ref + (ref * tolerance / 100);
	if ((value <= val_max) && (value >= val_min)) {
		return true;
	}
	else {
		return false;
	}
}
int check_number_error() {
	int cpt_error = 0;
	if (!in_range(value_width, ref_width, tolerance )) {
		cpt_error += 1;
	}
	if (!in_range(value_length, ref_length, tolerance )){
		cpt_error +=1;
	}
	if (!in_range(value_height, ref_height, tolerance )) {
		cpt_error +=1;
	}
	return cpt_error;
}
int main(int argc , char* argv []) {



	printf("Saisissez une valeur pour le poids: ");
	weight_input = scanf("%d", &value_weight);
	printf("Saisissez une valeur pour la longueur: ");
	width_input = scanf("%d", &value_width);
	printf("Saisissez une valeur pour la largeur: ");
	length_input = scanf("%d", &value_length);
	printf("Saisissez une valeur pour la hauteur: ");
	height_input = scanf("%d", &value_height);
	int cpt =0;
	cpt=check_number_error();
	if (value_weight == 19){
		if (cpt <= 1){
			printf("categorie A");
		}
		else {
			printf("categorie B");
		}
	}
	else {
		if (cpt == 0 ){
			printf("categorie B");
		}
		else {
			printf("categorie C");
		}
	}
	return 0;
}
