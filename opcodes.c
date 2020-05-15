#include "monty.h"

/**
  * push - push data to stack
  * @head: head of linked list stack
  * @n: value
  * Return: head
  */
stack_t *push(stack_t **head, int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t)); /*prompt accurate for malloc*/
	if (!head || !new)
		prerror("malloc", -97, 0);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
		new->prev = NULL;
	else
	{
		new->prev = *head;
		(*head)->next = new;
	}
	*head = new;
	return (*head);
}

/**
  * pall - print stack in stack order
  * @stack: head of stack
  * @ln: line number
  */
void pall(stack_t **stack, unsigned int ln)
{
	stack_t *node = *stack;

	while (node)
	{
		printf("%d\n", node->n);
		node = node->prev;
	}
	(void)ln;
}

/**
  * pint - print head of stack
  * @stack: head of stacl linked list
  * @ln: line number
  */
void pint(stack_t **stack, unsigned int ln)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
		prerror("pint", -98, ln);
}

