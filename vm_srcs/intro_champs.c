/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro_champs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 12:04:34 by gricquie          #+#    #+#             */
/*   Updated: 2017/11/28 16:05:23 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	intro_champs(t_info info)
{
	unsigned	i;

	ft_putendl(INTRO_LINE);
	i = 0;
	while (i < info.nbr_player)
	{
		ft_printf(INTRO_CHAMP "\n",
				i + 1,
				info.champs[i].header.prog_size,
				info.champs[i].header.prog_name,
				info.champs[i].header.comment);
		i++;
	}
}
