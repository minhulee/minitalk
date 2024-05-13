/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_di_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:38:55 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/08 11:44:02 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	di_len(long n, t_o op)
{
	int		len;
	long	filter;

	if (!n && !op.p)
		return (0);
	if (n < 0)
		n *= -1;
	len = 1;
	filter = 1;
	while (filter <= n / DECIMAL)
	{
		filter *= DECIMAL;
		len++;
	}
	return (len);
}

char	*apply_sign(long *n, t_o op)
{
	if (*n < 0)
	{
		(*n) *= -1;
		return ("-");
	}
	if (*n >= 0 && op.f[PLUS])
		return ("+");
	if (*n >= 0 && op.f[SPACE])
		return (" ");
	return (NULL);
}

int	print_sign(long *n, size_t *count, t_o op)
{
	char	*sign;

	sign = apply_sign(n, op);
	if (sign)
	{
		if (write(1, sign, 1) < 0)
			return (ERROR);
		(*count)++;
	}
	(*count) += 0;
	return (TRUE);
}

int	print_reverse_di(size_t *count, long n, int p_len, t_o op)
{
	if (op.f[REVERSE] == FALSE)
	{
		if (print_width(count, p_len, &op) < 0)
			return (ERROR);
		if (print_sign(&n, count, op) < 0)
			return (ERROR);
		if (print_precision(count, di_len(n, op), &op) < 0)
			return (ERROR);
		if (print_nbr_base(count, n, DECIMAL, op) < 0)
			return (ERROR);
	}
	else
	{
		if (print_sign(&n, count, op) < 0)
			return (ERROR);
		if (print_precision(count, di_len(n, op), &op) < 0)
			return (ERROR);
		if (print_nbr_base(count, n, DECIMAL, op) < 0)
			return (ERROR);
		if (print_width(count, p_len, &op) < 0)
			return (ERROR);
	}
	return (TRUE);
}

int	print_format_di(int n, t_o op)
{
	size_t	count;
	int		print_len;

	count = 0;
	print_len = measure_len_(di_len(n, op), op);
	if (n < 0 || op.f[PLUS] || op.f[SPACE])
		print_len++;
	if ((op.f[ZERO]) && (op.p < 0 && op.w > 0) && !op.f[REVERSE])
	{
		op.p = op.w;
		if ((n < 0 || op.f[PLUS] || op.f[SPACE]) && op.p > 1)
			op.p -= 1;
		op.w = 0;
	}
	if (print_reverse_di(&count, n, print_len, op) < 0)
		return (ERROR);
	return (count);
}
