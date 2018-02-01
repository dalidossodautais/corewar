/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:57:03 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/05 19:26:43 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array		*ft_arrayjoin(const t_array *a1, const t_array *a2)
{
	t_array		*new;

	if (!a1 || !a2)
		return (NULL);
	new = ft_arraydup(a1);
	ft_arraycat(new, a2);
	return (new);
}
