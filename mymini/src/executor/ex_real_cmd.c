/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_real_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:31:11 by afalconi          #+#    #+#             */
/*   Updated: 2023/12/01 22:37:47 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	bl_ck_builtins3(int *exit, char **arr_cmd_arg,
	char **env, t_shell_info *sh_info)
{
	int	n_ac;

	n_ac = 0;
	while (arr_cmd_arg[n_ac] != NULL)
		n_ac ++;
	if (ft_cmp_len_and_str(arr_cmd_arg[0], "pwd", 3) == 1)
	{
		if (bl_pwd() != 1)
			*exit = -1;
		return (1);
	}
	else if (ft_cmp_len_and_str(arr_cmd_arg[0], "cd", 2) == 1)
	{
		if (bl_cd(sh_info, env, arr_cmd_arg) != 1)
			*exit = -1;
		return (1);
	}
	return (0);
}

static int	bl_ck_builtins2(int *exit, char **arr_cmd_arg,
	char **env, t_shell_info *sh_info)
{
	int	n_ac;

	n_ac = 0;
	while (arr_cmd_arg[n_ac] != NULL)
		n_ac ++;
	if (ft_cmp_len_and_str(arr_cmd_arg[0], "exit", 4) == 1)
	{
		if (bl_exit(sh_info, arr_cmd_arg, n_ac, sh_info->last_exit) == -1)
			*exit = -1;
		return (1);
	}
	if (ft_cmp_len_and_str(arr_cmd_arg[0], "env", 3) == 1)
	{
		if (bl_env(env, n_ac, arr_cmd_arg) != 1)
			*exit = -1;
		return (1);
	}
	return (bl_ck_builtins3(exit, arr_cmd_arg, env, sh_info));
}

int	bl_ck_builtins(int *exit, char **arr_cmd_arg,
	char **env, t_shell_info *sh_info)
{
	int	n_ac;

	n_ac = 0;
	while (arr_cmd_arg[n_ac] != NULL)
		n_ac ++;
	if (ft_cmp_len_and_str(arr_cmd_arg[0], "export", 6) == 1)
	{
		if (bl_export(sh_info, env, n_ac, arr_cmd_arg) != 1)
			*exit = -1;
		return (1);
	}
	else if (ft_cmp_len_and_str(arr_cmd_arg[0], "unset", 5) == 1)
	{
		if (bl_unset(sh_info, arr_cmd_arg, n_ac) != 1)
			*exit = -1;
		return (1);
	}
	else if (ft_cmp_len_and_str(arr_cmd_arg[0], "echo", 4) == 1)
	{
		*exit = 1;
		bl_echo(arr_cmd_arg, n_ac);
		return (1);
	}
	return (bl_ck_builtins2(exit, arr_cmd_arg, env, sh_info));
}

void	ex_real_esecution(char *path_cmd, char **arr_cmd_arg,
	struct s_minitree *node, t_shell_info *sh_info)
{
	pid_t	pid;
	int		exit;

	(void)node;
	if (sh_info->pipe_flag == 1)
		execve(path_cmd, arr_cmd_arg, sh_info->env);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			execve(path_cmd, arr_cmd_arg, sh_info->env);
		}
		waitpid(pid, &exit, 0);
		node->exit_status = WSTOPSIG(exit);
		if (node->exit_status > 256)
			node->exit_status = node->exit_status % 256;
	}
}
