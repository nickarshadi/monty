#include "monty.h"

data_t data;

/**
  * main - entry point
  * @ac: argument count
  * @av: argument vector
  * Return: 1 on failure 0 on success
  */
int main(int ac, char **av)
{
	data = {NULL, NULL, 1, NULL, 0, NULL, 0}

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, USAGE);
		return (EXIT_FAILURE);
	}

	data->fp = fopen(av[1], "r");
	if (!data()->fp)
	{
		dprintf(STDERR_FILENO, ERR_FILE, av[1]);
	//	free_data(1);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
