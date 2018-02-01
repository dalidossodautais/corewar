/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayaddcharback.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 10:17:57 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/05 19:47:19 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array	*ft_arrayaddcharback(t_array *a, char c)
{
	if (!a)
		return (NULL);
	a = ft_arrayrealloc(a, a->size + 1);
	a->str[a->size - 1] = c;
	return (a);
}
