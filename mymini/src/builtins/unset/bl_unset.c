/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:36:19 by matteo            #+#    #+#             */
/*   Updated: 2023/11/29 20:05:04 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bl_unset(char **env, char **split, t_shell_info *sh_info, int argc)
{
	int		i;

	i = 1;
	if (argc > 1)
	{
		while (split[i])
		{
			if (ft_unset(sh_info, split, env, i) != 1)
				return (-1);
			i++;
		}
	}
	return (1);
}

int	ft_unset(t_shell_info *sh_info, char **split, char **env, int i)
{
	int		index_egual_sign;

	index_egual_sign = ft_find_char_index_str(split[i], '=');
	ft_remove_char_in_str(split[i], '\"');
	ft_remove_char_in_str(split[i], '\'');
	if (index_egual_sign > -1)
	{
		printf("minishell: unset: `%s': not a valid identifier\n", split[i]);
		return (-1);
	}
	if (ft_check_if_variable_name_exists(sh_info, split[i]) != -1)
	{
		if (ft_remove_string_from_array(env, split[i]) != 1)
		{
			return (-1);
		}
		ft_remove_node_from_list(sh_info->var, split[i]);
	}
	return (1);
}

int	ft_remove_string_from_array(char **env, char *name)
{
	int		index_equal_sign;
	int		size_array;
	int		i;

	index_equal_sign = 0;
	size_array = ft_get_size_array(env);
	i = 0;
	while (i < size_array)
	{
		index_equal_sign = ft_find_char_index_str(env[i], '=');
		if ((ft_strncmp(env[i], name, ft_strlen(name) == 0))
				&& (env[i][index_equal_sign] == '='))
		{
			ft_resize_array(env, size_array, i);
			break ;
		}
		i++;
	}
	return (1);
}

void	ft_remove_node_from_list(t_list_var_env *env, char *name)
{
	t_node	*current;
	t_node	*prev;

	if (env->head == NULL)
		return ;
	if (ft_node_to_remove_is_head(env, name) == 1)
		return ;
	current = env->head;
	prev = NULL;
	while (current != NULL && ft_strcmp(current->name, name) != 0)
	{
		prev = current;
		current = current->next;
	}
	if (ft_strcmp(current->name, name) == 0)
	{
		prev->next = current->next;
		ft_free_node(current);
	}
	return ;
}
