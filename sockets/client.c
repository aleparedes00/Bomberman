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
  return 0;
}

int                     main(int argc, char **argv){
  
  int                   clientSocket;
  char                  buffer[1024];
  struct protoent       *protocolUtilise;
  struct sockaddr_in    serverAddr;
  socklen_t             addr_size;
  int received = 0;
  
  //if(argc < 3){
  //    puts("Please, provide the IP address and port to conenct");
  //    return -1;
  //}
  
  protocolUtilise = getprotobyname("tcp");
  
  /*---- Create the socket. The three arguments are: ----*/
  
  clientSocket = socket(PF_INET, SOCK_STREAM, protocolUtilise->p_proto);
  
  
  if(clientSocket == -1)
    {
      puts("Connection with socket failed...");
      return -1;
    }
  /*---- Configure settings of the server address struct ----*/
  /* Address family = Internet */
  serverAddr.sin_family = AF_INET;
  /* Set port number, using htons function to use proper byte order */
  serverAddr.sin_port = htons(8888); /*TODO replace for the function to transform argv[2] into i \
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
  
  //TODO If server disconnects, I have to disconnect too.
  while(1){
    /*---- Read the message from the server into the buffer ----*/
    received = 0;
      puts("[+]Buffer: ");
      puts(buffer);
      printf("[+] before received: %d\n", received);
      received = recv(clientSocket, buffer, 1024, 0);
      puts("\n[+]Ater received'\n");
      /*---- Print the received message ----*/
      if (received  > 0) {
      	buffer[received] = '\0';
        printf("[+]After recv() received: %d\n", received);
      	puts("\nServer says: ");
	puts(buffer);
	//memset(buffer, 0, 1024);
      } else if (received == 0) {
	puts("[+] Connection lost\n");
      }
      // sleep(1);
      
  }     
  puts("Please input your message:\n");
  /*-- Read and send input from user --*/
  int result = read(1, buffer, 1024);
  buffer[result] = '\0';
  if (result > 0) {
    puts("Sendind: ");
    puts(buffer);
    result = send(clientSocket, buffer, strlen(buffer), 0);
  } else {
    puts("Nothing to read...");
  }
    
    return 0;
}
