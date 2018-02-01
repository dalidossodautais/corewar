/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_param_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:19:08 by gricquie          #+#    #+#             */
/*   Updated: 2017/09/19 14:22:51 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		stock_param_type(int param_type[], char *line, int s)
{
	int		i;

	i = 0;
	ft_bzero(param_type, sizeof(int) * 3);
	while (i < 3)
	{
		while (ft_isspace(*line))
			line++;
		if (*line == DIRECT_CHAR)
			param_type[i] = T_DIR;
		else if (*line == 'r')
			param_type[i] = T_REG;
		else
			param_type[i] = T_IND;
		if (!(g_op_tab[s].param_type[i] & param_type[i]))
			return (0);
		while (*line && *line != SEPARATOR_CHAR && !is_comment(line))
			line++;
		if (!*line || is_comment(line))
			return (i + 1 == g_op_tab[s].nb_param);
		line++;
		i++;
	}
	return (1);
}
