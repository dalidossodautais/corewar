/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayrealloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 16:54:06 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/11 12:50:54 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array		*ft_arrayrealloc(t_array *a, size_t len)
{
	if (!a)
		return (NULL);
	if (len <= a->size)
		return (a);
	if (len / ARRAYSIZE < a->size / ARRAYSIZE)
		return (a);
	a->str = ft_realloc(a->str, sizeof(char ) * ARRAY_PAD_SIZE(a->size),
			sizeof(char) * ARRAY_PAD_SIZE(a->size + len));
	if (!a->str)
		return (NULL);
	a->size = len;
	return (a);
}
