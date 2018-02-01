/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeljoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:22:43 by gricquie          #+#    #+#             */
/*   Updated: 2017/08/18 14:51:37 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstdeljoin(t_list *begin, t_list *del, void (*fdel)(void *, size_t))
{
	t_list	*b;

	b = (begin == del ? del->next : begin);
	if (!del)
		return (begin);
	while (begin && begin->next != del && begin->next)
		begin = begin->next;
	if (begin && begin->next == del)
		begin->next = del->next;
	if (fdel)
		(*fdel)(del->content, del->content_size);
	free(del);
	return (b);
}
