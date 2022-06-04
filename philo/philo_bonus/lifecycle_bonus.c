/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:21:43 by bmaya             #+#    #+#             */
/*   Updated: 2022/05/23 20:29:25 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(t_philo *philo)
{
	t_general	*general;

	general = philo->general;
	sem_wait(general->forks);
	print_action(general, philo->philo_id + 1, "has taken a fork");
	sem_wait(general->forks);
	print_action(general, philo->philo_id + 1, "has taken a fork");
	print_action(general, philo->philo_id + 1, "is eating");
	thread_sleep(general->eat_time, general);
	sem_wait(general->death_or_meal_check);
	philo->ate_times++;
	printf("philo %d ate %d times\n", philo->philo_id, philo->ate_times);
	philo->last_meal_time = get_timestamp();
	sem_post(general->death_or_meal_check);
	sem_post(general->forks);
	sem_post(general->forks);
}

void	proc_behavior(void *void_philo)
{
	t_philo		*philo;
	t_general	*general;

	philo = (t_philo *)void_philo;
	general = philo->general;
	philo->last_meal_time = get_timestamp();
	pthread_create(&philo->thread, 0, \
		check_ate_and_death, void_philo);
	while (1)
	{
		eating(philo);
		if (check_death_ate_flag(general))
			break ;
		print_action(general, philo->philo_id + 1, "is sleeping");
		thread_sleep(general->sleep_time, general);
		print_action(general, philo->philo_id + 1, "is thinking");
		if (check_death_ate_flag(general))
			break ;
	}
	pthread_join(philo->thread, 0);
	exit (0);
}

int	start_procs(t_general *general)
{
	int		counter;

	counter = 0;
	general->start_time = get_timestamp();
	while (counter < general->philo_num)
	{
		general->philos[counter].pid = fork();
		if (general->philos[counter].pid == 0)
			proc_behavior(&general->philos[counter]);
		else if (general->philos[counter].pid < 0)
			return (1);
		counter++;
	}
	return (0);
}

void	destroy_sems(t_general *general)
{
	sem_close(general->forks);
	sem_close(general->print_check);
	sem_close(general->death_or_meal_check);
	sem_unlink("forks_sem");
	sem_unlink("print_check_sem");
	sem_unlink("death_meal_sem");
}

void	close_procs(t_general *general)
{
	int	counter;
	int	ret;

	counter = 0;
	while (counter < general->philo_num)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			counter = 0;
			while (counter < general->philo_num)
			{
				kill(general->philos[counter].pid, SIGTERM); // под вопросом (philo_id или pid)
				counter++;
			}
			break ;
		}
		counter++;
	}
	destroy_sems(general);
}
