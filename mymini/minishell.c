/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <matteo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:09:31 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/01 18:42:53 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_shell_info		sh_info;
	t_builtins			builtins;
	//struct s_minitree	mini_tree;

	ft_check_args(argc, argv);
	ft_init_variables(env, &sh_info);
//	printf("%s\n", ft_pwd(env));
	while(1)
	{
		ft_check_lexical_error(&sh_info);
		sh_info.input = readline("\033[32mminishell> \033[0m");
		add_history(sh_info.input);
		ft_lexical(&sh_info);
		ft_builtins_cmd(&sh_info, &builtins);
		if (sh_info.lx_error != 1)
		{
			//si continua a fare robba
		}
	}
	return (0);
}
