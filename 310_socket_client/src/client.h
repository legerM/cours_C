/*
 * client.h
 *
 *  Created on: Mar 16, 2020
 *      Author: mickaell
 */

#ifndef CLIENT_H_
#define CLIENT_H_
#define SRV_IP "127.0.0.1"
#define SRV_PORT 5001

int create_socket();
int connect_socket();
int send_message(int socket_desc, char* message);
#endif /* CLIENT_H_ */
