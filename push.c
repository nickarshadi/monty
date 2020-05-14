#include "monty.h"

/**
 * _push- push ellements to the stack
 * @stack: stack
 * @line_number: line number in the file
 * Return: noothing
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t * element, *head = NULL;
	char *n = NULL;
	if (!stack)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	element = malloc(sizeof(stack_t));
	if (!element)
		exit(EXIT_FAILURE);
	element->prev = NULL;
	element->n = atoi(n);
	element->next = *stack;
	if (*stack)
		head->prev = element;
		*stack = element;

}
