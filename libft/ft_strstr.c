/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:14:52 by pdonnie           #+#    #+#             */
/*   Updated: 2019/04/08 17:14:59 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(char *haystack, char *needle)
{
	size_t		index_haystack;
	size_t		index_needle;
	size_t		counter;

	if (haystack[0] == '\0' && needle[0] == '\0')
		return (char *)(haystack);
	if (needle[0] == '\0')
		return (char *)(haystack);
	counter = 0;
	index_haystack = 0;
	while (haystack[index_haystack] != '\0')
	{
		index_haystack = counter;
		index_needle = 0;
		while (needle[index_needle] != '\0' && haystack[index_haystack] != '\0'
			&& needle[index_needle] == haystack[index_haystack])
		{
			index_needle++;
			index_haystack++;
		}
		if (needle[index_needle] == '\0')
			return (char *)(haystack + index_haystack - ft_strlen(needle));
		counter++;
	}
	return (0);
}
