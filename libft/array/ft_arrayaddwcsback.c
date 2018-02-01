/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayaddwcsback.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:38:19 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/13 16:40:25 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array		*ft_arrayaddwcsback(t_array *buff, const wchar_t *wcs)
{
	while (*wcs)
	{
		buff = ft_arrayaddwcharback(buff, *wcs);
		wcs++;
	}
	return (buff);
}
