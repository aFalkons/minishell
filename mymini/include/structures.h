/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:09:57 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/07 22:40:55 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_builtins
{
	char	current_directory[4096];
}	t_builtins;

typedef struct s_lx_list_token
{
	char					*str;
	char					token;
	struct s_lx_list_token	*next;
}	t_lx_list_token;

typedef struct s_list_redirection
{
	char					*file;
	int						fd_input;
	char					token;
	int8_t					dont_say_that;
	int						fd_copy;
	int						fd_of_file;
	int8_t					exit_inp;
	struct s_list_redirection	*next;
}	t_list_redirection;

typedef struct s_minitree
{
	struct s_lx_list_token		*token;
	int8_t						exit_status;
	int							*fd_file;
	int							fd_output;
	int							fd_input;
	struct s_list_redirection	*redire;
	struct s_list_redirection	*close_redire;
	char						**env;
	struct s_minitree			*next;
	struct s_minitree			*subsh;
}	t_minitree;

typedef struct s_shell_info
{
	char				**env;
	char				*complite;
	char				*input;
	char				*pwd;
	int					fd_stdin;
	int					fd_stdout;
	int8_t				lx_error;
	int8_t				is_emty;
	t_list_redirection	*redire;
	t_list_redirection	*redire_h;
	t_lx_list_token		*lx_ls_token;
	t_lx_list_token		*lx_ls_token_h;
	t_minitree			*node;
	t_minitree			*node_h;
}	t_shell_info;

#endif

