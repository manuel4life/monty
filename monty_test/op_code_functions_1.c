#include "monty.h"

/**
 * push - opcode pushes an element to the stack
 * @stack: pointer start location in stack
 * @line_number: integer to be pushed
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *top;
	char **tokens;
	int stack_data;
	char *lines = lines;

	tokens = tokenize(lines);
	stack_data = atoi(tokens[1]);

	if (isdigit(stack_data) == 0)
	{
		printf("L%d: usage push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = (stack_t *)malloc(sizeof(stack_t));

	top = NULL;
	new_node = NULL;
	new_node->n = stack_data;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (stack == NULL)
	{
		(*stack) = top;
		top = new_node;
		return;
	}
	top = (*stack);
	while (top->next != NULL)
	{
		top = top->next;
	}
	new_node->prev = top;
	top->next = new_node;
	top = new_node;
}


/**
 * pall - prints all the values on the stack
 * starting from the top of the stack
 * @stack: pointer to start location in stack
 * @line_number: integer to be pushed
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	if (stack == NULL)
		return;
	while ((*stack)->next != NULL)
		(*stack) = (*stack)->next;

	while ((*stack) != NULL)
	{
		printf("%d\n", (*stack)->n);
		(*stack) = (*stack)->prev;
	}
}
