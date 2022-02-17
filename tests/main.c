#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

int main(int argc, char **argv)
{
	int fd, line_count;
	char *line;

	line_count = 1;
	line = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((line = get_next_line(fd)))
		{
			printf(" \n [ Return: %s ] | A line has been read #%d => %s\n", line, line_count, line);
			line_count++;
			free(line);
		}
		printf("\n");
		printf("-----------\n EOF has been reached\n");
		free(line);
		close(fd);
	}
	if (argc == 1)
	{
		while ((line = get_next_line(0)))
		{
			printf("[Return: %s] Line #%d: %s\n", line, line_count, line);
			line_count++;
		}
		printf("\n EOF has been reached\n");
		close(fd);
	}
	return (0);
}