/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:43:42 by afalconi          #+#    #+#             */
/*   Updated: 2023/11/29 20:59:13 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

struct s_minitree	*ps_create_or_insert(void)
{
	struct s_minitree	*tree_node;

	tree_node = NULL;
	tree_node = ft_calloc(sizeof(struct s_minitree), 1);
	tree_node->subsh = NULL;
	tree_node->next = NULL;
	tree_node->token = NULL;
	tree_node->exit_status = 0;
	tree_node->fd_file = NULL;
	tree_node->redire = NULL;
	tree_node->close_redire = NULL;
	tree_node->flag_pipe = 0;
	return (tree_node);
}

static void	ps_create_node_sub(t_shell_info *sh_info
	, int8_t flag, struct s_minitree *tree_node)
{
	if (flag == 0)
	{
		tree_node->next = ps_create_or_insert();
		tree_node = tree_node->next;
	}
	else
	{
		tree_node->subsh = ps_create_or_insert();
		tree_node = tree_node->subsh;
	}
	tree_node->token = sh_info->lx_ls_token;
	if (sh_info->lx_ls_token->token == CL_S)
	{
		sh_info->lx_ls_token = sh_info->lx_ls_token->next;
		ps_recursiv_tree(sh_info, tree_node);
		return ;
	}
	if (sh_info->lx_ls_token == NULL)
		return ;
	if (sh_info->lx_ls_token->token == ARG)
		sh_info->lx_ls_token = sh_info->lx_ls_token->next;
	sh_info->lx_ls_token = sh_info->lx_ls_token->next;
}

void	ps_recursiv_tree(t_shell_info *sh_info, struct s_minitree *tree_node)
{
	while (sh_info->lx_ls_token)
	{
		if (sh_info->lx_ls_token->token == OP_S)
		{
			ps_create_node_sub(sh_info, 0, tree_node);
			break ;
		}
		else if (sh_info->lx_ls_token->token == CL_S)
		{
			ps_create_node_sub(sh_info, 1, tree_node);
		}
		else
		{
			ps_create_node_sub(sh_info, 0, tree_node);
			tree_node = tree_node->next;
		}
	}
}

static void	ps_swap_list(struct s_lx_list_token *lx_ls_token
	, struct s_lx_list_token *tmp, t_shell_info *sh_info)
{
	if (lx_ls_token->next == NULL)
		sh_info->lx_ls_token_h = lx_ls_token;
	if (lx_ls_token->next != NULL)
		ps_swap_list(lx_ls_token->next, lx_ls_token, sh_info);
	lx_ls_token->next = tmp;
}

int	ft_parser(t_shell_info *sh_info, struct s_minitree *tree_node)
{
	g_for_sig = 4;
	ps_swap_list(sh_info->lx_ls_token, NULL, sh_info);
	sh_info->lx_ls_token = sh_info->lx_ls_token_h;
	ps_recursiv_tree(sh_info, tree_node);
	ps_redirection_setup(sh_info->node, sh_info->node_h, sh_info);
	add_history(sh_info->input);
	sh_info->node = sh_info->node_h;
	if (ps_set_hdoc(sh_info->node, sh_info->node_h, sh_info) == 1)
	{
		sh_info->last_exit = 130;
		return(1);
	}
	return(0);
}
