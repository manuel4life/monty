#ifndef _MONTY_H_
#define _MONTY_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_v - global variables
 * @line
 *
 * Description: global variables used
 */
typedef struct global_v
{
        char *line;
}glb_v;

/* extern unsigned int line_number; */
extern glb_v v_glb;

/* Prototypes */
char **tokenize(char *line_input);
char *getline_input(FILE *stream);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)));
void pop(stack_t **stack, unsigned int line_number __attribute__((unused)));
void pint(stack_t **stack, unsigned int line_number __attribute__((unused)));
void swap(stack_t **stack, unsigned int line_number __attribute__((unused)));
void add(stack_t **stack, unsigned int line_number __attribute__((unused)));
void nop(stack_t **stack __attribute__((unused)),\
                unsigned int line_number __attribute__((unused)));
void sub(stack_t **stack, unsigned int line_number __attribute__((unused)));
void (*comp_opc_func(char *s))(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
