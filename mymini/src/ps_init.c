/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:43:42 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/10 13:31:32 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void ps_create_node_sub(t_shell_info *sh_info, int flag, struct s_minitree *tree_node)
{
	// printf("-%p\n", tree_node);
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
	// printf("--%p\n", tree_node);
	tree_node->token = sh_info->lx_ls_token;
	// printf("---%c\n", tree_node->token->token);
	while (!(sh_info->lx_ls_token->token == AND || sh_info->lx_ls_token->token == OR || sh_info->lx_ls_token->token == PIPE || sh_info->lx_ls_token->token == OP_S || sh_info->lx_ls_token->token == CL_S))
	{
		sh_info->lx_ls_token = sh_info->lx_ls_token->next;
		if (sh_info->lx_ls_token == NULL)
			break;
	}
	if (sh_info->lx_ls_token == NULL)
		return ;
	if (sh_info->lx_ls_token->token == OP_S)
	{
		sh_info->lx_ls_token = sh_info->lx_ls_token->next;
		ft_parser(sh_info, tree_node);
	}
	if (tree_node->token->token == AND || tree_node->token->token == OR || tree_node->token->token == PIPE)
		sh_info->lx_ls_token = sh_info->lx_ls_token->next;

}

static void	ps_recursiv_tree(t_shell_info *sh_info, struct s_minitree *tree_node)
{
	while (sh_info->lx_ls_token)
	{
		if (sh_info->lx_ls_token->token == CL_S)
		{
			sh_info->lx_ls_token = sh_info->lx_ls_token->next;
			break ;
		}
		if (sh_info->lx_ls_token->token == AND || sh_info->lx_ls_token->token == OR || sh_info->lx_ls_token->token == PIPE)
		{
			ps_create_node_sub(sh_info, 0, tree_node);
			tree_node = tree_node->next;
		}
		else if (sh_info->lx_ls_token->token == OP_S)
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

void	print_tree(struct s_minitree *tree_node)
{
	while (tree_node != NULL)
	{
		if (tree_node->token != NULL)
			printf("------%c\n", tree_node->token->token);
		if (tree_node->subsh)
			print_tree(tree_node->subsh);
		tree_node = tree_node->next;
	}
}

static void	ps_swap_list(t_shell_info *sh_info)
{
	x
}

void	ft_parser(t_shell_info *sh_info, struct s_minitree *tree_node)
{
	ps_swap_list(sh_info);
	ps_recursiv_tree(sh_info, tree_node)
}
