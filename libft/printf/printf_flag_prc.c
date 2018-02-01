/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_prc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:18:59 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/12 17:25:00 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_flag_prc(va_list ap, t_array *buff, t_printf_mod mod)
{
	(void)ap;
	if (!mod.minus)
		buff = printf_addpad(buff, mod, 1);
	buff = ft_arrayaddcharback(buff, '%');
	if (mod.minus)
		buff = printf_addpad(buff, mod, 1);
	if (!buff)
		return (-1);
	return (0);
}
