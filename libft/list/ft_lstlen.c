/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 23:00:51 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/08 23:08:45 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t		ft_lstlen(t_list *l)
{
	size_t	i;

	i = 0;
	while (l)
	{
		i++;
		l = l->next;
	}
	return (i);
}