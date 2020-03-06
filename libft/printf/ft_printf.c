/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:23:04 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/06 14:23:09 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_validation(const char *s, int i)
{
	i = ft_valid_flag(s, i);
	i = ft_valid_width(s, i);
	i = ft_valid_precision(s, i);
	i = ft_valid_size(s, i);
	i = ft_valid_size(s, i);
	i = ft_valid_type(s, i);
	return (i);
}

int		ft_arg_count(const char *str)
{
	int i;
	int arg_c;

	i = 0;
	arg_c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_validation(str, i + 1) == 1)
			arg_c++;
		i++;
	}
	return (arg_c);
}

int		ft_printf(const char *format, ...)
{
	int		arg_c;
	int		count;
	va_list	argp;

	arg_c = ft_arg_count(format);
	va_start(argp, format);
	count = ft_create_array(format, argp);
	va_end(argp);
	return (count);
}
