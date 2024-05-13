/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_precision_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:45:53 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/05 14:49:15 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	decode_precision(char *f, size_t c, int n, t_o *op)
{
	int		p;

	if (c == (size_t)n)
		return (c);
	if (f[c] != '.')
		return (c);
	c++;
	p = 0;
	while (c < (size_t)n)
	{
		if (!is_num(f[c]))
			break ;
		p = p * 10;
		p += f[c] - 48;
		c++;
	}
	if (p == 2147483647 || p < 0)
		return (FALSE);
	op->p = p;
	return (c);
}
