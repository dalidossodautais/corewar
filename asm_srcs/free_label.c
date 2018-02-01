/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 16:16:01 by gricquie          #+#    #+#             */
/*   Updated: 2017/09/08 16:17:23 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	free_label(t_label *l)
{
	free(l->name);
}
