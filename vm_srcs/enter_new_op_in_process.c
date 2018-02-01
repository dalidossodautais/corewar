/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_new_op_in_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 14:28:37 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/08 12:04:22 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	enter_new_op_in_process(t_process *p, t_op op)
{
	p->op = op.opcode;
	p->cycle_to_do = op.nb_cycles;
	p->nb_param = op.nb_param;
	ft_memcpy(p->prototype, op.param_type, sizeof(p->prototype));
}
