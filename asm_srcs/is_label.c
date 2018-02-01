/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_label.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 14:31:32 by gricquie          #+#    #+#             */
/*   Updated: 2017/09/14 13:42:48 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		is_label(char *line)
{
	while (ft_isspace(*line))
		line++;
	while (*line && ft_strchr(LABEL_CHARS, *line))
		line++;
	if (*line == LABEL_CHAR)
		return (1);
	return (0);
}
