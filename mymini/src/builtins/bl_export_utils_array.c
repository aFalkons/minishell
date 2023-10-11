/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_export_utils_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:34:02 by misidori          #+#    #+#             */
/*   Updated: 2023/10/11 18:58:59 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_add_element_to_array(char **env, char *name, char *value)
{
	char	**env_array;
	char	*temp;
	int		env_count;

	env_array = env;
	env_count = 0;
	while (*env_array)
	{
		if (ft_strncmp(name, *env_array, ft_strlen(name)) == 0
			&& name[ft_strlen(name) == '='])
			return ;
		env_count++;
		env_array++;
	}
	temp = ft_strdup(name);
	env[env_count] = ft_strjoin(temp, "=");
	free(temp);
	if (value != NULL || (ft_strcmp(value, "") != 0))
	{
		temp = ft_strdup(env[env_count]);
		free(env[env_count]);
		env[env_count] = ft_strjoin(temp, value);
		free(temp);
	}
	env[env_count + 1] = NULL;
}

void	ft_edit_value_in_array(t_shell_info *sh_info, char **env,
	char *name, char *value)
{
	t_node	*current;
	int		i;
	char	*temp;

	current = ft_get_list_head(sh_info->var);
	i = 0;
	while (ft_strncmp(current->name, name, ft_strlen(name)) != 0
		&& current->next != NULL)
	{
		current = current->next;
		i++;
	}
	if (ft_strncmp(name, current->name, ft_strlen(name)) == 0
		&& ft_strlen(name) == ft_strlen(current->name))
	{
		env[i] = ft_strdup(name);
		temp = env[i];
		env[i] = ft_strjoin(temp, "=");
		free(temp);
		temp = env[i];
		env[i] = ft_strjoin(temp, value);
		free(temp);
	}
	return ;
}

int	ft_attach_string_to_array(char **env, char *name, char *value)
{
	int		i;
	int		len;

	len = (ft_get_size_array(env));
	i = -1;
	while (++i < len)
	{
		if (ft_strncmp(name, env[i], ft_strlen(name)) == 0
			&& env[i][ft_strlen(name)] == '=')
		{
			env[i] = ft_strjoin(env[i], value);
			break ;
		}
	}
	return (1);
}
