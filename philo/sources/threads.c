/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:59:34 by bmaya             #+#    #+#             */
/*   Updated: 2022/05/08 16:22:54 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	check_ate(t_general *general)
{
	int	counter;

	counter = 0;
	if (general->meal_times == -1)
		return (0);
	pthread_mutex_lock(&general->death_or_meal_check);
	while (counter < general->philo_num && \
	general->philos[counter].ate_times >= general->meal_times)
		counter++;
	if (counter == general->philo_num)
	{
		general->death_or_ate_flag = 1;
		pthread_mutex_unlock(&general->death_or_meal_check);
		return (1);
	}
	pthread_mutex_unlock(&general->death_or_meal_check);
	return (0);
}

void	check_ate_and_death(t_general *general)
{
	int	counter;

	while (1)
	{
		counter = 0;
		while (counter < general->philo_num)
		{
			pthread_mutex_lock(&general->death_or_meal_check);
			if ((get_timestamp() - \
			general->philos[counter].last_meal_time) > general->die_timer)
			{
				print_action(general, counter + 1, "died");
				general->death_or_ate_flag = 1;
				pthread_mutex_unlock(&general->death_or_meal_check);
				return ;
			}
			pthread_mutex_unlock(&general->death_or_meal_check);
			counter++;
		}
		if (check_ate(general))
			return ;
	}
}

int	check_death_ate_flag(t_general *general)
{
	pthread_mutex_lock(&general->death_or_meal_check);
	if (general->death_or_ate_flag == 1)
	{
		pthread_mutex_unlock(&general->death_or_meal_check);
		return (1);
	}
	pthread_mutex_unlock(&general->death_or_meal_check);
	return (0);
}

static void	*thread_behavior(void *void_philo)
{
	t_philo		*philo;
	t_general	*general;

	philo = (t_philo *)void_philo;
	general = philo->general;
	while (1)
	{
		if (general->death_or_ate_flag)
			return (0);
		eating(philo);
		if (general->death_or_ate_flag)
			return (0);
		print_action(general, philo->philo_id + 1, "is sleeping");
		thread_sleep(general->sleep_time);
		if (general->death_or_ate_flag)
			return (0);
		print_action(general, philo->philo_id + 1, "is thinking");
	}
}

int	start_threads(t_general *general)
{
	int		counter;

	counter = 0;
	general->start_time = get_timestamp();
	while (counter < general->philo_num)
	{
		pthread_create(&general->philos[counter].thread, 0, \
			thread_behavior, &general->philos[counter]);
		general->philos[counter].last_meal_time = get_timestamp();
		counter++;
	}
	check_ate_and_death(general);
	return (0);
}

void	close_threads(t_general *general)
{
	int	counter;

	counter = 0;
	while (counter < general->philo_num)
	{
		pthread_join(general->philos[counter].thread, NULL);
		counter++;
	}
	counter = 0;
	while (counter < general->philo_num)
	{
		pthread_mutex_destroy(&general->forks[counter]);
		counter++;
	}
	pthread_mutex_destroy(&general->death_or_meal_check);
	pthread_mutex_destroy(&general->print_check);
}
