#include "monty.h"
#include "list.h"
/**
 * sub_handler - handles the pint instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */

void sub_handler(stack_t **stack, unsigned int line_number)
{
	int res = 0;
	stack_t *node = NULL;
	stack_t *node_a = get_dnodeint_at_index(*stack, 0);
	stack_t *node_b = get_dnodeint_at_index(*stack, 1);

	(void)stack;
	(void)line_number;
	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SUB_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	res = node_b->n - node_a->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, res);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
* div_handler - handles the pint instruction
* @stack: double pointer to the stack to push to
* @line_number: number of the line in the file
*/
void div_handler(stack_t **stack, unsigned int line_number)
{
	int res = 0;
	stack_t *node = NULL;
	stack_t *node_a = get_dnodeint_at_index(*stack, 0);
	stack_t *node_b = get_dnodeint_at_index(*stack, 1);

	(void)stack;
	(void)line_number;
	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, DIV_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	if (node_a->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	res = node_b->n / node_a->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, res);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}
/**
 * mul_handler - handles the pint instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void mul_handler(stack_t **stack, unsigned int line_number)
{
	int res = 0;
	stack_t *node = NULL;
	stack_t *node_a = get_dnodeint_at_index(*stack, 0);
	stack_t *node_b = get_dnodeint_at_index(*stack, 1);

	(void)stack;
	(void)line_number;
	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MUL_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	res = node_a->n * node_b->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, res);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * mod_handler - handles the pint instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */

void mod_handler(stack_t **stack, unsigned int line_number)
{
	int res = 0;
	stack_t *node = NULL;
	stack_t *node_a = get_dnodeint_at_index(*stack, 0);
	stack_t *node_b = get_dnodeint_at_index(*stack, 1);

	(void)stack;
	(void)line_number;
	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MOD_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	if (node_a->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	res = node_b->n % node_a->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, res);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}
