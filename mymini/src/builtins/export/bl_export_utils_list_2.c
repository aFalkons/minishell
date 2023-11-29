/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_export_utils_list_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:17:25 by misidori          #+#    #+#             */
/*   Updated: 2023/11/24 00:34:18 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_node	*ft_get_list_head(t_list_var_env *var)
{
	if (var == NULL)
		write(2, "Error\n", 6);
	return (var->node);
}

t_node	*ft_get_list_tail(t_list_var_env *var)
{
	t_node	*current_node;

	if (var == NULL)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	current_node = var->node;
	while (current_node->next != NULL)
		current_node = current_node->next;
	return (current_node);
}

void	ft_swap_nodes(t_node *a, t_node *b)
{
	char	*tmp_name;
	char	*tmp_value;
	char	*tmp_full_info;

	tmp_name = a->name;
	a->name = b->name;
	b->name = tmp_name;
	tmp_value = a->value;
	a->value = b->value;
	b->value = tmp_value;
	tmp_full_info = a->full_info;
	a->full_info = b->full_info;
	b->full_info = tmp_full_info;
}

void	ft_sort_list(t_node **head)
{
	t_node	*current;
	t_node	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		while (next != NULL)
		{
			if (ft_strcmp(current->full_info, next->full_info) > 0)
				ft_swap_nodes(current, next);
			next = next->next;
		}
		current = current->next;
	}
}

void	ft_print_list(t_list_var_env *list)
{
	t_node	*current;

	current = list->node;
	while (current)
	{
		if (current->value)
		{
			printf("declare -x %s=\"%s\"\n", current->name, current->value);
		}
		else
			printf("declare -x %s\n", current->name);
		current = current->next;
	}
}
