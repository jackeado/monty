#include "monty.h"
#include "list.h"

/**
 * pchar_handler - handles the pchar instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pchar_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp  = *stack;
	int num;

	(void)line_number;
	if (!temp)
	{
		dprintf(STDERR_FILENO, PCHAR_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	num = temp->n;
	if (!isascii(num))
	{
		dprintf(STDERR_FILENO, PCHAR_OUT, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", num);
}

/**
 * pstr_handler - handles the pstr instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pstr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	if (!temp)
	{
		free_all(1);
		putchar('\n');
		return;
	}
	while (temp)
	{
		if (temp->n != 0 && isascii(temp->n))
			putchar(temp->n);
		else
			break;
		temp = temp->next;
	}
	putchar('\n');
}
