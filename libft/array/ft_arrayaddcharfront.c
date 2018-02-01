/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayaddcharfront.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 10:17:57 by gricquie          #+#    #+#             */
/*   Updated: 2017/06/27 16:31:47 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array	*ft_arrayaddcharfront(t_array *a, char c)
{
	if (!a)
		return (NULL);
	a = ft_arrayrealloc(a, a->size + 1);
	ft_memmove(a->str + sizeof(char), a->str, a->size - 1);
	a->str[0] = c;
	return (a);
}
