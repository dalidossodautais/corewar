/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 21:27:34 by gricquie          #+#    #+#             */
/*   Updated: 2017/09/13 15:11:19 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define ULL unsigned long long
# define LL long long

# define MAX_INT 2147483647

typedef void	(*t_fprint)(const void *, size_t);
typedef void	(*t_fdel)(void *, size_t);

typedef enum e_boolean	t_bool;
enum					e_boolean
{
	TRUE = 1,
	FALSE = 0
};

enum					e_strdeljoin
{
	DELLEFT,
	DELRIGHT,
	DELBOTH
};

typedef struct s_list	t_list;
struct		s_list
{
	void	*content;
	size_t	content_size;
	t_list	*next;
};

typedef struct s_btree	t_btree;
struct		s_btree
{
	void	*content;
	size_t	content_size;
	t_btree	*parent;
	t_btree	*right;
	t_btree	*left;
	t_bool	is_red;
};

/*
**		MEMORY
*/
void		*ft_memset(void *s, int n, size_t c);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
void		*ft_realloc(void *tab, size_t oldsize, size_t newsize);
void		ft_reversebyte(void *bytes, size_t size);

/*
**		STRING
*/
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strndup(const char *s, size_t size);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strncat(char *dest, const char *src, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);
char		**ft_strsplitcharset(char const *s, char const *c);
void		ft_printtab(char **tab);
void		ft_freetab(char **tab);
char		*ft_itoa(long long int n);
intmax_t	ft_atoi(const char *str);
char		*ft_strdeljoin(char *s1, char *s2, int del);
char		*ft_itoabase(unsigned long long nb, char *base);
char		*ft_chartostr(char c);
char		*ft_ctoa(char c);
char		*ft_addstr(char *s1, const char *s2, int n);

/*
**			IS_
*/
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_isupper(int c);
int			ft_islower(int c);
int			ft_isallnumber(char *str);
int			ft_toupper(int c);
int			ft_tolower(int c);

/*
**			PRINT
*/
int			ft_putchar(char c);
int			ft_putstr(char const *s);
void		ft_putendl(char const *s);
int			ft_putnbr(long long int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_putbase(ULL n, char *base);
int			ft_putnbrl(int n);
void		ft_putnbrl_fd(int n, int fd);
int			ft_putwchar(wchar_t c);

/*
**			LIST
*/
t_list		*ft_lstnew(void const *content, size_t content_size);
void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list		*ft_lstdeljoin(t_list *begin, t_list *del,
		void (*fdel)(void *, size_t));
void		ft_lstadd(t_list **alst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list		*ft_lstaddback(t_list *begin, t_list *new);
void		ft_lstprint(t_list *l, void (*print)(const void *, size_t));
size_t		ft_lstlen(t_list *l);
t_list		*ft_lstsort(t_list *l,
		int (*cmp)(const void *, const void *, size_t, size_t));

/*
**			BTREE
*/
t_btree		*ft_btreenew(const void *content, size_t content_size);
t_btree		*ft_btreeaddnode(t_btree *root, t_btree *new,
		int (*cmp)(const void *, const void *, size_t, size_t));
t_btree		*ft_btreegetfirst(t_btree *root);
void		ft_btreeprint(t_btree *root, void (*print)(const void *, size_t));
t_btree		*ft_btreedelone(t_btree *root, t_btree *del,
		void (*fdel)(void *, size_t),
		int (*cmp)(const void *, const void *, size_t, size_t));
size_t		ft_btreedepth(t_btree *root);
void		ft_btreedel(t_btree **root, void (*del)(void *, size_t));
void		ft_btreerotateleft(t_btree *n);
void		ft_btreerotateright(t_btree *n);
void		ft_btreerearange(t_btree *n);
size_t		ft_btreenbnode(t_btree *root);
t_btree		*ft_btreegetnext(t_btree *n);

/*
**			WCHAR
*/
int			ft_wcslen(const wchar_t *wcs);
int			ft_wcswrite(wchar_t *wcs, int len);
char		*ft_wchartostr(wchar_t wc);
char		*ft_wcstostr(wchar_t *wcs);
wchar_t		*ft_wcsdup(const wchar_t *wcs);
size_t		ft_wcharbytelen(wchar_t wc);

/*
**			INT
*/
int			ft_max(int x, int y);
size_t		ft_intlen(long long int n);
size_t		ft_unsignedintlen(ULL n);
size_t		ft_baselen(ULL n, unsigned base);
LL			ft_abs(long long n);
int			ft_min(int a, int b);
void		ft_sort(int *tab, size_t size);
int			ft_median(int *tab, size_t size);
void		ft_swap(int *a, int *b);

#endif
