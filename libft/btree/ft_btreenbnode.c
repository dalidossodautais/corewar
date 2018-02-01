/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreenbnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 14:18:11 by gricquie          #+#    #+#             */
/*   Updated: 2017/08/09 14:21:05 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_btreenbnode(t_btree *root)
{
	size_t	nbnode;

	if (!root)
		return (0);
	nbnode = ft_btreenbnode(root->left);
	nbnode += ft_btreenbnode(root->right);
	return (nbnode + 1);
}
