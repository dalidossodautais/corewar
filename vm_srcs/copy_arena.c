/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:57:48 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/05 19:29:42 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	copy_arena(int *reg, int pos, size_t size)
{
	size_t	i;

	i = 0;
	*reg = 0;
	if (pos < 0)
		pos += MEM_SIZE;
	while (i < size)
	{
		*reg |=
			GET_MEM(g_arena[(pos + i) % MEM_SIZE]) << (size - i - 1) * 8;
		i++;
	}
	if (size != DIR_SIZE)
	{
		if (*reg & (1 << ((size * 8) - 1)))
			*reg -= (1 << (size * 8));
	}
}
