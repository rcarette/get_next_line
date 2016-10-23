/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 18:22:04 by rcarette          #+#    #+#             */
/*   Updated: 2016/10/23 20:40:26 by rcarette         ###   ########.fr       */
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
		else if ((*str)[j] == '\n')
		{
			(*line)[i] = '\0';
			j++;
			return (1);
		}
	}
	free(*str);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	char			board[BUFF_SIZE];
	size_t			ret;
    static char		*str = NULL;
	char			*temporary;

	ret = 0;
	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, board, BUFF_SIZE)))
	{
		board[ret] = '\0';
		if (str == NULL)
		{
			printf("Passage 1\n");
			str = (char *)malloc(sizeof(char) * strlen(board) + 1);
			if (str == NULL)
				exit(EXIT_FAILURE);
			memcpy(str, board, strlen(board) + 1);
		}
		else
		{
			printf("Passage 2\n");
			if (!(temporary = (char *)malloc(sizeof(char) * strlen(str) + 1)))
				exit(EXIT_FAILURE);
			memcpy(temporary, str, strlen(str) + 1);
			free(str);
			str = NULL;
			str = malloc(sizeof(char) * strlen(temporary) + strlen(board) + 1);
			if (str == NULL)
				exit(EXIT_FAILURE);
			memcpy(str,temporary, strlen(temporary) + 1);
			strcat(str, board);
			free(temporary);
		}
	}
	return (ft_getline(line, &str));
}

int		main(int argc, char **argv)
{
	int		descriptor = 0;
	char	*s1;
	s1 = NULL;
	descriptor = open("test", O_RDONLY);
	while (get_next_line(descriptor, &s1))
	{
		printf("%s\n", s1);
		free(s1);
	}
	free(s1);

	return (0);
}
