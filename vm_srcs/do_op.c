/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:46:12 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/08 12:49:29 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static const t_func_tab	g_func_tab[17] = {
	{1, &op_live},
	{2, &op_load},
	{3, &op_store},
	{4, &op_add},
	{5, &op_sub},
	{6, &op_and},
	{7, &op_or},
	{8, &op_xor},
	{9, &op_zjmp},
	{10, &op_ldi},
	{11, &op_sti},
	{12, &op_fork},
	{13, &op_lld},
	{14, &op_lldi},
	{15, &op_lfork},
	{16, &op_aff},
	{0, 0}
};

void		print_op_second(t_process *p, t_op op, int i)
{
	if (OCP_PARAM(p->ocp, i) == REG_CODE
			&& !(op.param_type[i] & (T_DIR | T_IND) && check_reg(p)))
		ft_printf(" r");
	else
		ft_printf(" ");
	if (OCP_PARAM(p->ocp, i) == REG_CODE && check_ocp(p)
			&& op.param_type[i] & (T_DIR | T_IND) && check_reg(p))
		ft_printf("%d", p->reg[p->param[i] - 1]);
	else
		ft_printf("%d", p->param[i]);
}

static void	print_op_param(t_process *p, t_op op)
{
	unsigned	i;

	i = 0;
	if (!op.ocp)
	{
		if (op.param_type[0] == T_REG)
			i = 1;
		else if (op.param_type[0] == T_IND
				|| (op.param_type[0] == T_DIR && op.direquind))
			i = IND_SIZE;
		else if (op.param_type[0] == T_DIR)
			i = DIR_SIZE;
		ft_printf(" %d", p->param[0]);
	}
	else
		while (i < op.nb_param)
		{
			print_op_second(p, op, i);
			i++;
		}
	if (op.opcode != 9 && op.opcode != 12 && op.opcode != 15)
		ft_printf("\n");
}

int			do_op(t_process *p, t_list **all_process, t_info *info,
	unsigned cycle)
{
	int		i;
	int		ret;
	t_op	op;

	i = 0;
	while (g_func_tab[i].opcode && g_func_tab[i].opcode != p->op)
		i++;
	if (!p->ocp && get_op(p->op).direquind)
		copy_arena(&p->param[0], p->pc + 1, IND_SIZE);
	op = get_op(p->op);
	get_param(p, op);
	if (p->op && g_flag.val_v & FLAG_V_OP && (!op.ocp || check_ocp(p)))
	{
		ft_printf("P %4d | %s", p->nb, g_op_tab[i].name);
		print_op_param(p, g_op_tab[i]);
	}
	ret = (g_func_tab[i].f) ?
		(*g_func_tab[i].f)(p, all_process, info, cycle) : 1;
	if (!g_func_tab[i].f)
		p->pc++;
	return (ret);
}
