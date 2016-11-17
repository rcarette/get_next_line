/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 18:22:04 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/17 01:59:48 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_search(char *board, char **stock, char **line)
{
	char	*t_li;

	if (!(t_li = strchr(board, '\n')))
		return (0);
	*t_li = '\0';
	if (*line == NULL)
	{
		*line = strdup(board);
		*stock = strdup(t_li + 1);
		if (!(*stock || *line))
			return (-1);
		t_li = NULL;
		return (1);
	}
	t_li = *line;
	if (!(*line = malloc(sizeof(char) * (strlen(board) + strlen(t_li)) + 1)))
		return (-1);
	strcpy(*line, t_li);
	strcat(*line, board);
	free(t_li);
	return (1);
}

int		ft_assembly(char **line, char *board)
{
	char	*t_li;

	if (*line == NULL)
	{
		if (!(*line = malloc(sizeof(char) * (strlen(board) + 1))))
			return (-1);
		strcpy(*line, board);
		return (1);
	}
	t_li = *line;
	if (!(*line = malloc(sizeof(char) * (strlen(board) + strlen(t_li) + 1))))
		return (-1);
	strcpy(*line, t_li);
	strcat(*line, board);
	free(t_li);
	return (1);
}

int		ft_search_stock(char **stock, char **line)
{
	char	*t_li;
	char	*temporary;
	printf("%s", *stock);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char		*stock = NULL;
	int				ret;
	char			board[BUFF_SIZE + 1];

	*line = NULL;
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (stock != NULL)
	{
		if (ft_search_stock(&stock, line))
			return (1);
	}
	while ((ret = read(fd, board, BUFF_SIZE)) > 0)
	{
		board[ret] = '\0';
		if (ft_search(board, &stock, line))
			return (1);
		if (!(ft_assembly(line, board)))
			return (-1);
	}
	return (ret < 0 ? -1 : 0);
}
