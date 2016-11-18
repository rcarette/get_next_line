/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:16:55 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/17 14:53:40 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*temporary;

	new = NULL;
	if (lst && f)
	{
		new = f(lst);
		temporary = new;
		while (lst->next)
		{
			temporary->next = f(lst->next);
			temporary = temporary->next;
			lst = lst->next;
		}
	}
	return (new);
}
