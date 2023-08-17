/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:49:08 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/17 16:15:32 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	print_tree(t_minitree *tree_node, t_minitree *tree_node_h)
{
	if (tree_node->next)
		print_tree(tree_node->next, tree_node_h);
	if (tree_node->subsh)
		print_tree(tree_node->subsh, tree_node_h);
	if (tree_node != tree_node_h)
	{
		printf("!!---!!        %s\n", tree_node->token->str);
		// printf("-<>-%d\n", tree_node->fd_output);
		// printf("-><-%d\n", tree_node->fd_input);
	}
}
