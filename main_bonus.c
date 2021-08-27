#include "get_next_line_bonus.h"
#include <stdio.h>

int main()
{
	int fd;
	int fd1;
	int fd2;
	char *ret;

	fd = open ("text.txt", O_RDONLY);
	ret = get_next_line(fd);
	printf("First FD: %s\n", ret);
	fd1 = open ("text1.txt", O_RDONLY);
	ret = get_next_line(fd1);
	printf("Second FD: %s\n", ret);
	fd2 = open ("text2.txt", O_RDONLY);
	ret = get_next_line(fd2);
	printf("Third FD: %s\n", ret);
	ret = get_next_line(fd);
	printf("First FD: %s\n", ret);
	ret = get_next_line(fd1);
	printf("Second FD: %s\n", ret);
	ret = get_next_line(fd2);
	printf("Third FD: %s\n", ret);
	close(fd);
	close(fd1);
	close(fd2);
	return (0);
}
