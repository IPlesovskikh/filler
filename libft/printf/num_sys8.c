/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_sys8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 18:18:14 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/17 18:18:17 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_for_osh4(char *str, char *str2, long long int num, int i)
{
	int j;

	j = 0;
	if (num >= 0)
		while (i >= 0)
			str2[j++] = str[i--];
	else
	{
		while (i >= 0)
		{
			str2[5 - i] = str[i];
			i--;
		}
		i++;
		while (str2[5 - i] + 1 > '7')
		{
			str2[5 - i] = '0';
			i++;
		}
		str2[5 - i] = str2[5 - i] + 1;
		if (ft_strlen(str) == 6)
			str2[0] = '1';
	}
	if (num >= 0)
		str2[j] = '\0';
}

char	*ft_for_osh3(char *str, long long int num)
{
	int		i;
	int		j;
	char	*str2;

	i = ft_strlen(str) - 1;
	j = 0;
	if ((str2 = (char *)malloc(sizeof(char) * 7)) == NULL)
		exit(-1);
	if (num < 0)
	{
		while (j < 6)
			str2[j++] = '7';
		str2[j] = '\0';
		str2[0] = '1';
	}
	ft_for_osh4(str, str2, num, i);
	free(str);
	str = NULL;
	return (str2);
}

char	*ft_for_osh2(char *str, long long int num)
{
	int	k;

	k = 0;
	str[k] = '0';
	str[k + 1] = '\0';
	while (num != 0)
	{
		if (num > 0)
			str[k++] = (num % 8) + '0';
		else
			str[k++] = '7' + (num % 8);
		str[k] = '\0';
		num = num / 8;
	}
	return (str);
}

char	*ft_for_osh(long long int num)
{
	char	*str;

	str = NULL;
	if ((str = (char *)malloc(sizeof(char) * 7)) == NULL)
		exit(-1);
	str = ft_for_osh2(str, num);
	str = ft_for_osh3(str, num);
	return (str);
}
