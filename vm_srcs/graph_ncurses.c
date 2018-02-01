/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_ncurses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:17:13 by ddosso-d          #+#    #+#             */
/*   Updated: 2018/01/04 16:17:15 by ddosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	check_input(t_win *win, char *input)
{
	*input = getch();
	if (*input == INPUT_MINUS && win->cps > MIN_CPS)
		win->cps /= MODIF_CPS;
	if (*input == INPUT_PLUS && win->cps < MAX_CPS)
		win->cps *= MODIF_CPS;
	if (*input == INPUT_SPACE)
		(START(win->cases)) ? (win->cases &= ~1) : (win->cases |= 1);
	if (*input == INPUT_ESC)
		win->cases |= 2;
	if (LINES >= BOX_HEIGHT + 2 && COLS >= MAIN_BOX_WIDTH + SUPP_BOX_WIDTH)
		win->cases |= 8;
	else
		win->cases &= ~8;
}

int			print_graph(t_list *l, t_info *info, unsigned cycle)
{
	static t_win	*win = NULL;
	char			input;
	struct timespec	tmp;

	if (!l)
		return (del_win(win));
	if (!win)
		init_win(&win);
	clock_gettime(CLOCK_REALTIME, &win->time);
	readapt_win(win, l, *info, cycle);
	check_input(win, &input);
	while (!START(win->cases) && !ESC(win->cases))
	{
		readapt_win(win, l, *info, cycle);
		check_input(win, &input);
	}
	if (ESC(win->cases))
		return (FAILURE);
	clock_gettime(CLOCK_REALTIME, &tmp);
	while ((tmp.tv_sec - win->time.tv_sec) * 1000000000 +
		(tmp.tv_nsec - win->time.tv_nsec) < 1000000000 / win->cps)
		clock_gettime(CLOCK_REALTIME, &tmp);
	return (SUCCESS);
}
