/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_comment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 14:23:26 by gricquie          #+#    #+#             */
/*   Updated: 2017/09/08 14:24:50 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		is_comment(char *line)
{
	while (ft_isspace(*line))
		line++;
	if (!*line || *line == COMMENT_CHAR)
		return (1);
	return (0);
}
