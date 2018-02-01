/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:05:30 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/10 17:46:27 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	get_param_second(t_process *p, t_op op, unsigned pi, unsigned *a)
{
	unsigned	size;

	p->param[pi] = 0;
	if (p->ocp && (OCP_PARAM(p->ocp, pi) == IND_CODE ||
		(OCP_PARAM(p->ocp, pi) == DIR_CODE && op.direquind)))
	{
		copy_arena(&p->param[pi], p->pc + *a, IND_SIZE);
		*a += IND_SIZE;
	}
	else
	{
		size = (!op.ocp || OCP_PARAM(p->ocp, pi) == DIR_CODE) ? DIR_SIZE : 1;
		copy_arena(&p->param[pi], p->pc + *a, size);
		*a += size;
	}
}

void	get_param(t_process *p, t_op op)
{
	unsigned	pi;
	unsigned	a;
	unsigned	size;

	p->ocp = (op.ocp ? GET_MEM(g_arena[(p->pc + 1) % MEM_SIZE]) : 0);
	a = op.ocp + 1;
	pi = 0;
	if (!p->ocp)
	{
		size = (op.direquind ? IND_SIZE : DIR_SIZE);
		copy_arena(&p->param[0], p->pc + 1, size);
		return ;
	}
	while (pi < op.nb_param)
	{
		get_param_second(p, op, pi, &a);
		pi++;
	}
}
