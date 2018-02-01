/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 11:09:37 by gricquie          #+#    #+#             */
/*   Updated: 2017/09/14 14:30:39 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_flag_x(va_list ap, t_array *buff, t_printf_mod mod)
{
	ULL		nb;
	size_t	len;

	nb = printf_typeunsigned(ap, mod);
	len = ft_baselen(nb, 16);
	if (mod.zero && mod.prec < mod.width)
		mod.prec = mod.width - 2 * mod.sharp;
	if (!mod.minus && !mod.zero)
		buff = printf_addpad(buff, mod, ft_max(len, mod.prec) + 2 * mod.sharp);
	buff = ft_arrayaddstrnback(buff, (mod.maj ? "0X" : "0x"),
				2 * (mod.sharp && nb));
	buff = printf_addprec(buff, mod, len + (nb == 0));
	if (mod.prec || nb)
		buff = ft_arrayaddbaseback(buff, nb, (mod.maj ? UPHEXA : LOWHEXA));
	if (mod.minus)
		buff = printf_addpad(buff, mod, ft_max(len, mod.prec) + 2 * mod.sharp);
	if (!buff)
		return (-1);
	return (0);
}
