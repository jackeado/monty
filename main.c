#include "monty.h"
data_t data = {NULL, NULL, NULL, NULL, 0};
/**
 * main - handles the pint instruction
 * @argc: double pointer to the stack to push to
 * @argv: number of the line in the file
 *
 * Return: 1 success 0 failure
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	return (EXIT_SUCCESS);
}
