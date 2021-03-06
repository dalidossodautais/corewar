/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:03:13 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/13 17:11:27 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	const char	*ptr;
	int			len;
	t_array		*buff;

	va_start(ap, format);
	if (!format)
		return (-1);
	buff = ft_arraynew("");
	while (*format && buff)
	{
		ptr = format;
		while (*ptr && *ptr != '%' && *ptr != '{')
			ptr++;
		buff = ft_arrayaddstrnback(buff, format, ptr - format);
		if (*ptr == '%' && !(format = printf_addparam(buff, ptr, ap)))
			return (-1);
		else if (*ptr == '{' && !(format = printf_color(buff, ptr)))
			return (-1);
		(!*ptr ? format = ptr : 0);
	}
	va_end(ap);
	len = ft_arrayprint(buff);
	ft_arraydel(&buff);
	return ((format ? len : -1));
}
