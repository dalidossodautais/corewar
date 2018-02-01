/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 13:05:44 by gricquie          #+#    #+#             */
/*   Updated: 2017/09/19 14:42:59 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static void	add_ocp(char res[], int param_type[], int s)
{
	int		i;
	char	c;

	i = 0;
	res[0] = 0;
	while (i < g_op_tab[s].nb_param)
	{
		if (param_type[i] == T_DIR)
			c = DIR_CODE;
		else if (param_type[i] == T_IND)
			c = IND_CODE;
		else
			c = REG_CODE;
		res[0] |= c << (3 - i) * 2;
		i++;
	}
}

static void	copy_param_in_mem(int param, int param_type,
		char res[], int *size)
{
	ft_reversebyte(&param, sizeof(param));
	if (param_type & T_DIR)
	{
		ft_memcpy(res + *size, &param, DIR_SIZE);
		*size += DIR_SIZE;
	}
	else if (param_type & T_IND)
	{
		ft_memcpy(res + *size, ((char *)&param) +
				sizeof(int) - IND_SIZE, IND_SIZE);
		*size += IND_SIZE;
	}
	else
	{
		ft_memcpy(res + *size, ((char *)&param) +
				sizeof(int) - 1, 1);
		(*size)++;
	}
}

static int	get_param_value(char *line, int param_type,
		t_sheet *sheet, int *param)
{
	while (ft_isspace(*line))
		line++;
	if (*line == '%' || *line == 'r')
		line++;
	if (*line == LABEL_CHAR)
	{
		if (!(get_label_value(line + 1, sheet, param)))
			return (error(ERROR_SYNTAX));
		line++;
		while (*line && ft_strchr(LABEL_CHARS, *line))
			line++;
	}
	else
	{
		*param = ft_atoi(line);
		if (*line == '-')
			line++;
		while (ft_isdigit(*line))
			line++;
	}
	if (!ft_isspace(*line) && *line != SEPARATOR_CHAR && !is_comment(line))
		return (error(ERROR_SYNTAX));
	if (param_type & T_REG && *param <= 0)
		return (error(ERROR_SYNTAX));
	return (1);
}

int			convert_param(char *line, char res[], int s, t_sheet *sheet)
{
	int		i;
	int		param_type[3];
	int		param;
	int		size;

	if (!stock_param_type(param_type, line, s))
		return (error(ERROR_SYNTAX));
	size = 1;
	if (g_op_tab[s].ocp)
		add_ocp(res + sheet->prog_size + size++, param_type, s);
	i = -1;
	while (++i < g_op_tab[s].nb_param)
	{
		if (param_type[i] & T_DIR && g_op_tab[s].direqind)
			param_type[i] = T_IND;
		if (!(get_param_value(line, param_type[i], sheet, &param)))
			return (0);
		copy_param_in_mem(param, param_type[i], res + sheet->prog_size, &size);
		while (*line && *line != SEPARATOR_CHAR && !is_comment(line))
			line++;
		if (*line)
			line++;
	}
	sheet->prog_size += size;
	return (1);
}
