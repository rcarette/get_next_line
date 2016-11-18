/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 15:02:42 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/17 14:59:13 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_realloc(void *ptr, size_t size_ptr, size_t new_size)
{
	void	*pt;
	int		i;

	i = -1;
	if (ptr == NULL)
	{
		pt = malloc(new_size);
		if (pt == NULL)
			return (NULL);
		return (pt);
	}
	else
	{
		pt = (void *)malloc(size_ptr + new_size);
		if (pt == NULL)
			return (NULL);
		ft_memcpy(pt, ptr, ft_strlen(ptr) + 1);
		free(ptr);
		ptr = NULL;
		return (pt);
	}
}
