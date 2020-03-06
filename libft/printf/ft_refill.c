/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 00:31:03 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/09 00:31:07 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_refill2(char *s, char *str, int i)
{
	int j;

	j = 0;
	while (str[j] != '\0')
		j++;
	while (s[i] != '\0')
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(s);
	s = NULL;
}

char	*ft_refill(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	j = 0;
	if ((str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		exit(-1);
	str[0] = '%';
	str[1] = '\0';
	while (s[i] == '-' || s[i] == '+' || s[i] == ' ' ||
	s[i] == '#' || s[i] == '0')
	{
		while (str[j] != '\0' && str[j] != s[i])
			j++;
		if (str[j] == '\0')
		{
			str[j] = s[i];
			str[++j] = '\0';
		}
		i++;
		j = 0;
	}
	ft_refill2(s, str, i);
	return (str);
}
