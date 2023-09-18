/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 06:46:09 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/18 21:32:20 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ex_chose_token(t_minitree *node,t_shell_info *sh_info, int last_exit)
{
	if (node->token->token == ARG)
		return(ex_cmd(node->token->next, node->token, node, sh_info));
	else if (node->token->token == CMD)
		return(ex_cmd(node->token, NULL, node, sh_info));
	// else if (node->token->token == CL_S)
	// 	ex_cl_s(node);
	return(last_exit);
}

static void	ex_all_node(t_minitree *node, t_minitree *node_h, t_shell_info *sh_info, int *exit_stat)
{
	if (node->next)
		ex_all_node(node->next, node_h, sh_info, exit_stat);
	if (node->subsh)
	{
		sh_info->pid = fork();
		if (sh_info->pid == 0)
		{
			sh_info->sub_level ++;
			ps_redirection_setup(node->subsh, node->subsh);
			ex_all_node(node->subsh, node_h, sh_info, exit_stat);
		}
		waitpid(-1 , 0, 0);
		if (sh_info->pid == 0)
			exit(1);
	}
	if ((node->close_redire || node->redire) && sh_info->pipe_flag != 1)
		ex_ck_redirection(node, sh_info);
	ex_pipe(node, sh_info);
	if (node != node_h && node->token->token == AND)
	{
		if (*exit_stat == 2)
			*exit_stat = 1;
		sh_info->stdin_flag= 0;
		sh_info->stdout_flag = 0;
	}
	else if (node != node_h && *exit_stat == 1 && node->token->token == OR)
	{
		*exit_stat = 2;
		sh_info->stdin_flag= 0;
		sh_info->stdout_flag = 0;
	}
	else if (node != node_h && *exit_stat == -1 && node->token->token == OR)
	{
		*exit_stat = 1;
		sh_info->stdin_flag= 0;
		sh_info->stdout_flag = 0;
	}
	else if ((node != node_h && *exit_stat == 1) && sh_info->pid_flag == 1)
	{
		*exit_stat = ex_chose_token(node, sh_info, *exit_stat);
	}
}

void	ft_executor(t_shell_info *sh_info)
{
	int	exit_stat;

	exit_stat = 1;
	ex_all_node(sh_info->node, sh_info->node_h, sh_info, &exit_stat);
}
