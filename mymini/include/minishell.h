/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:16:57 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/27 17:22:24 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/src/libft.h"

# define AND	0b01000001
# define OR  	0b01000010
# define PIPE	'|'
# define CMD	0b01000011
# define ARG	0b01000100
# define INP	'<'
# define HDOC	0b01000101
# define OUT 	'>'
# define APP	0b01000110

typedef struct s_cmd {
	char			**cmd;
	char			*path;
}	t_cmd;

typedef struct s_lx_list_token {
	char					*str;
	char					token;
	struct s_lx_list_token	*next;
} t_list_token;

typedef struct s_shell_info {
	char			**env;
	char			*input;
	char			*pwd;
	int				lx_error;
	t_list_token	*lx_ls_token;
	t_list_token	*lx_ls_token_h;
}	t_shell_info;

typedef struct s_minitree {
	char				*str;
	char				token;
	t_cmd				*cmd;
	struct s_minitree	*next;
	struct s_minitree	*subsh;
	struct s_minitree	*back;
}	t_minitree;

void	ck_arg(int ac, char **av);
void	init_val(char **env, t_shell_info *sh_info);
void	ck_error(t_shell_info *sh_info);

// lexical
void	lexical(t_shell_info *sh_info);
void	lx_list_token(t_shell_info *sh_info);
void 	lx_crate_or_insert(t_shell_info *sh_info);


#endif
