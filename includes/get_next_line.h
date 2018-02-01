/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:59:28 by gricquie          #+#    #+#             */
/*   Updated: 2017/07/25 23:26:43 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 32

typedef struct		s_line
{
	int				fd;
	int				size;
	int				i;
	char			line[BUFF_SIZE];
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
