/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:08:15 by gricquie          #+#    #+#             */
/*   Updated: 2017/02/25 00:55:22 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwchar(wchar_t c)
{
	if (c < 0x80)
		ft_putchar(c);
	else if (c < 0x800)
	{
		ft_putchar(c / 0x40 + 0xc0);
		ft_putchar(c % 0x40 + 0x80);
	}
	else if (c < 0x10000)
	{
		ft_putchar(c / 0x1000 + 0xe0);
		ft_putchar(c / 0x40 - c / 0x1000 * 0x40 + 0x80);
		ft_putchar(c % 0x40 + 0x80);
	}
	else
	{
		ft_putchar(c / 0x40000 + 0xf0);
		ft_putchar(c / 0x1000 - c / 0x40000 * 0x1000 + 0x80);
		ft_putchar(c / 0x40 - c / 0x1000 * 0x40 + 0x80);
		ft_putchar(c % 0x40 + 0x80);
	}
	return (1);
}
