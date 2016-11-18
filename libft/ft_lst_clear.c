/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:24:17 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/17 14:51:32 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lst_clear(t_list **lst)
{
	t_list		*temporary;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		temporary = *lst;
		*lst = (*lst)->next;
		free(temporary);
	}
	*lst = NULL;
}
