/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:49:08 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/09 19:52:07 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	print_tree(t_minitree *tree_node, t_minitree *tree_node_h, int i)
{
	t_list_redirection *tmp;

	tmp = 0;
	if (tree_node->next)
		print_tree(tree_node->next, tree_node_h, i);
	if (tree_node->subsh)
		print_tree(tree_node->subsh, tree_node_h, i + 1);
	if (tree_node == tree_node_h)
	{
		if (tree_node->close_redire)
		{
			printf("testa\n");
			tmp = tree_node->close_redire;
			while(tmp)
			{
				if (tmp->token == '|')
					printf("%p\n", tmp->for_pipe);
				else
					printf("<>%s\n", tmp->file);
				printf("<>%d\n", tmp->fd_input);
				printf("<>%c\n", tmp->token);
				tmp = tmp->next;
			}
		}
	}
	if (tree_node != tree_node_h)
	{
		printf("%d", i);
		printf("!!---!!        %s\n", tree_node->token->str);
		if (tree_node->redire)
		{
			printf("open\n");
			tmp = tree_node->redire;
			while(tmp)
			{
				printf("><%d\n", tmp->fd_input);
				if (tmp->token == '|')
					printf("%p\n", tmp->for_pipe);
				else
					printf("<>%s\n", tmp->file);
				printf("><%c\n", tmp->token);
				tmp = tmp->next;
			}
		}
		if (tree_node->close_redire)
		{
			printf("close\n");
			tmp = tree_node->close_redire;
			while(tmp)
			{
				printf("<>%d\n", tmp->fd_input);
				if (tmp->token == '|')
					printf("%p\n", tmp->for_pipe);
				else
					printf("<>%s\n", tmp->file);
				printf("<>%c\n", tmp->token);
				tmp = tmp->next;
			}
		}
	}
}
