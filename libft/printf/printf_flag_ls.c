/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_ls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 11:16:59 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/13 17:01:55 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_flag_ls(va_list ap, t_array *buff, t_printf_mod mod)
{
	wchar_t		*wcs;
	size_t		len;

	wcs = va_arg(ap, wchar_t *);
	if (!wcs)
		wcs = L"(null)";
	len = (mod.prec >= 0 ? ft_min(ft_wcslen(wcs), mod.prec) : ft_wcslen(wcs));
	if (!mod.minus)
		buff = printf_addpad(buff, mod, len);
	if (mod.prec == -1)
		buff = ft_arrayaddwcsback(buff, wcs);
	while (*wcs && mod.prec && (mod.prec -= ft_wcharbytelen(*wcs)) >= 0)
	{
		buff = ft_arrayaddwcharback(buff, *wcs);
		wcs++;
	}
	if (mod.minus)
		buff = printf_addpad(buff, mod, len);
	if (!buff)
		return (-1);
	return (0);
}
