#include "monty.h"

/**
 * comp_opc_func - for getting comparing opcode instructions
 * @s: opcodes
 * Return: nothing
 */
void (*comp_opc_func(char *s))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t opcs[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL}
	};

	while (opcs[i].opcode)
	{
		if (opcs[i].opcode[0] == s[0] && s[1] == '\0')
			return (opcs[i].f);
		i++;
	}
	return (NULL);
}
