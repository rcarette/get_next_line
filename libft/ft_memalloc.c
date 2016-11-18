/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 19:43:51 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/17 14:54:12 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new_memory;

	if (size > 0)
	{
		new_memory = (void *)malloc(size);
		if (new_memory)
		{
			ft_bzero(new_memory, size);
			return (new_memory);
		}
	}
	return (NULL);
}
