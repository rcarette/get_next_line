/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:33:59 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/17 14:55:51 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_memdup(char *s, size_t size)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * size)))
		return (NULL);
	ft_memcpy(str, s, size);
	return (str);
}
