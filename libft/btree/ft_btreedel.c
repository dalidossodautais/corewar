/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 15:42:57 by gricquie          #+#    #+#             */
/*   Updated: 2017/08/07 15:46:29 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_btreedel(t_btree **root, void (*del)(void *, size_t))
{
	if (!root || !*root)
		return ;
	ft_btreedel(&(*root)->left, del);
	ft_btreedel(&(*root)->right, del);
	if (del)
		(*del)((*root)->content, (*root)->content_size);
	free(*root);
	*root = NULL;
}
