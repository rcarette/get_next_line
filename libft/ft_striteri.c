/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 04:25:45 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/17 15:01:33 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *s))
{
	int		i;

	if (s == NULL || f == NULL)
		return ;
	i = -1;
	while (s[++i])
		(*f)(i, &s[i]);
}
