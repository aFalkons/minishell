/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:43:42 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/12 16:15:02 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void ps_create_node_sub(t_shell_info *sh_info, int flag, struct s_minitree *tree_node)
{
	if (flag == 0)
		tree_node->next = ps_create_or_insert(sh_info);
	else
		tree_node->subsh = ps_create_or_insert(sh_info);
	if (flag == 0)
		tree_node = tree_node->next;
	else
		tree_node = tree_node->subsh;
	tree_node->token = sh_info->lx_ls_token;
	while (!(sh_info->lx_ls_token->token == AND || sh_info->lx_ls_token->token == OR || sh_info->lx_ls_token->token == PIPE || sh_info->lx_ls_token->token == OP_S || sh_info->lx_ls_token->token == CL_S))
	{
		sh_info->lx_ls_token = sh_info->lx_ls_token->next;
		if (sh_info->lx_ls_token == NULL)
			break;
	}
	if (sh_info->lx_ls_token == NULL)
		return ;
	if (sh_info->lx_ls_token->token == CL_S)
	{
		sh_info->lx_ls_token = sh_info->lx_ls_token->next;
		ps_recursiv_tree(sh_info, tree_node);
	}
	if (tree_node->token->token == AND || tree_node->token->token == OR || tree_node->token->token == PIPE)
		sh_info->lx_ls_token = sh_info->lx_ls_token->next;
}

void	ps_recursiv_tree(t_shell_info *sh_info, struct s_minitree *tree_node)
{
	while (sh_info->lx_ls_token)
	{
		if (sh_info->lx_ls_token->token == OP_S)
		{
			ps_create_node_sub(sh_info, 0, tree_node);
			sh_info->lx_ls_token = sh_info->lx_ls_token->next;
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

// void	print_tree(struct s_minitree *tree_node, int i)
// {
// 	while (tree_node != NULL)
// 	{
// 		if (tree_node->token != NULL)
// 		{
// 			printf("%d",i);
// 			printf("------%c\n", tree_node->token->token);
// 		}
// 		if (tree_node->subsh)
// 			print_tree(tree_node->subsh, i++);
// 		tree_node = tree_node->next;
// 	}
// }

static void	ps_swap_list(struct s_lx_list_token *lx_ls_token, struct s_lx_list_token *tmp, t_shell_info *sh_info)
{
	if (lx_ls_token->next == NULL)
		sh_info->lx_ls_token_h = lx_ls_token;
	if (lx_ls_token->next != NULL)
		ps_swap_list(lx_ls_token->next, lx_ls_token, sh_info);
	lx_ls_token->next = tmp;
}

// static void	print_list(t_shell_info *sh_info)
// {
// 	t_list_token	*tmp;

// 	tmp = sh_info->lx_ls_token;
// 	while (tmp != NULL)
// 	{
// 		printf("%s\n", tmp->str);
// 		printf("%c\n", tmp->token);
// 		tmp = tmp->next;
// 	}
// }

// static void	print_tree_test(struct s_minitree *tree_node, struct s_minitree *tree_node_h)
// {
// 	if (tree_node->next)
// 		print_tree_test(tree_node->next, tree_node_h);
// 	if (tree_node->subsh)
// 		print_tree_test(tree_node->subsh, tree_node_h);
// 	if (tree_node != tree_node_h)
// 	{
// 		printf("---%s\n", tree_node->token->str);
// 		// printf("--%p\n", tree_node->env);
// 	}
// }

void	ft_parser(t_shell_info *sh_info, struct s_minitree *tree_node)
{
	ps_swap_list(sh_info->lx_ls_token, NULL, sh_info);
	sh_info->lx_ls_token = sh_info->lx_ls_token_h;
	// print_list(sh_info);
	ps_recursiv_tree(sh_info, tree_node);
	sh_info->node = sh_info->node_h;
	// print_tree_test(sh_info->node, sh_info->node_h);
}
