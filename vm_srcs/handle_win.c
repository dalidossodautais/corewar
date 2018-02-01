/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:00:27 by ddosso-d          #+#    #+#             */
/*   Updated: 2018/01/03 19:00:31 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			init_win(t_win **win)
{
	if (!((*win) = (t_win *)malloc(sizeof(t_win))))
		return (ERROR);
	initscr();
	cbreak();
	nodelay(stdscr, TRUE);
	curs_set(0);
	if (((*win)->cases =
		4 * (has_colors() == TRUE && can_change_color() == TRUE)))
	{
		start_color();
		init_color(COLOR_WHITE, 1000, 1000, 1000);
		init_pair(10, COLOR_BLACK, COLOR_WHITE);
		init_pair(1, COLOR_P1, COLOR_BLACK);
		init_pair(11, COLOR_P1, COLOR_WHITE);
		init_pair(2, COLOR_P2, COLOR_BLACK);
		init_pair(12, COLOR_P2, COLOR_WHITE);
		init_pair(3, COLOR_P3, COLOR_BLACK);
		init_pair(13, COLOR_P3, COLOR_WHITE);
		init_pair(4, COLOR_P4, COLOR_BLACK);
		init_pair(14, COLOR_P4, COLOR_WHITE);
		init_pair(21, COLOR_GREEN, COLOR_BLACK);
		init_pair(22, COLOR_RED, COLOR_BLACK);
	}
	(*win)->cps = BASE_CPS;
	return (SUCCESS);
}

WINDOW		*create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0, 0);
	return (local_win);
}

int			del_win(t_win *win)
{
	free(win);
	endwin();
	return (SUCCESS);
}

void		readapt_win(t_win *win, t_list *l, t_info info, unsigned cycle)
{
	delwin(win->main);
	delwin(win->supp);
	win->main = create_newwin(BOX_HEIGHT, MAIN_BOX_WIDTH, 0, 0);
	print_bytes(win);
	print_pc(win, l);
	wrefresh(win->main);
	if (SIZE(win->cases))
	{
		win->supp = create_newwin(BOX_HEIGHT, SUPP_BOX_WIDTH, 0,
			MAIN_BOX_WIDTH + 1);
		print_state(win);
		print_player(win, l, info);
		print_bonus(win, info, cycle);
		wrefresh(win->supp);
	}
}
