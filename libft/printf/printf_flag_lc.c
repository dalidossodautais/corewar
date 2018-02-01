/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_lc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 11:28:05 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/13 16:22:51 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_flag_lc(va_list ap, t_array *buff, t_printf_mod mod)
{
	wchar_t		wc;

	wc = va_arg(ap, wchar_t);
	if (!mod.minus)
		buff = printf_addpad(buff, mod, 1);
	buff = ft_arrayaddwcharback(buff, wc);
	if (!mod.minus)
		buff = printf_addpad(buff, mod, 1);
	if (!buff)
		return (-1);
	return (0);
}
