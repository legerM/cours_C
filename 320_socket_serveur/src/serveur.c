
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include<stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "serveur.h"

int connect_server(void){

	int socket_desc , new_socket , c;
	struct sockaddr_in server , client;
	char client_message[SIZEMESSAGE+1];
	//	int sock = *(int*)socket_desc;
	int read_size;

	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	while (socket_desc == -1)
	{
		perror("Could not create socket");
		socket_desc = socket(AF_INET , SOCK_STREAM , 0);

	}

	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( SRV_PORT );

	//Bind
	int stateBind = bind(socket_desc,(struct sockaddr *)&server , sizeof(server));
	while( stateBind == -1 )
	{
		perror("bind failed");
		stateBind = bind(socket_desc,(struct sockaddr *)&server , sizeof(server));
	}

	puts("bind done");

	//Listen
	int stateListen = listen(socket_desc , 3);
	if(stateListen ==0){
		while(1){
			//Accept and incoming connection
			puts("Waiting for incoming connections...");
			c = sizeof(struct sockaddr_in);
			new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);

			if (new_socket==-1)
			{
				perror("accept failed");
			}

			printf("New Client !\n");
			puts("Connection accepted");
			//	int sock = *(int*)socket_desc;
			int compteur=0;
			while( (read_size = recv(new_socket , client_message , SIZEMESSAGE , 0)) > 0 )
			{
					compteur++;

					client_message[read_size]= '\0';
					//Send the message back to client

					printf("%s", client_message);

			}

			if(read_size == 0)
			{
				puts("Client disconnected");
				fflush(stdout);
			}
			else if(read_size == -1)
			{
				perror("recv failed");
			}
		}
	}
	// si listen retourne autre chose que 0 ou >0
	else{
		perror("listen failed");
	}

	void * gnu_socket= &socket_desc;
	//Free the socket pointer
	free(gnu_socket);

	return 0;

}
