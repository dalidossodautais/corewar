/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayaddstrfront.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:34:23 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/05 19:45:00 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array		*ft_arrayaddstrfront(t_array *arr, const char *str)
{
	size_t		len;

	if (!arr || !str)
		return (NULL);
	len = ft_strlen(str);
	if (!len)
		return (arr);
	if (!(arr = ft_arrayrealloc(arr, arr->size + len)))
		return (NULL);
	ft_memmove(arr->str + len, arr->str, arr->size - len);
	ft_memcpy(arr->str, str, len);
	return (arr);
}
