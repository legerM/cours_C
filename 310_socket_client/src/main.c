#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include <unistd.h>
#include"debug.h"
#include <errno.h>
#include"client.h"
// IPv4 AF_INET sockets:

int main(int argc, char *argv[]) {

	char *message = "mooooooordu\n";

	debug_setlevel(1) ;

	int socket_desc = connect_socket();
	printf("1");
	//Send some data
	send_message(socket_desc, message);

	return 0;

}

