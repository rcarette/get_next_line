/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 18:22:04 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/16 17:24:32 by rcarette         ###   ########.fr       */
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
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char		*stock;
	int				ret;
	char			board[BUFF_SIZE + 1];

	if (stock)
		if (ft_search_stock(&stock, line))
			return (1);
	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, board, BUFF_SIZE)) > 0)
	{
		board[ret] = '\0';
		if (ft_search(board, &stock, line))
			return (1);
		*line = ft_strjoin(*line, board);
	}
	if (ret == -1)
		return (0);
	return (ret);
}
