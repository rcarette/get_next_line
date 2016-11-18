/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 22:18:49 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/17 14:50:19 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_print_list(t_list *s1, size_t n)
{
	if (n == 4)
		while (s1)
		{
			ft_putnbr(*(int *)s1->content);
			s1 = s1->next;
			ft_putchar('\n');
		}
	else if (n == 1)
		while (s1)
		{
			ft_putstr(s1->content);
			s1 = s1->next;
			ft_putchar('\n');
		}
	else
		while (s1)
		{
			ft_putnbr(*(double *)s1->content);
			s1 = s1->next;
			ft_putchar('\n');
		}
}
