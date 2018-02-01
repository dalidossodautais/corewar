/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:19:41 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/24 16:54:36 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		op_zjmp(t_process *p, t_list **all_p, t_info *info, unsigned cycle)
{
	(void)all_p;
	(void)info;
	(void)cycle;
	if (p->carry)
	{
		p->pc += p->param[0] % IDX_MOD;
		if (p->pc < 0)
			p->pc += MEM_SIZE;
		p->pc %= MEM_SIZE;
		if (g_flag.val_v & FLAG_V_OP)
			ft_putendl(" OK");
		return (1);
	}
	if (g_flag.val_v & FLAG_V_OP)
		ft_putendl(" FAILED");
	return (advance_pc(p));
}
