#include "monty.h"

vars g_var;

#define BUFFER_SIZE 256

/**
 * main - Stacks, Queues - LIFO, FIFO main program
 * @ac: arguments count
 * @av: argunemt vector / data
 * Return: 0 Success, 1 Failure
 */
int main(int ac, char **av)
{
    ssize_t read_chars;
    size_t buffer_size = BUFFER_SIZE;  
    char *opcode_directive;

    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    if (start_vars(&g_var) != 0)
        return (EXIT_FAILURE);

    g_var.file = fopen(av[1], "r");
    if (!g_var.file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", av[1]);
        free_all();
        return (EXIT_FAILURE);
    }

    g_var.buffer = malloc(buffer_size * sizeof(char));
    if (!g_var.buffer)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_all();
        return (EXIT_FAILURE);
    }

    while (fgets(g_var.buffer, buffer_size, g_var.file) != NULL)
    {
        read_chars = strlen(g_var.buffer);

    
        if (read_chars > 0 && g_var.buffer[read_chars - 1] == '\n')
            g_var.buffer[read_chars - 1] = '\0';

        opcode_directive = strtok(g_var.buffer, " \r\t\n");
        if (opcode_directive != NULL)
        {
            if (function_call(&g_var, opcode_directive) == EXIT_FAILURE)
            {
                free_all();
                return (EXIT_FAILURE);
            }
        }
        g_var.line_number++;
    }

    free(g_var.buffer);

    return (EXIT_SUCCESS);
}
