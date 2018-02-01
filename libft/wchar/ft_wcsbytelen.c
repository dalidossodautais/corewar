/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsbytelen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:17:45 by gricquie          #+#    #+#             */
/*   Updated: 2017/03/29 08:07:28 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wcsbytelen(wchar_t *wcs)
{
	size_t		len;

	len = 0;
	while (*wcs)
	{
		len += ft_wcharbytelen(*wcs);
		wcs++;
	}
	return (len);
}
