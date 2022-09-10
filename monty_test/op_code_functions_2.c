#include "monty.h"

/**
 * pop - opcode removes an element from the stack
 * @stack: pointer start location in stack
 * @line_number: integer to be poped
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *prev_node, *top;

	prev_node = (stack_t *)malloc(sizeof(stack_t));

	top = NULL;
	top->n = 0;

	if (stack == NULL)
	{
		return;
	}
	top = (*stack);
	while (top->next != NULL)
	{
		top = top->next;
	}
	prev_node = top->prev;
	prev_node->next = NULL;
	top->prev = NULL;
}


/**
 * pint - prints the value on the top
 * of the stack, followed by a newline
 * @stack: pointer to start location in stack
 * @line_number: integer to be pushed
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	while ((*stack)->next != NULL)
		(*stack) = (*stack)->next;
	printf("%d\n", (*stack)->n);
}
