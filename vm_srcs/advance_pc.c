/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance_pc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:24:05 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/05 19:26:43 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static int		ocp_param_size(t_process *p, t_op op)
{
	unsigned	i;
	unsigned	j;

	i = 0;
	j = 0;
	while (j < p->nb_param)
	{
		if (OCP_PARAM(p->ocp, j) == REG_CODE)
			i += 1;
		else if (OCP_PARAM(p->ocp, j) == IND_CODE ||
				(OCP_PARAM(p->ocp, j) == DIR_CODE && op.direquind))
			i += IND_SIZE;
		else if (OCP_PARAM(p->ocp, j) == DIR_CODE)
			i += DIR_SIZE;
		j++;
	}
	return (i);
}

static int		no_ocp_param_size(t_op op)
{
	unsigned	i;
	size_t		s;

	i = 0;
	s = 0;
	while (i < op.nb_param)
	{
		if (op.param_type[i] == T_REG)
			s += 1;
		else if (op.param_type[i] == T_IND ||
				(op.param_type[i] == T_DIR && op.direquind))
			s += IND_SIZE;
		else if (op.param_type[i] == T_DIR)
			s += DIR_SIZE;
		else
			return (0);
		i++;
	}
	return (s);
}

int				advance_pc(t_process *p)
{
	int		i;
	int		j;

	j = 0;
	i = 1;
	while (g_op_tab[j].opcode && g_op_tab[j].opcode != p->op)
		j++;
	if (g_op_tab[j].ocp)
		i += ocp_param_size(p, g_op_tab[j]) + 1;
	else
		i += no_ocp_param_size(g_op_tab[j]);
	if (g_flag.val_v & FLAG_V_PC_MOV)
	{
		ft_printf("ADV %d (0x%.4x -> 0x%.4x)", i, p->pc, p->pc + i);
		print_op_mem(p->pc, i);
		ft_putstr(" \n");
	}
	p->pc += i;
	return (1);
}
