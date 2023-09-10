/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:23:15 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/10 19:56:04 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static pid_t	ex_create_pipe(t_minitree *node, t_shell_info *sh_info)
{
	pid_t	pid_fork;

	pid_fork = 1;
	if (pipe(sh_info->fd) == -1)
		node->exit_status = -1;
	sh_info->fd_stdout = dup(1);
	sh_info->pid_flag = 0;
	pid_fork = fork();
	if (pid_fork == 0)
	{
		sh_info->pid_flag = 1;
		close(sh_info->fd[1]);
		dup2(sh_info->fd[0], 1);
	}
	return(pid_fork);
}

static void	ex_real_pipe(t_minitree *node, t_shell_info *sh_info, pid_t pid)
{
	(void)node;
	waitpid(pid, 0, 0);
	if (pid == 0)
		exit(1);
	if (pid != 0)
		sh_info->pid_flag = 1;
	// dup2(sh_info->fd_stdout, 1);
	close(sh_info->fd[0]);
	sh_info->fd_stdin = dup(0);
	dup2(sh_info->fd[1], 0);
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
	pid_t	pid;

	pid = 1;
	// if (node->token)
	// 	printf("%s\n", node->token->next->str);
	// else
	// 	printf("testa\n");
	if (node->flag_pipe == 1)
		pid = ex_create_pipe(node, sh_info);
	else if (node->flag_pipe == 2)
		ex_real_pipe(node, sh_info, pid);
	else if (node->flag_pipe == 3)
		ex_close_pipe(node, sh_info);
}


// void	ex_pipe(t_minitree *node, t_shell_info *sh_info);
// {
// 	int	bozi;

// 	bozi = *(pip->for_pipe);
// 	if(flag == 1)
// 	{
// 		if (pip->fd_input == 1)
// 		{
// 			if (pipe(pip->for_pipe) == -1)
// 			{
// 				pip->exit_inp = 1;
// 				return;
// 			}
// 			close(pip->for_pipe[1]);
// 			if (bozi != 1)
// 			{
// 				pip->fd_copy = dup(1);
// 				dup2(pip->for_pipe[0], 1);
// 			}
// 		}
// 		else
// 		{
// 			close(pip->for_pipe[0]);
// 			pip->fd_copy = dup(0);
// 			dup2(pip->for_pipe[1], 0);
// 		}
// 		return;
// 	}
// 	dup2(pip->fd_copy, pip->fd_input);
// 	close(pip->fd_copy);
// }
