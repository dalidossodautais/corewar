/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraycutback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 11:50:02 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/05 19:52:46 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array	*ft_arraycutback(t_array *a, size_t cut)
{
	if (!a)
		return (NULL);
	if (a->size > cut)
		a->size = cut;
	return (a);
}
