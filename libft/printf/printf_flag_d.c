/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 10:57:37 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/14 19:25:20 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_flag_d(va_list ap, t_array *buff, t_printf_mod mod)
{
	size_t		len;
	long long	nb;

	nb = printf_typesigned(ap, mod);
	if (!nb && mod.prec < 0)
		mod.prec = 1;
	mod.width -= ((nb < 0) && mod.zero);
	len = (mod.prec > 0 ? ft_max(ft_intlen(nb), mod.prec) : ft_intlen(nb));
	len += (mod.apos && len ? (len - 1) / 3 : 0)
			+ (nb >= 0 && (mod.space || mod.plus));
	if (mod.zero && mod.width > mod.prec)
		mod.prec = mod.width - (nb >= 0 && (mod.plus || mod.space));
	if (!mod.minus && !mod.zero)
		buff = printf_addpad(buff, mod, len + (!len && mod.prec) + (nb < 0));
	if (nb < 0)
		buff = ft_arrayaddcharback(buff, '-');
	else if (mod.space || mod.plus)
		buff = ft_arrayaddcharback(buff, (mod.plus ? '+' : ' '));
	buff = printf_addapos(buff, mod, nb);
	if (mod.minus)
		buff = printf_addpad(buff, mod, len + (nb < 0));
	if (!buff)
		return (-1);
	return (0);
}
