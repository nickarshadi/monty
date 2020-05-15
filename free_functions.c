#include "monty.h"
/**
 * free_list - free_list
 */
void free_code(void)
{
	stack_t *p, *store;

	p = gdata.stack;

	while (p != NULL)
	{
		store = p->next;
		free(p);
		p = store;
	}
}
/**
 * init_vars - init_vars
 */
void init_vars(void)
{
	gdata.stack = NULL;
	gdata.file = NULL;
	gdata.line = NULL;
}
/**
 * free_prog - free_prog
 */
void free_all(void)
{
	if (gdata.file  != NULL)
		fclose(gdata.file);
	if (gdata.line  != NULL)
		free(gdata.line);
	if (gdata.stack != NULL)
		free_code();
}
