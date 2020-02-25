

#include<stdio.h>
#include<string.h>
char s1[]="toto";
char s2[]="totota";

int comparer(const char s1[],const char s2[]){
	for (int i=0; ((s1[i]!='\0') || (s2[i]!= '\0')); i++){

		if(s1[i]==s2[i]){
			continue ;
		}
		else if (s1[i] > s2[i]){
			return 1;
		}
		else {
			return -1;
		}
	}
return 0;

}


int main(int argc, char *argv[]){
	int compare = comparer(s1, s2);
	if (compare == 0){
		printf("le mot %s est egal à %s \n", s1,s2);
	}
	else if (compare == 1){
		printf("le mot %s est inferieur à %s \n", s2,s1);
	}
	else {
		printf("le mot %s est inferieur à %s \n", s1,s2);
	}

	return 0;
}
