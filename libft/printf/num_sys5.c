/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_sys5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:56:14 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/17 15:56:16 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_for_xch4(char *str, char *str2, long long num, int i)
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
			str2[1 - i] = str[i];
			i--;
		}
		i++;
		while (str2[1 - i] + 1 > 'f')
		{
			str2[1 - i] = '0';
			i++;
		}
		str2[1 - i] = (str2[1 - i] == '9') ? 'a' : str2[1 - i] + 1;
	}
	if (num >= 0)
		str2[j] = '\0';
}

char	*ft_for_xch3(char *str, long long num)
{
	int		i;
	int		j;
	char	*str2;

	i = ft_strlen(str) - 1;
	j = 0;
	if ((str2 = (char *)malloc(sizeof(char) * 3)) == NULL)
		exit(-1);
	if (num < 0)
	{
		while (j < 2)
			str2[j++] = 'f';
		str2[j] = '\0';
	}
	ft_for_xch4(str, str2, num, i);
	free(str);
	str = NULL;
	return (str2);
}

char	*ft_for_xch2(char *str, long long num)
{
	int	k;

	k = 0;
	str[k] = '0';
	str[k + 1] = '\0';
	while (num != 0)
	{
		if (num > 0)
		{
			if (num % 16 < 10)
				str[k++] = (num % 16) + '0';
			else
				str[k++] = (num % 16) + 'W';
		}
		else
		{
			if (num % 16 > -6)
				str[k++] = 'f' + (num % 16);
			else
				str[k++] = '?' + (num % 16);
		}
		str[k] = '\0';
		num = num / 16;
	}
	return (str);
}

char	*ft_for_xch(long long num)
{
	char	*str;

	str = NULL;
	if ((str = (char *)malloc(sizeof(char) * 3)) == NULL)
		exit(-1);
	str = ft_for_xch2(str, num);
	str = ft_for_xch3(str, num);
	return (str);
}
