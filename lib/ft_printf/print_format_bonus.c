/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:49:36 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/05 14:49:22 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_format(t_o op, va_list args)
{
	int	count;

	count = -1;
	if (op.s == 'c')
		count = print_format_c(va_arg(args, int), op);
	else if (op.s == 's')
		count = print_format_s(va_arg(args, char *), op);
	else if (op.s == 'p')
		count = print_format_p(va_arg(args, void *), op);
	else if (op.s == 'd' || op.s == 'i')
		count = print_format_di(va_arg(args, int), op);
	else if (op.s == 'u')
		count = print_format_u(va_arg(args, unsigned int), op);
	else if (op.s == 'x' || op.s == 'X')
		count = print_format_xux(va_arg(args, unsigned int), op);
	else if (op.s == '%')
		count = print_format_per(op);
	return (count);
}
