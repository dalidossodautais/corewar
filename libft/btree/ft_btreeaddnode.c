/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeaddnode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:29:45 by gricquie          #+#    #+#             */
/*   Updated: 2017/08/19 15:29:33 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_btree	*addnode(t_btree *root, t_btree *new,
		int (*cmp)(const void *, const void *, size_t, size_t))
{
	if (!cmp)
		return (NULL);
	if (!new)
		return (root);
	if (!root)
		return (new);
	if ((*cmp)(root->content, new->content,
				root->content_size, new->content_size) > 0)
	{
		if ((root->left = ft_btreeaddnode(root->left, new, cmp)))
			root->left->parent = root;
	}
	else if ((root->right = ft_btreeaddnode(root->right, new, cmp)))
		root->right->parent = root;
	return (root);
}

t_btree			*ft_btreeaddnode(t_btree *root, t_btree *new,
		int (*cmp)(const void *, const void *, size_t, size_t))
{
	if (!new)
		return (root);
	new->is_red = TRUE;
	root = addnode(root, new, cmp);
	return (root);
}
