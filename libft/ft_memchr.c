/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 21:21:59 by pdonnie           #+#    #+#             */
/*   Updated: 2019/04/10 21:22:02 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	char			*str;
	char			numb;

	numb = (char)c;
	str = (char *)s;
	index = 0;
	while (index < n)
	{
		if (str[index] == numb)
			return (void *)(str + index);
		index++;
	}
	return (NULL);
}
