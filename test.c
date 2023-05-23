#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

int main(int argc, char *argv[]) {
    char *input_text = NULL;
    size_t input_length = 0;
    const char *delim = " \n";
    char *token = NULL;
    char **args = NULL;
    int status = 0;

    

    while (1) {
        printf(">> ");
        if (getline(&input_text, &input_length, stdin) == -1) {
            perror("getline");
            exit(EXIT_FAILURE);
        }

        // Parse input text into separate arguments
        int arg_count = 0;
        token = strtok(input_text, delim);
        while (token != NULL) {
            args = realloc(args, sizeof(char*) * (arg_count + 1));
            args[arg_count] = token;
            arg_count++;
            token = strtok(NULL, delim);
        }
        args = realloc(args, sizeof(char*) * (arg_count + 1));
        args[arg_count] = NULL;

        // Execute command
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process
            waitpid(pid, &status, 0);
        }

        free(input_text);
        input_text = NULL;
        input_length = 0;
        free(args);
        args = NULL;
    }

    return 0;
}