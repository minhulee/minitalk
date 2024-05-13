/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:22:39 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/13 14:43:51 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_kill(pid_t pid, int signal)
{
	if (kill(pid, signal) < 0)
	{
		ft_putstr_fd("invalid pid\n", STDERR_FILENO);
		exit(1);
	}
}

void	end_message(volatile unsigned char *m, int byte)
{
	ft_putstr_fd((char *)m, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	ft_putstr_fd("[END]\n\n", STDOUT_FILENO);
	ft_memset((void *)m, '\0', byte + 1);
}

void	reset_message(volatile unsigned char *m)
{
	ft_putstr_fd((char *)m, STDOUT_FILENO);
	ft_memset((void *)m, '\0', 1023);
}

void	start_message(pid_t	pid)
{
	ft_putstr_fd("[ ", STDOUT_FILENO);
	ft_putnbr_fd(pid, STDOUT_FILENO);
	ft_putstr_fd(" ] :\n", STDOUT_FILENO);
}

void	start_server(pid_t pid)
{
	char	*s;
	int		len;

	s = ft_itoa((int)pid);
	len = ft_strlen(s);
	if (s)
		free(s);
	ft_printf("%s%d",
		"\n\n"
		"/* ************************************* */\n"
		"/*                                       */\n"
		"/*               MINI TALK               */\n"
		"/*                   -                   */\n"
		"/*                                       */\n"
		"/*              PID : ",
		pid
		);
	while (len++ < 19)
		ft_printf(" ");
	ft_printf("%s",
		"*/\n"
		"/*                                       */\n"
		"/* ************************************* */\n"
		"\n"
		);
}
