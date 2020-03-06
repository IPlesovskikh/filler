/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:26:15 by pdonnie           #+#    #+#             */
/*   Updated: 2019/04/11 21:26:18 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	size_t	i;
	char	chr;

	i = ft_strlen(s);
	chr = (int)c;
	while (i > 0 && s[i] != chr)
		i--;
	if (s[i] == chr)
		return (char *)(s + i);
	return (0);
}
