/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 16:31:36 by gricquie          #+#    #+#             */
/*   Updated: 2017/08/07 20:12:21 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstsort(t_list *l, int (*cmp)(const void *, const void *,
			size_t, size_t))
{
	t_list	*begin;
	t_list	*tmp1;
	t_list	*tmp2;

	begin = l;
	tmp1 = NULL;
	while (l && l->next)
	{
		if ((*cmp)(l->content, l->next->content,
					l->content_size, l->next->content_size) > 0)
		{
			tmp2 = l->next;
			l->next = tmp2->next;
			tmp2->next = l;
			if (!tmp1)
				begin = tmp2;
			else
				tmp1->next = tmp2;
			tmp1 = NULL;
			l = begin;
		}
		else if ((tmp1 = l))
			l = l->next;
	}
	return (begin);
}
