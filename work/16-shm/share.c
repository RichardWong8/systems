#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>

int main() {
  key_t key;
  int shmid;
  char *data;
 
  key = ftok("foo", 'R');
  shmid = shmget(key, 200, 0644 | IPC_CREAT);
  data = shmat(shmid, (void *)0, 0);

  if (!strlen(data)) {
    printf("segment created\n");
  }
  else {
    printf("contents: %s\n", data);
  }

  char input[200];
  
  printf("change contents? (y/n)");
  fgets(input, 200, stdin);  
  if(!strcmp(input, "y\n")) {
    printf("provide new string: ");
    fgets(input, 200, stdin);
    input[strlen(input) - 1] = 0;
    strcpy(data, input);
  }

  printf("delete segment? (y/n)");
  fgets(input, 200, stdin);
  if(!strcmp(input, "y\n")) {
    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);
  }
  
  return 0;
}
