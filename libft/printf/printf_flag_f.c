/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 11:49:25 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/15 17:25:46 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_flag_f(va_list ap, t_array *buff, t_printf_mod mod)
{
	size_t		len;
	long double	n;

	if (mod.prec < 0)
		mod.prec = 6;
	n = (mod.ml ? va_arg(ap, long double) : va_arg(ap, double));
	len = ft_intlen((long int)n) + mod.prec + (mod.prec != 0) + (n < 0);
	if (!mod.minus)
		buff = printf_addpad(buff, mod, len);
	if (n < 0)
		buff = ft_arrayaddcharback(buff, '-');
	buff = ft_arrayaddbaseback(buff, ft_abs((LL)n), DECIMAL);
	buff = printf_adddoubleprec(buff, n, mod.prec);
	if (mod.minus)
		buff = printf_addpad(buff, mod, len);
	if (!buff)
		return (-1);
	return (0);
}
