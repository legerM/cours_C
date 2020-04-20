#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "FIFO.h"
#include <pthread.h>
#include<unistd.h>

int main(void){
	struct List liste;
	init_liste(&liste);

	//	for(int i=0; i<3; i++) {
	//		push_element(&liste, i);
	//	}
	//
	//	printf("gnu %d \n", pop_element(&liste));
	//	printf("gnou %d \n", pop_element(&liste));
	//	printf("gnui %d \n", pop_element(&liste));

	pthread_t t1, t2;
	pthread_create(&t1, NULL, &thread_send, &liste);
	pthread_create(&t2, NULL, &thread_pop, &liste);


	pthread_join(t1, NULL);
	pthread_join(t2, NULL);



	return 0;
}
