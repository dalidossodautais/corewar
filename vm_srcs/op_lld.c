/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:09:26 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/03 15:05:48 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		op_lld(t_process *p, t_list **all_p, t_info *info, unsigned cycle)
{
	(void)all_p;
	(void)cycle;
	(void)info;
	if (!check_ocp(p) || !check_reg(p))
		return (advance_pc(p));
	if (OCP_PARAM(p->ocp, 0) == IND_CODE)
		copy_arena(&p->reg[p->param[1] - 1], p->param[0] + p->pc, REG_SIZE);
	else
		p->reg[p->param[1] - 1] = p->param[0];
	change_carry(p, p->reg[p->param[1] - 1]);
	return (advance_pc(p));
}
