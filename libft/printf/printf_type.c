/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 12:17:54 by gricquie          #+#    #+#             */
/*   Updated: 2017/03/29 14:02:36 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int			printf_typesigned(va_list ap, t_printf_mod mod)
{
	if (mod.l == -2)
		return ((char)va_arg(ap, int));
	if (mod.l == -1)
		return ((short)va_arg(ap, int));
	if (!mod.l)
		return (va_arg(ap, int));
	else if (mod.l == 1)
		return (va_arg(ap, long));
	else
		return (va_arg(ap, long long));
}

unsigned long long		printf_typeunsigned(va_list ap, t_printf_mod mod)
{
	if (mod.l == -2)
		return ((unsigned char)va_arg(ap, unsigned int));
	else if (mod.l == -1)
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (mod.l == 0)
		return (va_arg(ap, unsigned int));
	else if (mod.l == 1)
		return (va_arg(ap, unsigned long));
	else
		return (va_arg(ap, unsigned long long));
}
