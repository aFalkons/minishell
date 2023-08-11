/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:09:31 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/11 08:39:01 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_shell_info		sh_info;
	// t_builtins			builtins;
	ft_check_args(argc, argv);
	ft_init_variables(env, &sh_info);
	while (1)
	{
		ft_init_var_newcmd(&sh_info);
		ft_check_lexical_error(&sh_info);
		sh_info.input = readline("\033[32mminishell> \033[0m");
		add_history(sh_info.input);
		ft_lexical(&sh_info);
		ft_parser(&sh_info, sh_info.node);
		// ft_builtins_cmd(&sh_info, &builtins);
		lx_free_ls(&sh_info);
	}
	return (0);
}
