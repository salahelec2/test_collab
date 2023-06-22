#include "monty.h"

/**
 * start_vars - Fake rand to jackpoint Giga Millions
 * @var: Global variables to initialize
 * Return: 0 Success, 1 Failed
 */
int start_vars(vars *var)
{
	var->file = NULL;
	var->buffer = NULL;
	var->tmp = 0;
	var->dict = create_instruction();
	if (var->dict == NULL)
		return (EXIT_FAILURE);
	var->head = NULL;
	var->line_number = 1;
	var->MODE = 0;

	return (EXIT_SUCCESS);
}

/**
 * create_instruction - Create new functions dictionary
 * Return: Dictionary pointer
 */
instruction_t *create_instruction()
{
	instruction_t *instruct = malloc(sizeof(instruction_t) * 18);

	if (!instruct)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	instruct[0].opcode = "pall", instruct[0].f = op_pall;
	instruct[1].opcode = "push", instruct[1].f = op_push;
	instruct[2].opcode = "pint", instruct[2].f = op_pint;
	instruct[3].opcode = "pop", instruct[3].f = op_pop;
	instruct[4].opcode = "swap", instruct[4].f = op_swap;
	instruct[5].opcode = "add", instruct[5].f = op_add;
	instruct[6].opcode = "nop", instruct[6].f = NULL;
	instruct[7].opcode = "sub", instruct[7].f = op_sub;
	instruct[8].opcode = "div", instruct[8].f = op_divi;
	instruct[9].opcode = "mul", instruct[9].f = op_mul;
	instruct[10].opcode = "mod", instruct[10].f = op_mod;
	instruct[11].opcode = "pchar", instruct[11].f = op_pchar;
	instruct[12].opcode = "pstr", instruct[12].f = op_pstr;
	instruct[13].opcode = "rotl", instruct[13].f = op_rotl;
	instruct[14].opcode = "rotr", instruct[14].f = op_rotr;
	instruct[15].opcode = "stack", instruct[15].f = op_stack;
	instruct[16].opcode = "queue", instruct[16].f = op_queue;
	instruct[17].opcode = NULL, instruct[17].f = NULL;

	return (instruct);
}

/**
 * function_call - Call Functions
 * @var: Global variables
 * @opcode: Command to execute
 * Return: None
 */
int function_call(vars *var, char *opcode)
{
	int i;

	for (i = 0; var->dict[i].opcode; i++)
		if (strcmp(opcode, var->dict[i].opcode) == 0)
		{
			if (!var->dict[i].f)
				return (EXIT_SUCCESS);
			var->dict[i].f(&var->head, var->line_number);
			return (EXIT_SUCCESS);
		}
	if (strlen(opcode) != 0 && opcode[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			var->line_number, opcode);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}


/**
 * free_all - Clean all program mallocs
 * Return: None
 */
void free_all(void)
{
	if (g_var.buffer != NULL)
		free(g_var.buffer);
	if (g_var.file != NULL)
		fclose(g_var.file);
	free(g_var.dict);
	if (g_var.head != NULL)
	{
		while (g_var.head->next != NULL)
		{
			g_var.head = g_var.head->next;
			free(g_var.head->prev);
		}
		free(g_var.head);
	}
}

/**
 * _isdigit - Clean all program mallocs
 * @string: Num to validate
 * Return: 0 Success, 1 Failed
 */
int _isdigit(char *string)
{
	int i;

	for (i = 0; string[i]; i++)
	{
		if (string[i] < 48 || string[i] > 57)
			return (1);
	}
	return (0);
}
