/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:09:57 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/17 20:38:34 by afalconi         ###   ########.fr       */
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


typedef struct s_minitree
{
	struct s_lx_list_token	*token;
	int						exit_status;
	int						fd_output;
	int						fd_input;
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
	int				fd_stdin;
	int				fd_stdout;
	int				lx_error;
	t_lx_list_token	*lx_ls_token;
	t_lx_list_token	*lx_ls_token_h;
	t_minitree		*node;
	t_minitree		*node_h;
}	t_shell_info;

#endif

