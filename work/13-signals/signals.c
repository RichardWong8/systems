#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static void signal_handler(int signo){
  if (signo == SIGINT){
    int out = open("out.txt", O_CREAT | O_APPEND | O_RDWR, 0777);
    lseek(out, SEEK_END, 0);
    write(out, "program exit due to SIGINT\n", 28);
    close(out);
    exit(0);
  }
  if (signo == SIGUSR1){
    printf("parent process PID: %d\n", getppid());
  }
}

int main(){
  signal(SIGINT, signal_handler);
  signal(SIGUSR1, signal_handler);
  while(1){
    printf("process PID: %d\n", getpid());
    kill(getpid(), SIGUSR1);
    sleep(1);
  }
  return 0;
}
