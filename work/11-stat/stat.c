#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main(){
  struct stat info;
  stat("stat.c", &info);

  printf("file size: %ld\n", info.st_size);
  printf("permissions: %o\n", info.st_mode);
  printf("time of last access: %s\n", ctime(&info.st_atime));

  return 0;
}