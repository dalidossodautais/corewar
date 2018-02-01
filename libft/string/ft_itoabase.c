/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 11:25:49 by gricquie          #+#    #+#             */
/*   Updated: 2017/03/29 14:11:07 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoabase(unsigned long long n, char *base)
{
	int					i;
	int					baselen;
	char				*tab;
	unsigned long long	nb;

	baselen = ft_strlen(base);
	i = 1;
	nb = n / baselen;
	while (nb > 0)
	{
		nb /= baselen;
		i++;
	}
	if (!(tab = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	tab[i] = '\0';
	while (i > 0)
	{
		tab[--i] = base[n % baselen];
		n /= baselen;
	}
	return (tab);
}
