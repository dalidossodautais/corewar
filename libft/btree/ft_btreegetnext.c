/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreegetnext.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 14:41:15 by gricquie          #+#    #+#             */
/*   Updated: 2017/08/18 16:04:46 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_btree		*ft_btreegetnext(t_btree *n)
{
	if (!n)
		return (n);
	if (n->right)
		return (ft_btreegetfirst(n->right));
	while (n && !n->right)
	{
		while (n->parent && n->parent->right == n)
			n = n->parent;
		n = n->parent;
	}
	return (n);
}
