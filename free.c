#include "monty.h"

/**
  * free_data - free all allocated data
  * @all: on if freeing all data, else only partially
  */
void free_data(int all)
{
	/* this is freed every loop iteration since getline() allocates each time */
	if (data->line)
	{
		free(data->line);
		data->line = NULL;
		/* words are malloced separately from data()->line by strtow() */
		ffree(data->words);
		data->words = NULL;
	}
	/* this is freed at normal or forced exit */
	if (all)
	{
		if (data->stack)
		{
			free_dlistint(data->stack);
			data->stack = NULL;
		}
		/* not a free, but a clean_up, and this is the perfect place for it */
		if (data->fp)
		{
			fclose(data->fp);
			data->fp = NULL;
		}
	}
}
