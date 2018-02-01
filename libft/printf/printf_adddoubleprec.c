/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_adddoubleprec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 14:12:19 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/16 16:43:04 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_array		*printf_adddoubleprec(t_array *buff, long double n, int prec)
{
	if (prec)
		buff = ft_arrayaddcharback(buff, '.');
	n = printf_cutdouble(n, prec);
	while (prec-- > 0)
	{
		n = (n - (LL)n) * 10;
		n += (n < 0 ? -(n - (LL)n < -0.9999) : (n - (LL)n > 0.9999));
		buff = ft_arrayaddcharback(buff,
				(ft_abs((int)n) < 10 ? ft_abs((int)n) : 0) + '0');
	}
	return (buff);
}
