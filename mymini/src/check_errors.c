/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:16:57 by afalconi          #+#    #+#             */
/*   Updated: 2023/10/03 03:42:21 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ck_tree_error(t_minitree *node)
{
	char	*str;

	str = NULL;
	if (node->exit_status == 127)
	{
		if (node->token->token == ARG)
			str = ft_strjoin("Error: comand not found --", node->token->next->str);
		else if (node->token->token == CMD)
			str = ft_strjoin("Error: comand not found --", node->token->str);
		ft_print_message(str, 2);
		free(str);
	}
}

void	ft_check_args(int argc, char **argv)
{
	if (argc != 1)
	{
		ft_print_message("Error: too many arguments", 2);
		exit(1);
	}
	(void) argv;
}

void	ft_check_lexical_error(t_shell_info *sh_info)
{
	if (sh_info->lx_error == 1)
		ft_print_message("Error: lexical error", 2);
	sh_info->lx_error = 0;
}
