/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:33:46 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/08 14:59:33 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void	modif_new(t_process *new)
{
	while (new->pc < 0)
		new->pc += MEM_SIZE;
	new->nb = get_next_process_nb();
}

int			op_lfork(t_process *p, t_list **all_p, t_info *info, unsigned cycle)
{
	t_process	new;
	t_list		*l;
	unsigned	i;

	(void)info;
	(void)cycle;
	new = *p;
	new.op = 0;
	new.ocp = 0;
	ft_bzero(new.param, sizeof(new.param));
	new.cycle_to_do = 0;
	new.pc += p->param[0];
	if (g_flag.val_v & FLAG_V_OP)
		ft_printf(" (%d)\n", new.pc);
	modif_new(&new);
	i = 0;
	while (g_op_tab[i].opcode && g_op_tab[i].opcode != GET_MEM(g_arena[new.pc]))
		i++;
	if (g_op_tab[i].opcode)
		enter_new_op_in_process(&new, g_op_tab[i]);
	if (!(l = ft_lstnew(&new, sizeof(new))))
		return (0);
	ft_lstadd(all_p, l);
	return (advance_pc(p));
}
