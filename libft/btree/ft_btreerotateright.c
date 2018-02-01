/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreerotateright.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 18:13:02 by gricquie          #+#    #+#             */
/*   Updated: 2017/08/07 18:43:17 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_btreerotateright(t_btree *n)
{
	t_btree		*y;

	if (!n)
		return ;
	y = n->left;
	if (!y)
		return ;
	n->left = y->right;
	if (n->left)
		n->left->parent = n;
	y->right = n;
	y->parent = n->parent;
	if (y->parent && y->parent->left == n)
		y->parent->left = y;
	else if (y->parent)
		y->parent->right = y;
	n->parent = y;
	n = y;
}
