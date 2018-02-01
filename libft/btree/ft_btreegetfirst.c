/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreegetfirst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:46:44 by gricquie          #+#    #+#             */
/*   Updated: 2017/08/18 14:50:55 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_btree		*ft_btreegetfirst(t_btree *root)
{
	if (!root)
		return (NULL);
	while (root->left)
		root = root->left;
	return (root);
}
