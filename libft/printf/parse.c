/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:49:02 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/27 16:32:10 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_get_type(char *symbols, t_symbols *save, int *i)
{
	save->type = symbols[--(*i)];
	if (('a' <= symbols[--(*i)] && symbols[(*i)] <= 'z') ||
	('A' <= symbols[(*i)] && symbols[(*i)] <= 'Z'))
	{
		save->length = symbols[(*i)];
		if (('a' < symbols[--(*i)] && symbols[(*i)] < 'z') ||
		('A' < symbols[(*i)] && symbols[(*i)] < 'Z'))
			save->length += symbols[(*i)--];
	}
}

void	ft_get_precisions(char *symbols, t_symbols *save, int *i)
{
	int	dec;

	dec = 1;
	while ('0' <= symbols[(*i)] && symbols[(*i)] <= '9')
	{
		save->precision += (symbols[(*i)--] - '0') * dec;
		dec = (dec == 1) ? 10 : dec * 10;
	}
	if (save->precision != 0 && symbols[(*i)] != '.')
	{
		save->width = save->precision;
		save->precision = 0;
	}
	if (symbols[(*i)] == '.' && save->precision == 0)
		save->precision = -1;
	if (symbols[(*i)] == '.')
		(*i)--;
}

void	ft_get_width(char *symbols, t_symbols *save, int *i)
{
	int	dec;

	dec = 1;
	while ('0' <= symbols[(*i)] && symbols[(*i)] <= '9')
	{
		save->width += (symbols[(*i)--] - '0') * dec;
		dec = (dec == 1) ? 10 : dec * 10;
	}
	if (symbols[++(*i)] == '0')
		save->nul = '0';
	(*i)--;
}

void	ft_get_flags(char *symbols, t_symbols *save, int *i)
{
	save->minus = '.';
	save->plus = '.';
	if (save->nul != '0')
		save->nul = '.';
	save->sharp = '.';
	save->space = '.';
	if (symbols[(*i)] != '%')
	{
		while (symbols[(*i)] != '%')
		{
			if (symbols[(*i)] == '-')
				save->minus = '-';
			if (symbols[(*i)] == '+')
				save->plus = '+';
			if (symbols[(*i)] == '#')
				save->sharp = '#';
			if (symbols[(*i)] == '0')
				save->nul = '0';
			if (symbols[(*i)] == ' ')
				save->space = ' ';
			(*i)--;
		}
	}
}
