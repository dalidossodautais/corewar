/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_and_comment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:42:31 by jlereffa          #+#    #+#             */
/*   Updated: 2017/09/08 14:16:38 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static t_list	*get_between_quote(t_list *file, char *line,
		char *buff, size_t size)
{
	while (ft_isspace(*line))
		line++;
	if (*line != '"')
		return (NULL);
	line++;
	while (*line != '"')
	{
		if (size == 1)
			return ((void *)(long)error(ERROR_NAME_TOO_LONG));
		size--;
		*buff = *line;
		buff++;
		line++;
		if (!*line)
		{
			if (!(file = file->next) || size == 1)
				return ((void *)(long)error(ERROR_MISSING_QUOTE));
			line = file->content;
			size--;
			*buff = '\n';
			buff++;
		}
	}
	*buff = '\0';
	return (file);
}

static int		stock_name_and_comment_if_found(int *found, char *line,
		t_list **file, t_sheet *sheet)
{
	if (ft_strnequ(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		if (*found & NAME_FOUND)
			return (error(ERROR_TOO_MANY_NAMES));
		*found |= NAME_FOUND;
		line += ft_strlen(NAME_CMD_STRING);
		if (!(*file = get_between_quote(*file, line, sheet->name,
				PROG_NAME_LENGTH + 1)))
			return (error(ERROR_NAME_TOO_LONG));
	}
	else if (line && ft_strnequ(line, COMMENT_CMD_STRING,
				ft_strlen(COMMENT_CMD_STRING)))
	{
		if (*found & COMMENT_FOUND)
			return (error(ERROR_TOO_MANY_COMMENTS));
		*found |= COMMENT_FOUND;
		line += ft_strlen(COMMENT_CMD_STRING);
		if (!(*file = get_between_quote(*file, line, sheet->comment,
				COMMENT_LENGTH + 1)))
			return (0);
	}
	else if (*line != COMMENT_CHAR && *line)
		return (0);
	return (1);
}

t_list			*get_name_and_comment(t_list *file, t_sheet *sheet)
{
	int		found;
	char	*line;

	found = 0;
	while (file && found != (NAME_FOUND | COMMENT_FOUND))
	{
		line = (char *)file->content;
		while (ft_isspace(*line))
			line++;
		if (!stock_name_and_comment_if_found(&found, line, &file, sheet))
			return (NULL);
		file = file->next;
	}
	if (!(found & NAME_FOUND))
		return ((t_list *)(long)error(ERROR_NO_NAME));
	if (!(found & COMMENT_FOUND))
		return ((t_list *)(long)error(ERROR_NO_COMMENT));
	return (file);
}
