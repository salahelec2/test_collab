#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	printf("%d\n", _printf("Character:[%c]\n", 'H'));

	printf("Character:[%c]\n", 'H');
	printf("%d\n", _printf("String:[%s]\n", "I am a string !"));
	printf("String:[%s]\n", "I am a string !");
	printf("%d\n", _printf("Percent:[%%]\n"));
	printf("Percent:[%%]\n");

	return (0);
}