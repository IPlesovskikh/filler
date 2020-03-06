/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:30:23 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/27 16:30:26 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_round_number(long double num, char *fraction,
		int i, char *exponent)
{
	int	temp;

	num *= 10.0;
	temp = (int)num;
	if (temp > 4)
	{
		if (fraction[i] == '9')
		{
			fraction[i] = '0';
			while (fraction[--i] == '9')
				fraction[i] = '0';
			if (fraction[i] == '.')
			{
				i = 0;
				while (exponent[i] != '\0')
					i++;
				exponent[--i]++;
			}
			else
				fraction[i]++;
		}
		else
			fraction[i]++;
	}
}

char	*ft_convert_fraction(long double num, long long int temp,
		int *precision, char *exponent)
{
	char	*fraction;
	int		i;

	temp = (long long int)num;
	num -= (long double)temp;
	if ((fraction = (char*)malloc(sizeof(char) * (*precision + 2))) == NULL)
		exit(-1);
	fraction[*precision + 1] = '\0';
	fraction[0] = '.';
	i = 1;
	while (i <= (*precision))
	{
		num *= 10.0;
		temp = (int)num;
		fraction[i++] = temp + '0';
		num -= (long double)temp;
	}
	ft_round_number(num, fraction, --i, exponent);
	return (fraction);
}

char	*ft_convert_float(t_symbols *save, long double num)
{
	char	*exponent;
	char	*fraction;
	int		precision;
	char	*result;

	if ((exponent = ft_itol((size_t)num)) == NULL)
		exit(-1);
	fraction = NULL;
	if (save->precision == -1)
		precision = 0;
	else
		precision = (save->precision == 0) ? 6 : save->precision;
	if (precision != 0)
		fraction = ft_convert_fraction(num, 0, &precision, exponent);
	if (fraction)
		result = ft_strjoin(exponent, fraction);
	else
		return (exponent);
	free(exponent);
	free(fraction);
	return (result);
}

int		ft_red_minus_one(char **result, int *len, long double *num,
		t_symbols *save)
{
	long long int	temp;
	char			*string;

	while ((*result)[*len] != '\0')
		(*len)++;
	temp = (long long int)(*num);
	(*num) -= (long double)temp;
	(*num) *= 10.0;
	temp = (long long int)(*num);
	if (temp > 4)
	{
		--(*len);
		(*result)[(*len)++]++;
	}
	if (save->sharp == '#')
	{
		string = ft_strjoin((*result), ".");
		free(*result);
		(*result) = string;
		string = NULL;
		(*len)++;
	}
	return (*len);
}

int		float_to_string(t_symbols *save, va_list argp)
{
	char			*result;
	long double		num;
	int				count;
	int				lenght;
	int				len;

	num = ft_get_float(save, argp);
	result = ft_convert_float(save, num);
	len = 0;
	if (save->precision != -1)
	{
		while (result[len] != '.')
			len++;
		while (result[len] != '\0')
			len++;
		lenght = len;
	}
	else
		lenght = ft_red_minus_one(&result, &len, &num, save);
	if (save->sign == -1 || save->plus == '+' || save->space == ' ')
		lenght++;
	count = (lenght >= save->width) ? lenght : save->width;
	ft_print_float(save, lenght, len, result);
	return (count);
}
