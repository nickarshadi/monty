#include "monty.h"

int main(int argc, char **argv)
{
	int fd;
	char buf[1024 * 0xa];
	ssize_t bytes;

	if (!argv[1] || argc != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == (-1))
	{
		perror("Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}
	bytes = read(fd, &buf[0], 1024);
	bytes = write(STDOUT_FILENO, &buf[0], bytes);
	close(fd);
	return (1);
}
