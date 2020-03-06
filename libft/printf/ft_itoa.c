/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:47:48 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/25 19:47:53 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t		ft_length_of_string(size_t n)
{
	size_t	i;
	size_t	temp;

	i = 0;
	temp = n;
	if (temp == 0)
		i++;
	while (temp > 0)
	{
		temp = temp / 10;
		i++;
	}
	return (i);
}

char				*ft_itol(size_t n)
{
	char	*str;
	int		i;
	size_t	temp;

	i = ft_length_of_string(n);
	if ((str = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	temp = n;
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = temp % 10 + 48;
		temp = temp / 10;
		i--;
	}
	return (str);
}
