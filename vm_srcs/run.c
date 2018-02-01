/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:17:19 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/10 19:12:17 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void		reset_process(t_process *p)
{
	p->cycle_to_do = 0;
	p->op = 0;
	p->ocp = 0;
	p->nb_param = 0;
	ft_bzero(p->prototype, sizeof(p->prototype));
	ft_bzero(p->param, sizeof(p->param));
}

static void		enter_all_new_op(t_list *p)
{
	t_op	op;

	while (p)
	{
		if (!LST_PROCESS(p)->cycle_to_do)
		{
			op = get_op(GET_MEM(g_arena[LST_PROCESS(p)->pc % MEM_SIZE]));
			enter_new_op_in_process(p->content, op);
		}
		p = p->next;
	}
}

static int		do_process(t_list **process, t_info *info, unsigned cycle)
{
	t_list	*cur;

	cur = *process;
	while (cur)
	{
		while (LST_PROCESS(cur)->pc < 0)
			LST_PROCESS(cur)->pc += MEM_SIZE;
		LST_PROCESS(cur)->pc %= MEM_SIZE;
		if (LST_PROCESS(cur)->cycle_to_do)
			LST_PROCESS(cur)->cycle_to_do--;
		if (!LST_PROCESS(cur)->cycle_to_do)
		{
			if (!(do_op(cur->content, process, info, cycle)))
				return (0);
			reset_process(cur->content);
		}
		cur = cur->next;
	}
	enter_all_new_op(*process);
	return (1);
}

static int		exit_run(t_list **process, int ret)
{
	ft_lstdel(process, (t_fdel) & free);
	return (ret);
}

int				run(t_list *process, t_info *info)
{
	int			cycle;
	int			cycle_to_check;

	cycle = 0;
	cycle_to_check = g_cycle_to_die;
	while (++cycle && process)
	{
		if (g_flag.val_v & FLAG_V_CYCLES)
			ft_printf("It is now cycle %d\n", cycle);
		if (!(do_process(&process, info, cycle)))
			return (exit_run(&process, 0));
		if (g_flag.exist & FLAG_D && cycle == g_flag.val_d)
		{
			dump(g_arena);
			return (exit_run(&process, 2));
		}
		if (g_flag.exist & FLAG_S && !(cycle % g_flag.val_s))
			dump(g_arena);
		if (g_flag.exist & FLAG_C &&
				print_graph(process, info, cycle) == FAILURE)
			return (exit_run(&process, 2));
		if (--cycle_to_check <= 0)
			check_live(&process, cycle, &cycle_to_check);
	}
	return (1);
}
