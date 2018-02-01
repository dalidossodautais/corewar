/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_addprec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:52:04 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/11 17:48:33 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_array		*printf_addprec(t_array *buff, t_printf_mod mod, long int len)
{
	if (mod.prec < 0 || len < 0 || mod.prec < len)
		return (buff);
	while (mod.prec > len)
	{
		buff = ft_arrayaddstrnback(buff, ZEROS, mod.prec - len);
		mod.prec -= ft_strlen(ZEROS);
	}
	return (buff);
}
