/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_real_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:31:11 by afalconi          #+#    #+#             */
/*   Updated: 2023/10/11 19:04:30 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	bl_ck_builtins2(int *exit, char **arr_cmd_arg, char **env, int n_ac)
{
	if (ft_strncmp(arr_cmd_arg[0], "env", 3) == 0 && ft_strlen(arr_cmd_arg[0]) == 3)
	{
		if (bl_env(env, n_ac, arr_cmd_arg) != 1)
			*exit = -1;
		return(1);
	}
	else if (ft_strncmp(arr_cmd_arg[0], "exit", 4) == 0 && ft_strlen(arr_cmd_arg[0]) == 4)
		bl_exit(arr_cmd_arg, n_ac);
	if(ft_strncmp(arr_cmd_arg[0], "pwd", 3) == 0 && ft_strlen(arr_cmd_arg[0]) == 3)
	{
		if (bl_pwd() != 1)
			*exit = -1;
		return(1);
	}
	else if (ft_strncmp(arr_cmd_arg[0], "cd", 2) == 0 && ft_strlen(arr_cmd_arg[0]) == 2)
	{
		if (bl_cd(env, arr_cmd_arg) != 1)
			*exit = -1;
		return(1);
	}
	return(0);
}

int	bl_ck_builtins(int *exit, char **arr_cmd_arg, char **env, t_shell_info *sh_info)
{
	int	n_ac;

	n_ac = 0;
	while(arr_cmd_arg[n_ac] != NULL)
		n_ac ++;
	if (ft_strncmp(arr_cmd_arg[0], "export", 6) == 0 && ft_strlen(arr_cmd_arg[0]) == 6)
	{
		if (bl_export(sh_info, env, n_ac, arr_cmd_arg) != 1)
			*exit = -1;
		return(1);
	}
	else if (ft_strncmp(arr_cmd_arg[0], "unset", 5) == 0 && ft_strlen(arr_cmd_arg[0]) == 5)
	{
		if (bl_unset(env, arr_cmd_arg, sh_info, n_ac) != 1)
			*exit = -1;
		return(1);
	}
	else if (ft_strncmp(arr_cmd_arg[0], "echo", 4) == 0 && ft_strlen(arr_cmd_arg[0]) == 4)
	{
		bl_echo(arr_cmd_arg, n_ac);
		*exit = 1;
		return(1);
	}
	return(bl_ck_builtins2(exit, arr_cmd_arg, env, n_ac));
}

void	ex_real_esecution(char *path_cmd, char **arr_cmd_arg,  struct s_minitree *node, t_shell_info *sh_info)
{
	pid_t	pid;

	if (sh_info->pipe_flag == 1)
		execve(path_cmd, arr_cmd_arg, node->env);
	else
	{
		pid = fork();
		if (pid == 0)
			execve(path_cmd, arr_cmd_arg, node->env);
		waitpid(pid, 0, 0);
	}
}
