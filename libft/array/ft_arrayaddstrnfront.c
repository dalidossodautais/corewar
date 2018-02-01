/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayaddstrnfront.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 08:14:47 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/11 12:48:56 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array	*ft_arrayaddstrnfront(t_array *a, const char *str, size_t len)
{
	if (!str)
		return (NULL);
	if (!len || !a)
		return (a);
	if (len > ft_strlen(str))
		len = ft_strlen(str);
	if (!(a = ft_arrayrealloc(a, a->size + len)))
		return (NULL);
	ft_memmove(a->str + len, a->str, a->size - len);
	ft_memcpy(a->str, str, len);
	return (a);
}
