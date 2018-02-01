/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraycutfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 11:49:47 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/05 19:52:40 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array	*ft_arraycutfront(t_array *a, size_t cut)
{
	if (!a)
		return (NULL);
	if (a->size > cut)
	{
		ft_memcpy(a->str, a->str + a->size - cut, cut);
		a->size = cut;
	}
	return (a);
}
