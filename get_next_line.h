/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 18:19:08 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/13 11:36:33 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 15
# include <unistd.h>
# include <stdlib.h>

# define ERR -1
# define SUCCESS 1
# define RETURN return (SUCCESS)
typedef struct		s_struct
{
	int				ret;
	char			board[BUFF_SIZE + 1];
}					t_struct;

int					get_next_line(int const fd, char **line);
int					ft_save(char *board, char **str, int position);
char				*ft_strnew(size_t size);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
#endif
