/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraynew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:59:33 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/17 17:09:43 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array		*ft_arraynew(const char *str)
{
	t_array		*new;

	new = (t_array *)malloc(sizeof(t_array));
	if (!str)
		return (NULL);
	new->size = 0;
	new->str = NULL;
	new = ft_arrayrealloc(new, ft_strlen(str));
	ft_memcpy(new->str, str, new->size * sizeof(char));
	return (new);
}
