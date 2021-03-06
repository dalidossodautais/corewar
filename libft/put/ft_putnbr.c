/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:57:13 by gricquie          #+#    #+#             */
/*   Updated: 2017/01/29 02:29:01 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr(long long int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n >= 10)
		i = ft_putnbr(n / 10);
	ft_putchar((char)(n % 10 + 48));
	return (i + 1);
}
