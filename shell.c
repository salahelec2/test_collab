#include "main.h"

/**
 * main - entry point of the shell
 *
 * Return: 0 on success
 */

int main(void)
{
	char *prompt = ">> ";
	char *read_line = NULL;
	size_t n = 0;

	while (1)
	{
		_puts(prompt);
		getline(&read_line, &n, stdin);
		_puts(read_line);
        _putchar(10);

	}
	free(read_line);
	return (0);
}