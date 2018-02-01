/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_addparam.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:05:10 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/15 19:04:04 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_printf_flag	g_printf_flag[16] = {
	{'a', &printf_flag_a},
	{'b', &printf_flag_b},
	{'c', &printf_flag_c},
	{'d', &printf_flag_d},
	{'i', &printf_flag_d},
	{'e', &printf_flag_e},
	{'f', &printf_flag_f},
	{'g', &printf_flag_g},
	{'n', &printf_flag_n},
	{'o', &printf_flag_o},
	{'p', &printf_flag_p},
	{'s', &printf_flag_s},
	{'u', &printf_flag_u},
	{'x', &printf_flag_x},
	{'%', &printf_flag_prc},
	{'\0', NULL}
};

const char	*printf_addparam(t_array *buff, const char *restrict format,
							va_list ap)
{
	t_printf_mod	mod;
	int				i;

	if (!*format)
		return (format);
	format++;
	format = printf_searchmod(format, ap, &mod);
	i = 0;
	while (g_printf_flag[i].conv != '\0')
	{
		if (g_printf_flag[i].conv == ft_tolower(*format))
		{
			if ((*g_printf_flag[i].f)(ap, buff, mod) >= 0)
				return (format + 1);
			else
				return (NULL);
		}
		i++;
	}
	if (!(!g_printf_flag[i].conv && printf_wrongconv(*format, buff, mod) >= 0))
		return (NULL);
	return ((*format ? format + 1 : format));
}
