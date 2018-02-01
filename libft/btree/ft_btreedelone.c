/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 14:09:00 by gricquie          #+#    #+#             */
/*   Updated: 2017/08/13 17:12:46 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_btree		*rootequdel(t_btree *root, void (*fdel)(void *, size_t))
{
	t_btree	*tmp;

	if (!root)
		return (NULL);
	if ((!root->left || !root->right))
	{
		if ((tmp = (!root->right ? root->left : root->right)))
			tmp->parent = NULL;
	}
	else
	{
		tmp = root->right;
		while (tmp->left)
			tmp = tmp->left;
		tmp->left = root->left;
		if (tmp->left)
			tmp->left->parent = tmp;
		tmp = root->right;
	}
	if (root && fdel)
		(*fdel)(root->content, root->content_size);
	free(root);
	return (tmp);
}

t_btree		*ft_btreedelone(t_btree *root, t_btree *del,
		void (*fdel)(void *, size_t),
		int (*cmp)(const void *, const void *, size_t, size_t))
{
	if (!root || !cmp)
		return (NULL);
	if (!del)
		return (root);
	if (root == del)
		return (rootequdel(root, fdel));
	else if (!root->left)
	{
		if ((root->right = ft_btreedelone(root->right, del, fdel, cmp)))
			root->right->parent = root;
	}
	else if (!root->right)
	{
		if ((root->left = ft_btreedelone(root->left, del, fdel, cmp)))
			root->left->parent = root;
	}
	else if ((*cmp)(root->content, del->content,
				root->content_size, del->content_size) > 0)
	{
		if ((root->left = ft_btreedelone(root->left, del, fdel, cmp)))
			root->left->parent = root;
	}
	else if ((root->right = ft_btreedelone(root->right, del, fdel, cmp)))
		root->right->parent = root;
	return (root);
}
