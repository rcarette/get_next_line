/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 11:52:42 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/12 17:21:09 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_if_null(char const *s1, char const *s2)
{
	char	*s;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 != NULL && s2 != NULL)
	{
		s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (s == NULL)
			return (NULL);
	}
	else if (s1 != NULL && s2 == NULL)
	{
		if (!(s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
			return (NULL);
	}
	else if (s1 == NULL && s2 != NULL)
		if (!(s = (char *)malloc(sizeof(char) * (ft_strlen(s2) + 1))))
			return (NULL);
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	int			i;

	i = -1;
	str = check_if_null(s1, s2);
	if (str != NULL)
	{
		if (s1 != NULL)
			while (*s1)
				str[++i] = *s1++;
		if (s2 != NULL)
			while (*s2)
				str[++i] = *s2++;
		str[++i] = '\0';
		return (str);
	}
	return (NULL);
}
