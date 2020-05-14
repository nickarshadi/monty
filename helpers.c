#include "monty.h"

/**
  * open_and_read - open fd and read
  * @f: FILE file
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
				//push_stack(&gdata.stack, value);
				printf("%d, ", value);
			}
			else
				prerror(op, -129, ln);
		}
		else
		{
			(void)value;
			//execvop(&gdata.stack, op, ln);
		}
		ln++;
		printf("%s\n",op);
	}
}
