/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_sys12.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:26:59 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/17 19:27:02 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_for_bigxul4(char *str, char *str2, long long num, int i)
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
			str2[15 - i] = str[i];
			i--;
		}
		i++;
		while (str2[15 - i] + 1 > 'F')
		{
			str2[15 - i] = '0';
			i++;
		}
		str2[15 - i] = (str2[15 - i] == '9') ? 'A' : str2[15 - i] + 1;
	}
	if (num >= 0)
		str2[j] = '\0';
}

char	*ft_for_bigxul3(char *str, long long num)
{
	int		i;
	int		j;
	char	*str2;

	i = ft_strlen(str) - 1;
	j = 0;
	if ((str2 = (char *)malloc(sizeof(char) * 17)) == NULL)
		exit(-1);
	if (num < 0)
	{
		while (j < 16)
			str2[j++] = 'F';
		str2[j] = '\0';
	}
	ft_for_bigxul4(str, str2, num, i);
	free(str);
	str = NULL;
	return (str2);
}

char	*ft_for_bigxul2(char *str, long long num)
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

char	*ft_for_bigxul(long long num)
{
	char	*str;

	str = NULL;
	if ((str = (char *)malloc(sizeof(char) * 17)) == NULL)
		exit(-1);
	str = ft_for_bigxul2(str, num);
	str = ft_for_bigxul3(str, num);
	return (str);
}
