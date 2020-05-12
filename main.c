#include "monty.h"

int main(int argc, char **argv)
{
	FILE *fp;
	//char buf[1024 * 0xa];
	ssize_t read;//, bytes = 0;
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

	//bytes = write(STDOUT_FILENO, &buf[0], bytes);
	return (1);
}
