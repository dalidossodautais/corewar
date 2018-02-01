/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:51:53 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/03 15:03:50 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		op_aff(t_process *p, t_list **all_p, t_info *info, unsigned cycle)
{
	(void)all_p;
	(void)info;
	(void)cycle;
	if (!check_ocp(p) || !check_reg(p))
		return (advance_pc(p));
	ft_putchar(p->reg[p->param[0] - 1] & 0xff);
	return (advance_pc(p));
}
