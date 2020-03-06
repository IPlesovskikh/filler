/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:00:42 by pdonnie           #+#    #+#             */
/*   Updated: 2019/04/11 21:00:46 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t		index_s1;
	size_t		index_s2;

	index_s1 = 0;
	while (s1[index_s1] != '\0')
		index_s1++;
	index_s2 = 0;
	while (n > 0 && s2[index_s2] != '\0')
	{
		s1[index_s1] = s2[index_s2];
		index_s1++;
		index_s2++;
		n--;
	}
	s1[index_s1] = '\0';
	return (s1);
}
