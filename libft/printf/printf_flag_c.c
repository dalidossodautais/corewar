/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 11:13:30 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/12 17:26:51 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_flag_c(va_list ap, t_array *buff, t_printf_mod mod)
{
	char	c;

	if (!mod.valid)
		return (0);
	if (mod.maj || mod.l == 1)
		return (printf_flag_lc(ap, buff, mod));
	if (mod.valid)
		c = va_arg(ap, int);
	if (!mod.minus)
		buff = printf_addpad(buff, mod, mod.valid);
	if (mod.valid)
		buff = ft_arrayaddcharback(buff, c);
	if (mod.minus)
		buff = printf_addpad(buff, mod, mod.valid);
	if (!buff)
		return (-1);
	return (0);
}
