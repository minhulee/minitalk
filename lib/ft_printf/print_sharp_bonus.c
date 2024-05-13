/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sharp_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:29:02 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/05 14:49:43 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_sharp(size_t *count, t_o op)
{
	char	*sharp;

	sharp = NULL;
	if (op.s == 'p')
		sharp = ZEROX;
	if (op.s == 'x' && op.f[SHARP])
		sharp = ZEROX;
	if (op.s == 'X' && op.f[SHARP])
		sharp = ZEROXU;
	if (sharp)
	{
		if (write(1, sharp, 2) < 0)
			return (ERROR);
		(*count) += 2;
	}
	(*count) += 0;
	return (FALSE);
}
