/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:06:11 by pdonnie           #+#    #+#             */
/*   Updated: 2019/04/11 21:06:13 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t		index_src;
	size_t		result;
	size_t		len_dst;

	len_dst = ft_strlen(dst);
	result = len_dst;
	if (result >= size)
		return (size + ft_strlen(src));
	index_src = 0;
	while (result < size && src[index_src] != '\0')
	{
		dst[result] = src[index_src];
		result++;
		index_src++;
	}
	if (result >= size)
		dst[result - 1] = '\0';
	else
		dst[result] = '\0';
	return (len_dst + ft_strlen(src));
}
