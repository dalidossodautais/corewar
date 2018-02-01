/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedepth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 14:43:16 by gricquie          #+#    #+#             */
/*   Updated: 2017/08/07 14:47:27 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t		ft_btreedepth(t_btree *root)
{
	size_t	ldepth;
	size_t	rdepth;

	if (!root)
		return (0);
	ldepth = ft_btreedepth(root->left);
	rdepth = ft_btreedepth(root->right);
	return (1 + (ldepth < rdepth ? rdepth : ldepth));
}
