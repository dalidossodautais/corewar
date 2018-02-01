/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:44:37 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/08 12:37:04 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		init_process(t_list **process, unsigned champ_start[], t_info info)
{
	unsigned	i;
	unsigned	j;
	t_list		*new;
	t_process	p;

	i = 0;
	*process = NULL;
	while (i < info.nbr_player)
	{
		ft_bzero(&p, sizeof(p));
		p.pc = champ_start[i];
		p.reg[0] = info.champs[i].nb_champ;
		p.nb = get_next_process_nb();
		j = 0;
		while (g_op_tab[j].opcode &&
				g_op_tab[j].opcode != GET_MEM(g_arena[p.pc]))
			j++;
		if (g_op_tab[j].opcode)
			enter_new_op_in_process(&p, g_op_tab[j]);
		if (!(new = ft_lstnew(&p, sizeof(p))))
			return (error(ERROR_ALLOC));
		ft_lstadd(process, new);
		i++;
	}
	return (1);
}
