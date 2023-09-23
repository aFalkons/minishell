/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_real_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:31:11 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/23 15:31:46 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ex_real_esecution(char *path_cmd, char **arr_cmd_arg,  struct s_minitree *node, t_shell_info *sh_info)
{
	pid_t	pid;

	write(2, &sh_info->pipe_flag, 1);
	if (sh_info->pipe_flag == 1)
		execve(path_cmd, arr_cmd_arg, node->env);
	pid = fork();
	if (pid == 0)
		execve(path_cmd, arr_cmd_arg, node->env);
	waitpid(pid, 0, 0);
}
