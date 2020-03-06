/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:35:10 by pdonnie           #+#    #+#             */
/*   Updated: 2019/04/09 15:14:43 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		index;
	char		chr;
	char		*str;

	chr = (char)(c);
	str = (char *)(b);
	index = 0;
	while (index < len)
	{
		str[index] = c;
		index++;
	}
	return (b);
}
