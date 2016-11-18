/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:19:04 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/17 14:53:56 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*link;

	if (!(link = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	else
	{
		if (content == NULL)
		{
			link->content = NULL;
			link->content_size = 0;
		}
		if (content)
		{
			link->content = (void *)ft_memalloc(content_size);
			link->content = ft_memcpy(link->content, content, content_size);
			link->content_size = content_size;
			link->next = NULL;
		}
	}
	return (link);
}
