/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_create_insert_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:50:51 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/17 16:11:01 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

struct s_minitree	*ps_create_or_insert(t_shell_info *sh_info)
{
	struct s_minitree *tree_node;
	int	i;

	i = -1;
	tree_node = NULL;
	tree_node = ft_calloc(sizeof(struct s_minitree), 1);
	tree_node->subsh = NULL;
	tree_node->next = NULL;
	tree_node->token = NULL;
	tree_node->exit_status = 0;
	tree_node->fd_output = sh_info->fd_stdout;
	tree_node->fd_input = sh_info->fd_stdin;
	tree_node->env = sh_info->env;
	return(tree_node);
}
