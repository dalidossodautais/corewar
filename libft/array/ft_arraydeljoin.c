/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydeljoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:18:33 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/06 15:32:05 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array		*ft_arraydeljoin(t_array *a1, t_array *a2, const char del)
{
	t_array		*new;

	if (!a1 || !a2)
		return (NULL);
	new = ft_arrayjoin(a1, a2);
	if (del == DELLEFT || del == DELBOTH)
		ft_arraydel(&a1);
	if (del == DELRIGHT || del == DELBOTH)
		ft_arraydel(&a2);
	if (del != DELLEFT && del != DELRIGHT && del != DELBOTH)
		ft_putendl("erreur : mauvaise valeur de del");
	return (new);
}
