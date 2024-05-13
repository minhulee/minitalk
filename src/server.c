/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 06:49:49 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/14 07:14:29 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_packet	g_packet;

void	confirm_byte(void)
{
	if (g_packet.message[g_packet.bit / 8] == 127)
	{
		end_message(g_packet.message, g_packet.bit / 8);
		ft_kill(g_packet.pid, SIGUSR1);
		g_packet.pid = 0;
		g_packet.bit = -1;
	}
	else if (g_packet.bit / 8 == 1022)
	{
		reset_message(g_packet.message);
		g_packet.bit = -1;
	}
}

static void	handler(int signal, siginfo_t *info, void *old)
{
	(void)old;
	if (info->si_pid < 100)
		return ;
	if (!g_packet.pid)
	{
		g_packet.pid = info->si_pid;
		start_message(g_packet.pid);
	}
	if (g_packet.pid != info->si_pid)
	{
		ft_kill(info->si_pid, SIGUSR2);
		return ;
	}
	if (signal == SIGUSR2)
		g_packet.message[g_packet.bit / 8] |= 1 << (7 - g_packet.bit % 8);
	if ((g_packet.bit + 1) % 8 == 0)
		confirm_byte();
	g_packet.bit++;
	ft_kill(g_packet.pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	info;
	pid_t				pid;

	pid = getpid();
	start_server(pid);
	info.sa_handler = NULL;
	info.sa_sigaction = handler;
	info.sa_flags = SA_SIGINFO;
	sigaddset(&info.sa_mask, SIGUSR1);
	sigaddset(&info.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &info, NULL);
	sigaction(SIGUSR2, &info, NULL);
	while (1)
		pause();
	return (0);
}
