/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:16:57 by afalconi          #+#    #+#             */
/*   Updated: 2023/11/09 22:12:31 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_messag(t_minitree *node)
{
	char	*str;

	str = NULL;
	if (node->token->token == ARG)
	{
		str = ft_strjoin("Error: comand not found --",
				node->token->next->str);
	}
	else if (node->token->token == CMD)
	{
		str = ft_strjoin("Error: comand not found --",
				node->token->str);
	}
	ft_print_message(str, 2);
	free(str);
}

void	ck_tree_error(t_minitree *node)
{
	char	*str;

	str = NULL;
	if (node->exit_status == 127)
	{
		error_messag(node);
	}
	if (node->token->token == INP && node->exit_status == 1)
	{
		str = ft_strjoin("Error:  No such file or directory --",
				node->redire->file);
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
