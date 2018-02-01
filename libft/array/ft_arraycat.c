/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraycat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:10:54 by gricquie          #+#    #+#             */
/*   Updated: 2017/08/18 14:51:22 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array.h>

t_array		*ft_arraycat(t_array *dest, const t_array *src)
{
	size_t		len;

	if (!dest || !src)
		return (NULL);
	if (!src->str)
		return (dest);
	len = dest->size;
	if (!(dest = ft_arrayrealloc(dest, dest->size + src->size)))
		return (NULL);
	ft_memcpy(dest->str + len, src->str, src->size);
	return (dest);
}
