/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:24:25 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/11 13:16:29 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *tab, size_t oldsize, size_t newsize)
{
	void			*ntab;

	if (!(ntab = malloc(newsize)))
		return (NULL);
	if (tab != NULL)
	{
		ft_memcpy(ntab, tab, oldsize);
		free(tab);
	}
	return (ntab);
}
