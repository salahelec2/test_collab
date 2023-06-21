#include "monty.h"

vars var;

#define BUFFER_SIZE 256

/**
 * main - Start LIFO, FILO program
 * @ac: Number of arguments
 * @av: Pointer containing arguments
 * Return: 0 Success, 1 Failed
 */
int main(int ac, char **av)
{
    char *opcode;
    size_t buff_size = BUFFER_SIZE;  
    ssize_t chars_read;

    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    if (start_vars(&var) != 0)
        return (EXIT_FAILURE);

    var.file = fopen(av[1], "r");
    if (!var.file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", av[1]);
        free_all();
        return (EXIT_FAILURE);
    }

    var.buff = malloc(buff_size * sizeof(char));
    if (!var.buff)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        free_all();
        return (EXIT_FAILURE);
    }

    while (fgets(var.buff, buff_size, var.file) != NULL)
    {
        chars_read = strlen(var.buff);

    
        if (chars_read > 0 && var.buff[chars_read - 1] == '\n')
            var.buff[chars_read - 1] = '\0';

        opcode = strtok(var.buff, " \r\t\n");
        if (opcode != NULL)
        {
            if (call_funct(&var, opcode) == EXIT_FAILURE)
            {
                free_all();
                return (EXIT_FAILURE);
            }
        }
        var.line_number++;
    }

    free(var.buff);

    return (EXIT_SUCCESS);
}
