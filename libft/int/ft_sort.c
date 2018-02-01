/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 12:19:34 by gricquie          #+#    #+#             */
/*   Updated: 2017/06/30 13:18:54 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort(int *tab, size_t size)
{
	size_t	i;
	int		tmp;

	if (size == 0 || size == 1)
		return ;
	i = 1;
	while (i < size)
	{
		if (tab[i - 1] > tab[i])
		{
			tmp = tab[i];
			tab[i] = tab[i - 1];
			tab[i - 1] = tmp;
			i = 0;
		}
		i++;
	}
}
