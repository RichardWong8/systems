#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <math.h>

void format_size(float size){
  int index = 0;
  char * sizes[] = {"B", "KB", "MB", "GB"};
  while (index<= 3){
    printf("%f%s\n",size,sizes[index]);
    size /= 1024;
   index+=1;
  }
}

void print_info(char * dir_name) {
  struct dirent * file;
  DIR * dir = opendir(dir_name);
  int bytes = 0;

  printf("Directories:\n");
  while ((file = readdir(dir))) {
    if (file->d_type == DT_DIR) {
      printf("\t%s\n", file->d_name);
    }
  }
  closedir(dir);

  dir = opendir(dir_name);
  printf("Regular files:\n");
  while ((file = readdir(dir))) {
    if (file->d_type == DT_REG) {
      struct stat info;
      stat(file->d_name, &info);
      printf("\t%s\n", file->d_name);
      bytes += info.st_size;
    }
  }
  closedir(dir);

  //printf("Total Directory Size: %d Bytes\n", bytes);
  printf("Total Directory Size: \n");
  format_size((float)bytes);
  printf("\n");
}

int main(int argc, char *argv[]) {
  char * name = malloc(100);
  DIR * dir;

  if (argc > 1) {
    strcpy(name, argv[1]);
    dir = opendir(name);
  }
  else {
    printf("Enter a directory: ");
    fgets(name, 100, stdin);
    name[strlen(name) - 1] = 0;
    dir = opendir(name);
  }
  while (!dir) {
    printf("Error: %s\n", strerror(errno));
    printf("Enter a directory: ");
    fgets(name, 100, stdin);
    name[strlen(name) - 1] = 0;
    dir = opendir(name);
  }
  print_info(name);
}
