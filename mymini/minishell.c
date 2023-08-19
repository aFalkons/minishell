/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:09:31 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/18 16:46:37 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_shell_info		sh_info;
	// t_builtins			builtins;
	ft_check_args(argc, argv);
	ft_init_variables(env, &sh_info);
	add_history("echo 0 && (echo 1 > file1 && (echo 2 && echo 3 > file2)) > file3");
	ping();
	while (1)
	{
		ft_init_var_newcmd(&sh_info);
		sh_info.input = readline("\033[32mminishell> \033[0m");
		// printf("--%d\n", sh_info.fd_stdin);
		// printf("--%d\n", sh_info.fd_stdout);
		ft_lexical(&sh_info);
		// print_list(sh_info.lx_ls_token_h);
		ft_parser(&sh_info, sh_info.node);
		// print_tree(sh_info.node, sh_info.node_h);
		//printf("GG\n");
		ft_executor(&sh_info);
		ft_check_lexical_error(&sh_info);
		lx_free_ls(&sh_info);
		ps_free_tree(&sh_info);
	}
	return (0);
}
