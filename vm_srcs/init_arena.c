/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:28:52 by gricquie          #+#    #+#             */
/*   Updated: 2017/12/14 17:45:41 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	init_arena(unsigned champ_start[], t_info info)
{
	unsigned	i;
	unsigned	j;

	i = 0;
	ft_bzero(g_arena, sizeof(g_arena));
	while (i < info.nbr_player)
	{
		champ_start[i] = i * MEM_SIZE / info.nbr_player;
		j = 0;
		while (j < info.champs[i].header.prog_size)
		{
			g_arena[j + champ_start[i]] = (info.champs[i].prog[j] & 0xff) |
				((i + 1 & 0xff) << 8);
			j++;
		}
		i++;
	}
}
