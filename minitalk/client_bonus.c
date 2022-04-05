/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:40:11 by bmaya             #+#    #+#             */
/*   Updated: 2022/02/12 16:06:36 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_switch_client = 1;

static void	send_simbol(int pid, unsigned char simbol)
{
	int	bit_count;

	bit_count = 0;
	while (bit_count < 8)
	{
		if (g_switch_client == 1)
		{
			g_switch_client = 0;
			if (simbol << bit_count & 128)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit_count++;
		}
	}
}

static void	send_string(char *pid, char *message)
{
	int	process_id;

	process_id = ft_atoi(pid);
	while (*message)
	{
		send_simbol(process_id, (unsigned char)*message);
		message++;
	}
	send_simbol(process_id, '\0');
}

static void	sig_handler_client(int signal)
{
	static int	bits_counter = 0;

	if (signal == SIGUSR1)
	{
		g_switch_client = 1;
		bits_counter++;
	}
	else if (signal == SIGUSR2)
	{
		ft_putnbr_fd(bits_counter / 8, 1);
		write(1, " bytes received.\n", 17);
		exit(0);
	}
}

static int	check_errors(int argc)
{
	if (argc != 3)
	{
		if (argc > 3)
			write(1, "Please use quotes.\n", 19);
		else if (argc == 2)
			write(1, "Please input message.\n", 22);
		else if (argc == 1)
			write(1, "Please input PID and message.\n", 30);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	struct sigaction	sig_act_client;
	int					string_len;

	if (check_errors(argc) == 1)
		return (1);
	string_len = ft_strlen(argv[2]);
	sig_act_client.sa_handler = sig_handler_client;
	sig_act_client.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig_act_client, NULL);
	sigaction(SIGUSR2, &sig_act_client, NULL);
	if (argc == 3)
	{
		ft_putnbr_fd(string_len, 1);
		write(1, " bytes sent.\n", 13);
		send_string(argv[1], argv[2]);
	}
	return (0);
}
