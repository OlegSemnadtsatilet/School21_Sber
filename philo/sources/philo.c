/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:34:39 by bmaya             #+#    #+#             */
/*   Updated: 2022/05/08 16:44:07 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

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
			if ((str[i][j] < 48 || str[i][j] > 57) && \
			(str[i][j] != '-' && str[i][j] != '+'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_args(t_general *general, char **argv)
{
	if (check_is_numbers(argv))
		return (1);
	if (!argv[1] || !argv[2] || !argv[3] || !argv[4])
		return (1);
	return (0);
}

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
		print_action(general, philo->philo_id + 1, "has taken a right fork");
		if (general->philo_num == 1)
		{
			alone_hungry_philo(general, philo);
			return ;
		}
		pthread_mutex_lock(&general->forks[philo->left_fork]);
		print_action(general, philo->philo_id + 1, "has taken a left fork");
	}
}

void	alone_hungry_philo(t_general *general, t_philo *philo)
{
	while (1)
	{
		if (general->death_or_ate_flag)
			break ;
	}
}

void	eating(t_philo *philo)
{
	t_general	*general;

	general = philo->general;
	if (general->death_or_ate_flag)
		return ;
	take_forks(philo);
	if (general->death_or_ate_flag)
		return ;
	if (general->philo_num == 1)
		alone_hungry_philo(general, philo);
	print_action(general, philo->philo_id + 1, "is eating");
	thread_sleep(general->eat_time);
	pthread_mutex_lock(&general->death_or_meal_check);
	philo->ate_times++;
	philo->last_meal_time = get_timestamp();
	pthread_mutex_unlock(&general->death_or_meal_check);
	pthread_mutex_unlock(&general->forks[philo->right_fork]);
	pthread_mutex_unlock(&general->forks[philo->left_fork]);
}

void	close_with_message(char *message)
{
	printf("%s\n", message);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_general	general;

	if (argc != 5 && argc != 6)
		close_with_message("Error: Wrong number of arguments");
	//if (check_args(&general, argv) == 1)
		//close_with_message("Error: Wrong argument");
	fill_general(&general, argv);
	if (general.philo_num <= 0 || general.philo_num > 322 || \
	general.die_timer < 0 || general.eat_time < 0 || general.sleep_time < 0)
		close_with_message("Error: Wrong argument");
	if (turn_on_mutexes(&general))
		close_with_message("Error: Mutex initialization error");
	start_threads(&general);
	close_threads(&general);
	return (0);
}
