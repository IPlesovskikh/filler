/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:15:15 by pdonnie           #+#    #+#             */
/*   Updated: 2019/04/11 16:15:17 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, char *s2)
{
	int		index_s1;
	int		index_s2;

	index_s1 = 0;
	while (s1[index_s1] != '\0')
		index_s1++;
	index_s2 = 0;
	while (s2[index_s2] != '\0')
	{
		s1[index_s1] = s2[index_s2];
		index_s1++;
		index_s2++;
	}
	s1[index_s1] = '\0';
	return (s1);
}
