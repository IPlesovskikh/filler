/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_sys7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:56:29 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/17 15:56:30 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_for_bigxch4(char *str, char *str2, long long num, int i)
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
		while (str2[1 - i] + 1 > 'F')
		{
			str2[1 - i] = '0';
			i++;
		}
		str2[1 - i] = (str2[1 - i] == '9') ? 'A' : str2[1 - i] + 1;
	}
	if (num >= 0)
		str2[j] = '\0';
}

char	*ft_for_bigxch3(char *str, long long num)
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
			str2[j++] = 'F';
		str2[j] = '\0';
	}
	ft_for_bigxch4(str, str2, num, i);
	free(str);
	str = NULL;
	return (str2);
}

char	*ft_for_bigxch2(char *str, long long num)
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
				str[k++] = (num % 16) + '7';
		}
		else
		{
			if (num % 16 > -6)
				str[k++] = 'F' + (num % 16);
			else
				str[k++] = '?' + (num % 16);
		}
		str[k] = '\0';
		num = num / 16;
	}
	return (str);
}

char	*ft_for_bigxch(long long num)
{
	char	*str;

	str = NULL;
	if ((str = (char *)malloc(sizeof(char) * 3)) == NULL)
		exit(-1);
	str = ft_for_bigxch2(str, num);
	str = ft_for_bigxch3(str, num);
	return (str);
}
