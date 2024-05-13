/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_format_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:48:23 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/05 14:49:14 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	reset_options(char *f, int n, t_o *op)
{
	size_t	cursor;

	op->s = f[n - 1];
	op->p = -1;
	op->w = 0;
	cursor = 0;
	while (cursor < FLAGS_COUNT)
	{
		op->f[cursor] = FALSE;
		cursor++;
	}
}

int	decode_format(char *f, int n, va_list args)
{
	t_o		op;
	size_t	cursor;

	reset_options(f, n, &op);
	cursor = 1;
	cursor = decode_flags(f, cursor, n, &op);
	cursor = decode_width(f, cursor, n, &op);
	if (!cursor)
		return (ERROR);
	cursor = decode_precision(f, cursor, n, &op);
	if (!cursor)
		return (ERROR);
	return (print_format(op, args));
}
