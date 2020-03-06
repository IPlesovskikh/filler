/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:51:40 by pdonnie           #+#    #+#             */
/*   Updated: 2019/04/10 17:51:43 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_create_array(char const *s, char c, size_t index_rsc)
{
	size_t		counter;
	char		**array;

	counter = 0;
	while (s[index_rsc] == c)
		index_rsc++;
	while (s[index_rsc] != '\0')
	{
		counter++;
		while (s[index_rsc] != c && s[index_rsc] != '\0')
			index_rsc++;
		while (s[index_rsc] == c)
			index_rsc++;
	}
	if ((counter + 1) < counter)
		return (NULL);
	array = (char**)malloc(sizeof(char *) * (counter + 1));
	if (array == NULL)
		return (NULL);
	return (array);
}

static void		ft_free_memory(char **array, int index_array)
{
	index_array--;
	while (index_array >= 0)
	{
		free(*array + index_array);
		index_array--;
	}
	free(array);
}

static void		ft_create_strings(char **array, char const *s,
									char c, size_t index_rsc)
{
	size_t		counter;
	size_t		index_array;

	counter = 0;
	index_array = 0;
	while (s[index_rsc] == c)
		index_rsc++;
	while (s[index_rsc] != '\0')
	{
		while (s[index_rsc] != c && s[index_rsc] != '\0')
		{
			counter++;
			index_rsc++;
		}
		array[index_array] = ft_strnew(counter);
		if (array[index_array] == NULL)
		{
			ft_free_memory(array, index_array);
			return ;
		}
		while (s[index_rsc] == c)
			index_rsc++;
		index_array++;
		counter = 0;
	}
}

static void		ft_fill_array(char const *s, char c, char **array)
{
	size_t	index_array;
	size_t	index_string;
	size_t	index_rsc;

	index_array = 0;
	index_string = 0;
	index_rsc = 0;
	while (s[index_rsc] == c)
		index_rsc++;
	while (s[index_rsc] != '\0')
	{
		while (s[index_rsc] != c && s[index_rsc] != '\0')
		{
			array[index_array][index_string] = s[index_rsc];
			index_string++;
			index_rsc++;
		}
		array[index_array][index_string] = '\0';
		while (s[index_rsc] == c)
			index_rsc++;
		index_array++;
		index_string = 0;
	}
	array[index_array] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	index_rsc;
	char	**array;

	if (!s)
		return (NULL);
	index_rsc = 0;
	array = ft_create_array(s, c, index_rsc);
	if (array == NULL)
		return (NULL);
	ft_create_strings(array, s, c, index_rsc);
	if (array == NULL)
		return (NULL);
	ft_fill_array(s, c, array);
	return (array);
}
