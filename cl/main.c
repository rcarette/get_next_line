#include "get_next_line.h"

int		main(void)
{
	int		fd = open("romainCarette", O_RDONLY);
	char	*s1;

	get_next_line(fd, &s1);
	ft_putstr(s1);
	free(s1);
	s1 = NULL;
	get_next_line(fd, &s1);
	ft_putstr(s1);
	free(s1);
	s1 = NULL;
	get_next_line(fd, &s1);
	ft_putstr(s1);
	free(s1);
	s1 = NULL;
	return (0);
}
