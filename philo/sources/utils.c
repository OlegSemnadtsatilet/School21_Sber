/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:11:16 by bmaya             #+#    #+#             */
/*   Updated: 2022/05/08 15:40:08 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

long long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	thread_sleep(long long time)
{
	long long	first_timestamp;

	first_timestamp = get_timestamp();
	while ((get_timestamp() - first_timestamp) < time)
	{
		usleep(50);
	}
}

void	print_action(t_general *general, int philo_number, char *string)
{
	long long	time_from_start;

	pthread_mutex_lock(&general->print_check);
	if (general->death_or_ate_flag)
	{
		pthread_mutex_unlock(&general->print_check);
		return ;
	}
	printf("%lli %d %s\n", get_timestamp() - general->start_time, \
		philo_number, string);
	pthread_mutex_unlock(&general->print_check);
}
