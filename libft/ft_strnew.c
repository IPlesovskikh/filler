/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:11:19 by pdonnie           #+#    #+#             */
/*   Updated: 2019/04/09 17:18:37 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	index;

	if ((size + 1) < size)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (NULL);
	else
	{
		index = 0;
		while (size > 0)
		{
			str[index] = '\0';
			index++;
			size--;
		}
		if (size == 0)
			str[index] = 0;
		return (str);
	}
}
