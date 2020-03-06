/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:33:33 by pdonnie           #+#    #+#             */
/*   Updated: 2019/04/11 21:33:36 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t		index_h;
	size_t		index_n;
	size_t		counter;

	if (haystack[0] == '\0' && needle[0] == '\0')
		return (char *)(haystack);
	if (needle[0] == '\0')
		return (char *)(haystack);
	counter = 0;
	index_h = 0;
	while (haystack[index_h] != '\0')
	{
		index_h = counter;
		index_n = 0;
		while (needle[index_n] != '\0' && haystack[index_h] != '\0'
			&& needle[index_n] == haystack[index_h] && index_h < len)
		{
			index_n++;
			index_h++;
		}
		if (needle[index_n] == '\0')
			return (char *)(haystack + index_h - ft_strlen(needle));
		counter++;
	}
	return (0);
}
