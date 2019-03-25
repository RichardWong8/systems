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
    
  while (1) {
    printf("[server] creating wkp...\n");
    mkfifo("wkp",0644);

    printf("[server] connecting client...\n");
    from_client = open("wkp", O_RDONLY);

    int f = fork();
    if (!f) {
      from_client = server_handshake(from_client, &to_client);
      char data[BUFFER_SIZE];
      while (read(from_client, data, BUFFER_SIZE)) {
	printf("[subserver%d] client input: %s\n", getpid(),  data);

	char processed[BUFFER_SIZE];
	int i;
	for (i = 0; i < strlen(data); i++){
	  processed[i] = data[i]+1;
	}
	write(to_client, processed, BUFFER_SIZE);
      }
      exit(0);
    }
    else {
      remove("wkp");
      close(from_client);
      close(to_client);
    }
  }
}
