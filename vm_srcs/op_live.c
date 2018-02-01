/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:55:52 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/05 15:11:00 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		op_live(t_process *p, t_list **all_p, t_info *info, unsigned cycle)
{
	unsigned	i;

	(void)all_p;
	p->last_live = cycle;
	i = 0;
	while (i < info->nbr_player)
	{
		if (info->champs[i].nb_champ == p->param[0])
		{
			if (g_flag.val_v & FLAG_V_LIVES)
				ft_printf("Player %d (%s) is said to be alive\n",
						i + 1, info->champs[i].header.prog_name);
			info->champs[i].last_live = cycle;
		}
		i++;
	}
	g_nb_live++;
	return (advance_pc(p));
}
