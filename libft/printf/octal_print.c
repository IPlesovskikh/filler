/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:31:54 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/27 16:31:56 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	void	ft_print_octal1(t_symbols *save, long long int num,
		char *result)
{
	if (save->sign == -1)
		write(1, "-", 1);
	else if (save->plus == '+')
		write(1, "+", 1);
	else if (save->space == ' ')
		write(1, " ", 1);
	while (save->width-- > num)
		write(1, "0", 1);
	if (save->sharp == '#')
		write(1, "0", 1);
	num = (save->sharp == '#') ? (num - 1) : num;
	write(1, result, num);
	free(result);
}

static	void	ft_print_octal2(t_symbols *save, long long int num,
		char *result, int lenght)
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
	if (save->sharp == '#')
		write(1, "0", 1);
	num = (save->sharp == '#') ? (num - 1) : num;
	write(1, result, num);
	free(result);
}

static	void	ft_print_octal3(t_symbols *save, long long int num,
		char *result, int lenght)
{
	if (save->sign == -1)
		write(1, "-", 1);
	else if (save->plus == '+')
		write(1, "+", 1);
	else if (save->space == ' ')
		write(1, " ", 1);
	while (save->precision-- > num)
		write(1, "0", 1);
	if (save->sharp == '#')
		write(1, "0", 1);
	num = (save->sharp == '#') ? (num - 1) : num;
	write(1, result, num);
	free(result);
	while (save->width-- > lenght)
		write(1, " ", 1);
}

void			ft_print_octal(t_symbols *save, long long int num,
		char *result, int lenght)
{
	if (save->minus != '-' && save->width > lenght &&
		save->nul == '0' && save->precision == 0)
		ft_print_octal1(save, num, result);
	else if (save->minus != '-')
		ft_print_octal2(save, num, result, lenght);
	else
		ft_print_octal3(save, num, result, lenght);
}
