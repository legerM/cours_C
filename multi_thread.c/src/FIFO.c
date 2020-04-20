#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "FIFO.h"
#include <pthread.h>
#include<unistd.h>
#include<semaphore.h>

extern pthread_mutex_t mutex ;


void init_liste(struct List *liste){
	liste->mutex = (pthread_mutex_t) PTHREAD_MUTEX_INITIALIZER;
	liste->head = NULL;
	liste->tail = NULL;

}
int pop_element(struct List* liste,int *value) {

	struct Element* tmp;
	if (liste->head == NULL) {
		return 0; /* Retourne -1 si la pile est vide. */
	}
//	pthread_mutex_lock (&mutex);
	tmp = liste->head->next_p;
	*value = liste->head->value;
	free(liste->head);
	liste->head = tmp;/* Le pointeur pointe sur le dernier ��l��ment. */
//	pthread_mutex_unlock (&mutex);
	return 1;/* Retourne la valeur soutir��e de la pile. */
}


// envoie un element dans la liste chain��e
void push_element(struct List *liste, int value) {

	struct Element*  new_element = malloc(sizeof(struct Element)); //new_element contient l'adresse memoire des 8 octets cr��e

	if (new_element) {
		pthread_mutex_lock (&mutex);// si le malloc contient bien une adresse
		new_element->value = value;                      //valeur du struct
		new_element->next_p = NULL;                  // adresse du prochain element
		if (liste->head == NULL) {                          // si la liste est vide
			liste->tail = new_element; //on attache le nouvel element a la queue de liste
			liste->head = new_element;              // on attache la tete aussi
		} else {                        //si la liste contient deja des elements

			liste->tail->next_p = new_element;
			liste->tail = new_element;
		}
		pthread_mutex_unlock (&mutex);
	}
}
