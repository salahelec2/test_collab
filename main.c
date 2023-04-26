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
	int len, len2;
	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");

	_printf("Length:[%d, %i] ", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d] ", -762534);
	printf("Negative:[%d]\n", -762534);
	len = _printf("Percent:[%%] ");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d] ", len);
	printf("Len:[%d]\n", len2);

	_printf("Character:[%c] ", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s] ", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Percent:[%%] ");
	printf("Percent:[%%]\n");
	_printf("Unknown:[%i] ", 0100);
	printf("Unknown:[%i]\n", 0100);
	_printf("Unknown:[%i] ", 0);
	printf("Unknown:[%i]\n", 0);
	_printf("Unknown:[%i] ", 100);
	printf("Unknown:[%i]\n", 100);
	_printf("Unknown:[%i] ", -20);
	_printf("Unknown:[%i]\n", -20);
	_printf("Unknown:[%i] ", INT_MAX);
	printf("Unknown:[%i]\n", INT_MAX);
	_printf("Unknown:[%i] ", INT_MIN);
	printf("Unknown:[%i]\n", INT_MIN);

	return (0);
}
