#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void execmd(char *argv[]) {
  char *command;

  if (*argv) {
    /* get the command */
    command = argv[0];

    /* check to see if the command is valid */
    if (!command || !strcmp(command, "")) {
      _puts("Error: invalid command\n");
      return;
    }

    /* execute the command with execve */
    if (execve(command, argv, NULL) == -1) {
      perror("Error:");
      return;
    }
  }
}

int main(int ac, char *argv[]) {
  char *prompt = ">> ";
  char *lineptr = NULL, *lineptr_copy = NULL;
  size_t n = 0;
  ssize_t nchars_read;
  const char *delim = " \n";
  int num_tokens = 0;
  char *token;
  int i;
  char **args;
  pid_t pid;
  char *command;

  (void)ac;
  (void)argv;

  while (1) {
    _puts("%s", prompt);
    nchars_read = getline(&lineptr, &n, stdin);
    if (nchars_read == -1) {
      if (lineptr != NULL) {
        free(lineptr);
      }
      _puts("Exiting shell....\n");
      break;
    }

    if (lineptr[nchars_read - 1] == '\n') {
      lineptr[nchars_read - 1] = '\0';
    }

    lineptr_copy = malloc(sizeof(char) * nchars_read);
    if (lineptr_copy == NULL) {
      perror("tsh: memory allocation error");
      break;
    }
    _strcpy(lineptr_copy, lineptr);
    token = strtok(lineptr, delim);
    while (token != NULL) {
      num_tokens++;
      token = strtok(NULL, delim);
    }
    num_tokens++;
    args = malloc(sizeof(char *) * num_tokens);
    token = strtok(lineptr_copy, delim);

    for (i = 0; token != NULL; i++) {
      args[i] = malloc(sizeof(char) * (strlen(token) + 1));
      _strcpy(args[i], token);

      token = strtok(NULL, delim);
    }
    args[i] = NULL;

    

    pid = fork();
    if (pid == 0) {
      /* This is the child process */
      command = args[0];
      execve(command, args, NULL);
      perror("Error:");
      exit(1);
    } else if (pid > 0) {
      /* This is the parent process */
      wait(NULL);
    } else {
      /* Error creating child process */
      perror("Error:");
      exit(1);
    }

    for (i = 0; i < num_tokens; i++) {
      free(args[i]);
    }
    free(args);
    free(lineptr_copy);
    lineptr_copy = NULL;
    num_tokens = 0;
  }

  if (lineptr != NULL) {
    free(lineptr);
  }

  return (0);
}

