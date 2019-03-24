#include "shell.h"

int main() {
  char * line = calloc(100, sizeof(char));
  while (1) {
    printf("shell$ ");
    fgets(line, 100, stdin);
    line[strlen(line) - 1] = 0;

    parse_commands(line);
  }
  return 0;
}
