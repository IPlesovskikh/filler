/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:51:22 by pdonnie           #+#    #+#             */
/*   Updated: 2019/04/10 20:51:26 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	index;

	if (!dst && !src)
		return (NULL);
	s1 = (char *)src;
	s2 = (char *)dst;
	if (dst <= src)
		dst = ft_memcpy(dst, src, len);
	else
	{
		index = len;
		index--;
		while (len > 0)
		{
			s2[index] = s1[index];
			index--;
			len--;
		}
	}
	return (dst);
}
