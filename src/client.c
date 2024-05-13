/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 06:49:51 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/14 07:14:18 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>

volatile sig_atomic_t	g_ack_siganl;

static void	handler(int signal)
{
	if (signal == SIGUSR1)
		g_ack_siganl = ACK;
	else if (signal == SIGUSR2)
		g_ack_siganl = ALREADY;
}

static void	send_bit_to_sig(pid_t pid, unsigned char c, int i)
{
	if (((c >> i) & 1) == 0)
		ft_kill(pid, SIGUSR1);
	else
		ft_kill(pid, SIGUSR2);
}

static void	send_bit(pid_t pid, unsigned char c)
{
	int	i;
	int	time;

	i = 7;
	while (i >= 0)
	{
		time = -1;
		g_ack_siganl = NOSIGNAL;
		send_bit_to_sig(pid, c, i);
		while (!g_ack_siganl && time++ < 30)
			usleep(100);
		if (g_ack_siganl == ALREADY)
		{
			ft_putstr_fd("server is already receiving messages.\n",
				STDERR_FILENO);
			exit(1);
		}
		if (g_ack_siganl == ACK)
			i--;
	}
}

static void	send(pid_t pid, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		send_bit(pid, s[i]);
		i++;
	}
	send_bit(pid, 127);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_putstr_fd("invalid argv\n", STDERR_FILENO);
		exit(1);
	}
	pid = ft_atoi(av[1]);
	if (pid < 100 || pid > 99998)
	{
		ft_putstr_fd("invalid pid\n", STDERR_FILENO);
		exit(1);
	}
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	send(pid, av[2]);
	exit(0);
	return (0);
}
