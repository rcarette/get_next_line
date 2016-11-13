/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 02:48:55 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/12 17:13:27 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char		*str;
	size_t		i;

	i = 0;
	str = (char *)s;
	if (n)
		while (i < n)
		{
			*str++ = (unsigned char)c;
			i++;
		}
	return ((void *)s);
}
