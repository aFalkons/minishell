/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:35:58 by misidori          #+#    #+#             */
/*   Updated: 2023/08/02 15:55:53 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd_basic(t_builtins *builtins)
{
//	write(1, "pwd_basic\n", 10);
	if (getcwd(builtins->current_directory, sizeof(builtins->current_directory)) == NULL)
	{
		ft_print_message("Error: ", 2);
		strerror(errno);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	ft_pwd(t_shell_info *sh_info, t_builtins *builtins, int j, int argc)
{
//	write(1, "pwd\n", 4);
	if ((ft_strncmp(sh_info->input + j, "pwd", 3) == 0 && argc == 1))
	{
		if (ft_strncmp(sh_info->input + j, "pwd", 3) == 0 && (ft_strlen(sh_info->input) == (j + 3)))
		{
			if (getcwd(builtins->current_directory, sizeof(builtins->current_directory)) != NULL)
			{
				write(1, &builtins->current_directory, ft_strlen(builtins->current_directory));
				write(1, "\n", 1);
			}
			else
			{
				ft_print_message("Error: ", 2);
				strerror(errno);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
		printf("pwd: too many arguments\n");
	return (0);
}
/*
void	ft_cd(t_shell_info *sh_info, t_builtins *builtins)
{
	int	i;

	i = 0;
	if (ft_strncmp(sh_info->input, "cd ..", 5) == 0 && ft_strlen(sh_info->input) == 5)
	{
		ft_pwd(,sh_info, builtins, i);
		i = ft_strlen(builtins->current_directory);
		while (builtins->current_directory[i] != '/')
			i--;
		builtins->current_directory[i] = '\0';
		write(1, &builtins->current_directory, ft_strlen(builtins->current_directory));
		write(1, "\n", 1);
		if (chdir(builtins->current_directory) != 0)
		{
			write(1, "P", 1);
		}

	}
	else if (ft_strncmp(sh_info->input, "cd", 2))
	{

	}
}
*/
#include <dirent.h>

typedef struct s_program
{
	struct dirent	*dir_entry;
	DIR				*dir;
}	t_program;

char **ft_get_list_files(t_program *program)
{
	char	**list;
	int		i;

	list = (char **)malloc(4096 * sizeof(char *));
	if (!list)
		return (NULL);
	i = 0;
	program->dir = opendir(".");
	if (program->dir == NULL)
	{
		perror("opendir");
		return (NULL);
	}
	program->dir_entry = readdir(program->dir);
	while ((program->dir_entry = readdir(program->dir)) != NULL)
	{
		list[i] = strdup(program->dir_entry->d_name);
		i++;
	}
	closedir(program->dir);
	return (list);
}

void	ft_print_array(char **array_strings)
{
	int	i;

	i = 0;
	while (array_strings[i])
	{
		printf("%s\n", array_strings[i]);
		i++;
	}
}

int	ft_ls()
{
	t_program	program;
	char		**list;

	list = ft_get_list_files(&program);
	ft_print_array(list);
	return (0);
}


int	ft_skip_white_spaces(t_shell_info *sh_info, int j)
{
	while (sh_info->input[j])
	{
		if (sh_info->input[j] == ' ')
			j++;
		else
			break ;
	}
	return (j);
}

int ft_cd_relative_path(t_shell_info *sh_info, t_builtins *builtins, int j)
{
	t_program	program;
	char		**list;
	char		*new_directory;
	int			i;
	bool		directory_exists;

	i = 0;
	directory_exists = false;
	list = ft_get_list_files(&program);
	j = ft_skip_white_spaces(sh_info, (j + 2));
	while (list[i])
	{
		if (ft_strncmp(list[i], sh_info->input + j, ft_strlen(sh_info->input + j)) == 0)
		{
			ft_pwd_basic(builtins);
			new_directory = ft_strjoin((char *) builtins->current_directory, "/");
			new_directory = ft_strjoin((char *) new_directory, (sh_info->input + j));
			chdir(new_directory);
			directory_exists = true;
			break ;
		}
		i++;
	}
	if (directory_exists == false)
		printf("cd: no such file or directory: %s\n", sh_info->input + j);
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (0);
}

int ft_cd_absolute_path(t_shell_info *sh_info, int j)
{
	// t_program	program;
	// char		**list;
	// int			i;
	// bool		directory_exists;

	// i = 0;
	// directory_exists = false;
//	list = ft_get_list_files(&program);
	j = ft_skip_white_spaces(sh_info, (j + 2));
//	while (list[i])
//	{
		// if (ft_strncmp(list[i], sh_info->input + j, ft_strlen(sh_info->input + j)) == 0)
		// {
			write(1, "ciao1\n", 6);
//			ft_pwd(builtins);
//			new_directory = ft_strjoin((char *) builtins->current_directory, "/");
//			new_directory = ft_strjoin((char *) new_directory, (sh_info->input + j));
			chdir(sh_info->input + j);
	// 		directory_exists = true;
	// 		break ;
	// 	}
	// 	else
	// 		write(1, "ciao2\n", 6);
	// 	i++;
	// }
	// if (directory_exists == false)
	// 	printf("cd: no such file or directory: %s\n", sh_info->input + j);
	// while (list[i])
	// {
	// 	free(list[i]);
	// 	i++;
	// }
	// free(list);
	return (0);
}

int	ft_builtins_cmd(t_shell_info *sh_info, t_builtins *builtins)
{
	int	j;
	char	**split;

	split = ft_split(sh_info->input, ' ');
	int	i = 0;
	int argc = 0;
	while (split[i])
	{
//		printf("split: %s\n", split[i]);
		i++;
		argc++;
	}
//	printf("quanto é arggc? %d\n", argc);
	j = 0;
	j = ft_skip_white_spaces(sh_info, j);
//	if (ft_strncmp(sh_info->input + j, "pwd", 3) == 0 && (ft_strlen(sh_info->input) == (j + 3)))
	if (ft_strncmp(split[0], "pwd", 3) == 0)
	{
		ft_pwd(sh_info, builtins, j, argc);

	}
//	else
//		printf("pwd: too many arguments\n");
	if (ft_strncmp(sh_info->input + j, "cd /", 4) == 0)
		ft_cd_absolute_path(sh_info, j);
	if (ft_strncmp(sh_info->input + j, "cd ", 3) == 0)
		ft_cd_relative_path(sh_info, builtins, j);
	else if (ft_strncmp(sh_info->input + j, "ls", 2) == 0)
		ft_ls();

	// if (ft_strncmp(sh_info->input, "cd ..", 5) == 0 && ft_strlen(sh_info->input) == 5)
	// 	ft_cd(sh_info, builtins);
	// if (ft_strncmp(sh_info->input, "cd ", 3) == 0)// && ft_strlen(sh_info->input) == 3)
	// 	ft_cd_relative_path(sh_info, builtins);
//	else
//		ft_print_message("minishell: command not found: ", 2);

//	free(sh_info->pwd);
	return (0);
}
