/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   announce_winner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:24:21 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/23 15:30:31 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	announce_winner(t_info info)
{
	int			i;
	size_t		winner;
	int			winner_last_live;

	winner = 0;
	winner_last_live = 0;
	i = info.nbr_player - 1;
	while (i >= 0)
	{
		if (winner_last_live < info.champs[i].last_live)
		{
			winner_last_live = info.champs[i].last_live;
			winner = i;
		}
		i--;
	}
	ft_printf(ANNOUNCE_WINNER "\n", winner + 1,
			info.champs[winner].header.prog_name);
}
