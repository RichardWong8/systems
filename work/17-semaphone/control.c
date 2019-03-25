#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <fcntl.h>

union semun{
  int val;
  struct semid_ds * buf;
  unsigned short * array;
};


int main(int argc, char *argv[]){
  key_t shmkey;
  key_t semkey;
  
  if (argc == 1){
    printf("ERROR: Enter an argument\n");
    exit(1);
  }

  if (argc > 2){
    printf("ERROR: Too many arguments\n");
    exit(1);
  }
  
  if (!strcmp(argv[1],"-c")){
    printf("Creating Shared Memory, Semaphore, and File \n");
    shmkey = ftok("mem", 'M');
    semkey = ftok("sem", 'S');
    
    int shmid = shmget(shmkey, 200, IPC_CREAT | 0666);
    int semid = semget(semkey, 1, IPC_CREAT | IPC_EXCL | 0644);
    
    int file = open("story.txt", O_CREAT|O_TRUNC, 0666);;
    if (file < 0){
      perror("ERROR story.txt");
      exit(1);
    }

    union semun x;
    x.val = 1;
    semctl(semid, 0, SETVAL, x);
  }

  if (!strcmp(argv[1],"-r")){
    printf("Removing shared memory, semaphore, and story \n");
    shmkey = ftok("mem", 'M');
    semkey = ftok("sem", 'S');
    int semid = semget(semkey, 1, 0);
    int shmid = shmget(shmkey, 200, 0);

    while(semctl(semid, 0, GETVAL) == 0) {
      printf("checking if resources are available\n");
    }
    
    struct sembuf down;
    down.sem_op = -1;
    down.sem_num = 0;
    down.sem_flg = SEM_UNDO;

    semop(semid, &down, 1);
    
    shmctl(shmid, IPC_RMID, 0);
    semctl(semid, 0, IPC_RMID, 0);

    printf("Viewing Story \n");
    int file = open("story.txt",O_RDONLY);
    char * story = calloc(10000,1);
    read(file, story, 10000);
    printf("%s\n", story);
    close(file);

    remove("story.txt");
  }

  if(!strcmp(argv[1], "-v")){
    printf("Viewing Story \n");
    int file = open("story.txt",O_RDONLY);
    char * story = calloc(10000,1);
    read(file, story, 10000);
    printf("%s\n", story);
    close(file);
  }
}
