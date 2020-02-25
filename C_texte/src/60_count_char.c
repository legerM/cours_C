

#include<stdio.h>
#include<string.h>


int main(int argc, char *argv[]){
	char text[]="Qu'est-ce qu'un processeur ARM ? C'est un type de processeur particulier dont l'agencement des composants"
			"�lectroniques permet une taille r�duite. ARM est l'acronyme de Advanced Risk"
			"Machine. A l'origine, le A de ARM signifiait Acorn, le nom de la soci�t� qui a"
			"�quip� pour la premi�re fois un ordinateur avec un processeur ARM, en 1987."
			"Depuis, l'architecture ARM a rencontr� un succ�s qui ne se d�ment pas,"
			"notamment ces derni�res ann�es. Des processeurs ARM, on en trouve dans tous"
			"les smartphones r�cents : iPhone 4, Samsung Galaxy S, tout comme dans l'iPad,"
			"le Nokia N97 ou le Nexus One de Google. Mais la soci�t� ARM ltd ne fabrique"
			"pas, � proprement parler, les processeurs. Elle con�oit les architectures des"
			"processeurs, leurs plans en quelque sorte. Ce sont les clients qui, apr�s"
			"achat des licences, produisent les processeurs. Par exemple, Samsung fabrique"
			"un processeur ARM pour ses t�l�phones haut de gamme (Samsung Galaxy S et"
			"Wave), reposant sur l'architecture ARM Cortex-A8, cadenc�e � 1 GHz. Le"
			"processeur Apple A4, qui �quipe les iPhone 4 et les iPad, utilise exactement"
			"la m�me architecture Cortex-A8. Ces petits processeurs connaissent un tel"
			"succ�s qu'ils �voluent tr�s rapidement : Samsung a d�j� annonc� le rempla�ant"
			"de Cortex-A8 ; celui-ci r�pond au nom de Cortex-A9 et int�gre deux coeurs,"
			"comme dans les PC. Quant au Cortex-A15, qui devrait �tre disponible dans une"
			"vingtaine de mois, on sait d�j� qu'il s'agira d'un processeur quatre coeurs"
			"cadenc� � 2,5 GHz et basse consommation ! Un tel processeur devrait avoir des"
			"performances similaires � celles d'un ordinateur portable tr�s haut de gamme,"
			"alors qu'il est pr�vu pour �tre embarqu� dans un t�l�phone de seulement"
			"quelques millim�tres d'�paisseur.";
	char vowel[]={'a','e','i','o','u','y','A','E','I','O','U','Y','�','�','�','�','�','�','�','�','�'};
	char Consonant[] = {'b','c','�','d','f','g','h','j','k','l','m',
			'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z',
			'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M',
			'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Z'};

	int lentext=0;
	int lenvowel=0;
	int lencons=0;
	int nb_letter=0;
	int nb_vowel=0;
	int nb_cons=0;
	float pct_vowel=0;
	float pct_cons=0;
	lenvowel=strlen(vowel);
	lentext=strlen(text);
	lencons=strlen(Consonant);

	for (int i=0;i<lentext;i++){
		for(int j=0;j<lenvowel;j++){
			if(text[i]==vowel[j]){
				nb_vowel+=1;
			}
		}
		for (int k=0;k<lencons;k++){
			if (text[i]==Consonant[k]){
				nb_cons+=1;
			}
		}
	}

	nb_letter = nb_vowel + nb_cons;
	pct_vowel =(nb_vowel*100.00)/nb_letter;
	pct_cons=100.00 - pct_vowel;
	printf("il y a %d voyelles \n" ,nb_vowel);
	printf("il y a %d Consonnes \n", nb_cons);
	printf("il y a un total de %d lettres \n", nb_letter);
	printf("il y a un total de %.2f %% voyelles et de %.2f %% de consonnes\n",pct_vowel ,pct_cons);


	return 0;
}
