/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:59:34 by bmaya             #+#    #+#             */
/*   Updated: 2022/04/06 14:49:08 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	thread_sleep(t_general *general)
{
	long long	first_timestamp;

	first_timestamp = get_timestamp();
	while (get_timestamp() - first_timestamp < general->sleep_time)
		usleep(50);
}

static void	*thread_behavior(void *void_philo)
{
	t_philo		*philo;
	t_general	*general;

	philo = (t_philo *)void_philo;
	general = philo->general;
	eating(philo);
	thread_sleep(general);
	return (0);
}

int	start_threads(t_general *general)
{
	int		number;

	number = 0;
	general->start_time = get_timestamp();
	while (number < general->philo_num)
	{
		pthread_create(&general->philos[number].thread, 0, \
			thread_behavior, &general->philos[number]);
		number++;
	}
	return (0);
}

void	close_threads(t_general *general)
{
	int	number;

	number = 0;
	while (number < general->philo_num)
	{
		pthread_join(general->philos[number].thread, NULL);
		number++;
	}
	number = 0;
	while (number < general->philo_num)
	{
		pthread_mutex_destroy(&general->forks[number]);
		number++;
	}
	pthread_mutex_destroy(&general->print_check);
	pthread_mutex_destroy(&general->death_or_meal_check);
}
