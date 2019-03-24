#include "shell.h"

/*======== void run() ==========
Inputs: char ** args
Returns: void

Exits the shell if "exit" provided
Otherwise, forks processes.
Parent process will wait for child process to execute arguments provided and exits when complete.
====================*/
void run(char ** args) {
  if(!strcmp(args[0], "exit"))
    exit(0);
  int status;
  int f = fork();
  if (f) {
    wait(&status);
  }
  else {
    if(!strcmp(args[0],"cd"))
      chdir(args[1]);
    execvp(args[0], args);
    exit(0);
  }
}

/*======== void parse_args() ==========
Inputs: char * command
Returns: void

The function will parse the array named command (which should contain a single executable line) for arguments, pipes and redirections
Takes care of removing extra spaces, chain piping and multiple redirections.
====================*/
void parse_args(char * command) {
  int stdout_cpy = dup(1);
  int stdin_cpy = dup(0);
  int i = 0;
  char ** args = calloc(100, sizeof(char *));
  while (command) {
    args[i] = strsep(&command, " ");
    if (strcmp(args[i], "") != 0)
      i++;

  }
  if(strncmp(args[i-1], "", 1))
    args[i]=0;


  int lowest = 100;

  int fd[2];
  for(int i=0; args[i]; i++){
    pipe(fd);
    if(strcmp(args[i], ">")==0){
      dup2(open(args[i+1], O_CREAT | O_WRONLY, 0666), 1);
      if(i<lowest)
	lowest = i;
    }

    if(strcmp(args[i], "<")==0){
      dup2(open(args[i+1], O_CREAT | O_RDONLY, 0666), 0);
      if(i<lowest)
	lowest = i;
    }

    if(strcmp(args[i], "|")==0){
      args[i] = 0;
      dup2(fd[1], 1);
      run(args);
      close(fd[1]);
      dup2(fd[0], 0);
      args = &args[i+1];
      i = 0;
      dup2(stdout_cpy, 1);
    }

  }
  args[lowest] = 0;

  run(args);
  dup2(stdout_cpy, 1);
  dup2(stdin_cpy, 0);
  close(fd[0]);
}

/*======== void parse_commands() ==========
Inputs: char * line
Returns: void
This function will parse the line by putting each token separated by delim into an array of strings, called commands.
Then parse_args will be called with these commands.
====================*/
void parse_commands(char * line) {
  char * command = calloc(100, sizeof(char *));
  while (line) {
    command =  strsep(&line, ";");
    parse_args(command);
  }
}
