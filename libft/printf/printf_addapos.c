/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_addapos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:29:01 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/13 17:11:54 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static LL	initfactor(long long nb)
{
	LL		factor;

	factor = 1;
	if (nb == 0)
		return (0);
	while (factor <= ft_abs(nb / 10))
		factor *= 10;
	return (factor);
}

t_array		*printf_addapos(t_array *buff, t_printf_mod mod, long long nb)
{
	size_t		len;
	long long	factor;

	len = ft_intlen(nb);
	while (mod.prec > 0 && (size_t)mod.prec > len)
	{
		buff = ft_arrayaddcharback(buff, '0');
		if (mod.apos && mod.prec % 3 == 1 && !(mod.prec == 1 && nb == 0))
			buff = ft_arrayaddcharback(buff, ',');
		mod.prec--;
	}
	factor = initfactor(nb);
	while (factor > 0)
	{
		buff = ft_arrayaddcharback(buff, ft_abs(nb / factor) + '0');
		nb %= factor;
		if (factor == 1)
			factor = 0;
		factor /= 10;
		if (mod.apos && len % 3 == 1 && len != 1)
			buff = ft_arrayaddcharback(buff, ',');
		len--;
	}
	return (buff);
}
