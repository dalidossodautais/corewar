/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:14:12 by ddosso-d          #+#    #+#             */
/*   Updated: 2017/12/14 17:50:32 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	dump(int mem[])
{
	int	i;
	int	j;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.7x ", i);
		j = 0;
		while (i + j + 1 < MEM_SIZE && j + 1 < DUMP_BYTE_PER_LINE)
		{
			ft_printf("%.2hhx ", GET_MEM(mem[i + j]));
			++j;
		}
		ft_printf("%.2hhx\n", GET_MEM(mem[i + j]));
		i += j + 1;
	}
	ft_printf("%.7x\n", i);
}
