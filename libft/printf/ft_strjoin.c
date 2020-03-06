/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:45:52 by pdonnie           #+#    #+#             */
/*   Updated: 2019/04/10 16:48:00 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	size_t		index;
	size_t		index2;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == 0)
		return (NULL);
	index = 0;
	while (s1[index] != '\0')
	{
		str[index] = s1[index];
		index++;
	}
	index2 = 0;
	while (s2[index2] != '\0')
	{
		str[index] = s2[index2];
		index++;
		index2++;
	}
	str[index] = '\0';
	return (str);
}
