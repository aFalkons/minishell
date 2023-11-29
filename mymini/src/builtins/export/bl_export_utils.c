/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:50:06 by misidori          #+#    #+#             */
/*   Updated: 2023/11/29 14:39:55 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_check_exclamation_mark(char **split)
{
	int	exclamation_mark_index;

	exclamation_mark_index = ft_find_char_array(split, '!');
	if (exclamation_mark_index != -1)
	{
		printf("minishell: %s: event not found\n",
			ft_strchr(split[exclamation_mark_index], '!'));
		return (-1);
	}
	return (1);
}

int	ft_check_if_variable_name_exists(t_shell_info *sh_info, char *name)
{
	t_node	*current;
	int		return_value;

	return_value = -1;
	current = ft_get_list_head(sh_info->var);
	while (current)
	{
		if (ft_strcmp(current->name, name) == 0 && current->value)
		{
			return_value = 1;
			break ;
		}
		else if (ft_strcmp(current->name, name) == 0 && !current->value)
		{
			return_value = 2;
			break ;
		}
		current = current->next;
	}
	return (return_value);
}

bool	ft_check_name_is_correct(char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if ((name[i] >= 'a' && name[i] <= 'z')
			|| (name[i] >= 'A' && name[i] <= 'Z')
			|| (name[i] >= '0' && name[i] <= '9') || (name[i] == '_'))
		{
			i++;
		}
		else
		{
			return (false);
		}
	}
	return (true);
}

int	ft_check_name(t_export_var *exp_var, char *arg)
{
	exp_var->return_value = 1;
	if (ft_check_name_is_correct(exp_var->name) == false
		|| ft_isdigit(exp_var->name[0]) == true)
	{
		printf("minishell: export: `%s': not a valid identifier\n", arg);
		exp_var->return_value = -1;
	}
	return (exp_var->return_value);
}
