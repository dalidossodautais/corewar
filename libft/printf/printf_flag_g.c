/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_g.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 14:56:38 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/16 16:45:21 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flag_g_e(t_array *buff, long double n, int exp, t_printf_mod mod)
{
	size_t		len;

	len = mod.prec + (exp ? 5 : 1);
	if (!mod.minus)
		buff = printf_addpad(buff, mod, len);
	if (n < 0)
		buff = ft_arrayaddcharback(buff, '-');
	n = printf_cutdouble(n, mod.prec);
	buff = ft_arrayaddcharback(buff, ft_abs((int)n) + '0');
	buff = printf_adddoubleprec(buff, n, mod.prec - 1);
	while (buff->str[buff->size - 1] == '0')
		buff->size--;
	if (buff->str[buff->size - 1] == '.')
		buff->size--;
	buff = ft_arrayaddcharback(buff, (mod.maj ? 'E' : 'e'));
	buff = ft_arrayaddcharback(buff, (exp < 0 ? '-' : '+'));
	buff = ft_arrayaddcharback(buff, ft_abs(exp) / 10 + '0');
	buff = ft_arrayaddcharback(buff, ft_abs(exp) % 10 + '0');
	if (mod.minus)
		buff = printf_addpad(buff, mod, len);
	if (!buff)
		return (-1);
	return (0);
}

static int	flag_g_f(t_array *buff, long double n, t_printf_mod mod)
{
	size_t		len;

	len = ft_intlen((LL)n) + mod.prec + (n < 0);
	if (!n)
		len = 1;
	if (!mod.minus)
		buff = printf_addpad(buff, mod, len);
	buff = ft_arrayaddcharback(buff, (LL)n + '0');
	buff = printf_adddoubleprec(buff, n, mod.prec - ft_intlen((LL)n));
	if (!n)
		buff->size--;
	while (buff->str[buff->size - 1] == '0')
		buff->size--;
	if (buff->str[buff->size - 1] == '.')
		buff->size--;
	if (mod.minus)
		buff = printf_addpad(buff, mod, len);
	if (!buff)
		return (-1);
	return (0);
}

int			printf_flag_g(va_list ap, t_array *buff, t_printf_mod mod)
{
	long double		n;
	long double		nb;
	int				exp;

	if (mod.prec < 0)
		mod.prec = 6;
	if (mod.prec == 0)
		mod.prec = 1;
	n = (mod.ml ? va_arg(ap, long double) : va_arg(ap, double));
	nb = n;
	exp = printf_calcexp(&nb);
	if (exp < -4 || exp >= mod.prec)
		return (flag_g_e(buff, nb, exp, mod));
	return (flag_g_f(buff, n, mod));
}
