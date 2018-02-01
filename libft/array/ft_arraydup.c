/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:06:04 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/05 19:26:14 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array		*ft_arraydup(const t_array *old)
{
	t_array *new;

	if (!old)
		return (NULL);
	new = malloc(sizeof(t_array));
	new->size = 0;
	new->str = NULL;
	if (!(new = ft_arrayrealloc(new, old->size)))
		return (NULL);
	ft_memcpy(new->str, old->str, sizeof(char) * old->size);
	return (new);
}
