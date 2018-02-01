/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreerotateleft.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 18:06:12 by gricquie          #+#    #+#             */
/*   Updated: 2017/08/07 18:42:21 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_btreerotateleft(t_btree *n)
{
	t_btree		*y;

	if (!n)
		return ;
	y = n->right;
	if (!y)
		return ;
	n->right = y->left;
	if (n->right)
		n->right->parent = n;
	y->left = n;
	y->parent = n->parent;
	if (y->parent && y->parent->left == n)
		y->parent->left = y;
	else if (y->parent)
		y->parent->right = y;
	n->parent = y;
	n = y;
}
