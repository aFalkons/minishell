/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:16:57 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/19 13:50:33 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/src/libft.h"

typedef struct s_cmd {
	char			**cmd;
	char			*path;
}	t_cmd;

typedef struct s_shell_info {
	char	**env;
	char	*input;
	char	*pwd;
	int		error;
}	t_shell_info;

typedef struct s_minitree {
	t_cmd				*cmd;
	struct s_minitree	*next;
	struct s_minitree	*subsh;
	struct s_minitree	*back;
}	s_minitree;

void	ck_arg(int ac, char **av);
void	init_val(char **env, t_shell_info *sh_info);
void	lexical(t_shell_info *sh_info);

#endif
