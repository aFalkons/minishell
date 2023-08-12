/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 00:42:57 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/12 06:58:25 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ls_free_ls_recursiv(struct s_lx_list_token	*tmp)
{
	if (tmp->next)
		ls_free_ls_recursiv(tmp->next);
	free(tmp->str);
	free(tmp);
}

void	lx_free_ls(t_shell_info *sh_info)
{
	ls_free_ls_recursiv(sh_info->lx_ls_token_h);
	sh_info->lx_ls_token_h = NULL;
	sh_info->lx_ls_token = NULL;
}

static void	ps_free_tree_recursiv(struct s_minitree *tree_node)
{
	if (tree_node->subsh)
		ps_free_tree_recursiv(tree_node->subsh);
	if (tree_node->next)
		ps_free_tree_recursiv(tree_node->next);
	free(tree_node);
}

void	ps_free_tree(t_shell_info *sh_info)
{
	ps_free_tree_recursiv(sh_info->node_h);
	sh_info->node = NULL;
	sh_info->node_h = NULL;
}

