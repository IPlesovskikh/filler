/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_%.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:48:26 by jbowen            #+#    #+#             */
/*   Updated: 2019/12/15 01:56:50 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_get_value(char *symbols, va_list argp)
{
	t_symbols	save;
	int			i;
	int			count;

	save.precision = 0;
	save.length = 0;
	save.type = 0;
	save.width = 0;
	save.sign = 1;
	save.nul = '.';
	i = 0;
	while (symbols[i] != '\0')
		i++;
	ft_get_type(symbols, &save, &i);
	ft_get_precisions(symbols, &save, &i);
	ft_get_width(symbols, &save, &i);
	ft_get_flags(symbols, &save, &i);
	ft_fill_array_operation();
	count = (*g_operations[(int)save.type])(&save, argp);
	return (count);
}
