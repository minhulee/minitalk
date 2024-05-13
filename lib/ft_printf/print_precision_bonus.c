/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:22:51 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/05 17:14:18 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_precision(size_t *count, int len, t_o *op)
{
	int		i;

	i = 0;
	while (i < op->p - len)
	{
		if (write(1, "0", 1) < 0)
			return (ERROR);
		i++;
		(*count)++;
	}
	return (TRUE);
}
