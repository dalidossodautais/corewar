/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_stock_label.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 14:19:23 by gricquie          #+#    #+#             */
/*   Updated: 2017/09/19 11:15:23 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			stock_label(char **line, t_sheet *sheet, int pos)
{
	t_list		*new;
	t_label		lab;
	char		*ptr;

	while (ft_isspace(**line))
		(*line)++;
	ptr = ft_strchr(*line, LABEL_CHAR);
	if (!(lab.name = ft_strndup(*line, ptr - (*line))))
		return (0);
	lab.pos = pos;
	if (!(new = ft_lstnew(&lab, sizeof(lab))))
	{
		free(lab.name);
		return (0);
	}
	ft_lstadd(&sheet->label, new);
	(*line) = (ptr + 1);
	return (1);
}

static int	get_param_size(char *line, int s)
{
	if (*line == DIRECT_CHAR)
		return (g_op_tab[s].direqind ? IND_SIZE : DIR_SIZE);
	else if (*line == 'r')
		return (1);
	else
		return (IND_SIZE);
}

static int	calc_op_size(char *line)
{
	int		size;
	int		i;
	int		s;

	size = 1;
	s = 0;
	i = 1;
	while (line[i] && !ft_isspace(line[i]))
		i++;
	while (g_op_tab[s].name && !ft_strnequ(g_op_tab[s].name, line, i))
		s++;
	if (!g_op_tab[s].name)
		return (0);
	size += g_op_tab[s].ocp;
	line += ft_strlen(g_op_tab[s].name);
	while (*line)
	{
		while (ft_isspace(*line))
			line++;
		size += get_param_size(line, s);
		if (!(line = ft_strchr(line, SEPARATOR_CHAR)))
			return (size);
		line++;
	}
	return (size);
}

int			search_and_stock_label(t_list *file, t_sheet *sheet)
{
	char	*line;
	int		pos;

	pos = 0;
	while (file)
	{
		line = file->content;
		if (!is_comment(line))
		{
			if (is_label(line))
			{
				if (!(stock_label(&line, sheet, pos)))
					return (0);
			}
			while (ft_isspace(*line))
				line++;
			pos += calc_op_size(line);
		}
		file = file->next;
	}
	return (1);
}
