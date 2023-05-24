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
		printf("%s", prompt);
		getline(&read_line, &n, stdin);
		printf("%s\n", read_line);
	}
	free(read_line);
	return (0);
}