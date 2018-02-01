/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:17:44 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/24 16:53:29 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		op_store(t_process *p, t_list **all_p, t_info *info, unsigned cycle)
{
	int		s;

	(void)all_p;
	(void)info;
	(void)cycle;
	if (!check_ocp(p) || !check_reg(p))
		return (advance_pc(p));
	if (OCP_PARAM(p->ocp, 1) == REG_CODE)
		p->reg[p->param[1] - 1] = p->reg[p->param[0] - 1];
	else
	{
		s = p->param[1];
		copy_in_arena(p->pc + s % IDX_MOD, p->reg[p->param[0] - 1],
				REG_SIZE, GET_PLAYER(g_arena[p->pc]));
	}
	return (advance_pc(p));
}
