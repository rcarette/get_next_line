/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 18:22:04 by rcarette          #+#    #+#             */
/*   Updated: 2016/10/08 02:32:23 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include <fcntl.h>
#include <string.h>


int		ft_getline(char **line, char **str)
{
	int				i;
	static int		j = 0;

		i = 0;
		if (!(*line = malloc(sizeof(char) * (strlen(*str) + 1))))
			return (-1);
		bzero(*line, strlen(*str) + 1);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	int			i;

	i = -1;
	str = (char *)malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if (str)
	{
		while (*s1)
			str[++i] = *s1++;
		while (*s2)
			str[++i] = *s2++;
		str[++i] = '\0';
		return (str);
	}
	return (NULL);
}

int		get_next_line(int const fd, char **line)
{
	char			board[BUFF_SIZE];
	size_t			ret;
    static char		*str = "";

	ret = 0;
	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, board, BUFF_SIZE)))
	{
		board[ret] = '\0';
		str = ft_strjoin(str, board);
	}
	return (ft_getline(line, &str));
}

int		main(int argc, char **argv)
{
	int		descriptor = open(argv[1], O_RDONLY);
	char	*s1;
	while (get_next_line(descriptor, &s1))
		printf("%s", s1);
	return (0);
}
