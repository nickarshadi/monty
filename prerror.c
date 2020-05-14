#include "monty.h"

/**
  * prerror - procces error
  * @op: operator
  * @number: index of error
  * @ln: index of executed line
  * Return: VOID
  */
void prerror(char *op, int number, int ln)
{
	if (number == -95)
	{
		dprintf(STDERR_FILENO, "L%u: can't %s an empty stack\n", ln, op);
		sanitize();
		exit(EXIT_FAILURE);
	}
	if (number == -96)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", op);
		exit(EXIT_FAILURE);
	}
	if (number == -97)
	{
		dprintf(STDERR_FILENO, "Error: %s failed\n", op);
		sanitize();
		exit(EXIT_FAILURE);
	}
	if (number == -98)
	{
		dprintf(STDERR_FILENO, "L%u: can't %s, stack empty\n", ln, op);
		sanitize();
		exit(EXIT_FAILURE);
	}
	if (number == -99)
		dprintf(STDERR_FILENO,
		"L%u: can't %s, stack too short\n", ln, op), sanitize(), exit(EXIT_FAILURE);
	if (number == -126)
		dprintf(STDERR_FILENO,
		"L%u: division by zero\n", ln), sanitize(), exit(EXIT_FAILURE);
	if (number == -127)
		dprintf(STDERR_FILENO,
		"L%u: can't %s, value out of range\n", ln, op), sanitize(), exit(EXIT_FAILURE);
	if (number == -128)
		dprintf(STDERR_FILENO,
		"L%d: unknown instruction %s\n", ln, op), sanitize(), exit(EXIT_FAILURE);
	if (number == -129)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", ln);
		sanitize();
		exit(EXIT_FAILURE);
	}
}

void sanitize(void)
{
	fclose(gdata.file);
	free(gdata.line);
	//freestack(gdata.stack);
}
