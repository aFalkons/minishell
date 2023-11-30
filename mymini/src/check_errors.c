/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:16:57 by afalconi          #+#    #+#             */
/*   Updated: 2023/11/30 13:19:38 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_messag(t_minitree *node)
{
	char	*str;

	str = NULL;
	if (node->token->token == ARG && bl_is_builtins(node->token->next->str) == 0)
	{
		str = ft_strjoin("Error: comand not found --",
				node->token->next->str);
	}
	else if (node->token->token == CMD && bl_is_builtins(node->token->str) == 0)
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
	struct s_list_redirection	*redire;

	str = NULL;
	redire = NULL;
	if (node->exit_status == 127)
	{
		error_messag(node);
	}
	redire = node->redire;
	while(redire && redire->fd_copy != 42)
		redire = redire->next;
	if (node->exit_status == 1 && redire != NULL && redire->token == INP)
	{
		str = ft_strjoin("Error:  No such file or directory --",
				redire->file);
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
