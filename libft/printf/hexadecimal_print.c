/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:31:23 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/27 16:31:26 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_print_hexa1(t_symbols *save, int lenght, char *result,
		int long long num)
{
	char			*sharp;

	sharp = NULL;
	if (save->type == 'x')
		sharp = "0x";
	else if (save->type == 'X')
		sharp = "0X";
	if (save->sign == -1)
		write(1, "-", 1);
	else if (save->plus == '+')
		write(1, "+", 1);
	else if (save->space == ' ')
		write(1, " ", 1);
	if (save->sharp == '#')
		write(1, sharp, 2);
	while (save->width-- > lenght)
		write(1, "0", 1);
	write(1, result, num);
	free(result);
}

static void	ft_print_hexa2(t_symbols *save, int lenght, char *result,
		int long long num)
{
	char			*sharp;

	sharp = NULL;
	if (save->type == 'x')
		sharp = "0x";
	else if (save->type == 'X')
		sharp = "0X";
	while (save->width-- > lenght)
		write(1, " ", 1);
	if (save->sign == -1)
		write(1, "-", 1);
	else if (save->plus == '+')
		write(1, "+", 1);
	else if (save->space == ' ')
		write(1, " ", 1);
	if (save->sharp == '#')
		write(1, sharp, 2);
	while (save->precision-- > num)
		write(1, "0", 1);
	write(1, result, num);
	free(result);
}

static void	ft_print_hexa3(t_symbols *save, int lenght, char *result,
		int long long num)
{
	char			*sharp;

	sharp = NULL;
	if (save->type == 'x')
		sharp = "0x";
	else if (save->type == 'X')
		sharp = "0X";
	if (save->sign == -1)
		write(1, "-", 1);
	else if (save->plus == '+')
		write(1, "+", 1);
	else if (save->space == ' ')
		write(1, " ", 1);
	if (save->sharp == '#')
		write(1, sharp, 2);
	while (save->precision-- > num)
		write(1, "0", 1);
	write(1, result, num);
	free(result);
	while (save->width-- > lenght)
		write(1, " ", 1);
}

void		ft_print_hexa(t_symbols *save, int lenght, char *result,
		int long long num)
{
	if (save->minus != '-' && save->width > lenght &&
		save->nul == '0' && save->precision == 0)
		ft_print_hexa1(save, lenght, result, num);
	else if (save->minus != '-')
		ft_print_hexa2(save, lenght, result, num);
	else
		ft_print_hexa3(save, lenght, result, num);
}
