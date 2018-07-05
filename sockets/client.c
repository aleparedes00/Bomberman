//
// Created by Alejandra Paredes on 04/07/2018.
//

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int             getThePort(char *thePort){
    /*-- convert char * into int--*/
}

int                     main(int argc, char **argv){

    int                   clientSocket;
    char                  buffer[1024];
    struct protoent       *protocolUtilise;
    struct sockaddr_in    serverAddr;
    socklen_t             addr_size;

    if(argc < 3){
        puts("Please, provide the IP address and port to conenct");
        return -1;
    }

    protocolUtilise = getprotobyname("tcp");

    /*---- Create the socket. The three arguments are: ----*/

    clientSocket = socket(PF_INET, SOCK_STREAM, protocolUtilise->p_proto);


    if(clientSocket == -1)
    {
        return -1;
    }
    /*---- Configure settings of the server address struct ----*/
    /* Address family = Internet */
    serverAddr.sin_family = AF_INET;
    /* Set port number, using htons function to use proper byte order */
    serverAddr.sin_port = htons(7891); /*TODO replace for the function to transform argv[2] into i\
nt */
    /* Set IP address to localhost */
    serverAddr.sin_addr.s_addr = INADDR_ANY; /*TODO replace for the inet_addr(argv[1])*/
    /* Set all bits of the padding field to 0 */
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    /*---- Connect the socket to the server using the address struct ----*/
    addr_size = sizeof serverAddr;

    int connected = connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

    if(connected == -1){
        return -1;
    }

    /*testing reading input and send to the server*/
    while(1) {
        /*-- Read and send input from user --*/
        int result = read(1, buffer, 1024);

        if (result > 0) {
            puts(buffer);
            result = send(clientSocket, buffer, strlen(buffer), 0);
        }
    }
        /*testing receiving data and print it on command line */
    while(1){
        /*---- Read the message from the server into the buffer ----*/
        int received = recv(clientSocket, buffer, 1024, 0);

        /*---- Print the received message ----*/
        if (received > 0) {
            puts(buffer);
            memset(buffer, 0, 1024);
        }
        sleep(1);
    }

    return 0;
}