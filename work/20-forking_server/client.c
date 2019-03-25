#include "pipe_networking.h"

void signal_handler(int sig) {
  remove("private");
  exit(0);
}

int main() {
  signal(SIGINT, signal_handler);
  
  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  while (1) {
    printf("[client] enter data: ");
    char input[BUFFER_SIZE];
    fgets(input, BUFFER_SIZE, stdin);
    input[strlen(input) - 1] = 0;

    write(to_server, input, BUFFER_SIZE);

    char output[BUFFER_SIZE];
    read(from_server, output, BUFFER_SIZE);

    printf("[client] server response: %s\n", output);
  }
}
