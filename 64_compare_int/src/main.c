

#include<stdio.h>

int main(void){
	int entier1;
	int entier2;

	printf("Veuillez entrer un entier\n");
	scanf("%d",&entier1);
	printf("veuillez entrer un second entier\n");
	scanf("%d",&entier2);

	if (entier1 == entier2){
		printf("les entiers sont les mêmes\n");
		return 0;

	}

	else{
		printf("les entiers ne sont pas les mêmes\n");
		return 1;
	}



	return 0;
}
