#include "pipe_networking.h"

void signal_handler(int sig) {
  if (sig == SIGINT) {
    remove("wkp");
    exit(0);
  }
}

int main() {
  signal(SIGINT, signal_handler);
  
  int to_client;
  int from_client;
  char data[BUFFER_SIZE];
  
  while (1) {
    from_client = server_handshake( &to_client );

    while (read(from_client, data, BUFFER_SIZE)) {
      printf("client input: %s\n", data);

      char processed[BUFFER_SIZE];
      int i;
      for (i = 0; i < strlen(data); i++){
	processed[i] = data[i]+1;
      }
      write(to_client, processed, BUFFER_SIZE);
    }
  }
}
