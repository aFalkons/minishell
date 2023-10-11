/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:36:19 by matteo            #+#    #+#             */
/*   Updated: 2023/10/11 18:33:52 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bl_unset(char **env, char **split, t_shell_info *sh_info, int argc)
{
	int		i;
	int		index_egual_sign;
	char	*name;
	char	*value;

	i = 1;
	name = NULL;
	value = NULL;
	if (argc > 1)
	{
		while (split[i])
		{
			index_egual_sign = ft_find_char_index_str(split[i], '=');
			if (index_egual_sign > -1)
			{
				name = ft_substr(split[i], 0, index_egual_sign);
				value = ft_substr(split[i], (index_egual_sign + 1),
						ft_strlen(split[i]));
			}
			else
			{
				name = ft_strdup(split[i]);
				value = NULL;
			}
			if (ft_check_if_variable_name_exists(sh_info, name) == 1
				|| ft_check_if_variable_name_exists(sh_info, name) == 2)
			{
				if (ft_remove_string_from_array(env, name, value) != 1)
					return (-1);
				ft_remove_node_from_list(sh_info->var, name, value);
			}
			if (name)
				free(name);
			if (value)
				free(value);
			i++;
		}
	}
	return (1);
}

int ft_remove_string_from_array(char **env, char *name, char *value)
{
	int i;
	int size_array;
	int index_equal_sign;
	char *name_env;
	char *value_env;
	char *temp;

	i = 0;
	size_array = ft_get_size_array(env);
	index_equal_sign = 0;
	name_env = NULL;
	value_env = NULL;
	temp = NULL;
	while (i < size_array)
	{
		index_equal_sign = ft_find_char_index_str(env[i], '=');
		name_env = ft_substr(env[i], 0, index_equal_sign);
		value_env = ft_substr(env[i], index_equal_sign + 1, ft_strlen(env[i]));
		if ((ft_strcmp(name_env, name) == 0 && value == NULL) ||
			(ft_strcmp(name_env, name) == 0 && value != NULL && ft_strcmp(value_env, value) == 0))
		{
			free(name_env);
			free(value_env);
			while (i < size_array - 1)
			{
				if (env[i + 1])
				{
					free(env[i]);
					temp = env[i + 1];
					env[i] = ft_strdup(temp);
					free(temp);
				}
				else
				{
					free(env[i]);
					env[i] = NULL; // Imposta il puntatore a NULL invece di (char *) '\0'
				}
				i++;
			}
			env[size_array - 1] = NULL; // Imposta il puntatore a NULL invece di (char *) '\0'
			break;
		}
		else if (ft_strcmp(name_env, name) == 0)
		{
			printf("minishell: unset: `%s=%s': not a valid identifier\n", name, value);
			free(name_env);
			free(value_env);
			return (-1);
		}
		i++;
		free(name_env);
		free(value_env);
	}
	return (1);
}

void	ft_free_node(t_node *node)
{
	if (node->full_info)
		free(node->full_info);
	if (node->name)
		free(node->name);
	if (node->value)
		free(node->value);
	if (node)
		free(node);
}

void	ft_remove_node_from_list(t_list_var_env *env, char *name, char *value)
{
	t_node	*temp;
	t_node	*current;
	t_node	*prev;

	if (env->head == NULL)
		return ;
	if (strcmp(env->head->name, name) == 0)
	{
		temp = env->head;
		env->head = env->head->next;
		ft_free_node(temp);
		return ;
	}
	current = env->head;
	prev = NULL;
	while (current != NULL && strcmp(current->name, name) != 0)
	{
		prev = current;
		current = current->next;
	}
	if ((ft_strcmp(current->name, name) == 0 && value == NULL)
		|| (ft_strcmp(current->name, name) == 0
			&& ft_strcmp(current->value, value) == 0))
	{
		prev->next = current->next;
		ft_free_node(current);
	}
	return ;
}
