/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:13:01 by misidori          #+#    #+#             */
/*   Updated: 2023/11/29 12:20:40 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd_with_no_arg(char **env, char **split)
{
	char	*home_dir;

	home_dir = ft_get_home(env);
	if (ft_change_folder(home_dir, split) != 1)
	{
		free(home_dir);
		return (-1);
	}
	free(home_dir);
	return (1);
}

int	bl_cd(t_shell_info *sh_info, char **env, char **split)
{
	char	current_directory[PATH_MAX];

	if (getcwd(current_directory, PATH_MAX) == NULL)
		return (-1);
	if (ft_get_size_array(split) > 2)
	{
		printf("minishell: cd: too many arguments\n");
		return (-1);
	}
	if (ft_cd_check_quotes(split[1]) == -1)
	{
		printf("minishell: %s: No such file or directory\n", split[1]);
		return (-1);
	}
	if (!split[1])
	{
		if (ft_cd_with_no_arg(env, split) != 1)
			return (-1);
	}
	else
		if (ft_change_folder(split[1], split) != 1)
			return (-1);
	ft_set_pwd_and_oldpwd(sh_info, env, current_directory);
	return (1);
}

void	ft_set_pwd_and_oldpwd(t_shell_info *sh_info, char **env,
	char *current_directory)
{
	ft_set_oldpwd(sh_info, env, current_directory);
	if (getcwd(current_directory, PATH_MAX) == NULL)
	{
		return ;
	}
	ft_set_pwd(sh_info, env, current_directory);
}

void	ft_set_oldpwd(t_shell_info *sh_info, char **env, char *old_directory)
{
	char	**old_pwd;

	old_pwd = (char **) ft_calloc(3, sizeof(char *));
	old_pwd[0] = "export\0";
	old_pwd[1] = ft_strjoin("OLDPWD=", old_directory);
	old_pwd[2] = NULL;
	bl_export(sh_info, env, 2, old_pwd);
	free(old_pwd[1]);
	free(old_pwd);
}

void	ft_set_pwd(t_shell_info *sh_info, char **env, char *new_directory)
{
	char	**new_pwd;

	new_pwd = (char **) ft_calloc(3, sizeof(char *));
	new_pwd[0] = "export\0";
	new_pwd[1] = ft_strjoin("PWD=", new_directory);
	new_pwd[2] = NULL;
	bl_export(sh_info, env, 2, new_pwd);
	free(new_pwd[1]);
	free(new_pwd);
}
