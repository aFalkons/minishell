/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:16:57 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/17 16:59:51 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/include/libft.h"
# include "./libraries.h"
# include "./structures.h"


# define AND	0b01000001
# define OR		0b01000010
# define PIPE	'|'
# define CMD	0b01000011
# define ARG	0b01000100
# define INP	'<'
# define HDOC	0b01000101
# define OUT	'>'
# define APP	0b01000110
# define OP_S	'('
# define CL_S	')'

void	ft_check_args(int argc, char **argv);
void	ft_init_variables(char **env, t_shell_info *sh_info);
void	ft_check_lexical_error(t_shell_info *sh_info);
void	ft_init_var_newcmd(t_shell_info *sh_info);
void	ping(void);

/*	lexical	*/
void	ft_lexical(t_shell_info *sh_info);
void	lx_list_token(t_shell_info *sh_info);
void 	lx_create_or_insert(t_shell_info *sh_info, char *str, char token);
void	lx_insert_cmd_arg(t_shell_info *sh_info, int *i);
void	lx_check_quotes(t_shell_info *sh_info, int *i);
void	lx_free_ls(t_shell_info *sh_info);
void	lx_skip_space(t_shell_info *sh_info, int *i);
void	lx_ck_list_token(t_shell_info *sh_info);

/*	parser	*/
void				ft_parser(t_shell_info *sh_info, struct s_minitree  *tree_node);
struct s_minitree	*ps_create_or_insert();
void				ps_recursiv_tree(t_shell_info *sh_info, struct s_minitree *tree_node);
void				ps_free_tree(t_shell_info *sh_info);


/*	executor	*/
void	ft_executor(t_shell_info *sh_info);
void 	ex_cmd(struct s_lx_list_token *cmd, struct s_lx_list_token *arg,  struct s_minitree *node);
void	ex_cl_s(t_minitree *node);
char	*ex_ck_cmd(struct s_lx_list_token *cmd,  struct s_minitree *node);
void	ex_out(t_minitree *node, t_shell_info *sh_info, int flag);
void	ex_real_esecution(char *path_cmd, char **arr_cmd_arg,  struct s_minitree *node);



/*	bultins.c	*/
int		ft_pwd(t_shell_info *sh_info, t_builtins *builtins, int j, int argc);
void	ft_cd(t_shell_info *sh_info, t_builtins *builtins);
int		ft_builtins_cmd(t_shell_info *sh_info, t_builtins *builtins);



#endif
