/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_asm_to_bytecode.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 16:43:13 by gricquie          #+#    #+#             */
/*   Updated: 2017/09/19 11:48:36 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int					convert_asm_to_bytecode(t_list *file, char result[],
		t_sheet *sheet)
{
	t_header		*h;

	h = (t_header *)result;
	h->magic = COREWAR_EXEC_MAGIC;
	ft_reversebyte(&h->magic, sizeof(h->magic));
	ft_strcpy(h->prog_name, sheet->name);
	ft_strcpy(h->comment, sheet->comment);
	if (!(write_instr_in_result(file, result + sizeof(t_header), sheet)))
		return (0);
	h->prog_size = sheet->prog_size;
	ft_reversebyte(&h->prog_size, sizeof(h->prog_size));
	return (1);
}
