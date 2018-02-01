/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdeljoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:53:28 by gricquie          #+#    #+#             */
/*   Updated: 2017/04/01 17:18:37 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdeljoin(char *s1, char *s2, int del)
{
	char	*final;

	if (!s1 || !s2)
		return (NULL);
	final = ft_strjoin(s1, s2);
	if (del == DELLEFT || del == DELBOTH)
		ft_strdel(&s1);
	if (del == DELRIGHT || del == DELBOTH)
		ft_strdel(&s2);
	if (del != DELLEFT && del != DELRIGHT && del != DELBOTH)
	{
		ft_putendl("valeur de del inconnue");
		return (NULL);
	}
	return (final);
}
