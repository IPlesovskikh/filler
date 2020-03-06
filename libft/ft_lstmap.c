/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 00:30:12 by pdonnie           #+#    #+#             */
/*   Updated: 2019/05/01 00:30:16 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(t_list *result)
{
	t_list	*temp;

	while (result)
	{
		temp = result->next;
		free(result);
		result = temp;
	}
	result = NULL;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*new;
	t_list	*temp;
	t_list	*result;

	if (!lst || !f)
		return (NULL);
	if ((new = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new = f(lst);
	lst = lst->next;
	temp = new;
	result = new;
	while (lst)
	{
		if ((new = malloc(sizeof(t_list))) == NULL)
		{
			ft_free(result);
			return (NULL);
		}
		new = f(lst);
		temp->next = new;
		temp = new;
		lst = lst->next;
	}
	return (result);
}
