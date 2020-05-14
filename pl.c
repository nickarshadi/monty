#include "monty.h"

/**
  * pl - process line
  * @line: line
  * @i: int counter
  * @file: string file
  * Return: 0
  */
int pl(char *line, int i, stack_t *head)
{
	char *op = NULL, *val = NULL; 
	int v = -1;


	op = strtok(line, " ");
	if (op[0] == '\n')
		return (0);
	val = strtok(NULL, "\n");
	val = strtok(val, " ");
	if (val)
		v = atoi(val);
	getop(op)(head, v);
	return (1);
	(void)i;
}
