/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 18:22:04 by rcarette          #+#    #+#             */
/*   Updated: 2016/10/06 00:42:53 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include <fcntl.h>
#include <string.h>

void	ft_realloc(char **ptr, char *s1)
{
	char	*str;
	int		i;

	i = 0;
	if (*ptr == NULL)
	{
		i = 1;
		if (!(*ptr = (char *)malloc(sizeof(char) * strlen(s1) + 1)))
			return ;
		strcpy(*ptr, s1);
	}
	if (i != 1)
	{
		str = (char *)malloc(sizeof(char) * (strlen(s1) + strlen(*ptr) + 1));
		if (str == NULL)
			return ;
		strcpy(str, *ptr);
		strcat(str, s1);
		if (!(*ptr = (char *)malloc(sizeof(char) * (strlen(str) + 1))))
			return ;
		strcpy(*ptr, str);
		free(str);
	}
}

int		ft_getline(char **line, char **str)
{
	int				size_str;
	int				i;
	static int		j = 0;

	i = 0;
	if (*line == NULL)
	{
		size_str = strlen(*str);
		if (!(*line = malloc(sizeof(char) * (size_str + 1))))
			return (-1);
		bzero(*line, size_str + 1);
	}
	while ((*str)[j] != '\0')
	{
		if ((*str)[j] != '\n')
			(*line)[i++] = (*str)[j++];
		else if ((*str)[j] == '\0')
			return (-1);
		else if ((*str)[j] == '\n')
		{
			(*line)[i] = '\0';
			j++;
			return (1);
		}
	}
}

int		get_next_line(int const fd, char **line)
{
	char			board[BUFF_SIZE];
	size_t			ret;
	static char		*str;

	ret = 0;
	if (fd <= 0)
		return (-1);
	while ((ret = read(fd, board, BUFF_SIZE)))
	{
		board[ret] = '\0';
		ft_realloc(&str, board);
	}
	return (ft_getline(line, &str));
}

int		main(int argc, char **argv)
{
	int		fd;

	fd = 0;
	char	*s1;
	(void)argc;
	(void)argv;
	int		i;

	i = 0;

	s1 = NULL;
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			while (get_next_line(fd, &s1))
			{
				printf("%s", s1);
			}
		}
	return (0);
}
