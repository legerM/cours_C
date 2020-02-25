#include <stdio.h>



int weight = 19 ;
int width = 50 ;
int length = 20;
int height = 20 ;


int check_number_error() {
	int cpt_error = 0;

	if (width != 50){
		cpt_error += 1;
	}

	if (length != 20){
		cpt_error +=1;
	}

	if (height != 20) {
		cpt_error +=1;
	}
	return cpt_error;
}

int main(int argc , char* argv []) {
	int cpt =0;
	cpt=check_number_error();
	if (weight == 19){
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

