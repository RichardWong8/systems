#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int rand_int() {
  return rand() % (20 + 1 - 5) + 5;
}

int child_stuff() {
  srand(getpid());
  printf("child pid: %d\n", getpid());
  int time = rand_int();
  sleep(time);
  printf("child %d done sleeping\n", getpid());
  return time;
}

int main() {
  int f = fork();
  int status;
  if (f) {
    printf("parent pid: %d\n", getpid());
    int f2 = fork();
    if (f2) {
      int status;
      int first = wait(&status);
      printf("completed child pid: %d, sleep time: %d\n", first, WEXITSTATUS(status));
      printf("parent completed\n");
      return 0;
    }
    else {
      return child_stuff();
    }
  }
  else {
    return child_stuff();
  }
  return 0;
}
