#include "main.h"

/**
 * _puts - prints a string
 * @str: string to print
 * Return: number of char 
 */
int _puts(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		_putchar(str[i]);
	return (i);
}