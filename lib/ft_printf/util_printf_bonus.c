/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_printf_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:44:47 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/08 11:43:05 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	measure_len_(int len, t_o op)
{
	if (op.s == 's')
	{
		if (op.p >= 0)
			return (op.p);
		return (len);
	}
	else
	{
		if (len < op.p)
			return (op.p);
		return (len);
	}
}

int	base_len(unsigned long n, int base, t_o op)
{
	int				len;
	unsigned long	filter;

	if (!n && !op.p)
		return (0);
	if (n < 0)
		n *= -1;
	len = 1;
	filter = 1;
	while (filter <= n / base)
	{
		filter *= base;
		len++;
	}
	return (len);
}

char	*apply_base(int base, t_o op)
{
	if (base == DECIMAL)
		return (DECIMAL_BASE);
	if (base == HEXA && op.s == 'X')
		return (HEXA_U_BASE);
	if (base == HEXA)
		return (HEXA_BASE);
	return (NULL);
}

int	print_nbr_base(size_t *count, unsigned long n, int base, t_o op)
{
	unsigned long	filter;
	char			*base_form;

	if (!n && !op.p)
		return (TRUE);
	base_form = apply_base(base, op);
	filter = 1;
	while (filter <= n / base)
		filter *= base;
	while (filter > 0)
	{
		if (write(1, &base_form[n / filter], 1) < 0)
			return (ERROR);
		n %= filter;
		filter /= base;
		(*count)++;
	}
	return (TRUE);
}
