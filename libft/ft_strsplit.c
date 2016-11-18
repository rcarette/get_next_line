/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:23:06 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/17 15:05:33 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		count_the_world(char *str, char c)
{
	int		size_world;
	int		i;

	i = 0;
	size_world = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			++size_world;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (size_world);
}

static void		count_character(char *s, char chararacter, char ***board)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] && s[i] != chararacter)
		{
			while (s[i] && s[i] != chararacter)
			{
				i++;
				j++;
			}
			if (!((*board)[x] = (char *)malloc(sizeof(char) * (j + 1))))
				return ;
			x++;
			j = 0;
		}
		i++;
	}
	if (!((*board)[x] = (char *)malloc(sizeof(char) * (j + 1))))
		return ;
}

static void		insertion(char *s, char chararacter, char ***board)
{
	int		i;
	int		j;
	int		x;

	x = 0;
	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] && s[i] != chararacter)
		{
			while (s[i] && s[i] != chararacter)
				(*board)[x][j++] = s[i++];
			(*board)[x][j++] = '\0';
			j = 0;
			x++;
		}
		else
			i++;
	}
	(*board)[x] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		size_world;
	char		**board;
	int			i;
	int			j;

	if (s == NULL)
		return (NULL);
	i = -1;
	j = 0;
	size_world = count_the_world((char *)s, c);
	if (!(board = (char **)malloc(sizeof(char *) * (size_world + 1))))
		return (NULL);
	count_character((char *)s, c, &board);
	insertion((char *)s, c, &board);
	return (board);
}
