/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayaddnstrback.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:05:51 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/11 12:43:36 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array		*ft_arrayaddstrnback(t_array *arr, const char *str, size_t len)
{
	if (!str)
		return (NULL);
	if (!len || !arr)
		return (arr);
	len = ft_min(len, ft_strlen(str));
	if (!(arr = ft_arrayrealloc(arr, arr->size + len)))
		return (NULL);
	ft_memcpy(arr->str + arr->size - len, str, len);
	return (arr);
}
