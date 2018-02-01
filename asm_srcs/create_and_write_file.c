/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_write_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:59:14 by gricquie          #+#    #+#             */
/*   Updated: 2018/01/24 16:42:21 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <fcntl.h>

static char	*create_name(const char *path)
{
	char	*name;
	char	*point;

	if (!(point = ft_strrchr(path, '.')))
	{
		if (!(name = malloc(sizeof(char) * (ft_strlen(path) + 5))))
			return (NULL);
		ft_strcpy(name, path);
		ft_strcat(name, ".cor");
	}
	else if (point && ft_strchr(point, '/'))
	{
		if (!(name = malloc(sizeof(char) * (ft_strlen(path) + 5))))
			return (NULL);
		ft_strcpy(name, path);
		ft_strcat(name, ".cor");
	}
	else
	{
		if (!(name = malloc(sizeof(char) * (ft_strlen(path) + 3))))
			return (NULL);
		ft_strcpy(name, path);
		ft_strcpy(ft_strrchr(name, '.'), ".cor");
	}
	return (name);
}

int			create_and_write_file(const char *path, char result[])
{
	int		fd;
	char	*name;
	int		size;

	name = create_name(path);
	fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd < 0)
		return (error(ERROR_CREATE_FILE));
	size = ((t_header *)result)->prog_size;
	ft_reversebyte(&size, sizeof(size));
	write(fd, result, sizeof(t_header) + size);
	ft_printf("Writing output program to %s\n", name);
	free(name);
	return (1);
}
