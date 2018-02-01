/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wrongconv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:35:38 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/15 19:04:24 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_wrongconv(char c, t_array *buff, t_printf_mod mod)
{
	if (!mod.minus)
		buff = printf_addpad(buff, mod, 1);
	if (c)
		buff = ft_arrayaddcharback(buff, c);
	if (mod.minus)
		buff = printf_addpad(buff, mod, 1);
	if (!buff)
		return (-1);
	return (0);
}
