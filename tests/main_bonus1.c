#include "../get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

int main(int argc, char **argv)
{
	int fd, line_count;
	char *line;
	int	i;
	
	i = 1;
	line_count = 1;
	line = NULL;
	while (fd > 0)
	{
		fd = open(argv[i], O_RDONLY);
		while ((line = get_next_line(fd)))
		{
			printf(" \n [ Return: %s ] | A line has been read #%d => %s\n", line, line_count, line);
			line_count++;
		}
		printf("\n");
		printf("-----------\n EOF has been reached\n");
		i++;
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