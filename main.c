
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	char *line;
	int fd;
	int ret;

	fd = open("test", O_RDONLY);

	while((ret = get_next_line(fd, &line))) {
		printf("%d, %s\n", ret, line);
	}
	return (0);
}
