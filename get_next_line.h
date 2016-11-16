/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 18:19:08 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/16 19:19:00 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/includes/libft.h"

int		get_next_line(int const fd, char **line);
int		ft_search(char *board, char **str, char **line);
void	ft_assembly(char **line, char *board);
int		ft_search_stock(char **stock, char **line);
#endif
