/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_export_utils_list_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:43:37 by misidori          #+#    #+#             */
/*   Updated: 2023/10/10 17:28:11 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_add_or_update_node_in_list(t_node **head, char *name, char *value)
{
	if (ft_update_existing_node(head, name, value) == true)
		return ;
	else
		ft_add_node_in_list(head, name, value);
}

bool	ft_update_existing_node(t_node **head, char *name, char *value)
{
	t_node	*current;

	current = *head;
	while (current)
	{
		if (ft_strcmp(current->name, name) == 0)
		{
			if (value && current->value)
				ft_name_exists_so_update_value(current, name, value);
			else if (!value && current->value)
				;
			else if (value && !current->value)
				ft_name_exists_add_value(current, name, value);
			else if (!value && name[ft_strlen(name) - 1] == '=')
				ft_name_exists_no_value(current, name);
			return (true);
		}
		current = current->next;
	}
	return (false);
}

void	ft_add_node_in_list(t_node **head, char *name, char *value)
{
	t_node	*current;
	t_node	*new_node;

	current = *head;
	new_node = (t_node *) malloc(sizeof(t_node));
	new_node->name = ft_strdup(name);
	if (value)
		ft_name_doesnt_exists_add_new_node(new_node, name, value);
	else if (!value && name[ft_strlen(name) - 1] == '=')
		ft_name_and_value_dont_exist_add_name(new_node, name);
	else
		ft_value_doesnt_exists(new_node, name);
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
		ft_add_new_node_at_the_end_of_list(head, current, new_node);
}

int	ft_add_arg_without_egual_sign(t_shell_info *sh_info, char *arg)
{
	int	return_value;

	return_value = 1;
	if (ft_isalnum_str(arg) == true && ft_isdigit(arg[0]) == false)
	{
		ft_add_or_update_node_in_list(&sh_info->var->node, arg, NULL);
	}
	else
	{
		printf("minishell: export: `%s': not a valid identifier\n", arg);
		return_value = -1;
	}
	return (return_value);
}

int	ft_attach_string_to_list(t_shell_info *sh_info, char *name, char *value)
{
	t_node	*head;
	int		i;

	head = ft_get_list_head(sh_info->var);
	i = 0;
	while (ft_strncmp(sh_info->var->node->name, name, ft_strlen(name)) != 0
		&& sh_info->var->node->next != NULL)
	{
		sh_info->var->node = sh_info->var->node->next;
		i++;
	}
	if (ft_strncmp(name, sh_info->var->node->name, ft_strlen(name)) == 0
		&& ft_strlen(name) == ft_strlen(sh_info->var->node->name))
	{
		sh_info->var->node->value = ft_strjoin
			(sh_info->var->node->value, value);
	}
	sh_info->var->node = head;
	return (1);
}
