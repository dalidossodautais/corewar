/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:27:28 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/11 12:59:19 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addstr(char *s1, const char *s2, int n)
{
	if (n < 0)
		return (NULL);
	if (!s1 || !s2)
		return (NULL);
	if (!(s1 = ft_realloc(s1, sizeof(char) * (ft_strlen(s1) + 1),
					sizeof(char) * (ft_strlen(s1) + n + 1))))
		return (NULL);
	s1 = ft_strncat(s1, s2, n);
	return (s1);
}
