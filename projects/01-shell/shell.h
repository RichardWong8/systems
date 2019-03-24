#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

void run(char ** args);
void parse_args(char * command);
void parse_commands(char * line);
