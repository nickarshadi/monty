#include "monty.h"

void exec_stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	settings.queue = false;
}
/**
 * exec_queue - this function executes the queue opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void exec_queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	settings.queue = true;
}

