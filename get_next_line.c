/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 18:22:04 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/16 22:44:01 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_search(char *board, char **stock, char **line)
{
	char	*temporary;
	if ((temporary = ft_strchr(board, '\n')))
	{
		*temporary = '\0';
		if (!(*line = ft_strjoin(*line, board)))
			return (-1);
		if (!(*stock = ft_strdup(temporary + 1)))
			return (-1);
		return (1);
	}
	return (0);
}

int		ft_search_stock(char **stock, char **line)
{
	char	*temporary;

	if ((temporary = ft_strchr(*stock, '\n')))
	{
		*temporary = '\0';
		if (!(*line = ft_strdup(*stock)))
			return (-1);
		*stock = ft_strdup(temporary + 1);
		return (1);
	}
	if (!(*line = ft_strdup(*stock)))
		return (-1);
	*stock = NULL;
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char		*stock = NULL;
	static int		ret;
	char			board[BUFF_SIZE + 1];
	char			*temporary_line;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (ret == 0)
		*line = ft_strnew(1);
	if (stock != NULL)
		if (ft_search_stock(&stock, line))
			return (1);
	while ((ret = read(fd, board, BUFF_SIZE)) > 0)
	{
		board[ret] = '\0';
		if (ft_search(board, &stock, line))
			return (1);
		if (ft_strlen(*line) == 0)
		{
			if (!(*line = ft_strnew(BUFF_SIZE + 1)))
				return (-1);
			ft_memcpy(*line, board, BUFF_SIZE);
		}
		else
		{
			temporary_line = (*line);
			*line = ft_strjoin(*line, board);
			free(temporary_line);
			temporary_line = NULL;
		}
	}
	return (ret < 0 ? -1 : 0);
}
