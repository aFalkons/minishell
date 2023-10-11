/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:50:06 by misidori          #+#    #+#             */
/*   Updated: 2023/10/10 16:49:34 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_find_char_index_str(char *str, char c)
{
	int	i;

	i = 0;
	if (!str || !c)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_find_char_array(char **array, char c)
{
	int	i;
	int	j;

	i = 0;
	if (!array || !c)
		return (0);
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == c)
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

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
