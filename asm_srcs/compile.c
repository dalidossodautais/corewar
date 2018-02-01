/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:49:12 by jlereffa          #+#    #+#             */
/*   Updated: 2017/09/19 11:48:42 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <fcntl.h>

static t_list	*read_and_stock_file(int fd)
{
	t_list		*file;
	t_list		*tmp;
	char		*line;

	file = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(tmp = ft_lstnew(line, (ft_strlen(line) + 1) * sizeof(char))))
		{
			ft_lstdel(&file, (t_fdel) & free);
			return (NULL);
		}
		ft_strdel(&line);
		file = ft_lstaddback(file, tmp);
	}
	return (file);
}

int				compile(const char *path)
{
	int		fd;
	t_list	*file;
	t_list	*begin;
	t_sheet	sheet;
	char	result[CHAMP_MAX_SIZE + sizeof(t_header) + 1];

	if ((fd = open(path, O_RDONLY)) < 0)
		return (error(ERROR_OPEN));
	if (!(file = read_and_stock_file(fd)))
		return (error(ERROR_ALLOC));
	begin = file;
	ft_bzero(&sheet, sizeof(sheet));
	if (!(file = get_name_and_comment(file, &sheet)))
		return (0);
	if (!(search_and_stock_label(file, &sheet)))
		return (0);
	ft_bzero(result, sizeof(result));
	if (!(convert_asm_to_bytecode(file, result, &sheet)))
		return (0);
	if (!(create_and_write_file(path, result)))
		return (0);
	ft_lstdel(&begin, (t_fdel) & free);
	ft_lstdel(&sheet.label, (t_fdel) & free_label);
	return (1);
}
