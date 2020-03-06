/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:29:18 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/27 16:29:20 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void						ft_print1(t_symbols *save, int lenght,
		char *result, long long int num)
{
	if (save->sign == -1)
		write(1, "-", 1);
	else if (save->plus == '+')
		write(1, "+", 1);
	else if (save->space == ' ')
		write(1, " ", 1);
	while (save->width-- > lenght)
		write(1, "0", 1);
	write(1, result, num);
	free(result);
}

static void						ft_print2(t_symbols *save, int lenght,
		char *result, long long int num)
{
	while (save->width-- > lenght)
		write(1, " ", 1);
	if (save->sign == -1)
		write(1, "-", 1);
	else if (save->plus == '+')
		write(1, "+", 1);
	else if (save->space == ' ')
		write(1, " ", 1);
	while (save->precision-- > num)
		write(1, "0", 1);
	write(1, result, num);
	free(result);
}

static void						ft_print3(t_symbols *save, int lenght,
		char *result, long long int num)
{
	if (save->sign == -1)
		write(1, "-", 1);
	else if (save->plus == '+')
		write(1, "+", 1);
	else if (save->space == ' ')
		write(1, " ", 1);
	while (save->precision-- > num)
		write(1, "0", 1);
	write(1, result, num);
	free(result);
	while (save->width-- > lenght)
		write(1, " ", 1);
}

void							ft_print_decimal(t_symbols *save, int lenght,
		char *result, long long int num)
{
	if (save->minus != '-' && save->width > lenght &&
		save->nul == '0' && save->precision == 0)
		ft_print1(save, lenght, result, num);
	else if (save->minus != '-')
		ft_print2(save, lenght, result, num);
	else
		ft_print3(save, lenght, result, num);
}
