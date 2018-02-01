/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:29:33 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/18 18:19:48 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		split(char const *s, char ***tab, int *i, char c)
{
	int a;
	int j;

	j = 0;
	a = 0;
	if (!(*tab = ft_realloc(*tab, sizeof(char *) * (*i + 1),
					sizeof(char *) * (*i + 2))))
		return (0);
	(*tab)[*i] = NULL;
	while (s[a] != c && s[a])
	{
		if (!((*tab)[*i] = ft_realloc(((*tab)[*i]),
						sizeof(char) * j, sizeof(char) * (j + 1))))
			return (0);
		(*tab)[*i][j++] = s[a++];
	}
	if (!((*tab)[*i] = ft_realloc(((*tab)[*i]),
					sizeof(char) * j, sizeof(char) * (j + 1))))
		return (0);
	(*tab)[(*i)++][j] = '\0';
	while (s[a] == c && s[a])
		a++;
	return (a);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		a;
	int		temp;

	if (s == NULL)
		return (NULL);
	i = 0;
	a = 0;
	tab = malloc(sizeof(char *));
	tab[0] = NULL;
	while (s[a] == c && s[a])
		a++;
	while (s[a])
	{
		if (!(temp = split(s + a, &tab, &i, c)))
			return (NULL);
		a += temp;
	}
	if (!(tab = ft_realloc(tab, sizeof(char *) * (i + 1),
					sizeof(char *) * (i + 2))))
		return (NULL);
	tab[i] = NULL;
	return (tab);
}
