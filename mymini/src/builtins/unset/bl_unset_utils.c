/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_unset_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:36:19 by matteo            #+#    #+#             */
/*   Updated: 2023/12/01 19:19:32 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_node_to_remove_is_head(t_list_var_env *env, char *name)
{
	t_node	*temp;

	if (ft_strcmp(env->head->name, name) == 0)
	{
		temp = env->node->next;
		ft_free_node(env->node);
		env->node = temp;
		return (1);
	}
	return (-1);
}

void	ft_free_node(t_node *node)
{
	if (node->full_info != NULL)
		free(node->full_info);
	if (node->name != NULL)
		free(node->name);
	if (node->value != NULL)
		free(node->value);
	if (node != NULL)
		free(node);
}
