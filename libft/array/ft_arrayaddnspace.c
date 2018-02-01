/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayaddnspace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 14:45:20 by gricquie          #+#    #+#             */
/*   Updated: 2017/08/04 14:50:27 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array.h>
#include <ft_printf.h>

t_array		*ft_arrayaddnspace(t_array *a, size_t n)
{
	size_t	spacesize;

	spacesize = ft_strlen(SPACES);
	while (n > 0)
	{
		a = ft_arrayaddstrnback(a, SPACES, n);
		if (n < spacesize)
			n = 0;
		else
			n -= spacesize;
	}
	return (a);
}
