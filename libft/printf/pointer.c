/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:32:17 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/27 16:32:20 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_print_pointer1(t_symbols *save, long long int num,
		char *result, long long int temp)
{
	while (save->width-- > num)
		write(1, "0", 1);
	write(1, "0x", 2);
	if (temp != 0)
		write(1, result, (num - 2));
	free(result);
}

static void	ft_print_pointer2(t_symbols *save, long long int num,
		char *result, int lenght)
{
	while (save->width-- > lenght)
		write(1, " ", 1);
	write(1, "0x", 2);
	while (save->precision != -1 && save->precision-- > (num - 2))
		write(1, "0", 1);
	if (result[0] != '0' || save->precision <= 0)
		write(1, result, (num - 2));
	free(result);
}

static void	ft_print_pointer3(t_symbols *save, long long int num,
		char *result, int lenght)
{
	while (save->precision != -1 && save->precision-- > num)
		write(1, "0", 1);
	write(1, "0x", 2);
	if (result[0] != '0' || save->precision <= 0)
		write(1, result, (num - 2));
	free(result);
	while (save->width-- > lenght)
		write(1, " ", 1);
}

int			pointer_to_string(t_symbols *save, va_list argp)
{
	char				*result;
	long long int		num;
	int					lenght;
	int					count;
	long long int		temp;

	temp = (long long int)va_arg(argp, void *);
	result = ft_for_x(temp);
	num = (temp != 0 || save->precision != -1) ?
			(long long)ft_strlen(result) + 2 : 2;
	lenght = (num >= save->precision) ? (int)num : save->precision + 2;
	count = (lenght >= save->width) ? lenght : save->width;
	if (save->minus != '-' && save->width > lenght &&
				save->nul == '0' && save->precision == 0)
		ft_print_pointer1(save, num, result, temp);
	else if (save->minus != '-')
		ft_print_pointer2(save, num, result, lenght);
	else
		ft_print_pointer3(save, num, result, lenght);
	return (count);
}
