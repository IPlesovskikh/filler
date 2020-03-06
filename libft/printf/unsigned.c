/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:32:51 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/27 16:33:02 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	unsigned long long	int			ft_get_decimal(t_symbols *save,
		va_list argp)
{
	unsigned long long int	num;

	if (save->length == (int)'h')
		num = (unsigned long long int)(unsigned short int)
				va_arg(argp, unsigned int);
	else if (save->length == (int)'h' + (int)'h')
		num = (unsigned long long int)(unsigned char)va_arg(argp, unsigned int);
	else if (save->length == (int)'l')
		num = (unsigned long long int)va_arg(argp, unsigned long int);
	else if (save->length == (int)'l' + (int)'l')
		num = va_arg(argp, unsigned long long int);
	else
		num = (unsigned long long int)va_arg(argp, unsigned int);
	return (num);
}

int										unsigned_to_string(t_symbols *save,
		va_list argp)
{
	char					*result;
	unsigned long long int	num;
	int						len;
	int						lenght;
	int						count;

	num = ft_get_decimal(save, argp);
	if (num == 0 && save->precision == -1)
	{
		count = save->width;
		while (save->width-- > 0)
			write(1, " ", 1);
		return (count);
	}
	if ((result = ft_itol(num)) == NULL)
		exit(-1);
	len = ft_strlen(result);
	lenght = ((int)len >= save->precision) ? (int)len : save->precision;
	count = (lenght >= save->width) ? lenght : save->width;
	ft_print_unsigned(save, lenght, result, len);
	return (count);
}
