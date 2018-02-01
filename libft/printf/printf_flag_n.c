/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 19:32:13 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/12 17:12:08 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_flag_n(va_list ap, t_array *buff, t_printf_mod mod)
{
	int		*n;

	n = va_arg(ap, int *);
	*n = (buff ? buff->size : -1);
	(void)mod;
	return (0);
}
