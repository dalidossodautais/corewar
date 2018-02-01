/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:21:30 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/04 15:56:36 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

t_op	get_op(char opcode)
{
	unsigned	i;

	i = 0;
	while (g_op_tab[i].opcode && g_op_tab[i].opcode != opcode)
		i++;
	return (g_op_tab[i]);
}
