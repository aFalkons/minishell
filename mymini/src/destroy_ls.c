/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 00:42:57 by afalconi          #+#    #+#             */
/*   Updated: 2023/11/10 19:50:13 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	bl_free_list_var(t_node *node)
{
	if (node->next)
		bl_free_list_var(node->next);
	ft_free_node(node);
}

static void	ls_free_ls_recursiv(struct s_lx_list_token *tmp)
{
	if (tmp->next)
		ls_free_ls_recursiv(tmp->next);
	free(tmp->str);
	free(tmp);
}

void	lx_free_ls(t_shell_info *sh_info, int flag)
{
	ls_free_ls_recursiv(sh_info->lx_ls_token_h);
	sh_info->lx_ls_token_h = NULL;
	sh_info->lx_ls_token = NULL;
	if (flag == 1)
	{
		bl_free_list_var(sh_info->var->node);
		free(sh_info->var);
	}
}

static void	ps_free_redire(struct s_list_redirection *redire)
{
	struct s_list_redirection	*tmp;

	tmp = NULL;
	while (redire)
	{
		if (redire->file != NULL)
			free(redire->file);
		tmp = redire->next;
		free(redire);
		redire = tmp;
	}
}

void	ps_free_tree_recursiv(struct s_minitree *tree_node)
{
	if (tree_node->subsh)
		ps_free_tree_recursiv(tree_node->subsh);
	if (tree_node->next)
		ps_free_tree_recursiv(tree_node->next);
	if (tree_node->redire)
		ps_free_redire(tree_node->redire);
	free(tree_node);
}
