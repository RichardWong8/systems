#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

  int in = open("in.txt", O_RDONLY);
  char *c1 = (char*)malloc(100);
  
  int input = read(in, c1, 24);
  printf("read returned: %d\n", input);
  printf("c1: %s\n", c1);

  int out = open("out.txt", O_WRONLY);
  char *c2 = (char*)malloc(100);
  strcat(c2, "Best Class: ");
  strcat(c2, c1);

  int output = write(out, c2, strlen(c2));
  printf("write returned: %d\n", output);
  printf("c2: %s\n", c2);

  int close1 = close(in);
  int close2 = close(out);
  printf("close1: %d\n", close1);
  printf("close2: %d\n", close2);

  return 0;
}
