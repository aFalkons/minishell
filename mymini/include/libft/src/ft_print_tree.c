/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:49:08 by afalconi          #+#    #+#             */
/*   Updated: 2023/11/09 18:21:41 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	pummalo2(t_minitree *tree_node)
{
	t_list_redirection	*tmp;

	tmp = 0;
	printf("close\n");
	tmp = tree_node->close_redire;
	while (tmp)
	{
		printf("<>%d\n", tmp->fd_input);
		printf("<>%s\n", tmp->file);
		printf("<>%c\n", tmp->token);
		tmp = tmp->next;
	}
}

static void	pummalo(t_minitree *tree_node, int i)
{
	t_list_redirection	*tmp;

	tmp = 0;
	printf("%d", i);
	printf("!!---!!        %s\n", tree_node->token->str);
	printf("||-----%d\n", tree_node->flag_pipe);
	if (tree_node->redire)
	{
		printf("open\n");
		tmp = tree_node->redire;
		while (tmp)
		{
			printf("><%d\n", tmp->fd_input);
			printf("><%s\n", tmp->file);
			printf("><%c\n", tmp->token);
			tmp = tmp->next;
		}
	}
	if (tree_node->close_redire)
		pummalo2(tree_node);
}

void	print_tree(t_minitree *tree_node, t_minitree *tree_node_h, int i)
{
	t_list_redirection	*tmp;

	tmp = 0;
	if (tree_node->next)
		print_tree(tree_node->next, tree_node_h, i);
	if (tree_node->subsh)
		print_tree(tree_node->subsh, tree_node_h, i + 1);
	if (tree_node == tree_node_h)
	{
		printf("testa\n");
		printf("||%d\n", tree_node->flag_pipe);
		if (tree_node->close_redire)
		{
			tmp = tree_node->close_redire;
			while (tmp)
			{
				printf("<>%s\n", tmp->file);
				printf("<>%d\n", tmp->fd_input);
				printf("<>%c\n", tmp->token);
				tmp = tmp->next;
			}
		}
	}
	if (tree_node != tree_node_h)
		pummalo(tree_node, i);
}
