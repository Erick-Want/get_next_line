#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd;
	char *ret;

	fd = open ("text.txt", O_RDONLY);
	while (ret = get_next_line(fd))
		printf("%s", ret);
	close(fd);
	return (0);
}
