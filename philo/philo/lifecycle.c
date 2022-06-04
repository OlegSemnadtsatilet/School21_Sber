/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:21:43 by bmaya             #+#    #+#             */
/*   Updated: 2022/05/19 16:21:54 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	t_general	*general;

	general = philo->general;
	if (philo->philo_id % 2)
	{
		pthread_mutex_lock(&general->forks[philo->left_fork]);
		print_action(general, philo->philo_id + 1, "has taken a left fork");
		pthread_mutex_lock(&general->forks[philo->right_fork]);
		print_action(general, philo->philo_id + 1, "has taken a right fork");
	}
	else
	{
		pthread_mutex_lock(&general->forks[philo->right_fork]);
		if (check_death_ate_flag(general))
			return ;
		print_action(general, philo->philo_id + 1, "has taken a right fork");
		if (general->philo_num == 1)
		{
			alone_hungry_philo(general);
			return ;
		}
		pthread_mutex_lock(&general->forks[philo->left_fork]);
		print_action(general, philo->philo_id + 1, "has taken a left fork");
	}
}

void	eating(t_philo *philo)
{
	t_general	*general;

	general = philo->general;
	if (check_death_ate_flag(general))
		return ;
	take_forks(philo);
	if (check_death_ate_flag(general))
		return ;
	print_action(general, philo->philo_id + 1, "is eating");
	thread_sleep(general->eat_time, general);
	pthread_mutex_lock(&general->death_or_meal_check);
	philo->ate_times++;
	philo->last_meal_time = get_timestamp();
	pthread_mutex_unlock(&general->death_or_meal_check);
	pthread_mutex_unlock(&general->forks[philo->right_fork]);
	pthread_mutex_unlock(&general->forks[philo->left_fork]);
}

void	*thread_behavior(void *void_philo)
{
	t_philo		*philo;
	t_general	*general;

	philo = (t_philo *)void_philo;
	general = philo->general;
	while (1)
	{
		if (check_death_ate_flag(general))
			return (0);
		eating(philo);
		if (check_death_ate_flag(general))
			return (0);
		print_action(general, philo->philo_id + 1, "is sleeping");
		thread_sleep(general->sleep_time, general);
		if (check_death_ate_flag(general))
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
