/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 11:25:49 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/16 16:45:45 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(long long int n)
{
	char		*tab;
	int			i;
	long long	nb;

	i = 1;
	nb = n / 10;
	while (ft_abs(nb) > 0)
	{
		nb /= 10;
		i++;
	}
	if (!(tab = malloc(sizeof(char) * (i + (n < 0) + 1))))
		return (NULL);
	tab[i + (n < 0)] = '\0';
	if (n < 0)
		tab[0] = '-';
	while (i + (n < 0) > 0)
	{
		tab[--i + (n < 0)] = n % 10;
		n /= 10;
	}
	return (tab);
}
