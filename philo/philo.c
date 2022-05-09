/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:34:39 by bmaya             #+#    #+#             */
/*   Updated: 2022/05/09 15:55:30 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	turn_on_mutexes(t_general *general)
{
	int	number;

	number = 0;
	while (number < general->philo_num)
	{
		if (pthread_mutex_init(&general->forks[number], 0))
			return (1);
		number++;
	}
	if (pthread_mutex_init(&general->print_check, 0))
		return (1);
	if (pthread_mutex_init(&general->death_or_meal_check, 0))
		return (1);
	return (0);
}

void	fill_philos(t_general *general)
{
	int	number;

	number = 0;
	while (number < general->philo_num)
	{
		general->philos[number].philo_id = number;
		general->philos[number].left_fork = number;
		general->philos[number].right_fork = (number + 1) % general->philo_num;
		general->philos[number].ate_times = 0;
		general->philos[number].last_meal_time = 0;
		general->philos[number].general = general;
		number++;
	}
}

int	fill_general(t_general *general, char **argv)
{
	general->meal_times = -1;
	general->philo_num = ft_atoi(argv[1]);
	general->die_timer = ft_atoi(argv[2]);
	general->eat_time = ft_atoi(argv[3]);
	general->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
	{
		if (ft_atoi(argv[5]) <= 0 && argv[5][0] != '0')
			return (1);
		else
			general->meal_times = ft_atoi(argv[5]);
	}
	general->death_or_ate_flag = 0;
	fill_philos(general);
	return (0);
}

int	main(int argc, char **argv)
{
	t_general	general;

	if (argc != 5 && argc != 6)
		close_with_message("Error: Wrong number of arguments");
	if (check_args(argv) == 1)
		close_with_message("Error: Wrong argument");
	fill_general(&general, argv);
	if (general.meal_times == 0)
		return (0);
	if (general.philo_num <= 0 || general.philo_num > 199 || \
	general.die_timer < 0 || general.eat_time < 0 || general.sleep_time < 0)
		close_with_message("Error: Wrong argument");
	if (turn_on_mutexes(&general))
		close_with_message("Error: Mutex initialization error");
	start_threads(&general);
	close_threads(&general);
	return (0);
}
