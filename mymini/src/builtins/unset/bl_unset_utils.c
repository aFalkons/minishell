/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_unset_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:36:19 by matteo            #+#    #+#             */
/*   Updated: 2023/11/29 13:58:02 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_resize_array(char **env, int size_array, int i)
{
	while (i < size_array - 1)
	{
		if (env[i + 1])
			env[i] = ft_strdup(env[i + 1]);
		else
			env[i] = NULL;
		i++;
	}
	env[size_array - 1] = NULL;
}

int	ft_node_to_remove_is_head(t_list_var_env *env, char *name)
{
	t_node	*temp;

	if (ft_strcmp(env->head->name, name) == 0)
	{
		temp = env->head;
		env->head = env->head->next;
		ft_free_node(temp);
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
