//
// Created by Alejandra Paredes on 04/07/2018.
//
#include <stdio.h>  
#include <string.h>   //strlen  
#include <stdlib.h>  
#include <errno.h>  
#include <unistd.h>   //close  
#include <arpa/inet.h>    //close  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros  
     
#define TRUE   1  
#define FALSE  0  
#define PORT 8888


int main(){
  int opt = TRUE;
  int master_socket , addrlen , new_socket , client_socket[5] ,  
    max_clients = 5 , activity, i , valread , sd;
  int max_sd;
  struct sockaddr_in address;

  char buffer[1025];

  //set of socket descriptors
  fd_set readfds; 
  //a message
  char const * const message = "ECHO Daemon v1.0 \r\n";
     
  //initialise all client_socket[] to 0 so not checked
  puts("[+]Initialise all client sockets to 0...");
  for (i = 0; i < max_clients; i++)   
    {   
      client_socket[i] = 0;   
    }   
  //create a master socket
  puts("[+]Creating master socket...");
  if( (master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0)   
    {   
      perror("socket failed");   
      exit(EXIT_FAILURE);   
    }
  
  //set master socket to allow multiple connections ,  
  //this is just a good habit, it will work without this  
  if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0 )   
    {   
      perror("setsockopt");   
      exit(EXIT_FAILURE);   
    }

  address.sin_family = AF_INET;
  /* Set port number, using htons function to use proper byte order */
  address.sin_port = htons(PORT);
  /* Set IP address to localhost */
  address.sin_addr.s_addr = INADDR_ANY;
  /* Set all bits of the padding field to 0 */ //WHY DO I NEED THIS LINE????
  //memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  /*---- Bind the address struct to the socket ----*/
  if(bind(master_socket, (struct sockaddr *) &address, sizeof(address)) < 0)
    {
      perror("bind failed");
      exit(EXIT_FAILURE);
    }
  printf("[+]Listener on port %d \n", PORT);   
         
  //try to specify maximum of 3 pending connections for the master socket  
  if (listen(master_socket, 3) < 0)   
    {   
      perror("listen");   
      exit(EXIT_FAILURE);   
    }

  addrlen = sizeof(address);   
  puts("[+]Waiting for connections ...");

  while(TRUE)
    {
      //clear the socket set  
      FD_ZERO(&readfds);   
     
      //add master socket to set  
      FD_SET(master_socket, &readfds);   
      max_sd = master_socket;   
             
      //add child sockets to set  
      for ( i = 0 ; i < max_clients ; i++)   
        {   
	  //socket descriptor  
	  sd = client_socket[i];   
                 
	  //if valid socket descriptor then add to read list
	  if(sd > 0)   
	    FD_SET( sd , &readfds);   
                 
	  //highest file descriptor number, need it for the select function  
	  if(sd > max_sd)   
	    max_sd = sd;   
        }   
      //wait for an activity on one of the sockets , timeout might be set ,  
      //For now, wait indefinitely  
      activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);
       
      if ((activity < 0) && (errno!=EINTR))   
        {   
	  perror("select error");   
        }
      //If something happened on the master socket, then its an incoming connection  
      if (FD_ISSET(master_socket, &readfds))
        {   
	  if ((new_socket = accept(master_socket, (struct sockaddr *) &address, (socklen_t*)&addrlen))<0)   
            {   
	      perror("accept");   
	      exit(EXIT_FAILURE);   
            } 
	  //inform user of socket number - used in send and receive commands  
	  printf("[+]New connection , socket fd is %d , ip is : %s , port : %d\n",\
 new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));
           
	  //send new connection greeting message  
	  int result = read(1, buffer, 1024);
	  buffer[result] = '\0';
	  //	  send(new_socket, buffer, strlen(buffer), 0);
	  //if( send(new_socket, message, strlen(message), 0) != strlen(message) )   
	  if(send(new_socket, buffer, strlen(buffer), 0) != strlen(buffer))
            {   
	      perror("send");   
            }   
                 
	  puts("Welcome message sent successfully");   
                 
	  //add new socket to array of sockets  
	  for (i = 0; i < max_clients; i++)   
            {   
	      //if position is empty  
	      if(client_socket[i] == 0)   
                {   
		  client_socket[i] = new_socket;   
		  printf("[+]Adding to list of sockets at position %d\n" , i);   
                         
		  break;   
                }   
            }   
        }
      //else its some IO operation on some other socket 
      for (i = 0; i < max_clients; i++)   
        {   
	  sd = client_socket[i];   
                 
	  if (FD_ISSET( sd , &readfds))   
            {   
	      //Check if it was for closing , and also read the  
	      //incoming message  
	      puts("[+]Receiving: ");
	      if ((valread = recv( sd , buffer, 1024, 0)) == 0)   
                {   
		  //Somebody disconnected , get his details and print  
		  getpeername(sd , (struct sockaddr*)&address, (socklen_t*)&addrlen);   
		  printf("[+]Host disconnected , ip %s , port %d \n" ,  
			 inet_ntoa(address.sin_addr) , ntohs(address.sin_port));   
                         
		  //Close the socket and mark as 0 in list for reuse  
		  close( sd );   
		  client_socket[i] = 0;   
                }   
                     
	      //Echo back the message that came in  
	      else 
                { 
		  //set the string terminating NULL byte on the end  
		  //of the data read  
		  buffer[valread] = '\0';
		  puts(buffer);
		  //send(sd , buffer , strlen(buffer) , 0 );   
                }   
	    }
	}
    }
    return 0;
}
