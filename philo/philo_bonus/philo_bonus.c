/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:34:39 by bmaya             #+#    #+#             */
/*   Updated: 2022/05/23 18:53:39 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_semaphores(t_general *general)
{
	sem_unlink("forks_sem");
	sem_unlink("print_check_sem");
	sem_unlink("death_meal_sem");
	general->forks = sem_open("forks_sem", O_CREAT, S_IRWXU, \
		general->philo_num);
	general->print_check = sem_open("print_check_sem", O_CREAT, \
		S_IRWXU, 1);
	general->death_or_meal_check = sem_open("death_meal_sem", \
		O_CREAT, S_IRWXU, 1);
	if (general->forks <= 0 || general->print_check <= 0 || \
		general->death_or_meal_check <= 0)
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
	if (init_semaphores(&general))
		close_with_message("Error: Semaphores initialization error");
	start_procs(&general);
	close_procs(&general);
	return (0);
}
