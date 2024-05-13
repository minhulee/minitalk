/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:22:42 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/13 14:36:25 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

typedef enum e_ack_signal
{
	NOSIGNAL = 0,
	ACK,
	ALREADY
}	t_ack;

typedef struct s_packet
{
	volatile sig_atomic_t	pid;
	volatile sig_atomic_t	bit;
	volatile unsigned char	message[1024];
}	t_packet;

void	ft_kill(pid_t pid, int signal);
void	start_server(pid_t pid);
void	start_message(pid_t	pid);
void	reset_message(volatile unsigned char *m);
void	end_message(volatile unsigned char *m, int byte);

#endif