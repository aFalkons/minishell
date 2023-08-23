/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 06:46:09 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/21 12:54:14 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ex_chose_token(t_minitree *node,t_shell_info *sh_info)
{
	printf("--%s\n", node->token->str);
	if (node->token->token == ARG)
		ex_cmd(node->token->next, node->token, node, sh_info);
	else if (node->token->token == CMD)
		ex_cmd(node->token, NULL, node, sh_info);
	if (node->token->token == OUT)
		ex_out(node, sh_info);
	// else if (node->token->token == APP)
	//	ex_out(node->token, NULL, node, sh_info);
	// else if (node->token->token == AND)
	// 	ex_and(node);
	// else if (node->token->token == OR)
	// 	ex_or(node);
	// else if (node->token->token == PIPE)
	// 	ex_pipe(node);
	// else if (node->token->token == CL_S)
	// 	ex_cl_s(node);
	(void)sh_info;
}

static void	ex_all_node(t_minitree *node, t_minitree *node_h, t_shell_info *sh_info)
{
	if (node->next)
		ex_all_node(node->next, node_h, sh_info);
	if (node->subsh)
		ex_all_node(node->subsh, node_h, sh_info);
	if (node == NULL)
		return ;
	// if (node->next == NULL && node->subsh == NULL)
	if (node != node_h)
		ex_chose_token(node, sh_info);
}

void	ft_executor(t_shell_info *sh_info)
{
	ex_all_node(sh_info->node, sh_info->node_h, sh_info);
	// printf("GG\n");
	// print_tree(sh_info->node, sh_info->node_h);
}
