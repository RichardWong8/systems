#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main() {
  key_t shmkey = ftok("mem", 'M');
  key_t semkey = ftok("sem", 'S');
  
  int shmid = shmget(shmkey, 200, 0);
  int semid = semget(semkey, 1, 0);

  while (semctl(semid, 0, GETVAL) == 0) {
    printf("checking if resources are available\n");
  }
  
  struct sembuf down;
  down.sem_op = -1;
  down.sem_num = 0;
  down.sem_flg = SEM_UNDO;

  semop(semid, &down, 1);
  
  char * line = malloc(200);
  line = shmat(shmid, 0, 0);
  printf("last line: %s\n", line);
  printf("add the next line of the story: \n");
  
  char input[200];
  fgets(input, 200, stdin);
  input[strlen(input) - 1] = 0;
  
  strcpy(line, input);
  shmdt(line);
  
  int file = open("story.txt", O_WRONLY | O_APPEND, 0666);
  write(file, input, strlen(input));
  
  struct sembuf up;
  up.sem_op = 1;
  up.sem_num = 0;
  up.sem_flg = SEM_UNDO;

  semop(semid, &up, 1);
  
  close(file);
}
