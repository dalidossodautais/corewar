/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 20:55:31 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/11 17:37:41 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstprint(t_list *l, void (*print)(const void *, size_t))
{
	while (l)
	{
		if (print)
			(*print)(l->content, l->content_size);
		l = l->next;
	}
}
