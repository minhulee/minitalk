/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_without_format_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:17:56 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/05 14:49:48 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_without_format(char c)
{
	if (write(1, &c, 1) < 0)
		return (ERROR);
	return (TRUE);
}
