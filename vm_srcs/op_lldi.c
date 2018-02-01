/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:46:37 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/05 19:27:30 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		op_lldi(t_process *p, t_list **all_p, t_info *info, unsigned cycle)
{
	int		s;
	int		tmp;

	(void)all_p;
	(void)info;
	(void)cycle;
	if (!check_ocp(p) || !check_reg(p))
		return (advance_pc(p));
	if (OCP_PARAM(p->ocp, 0) == REG_CODE)
		s = p->reg[p->param[0] - 1];
	else
		copy_arena(&s, p->param[0] + p->pc, DIR_SIZE);
	if (OCP_PARAM(p->ocp, 1) == REG_CODE)
		tmp = p->reg[p->param[1] - 1];
	else
		copy_arena(&tmp, p->param[1] + p->pc, DIR_SIZE);
	copy_arena(&p->reg[p->param[2] - 1], p->pc + s, REG_SIZE);
	change_carry(p, p->reg[p->param[2] - 1]);
	return (advance_pc(p));
}
