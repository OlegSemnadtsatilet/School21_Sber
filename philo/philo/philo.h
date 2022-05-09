/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:53:56 by bmaya             #+#    #+#             */
/*   Updated: 2022/05/09 15:34:37 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo
{
	int					philo_id;
	int					left_fork;
	int					right_fork;
	int					ate_times;
	long long			last_meal_time;
	struct s_general	*general;
	pthread_t			thread;
}	t_philo;

typedef struct s_general
{
	int				philo_num;
	int				die_timer;
	int				eat_time;
	int				sleep_time;
	int				meal_times;
	int				death_or_ate_flag;
	long long		start_time;
	t_philo			philos[199];
	pthread_mutex_t	forks[199];
	pthread_mutex_t	print_check;
	pthread_mutex_t	death_or_meal_check;
}	t_general;

long long	ft_atoi(const char *str);
int			start_threads(t_general *general);
void		close_threads(t_general *general);
long long	get_timestamp(void);
void		print_action(t_general *general, int philo_number, char *string);
void		eating(t_philo *philo);
void		thread_sleep(long long time, t_general *general);
void		alone_hungry_philo(t_general *general);
void		check_ate_and_death(t_general *general);
int			check_args(char **argv);
void		close_with_message(char *message);
int			check_death_ate_flag(t_general *general);

#endif