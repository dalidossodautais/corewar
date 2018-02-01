/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 10:52:34 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/13 13:51:50 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_flag_p(va_list ap, t_array *buff, t_printf_mod mod)
{
	void	*add;
	size_t	len;

	add = va_arg(ap, void *);
	len = ft_baselen((ULL)add, 16);
	if (mod.zero && mod.prec >= 0)
		mod.zero = 0;
	if (!mod.minus && !mod.zero)
		buff = printf_addpad(buff, mod, ft_max(len, mod.prec) + 2 + !len);
	buff = ft_arrayaddstrback(buff, "0x");
	buff = printf_addprec(buff, mod, len + !len);
	if (mod.prec || add)
		buff = ft_arrayaddbaseback(buff, (ULL)add, LOWHEXA);
	if (mod.minus)
		buff = printf_addpad(buff, mod, ft_max(len, mod.prec) + 2 + !len);
	if (!buff)
		return (-1);
	return (0);
}
