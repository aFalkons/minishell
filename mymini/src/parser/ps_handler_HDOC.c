/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_handler_HDOC.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:22:15 by afalconi          #+#    #+#             */
/*   Updated: 2023/10/26 19:00:59 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void ps_hdoc_handler_signal(int sig)
{
	(void)sig;
	exit(1);
}

static void ps_hdoc_insert(t_list_redirection *hdoc, int *fd)
{
	char	*str;

	str = NULL;
	while(1)
	{
		str = readline(">");
		if (!str || ft_strncmp(str, hdoc->file, ft_strlen(hdoc->file)) == 0)
			break;
		write(fd[1], str, ft_strlen(str));
		write(fd[1], "\n", 1);
	}
	if (!str)
	{
		ft_putstr_fd("\033[93m", 1);
		ft_putstr_fd(" minishell : warning: here-document delimited by end-of-file (wanted '", 1);
		ft_putstr_fd(hdoc->file, 1);
		ft_putstr_fd("')", 1);
		ft_putstr_fd("\n\e[0m", 1);
	}
}

// static void ps_join_and_free(char **intput, char *c)
// {
// 	char	*tmp;
//
// 	tmp = NULL;
// 	tmp = ft_strdup(*intput);
// 	free(*intput);
// 	*intput = ft_strjoin(tmp, *(&c));
// 	free(tmp);
// }
//
// static void	ps_update_input(t_list_redirection *hdoc, t_shell_info *sh_info)
// {
// 	int		to_add;
// 	char	read_buff;
// 	char	*tmp_input;
// 	char	*tmp;
// 	int		condition;
//
// 	condition = 1;
// 	to_add = dup(hdoc->fd_hdoc[0]);
// 	read_buff = 1;
// 	tmp = NULL;
// 	tmp_input = ft_strdup("\n");
// 	while(condition)
// 	{
// 		condition = read(to_add, &read_buff, 1);
// 		if (read_buff > 12)
// 			ps_join_and_free(&tmp_input, &read_buff);
// 	}
// 	ps_join_and_free(&tmp_input, "\0");
// 	ps_join_and_free(&sh_info->input, tmp_input);
// 	free(tmp_input);
// 	close(to_add);
// }

int	ps_handler_HDOC(t_list_redirection *hdoc, t_shell_info *sh_info)
{
	pid_t		pid;
	int			fd[2];

	(void)sh_info;
	sh_info->flag_hdoc_sig = 0;
	if (pipe(fd) == -1)
		return(-1);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, &ps_hdoc_handler_signal);
		//ps_hdoc_handler_signal();
		close(fd[0]);
		ps_hdoc_insert(hdoc, fd);
		sh_info->flag_hdoc_sig = 1;
	}
	waitpid(pid, 0, 0);
	if (pid == 0 && sh_info->flag_hdoc_sig == 1)
		exit(1);
	hdoc->fd_of_file = dup(fd[0]);
	close(fd[1]);
	close(fd[0]);
	if (sh_info->flag_hdoc_sig == 0)
	{
		close(hdoc->fd_of_file);
		return(-1);
	}
	return(1);
}
