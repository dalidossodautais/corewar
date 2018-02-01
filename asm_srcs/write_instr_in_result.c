/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instr_in_result.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 11:58:40 by gricquie          #+#    #+#             */
/*   Updated: 2018/02/01 14:16:28 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int		convert_instr(char *line, char res[], t_sheet *sheet)
{
	int		s;
	size_t	i;

	while (ft_isspace(*line))
		line++;
	s = 0;
	i = 1;
	while (line[i] && !ft_isspace(line[i]))
		i++;
	while (g_op_tab[s].name && (ft_strlen(g_op_tab[s].name) != i ||
			!ft_strnequ(g_op_tab[s].name, line, i)))
		s++;
	if (!g_op_tab[s].name)
		return (0);
	line += ft_strlen(g_op_tab[s].name);
	res[sheet->prog_size] = g_op_tab[s].opcode;
	if (!(convert_param(line, res, s, sheet)))
		return (0);
	return (1);
}

unsigned int	write_instr_in_result(t_list *file, char res[], t_sheet *sheet)
{
	char	*line;

	while (file)
	{
		line = file->content;
		if (is_label(line))
			line = ft_strchr(line, LABEL_CHAR) + 1;
		if (!is_comment(line))
			if (!convert_instr(line, res, sheet))
				return (0);
		file = file->next;
	}
	return (1);
}
