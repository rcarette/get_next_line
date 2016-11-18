/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:04:50 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/17 15:07:41 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*lst_front(t_list *list, void const *content, size_t size)
{
	t_list		*new_link;

	if (list == NULL)
	{
		new_link = ft_lstnew(content, size);
		if (new_link == NULL)
			return (NULL);
	}
	else
	{
		new_link = ft_lstnew(content, size);
		if (new_link == NULL)
			return (NULL);
		new_link->next = list;
	}
	return (new_link);
}
