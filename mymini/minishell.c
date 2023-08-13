/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:09:31 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/13 13:23:21 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_shell_info		sh_info;
	// t_builtins			builtins;
	ft_check_args(argc, argv);
	ft_init_variables(env, &sh_info);
	add_history("(echo 1 && (echo 2 || echo 3)) && (echo 4 && echo 5) | echo 6");
	while (1)
	{
		ft_init_var_newcmd(&sh_info);
		ft_check_lexical_error(&sh_info);
		sh_info.input = readline("\033[32mminishell> \033[0m");
		ft_lexical(&sh_info);
		ft_parser(&sh_info, sh_info.node);
		ft_executor(&sh_info);
		// ft_builtins_cmd(&sh_info, &builtins);
		lx_free_ls(&sh_info);
		ps_free_tree(&sh_info);
	}
	return (0);
}
