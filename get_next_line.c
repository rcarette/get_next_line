/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 18:22:04 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/13 12:36:58 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include <fcntl.h>
#include <string.h>

int		ft_search(char *board, char **line)
{
	int		iterator;
	short	i;
	char	*temporary;

	iterator = -1;
	i = 1;
	while (board[++iterator])
		if (board[iterator] == '\n')
		{
			i = -1;
			return (SUCCESS);
		}
	if (i = 1 && *line == NULL)
	{
		if (!(*line = ft_strnew(BUFF_SIZE + 1)))
			return (ERR);
		memcpy(*line, board, (BUFF_SIZE + 1));
	}
	else
	{
		temporary = *line;
		*line = ft_strjoin(temporary, board + i);
		free(temporary);
	}
	return (0);
}

int		ft_assembly_line(char *board, char **line, char **str)
{
	size_t		i;
	char		*temporary;
	char		tab[BUFF_SIZE + 1];

	i = 0;
	if (board[i] == '\n' && board[i + 1] != '\0')
		return (ft_save(board, str, i));
	if (*line != NULL && (board[i] != '\n' && board[i + 1] != '\0'))
	{
		while (board[i] && board[i] != '\n')
		{
			tab[i] = board[i];
			i++;
		}
		tab[i] = '\0';
		temporary = *line;
		*line = ft_strjoin(temporary, tab);
		free(temporary);
		return ((board[i] == '\n' && board[i + 1] == '\0') ? SUCCESS: ft_save(board, str, i));
	}
	if (*line == NULL)
	{
		while (board[i] && board[i] != '\n')
			++i;
		*line = (char *)malloc(sizeof(char) * (i + 1));
		memcpy(*line, board, i);
		(*line)[i] = '\0';
		return ((board[i] == '\n' && board[i + 1] == '\0') ? SUCCESS : ft_save(board, str, i));
	}
	return (((board[i] == '\n' && board[i + 1] == '\0') ? SUCCESS : 0));
}

int		ft_save(char *board, char **str, int position)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = position;
	if (board[position] == '\n')
	{
		++position;
		j = position;
	}
	while (board[position])
		++position;
	if (!((*str) = (char *)malloc(sizeof(char) * (position + 1))))
		return (ERR);
	while (board[j])
	{
		(*str)[i] = board[j];
		++i;
		++j;
	}
	(*str)[i] = '\0';
	return (SUCCESS);
}

int		ft_assembly_str(char **str, char **line)
{
	size_t		i;
	size_t		j;
	size_t		x;
	char		*temporary;

	j = 0;
	i = 0;
	x = 0;
	((*str)[i] == '\n') ? i++ : 0;
	j = i;
	if (*line == NULL)
	{
		while ((*str)[i] && (*str)[i] != '\n')
			++i;
		*line = (char *)malloc(sizeof(char) * (i + 1));
		while ((*str)[j] && (*str)[j] != '\n')
		{
			(*line)[x] = (*str)[j];
			++x;
			++j;
		}
		(*line)[x] = '\0';
		if ((*str)[j] == '\0')
		{
			free(*str);
			*str = NULL;
			return (0);
		}
		else if ((*str)[j] == '\n')
		{
			++j;
			x = 0;
			temporary = ft_strnew(BUFF_SIZE + 1);
			while ((*str)[j])
			{
				temporary[x] = (*str)[j];
				++x;
				++j;
			}
			temporary[x] = '\0';
			free(*str);
			*str = temporary;
		}
	}
	return (SUCCESS);
}

int		get_next_line(int const fd, char **line)
{
	static char		*str = NULL;
	t_struct		s1;
	if(str != NULL)
	{
		if (ft_assembly_str(&str, line) == SUCCESS)
			return (SUCCESS);
	}
	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	while ((s1.ret = read(fd, s1.board, BUFF_SIZE)))
	{
		s1.board[s1.ret] = '\0';
		if (ft_search(s1.board, line) == SUCCESS)
		{
			if (ft_assembly_line(s1.board, line, &str) == SUCCESS)
				return (SUCCESS);
		}
	}
	return (s1.ret);
}

int		main(void)
{
	char	*s1;
	int		descriptor;
	s1 = NULL;
	descriptor = open("romainCarette", O_RDONLY);
	while (get_next_line(descriptor, &s1) == 1)
	{
		printf("%s", s1);
		free(s1);
		s1 = NULL;
	}
	return (0);
}
