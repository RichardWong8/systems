#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int run(char ** args) {
  int status; 
  int f = fork();
  if (f) {
    wait(&status);
  }
  else {
    if(!strcmp(args[0],"cd"))
      chdir(args[1]);
    execvp(args[0], args);
  }
}

int parse_args(char * command) {
  int stdout_cpy = dup(1);
  int stdin_cpy = dup(0);
  int i = 0;
  char ** args = calloc(100, sizeof(char *));
  while (command) {
    args[i] = strsep(&command, " ");
    if (strcmp(args[i], "") != 0) {
      i++;
    }
  }
  
  for(int i=0; args[i]; i++){
    if(strcmp(args[i], ">")==0){
      args[i] = 0;
      dup2(open(args[i+1], O_CREAT | O_WRONLY, 0666), 1);
      run(args);
      dup2(stdout_cpy, 1);
      args[i] = " ";
      args[i+1] = " ";
    }

    if(strcmp(args[i], "<")==0){
      args[i] = 0;
      dup2(open(args[i+1], O_CREAT | O_RDONLY, 0666), 0);
      run(args);
      dup2(stdin_cpy, 0);
      args = &args[i];
      args[i] = " ";
      args[i+1] = " ";
    }

  }

  run(args);
    
}


int parse_commands(char * line) {
  char * command = calloc(100, sizeof(char *));
  while (line) {
    command =  strsep(&line, ";");
    
    parse_args(command);
  }
}

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
