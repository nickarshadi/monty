#ifndef __MONTY__H
#define __MONTY__H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <errno.h>

#define FAILURE 0
#define USAGE "USAGE: monty file\n"
#define ERR_FILE "Error: Can't open file %s\n"
#define ERR_OPCODE "L%d: unknown instruction %s\n"
#define ERR_MALLOC "Error: malloc failed\n"
#define ERR_PINT "L%d: can't pint, stack empty\n"
#define ERR_PUSH "L%d: usage: push integer\n"
#define ERR_POP "L%d: can't pop an empty stack\n"
#define ERR_SWAP "L%d: can't swap, stack too short\n"
#define ERR_ADD "L%d: can't add, stack too short\n"
#define ERR_SUB "L%d: can't sub, stack too short\n"
#define ERR_DIV "L%d: can't div, stack too short\n"
#define ERR_MUL "L%d: can't mul, stack too short\n"
#define ERR_ZERO "L%d: division by zero\n"
#define ERR_MOD "L%d: can't mod, stack too short\n"
#define ERR_PCHAR "L%d: can't pchar, stack empty\n"
#define ERR_NOCHAR "L%d: can't pchar, value out of range\n"


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

/**
 * struct data - paramater pattern
 * @fp: file pointer
 * @stack: pointer to stack
 * @line_number: number of line in monty file
 * @words: pointer to pointer to words
 * @num_words: number of lines
 * @line: pointer to line (current)
 * @queue_mode: 1 if in queue mode else 0
 * Description: parameter pattern
 */
typedef struct data_s
{
	FILE *fp;
	stack_t *stack;
	unsigned int line_number;
	char **words;
	int num_words;
	char *line;
	int queue_mode;
} data_t;

extern data_t data;
void free_data(int all);

#endif
