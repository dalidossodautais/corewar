/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:53:47 by gricquie          #+#    #+#             */
/*   Updated: 2017/08/04 14:48:45 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <stdlib.h>
# include "libft.h"
# define ARRAYSIZE 64
# define ARRAY_DIV_PAD(size) (size / ARRAYSIZE + (size % ARRAYSIZE ? 1 : 0))
# define ARRAY_PAD_SIZE(size) (ARRAY_DIV_PAD(size) * ARRAYSIZE)

typedef struct	s_array
{
	char		*str;
	size_t		size;
}				t_array;

t_array			*ft_arraynew(const char *str);
t_array			*ft_arraydup(const t_array *old);
t_array			*ft_arraycat(t_array *dest, const t_array *src);
t_array			*ft_arrayjoin(const t_array *a1, const t_array *a2);
void			ft_arraydel(t_array **del);
t_array			*ft_arraydeljoin(t_array *a1, t_array *a2, char del);
t_array			*ft_arrayaddstrfront(t_array *arr, const char *str);
t_array			*ft_arrayaddstrback(t_array *arr, const char *str);
t_array			*ft_arrayaddstrnback(t_array *arr, const char *str, size_t len);
t_array			*ft_arrayaddstrnfront(t_array *a, const char *str, size_t len);
t_array			*ft_arraycutfront(t_array *a, size_t cut);
t_array			*ft_arraycutback(t_array *a, size_t cut);
t_array			*ft_arrayaddcharback(t_array *a, char c);
t_array			*ft_arrayaddcharfront(t_array *a, char c);
int				ft_arrayprint(const t_array *a);
int				ft_arrayprint_fd(int fd, const t_array *a);
int				ft_arrayprintl(const t_array *a);
t_array			*ft_arrayrealloc(t_array *a, size_t len);
t_array			*ft_arrayaddbaseback(t_array *a, ULL nbr, char *base);
t_array			*ft_arrayaddwcharback(t_array *a, wchar_t wc);
t_array			*ft_arrayaddwcsback(t_array *buff, const wchar_t *wcs);
t_array			*ft_arrayaddnspace(t_array *a, size_t n);

#endif
