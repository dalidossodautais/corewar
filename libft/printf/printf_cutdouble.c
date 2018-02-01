/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_cutdouble.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 12:22:40 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/16 16:42:01 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double		printf_cutdouble(long double n, int prec)
{
	int		i;

	i = prec;
	while (i-- >= 0)
		n *= 10;
	if (ft_abs(n - (long int)n) >= 0.5)
		n += (n > 0 ? 1 : -1);
	while (++i < prec)
		n /= 10;
	return (n);
}
