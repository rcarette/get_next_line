/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 11:11:57 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/17 15:00:13 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int		size_s1_s2;

	size_s1_s2 = 0;
	while ((*s1 || *s2) && size_s1_s2 == 0)
	{
		size_s1_s2 = ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (size_s1_s2);
}
