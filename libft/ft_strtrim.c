/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:22:54 by pdonnie           #+#    #+#             */
/*   Updated: 2019/12/15 09:08:45 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_create_empty_string(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

static char	*ft_create_string_strimmed(char const *s, size_t start,
										size_t finish)
{
	size_t	index;
	char	*str;

	if ((finish - start + 2) < (finish - start + 1))
		return (NULL);
	while (s[finish] == ' ' || s[finish] == '\n' || s[finish] == '\t')
		finish--;
	str = (char *)malloc(sizeof(char) * (finish - start + 2));
	if (str == NULL)
		return (NULL);
	index = 0;
	while (start <= finish)
	{
		str[index] = s[start];
		index++;
		start++;
	}
	str[index] = '\0';
	return (str);
}

char		*ft_strtrim(char *s)
{
	char	*str;
	size_t	start;
	size_t	finish;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (s[start] == '\0')
	{
		str = ft_create_empty_string();
		return (str);
	}
	finish = ft_strlen(s) - 1;
	str = ft_create_string_strimmed(s, start, finish);
	return (str);
}
