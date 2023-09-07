/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 06:46:09 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/07 23:03:20 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ex_error_setup(t_minitree *node)
{
	node->exit_status = -1;
	while(node)
	{
		if (node->token->token == OR)
			break;
		node->exit_status = -1;
		node = node->next;
	}
}

static void	ex_chose_token(t_minitree *node,t_shell_info *sh_info, t_minitree *node_h)
{
	if (node == node_h)
		(void)sh_info;
	else if (node->token->token == ARG)
		ex_cmd(node->token->next, node->token, node, sh_info);
	else if (node->token->token == CMD)
		ex_cmd(node->token, NULL, node, sh_info);
	// else if (node->token->token == AND)
	// 	ex_and(node);
	// else if (node->token->token == OR)
	// 	ex_or(node);
	// else if (node->token->token == PIPE)
	// 	ex_pipe(node);
	// else if (node->token->token == CL_S)
	// 	ex_cl_s(node);

}

static void	ex_all_node(t_minitree *node, t_minitree *node_h, t_shell_info *sh_info)
{
	if (node == NULL)
		return ;
	if (node->next)
		ex_all_node(node->next, node_h, sh_info);
	if (node->subsh)
		ex_all_node(node->subsh, node_h, sh_info);
	if (node->close_redire || node->redire)
		ex_ck_redirection(node);
	if (node->redire->exit_inp == 1)
		ex_error_setup(node);
	if (node->exit_status == 0)
		ex_chose_token(node, sh_info, node_h);
}

void	ft_executor(t_shell_info *sh_info)
{
	ex_all_node(sh_info->node, sh_info->node_h, sh_info);
}
