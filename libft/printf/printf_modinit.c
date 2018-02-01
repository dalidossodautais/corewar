/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:51:18 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/16 16:41:47 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*calc_pad(const char *restrict str, va_list ap, char *width)
{
	if (*str == '*')
	{
		*width = va_arg(ap, int);
		return (str);
	}
	*width = ft_atoi(str);
	while (ft_isdigit(*str) || *str == '-')
		str++;
	str--;
	return (str);
}

static const char	*calc_prec(const char *restrict str, va_list ap, char *prec)
{
	if (*str != '.')
		return (0);
	str++;
	if (*str == '*')
	{
		*prec = va_arg(ap, int);
		if (*prec < 0)
			*prec = -1;
		return (str);
	}
	*prec = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	str--;
	return (str);
}

void				init_mod(t_printf_mod *mod)
{
	mod->width = 0;
	mod->prec = -1;
	mod->maj = 0;
	mod->zero = 0;
	mod->minus = 0;
	mod->sharp = 0;
	mod->plus = 0;
	mod->space = 0;
	mod->l = 0;
	mod->apos = 0;
	mod->ml = 0;
	mod->valid = 1;
}

static const char	*fill_mod(t_printf_mod *mod, const char *restrict str,
						va_list ap)
{
	if ((ft_isdigit(*str) && *str != '0') || *str == '*')
		str = calc_pad(str, ap, &mod->width);
	else if (*str == '.')
		str = calc_prec(str, ap, &mod->prec);
	else if (*str == '#')
		mod->sharp += 1;
	else if (*str == '0')
		mod->zero += 1;
	else if (*str == '-')
		mod->minus += 1;
	else if (*str == '+')
		mod->plus = 1;
	else if (*str == ' ')
		mod->space += 1;
	else if (*str == 'h' && mod->l <= 0)
		mod->l--;
	else if (*str == 'l' || *str == 'j' || *str == 'z')
		mod->l++;
	else if (*str == *"'")
		mod->apos++;
	else if (*str == 'L')
		mod->ml++;
	else
		mod->valid = 0;
	return (str);
}

const char			*printf_searchmod(const char *restrict str, va_list ap,
				t_printf_mod *mod)
{
	init_mod(mod);
	while (*str && (ft_isdigit(*str) || ft_strchr(PRINTF_MOD, *str)))
	{
		str = fill_mod(mod, str, ap);
		str++;
	}
	if (mod->width < 0)
		mod->minus = 1;
	mod->width = ft_abs(mod->width);
	if (mod->minus || mod->zero > 1 || (mod->prec > -1 && *str == 'd'))
		mod->zero = 0;
	if (mod->sharp > 1)
		mod->sharp = 0;
	if (ft_isupper(*str))
		mod->maj = 1;
	if (*str == 'D' || *str == 'O' || *str == 'U')
		mod->l = 1;
	if (!ft_strchr(PRINTF_CONV, *str))
		mod->valid = 0;
	return (str);
}
