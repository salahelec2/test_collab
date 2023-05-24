#include "main.h"

void execmd(char *args[])
{
    pid_t pid;
    char *command;

    if (*args)
    {
        pid = fork();

        if (pid == 0)
        {
            command = args[0];
            execve(command, args, NULL);
            exit(1);
        }
        else if (pid > 0)
        {
            wait(NULL);
        }
        else
        {
            exit(1);
        }
    }
}

int main(void)
{
    size_t n = 0;
    const char *delim = " \n";
    int num_tokens = 0;
    char *env_var = *environ;
    char *lineptr = NULL, *lineptr_copy = NULL;
    ssize_t nchars_read;
    char *token;
    int i;
    char **args;

    while (1)
    {
        _puts(">> ");
        nchars_read = getline(&lineptr, &n, stdin);
        if (nchars_read == -1)
        {
            perror("Error reading input");
            break;
        }
        if (_strcmp(lineptr, "exit\n") == 0)
        {
            _puts("exit the shell\n");
            break;
        }
        if (_strcmp(lineptr, "env\n") == 0)
        {

            while (env_var != NULL)
            {
                _puts(env_var);
                _putchar('\n');
                env_var = *(environ++);
            }
            continue;
        }
        lineptr_copy = malloc(sizeof(char) * nchars_read);
        if (lineptr_copy == NULL)
        {
            perror("tsh: memory allocation error");
            continue;
        }
        _strcpy(lineptr_copy, lineptr);
        token = strtok(lineptr, delim);
        while (token != NULL)
        {
            num_tokens++;
            token = strtok(NULL, delim);
        }
        num_tokens++;
        args = malloc(sizeof(char *) * num_tokens);
        token = strtok(lineptr_copy, delim);

        for (i = 0; token != NULL; i++)
        {
            args[i] = malloc(sizeof(char) * (strlen(token) + 1));
            _strcpy(args[i], token);

            token = strtok(NULL, delim);
        }
        args[i] = NULL;
        execmd(args);

        for (i = 0; i < num_tokens; i++)
        {
            free(args[i]);
        }
        free(args);
        free(lineptr_copy);
        lineptr_copy = NULL;
        num_tokens = 0;
    }

    free(lineptr);

    return 0;
}
