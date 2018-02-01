/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:22:32 by ddosso-d          #+#    #+#             */
/*   Updated: 2018/01/08 14:58:59 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <fcntl.h>
# include <ft_printf.h>
# include <op.h>
# include <ncurses.h>
# include <time.h>

# define ERROR_ALLOC "Error : allocation failed"
# define ERROR_TOO_MUCH_PLAYERS "Error : Too much players"
# define ERROR_OPEN "Error : Open fail"
# define ERROR_READ "Error : Read fail"
# define ERROR_NON_EXISTENT_FLAG "Error : Non-existent flag"
# define ERROR_NOT_FOLLOWING_FLAG "Error : Not following special flag"
# define ERROR_NOT_VALID_NUMBER "Error : Not following valid number"
# define ERROR_FLAG_BADLY_USED "Error : Flag is badly used"
# define ERROR_FILE_TOO_SHORT "Error : File is too short to be a champion"
# define ERROR_BAD_HEADER "Error : Bad header"
# define ERROR_NB_CHAMP_TAKEN "Error : Champion number taken"
# define ERROR_FLAG_N_NUMBER_TOO_BIG "Error : -n arg is too big"
# define ERROR_FLAG_NUMBER "Error : Flag not following by a valid number"
# define ERROR_CHAMP_TOO_BIG "Error : Champ is too big"

# define INTRO_LINE "Introducing contestants..."
# define INTRO_CHAMP "* Joueur %d, pesant %d octets, \"%s\" (\"%s\") !"
# define ANNOUNCE_WINNER "Le joueur %d (%s) a gagné."

# define DUMP_BYTE_PER_LINE 64

# define GET_MEM(a) ((a) & 0xff)

# define FLAG_A 1
# define FLAG_B 2
# define FLAG_C 4
# define FLAG_D 8
# define FLAG_N 16
# define FLAG_S 32
# define FLAG_V 64
# define FLAG_STEALTH 128

# define FLAG_V_LIVES 1
# define FLAG_V_CYCLES 2
# define FLAG_V_OP 4
# define FLAG_V_DEATHS 8
# define FLAG_V_PC_MOV 16

# define OCP_PARAM(ocp, i) (((ocp) >> (6 - (i) * 2)) & 3)

# define GET_MEM1(a) (((a) >> 4) & 0xf)
# define GET_MEM2(a) ((a) & 0xf)
# define GET_PLAYER(a) (((a) >> 8) & 0xff)

# define START(a) ((a) & 0x1)
# define ESC(a) ((a) & 0x2)
# define COLOR(a) ((a) & 0x4)
# define SIZE(a) ((a) & 0x8)

# define COLOR_P1 COLOR_RED
# define COLOR_P2 COLOR_YELLOW
# define COLOR_P3 COLOR_BLUE
# define COLOR_P4 COLOR_GREEN

# define BOX_HEIGHT 66
# define MAIN_BOX_WIDTH 195
# define SUPP_BOX_WIDTH 55
# define INPUT_ESC 27
# define INPUT_SPACE 32
# define INPUT_PLUS 43
# define INPUT_MINUS 45
# define ERROR -1
# define FAILURE 0
# define SUCCESS 1
# define BASE_CPS 100
# define MAX_CPS 10000
# define MIN_CPS 1
# define MODIF_CPS 10

typedef struct				s_flag
{
	unsigned	exist;
	int			val_d;
	int			val_s;
	unsigned	val_v;
}							t_flag;

typedef struct				s_champ
{
	t_header	header;
	char		prog[CHAMP_MAX_SIZE];
	int			nb_champ;
	int			last_live;
}							t_champ;

typedef struct				s_info
{
	t_champ		champs[MAX_PLAYERS];
	unsigned	nbr_player;
}							t_info;

typedef struct s_op			t_op;
struct						s_op
{
	char			*name;
	unsigned		nb_param;
	char			param_type[3];
	unsigned char	opcode;
	int				nb_cycles;
	char			*full_name;
	char			ocp;
	char			direquind;
};

typedef struct s_win		t_win;
struct						s_win
{
	int				cps;
	char			cases;
	struct timespec	time;
	WINDOW			*main;
	WINDOW			*supp;
};

# define LST_PROCESS(l) ((t_process *)((l)->content))

typedef struct s_process	t_process;
struct						s_process
{
	int				pc;
	unsigned char	op;
	unsigned char	ocp;
	unsigned		nb_param;
	char			prototype[3];
	int				param[3];
	unsigned		cycle_to_do;
	int				reg[REG_NUMBER];
	char			carry;
	int				last_live;
	int				nb;
};

typedef struct s_func_tab	t_func_tab;
struct						s_func_tab
{
	unsigned		opcode;
	int				(*f)(t_process *p, t_list **all_p, t_info *info,
						unsigned cycle);
};

int							g_cycle_to_die;
unsigned					g_nb_live;
const t_op					g_op_tab[17];
int							g_arena[MEM_SIZE];
t_flag						g_flag;

int							read_args(t_info *info, t_flag *flag, int ac,
								char **av);
int							read_champs(t_info *info, int ac, char **av);
void						dump(int mem[]);
int							error(char *err_msg);
void						init_arena(unsigned champ_start[], t_info info);
void						intro_champs(t_info info);
int							init_process(t_list **process,
								unsigned champ_start[], t_info info);
int							run(t_list *process, t_info *info);
void						enter_new_op_in_process(t_process *p, t_op op);
void						change_carry(t_process *p, int res);
void						check_live(t_list **all_p, int cycle,
								int *cycle_to_check);
void						copy_arena(int *reg, int pos, size_t size);
void						copy_in_arena(int pos, int src, size_t size,
								int player);
void						announce_winner(t_info info);
int							advance_pc(t_process *p);
int							check_ocp(t_process *p);
int							check_reg(t_process *p);
t_op						get_op(char opcode);
void						print_op_mem(size_t pos, size_t size);
unsigned					get_next_process_nb(void);
int							do_op(t_process *p, t_list **all_p,
								t_info *info, unsigned cyc);
void						get_param(t_process *p, t_op op);
int							op_live(t_process *p, t_list **all_p,
								t_info *info, unsigned c);
int							op_load(t_process *p, t_list **all_p,
								t_info *info, unsigned c);
int							op_store(t_process *p, t_list **all_p,
								t_info *info, unsigned c);
int							op_add(t_process *p, t_list **all_p,
								t_info *info, unsigned c);
int							op_sub(t_process *p, t_list **all_p,
								t_info *info, unsigned c);
int							op_and(t_process *p, t_list **all_p,
								t_info *info, unsigned c);
int							op_or(t_process *p, t_list **all_p,
								t_info *info, unsigned c);
int							op_xor(t_process *p, t_list **all_p,
								t_info *info, unsigned c);
int							op_zjmp(t_process *p, t_list **all_p,
								t_info *info, unsigned c);
int							op_ldi(t_process *p, t_list **all_p,
								t_info *info, unsigned c);
int							op_sti(t_process *p, t_list **all_p,
								t_info *info, unsigned c);
int							op_fork(t_process *p, t_list **all_p,
								t_info *info, unsigned c);
int							op_lld(t_process *p, t_list **all_p,
								t_info *info, unsigned c);
int							op_lldi(t_process *p, t_list **all_p,
								t_info *info, unsigned c);
int							op_lfork(t_process *p, t_list **all_p,
								t_info *info, unsigned c);
int							op_aff(t_process *p, t_list **all_p,
								t_info *info, unsigned c);
void						print_bytes(t_win *win);
void						print_pc(t_win *win, t_list *l);
void						print_state(t_win *win);
void						print_bonus(t_win *win, t_info info,
								unsigned cycle);
void						print_player(t_win *win, t_list *l, t_info info);
int							init_win(t_win **win);
WINDOW						*create_newwin(int height, int width,
								int starty, int startx);
int							del_win(t_win *win);
void						readapt_win(t_win *win, t_list *l,
								t_info info, unsigned cycle);
int							print_graph(t_list *l, t_info *info,
								unsigned cycle);

#endif
