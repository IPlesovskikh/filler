/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:46:12 by jbowen            #+#    #+#             */
/*   Updated: 2019/12/15 07:51:52 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			char_to_string(t_symbols *save, va_list argp)
{
	char	c;
	int		count;

	count = 1 + save->width;
	count = (save->width > 0) ? --count : count;
	if ((c = (char)va_arg(argp, int)) == '\0')
	{
		while (save->width-- > 1)
			write(1, " ", 1);
		write(1, &c, 1);
		return (count);
	}
	if (save->minus == '-')
	{
		write(1, &c, 1);
		while (save->width-- > 1)
			write(1, " ", 1);
	}
	else
	{
		while (save->width-- > 1)
			write(1, " ", 1);
		write(1, &c, 1);
	}
	return (count);
}

static void	ft_print_string(t_symbols *save, char *result, int lenght)
{
	if (save->minus == '-')
	{
		write(1, result, lenght);
		while (save->width-- > lenght)
			write(1, " ", 1);
	}
	else
	{
		while (save->width-- > lenght)
			write(1, " ", 1);
		write(1, result, lenght);
	}
}

int			string_to_string(t_symbols *save, va_list argp)
{
	char	*result;
	int		lenght;
	int		count;

	if ((result = va_arg(argp, char*)) == NULL)
		result = "(null)";
	if (result[0] == '\0')
	{
		lenght = save->width;
		while (save->width-- > 0)
			write(1, " ", 1);
		return (lenght);
	}
	lenght = ft_strlen(result);
	if (save->precision > 0 && save->precision < lenght)
		lenght = save->precision;
	else if (save->precision == -1 && save->precision < lenght)
		lenght = 0;
	count = (lenght > save->precision && save->precision != 0) ?
	save->precision : lenght;
	if (lenght < save->width)
		count += (save->width - count);
	ft_print_string(save, result, lenght);
	return (count);
}

int			percent_to_string(t_symbols *save, va_list argp)
{
	int		count;
	char	c;

	count = save->width;
	if (argp != NULL)
		count++;
	if (save->width > 0)
		count--;
	c = ' ';
	if (save->minus == '-')
	{
		write(1, "%", 1);
		while (save->width-- > 1)
			write(1, &c, 1);
	}
	else
	{
		if (save->nul == '0')
			c = '0';
		while (save->width-- > 1)
			write(1, &c, 1);
		write(1, "%", 1);
	}
	return (count);
}
