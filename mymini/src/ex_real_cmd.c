/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_real_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:31:11 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/17 20:30:04 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void ex_esecution_cmd(char *path_cmd, char **arr_cmd_arg,  struct s_minitree *node, int *fd)
{
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	(void)fd;
	execve(path_cmd, arr_cmd_arg, node->env);
}

void	ex_real_esecution(char *path_cmd, char **arr_cmd_arg,  struct s_minitree *node)
{
	int		fd[2];
	pid_t	pid;
	// int i = -1;

	if (pipe(fd) == -1)
		printf("tumadrepopotro\n");
	// printf("%s\n", path_cmd);
	// while(arr_cmd_arg[++i])
	// 	printf("%s\n", arr_cmd_arg[i]);
	pid = fork();
	if (pid == 0)
		ex_esecution_cmd(path_cmd, arr_cmd_arg, node, fd);
	dup2(node->fd_output, fd[0]);
	usleep(30);
}
