/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:57:13 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/23 17:44:17 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putbase(ULL n, char *base)
{
	int		i;
	size_t	baselen;

	i = 0;
	baselen = ft_strlen(base);
	if (n >= baselen)
		i = ft_putbase(n / baselen, base);
	ft_putchar((char)(base[n % baselen]));
	return (i + 1);
}
