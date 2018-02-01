/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:19:24 by gricquie          #+#    #+#             */
/*   Updated: 2017/09/18 12:50:41 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		get_label_value(char *line, t_sheet *sheet, int *param)
{
	t_list	*begin;

	begin = sheet->label;
	while (begin)
	{
		if (ft_strnequ(LST_LABEL(begin)->name, line,
					ft_strlen(LST_LABEL(begin)->name)))
		{
			*param = (LST_LABEL(begin)->pos - sheet->prog_size);
			return (1);
		}
		begin = begin->next;
	}
	return (0);
}
