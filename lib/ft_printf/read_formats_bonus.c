/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_formats_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 08:38:21 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/05 14:49:50 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	next_format(char *formats)
{
	size_t	i;
	size_t	cursor;

	i = 1;
	while (formats[i])
	{
		cursor = 0;
		while (cursor < SPEC_COUNT)
		{
			if (formats[i] == SPECIFIER[cursor])
				return (i + 1);
			cursor++;
		}
		i++;
	}
	return (ERROR);
}

int	read_fomat(char *f, size_t *n, size_t c, va_list args)
{
	int	count;

	*n = next_format(f + c);
	if (*n < 0)
		return (ERROR);
	count = decode_format(f + c, *n, args);
	if (count < 0)
		return (ERROR);
	return (count);
}

int	read_formats(char *formats, va_list args)
{
	int		total;
	int		count;
	size_t	next;
	size_t	cursor;

	total = 0;
	cursor = 0;
	while (formats[cursor])
	{
		if (formats[cursor] == '%')
		{
			count = read_fomat(formats, &next, cursor, args);
			if (count < 0)
				return (ERROR);
			total += count;
			cursor += next;
			continue ;
		}
		if (print_without_format(formats[cursor]) < 0)
			return (ERROR);
		total++;
		cursor++;
	}
	return (total);
}
