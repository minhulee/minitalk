/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_u_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:38:55 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/08 11:43:49 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_reverse_u(size_t *count, unsigned int n, int p_len, t_o op)
{
	if (op.f[REVERSE] == FALSE)
	{
		if (print_width(count, p_len, &op) < 0)
			return (ERROR);
		if (print_precision(count, base_len(n, DECIMAL, op), &op) < 0)
			return (ERROR);
		if (print_nbr_base(count, n, DECIMAL, op) < 0)
			return (ERROR);
	}
	else
	{
		if (print_precision(count, base_len(n, DECIMAL, op), &op) < 0)
			return (ERROR);
		if (print_nbr_base(count, n, DECIMAL, op) < 0)
			return (ERROR);
		if (print_width(count, p_len, &op) < 0)
			return (ERROR);
	}
	return (TRUE);
}

int	print_format_u(unsigned int n, t_o op)
{
	size_t	count;
	int		print_len;

	count = 0;
	print_len = measure_len_(base_len(n, DECIMAL, op), op);
	if (op.f[ZERO] && (op.p < 0 && op.w > 0) && !op.f[REVERSE])
	{
		op.p = op.w;
		op.w = 0;
	}
	if (print_reverse_u(&count, n, print_len, op) < 0)
		return (ERROR);
	return (count);
}
