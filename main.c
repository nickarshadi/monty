#include "monty.h"

int main(int argc, char **argv)
{
	FILE *fp;
	ssize_t read;
	char *line = NULL;
	size_t len = 0;

	if (!argv[1] || argc != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		perror("Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		printf("%s\n", line);
	}
	free(line);

	return (1);
}
