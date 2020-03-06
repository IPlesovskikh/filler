/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:48:47 by jbowen            #+#    #+#             */
/*   Updated: 2019/08/25 19:48:51 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_fill_array_operation(void)
{
	g_operations['c'] = char_to_string;
	g_operations['s'] = string_to_string;
	g_operations['p'] = pointer_to_string;
	g_operations['d'] = digits_to_string;
	g_operations['i'] = digits_to_string;
	g_operations['o'] = octal_to_string;
	g_operations['u'] = unsigned_to_string;
	g_operations['x'] = sixteen_to_string;
	g_operations['X'] = sixteen_to_string;
	g_operations['%'] = percent_to_string;
	g_operations['f'] = float_to_string;
}
