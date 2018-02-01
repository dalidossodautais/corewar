/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ocp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:37:24 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/03 15:36:54 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		check_ocp(t_process *p)
{
	unsigned	i;
	unsigned	ocp_param;

	i = 0;
	while (i < p->nb_param)
	{
		ocp_param = OCP_PARAM(p->ocp, i);
		if (!ocp_param)
			return (0);
		if (ocp_param == REG_CODE && !(p->prototype[i] & T_REG))
			return (0);
		else if (ocp_param == IND_CODE && !(p->prototype[i] & T_IND))
			return (0);
		else if (ocp_param == DIR_CODE && !(p->prototype[i] & T_DIR))
			return (0);
		i++;
	}
	return (1);
}
