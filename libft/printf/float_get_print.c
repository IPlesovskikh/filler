/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_get_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:30:41 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/27 16:30:46 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	void	ft_print_float1(t_symbols *save, int lenght,
		int len, char *result)
{
	if (save->sign == -1)
		write(1, "-", 1);
	else if (save->plus == '+')
		write(1, "+", 1);
	else if (save->space == ' ')
		write(1, " ", 1);
	while (save->width-- > lenght)
		write(1, "0", 1);
	write(1, result, len);
	free(result);
}

static	void	ft_print_float2(t_symbols *save, int lenght,
		int len, char *result)
{
	while (save->width-- > lenght)
		write(1, " ", 1);
	if (save->sign == -1)
		write(1, "-", 1);
	else if (save->plus == '+')
		write(1, "+", 1);
	else if (save->space == ' ')
		write(1, " ", 1);
	write(1, result, len);
	free(result);
}

static	void	ft_print_float3(t_symbols *save, int lenght,
		int len, char *result)
{
	if (save->sign == -1)
		write(1, "-", 1);
	else if (save->plus == '+')
		write(1, "+", 1);
	else if (save->space == ' ')
		write(1, " ", 1);
	write(1, result, len);
	free(result);
	while (save->width-- > lenght)
		write(1, " ", 1);
}

void			ft_print_float(t_symbols *save, int lenght,
		int len, char *result)
{
	if (save->minus != '-' && save->nul == '0')
		ft_print_float1(save, lenght, len, result);
	else if (save->minus != '-')
		ft_print_float2(save, lenght, len, result);
	else
		ft_print_float3(save, lenght, len, result);
}

long double		ft_get_float(t_symbols *save, va_list argp)
{
	long double		num;

	if (save->length == (int)'L')
		num = va_arg(argp, long double);
	else
		num = (long double)va_arg(argp, double);
	if (num < 0)
	{
		num = -num;
		save->sign = -1;
	}
	return (num);
}
