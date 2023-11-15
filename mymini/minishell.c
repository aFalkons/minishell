/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:09:31 by afalconi          #+#    #+#             */
/*   Updated: 2023/11/15 21:11:57 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	for_sig;

static void	heart(t_shell_info *sh_info)
{
	if (for_sig == 2)
		sh_info->last_exit = 130;
	else if (sh_info->input)
	{
		ft_lexical(sh_info);
		if (sh_info->lx_error != 0 || for_sig == 3)
			add_history(sh_info->input);
		if (sh_info->lx_error == 1)
			ft_print_message("Error: lexical error", 2);
		else if (sh_info->lx_error == 2)
			ft_print_message("\nError: unexpected EOF", 2);
		else if (sh_info->is_emty == 0 && sh_info->lx_error != 1
			&& for_sig != 3)
		{
			ft_parser(sh_info, sh_info->node);
			add_history(sh_info->input);
			ft_executor(sh_info);
			ps_free_tree_recursiv(sh_info->node_h);
		}
		if (sh_info->is_emty == 0 && sh_info->lx_error != 2 && for_sig != 3)
			lx_free_ls(sh_info, 0);
	}
	else
		ft_exit(1, "exit", sh_info->last_exit);
}

int	main(int argc, char **argv, char **env)
{
	t_shell_info		sh_info;

	ft_check_args(argc, argv);
	ping();
	ft_init_variables(env, &sh_info);
	while (1)
	{
		ft_init_var_newcmd(&sh_info, env);
		sh_info.input = readline("\033[32mminishell> \033[0m");
		heart(&sh_info);
		free(sh_info.input);
	}
	return (0);
}
