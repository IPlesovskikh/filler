/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:31:09 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/27 16:31:12 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static long long int			ft_get_hexadecimal(t_symbols *save,
		va_list argp)
{
	int long long num;

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

static char						*ft_convert_hexadecimal(t_symbols *save,
		int long long num)
{
	char	*result;

	if (save->type == 'x' && save->length == (int)'h')
		result = ft_for_xsh(num);
	else if (save->type == 'x' && save->length == (int)'h' + (int)'h')
		result = ft_for_xch(num);
	else if ((save->type == 'x') && (save->length == (int)'l'
			|| save->length == (int)'l' + (int)'l'))
		result = ft_for_xul(num);
	else if (save->type == 'X' &&
		(save->length == (int)'l' + (int)'l' || save->length == (int)'l'))
		result = ft_for_bigxul(num);
	else if (save->type == 'X' && save->length == (int)'h')
		result = ft_for_bigxsh(num);
	else if (save->type == 'X' && save->length == (int)'h' + (int)'h')
		result = ft_for_bigxch(num);
	else if (save->type == 'X')
		result = ft_for_bigx(num);
	else
		result = ft_for_x(num);
	return (result);
}

int								sixteen_to_string(t_symbols *save, va_list argp)
{
	char			*result;
	int long long	num;
	int				lenght;
	int				count;

	num = ft_get_hexadecimal(save, argp);
	result = ft_convert_hexadecimal(save, num);
	if (num == 0)
		save->sharp = '0';
	num = (num != 0 || save->precision != -1) ?
		(long long int)ft_strlen(result) : 0;
	lenght = (num >= save->precision) ? (int)num : save->precision;
	if (save->sharp == '#')
		lenght += 2;
	if (save->sign == -1 || save->plus == '+' || save->space == ' ')
		lenght++;
	count = (lenght >= save->width) ? lenght : save->width;
	ft_print_hexa(save, lenght, result, num);
	return (count);
}
