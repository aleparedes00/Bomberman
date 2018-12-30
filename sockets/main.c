#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <zconf.h>

#include "server.h"

int main() {
    Object object1;
    Object gameBoard[10][13];
    //Random to fill in the gameBoard with objects: Block, staticBlock
    return 0;
}

/*
   int socket_desc;
    struct sockaddr_in server;

    char *message;
    char server_reply[2000];

    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket\n");
    }
    //Check IP address of website -> nslookup google.com
    server.sin_addr.s_addr = inet_addr("172.217.22.142");
    server.sin_family = AF_INET;
    //check what is connected to the port 80 -> from command line do lsof -itcp:80
    server.sin_port = htons(80);

    //connect to the server
    if (connect(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        puts("connection error\n");
        return 1;
    }
    puts("connected\n");

    //Send some data
    message = "GET / HTTP/1.1\r\n\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("Send message failed");
        return 1;
    }
    puts("Data Sent\n");

    //Receive reply
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        puts("recv failed");
    }
    puts("recv successful");
    puts(server_reply);

    close(socket_desc);
    */
