#include "monty.h"
/**
* main - monty program
* @ac: number of arguments
* @av: arguments to get to
* Return: always zero
*/


int main(int ac, char **av)
{
	FILE *fd;
    	char *line = NULL;
	int bufsize = 100;
    	size_t len = 0;
    	ssize_t read;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token = NULL;    
	/*unsigned int line_number = 0;*/
	int i = 0;

	if (ac != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: can´t open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	
	read = getline(&line, &len, fd);
	printf("%s\n", line);
		//printf("%s",av[i]);
	{
	token = strtok(line, "\n\t ");
	tokens[i] = token;
	printf("%s este es line1\n", tokens[0]);
	printf("%s este es line1\n", tokens[2]);
	i++;
	printf("%s este es line\n", tokens[0]);
	printf("%s este es tok\n", token);
				
	}
	free(line);
	/*close(fd);*/
	return(EXIT_SUCCESS);

}
