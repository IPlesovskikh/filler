/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:16:55 by pdonnie           #+#    #+#             */
/*   Updated: 2019/12/15 09:05:41 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f) (unsigned int, char))
{
	char			*str;
	unsigned int	index;

	if (!s || !f)
		return (NULL);
	index = ft_strlen(s);
	if ((index + 1) < index)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (index + 1));
	if (str == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		str[index] = f(index, s[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}
