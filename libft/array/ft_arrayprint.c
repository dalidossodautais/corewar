/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 09:42:43 by gricquie          #+#    #+#             */
/*   Updated: 2017/03/29 10:06:04 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

int		ft_arrayprint(const t_array *a)
{
	if (!a)
		return (ft_putstr("(null)"));
	return (write(1, a->str, a->size));
}
