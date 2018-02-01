/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:13:17 by gricquie          #+#    #+#             */
/*   Updated: 2017/09/06 18:13:06 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

static void	btreeprint(t_btree *root, size_t depth, t_fprint print, t_btree *p)
{
	size_t	i;

	if (!root)
		return ;
	btreeprint(root->left, depth + 1, print, root);
	i = 0;
	while (i++ < depth)
		ft_putchar('\t');
	if (print)
		(*print)(root->content, root->content_size);
	if (root->parent != p)
		ft_putstr(" \033[31mparent err\033[0m");
	ft_putchar('\n');
	btreeprint(root->right, depth + 1, print, root);
}

void		ft_btreeprint(t_btree *root,
		void (*print)(const void *, size_t))
{
	btreeprint(root, 0, print, NULL);
}
