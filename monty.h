#ifndef MONTY_H
#define MONTY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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

typedef struct gdata_s
{
	FILE *file;
	char *line;
	stack_t *stack;
} gdata_t;

gdata_t gdata;


void open_and_read(char *arg);
void sanitize(void);
void prerror(char *op, int number, int ln);
void prerror2(char *op, int number, int ln);
void getandexecvop(stack_t **stack,char *op, int ln);
void free_stack(stack_t *head);
stack_t *push(stack_t **head, int n);
void pall(stack_t **stack, unsigned int ln);
void pint(stack_t **stack, unsigned int ln);
void add(stack_t **stack, unsigned int ln);
void pchar(stack_t **stack, unsigned int ln);
void pop(stack_t **stack, unsigned int line_number);
int _isdigit(char *number);

void free_code(void);
void init_vars(void);
void free_all(void);
#endif
