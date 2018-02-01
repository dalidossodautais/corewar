/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 08:29:46 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/11 13:29:32 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddback(t_list *begin, t_list *new)
{
	t_list	*b;

	b = begin;
	if (!new)
		return (begin);
	if (!begin)
		return (new);
	while (begin->next)
		begin = begin->next;
	begin->next = new;
	return (b);
}
