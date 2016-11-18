#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
int		main(void)
{
	char	*s1;
	int	fd;
	fd = open("romain", O_RDONLY);
	int		ret;
	while ((ret = get_next_line(fd, &s1)))
	{
		printf("%d -- %s\n", ret, s1);
		free(s1);
	}
	printf("%d -- %s\n", ret, s1);
	close(fd);
	return (0);
}
