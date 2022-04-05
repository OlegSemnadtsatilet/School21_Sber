/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:40:27 by bmaya             #+#    #+#             */
/*   Updated: 2022/03/16 11:44:59 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

t_flag	g_storage_server;

static void	storage_reset(int index, char simbol, int nulls)
{
	index = 0;
	simbol = 0;
	nulls = 0;
}

static void	sig_handler_server(int signal, siginfo_t *siginfo, void *context)
{
	static char	simbol = 0;
	static int	nulls = 0;
	static int	index = 0;

	g_storage_server.pid = siginfo->si_pid;
	g_storage_server.flag = 0;
	(void)context;
	if (g_storage_server.pid == 0 || g_storage_server.pid != siginfo->si_pid)
	{
		storage_reset(index, simbol, nulls);
		g_storage_server.pid = siginfo->si_pid;
	}
	simbol = simbol | (signal == SIGUSR1);
	nulls += (signal == SIGUSR2);
	index++;
	if (index == 8)
	{
		if (nulls == 8)
		{
			kill(g_storage_server.pid, SIGUSR2);
			write(1, "\n", 1);
			return ;
		}
		write(1, &simbol, 1);
		storage_reset(index, simbol, nulls);
	}
	else
		simbol = simbol << 1;
	g_storage_server.flag = 1;
}

int	main(void)
{
	struct sigaction	sig_act_server;

	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sig_act_server.sa_sigaction = sig_handler_server;
	sig_act_server.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig_act_server, NULL);
	sigaction(SIGUSR2, &sig_act_server, NULL);
	while (1)
	{
		if (g_storage_server.flag == 0)
			continue ;
		else
			g_storage_server.flag = 0;
		kill(g_storage_server.pid, SIGUSR1);
	}
	return (0);
}
