/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:59:34 by bmaya             #+#    #+#             */
/*   Updated: 2022/04/06 11:46:51 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static void	*thread_behavior(void *void_philo)
{
	t_philo		*philo;
	t_general	*general;

	philo = (t_philo *)void_philo;
	general = philo->general;
	eating(philo);
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
