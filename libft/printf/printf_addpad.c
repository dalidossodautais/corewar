/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_addpad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:29:48 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/14 19:21:08 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_array		*printf_addpad(t_array *buff, t_printf_mod mod, long int len)
{
	if (len < 0)
		return (buff);
	while (mod.width > len)
	{
		buff = ft_arrayaddstrnback(buff, (mod.zero ? ZEROS : SPACES),
									mod.width - len);
		mod.width -= ft_strlen(mod.zero ? ZEROS : SPACES);
	}
	return (buff);
}
