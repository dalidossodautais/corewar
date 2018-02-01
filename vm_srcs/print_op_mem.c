/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:06:10 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/05 19:26:54 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		print_op_mem(size_t pos, size_t size)
{
	while (size)
	{
		ft_printf(" %.2x", GET_MEM(g_arena[pos % MEM_SIZE]));
		pos++;
		size--;
	}
}
