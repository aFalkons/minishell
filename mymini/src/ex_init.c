/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 06:46:09 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/08 05:21:59 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//static void	ex_error_setup(t_minitree *node)
//{
//	node->exit_status = -1;
//	while(node)
//	{
//		if (node->token->token == OR)
//			break;
//		node->exit_status = -1;
//		node = node->next;
//	}
//}

static int	ex_chose_token(t_minitree *node,t_shell_info *sh_info, t_minitree *node_h, int last_exit)
{
	(void)last_exit;
	(void)sh_info;
	(void)node_h;
	if (node->token->token == ARG)
		return(ex_cmd(node->token->next, node->token, node, sh_info));
	else if (node->token->token == CMD)
		return(ex_cmd(node->token, NULL, node, sh_info));
	// else if (node->token->token == PIPE)
	// 	ex_pipe(node);
	// else if (node->token->token == CL_S)
	// 	ex_cl_s(node);
	return(0);
}

static void	ex_all_node(t_minitree *node, t_minitree *node_h, t_shell_info *sh_info, int *exit)
{
	if (node->next)
		ex_all_node(node->next, node_h, sh_info, exit);
	if (node->subsh)
		ex_all_node(node->subsh, node_h, sh_info, exit);
	if (node->close_redire || node->redire)
		ex_ck_redirection(node);
//	if (node->redire->exit_inp == 1)
//		ex_error_setup(node);
	if (node != node_h && node->token->token == AND )
		*exit = 1;
	else if (node != node_h && *exit == 1 && node->token->token == OR)
		*exit = -1;
	else if (node != node_h && *exit == 1)
		*exit = ex_chose_token(node, sh_info, node_h, *exit);
}

void	ft_executor(t_shell_info *sh_info)
{
	int	exit;

	exit = 1;
	ex_all_node(sh_info->node, sh_info->node_h, sh_info, &exit);
}
