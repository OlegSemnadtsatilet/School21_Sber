/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:40:03 by bmaya             #+#    #+#             */
/*   Updated: 2022/03/15 14:11:13 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <zconf.h>

typedef struct s_flag
{
	int		flag;
	int		pid;
}	t_flag;

long long			ft_atoi(const char *str);
void				ft_putnbr_fd(int n, int fd);
int					ft_strlen(const char *str);

#endif