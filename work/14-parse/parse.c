#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char ** parse_args(char *line){
  char ** arr = calloc(sizeof(char*), 5);
  int i = 0;
  while (line) {
    arr[i] = strsep(&line, " ");
    i++;
  }
  return arr;
}

int main() {
  char line[100] = "ls -a -l";
  char ** args = parse_args(line);
  execvp(args[0], args);
}
