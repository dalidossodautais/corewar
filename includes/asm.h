/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:37:35 by jlereffa          #+#    #+#             */
/*   Updated: 2018/01/04 16:37:42 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <ft_printf.h>
# include <op.h>

# define ERROR_NOFILE "Error : No file"
# define ERROR_OPEN "Error : File could not be open"
# define ERROR_ALLOC "Error : Memory allocation failed"
# define ERROR_TOO_MANY_NAMES "Error : Too many names"
# define ERROR_TOO_MANY_COMMENTS "Error : Too many comments"
# define ERROR_NAME_TOO_LONG "Error : Name or comment too long"
# define ERROR_MISSING_QUOTE "Error : Missing quote"
# define ERROR_NO_NAME "Error : No name was entered"
# define ERROR_NO_COMMENT "Error : No comment was entered"
# define ERROR_SYNTAX "Error : Syntax error"
# define ERROR_CREATE_FILE "Error : Error creating output file"

# define NAME_FOUND 1
# define COMMENT_FOUND 2

# define LST_LABEL(l) ((t_label *)((l)->content))

typedef struct s_sheet	t_sheet;
typedef struct s_label	t_label;
typedef struct s_op		t_op;

struct			s_sheet
{
	char		name[PROG_NAME_LENGTH + 1];
	char		comment[COMMENT_LENGTH + 1];
	unsigned	prog_size;
	t_list		*label;
};

struct			s_label
{
	char		*name;
	size_t		pos;
};

struct			s_op
{
	char		*name;
	char		nb_param;
	char		param_type[3];
	char		opcode;
	int			nb_cycles;
	char		*full_name;
	char		ocp;
	char		direqind;
};

const t_op		g_op_tab[17];

int				error(char *err_msg);
int				compile(const char *path);
t_list			*get_name_and_comment(t_list *file, t_sheet *sheet);
int				is_comment(char *line);
int				search_and_stock_label(t_list *file, t_sheet *sheet);
int				is_label(char *line);
void			print_label(t_label *l);
void			free_label(t_label *l);
int				convert_asm_to_bytecode(t_list *file, char result[],
		t_sheet *sheet);
unsigned		write_instr_in_result(t_list *file, char res[], t_sheet *sheet);
int				convert_param(char *line, char res[], int s, t_sheet *sheet);
int				get_label_value(char *line, t_sheet *sheet, int *param);
int				create_and_write_file(const char *path, char result[]);
int				stock_param_type(int param_type[], char *line, int s);

#endif
