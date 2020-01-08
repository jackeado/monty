#ifndef _monty_h_
#define _monty_h_
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define buffer_size 1024
#define delim_var " \t\r\n"
#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"
#define PINT_FAIL "L%u: can't pint, stack empty\n"
#define POP_FAIL "L%u: can't pop an empty stack\n"
#define SWAP_FAIL "L%u: can't swap, stack too short\n"
#define ADD_FAIL "L%u: can't add, stack too short\n"
#define SUB_FAIL "L%u: can't sub, stack too short\n"
#define DIV_FAIL "L%u: can't div, stack too short\n"
#define DIV_ZERO "L%u: division by zero\n"
#define MUL_FAIL "L%u: can't mul, stack too short\n"
#define MOD_FAIL "L%u: can't mod, stack too short\n"
#define PCHAR_FAIL "L%u: can't pchar, stack empty\n"
#define PCHAR_OUT "L%u: can't pchar, value out of range\n"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void open_file(char *filename);

/**
 * struct data_s - global vbles
 * @line: the opcode
 * @words: function to handle the opcode
 * @stack: stack
 * @fp: FILE
 * @qflag: flag queue /stack mode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct data_s
{
	char *line;
	char **words;
	stack_t *stack;
	FILE *fp;
	int qflag;
} data_t;

typedef stack_t dlistint_t;
extern data_t data;


/* hsh_readline.c */
char *hsh_readline(int fd);
int hsh_read(char **line, size_t *n, int fd);
int _getchar(int fd);
int alloc_error(char *buffer);
void *hsh_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/* helper_strtok.c */
char **hsh_strtok(char *str);
int count_word(char *s);

int hsh_strlen(char *s);
int hsh_strncmp(char *s1, char *s2, int len);
int hsh_strcmp(char *s1, char *s2);
char *hsh_strconcat(char *s1, char *s2);
int is_delimiter(char c, char *delim);

/* get_func.c */
void (*get_op(char **values))(stack_t **, unsigned int);
void push_handler(stack_t **stack, unsigned int line_number);
void pall_handler(stack_t **stack, unsigned int line_number);

/* handler_funcs1.c */
void pint_handler(stack_t **stack, unsigned int line_number);
void pop_handler(stack_t **stack, unsigned int line_number);
void swap_handler(stack_t **stack, unsigned int line_number);
void add_handler(stack_t **stack, unsigned int line_number);
void nop_handler(stack_t **stack, unsigned int line_number);

/* handler_funcs2.c */
void sub_handler(stack_t **stack, unsigned int line_number);
void div_handler(stack_t **stack, unsigned int line_number);
void mul_handler(stack_t **stack, unsigned int line_number);
void mod_handler(stack_t **stack, unsigned int line_number);

/* handler_funcs3.c */
void rotl_handler(stack_t **stack, unsigned int line_number);
void rotr_handler(stack_t **stack, unsigned int line_number);
void stack_handler(stack_t **stack, unsigned int line_number);
void queue_handler(stack_t **stack, unsigned int line_number);

/* string.c */
void pchar_handler(stack_t **stack, unsigned int line_number);
void pstr_handler(stack_t **stack, unsigned int line_number);
/* free.c */
void free_all(int all);
void free_everything(char **args);
#endif
