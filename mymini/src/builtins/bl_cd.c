/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:13:01 by misidori          #+#    #+#             */
/*   Updated: 2023/10/11 16:37:45 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bl_cd(char **env, char **split)
{
	char	*home_dir;

	home_dir = NULL;
	if (ft_get_size_array(split) > 2)
	{
		printf("minishell: cd: too many arguments\n");
		return (-1);
	}
	if (!split[1])
	{
		home_dir = ft_get_home(env);
		if (ft_change_folder(home_dir, split) != 1)
		{
			free(home_dir);
			return (-1);
		}
		free(home_dir);
		return (1);
	}
	if (split[1][0] == '/')
	{
		if (ft_cd_absolute_path(split) != 1)
			return (-1);
	}
	else if (split[1][0] != '/')
	{
		if (ft_cd_relative_path(split) != 1)
			return (-1);
	}
	else
		return (-1);
	return (1);
}

int	ft_cd_absolute_path(char **split)
{
	if (chdir(split[1]) == 0)
	{
		return (1);
	}
	else
	{
		printf("minishell: cd: %s: %s\n", split[1], strerror(errno));
		return (-1);
	}
}

int	ft_cd_relative_path(char **split)
{
	t_program	program;
	char		**list_of_files;
	int			count_slash;

	list_of_files = ft_get_list_files(&program);
	count_slash = ft_count_char(split[1], '/');
	if (count_slash > 0)
	{
		if (ft_deep_path(split, list_of_files, count_slash) != 1)
		{
			ft_free_array(list_of_files);
			return (-1);
		}
	}
	else
	{
		if (ft_enter_in_folder(split, list_of_files) != 1)
		{
			ft_free_array(list_of_files);
			return (-1);
		}
	}
	ft_free_array(list_of_files);
	return (1);
}

int	ft_deep_path(char **split, char **list_of_files, int count_slash)
{
	char	**folders;
	char	*new_folder;
	char	current_folder[PATH_MAX];
	int		i;
	int		j;
	int		flag;

	folders = ft_split(split[1], '/');
	i = 0;
	j = 0;
	flag = 0;
	while (list_of_files[i])
	{
		j = 0;
		while (folders[j])
		{
			if (ft_strncmp(list_of_files[i], folders[j], ft_strlen(folders[j])) == 0
				&& ft_strlen(list_of_files[i]) == ft_strlen(folders[j]))
			{
				if (getcwd(current_folder, PATH_MAX) == NULL)
				{
					ft_free_array(folders);
					return (-1);
				}
				new_folder = ft_get_destination_folder(current_folder,
						count_slash, folders, split[1]);
				if (ft_change_folder(new_folder, split) != 1)
				{
					free(new_folder);
					ft_free_array(folders);
					return (-1);
				}
				else
					flag=1;
				if (new_folder)
					free(new_folder);
				break ;
			}
			j++;
		}
		if (flag==1)
			break ;
		i++;
	}
	ft_free_array(folders);
	return (1);
}

int	ft_enter_in_folder(char **split, char **list_of_files)
{
	char	current_folder[PATH_MAX];
	char	*new_folder;
	char	*temp;
	int		i;
	int		flag;

	i = -1;
	flag = 0;
	new_folder = NULL;
	temp = NULL;
	while (list_of_files[++i])
	{
		if (ft_strncmp(list_of_files[i], split[1], ft_strlen(split[1])) == 0
			&& ft_strlen(list_of_files[i]) == ft_strlen(split[1]))
		{
			if (getcwd(current_folder, PATH_MAX) == NULL)
			{
				return (-1);
			}
			new_folder = ft_strjoin(current_folder, "/");
			temp = new_folder;
			free(new_folder);
			new_folder = ft_strjoin(temp, (split[1]));
			flag = 1;
			if (ft_change_folder(new_folder, split) != 1)
			{
				free(new_folder);
				return (-1);
			}
			free(new_folder);
			break ;
		}
	}
	if (flag == 0)
	{
		printf("minishell: cd: %s: No such file or directory\n", split[1]);
		return (-1);
	}
	return (1);
}
