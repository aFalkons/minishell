/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:09:31 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/08 05:01:31 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_shell_info		sh_info;

	ft_check_args(argc, argv);
	ft_init_variables(env, &sh_info);
	ping();
	while (1)
	{
		ft_init_var_newcmd(&sh_info);
		sh_info.input = readline("\033[32mminishell> \033[0m");
		ft_lexical(&sh_info);
		//print_list(sh_info.lx_ls_token);
		if (sh_info.lx_error == 1)
			ft_print_message("Error: lexical error", 2);
		else if (sh_info.is_emty == 0 && sh_info.lx_error != 1)
		{
			ft_parser(&sh_info, sh_info.node);
			//print_tree(sh_info.node, sh_info.node_h, 1);
			ft_executor(&sh_info);
			ft_check_lexical_error(&sh_info);
			ps_free_tree(&sh_info);
		}
		if (sh_info.is_emty == 0)
			lx_free_ls(&sh_info);
	}
	return (0);
}
