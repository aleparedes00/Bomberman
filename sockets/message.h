#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/errno.h>

/* Maximum bytes that can be send() or recv() via net by one call.
 * It's a good idea to test sending one byte by one.
 */
#define MAX_SEND_SIZE 100

/* Size of send queue (messages). */
#define MAX_MESSAGES_BUFFER_SIZE 10

#define SENDER_MAXSIZE 128
#define DATA_MAXSIZE 512

#define SERVER_IPV4_ADDR "127.0.0.1"
#define SERVER_LISTEN_PORT 33235

// message --------------------------------------------------------------------

typedef struct {
  char sender[SENDER_MAXSIZE];
  char data[DATA_MAXSIZE];
}  message_t;

int prepare_message(char *sender, char *data, message_t *message);
int print_message(message_t *message);

// message queue --------------------------------------------------------------

typedef struct {
  int size;
  message_t *data;
  int current;
} message_queue_t;

int create_message_queue(int queue_size, message_queue_t *queue);
void delete_message_queue(message_queue_t *queue);
int enqueue(message_queue_t *queue, message_t *message);
int dequeue(message_queue_t *queue, message_t *message);
int dequeue_all(message_queue_t *queue);

// peer -----------------------------------------------------------------------

typedef struct {
  int socket;
  struct sockaddr_in addres;
  
  /* Messages that waiting for send. */
  message_queue_t send_buffer;
  
  /* Buffered sending message.
   * 
   * In case we doesn't send whole message per one call send().
   * And current_sending_byte is a pointer to the part of data that will be send next call.
   */
  message_t sending_buffer;
  size_t current_sending_byte;
  
  /* The same for the receiving message. */
  message_t receiving_buffer;
  size_t current_receiving_byte;
} peer_t;

void delete_peer(peer_t *peer);
int create_peer(peer_t *peer);
char *peer_get_addres_str(peer_t *peer);
int peer_add_to_send(peer_t *peer, message_t *message);
int receive_from_peer(peer_t *peer, int (*message_handler)(message_t *));
int send_to_peer(peer_t *peer);

// common -----------------------------------------------------------------------
int read_from_stdin(char *read_buffer, size_t max_len);

#endif /* MESSAGE_H */
