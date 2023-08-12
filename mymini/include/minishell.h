/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:16:57 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/12 12:01:44 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/include/libft.h"
# include "./libraries.h"

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

typedef struct s_builtins
{
	char	current_directory[4096];
}	t_builtins;

typedef struct s_cmd {
	char			**cmd;
	char			*path;
}	t_cmd;

typedef struct s_lx_list_token
{
	char					*str;
	char					token;
	struct s_lx_list_token	*next;
}	t_list_token;

typedef struct s_minitree
{
	struct s_lx_list_token	*token;
	int						exit_status;
	char					**env;
	struct s_minitree		*next;
	struct s_minitree		*subsh;
}	t_minitree;

typedef struct s_shell_info
{
	char			**env;
	char			*complite;
	char			*input;
	char			*pwd;
	int				lx_error;
	t_list_token	*lx_ls_token;
	t_list_token	*lx_ls_token_h;
	t_minitree		*node;
	t_minitree		*node_h;
}	t_shell_info;

void	ft_check_args(int argc, char **argv);
void	ft_init_variables(char **env, t_shell_info *sh_info);
void	ft_check_lexical_error(t_shell_info *sh_info);
void	ft_init_var_newcmd(t_shell_info *sh_info);

/*	lexical	*/
void	ft_lexical(t_shell_info *sh_info);
void	lx_list_token(t_shell_info *sh_info);
void 	lx_create_or_insert(t_shell_info *sh_info, char *str, char token);
void	lx_insert_cmd_arg(t_shell_info *sh_info, int *i);
void	lx_check_quotes(t_shell_info *sh_info, int *i);
void	lx_free_ls(t_shell_info *sh_info);
void	lx_skip_space(t_shell_info *sh_info, int *i);
void	ck_list_token(t_shell_info *sh_info);

/*	parser	*/
void				ft_parser(t_shell_info *sh_info, struct s_minitree  *tree_node);
struct s_minitree	*ps_create_or_insert();
void				ps_recursiv_tree(t_shell_info *sh_info, struct s_minitree *tree_node);
void				ps_free_tree(t_shell_info *sh_info);


/*	executor	*/
void	ft_executor(t_shell_info *sh_info);
void 	ex_cmd(struct s_lx_list_token *cmd, struct s_lx_list_token *arg,  struct s_minitree *node);
void	ex_po_s(t_minitree *node);
char	*ex_ck_cmd(struct s_lx_list_token *cmd,  struct s_minitree *node);



/*	bultins.c	*/
int		ft_pwd(t_shell_info *sh_info, t_builtins *builtins, int j, int argc);
void	ft_cd(t_shell_info *sh_info, t_builtins *builtins);
int		ft_builtins_cmd(t_shell_info *sh_info, t_builtins *builtins);



#endif
