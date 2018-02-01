/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcswrite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 20:59:26 by gricquie          #+#    #+#             */
/*   Updated: 2017/03/15 14:15:18 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_wcswrite(wchar_t *wcs, int len)
{
	int		i;

	i = 0;
	if (!wcs)
		return (ft_putstr("(null)"));
	while (i < len)
		i += ft_putwchar(wcs[i]);
	return (i);
}
