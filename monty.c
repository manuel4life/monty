#include "monty.h"

glb_v v_glb;

/**
 * main - entry point
 * @argc: argument count
 * @argv: array of arguments
 * Return: 0 when successful
 */
int main(int argc, char **argv)
{
        FILE *stream;
        unsigned int line_number = 0;
        char **tokens;
        v_glb.line = NULL;

        char *opcode = NULL;
        size_t len = 0;
        ssize_t nread;
        int num;
        stack_t *stack = NULL;

        if (argc != 2 || argv[1] == NULL)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }

        stream = fopen(argv[1], "r");
        if (stream == NULL)
        {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                exit(EXIT_FAILURE);
        }

        while ((nread = getline(&v_glb.line, &len, stream)) != -1)
        {
                ++line_number;
                tokens = tokenize(v_glb.line);
                num = atoi(tokens[1]);
                opcode = tokens[0];
                printf("%d: %s\n", line_number, v_glb.line);
                printf("%s, %d\n", tokens[0], num);
                comp_opc_func(opcode)(&stack, line_number);
        }

        free(v_glb.line);
        fclose(stream);
        exit(EXIT_SUCCESS);
}
