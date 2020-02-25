

#include<stdio.h>
#include<string.h>



// a terminer il me reste a corriger le fait qu'il ne prend pas en compte les accents et les nombres , remplacer le 32 par de larithmetique sur les lettres reprendre la table ascii
int main(int argc, char *argv[]){
	char text[128];
	int i=0;
	int ascii= 32;
	FILE* fichier=NULL;
	FILE* fichier2=NULL;
	fichier=fopen("/home/mickaell/Atollic/TrueSTUDIO/STM32_workspace_9.3/61_exo/Debug/src/51_long_text.txt","r");
	fichier2=fopen("/home/mickaell/Atollic/TrueSTUDIO/STM32_workspace_9.3/63_toupper/Debug/src/new_51_long_text.txt","w+");

	while(fgets(text,128,fichier)!= NULL){
		i=0;
		while(text[i]!='\0'){
			if (text[i]>= 'a' && text[i]<= 'z'){
				text[i]= text[i] - ascii ;
				fputc(text[i], fichier2);
			}
		i++;
		}

	}





	fclose(fichier);
	return 0;
}
