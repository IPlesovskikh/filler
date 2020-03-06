/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:42:57 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/06 16:42:59 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_valid_type(const char *s, int i)
{
	while (s[i] == '-' || s[i] == '+' || s[i] == ' ' ||
	s[i] == '#' || s[i] == '0')
		i++;
	if (s[i] == 'c' || s[i] == 's' || s[i] == 'p' ||
		s[i] == 'd' || s[i] == 'i' || s[i] == 'o' || s[i] == '%' ||
		s[i] == 'u' || s[i] == 'x' || s[i] == 'X' || s[i] == 'f')
		return (1);
	return (0);
}

int	ft_valid_size(const char *s, int i)
{
	if (s[i] == 'l')
	{
		if (s[i + 1] == 'l')
			return (i + 2);
		return (i + 1);
	}
	if (s[i] == 'h')
	{
		if (s[i + 1] == 'h')
			return (i + 2);
		return (i + 1);
	}
	if (s[i] == 'L')
		return (i + 1);
	return (i);
}

int	ft_valid_precision(const char *s, int i)
{
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
			i++;
	}
	return (i);
}

int	ft_valid_width(const char *s, int i)
{
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	while (s[i] == '-' || s[i] == '+' || s[i] == ' ' ||
	s[i] == '#' || s[i] == '0')
		i++;
	return (i);
}

int	ft_valid_flag(const char *s, int i)
{
	while (s[i] == '-' || s[i] == '+' || s[i] == ' ' ||
		s[i] == '#' || s[i] == '0')
		i++;
	return (i);
}
