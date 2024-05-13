/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_flags_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:44:44 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/05 14:49:13 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	is_flags(char c)
{
	int	result;

	result = TRUE;
	if (c >= 49 && c <= 57)
		result = FALSE;
	if (c == '.')
		result = FALSE;
	return (result);
}

int	decode_flags(char *f, size_t c, int n, t_o *op)
{
	size_t	i;

	while (c < (size_t)n && is_flags(f[c]))
	{
		i = 0;
		while (i < FLAGS_COUNT)
		{
			if (f[c] == FLAGS[i])
				op->f[i] = TRUE;
			i++;
		}
		c++;
	}
	return (c);
}
