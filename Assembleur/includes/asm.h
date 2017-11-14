/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 12:20:50 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/07/01 12:19:42 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <fcntl.h>
# include "../ft_printf/ft_printf.h"
# include "get_next_line.h"
# include "op.h"

typedef struct		s_file
{
	char			*line;
	struct s_file	*next;
}					t_file;

typedef struct		s_lab
{
	char			*name;
	int				oct;
	struct s_lab	*next;
}					t_lab;

typedef struct		s_asm
{
	int				fd;
	char			*buf;
	char			*str;
	char			*s_err;
	char			*i_err;
	char			*t_err;
	int				c_err;
	int				p_err;
	int				l_err;
	int				lbl;
	int				gdi;
	int				i;
	int				size;
	int				insi;
	t_file			*file;
	t_lab			*lab;
	int				r;
	int				o;
	int				opcode;
	char			bitco[9];
}					t_asm;

union				u_asm
{
	int				nb;
	char			nbr[4];
};

void				ft_error_asm(int nb, t_asm **as);
t_asm				**ft_clean(t_asm **as);
void				ft_cleaning(char **tab, char *s);
void				ft_get_champ(t_asm **as);
void				ft_process_champ(t_asm **as);
int					ft_is_comment(t_asm **as);
int					ft_is_naco(t_asm **as);
int					ft_is_label(t_asm **as);
int					ft_mult_inst(t_asm **as);
void				ft_good_inst(t_asm **as);
int					ft_is_inst(char *str);
int					ft_is_inst_bis(char *str);
char				*ft_comm(char *str);
t_asm				*ft_new_struct(char *path);
int					ft_new_struct_bis(t_asm **as);
t_file				*ft_init_writing(t_asm **as, int *n);
int					ft_is_para(char *str, t_asm **as);
char				*ft_type_para(char *str);
int					ft_w_para(char *str);
int					ft_is_regist(char *str);
int					ft_is_direct(char *str);
int					ft_is_indire(char *str);
int					ft_not_inst(char **tab, t_asm **as);
int					ft_is_live(char **tab, t_asm **as);
int					ft_is_ld(char **tab, t_asm **as);
int					ft_is_st(char **tab, t_asm **as);
int					ft_is_add(char **tab, t_asm **as);
int					ft_is_sub(char **tab, t_asm **as);
int					ft_is_and(char **tab, t_asm **as);
int					ft_is_or(char **tab, t_asm **as);
int					ft_is_xor(char **tab, t_asm **as);
int					ft_is_zjmp(char **tab, t_asm **as);
int					ft_is_ldi(char **tab, t_asm **as);
int					ft_is_sti(char **tab, t_asm **as);
int					ft_is_fork(char **tab, t_asm **as);
int					ft_is_lld(char **tab, t_asm **as);
int					ft_is_lldi(char **tab, t_asm **as);
int					ft_is_lfork(char **tab, t_asm **as);
int					ft_is_aff(char **tab, t_asm **as);
void				ft_is_name(t_asm **as);
void				ft_is_comm(t_asm **as);
void				ft_print_hex(char *buf, int size);
t_file				*ft_new_file(char *str);
void				ft_add_file(t_file **begin, t_file *new);
void				ft_print_file(t_file *lst);
void				ft_clean_file(t_file **lst);
void				ft_save_file(t_asm **as);
t_lab				*ft_new_lab(char *str, int o);
void				ft_add_lab(t_lab **begin, t_lab *new);
void				ft_print_lab(t_lab *lst);
void				ft_clean_lab(t_lab **lst);
void				ft_lst_lab(t_asm **as, char *str);
void				ft_check_label(char *str, t_asm **as, int t);
int					ft_para_to_nbr(char *str, t_asm **as);
int					ft_para_lab(char *str, t_asm **as);
int					ft_coding_bit(char **tab, t_asm **as, int p);
void				ft_write_inst(char **tab, t_asm **as, int p, int s);
void				ft_instance(char **tab, t_asm **as, int p, int sp);
void				ft_add_nbr(t_asm **as, char n);
void				ft_add_size(t_asm **as, int ret);
void				ft_create_file(t_asm **as, char *name);
char				*ft_new_name(char *name);
int					ft_begin_inst(t_asm **as, char *str, int *r, int p);
void				ft_too_much_para(t_asm **as, char *str);
void				ft_end_inst(t_asm **as, char *str, int r);
void				ft_error_asm_bis(int nb, t_asm **as);
char				*ft_lab_cat(char *str);
char				*ft_str_du_turfu(char **tab, int n);
void				ft_is_too_long(t_asm **as, int i, char *s);

#endif
