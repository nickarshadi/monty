#include "monty.h"
/**
 * add - a function that add the elements of the input parameters.
 * @stack: pointer to the top of the stack
 * @ln: number of the line.
 */
void add(stack_t **stack, unsigned int ln)
{
	stack_t *temp = NULL;
	int add;
	if (stack == NULL || *stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		free_all();
	}
	temp = (*stack)->prev;
	add = temp->n + temp->next->n;
	temp->n = add;
	free(temp->next);
	*stack = temp;
	temp->next = NULL;
}
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to the top of the stack
 * @ln: number of the line
 */
void pchar(stack_t **stack, unsigned int ln)
{
	int ch = 0;
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
		free_all();
	}
	ch = (*stack)->n;
	if (ch < 0 || ch > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
		free_all();
	}
	putchar(ch);
	putchar(10);
}

/**
 * pop - The opcode pop removes the top element of the stack.
 * @stack: pointer to top of stack
 * @line_number: number of line.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (stack == NULL)
		return;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->prev != NULL)
	{
		temp->prev->next = NULL;
	}
	*stack = (*stack)->prev;
	free(temp);
}

/**
 * _isdigit - checks for a digit (0 through 9)
 * @number: pointer to a number
 * Return: 1 if @number is a numbe, 0 if it's not
 */
int _isdigit(char *number)
{
	int i = 0;
	if (number == NULL)
		return (0);
	if (number[0] == '-')
		i++;
	for (; number[i] != '\0'; i++)
	{
		if (number[i] < '0' || number[i] > '9')
			return (0);
	}
	return (1);
}
