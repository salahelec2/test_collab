#include "monty.h"

/**
 * mul - s
 * @stack: Double linked list
 * @line_number: File line execution
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	op_pop(stack, line_number);
}


/**
 * mod - s
 * @stack: Double linked list
 * @line_number: File line execution
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	op_pop(stack, line_number);
}

int is_ascii(int c) {
    return (c >= 0 && c <= 127);
}

/**
 * pchar - s
 * @stack: Double linked list
 * @line_number: File line execution
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if (is_ascii((*stack)->n))
	{
		printf("%c\n", (*stack)->n);
		return;
	}
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * pstr - s
 * @stack: Double linked list
 * @line_number: File line execution
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	if (!stack || !*stack)
	{
		putchar('\n');
		return;
	}
	while (tmp)
	{
		if (tmp->n == 0)
			break;
		if (!is_ascii((tmp)->n))
			break;
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}
