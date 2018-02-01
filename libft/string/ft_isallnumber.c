/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isallnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 18:12:22 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/08 18:06:22 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_isallnumber(char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '-')
		++str;
	if (!*str)
		return (0);
	while (ft_isdigit(*str))
		str++;
	return (!*str);
}
