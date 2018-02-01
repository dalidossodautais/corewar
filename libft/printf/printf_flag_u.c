/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 11:06:55 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/11 18:20:49 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_flag_u(va_list ap, t_array *buff, t_printf_mod mod)
{
	ULL		nb;
	size_t	len;

	nb = printf_typeunsigned(ap, mod);
	len = ft_baselen(nb, 10);
	if (mod.zero && mod.prec >= 0)
		mod.zero = 0;
	if (!mod.minus)
		buff = printf_addpad(buff, mod, ft_max(len, mod.prec));
	buff = printf_addprec(buff, mod, len);
	if (mod.prec || nb)
		buff = ft_arrayaddbaseback(buff, nb, DECIMAL);
	if (mod.minus)
		buff = printf_addpad(buff, mod, ft_max(len, mod.prec));
	if (!buff)
		return (-1);
	return (0);
}
