/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 11:02:17 by gricquie          #+#    #+#             */
/*   Updated: 2017/09/14 14:31:05 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_flag_o(va_list ap, t_array *buff, t_printf_mod mod)
{
	ULL		nb;
	size_t	len;

	nb = printf_typeunsigned(ap, mod);
	len = ft_baselen(nb, 8);
	if (mod.zero && mod.prec < mod.width)
		mod.prec = mod.width - mod.sharp;
	if (!mod.minus && !mod.zero)
		buff = printf_addpad(buff, mod, ft_max(len, mod.prec) + mod.sharp +
				nb == 0);
	buff = ft_arrayaddstrnback(buff, "0", mod.sharp && (len || !mod.prec));
	buff = printf_addprec(buff, mod, len + mod.sharp + (nb == 0));
	if (mod.prec || nb)
		buff = ft_arrayaddbaseback(buff, nb, OCTAL);
	if (mod.minus)
		buff = printf_addpad(buff, mod, ft_max(len, mod.prec) + mod.sharp +
				nb == 0);
	if (!buff)
		return (-1);
	return (0);
}
