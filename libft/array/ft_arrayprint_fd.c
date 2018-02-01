/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 09:42:43 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/21 15:50:23 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/array.h"

int		ft_arrayprint_fd(int fd, const t_array *a)
{
	if (!a)
		return (write(fd, "(null)", 7));
	return (write(fd, a->str, a->size));
}
