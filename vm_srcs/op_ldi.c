/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:46:37 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/05 19:33:15 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		op_ldi(t_process *p, t_list **all_p, t_info *info, unsigned cycle)
{
	int		s;
	int		t;

	(void)all_p;
	(void)info;
	(void)cycle;
	if (!check_ocp(p) || !check_reg(p))
		return (advance_pc(p));
	if (OCP_PARAM(p->ocp, 0) == REG_CODE)
		s = p->reg[p->param[0] - 1];
	else
		s = p->param[0];
	if (OCP_PARAM(p->ocp, 1) == REG_CODE)
		t = p->reg[p->param[1] - 1];
	else
		t = p->param[1];
	if (g_flag.val_v & FLAG_V_PC_MOV)
		ft_printf("       | -> load from %d + %d = %d", s, t, s + t);
	s = p->pc + (s + t) % IDX_MOD;
	if (g_flag.val_v & FLAG_V_PC_MOV)
		ft_printf(" (with pc and mod %d)\n", s);
	copy_arena(&p->reg[p->param[2] - 1], s, REG_SIZE);
	change_carry(p, p->reg[p->param[2] - 1]);
	return (advance_pc(p));
}
