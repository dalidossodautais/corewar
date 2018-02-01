/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayaddstrback.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:43:14 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/05 19:52:27 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array		*ft_arrayaddstrback(t_array *arr, const char *str)
{
	size_t		len;

	if (!arr || !str)
		return (NULL);
	len = ft_strlen(str);
	if (!len)
		return (arr);
	if (!(arr = ft_arrayrealloc(arr, arr->size + len)))
		return (NULL);
	ft_memcpy(arr->str + arr->size - len, str, len);
	return (arr);
}
