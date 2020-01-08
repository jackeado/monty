#include "monty.h"
#include "list.h"

/**
 * rotl_handler - rotates the stack to the top
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */

void rotl_handler(stack_t **stack, unsigned int line_number)
{
	int n = 0;
	stack_t *temp = *stack, *node = NULL;

	(void)line_number;
	if (!temp)
	{
		free_all(1);
		exit(EXIT_SUCCESS);
	}
	n = temp->n;
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint_end(stack, n);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_SUCCESS);
	}
}

/**
 * rotr_handler - rotates the stack to the bottom
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */

void rotr_handler(stack_t **stack, unsigned int line_number)
{
	int n = 0;
	stack_t *temp = *stack;

	(void)line_number;
	(void)n;
	if (!stack)
	{
		return;
	}
	while (temp)
	{
		if (!temp->next)
		{
			n = temp->n;
			temp->prev->next = NULL;
			free(temp);
			break;
		}
		temp = temp->next;
	}
	add_dnodeint(stack, n);
}
/**
 * stack_handler - sets the format of the data to a stack
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */

void stack_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 0;
}
/**
 * queue_handler - sets the format of the data to a queue
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */

void queue_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 1;
}
