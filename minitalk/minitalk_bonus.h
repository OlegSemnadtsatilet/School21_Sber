/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:40:03 by bmaya             #+#    #+#             */
/*   Updated: 2022/02/12 15:40:05 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <zconf.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flag
{
	int		flag;
	int		pid;
	int		index;
	int		nulls;
	char	simbol;
}	t_flag;

long long			ft_atoi(const char *str);
void				ft_putnbr_fd(int n, int fd);
int					ft_strlen(const char *str);

#endif