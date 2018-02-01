/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayaddbaseback.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:15:35 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/11 17:34:54 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array		*ft_arrayaddbaseback(t_array *a, ULL nbr, char *base)
{
	ULL		factor;
	size_t	baselen;

	factor = 1;
	baselen = ft_strlen(base);
	while (factor <= nbr / baselen)
		factor *= baselen;
	while (factor > 0)
	{
		a = ft_arrayaddcharback(a, base[nbr / factor]);
		nbr %= factor;
		if (factor == 1)
			factor = 0;
		factor /= baselen;
	}
	return (a);
}
