#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "randfile.h"

int rand_int() {
  int fd = open("/dev/random", O_RDONLY);
  if (fd < 0) {
    printf("open error: %s\n", strerror(errno));
    return -1;
  }
  
  int buffer;
  int r = read(fd, &buffer, sizeof(buffer));
  if (r < sizeof(buffer)) {
    printf("read error: %s\n", strerror(errno));
    return -1;
  }
  return buffer;
}