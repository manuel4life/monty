#include "monty.h"

/**
 * swap - opcode swaps two elements at the top of the stack
 * @stack: pointer start location in stack
 * @line_number: integer to be pushed
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *prev_node, *top, *temp;
	int count = 0;

	prev_node = (stack_t *)malloc(sizeof(stack_t));

	top = NULL;
	temp = NULL;

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
	{
		temp = top;
		prev_node = top->prev;
		top->n = prev_node->n;
		prev_node->n = temp->n;
	}
}


/**
 * add - opcode adds two elements at the top of the stack
 * @stack: pointer start location in stack
 * @line_number: integer to be pushed
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number __attribute__((unused)))
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

	result = top->n + prev_node->n;
	prev_node->n = result;
	prev_node->next = NULL;
	pop(&top, line_number);
}
