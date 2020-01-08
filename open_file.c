#include <stdio.h>
#include "monty.h"
#include "list.h"

/**
 * open_file - handles the pint instruction
 * @filename: double pointer to the stack to push to
 *
 * Return: 1 success 0 failure
 */
void open_file(char *filename)
{
	int line_number = 0;
	size_t len = 0;
	ssize_t read;
	void (*code_func)(stack_t **, unsigned int);


	data.fp = fopen(filename, "r");

	if (!data.fp)
	{
		dprintf(STDERR_FILENO, FILE_ERROR, filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&data.line, &len, data.fp)) != -1)
	{
		line_number++;
		data.words = hsh_strtok(data.line);

		if (*data.words == NULL || data.words[0][0] == '#')
		{
			free_all(0);
			continue;
		}

		code_func = get_op(data.words);
		if (!code_func)
		{
			dprintf(STDERR_FILENO, UNKNOWN, line_number, data.words[0]);
			free_all(1);
			exit(EXIT_FAILURE);
		}
		code_func(&(data.stack), line_number);
		free_all(0);

	}
	free_all(1);
}
