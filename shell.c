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
	ssize_t read_chars_count;
	char *env_var = *environ;

	while (1)
	{
		_puts(prompt);
		read_chars_count = getline(&read_line, &n, stdin);
		if (read_chars_count == -1)
		{
			_puts("Finish...\n");
			break;
		}
		if (_strcmp(read_line, "exit") == 0)
		{
			free(read_line);
			exit(0);
		}
		if (_strcmp(read_line, "env") == 0)
		{

			while (env_var != NULL)
			{
				_puts(env_var);
				_putchar('\n');
				env_var = *(environ++);
			}
			continue;
		}

		_puts(read_line);
		_putchar(10);
	}
	free(read_line);
	return (0);
}