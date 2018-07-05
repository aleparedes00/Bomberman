//
// Created by Alejandra Paredes on 04/07/2018.
//

/****************** SERVER CODE ****************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main(){
    int                   welcomeSocket, newSocket;
    char                  buffer[1024];
    struct protoent       *protocolUtilise;
    struct sockaddr_in    serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t             addr_size;

    protocolUtilise = getprotobyname("tcp");


    /*---- Create the socket. The three arguments are: ----*/
    /* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
    welcomeSocket = socket(PF_INET, SOCK_STREAM, protocolUtilise->p_proto);
    //Check que ca a marche.
    if(welcomeSocket == -1)
    {
        return -1;
    }
    /*---- Configure settings of the server address struct ----*/
    /* Address family = Internet */
    serverAddr.sin_family = AF_INET;
    /* Set port number, using htons function to use proper byte order */
    serverAddr.sin_port = htons(7891);
    /* Set IP address to localhost */
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    /* Set all bits of the padding field to 0 */ //WHY DO I NEED THIS LINE????
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    /*---- Bind the address struct to the socket ----*/
    bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
    /*---- Listen on the socket, with 5 max connection requests queued ----*/
    if(listen(welcomeSocket,5)==0)
        printf("Listening\n");
    else
        printf("Error\n");

    /*---- Accept call creates a new socket for the incoming connection ----*/
    addr_size = sizeof serverStorage;
    puts("creates new socket for client\n");
    newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);

    while(1){
        /*--  Receiving --*/
        int receive = recv(newSocket, buffer, sizeof(buffer), 0);

        if (receive > 0)
        {
            /*-- Function to do something with the information --*/
            puts(buffer);
            memset(buffer, 0, 1024);
            receive = 0;
        }
        if (receive == 0){
            /*-- Function to fill in the information to send--*/
            strcpy(buffer,"This could be an structure?\n");
            puts("sends test message\n");
            send(newSocket, buffer, strlen(buffer),0);
            receive = -1;
        }
        sleep(1);
    }
    /*---- Send message to the socket of the incoming connection ----*/

    sleep(1000);
    puts("Bye!\n");
    return 0;
}