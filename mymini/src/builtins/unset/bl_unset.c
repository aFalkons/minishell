/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:36:19 by matteo            #+#    #+#             */
/*   Updated: 2023/12/01 20:43:43 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bl_unset(t_shell_info *sh_info, char **arr_cmd_arg, int argc)
{
	int		i;

	i = 1;
	if (argc > 1)
	{
		while (arr_cmd_arg[i])
		{
			if (ft_unset(sh_info, arr_cmd_arg, i) != 1)
				return (-1);
			i++;
		}
	}
	return (1);
}

int	ft_unset(t_shell_info *sh_info, char **arr_cmd_arg, int i)
{
	int		index_egual_sign;

	index_egual_sign = ft_find_char_index_str(arr_cmd_arg[i], '=');
	ft_remove_char_in_str(arr_cmd_arg[i], '\"');
	ft_remove_char_in_str(arr_cmd_arg[i], '\'');
	if (index_egual_sign > -1)
	{
		printf("minishell: unset: `%s': not a valid identifier\n",
			arr_cmd_arg[i]);
		return (-1);
	}
	if (ft_check_if_variable_name_exists(sh_info, arr_cmd_arg[i]) != -1)
	{
		if (ft_check_if_variable_name_exists(sh_info, arr_cmd_arg[i]) == 2)
			ft_remove_node_from_list(sh_info->var, arr_cmd_arg[i]);
		else
		{
			if (ft_remove_string_from_array(sh_info, arr_cmd_arg[i]) == -1)
				return (-1);
			ft_remove_node_from_list(sh_info->var, arr_cmd_arg[i]);
		}
	}
	return (1);
}

int	ft_remove_string_from_array(t_shell_info *sh_info, char *name)
{
	char	**temp_env;
	int		index_equal_sign;
	int		i;
	int		j;

	temp_env = (char **) ft_calloc(ft_get_size_array(sh_info->env),
			sizeof(char *));
	index_equal_sign = 0;
	i = -1;
	j = 0;
	while (++i < ft_get_size_array(sh_info->env))
	{
		index_equal_sign = ft_find_char_index_str(sh_info->env[i], '=');
		if (!((ft_strncmp(sh_info->env[i], name, ft_strlen(name)) == 0)
				&& (sh_info->env[i][index_equal_sign] == '=')))
		{
			temp_env[j] = ft_strdup(sh_info->env[i]);
			j++;
		}
	}
	ft_free_array(sh_info->env);
	sh_info->env = temp_env;
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
