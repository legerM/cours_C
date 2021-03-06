/*
 * client.c
 *
 *  Created on: Mar 16, 2020
 *      Author: mickaell
 */

#include "client.h"
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include <unistd.h>
#include"debug.h"
#include <errno.h>
#include <string.h>// strlen

int create_socket(void) {
	int socket_desc = -1;
	int error_create_socket;
	//Create socket
	while (socket_desc == -1) {
		socket_desc = socket(AF_INET, SOCK_STREAM, 0);
		error_create_socket = errno;
		if (socket_desc == -1) {
			error_printf("Could not create socket. error n° : %i , %s",
					error_create_socket, strerror(error_create_socket));
		}
	}
	debug_printf(0, "la socket est cree \n");
	return socket_desc;
}

int connect_socket(void) {
	int socket_desc;
	struct sockaddr_in server;
	server.sin_addr.s_addr = inet_addr(SRV_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SRV_PORT);

	int error_connect_socket;
	int connect_status = -1;
	//Connect to remote server
	while (connect_status < 0) {
		socket_desc = create_socket();
		connect_status = connect(socket_desc, (struct sockaddr*) &server,
				sizeof(server));
		if (connect_status == -1) {
			error_connect_socket = errno;
			//puts("connect error");
			error_printf("connection error. error n° : %i , %s",
					error_connect_socket, strerror(error_connect_socket));
			close(socket_desc);
		}
	}
	debug_printf(1, "Connected\n");
	return socket_desc;
}

int send_message(int socket_desc, char* message) {
	//Send some data
	int compteur=0;
	int send_status = -1;
	int error_send_message;

	int lenght = strlen(message);
	while (1) {
		compteur++;
		char nombre[100];
		sprintf(nombre,"msg=%d",compteur);
		int lenghtNombre = strlen(nombre);
		strncat(&nombre[lenghtNombre],message,100-lenghtNombre-1);
		lenght = strlen(nombre);

		send_status = send(socket_desc, nombre, lenght, 0) < 0;
		error_printf("%d",send_status);
		if (send_status == -1) {
			error_send_message = errno;
			error_printf("Send failed. error n° : %i , %s", error_send_message,
					strerror(error_send_message));
			return send_status;
		}
		else if (send_status == lenght){
			debug_printf(1, "Data Sent\n");
			return send_status;


		}

		sleep(2);
	}
}
