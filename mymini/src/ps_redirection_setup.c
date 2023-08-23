/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_redirection_setup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:34:42 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/23 19:26:10 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ps_setup_out_app(t_minitree *node, t_shell_info *sh_info, t_minitree *and_or)
{
	t_minitree				*tmp;
	int						*fd_tmp;
	struct s_lx_list_token	*redirection;

	node->fd_file = ft_calloc(sizeof(int *), 1);
	fd_tmp = node->fd_file;
	redirection = node->token;
	if (and_or == NULL)
	{
		tmp = ps_create_or_insert(sh_info);
		tmp->
	}
	if (and_or->next != node)
	{
		tmp = and_or->next;
		and_or->next = NULL;
		and_or->next = ps_create_or_insert(sh_info);
		and_or = and_or->next;
		and_or->fd_file = fd_tmp;
		and_or->next = tmp;
		and_or->token = redirection;
		node->open_redirection = 1;
		and_or->env = sh_info->env;
		return;
	}
	while(node)
	{
		if (node->next == NULL || node->next->token->token == AND || node->next->token->token == OR || node->next->token->token == OP_S)
		{
			tmp = node->next;
			node->next = NULL;
			node->next = ps_create_or_insert(sh_info);
			node = node->next;
			node->fd_file = fd_tmp;
			node->next = tmp;
			node->token = redirection;
			node->open_redirection = 1;
			node->env = sh_info->env;
			break;
		}
		node = node->next;
	}
	(void)and_or;
}

void	ps_redirection_setup(t_minitree *node, t_minitree *node_h, t_shell_info *sh_info)
{
	static t_minitree *tmp;

	// printf("GG\n");
	// printf("%s\n", node->token->str);
	if (node != node_h)
	{
		if(node->token->token == AND || node->token->token == OR)
			tmp = node;
		printf("%s\n", node->token->str);
		if ((node->token->token == OUT || node->token->token == APP) && node->open_redirection == 0)
			ps_setup_out_app(node, sh_info, tmp);
		// else if (node->token->token == INP || node->token->token == HDOC)
		// 	ps_setup_inp_hdoc(node, sh_info);
	}
	if (node->subsh)
		ps_redirection_setup(node->subsh, node_h, sh_info);
	if (node->next)
		ps_redirection_setup(node->next, node_h, sh_info);
	if (node == NULL)
		return ;
}
