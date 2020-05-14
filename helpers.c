#include "monty.h"

/**
  * open_and_read - open fd and read
  * @arg: FILE file
  * Return: VOID
  */
void open_and_read(char *arg)
{
	size_t l = 0;
	ssize_t read;
	unsigned int ln = 1;
	int value;
	char *op, *val;

	gdata.file = fopen(arg, "r");
	if (gdata.file == NULL)
		prerror(arg, -96, ln);
	while ((read = getline(&gdata.line, &l, gdata.file)) != -1)
	{
		op = strtok(gdata.line, " ");
		if (*op == '\n')
		{
			ln += 1;
			continue;
		}
		val = strtok(NULL, " \n");
		op = strtok(op, " \n");
		if (strcmp(op, "push") == 0)
		{
			if (val != NULL)/*/if isnumber*/
			{
				value = atoi(val);
				push(&gdata.stack, value);
				/*printf("%d, ", value);*/
			}
			else
				prerror(op, -129, ln);
		}
		else
		{
			getandexecvop(&gdata.stack, op, ln);
		}
		ln++;
	}
}

/**
  * getandexecvop - get operator and execute
  * @stack: head of stack
  * @op: operator
  * @ln: line number
  *{"pint", pint},
  *{"pop", pop},
  *{"swap", swap},
  *{"nop", nop},
  */
void getandexecvop(stack_t **stack, char *op, int ln)
{
	int i = 0;
	instruction_t getop[] = {
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	for (i = 0; getop[i].opcode; i++)
		if (strcmp(op, getop[i].opcode) == 0)
		{
			getop[i].f(stack, ln);
			return;
		}
	prerror(op, -128, ln);
}
