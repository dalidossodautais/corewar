/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:34:07 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/03 15:03:37 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int			op_add(t_process *p, t_list **all_p, t_info *info, unsigned cycle)
{
	(void)all_p;
	(void)info;
	(void)cycle;
	if (!check_ocp(p) || !check_reg(p))
		return (advance_pc(p));
	p->reg[p->param[2] - 1] = p->reg[p->param[0] - 1] + p->reg[p->param[1] - 1];
	change_carry(p, p->reg[p->param[2] - 1]);
	return (advance_pc(p));
}
