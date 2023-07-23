/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:09:31 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/23 15:40:37 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_shell_info		sh_info;
	//struct s_minitree	mini_tree;

	ck_arg(ac, av);
	init_val(env, &sh_info);
	while(1)
	{
		// if ((int)"&&" == AND)
		ck_error(&sh_info);
		sh_info.input = readline("Minishell>");
		add_history(sh_info.input);
		lexical(&sh_info);
		if (sh_info.lx_error != 1)
		{
			//si cntinua a fare robba
		}
	}
	return (0);
}
