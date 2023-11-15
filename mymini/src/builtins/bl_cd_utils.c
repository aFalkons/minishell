/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:45:16 by misidori          #+#    #+#             */
/*   Updated: 2023/11/15 20:12:05 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**ft_get_list_files(t_program *program)
{
	char	**list;
	int		i;

	list = NULL;
	list = (char **) ft_calloc(4096 * sizeof(char *), 1);
	if (!list)
		return (NULL);
	i = 0;
	program->dir = opendir(".");
	if (program->dir == NULL)
	{
		perror("opendir");
		return (NULL);
	}
	while ((program->dir_entry = readdir(program->dir)) != NULL)
	{
		list[i] = ft_strdup(program->dir_entry->d_name);
		i++;
	}
	closedir(program->dir);
	return (list);
}

char	*ft_get_home(char **env)
{
	char	*home_dir;
	int		i;

	home_dir = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp("HOME=", env[i], 5) == 0)
		{
			home_dir = ft_substr(env[i], 5, ft_strlen(env[i]) - 5);
			break ;
		}
		i++;
	}
	return (home_dir);
}

char *ft_get_destination_folder(char *current_folder, int count_slash, char **folders, char *arg)
{
	char	*new_folder;
	char	*temp;
	int		i;

	i = 0;
	new_folder = ft_strjoin(current_folder, "/");
	if (arg[ft_strlen(arg) - 1] == '/')
		count_slash--;
	while (i <= count_slash)
	{
		temp = new_folder;
		new_folder = ft_strjoin(temp, folders[i]);
		free(temp);
		temp = new_folder;
		new_folder = ft_strjoin(temp, "/");
		free(temp);
		i++;
	}
	if (new_folder[ft_strlen(new_folder) - 1] == '/')
		new_folder[ft_strlen(new_folder) - 1] = '\0';
	return (new_folder);
}


int	ft_change_folder(char *new_folder, char **split)
{
	if (chdir(new_folder) != 0)
	{
		printf("minishell: cd: %s: %s\n", split[1], strerror(errno));
		return (-1);
	}
	else
		return (1);
}
