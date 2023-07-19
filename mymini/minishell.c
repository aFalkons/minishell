/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:09:31 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/19 14:11:34 by afalconi         ###   ########.fr       */
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
		sh_info.input = readline("Minishell>");
		lexical(&sh_info);
		if (sh_info.error != 1)
		{
			//si cntinua a fare robba
		}
	}
	return (0);
}
