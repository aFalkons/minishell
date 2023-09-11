/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:23:15 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/11 18:39:43 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ex_create_pipe(t_minitree *node, t_shell_info *sh_info)
{
	if (pipe(sh_info->fd) == -1)
		node->exit_status = -1;
	sh_info->fd_stdout = dup(1);
	sh_info->pid_flag = 0;
	sh_info->pid = fork();
	if (sh_info->pid == 0)
	{
		sh_info->pid_flag = 1;
		close(sh_info->fd[0]);
		dup2(sh_info->fd[1], 1);
	}
}

static void	ex_real_pipe(t_minitree *node, t_shell_info *sh_info)
{
	(void)node;
	waitpid(-1, 0, 0);
	if (sh_info->pid == 0)
		exit(1);
	if (sh_info->pid != 0)
		sh_info->pid_flag = 1;
	close(sh_info->fd[1]);
	sh_info->fd_stdin = dup(0);
	dup2(sh_info->fd[0], 0);
}

static void	ex_close_pipe(t_minitree *node, t_shell_info *sh_info)
{
	(void)node;
	// (void)sh_info;
	dup2(sh_info->fd_stdin , 0);
	close(sh_info->fd[1]);
}

void	ex_pipe(t_minitree *node, t_shell_info *sh_info)
{
	if (node->flag_pipe == 1)
		ex_create_pipe(node, sh_info);
	else if (node->flag_pipe == 2)
		ex_real_pipe(node, sh_info);
	else if (node->flag_pipe == 3)
		ex_close_pipe(node, sh_info);
}
