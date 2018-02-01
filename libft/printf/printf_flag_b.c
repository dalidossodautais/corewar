/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 12:18:42 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/12 17:07:48 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_flag_b(va_list ap, t_array *buff, t_printf_mod mod)
{
	ULL		nb;
	size_t	len;

	nb = printf_typeunsigned(ap, mod);
	len = ft_baselen(nb, 2);
	if (!mod.minus)
		buff = printf_addpad(buff, mod, ft_max(len, mod.prec));
	buff = printf_addprec(buff, mod, len);
	if (mod.prec || nb)
		buff = ft_arrayaddbaseback(buff, nb, "01");
	if (mod.minus)
		buff = printf_addpad(buff, mod, ft_max(len, mod.prec));
	if (!buff)
		return (-1);
	return (0);
}
