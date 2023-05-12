#include "monty.h"

/**
 * get_op_func - function to select correct operation function
 * @token: 1st bytecode input (opcode)
 * Return: pointer to correct operation function
 */
void (*get_op_func(char *token))(stack_t **stack, unsigned int line_counter)
{
	instruction_t instruction_s[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", _add},
		{"nop", nop}
	};

	int i = 0;

	while (instruction_s[i].f != NULL)
	{
		if (strcmp(token, instruction_s[i].opcode) == 0)
			return (instruction_s[i].f);
		i++;
	}
	return (NULL);
}

