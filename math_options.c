
#include "monty.h"

/**
 * sub - The opcode sub subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack:pointer to top of stack
 * @ln: line number
 */
void sub(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = NULL;
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->prev;
	sub = tmp->n - tmp->next->n;
	tmp->n = sub;
	free(tmp->next);
	*stack = tmp;
	tmp->next = NULL;
}
/**
 * _div - The opcode div divides the second top element of the
 * stack by the top element of the stack.
 * @stack:pointer to top of stack
 * @ln: line number
 */
void _div(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = NULL;
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", ln);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->prev;
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		free_all();
		exit(EXIT_FAILURE);
	}

	div = tmp->n / tmp->prev->n;
	tmp->n = div;
	free(tmp->next);
	*stack = tmp;
	tmp->next = NULL;
}
/**
 * _mul - The opcode mul multiplies the second top element of the
 * stack with the top element of the stack.
 * @stack:pointer to top of stack
 * @ln: line number
 */
void _mul(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = NULL;
	int mul;

	if (stack == NULL || *stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->prev;
	mul = tmp->n * tmp->next->n;
	tmp->n = mul;
	free(tmp->next);
	*stack = tmp;
	tmp->next = NULL;
}
/**
 * _mod - The opcode mul multiplies the second top element of the
 * stack with the top element of the stack.
 * @stack:pointer to top of stack
 * @ln: line number
 */
void _mod(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = NULL;
	int mod;

	if (stack == NULL || *stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->prev;
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		free_all();
		exit(EXIT_FAILURE);
	}
	mod = tmp->n % tmp->next->n;
	tmp->n = mod;
	free(tmp->next);
	*stack = tmp;
	tmp->next = NULL;
}

