/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:09:42 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/10 18:15:56 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	check_live2(unsigned *checks)
{
	if (g_nb_live > NBR_LIVE || *checks >= MAX_CHECKS)
	{
		g_cycle_to_die -= CYCLE_DELTA;
		if (g_flag.val_v & FLAG_V_CYCLES)
			ft_printf("Cycle to die is now %d\n", g_cycle_to_die);
		*checks = 0;
	}
}

void	check_live(t_list **all_p, int cycle, int *cycle_to_check)
{
	t_list			*l;
	t_list			*tmp;
	static unsigned	checks = 0;

	l = *all_p;
	while (l)
	{
		tmp = l->next;
		if (LST_PROCESS(l)->last_live <= cycle - g_cycle_to_die)
		{
			if (g_flag.val_v & FLAG_V_DEATHS)
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
						LST_PROCESS(l)->nb, cycle - LST_PROCESS(l)->last_live,
						g_cycle_to_die);
			*all_p = ft_lstdeljoin(*all_p, l, (t_fdel) & free);
		}
		l = tmp;
	}
	checks++;
	check_live2(&checks);
	g_nb_live = 0;
	*cycle_to_check = g_cycle_to_die;
}
