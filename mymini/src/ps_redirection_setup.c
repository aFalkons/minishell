/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_redirection_setup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:34:42 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/21 04:34:50 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ps_setup_out_app(t_minitree *node)
{
	t_minitree *tmp;
	int		*fd_tmp;
	struct s_lx_list_token *redirection;

	tmp = NULL;
	node->fd_file = ft_calloc(sizeof(int *), 1);
	fd_tmp = node->fd_file;
	redirection = node->token;
	while(node)
	{
		if (node->next == NULL || node->next->token->token == AND || node->next->token->token == OR || node->next->token->token == OP_S)
		{
			tmp = node->next;
			node->next = NULL;
			node->next = ps_create_or_insert();
			node = node->next;
			node->fd_file = fd_tmp;
			node->next = tmp;
			node->token = redirection;
			node->open_redirection = 1;
			break;
		}
		node = node->next;
	}
}

void	ps_redirection_setup(t_minitree *node, t_minitree *node_h)
{
	if (node != node_h)
	{
		if ((node->token->token == OUT || node->token->token == APP) && node->open_redirection == 0)
			ps_setup_out_app(node);
		// else if (node->token->token == INP || node->token->token == HDOC)
		// 	ps_setup_inp_hdoc(node, sh_info);
	}
	if (node->subsh)
		ps_redirection_setup(node->subsh, node_h);
	if (node->next)
		ps_redirection_setup(node->next, node_h);
	if (node == NULL)
		return ;
}
