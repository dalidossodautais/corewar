/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:25:16 by gricquie          #+#    #+#             */
/*   Updated: 2017/08/18 14:50:16 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_btree		*ft_btreenew(const void *content, size_t content_size)
{
	t_btree		*new;

	if (!(new = malloc(sizeof(t_btree))))
		return (NULL);
	if (!(new->content = malloc(content_size)))
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	new->is_red = TRUE;
	return (new);
}
