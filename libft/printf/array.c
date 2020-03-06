/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:42:13 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/07 16:42:17 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_fill_array(const char *s, int i, int j)
{
	int		count;
	char	*str;

	count = 0;
	str = NULL;
	if ((str = (char *)malloc(sizeof(char) * (j + 1))) == NULL)
		exit(-1);
	while (count < j)
	{
		str[count] = s[i];
		count++;
		i++;
	}
	str[count] = '\0';
	return (str);
}

void	ft_array_runner2(const char *s, int *i, int *j)
{
	if (s[*i] != '\0' && *j == 0 && s[*i] == '%')
	{
		(*i)++;
		(*j)++;
		while (s[*i] != 'c' && s[*i] != 's' && s[*i] != 'p' &&
		s[*i] != 'd' && s[*i] != 'i' && s[*i] != 'o' && s[*i] != '%' &&
		s[*i] != 'u' && s[*i] != 'x' && s[*i] != 'X' && s[*i] != 'f')
		{
			(*i)++;
			(*j)++;
		}
		(*i)++;
		(*j)++;
	}
}

int		ft_array_runner(const char *s, int *i, int *count)
{
	int j;

	j = 0;
	while (s[*i] != '\0' && s[*i] != '%')
	{
		(*i)++;
		j++;
	}
	if (j == 0 && s[*i] != '\0' && ft_validation(s, *i + 1) == 0)
	{
		(*i)++;
		while (s[*i] != '\0' && s[*i] != '%' && s[*i] != 'Z')
			(*i)++;
		return (1);
	}
	if (j != 0)
	{
		ft_putnstr(s, *i - j, j);
		*(count) += j;
	}
	return (j);
}

int		ft_create_array(const char *s, va_list argp)
{
	int		i;
	int		j;
	int		count;
	char	*str;

	i = 0;
	count = 0;
	str = NULL;
	while (s[i] != '\0')
	{
		if ((j = ft_array_runner(s, &i, &count)) == 0)
		{
			ft_array_runner2(s, &i, &j);
			str = ft_fill_array(s, i - j, j);
			str = ft_refill(str);
			count += ft_get_value(str, argp);
			free(str);
			str = NULL;
		}
	}
	return (count);
}
