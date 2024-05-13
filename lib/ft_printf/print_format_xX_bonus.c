/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_xX_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:39:25 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/08 11:44:13 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_reverse_xux(size_t *count, unsigned int n, int p_len, t_o op)
{
	if (op.f[REVERSE] == FALSE)
	{
		if (print_width(count, p_len, &op) < 0)
			return (ERROR);
		if (print_sharp(count, op) < 0)
			return (ERROR);
		if (print_precision(count, base_len(n, HEXA, op), &op) < 0)
			return (ERROR);
		if (print_nbr_base(count, n, HEXA, op) < 0)
			return (ERROR);
	}
	else
	{
		if (print_sharp(count, op) < 0)
			return (ERROR);
		if (print_precision(count, base_len(n, HEXA, op), &op) < 0)
			return (ERROR);
		if (print_nbr_base(count, n, HEXA, op) < 0)
			return (ERROR);
		if (print_width(count, p_len, &op) < 0)
			return (ERROR);
	}
	return (TRUE);
}

int	print_format_xux(unsigned int x, t_o op)
{
	size_t			count;
	int				print_len;

	count = 0;
	print_len = measure_len_(base_len(x, HEXA, op), op);
	if (!x)
		op.f[SHARP] = FALSE;
	if (op.f[SHARP])
		print_len += 2;
	if (op.f[ZERO] && (op.p < 0 && op.w > 0) && !op.f[REVERSE])
	{
		op.p = op.w;
		if (op.f[SHARP])
			op.p -= 2;
		op.w = 0;
	}
	if (print_reverse_xux(&count, x, print_len, op) < 0)
		return (ERROR);
	return (count);
}
