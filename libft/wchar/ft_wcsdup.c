/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 11:31:25 by gricquie          #+#    #+#             */
/*   Updated: 2017/08/18 14:51:55 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

wchar_t		*ft_wcsdup(const wchar_t *wcs)
{
	wchar_t		*tmp;
	int			i;

	tmp = malloc(sizeof(wchar_t) * (ft_wcslen(wcs) + 1));
	i = 0;
	while (wcs[i])
	{
		tmp[i] = wcs[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
