#include "main.h"

int main(int ac, char **argv){
    char *prompt = ">> ";
    char *lineptr = NULL, *lineptr_copy = NULL;
    size_t n = 0;
    ssize_t nchars_read;
    const char *delim = " \n";
    int num_tokens = 0;
    char *token;
    int i;

    (void)ac;

    while (1) {
        printf("%s", prompt);
        nchars_read = getline(&lineptr, &n, stdin);
        if (nchars_read == -1){
            printf("Exiting shell....\n");
            break;
        }

        lineptr_copy = malloc(sizeof(char) * nchars_read);
        if (lineptr_copy== NULL){
            perror("tsh: memory allocation error");
            break;
        }
        strcpy(lineptr_copy, lineptr);
        token = strtok(lineptr, delim);
        while (token != NULL){
            num_tokens++;
            token = strtok(NULL, delim);
        }
        num_tokens++;
        char **args = malloc(sizeof(char *) * num_tokens);
        token = strtok(lineptr_copy, delim);

        for (i = 0; token != NULL; i++){
            args[i] = malloc(sizeof(char) * (strlen(token) + 1));
            strcpy(args[i], token);

            token = strtok(NULL, delim);
        }
        args[i] = NULL;
        execmd(args);

        for (i = 0; i < num_tokens; i++) {
            free(args[i]);
        }
        free(args);
        free(lineptr_copy);
        lineptr_copy = NULL;
        num_tokens = 0;
    } 

    free(lineptr);

    return (0);
}