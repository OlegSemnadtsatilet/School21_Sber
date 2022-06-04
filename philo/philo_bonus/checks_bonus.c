/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:59:34 by bmaya             #+#    #+#             */
/*   Updated: 2022/05/23 20:15:44 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	check_is_numbers(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] < 48 || str[i][j] > 57 || str[i][j] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_args(char **argv)
{
	if (!check_is_numbers(argv))
		return (1);
	if (!argv[1] || !argv[2] || !argv[3] || !argv[4])
		return (1);
	return (0);
}

int	check_ate(t_general *general)
{
	int	counter;

	counter = 0;
	if (general->meal_times == -1)
		return (0);
	sem_wait(general->death_or_meal_check);
	while (counter < general->philo_num && \
	general->philos[counter].ate_times >= general->meal_times)
	{
		printf("%d %d\n", general->philos[counter].ate_times, general->meal_times);
		counter++;
	}
	if (counter == general->philo_num)
	{
		general->death_or_ate_flag = 1;
		sem_post(general->death_or_meal_check);
		return (1);
	}
	sem_post(general->death_or_meal_check);
	return (0);
}

void	*check_ate_and_death(void *void_philo)
{
	t_philo		*philo;
	t_general	*general;

	philo = (t_philo *)void_philo;
	general = philo->general;
	while (1)
	{
		sem_wait(general->death_or_meal_check);
		if ((get_timestamp() - \
			philo->last_meal_time) > general->die_timer)
		{
			print_action(general, philo->philo_id + 1, "died");
			general->death_or_ate_flag = 1;
			sem_wait(general->print_check);
			sem_post(general->death_or_meal_check);
			exit (0);
		}
		sem_post(general->death_or_meal_check);
		usleep(1000);
		if (check_ate(general))
			break ;
	}
	return (0);
}

int	check_death_ate_flag(t_general *general)
{
	sem_wait(general->death_or_meal_check);
	if (general->death_or_ate_flag == 1)
	{
		sem_post(general->death_or_meal_check);
		return (1);
	}
	sem_post(general->death_or_meal_check);
	return (0);
}
