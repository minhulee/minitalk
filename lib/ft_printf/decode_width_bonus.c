/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_width_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:45:50 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/05 14:49:16 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	is_num(char c)
{
	if (c >= 48 && c <= 57)
		return (TRUE);
	else
		return (FALSE);
}

int	decode_width(char *f, size_t c, int n, t_o *op)
{
	int		w;

	w = 0;
	while (c < (size_t)n)
	{
		if (!is_num(f[c]))
			break ;
		w = w * 10;
		w += f[c] - 48;
		c++;
	}
	if (w == 2147483647 || w < 0)
		return (FALSE);
	op->w = w;
	return (c);
}
