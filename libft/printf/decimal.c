/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:28:54 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/27 16:28:57 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static long long int	ft_get_decimal(t_symbols *save, va_list argp)
{
	long long int	num;

	if (save->length == (int)'h')
		num = (long long int)(short int)va_arg(argp, int);
	else if (save->length == (int)'h' + (int)'h')
		num = (long long int)(char)va_arg(argp, int);
	else if (save->length == (int)'l')
		num = (long long int)va_arg(argp, long int);
	else if (save->length == (int)'l' + (int)'l')
		num = va_arg(argp, long long int);
	else
		num = (long long int)va_arg(argp, int);
	return (num);
}

int						digits_to_string(t_symbols *save, va_list argp)
{
	char			*result;
	long long int	num;
	size_t			num_to_convert;
	int				lenght;
	int				count;

	num = ft_get_decimal(save, argp);
	if (num < 0)
	{
		num++;
		num_to_convert = (size_t)-num + 1;
		save->sign = -1;
	}
	else
		num_to_convert = num;
	result = ft_itol(num_to_convert);
	num = (num_to_convert != 0 || save->precision != -1) ?
			ft_strlen(result) : 0;
	lenght = (num >= save->precision) ? (int)num : save->precision;
	if (save->sign == -1 || save->plus == '+' || save->space == ' ')
		lenght++;
	count = (lenght >= save->width) ? lenght : save->width;
	ft_print_decimal(save, lenght, result, num);
	return (count);
}
