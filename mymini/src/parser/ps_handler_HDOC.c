/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_handler_HDOC.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:22:15 by afalconi          #+#    #+#             */
/*   Updated: 2023/10/27 18:50:19 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


//void ps_hdoc_handler_signal(int sig)
//{
//	(void)sig;
//	exit(1);
//}

static char *ps_hdoc_insert(t_list_redirection *hdoc, int *fd)
{
	char	*str;
	char	*fin;
	char	*tmp;

	fin = NULL;
	str = NULL;
	while(1)
	{
		str = readline(">");
		if (!str || ft_strncmp(str, hdoc->file, ft_strlen(hdoc->file)) == 0)
			break;
		if (!fin)
			fin = ft_strdup(str);
		else
		{
			tmp = ft_strdup(fin);
			free(fin);
			fin = ft_strjoin(tmp, str);
			free(tmp);
		}
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
	return(fin);
}

//static void ps_join_and_free(char **intput, char *c)
//{
//	char	*tmp;
//	tmp = NULL;
//	tmp = ft_strdup(*intput);
//	free(*intput);
//	*intput = ft_strjoin(tmp, *(&c));
//	free(tmp);
//}
//
//static void	ps_update_input(t_list_redirection *hdoc, t_shell_info *sh_info)
//{
//	int		to_add;
//	char	read_buff;
//	char	*tmp_input;
//	int		condition;
//
//	condition = 1;
//	to_add = dup(hdoc->fd_of_file);
//	read_buff = 1;
//	tmp_input = ft_strdup("\n");
//	while(condition)
//	{
//		condition = read(to_add, &read_buff, 1);
//		if ((read_buff >= 'a' && read_buff <= 'z') || (read_buff >= 'A' && read_buff <= 'Z') || read_buff == '\n')
//			ps_join_and_free(&tmp_input, &read_buff);
//	}
//	ps_join_and_free(&tmp_input, "\0");
//	ps_join_and_free(&sh_info->input, tmp_input);
//	free(tmp_input);
//	close(to_add);
//}

int	ps_handler_HDOC(t_list_redirection *hdoc, t_shell_info *sh_info)
{
	pid_t		pid;
	int			fd[2];
	char		*tmp;

	(void)sh_info;
	if (pipe(fd) == -1)
		return(-1);
	pid = fork();
	if (pid == 0)
	{
		//signal(SIGINT, &ps_hdoc_handler_signal);
		close(fd[0]);
		//ps_hdoc_insert(hdoc, fd);
		tmp = ft_strdup(sh_info->input);
		free(sh_info->input);
		sh_info->input = ft_strjoin(tmp, ps_hdoc_insert(hdoc, fd));
	}
	waitpid(pid, 0, 0);
	if (pid == 0)
		exit(1);
	hdoc->fd_of_file = dup(fd[0]);
	close(fd[1]);
	close(fd[0]);
	ft_for_debug(sh_info->input);
	//ps_update_input(hdoc, sh_info);
	return(1);
}
