/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_handler_HDOC.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:22:15 by afalconi          #+#    #+#             */
/*   Updated: 2023/10/22 15:23:48 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void test2()
{
	ft_for_debug("bo fra non so che scrivere\n");
}

//void ps_hdoc_handler_signal()
//{
//}

static void ps_hdoc_insert(t_list_redirection *hdoc, int *fd)
{
	char	*str;

	str = NULL;
	while(1)
	{
		str = readline(">");
		if (ft_strncmp(str, hdoc->file, ft_strlen(hdoc->file)) == 0)
			break;
		write(fd[1], str, ft_strlen(str));
		write(fd[1], "\n", 1);
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
	if (pipe(fd) == -1)
		return(-1);
	pid = fork();
	if (pid == 0)
	{
		//signal(SIGINT, &test2);
		//ps_hdoc_handler_signal();
		close(fd[0]);
		ps_hdoc_insert(hdoc, fd);
	}
	waitpid(pid, 0, 0);
	if (pid == 0)
		exit(1);
	hdoc->fd_of_file = dup(fd[0]);
	close(fd[1]);
	close(fd[0]);
	return(1);
}
