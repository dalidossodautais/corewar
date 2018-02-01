/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:44:02 by ddosso-d          #+#    #+#             */
/*   Updated: 2018/01/04 16:16:30 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int ac, char **av)
{
	t_info		info;
	unsigned	champ_start[MAX_PLAYERS];
	t_list		*process;
	int			ret;

	ft_bzero(&info, sizeof(info));
	ft_bzero(&g_flag, sizeof(g_flag));
	if (!read_args(&info, &g_flag, ac, av))
		return (EXIT_FAILURE);
	intro_champs(info);
	init_arena(champ_start, info);
	if (!(init_process(&process, champ_start, info)))
		return (EXIT_FAILURE);
	g_nb_live = 0;
	g_cycle_to_die = CYCLE_TO_DIE;
	ret = run(process, &info);
	if (g_flag.exist & FLAG_C)
		print_graph(NULL, NULL, 0);
	if (!ret)
		ft_lstdel(&process, (t_fdel) & free);
	if (!ret)
		return (EXIT_FAILURE);
	if (ret == 1)
		announce_winner(info);
	return (EXIT_SUCCESS);
}
