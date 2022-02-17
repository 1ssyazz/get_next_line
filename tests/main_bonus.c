#include "../get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

int main()
{
	int fd01, fd02, fd03;
	
	fd01 = open("tests/files/part1_test01_with_lines", O_RDONLY);
	fd02 = open("tests/files/part1_test01_with_lines_copy", O_RDONLY);
	fd03 = open("tests/files/part1_test01_with_lines_copy_2", O_RDONLY);

	//FD 01 first line
	printf("FD01 | First Line | FD return %s\n", get_next_line(fd01));
	printf("\n\n");
	
	//FD02 second line
	printf("FD02 | First Line | FD return %s\n", get_next_line(fd02));
	printf("\n\n");
	
	//FD03 third line
	printf("FD03 | First Line | FD return %s\n", get_next_line(fd03));
	printf("\n\n");
	printf("%d\n\n", fd03);
}
