#include "get_next_line.h"

int		main(void)
{
	int		fd = open("test", O_RDONLY);
	char	*s1;
	
	while (get_next_line(fd, &s1) > 0)
	{
		ft_putendl(s1);
		free(s1);
		s1 = NULL;
	}
	return (0);
}
