/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 15:53:38 by gricquie          #+#    #+#             */
/*   Updated: 2017/09/06 17:33:02 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <libft.h>
# include <array.h>
# include <get_next_line.h>

# define DEBUG_S "file : {green}%s{eoc}, line : {green}%u{eoc}\n"
# define DEBUG ft_fprintf(2, DEBUG_S, __FILE__, __LINE__);
# define DECIMAL "0123456789"
# define OCTAL "01234567"
# define UPHEXA "0123456789ABCDEF"
# define LOWHEXA "0123456789abcdef"
# define ZEROS "000000000000000000000000000000000000000000000000000000"
# define SPACES "                                                      "
# define PRINTF_CONV "aAbcCdDeEfFgGinoOpsSuUxX%"
# define PRINTF_MOD "#0-+ .hljz'L*"

typedef struct s_printf_mod	t_printf_mod;

struct		s_printf_mod
{
	char	width;
	char	prec;
	char	maj;
	char	zero;
	char	sharp;
	char	minus;
	char	plus;
	char	space;
	char	l;
	char	apos;
	char	ml;
	char	dollar;
	char	valid;
};

typedef struct s_printf_flag	t_printf_flag;

struct		s_printf_flag
{
	char	conv;
	int		(*f)(va_list ap, t_array *buff, t_printf_mod mod);
};

int			ft_printf(const char *str, ...);
int			ft_fprintf(int fd, const char *str, ...);

const char	*printf_addparam(t_array *buff, const char *restrict format,
				va_list ap);

const char	*printf_searchmod(const char *restrict str, va_list ap,
					t_printf_mod *mod);

t_array		*printf_addpad(t_array *buff, t_printf_mod mod, long int len);
t_array		*printf_addprec(t_array *buff, t_printf_mod mod, long int len);

long long	printf_typesigned(va_list ap, t_printf_mod mod);
ULL			printf_typeunsigned(va_list ap, t_printf_mod mod);

t_array		*printf_addapos(t_array *buff, t_printf_mod mod, long long nb);

long double	printf_cutdouble(long double n, int prec);
t_array		*printf_adddoubleprec(t_array *buff, long double n, int prec);
int			printf_calcexp(long double *n);

const char	*printf_color(t_array *buff, const char *str);
int			printf_flag_a(va_list ap, t_array *buff, t_printf_mod mod);
int			printf_flag_b(va_list ap, t_array *buff, t_printf_mod mod);
int			printf_flag_c(va_list ap, t_array *buff, t_printf_mod mod);
int			printf_flag_lc(va_list ap, t_array *buff, t_printf_mod mod);
int			printf_flag_d(va_list ap, t_array *buff, t_printf_mod mod);
int			printf_flag_e(va_list ap, t_array *buff, t_printf_mod mod);
int			printf_flag_f(va_list ap, t_array *buff, t_printf_mod mod);
int			printf_flag_g(va_list ap, t_array *buff, t_printf_mod mod);
int			printf_flag_n(va_list ap, t_array *buff, t_printf_mod mod);
int			printf_flag_o(va_list ap, t_array *buff, t_printf_mod mod);
int			printf_flag_p(va_list ap, t_array *buff, t_printf_mod mod);
int			printf_flag_s(va_list ap, t_array *buff, t_printf_mod mod);
int			printf_flag_ls(va_list ap, t_array *buff, t_printf_mod mod);
int			printf_flag_u(va_list ap, t_array *buff, t_printf_mod mod);
int			printf_flag_x(va_list ap, t_array *buff, t_printf_mod mod);
int			printf_flag_prc(va_list ap, t_array *buff, t_printf_mod mod);
int			printf_wrongconv(char c, t_array *buff, t_printf_mod mod);

#endif
