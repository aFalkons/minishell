/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:16:57 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/02 15:26:08 by misidori         ###   ########.fr       */
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

typedef struct s_shell_info
{
	char			**env;
	char			*input;
	char			*pwd;
	int				lx_error;
	t_list_token	*lx_ls_token;
	t_list_token	*lx_ls_token_h;
}	t_shell_info;

typedef struct s_minitree
{
	char				*str;
	char				token;
	t_cmd				*cmd;
	struct s_minitree	*next;
	struct s_minitree	*subsh;
	struct s_minitree	*back;
}	t_minitree;

void	ft_check_args(int argc, char **argv);
void	ft_init_variables(char **env, t_shell_info *sh_info);
void	ft_check_lexical_error(t_shell_info *sh_info);

/*	lexical	*/
void	ft_lexical(t_shell_info *sh_info);
void	lx_list_token(t_shell_info *sh_info);
void 	lx_create_or_insert(t_shell_info *sh_info);

/*	bultins.c	*/
int		ft_pwd(t_shell_info *sh_info, t_builtins *builtins, int j, int argc);
void	ft_cd(t_shell_info *sh_info, t_builtins *builtins);
int		ft_builtins_cmd(t_shell_info *sh_info, t_builtins *builtins);



#endif
