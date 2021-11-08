/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:07:34 by bmaya             #+#    #+#             */
/*   Updated: 2021/11/08 19:23:14 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef MAX_FD
#  define MAX_FD 65535
# endif

char	*get_next_line(int fd);
void	*ft_memmove(void *dst, const void *src, size_t n);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif