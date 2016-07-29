#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <readline/readline.h>
//#include <readline/history.h>
#include <iostream>
using namespace std;

#include "commands.c"

int err = 1;
#define sht_RL_BUFSIZE 1024

char *sht_read_line(void)
{
  int bufsize = sht_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer) {
    fprintf(stderr, "sht: allocation error\n");
    exit(EXIT_FAILURE);
  }

  while (1) {

    c = getchar();

    if (c == EOF || c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;

    // If we have exceeded the buffer, reallocate.
    if (position >= bufsize) {
      bufsize += sht_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "sht: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}

/*char sht_read_line(void)
{
  char *line = NULL;
  ssize_t bufsize = 0; // have getline allocate a buffer for us
  getline(&line, &bufsize, stdin);
  return line;
}*/

#define sht_TOK_BUFSIZE 64
#define sht_TOK_DELIM " \t\r\n\a"
char **sht_split_line(char *line)
{
  int bufsize = sht_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "sht: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, sht_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += sht_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "sht: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, sht_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

int sht_launch(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      printf("sht: Command \"%s\" not found!\n", args[0]);
      err++;
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error forking
    perror("sht");
  } else {
    // Parent process
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

/*
  Builtin function implementations.
*/

int sht_execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }

  for (i = 0; i < sht_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return sht_launch(args);
}

void sht_loop(void)
{
  char *line;
  char **args;
  int status;

  do {
    char cwd[256];
    getcwd(cwd, sizeof(cwd));
    printf("\e[1;31m%d\e[00m|\e[1;32m%s\e[2;1;34m § ", err, cwd);
    printf("\e[00m");
    line = sht_read_line();
    args = sht_split_line(line);
    status = sht_execute(args);
    free(line);
    free(args);
  } while (status);
}
