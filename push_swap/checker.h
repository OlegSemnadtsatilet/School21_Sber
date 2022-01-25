/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:24:59 by bmaya             #+#    #+#             */
/*   Updated: 2022/01/19 18:25:26 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

char	*get_next_line(int fd);
void	*ft_memmove(void *dst, const void *src, size_t n);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char*s2, size_t n);

void	csa(t_storage *storage);
void	csb(t_storage *storage);
void	css(t_storage *storage);
void	cpb(t_storage *storage);
void	cpa(t_storage *storage);

void	cra(t_storage *storage);
void	crb(t_storage *storage);
void	crr(t_storage *storage);

void	crra(t_storage *storage);
void	crrb(t_storage *storage);
void	crrr(t_storage *storage);

#endif