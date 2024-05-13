/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_per_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:39:09 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/05 14:49:31 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_format_per(t_o op)
{
	size_t	count;

	count = 1;
	if (op.f[REVERSE] == FALSE)
	{
		if (print_width(&count, 1, &op) < 0)
			return (ERROR);
		if (write(1, "%", 1) < 0)
			return (ERROR);
	}
	else
	{
		if (write(1, "%", 1) < 0)
			return (ERROR);
		if (print_width(&count, 1, &op) < 0)
			return (ERROR);
	}
	return (count);
}
