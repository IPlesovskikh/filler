/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:31:43 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/27 16:31:45 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static long long int	ft_get_octal(t_symbols *save, va_list argp)
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

static char				*ft_convert_octal(t_symbols *save, long long int num)
{
	char				*result;

	if (save->length == (int)'h' + (int)'h')
		result = ft_for_och(num);
	else if (save->length == (int)'h')
		result = ft_for_osh(num);
	else if (save->length == (int)'l' + (int)'l' || save->length == (int)'l')
		result = ft_for_oul(num);
	else
		result = ft_for_o(num);
	return (result);
}

int						octal_to_string(t_symbols *save, va_list argp)
{
	long long int		num;
	char				*result;
	int					lenght;
	int					count;

	num = ft_get_octal(save, argp);
	result = ft_convert_octal(save, num);
	num = ((num == 0 && save->sharp == '#') ||
			(save->precision == -1 && num == 0)) ?
				0 : (long long int)ft_strlen(result);
	if (save->sharp == '#')
		num += 1;
	lenght = (num >= save->precision) ? (int)num : save->precision;
	if (save->sign == -1 || save->plus == '+' || save->space == ' ')
		lenght++;
	count = (lenght >= save->width) ? lenght : save->width;
	ft_print_octal(save, num, result, lenght);
	return (count);
}
