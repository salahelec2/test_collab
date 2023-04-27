#include "main.h"

/**
 * init_print_sym - initialize print_sym struct
 *
 * Return: pointer to initialized struct
 */

print_sym_func *init_print_sym(void)
{

	print_sym_func *print_sym;

	print_sym = malloc(sizeof(print_sym_func) * 4);

	print_sym[1].type = "s";
	print_sym[1].f = print_string;
	print_sym[2].type = "i";
	print_sym[2].f = print_integer;
	print_sym[3].type = "d";
	print_sym[3].f = print_integer;
	print_sym[4].type = NULL;
	print_sym[4].f = NULL;

	return (print_sym);
}
