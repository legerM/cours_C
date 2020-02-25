

#include<stdio.h>
#include<string.h>





_Bool is_vowel(char text_letter)
{


	char vowel[]={'a','e','i','o','u','y','A','E','I','O','U','Y','�','�','�','�','�','�','�','�','�'};

	for(int j=0;vowel[j]!='\0';j++){
		if(text_letter==vowel[j]){
			return 1;
		}
	}
	return 0;
}
_Bool is_cons(char text_letter){
	char Consonant[] = {'b','c','�','d','f','g','h','j','k','l','m',
			'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z',
			'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M',
			'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Z'};

	for (int k=0;Consonant[k]!='\0';k++)
	{

		if (text_letter == Consonant[k]){
			return 1;
		}
	}
	return 0;
}

int main(int argc, char *argv[]){
	float pct_vowel=0;
	float pct_cons=0;
	int nb_letter=0;
	int nb_vowel=0;
	int nb_cons=0;
	char text[128];
	int i=0;
	FILE* fichier;
	fichier=fopen("/home/mickaell/Atollic/TrueSTUDIO/STM32_workspace_9.3/61_exo/Debug/src/51_long_text.txt","r");


	while(fgets(text,128,fichier)!= NULL){
		i=0;
		while(text[i]!='\0'){
			if (is_vowel(text[i])){
				nb_vowel+=1;
			}

			else if(is_cons(text[i])){
				nb_cons+=1;
			}
		i++;
		}

	}


	nb_letter = nb_vowel + nb_cons;
	pct_vowel =(nb_vowel*100.00)/nb_letter;
	pct_cons=100.00 - pct_vowel;
	printf("il y a %d voyelles \n" ,nb_vowel);
	printf("il y a %d Consonnes \n", nb_cons);
	printf("il y a un total de %d lettres \n", nb_letter);
	printf("il y a un total de %.2f %% voyelles et de %.2f %% de consonnes\n",pct_vowel ,pct_cons);




	fclose(fichier);
	return 0;
}