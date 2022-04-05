/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:40:27 by bmaya             #+#    #+#             */
/*   Updated: 2022/03/15 12:44:17 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_flag	g_storage_server;

static void	storage_reset(void)
{
	g_storage_server.index = 0;
	g_storage_server.simbol = 0;
	g_storage_server.nulls = 0;
}

static void	sig_handler_server(int signal, siginfo_t *siginfo, void *context)
{
	g_storage_server.flag = 0;
	(void)context;
	if (g_storage_server.pid == 0 || g_storage_server.pid != siginfo->si_pid)
	{
		storage_reset();
		g_storage_server.pid = siginfo->si_pid;
	}
	g_storage_server.simbol = g_storage_server.simbol | (signal == SIGUSR1);
	g_storage_server.nulls += (signal == SIGUSR2);
	g_storage_server.index++;
	if (g_storage_server.index == 8)
	{
		if (g_storage_server.nulls == 8)
		{
			kill(g_storage_server.pid, SIGUSR2);
			write(1, "\n", 1);
			return ;
		}
		write(1, &g_storage_server.simbol, 1);
		storage_reset();
	}
	else
		g_storage_server.simbol = g_storage_server.simbol << 1;
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
