/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reversebyte.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 12:37:55 by gricquie          #+#    #+#             */
/*   Updated: 2017/09/13 12:45:12 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_reversebyte(void *bytes, size_t size)
{
	size_t	i;
	char	c;

	i = 0;
	while (i < size / 2)
	{
		c = ((char *)bytes)[i];
		((char *)bytes)[i] = ((char *)bytes)[size - i - 1];
		((char *)bytes)[size - i - 1] = c;
		i++;
	}
}
