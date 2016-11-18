/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:09:32 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/17 15:07:25 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*lst_back(t_list *list, void const *content, size_t size)
{
	t_list		*new_link;
	t_list		*temporary;

	temporary = list;
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
		while (temporary->next != NULL)
			temporary = temporary->next;
		temporary->next = new_link;
	}
	return (list);
}
