/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_e.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 14:02:37 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/16 16:44:45 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_flag_e(va_list ap, t_array *buff, t_printf_mod mod)
{
	size_t		len;
	long double	n;
	int			exp;

	if (mod.prec < 0)
		mod.prec = 6;
	n = (mod.ml ? va_arg(ap, long double) : va_arg(ap, double));
	len = 5 + mod.prec + (mod.prec != 0) + (n < 0);
	exp = printf_calcexp(&n);
	if (!mod.minus)
		buff = printf_addpad(buff, mod, len);
	if (n < 0)
		buff = ft_arrayaddcharback(buff, '-');
	buff = ft_arrayaddcharback(buff, (LL)n + '0');
	buff = printf_adddoubleprec(buff, n, mod.prec);
	buff = ft_arrayaddcharback(buff, (mod.maj ? 'E' : 'e'));
	buff = ft_arrayaddcharback(buff, (exp < 0 ? '-' : '+'));
	buff = ft_arrayaddcharback(buff, ft_abs(exp) / 10 + '0');
	buff = ft_arrayaddcharback(buff, ft_abs(exp) % 10 + '0');
	if (!buff)
		return (-1);
	return (0);
}
