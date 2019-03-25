#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "randfile.h"

int main() {
  printf("Generating random numbers:\n");
  int arr[10];
  int i;
  for (i = 0; i < 10; i++) {
    arr[i] = rand_int();
    printf("random %d: %d\n", i, arr[i]);
  }

  printf("Writing numbers to file...\n");
  int fd = open("out.txt", O_WRONLY | O_CREAT, 0777);
  if (fd < 0) {
    printf("open error: %s\n", strerror(errno));
    return 0;
  }
  int w = write(fd, arr, sizeof(int) * 10);
  if (w < 0) {
    printf("write error: %s\n", strerror(errno));
    return 0;
  }

  printf("Reading numbers from file...\n");
  fd = open("out.txt", O_RDONLY);
  if (fd < 0) {
    printf("open error: %s\n", strerror(errno));
    return 0;
  }
  int other[10];
  int r = read(fd, other, sizeof(int) * 10);
  if (r < 0) {
    printf("read error: %s\n", strerror(errno));
    return 0;
  }

  printf("Verification that written values are the same:\n");
  for (i = 0; i < 10; i++) {
    printf("random %d: %d\n", i, other[i]);
  }
}