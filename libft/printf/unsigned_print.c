/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:33:16 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/27 16:33:19 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	void	ft_print1(t_symbols *save, int lenght, char *result, int len)
{
	while (save->width-- > (int)lenght)
		write(1, "0", 1);
	write(1, result, len);
	free(result);
}

static	void	ft_print2(t_symbols *save, int lenght, char *result, int len)
{
	while (save->width-- > lenght)
		write(1, " ", 1);
	while (save->precision-- > (int)len)
		write(1, "0", 1);
	write(1, result, len);
	free(result);
}

static	void	ft_print3(t_symbols *save, int lenght, char *result, int len)
{
	while (save->precision-- > (int)len)
		write(1, "0", 1);
	write(1, result, len);
	free(result);
	while (save->width-- > lenght)
		write(1, " ", 1);
}

void			ft_print_unsigned(t_symbols *save, int lenght,
		char *result, int len)
{
	if (save->minus != '-' && save->width > len &&
	save->nul == '0' && save->precision == 0)
		ft_print1(save, lenght, result, len);
	else if (save->minus != '-')
		ft_print2(save, lenght, result, len);
	else
		ft_print3(save, lenght, result, len);
}
