/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:04:07 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/05 17:13:40 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_width(size_t *count, int len, t_o *op)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (op->s == 's' && op->f[ZERO] && !op->f[REVERSE])
		c = '0';
	while (i < op->w - len)
	{
		if (write(1, &c, 1) < 0)
			return (ERROR);
		i++;
		(*count)++;
	}
	return (TRUE);
}
