#include "monty.h"

/**
 * getline_input - for process input args
 * @stream: File to be processed
 * Return: Line array processed
 */
char *getline_input(FILE *stream)
{
	char *line = NULL;
	size_t len = 0;
	/* ssize_t nread; */
	/* unsigned int line_number = 1; */
	/* char **lines = (char **)malloc(sizeof(char) * 100); */

	getline(&line, &len, stream);
	/*
	 * while (nread >= 0)
	{
		lines[line_number] = line;
		line_number++;
		nread = getline(&line, &len, stream);
	}
	free(line);
	*/
	return (line);
}
