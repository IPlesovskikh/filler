/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:19:15 by pdonnie           #+#    #+#             */
/*   Updated: 2019/04/10 20:35:56 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
					int c, size_t n)
{
	char	num;
	size_t	index;
	char	*str1;
	char	*str2;

	str1 = (char *)dst;
	str2 = (char *)src;
	num = (char)(c);
	index = 0;
	while (n > 0)
	{
		str1[index] = str2[index];
		if (str2[index] == num)
			return (str1 + index + 1);
		index++;
		n--;
	}
	return (NULL);
}
