# systems-project1
shell
by Taaseen Ali and Richard Wong

## Features:
*	Forks and executes commands!
*	Parses multiple commands on one line!
*	Redirects using >, <, with multiple redirects (mimicking linux functionality)!
*  Can handle multiple pipes (cmd | cmd | cmd ...) at a time
*  Ignores extra whitespace
*  Can cd and exit

## Attempted:
*  Fixing the exit bug which causes multiple "shell$" prompts to be displayed before exiting
*  Implementing ">>" and "<<"
*  Allowing for piping to work without having to include a space between pipes eg. "ls|wc" vs "ls | wc"

## Bugs:
*	Requires at least one space between commands
*	Putting two ;'s next to each other will break the parser
*  Exiting under certain circumstances will cause the "shell$" prompt to be shown multiple times
*  Calling cd under certain circumstances will cause the "shell$" prompt to be shown multiple times

## Files & Function Headers:
shell_utils.c\
  Handles line parsing, forking processes, executing commands\ 
  
  /*======== void run() ==========\
  Inputs: char ** args\
  Returns: void

  Exits the shell if "exit" provided\
  Otherwise, forks processes.\
  Parent process will wait for child process to execute arguments provided and exits when complete.\
  ====================*/
  
  /*======== void parse_args() ==========\
  Inputs: char * command\
  Returns: void

  The function will parse the array named command (which should contain a single executable line) for arguments, pipes and redirection\
  Takes care of removing extra spaces, chain piping and multiple redirection.\
  ====================*/
  
  /*======== void parse_commands() ==========\
  Inputs: char * line\
  Returns: void

  This function will parse the line by putting each token separated by delim into an array of strings, called commands.\
  Then parse_args will be called with these commands.\
  ====================*/
  
shell.c\
    Processes command line input\
