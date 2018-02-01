/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_in_arena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:13:57 by gricquie          #+#    #+#             */
/*   Updated: 2017/12/22 16:24:42 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	copy_in_arena(int pos, int src, size_t size, int player)
{
	size_t	i;

	i = 0;
	if (pos < 0)
		pos += MEM_SIZE;
	while (i < size)
	{
		g_arena[(pos + i) % MEM_SIZE] = ((src >> (size - i - 1) * 8) & 0xff) |
			((player & 0xff) << 8);
		i++;
	}
}
