/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayaddwcharback.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:23:14 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/15 19:07:06 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array		*ft_arrayaddwcharback(t_array *a, wchar_t wc)
{
	if (wc < 0x80 || (wc < 0x100 && MB_CUR_MAX == 1))
		return (ft_arrayaddcharback(a, wc));
	if (wc < 0x800 && MB_CUR_MAX >= 2)
	{
		a = ft_arrayaddcharback(a, wc / 0x40 + 0xc0);
		return (ft_arrayaddcharback(a, wc % 0x40 + 0x80));
	}
	if (wc < 0x10000 && MB_CUR_MAX >= 3)
	{
		a = ft_arrayaddcharback(a, wc / 0x1000 + 0xe0);
		a = ft_arrayaddcharback(a, wc / 0x40 - wc / 0x1000 * 0x40 + 0x80);
		return (ft_arrayaddcharback(a, wc % 0x40 + 0x80));
	}
	else if (MB_CUR_MAX >= 4)
	{
		a = ft_arrayaddcharback(a, wc / 0x40000 + 0xf0);
		a = ft_arrayaddcharback(a, wc / 0x1000 - wc / 0x40000 * 0x1000 + 0x80);
		a = ft_arrayaddcharback(a, wc / 0x40 - wc / 0x1000 * 0x40 + 0x80);
		return (ft_arrayaddcharback(a, wc % 0x40 + 0x80));
	}
	return (a);
}
