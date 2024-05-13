/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_s_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:38:30 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/08 11:43:37 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	str_len(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	print_string(char *s, size_t *count, t_o *op)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = str_len(s);
	if (op->p >= 0)
		len = (size_t)op->p;
	while (s[i] && i < len)
	{
		if (write(1, &s[i], 1) < 0)
			return (ERROR);
		i++;
		(*count)++;
	}
	return (TRUE);
}

int	print_reverse_s(size_t *count, char *s, int p_len, t_o op)
{
	if (op.f[REVERSE] == FALSE)
	{
		if (print_width(count, p_len, &op) < 0)
			return (ERROR);
		if (print_string(s, count, &op) < 0)
			return (ERROR);
	}
	else
	{
		if (print_string(s, count, &op) < 0)
			return (ERROR);
		if (print_width(count, p_len, &op) < 0)
			return (ERROR);
	}
	return (TRUE);
}

int	print_format_s(char *s, t_o op)
{
	size_t	count;
	int		print_len;

	if (!s)
		s = "(null)";
	if (op.p > str_len(s))
		op.p = str_len(s);
	print_len = measure_len_(str_len(s), op);
	count = 0;
	if (!str_len(s))
	{
		print_len = 0;
		op.p = -1;
	}
	if (print_reverse_s(&count, s, print_len, op) < 0)
		return (ERROR);
	return (count);
}
