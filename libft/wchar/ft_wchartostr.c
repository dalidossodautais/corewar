/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchartostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:01:34 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/04 16:32:17 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*onechar(wchar_t wc)
{
	char	*ret;

	ret = malloc(sizeof(char) * 2);
	ret[0] = wc;
	ret[1] = '\0';
	return (ret);
}

static char	*twochar(wchar_t wc)
{
	char	*ret;

	ret = malloc(sizeof(char) * 3);
	ret[0] = wc / 0x40 + 0xc0;
	ret[1] = wc % 0x40 + 0x80;
	ret[2] = '\0';
	return (ret);
}

static char	*threechar(wchar_t wc)
{
	char	*ret;

	ret = malloc(sizeof(char) * 4);
	ret[0] = wc / 0x1000 + 0xe0;
	ret[1] = wc % 0x1000 / 0x40 + 0x80;
	ret[2] = wc % 0x40 + 0x80;
	ret[3] = '\0';
	return (ret);
}

static char	*fourchar(wchar_t wc)
{
	char	*ret;

	ret = malloc(sizeof(char) * 5);
	ret[0] = wc / 0x40000 + 0xf0;
	ret[1] = wc % 0x40000 / 0x1000 + 0x80;
	ret[2] = wc % 0x1000 / 0x40 + 0x80;
	ret[3] = wc % 0x40 + 0x80;
	ret[4] = '\0';
	return (ret);
}

char		*ft_wchartostr(wchar_t wc)
{
	if (wc < 0x80 || (MB_CUR_MAX == 1 && wc < 0x100))
		return (onechar(wc));
	else if (wc < 0x800 && MB_CUR_MAX > 1)
		return (twochar(wc));
	else if (wc < 0x10000 && MB_CUR_MAX > 2)
		return (threechar(wc));
	else if (MB_CUR_MAX > 3)
		return (fourchar(wc));
	return (NULL);
}
