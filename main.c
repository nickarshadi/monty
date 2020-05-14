#include "monty.h"
gdata_t gdata;

/**
  * main - entry point
  * @argc: amount of arguments
  * @argv: Array of arguments strings
  * Return: Exit_Success
  */
int main(int argc, char **argv)
{
	gdata.file = NULL;
	gdata.line = NULL;
	gdata.stack = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_and_read(argv[1]);
	sanitize();

	return (EXIT_SUCCESS);
}
