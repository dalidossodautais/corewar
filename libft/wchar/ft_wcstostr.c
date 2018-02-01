/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:21:03 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/06 19:22:59 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wcstostr(wchar_t *wcs)
{
	char	*ret;
	char	*tmp;

	ret = ft_strdup("");
	while (wcs && *wcs)
	{
		tmp = ft_wchartostr(*wcs);
		if (tmp)
			ret = ft_strdeljoin(ret, tmp, DELBOTH);
		else
		{
			free(ret);
			return (NULL);
		}
		wcs++;
	}
	return (ret);
}
