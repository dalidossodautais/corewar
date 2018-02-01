/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 10:02:47 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/11 12:33:06 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_flag_s(va_list ap, t_array *buff, t_printf_mod mod)
{
	char	*tmp;
	int		len;

	if (mod.maj || mod.l == 1)
		return (printf_flag_ls(ap, buff, mod));
	tmp = va_arg(ap, char *);
	len = ft_strlen((tmp ? tmp : "(null)"));
	if (mod.prec >= 0)
		len = ft_min(len, mod.prec);
	if (!mod.minus)
		buff = printf_addpad(buff, mod, len);
	buff = ft_arrayaddstrnback(buff, (tmp ? tmp : "(null)"), len);
	if (mod.minus)
		buff = printf_addpad(buff, mod, len);
	if (!buff)
		return (-1);
	return (0);
}
