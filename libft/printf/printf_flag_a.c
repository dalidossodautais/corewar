/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:03:39 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/15 18:23:52 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_array	*flag_a_addnbr(long double n, t_array *buff, t_printf_mod mod, int exp)
{
	buff = ft_arrayaddstrback(buff, (mod.maj ? "0X" : "0x"));
	buff = ft_arrayaddcharback(buff, (int)n + '0');
	if (mod.prec && n)
		buff = ft_arrayaddcharback(buff, '.');
	while (n && n - (LL)n && (mod.prec < 0 ? 1 : mod.prec > 0))
	{
		n = (n - (LL)n) * 16;
		buff = ft_arrayaddcharback(buff, (mod.maj ? UPHEXA : LOWHEXA)[(LL)n]);
		mod.prec--;
	}
	buff = ft_arrayaddcharback(buff, 'p');
	buff = ft_arrayaddcharback(buff, n < 0 ? '-' : '+');
	buff = ft_arrayaddbaseback(buff, exp, DECIMAL);
	(void)exp;
	return (buff);
}

int		printf_flag_a(va_list ap, t_array *buff, t_printf_mod mod)
{
	size_t		len;
	int			exp;
	long double	n;

	n = (mod.ml ? va_arg(ap, long double) : va_arg(ap, double));
	len = 7 + mod.prec + (mod.prec != 0);
	exp = 0;
	while (n && n < 1 && --exp)
		n *= 2;
	while (n && n >= 2 && ++exp)
		n /= 2;
	if (!mod.minus)
		buff = printf_addpad(buff, mod, len);
	buff = flag_a_addnbr(n, buff, mod, exp);
	if (mod.minus)
		buff = printf_addpad(buff, mod, len);
	if (!buff)
		return (-1);
	return (0);
}
