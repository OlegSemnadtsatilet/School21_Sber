/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:11:16 by bmaya             #+#    #+#             */
/*   Updated: 2022/04/06 11:38:53 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

long long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_action(t_general *general, int philo_number, char *string)
{
	long long	time_from_start;

	pthread_mutex_lock(&general->print_check);
	printf("%lli %d %s", get_timestamp() - general->start_time, \
	philo_number, string);
	//проверки
	pthread_mutex_unlock(&general->print_check);
}
