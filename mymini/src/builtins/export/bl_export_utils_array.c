/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_export_utils_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:34:02 by misidori          #+#    #+#             */
/*   Updated: 2023/11/29 19:13:52 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_add_element_to_array(t_shell_info *sh_info, char *name, char *value)
{
	char	**new_array;
	char	*temp;
	int		env_count;
	int		i;

	env_count = ft_get_size_array(sh_info->env);
	new_array = (char **) ft_calloc((ft_get_size_array(sh_info->env) + 2)
			* sizeof(char *), 1);
	if (!new_array)
		return ;
	i = -1;
	while (++i < env_count)
		new_array[i] = ft_strdup(sh_info->env[i]);
	ft_free_array(sh_info->env);
	if (value != NULL || (ft_strcmp(value, "") != 0))
	{
		temp = ft_strjoin(name, "=");
		new_array[env_count] = NULL;
		new_array[env_count] = ft_strjoin(temp, value);
		free(temp);
	}
	new_array[env_count + 1] = NULL;
	sh_info->env = new_array;
}

int	ft_index_name_in_env(char **env, char *name)
{
	bool	match;
	int		i;

	match = false;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], name, ft_strlen(name)) == 0
			&& env[i][ft_strlen(name)] == '=')
		{
			match = true;
			break ;
		}
		i++;
	}
	if (match == true)
		return (i);
	else
		return (-1);
}

void	ft_edit_value_in_array(char **env, char *name, char *value)
{
	char	*temp;
	int		i;

	i = ft_index_name_in_env(env, name);
	if (i != -1)
	{
		free(env[i]);
		temp = ft_strdup(name);
		env[i] = ft_strjoin(temp, "=");
		free(temp);
		temp = ft_strdup(env[i]);
		free(env[i]);
		env[i] = ft_strjoin(temp, value);
		free(temp);
	}
	return ;
}

int	ft_attach_string_to_array(char **env, char *name, char *value)
{
	char	*temp;
	int		i;
	int		len;

	len = (ft_get_size_array(env));
	i = -1;
	while (++i < len)
	{
		if (ft_strncmp(name, env[i], ft_strlen(name)) == 0
			&& env[i][ft_strlen(name)] == '=')
		{
			temp = ft_strjoin(env[i], value);
			free(env[i]);
			env[i] = ft_strdup(temp);
			free(temp);
			break ;
		}
	}
	return (1);
}
