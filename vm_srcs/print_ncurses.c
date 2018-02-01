/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ncurses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:03:51 by ddosso-d          #+#    #+#             */
/*   Updated: 2018/01/03 19:03:53 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		print_bytes(t_win *win)
{
	int	i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (COLOR(win->cases))
			wattron(win->main, COLOR_PAIR(GET_PLAYER(g_arena[i])));
		mvwaddch(win->main, 1 + i / 64, 2 + i % 64 * 3,
			LOWHEXA[GET_MEM1(g_arena[i])]);
		mvwaddch(win->main, 1 + i / 64, 3 + i % 64 * 3,
			LOWHEXA[GET_MEM2(g_arena[i])]);
		if (COLOR(win->cases))
			wattroff(win->main, COLOR_PAIR(GET_PLAYER(g_arena[i])));
	}
}

void		print_pc(t_win *win, t_list *l)
{
	while (l)
	{
		if (COLOR(win->cases))
			wattron(win->main,
				COLOR_PAIR(GET_PLAYER(g_arena[LST_PROCESS(l)->pc]) + 10));
		mvwaddch(win->main, 1 + LST_PROCESS(l)->pc / 64,
			2 + LST_PROCESS(l)->pc % 64 * 3,
			LOWHEXA[GET_MEM1(g_arena[LST_PROCESS(l)->pc])]);
		mvwaddch(win->main, 1 + LST_PROCESS(l)->pc / 64,
			3 + LST_PROCESS(l)->pc % 64 * 3,
			LOWHEXA[GET_MEM2(g_arena[LST_PROCESS(l)->pc])]);
		if (COLOR(win->cases))
			wattroff(win->main,
				COLOR_PAIR(GET_PLAYER(g_arena[LST_PROCESS(l)->pc]) + 10));
		l = l->next;
	}
}

void		print_state(t_win *win)
{
	if (START(win->cases))
	{
		if (COLOR(win->cases))
			wattron(win->supp, COLOR_PAIR(21));
		mvwaddstr(win->supp, 1, 1, "En cours");
		if (COLOR(win->cases))
			wattroff(win->supp, COLOR_PAIR(21));
	}
	else
	{
		if (COLOR(win->cases))
			wattron(win->supp, COLOR_PAIR(22));
		mvwaddstr(win->supp, 1, 1, "En pause");
		if (COLOR(win->cases))
			wattroff(win->supp, COLOR_PAIR(22));
	}
}

void		print_player(t_win *win, t_list *l, t_info info)
{
	int	i;

	i = 0;
	while (l)
	{
		l = l->next;
		++i;
	}
	mvwprintw(win->supp, 7, 1, "Processus : %d", i);
	i = -1;
	while (++i < (int)info.nbr_player)
	{
		if (COLOR(win->cases))
			wattron(win->supp, COLOR_PAIR(i + 1));
		mvwprintw(win->supp, 9 + i * 3, 1, "Joueur %d : %s",
			info.champs[i].nb_champ, info.champs[i].header.prog_name);
		mvwprintw(win->supp, 10 + i * 3, 3, "Dernier live : %d",
			info.champs[i].last_live);
		if (COLOR(win->cases))
			wattroff(win->supp, COLOR_PAIR(i + 1));
	}
}

void		print_bonus(t_win *win, t_info info, unsigned cycle)
{
	print_state(win);
	mvwprintw(win->supp, 3, 1, "%d cycles par seconde", win->cps);
	mvwprintw(win->supp, 5, 1, "Cycle : %d", cycle);
	mvwprintw(win->supp, 9 + info.nbr_player * 3, 1,
		"CYCLE_TO_DIE : %d", g_cycle_to_die);
	mvwprintw(win->supp, 11 + info.nbr_player * 3, 1,
		"CYCLE_DELTA : %d", CYCLE_DELTA);
	mvwprintw(win->supp, 13 + info.nbr_player * 3, 1,
		"NBR_LIVE : %d", NBR_LIVE);
	mvwprintw(win->supp, 15 + info.nbr_player * 3, 1,
		"MAX_CHECKS : %d", MAX_CHECKS);
}
