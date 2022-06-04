/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:11:16 by bmaya             #+#    #+#             */
/*   Updated: 2022/05/20 15:26:18 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	close_with_message(char *message)
{
	printf("%s\n", message);
	exit (1);
}

long long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	thread_sleep(long long time, t_general *general)
{
	long long	first_timestamp;

	first_timestamp = get_timestamp();
	while ((get_timestamp() - first_timestamp) < time)
	{
		if (check_death_ate_flag(general))
			break ;
		usleep(50);
	}
}

void	print_action(t_general *general, int philo_number, char *string)
{
	sem_wait(general->print_check);
	printf("%lli %d %s\n", get_timestamp() - general->start_time, \
		philo_number, string);
	sem_post(general->print_check);
}
