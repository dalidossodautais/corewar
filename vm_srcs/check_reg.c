/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:59:59 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/03 15:26:16 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		check_reg(t_process *p)
{
	unsigned	i;

	i = 0;
	while (i < p->nb_param)
	{
		if (OCP_PARAM(p->ocp, i) == REG_CODE)
		{
			if (p->param[i] > REG_NUMBER || p->param[i] <= 0)
				return (0);
		}
		i++;
	}
	return (1);
}
