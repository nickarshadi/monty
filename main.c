#include "monty.h"

/**
  * main - run monty bytecode
  * @argc: number of arguments
  * @argv: Array of argument strings
  * Return: 1
  */
int main(int argc, char **argv)
{
	FILE *fp;
	ssize_t read;
	char *line = NULL;
	size_t len = 0;
	int i;

	if (!argv[1] || argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		i++;
		printf("%s", line);
	}
	free(line);

	return (1);
}
