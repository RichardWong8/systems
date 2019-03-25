#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int receive_pipe, int *to_client) {  
  remove("wkp");

  char s[HANDSHAKE_BUFFER_SIZE];
 
  read(receive_pipe, s, sizeof(s));
  printf("[subserver] message received: %s\n", s);
    
  printf("[subserver] notifying client...\n");
  int send_pipe = open(s, O_WRONLY);
  write(send_pipe, ACK, sizeof(ACK));
  
  printf("[subserver] receiving client message...\n");
  read(receive_pipe, s, sizeof(s));
  printf("[subserver] message received: %s\n", s);
  
  printf("[subserver] handshake complete\n");
  
  *to_client = send_pipe;
  return receive_pipe;
}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
  printf("[client] creating private pipe...\n");
  mkfifo("private", 0644);

  printf("[client] connecting to server...\n");
  int send_pipe = open("wkp", O_WRONLY);
  write(send_pipe, "private", 8);

  printf("[client] receiving server message...\n");
  char message[HANDSHAKE_BUFFER_SIZE];
  int receive_pipe = open("private", O_RDONLY);
  read(receive_pipe, message, HANDSHAKE_BUFFER_SIZE);
  printf("[client] message received: %s\n", message);
  remove("private");

  printf("[client] notifying server...\n");
  write(send_pipe, ACK, sizeof(ACK));

  printf("[client] handshake complete\n");

  *to_server = send_pipe;
  return receive_pipe;
}

