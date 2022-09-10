#include "monty.h"

/**
 * nop - does nothing
 * @stack: pointer to start location in stack
 * @line_number: integer to be pushed
 * Return: nothing
 */
void nop(stack_t **stack __attribute__((unused)),
	unsigned int line_number __attribute__((unused)))
{
	exit(EXIT_SUCCESS);
}


/**
 * sub - opcode subtracts two elements at the top of the stack
 * @stack: pointer start location in stack
 * @line_number: integer to be pushed
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *prev_node, *top;
	int count = 0, result;

	prev_node = (stack_t *)malloc(sizeof(stack_t));

	top = NULL;

	if (stack == NULL)
	{
		return;
	}
	top = (*stack);
	while (top->next != NULL)
	{
		top = top->next;
		count++;
	}

	if (count != 0)
		prev_node = top->prev;

	result = top->n - prev_node->n;
	prev_node->n = result;
	prev_node->next = NULL;
	pop(&top, line_number);
}
