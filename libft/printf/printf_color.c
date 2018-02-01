/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 12:21:49 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/13 17:10:03 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*printf_color(t_array *buff, const char *restrict str)
{
	int		dec;

	dec = 0;
	if (ft_strnequ(str, "{eoc}", (dec = 4)))
		buff = ft_arrayaddstrback(buff, "\033[0m");
	else if (ft_strnequ(str, "{black}", (dec = 6)))
		buff = ft_arrayaddstrback(buff, "\033[30m");
	else if (ft_strnequ(str, "{red}", (dec = 4)))
		buff = ft_arrayaddstrback(buff, "\033[31m");
	else if (ft_strnequ(str, "{green}", (dec = 6)))
		buff = ft_arrayaddstrback(buff, "\033[32m");
	else if (ft_strnequ(str, "{yellow}", (dec = 7)))
		buff = ft_arrayaddstrback(buff, "\033[33m");
	else if (ft_strnequ(str, "{blue}", (dec = 5)))
		buff = ft_arrayaddstrback(buff, "\033[34m");
	else if (ft_strnequ(str, "{magenta}", (dec = 8)))
		buff = ft_arrayaddstrback(buff, "\033[35m");
	else if (ft_strnequ(str, "{cyan}", (dec = 5)))
		buff = ft_arrayaddstrback(buff, "\033[36m");
	else if (ft_strnequ(str, "{white}", (dec = 6)))
		buff = ft_arrayaddstrback(buff, "\033[37m");
	else if (!(dec = 0))
		buff = ft_arrayaddcharback(buff, '{');
	return ((buff ? str + dec + 1 : NULL));
}
