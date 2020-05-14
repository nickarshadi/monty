#include "monty.h"

/**
  * getop - get operator and run
  * @op: operator
  * @val: value
  * Return: 0
  */
void (*getop(char *op))(stack_t *head, int v)
{

	instruction_t ins[] = {
	{"push", push},
/**	{"pall", pall},
	{"pint", pint},
	{"swap", swap},
	{"add", add},
	{"nop", nop},*/
	{NULL, NULL}
	};
	int i = 0;

	while (i < 6)
	{
		if (strcmp(op,ins[i].opcode))
		{
		return (ins[i].f);
		}
	i++;
	}	
	printf("%s\n", op);
	return (ins[1].f);
}
