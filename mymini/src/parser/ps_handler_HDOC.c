/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_handler_HDOC.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:22:15 by afalconi          #+#    #+#             */
/*   Updated: 2023/12/01 19:22:21 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ps_hdoc_handler_signal(int sig)
{
	if (sig == SIGINT)
	{
		exit(130);
		g_for_sig = 3;
	}
}

static void	ps_hdoc_insert(t_list_redirection *hdoc, int *fd)
{
	char	*str;

	str = NULL;
	while (1)
	{
		str = readline("> ");
		if (!str || ((ft_strncmp(str, hdoc->file, ft_strlen(hdoc->file)) == 0)
				&& ft_strlen(hdoc->file) == ft_strlen(str)))
			break ;
		write(fd[1], str, ft_strlen(str));
		write(fd[1], "\n", 1);
	}
	if (!str)
	{
		ft_putstr_fd("\033[93m", 1);
		ft_putstr_fd(" minishell : warning: here-document", 1);
		ft_putstr_fd(" delimited by end-of-file (wanted '", 1);
		ft_putstr_fd(hdoc->file, 1);
		ft_putstr_fd("')", 1);
		ft_putstr_fd("\n\e[0m", 1);
		g_for_sig = 5;
	}
}

//static char	*ps_join_char(char *str, char c)
//{
//	char	*ret;
//	int		i;
//
//	i = -1;
//	ret = NULL;
//	ret = ft_calloc(ft_strlen(str) + 2, 1);
//	while(++i < ft_strlen(str))
//		ret[i] = str[i];
//	ret[i] = c;
//	ret[i + 1] = 0;
//	return(ret);
//}
//
//
//static void	ps_update_input(t_list_redirection *hdoc, t_shell_info *sh_info)
//{
//	int		to_add;
//	char	str;
//	int		len;
//	char	*tmp;
//
//	tmp = NULL;
//	len = 1;
//	to_add = dup(hdoc->fd_of_file);
//	tmp = ft_strdup(sh_info->input);
//	free(sh_info->input);
//	sh_info->input = ps_join_char(tmp, '\n');
//	while(len && len != -1)
//	{
//		len = read(to_add, &str, 1);
//		tmp = ft_strdup(sh_info->input);
//		free(sh_info->input);
//		sh_info->input = ps_join_char(tmp, str);
//	}
//	tmp = ft_strdup(sh_info->input);
//	free(sh_info->input);
//	sh_info->input = ft_strndup(tmp, 0, ft_strlen(tmp) - 1);
//	if (g_for_sig == 5)
//	{
//		tmp = ft_strdup(sh_info->input);
//		free(sh_info->input);
//		sh_info->input = ft_strjoin(tmp, hdoc->file);
//	}
//	g_for_sig = 0;
//	close(to_add);
//}

int	ps_handler_hdoc(t_list_redirection *hdoc, t_shell_info *sh_info)
{
	pid_t		pid;
	int			fd[2];

	(void)sh_info;
	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, &ps_hdoc_handler_signal);
		close(fd[0]);
		ps_hdoc_insert(hdoc, fd);
	}
	waitpid(pid, 0, 0);
	if (pid == 0)
		exit(1);
	hdoc->fd_of_file = dup(fd[0]);
	close(fd[1]);
	close(fd[0]);
	if (g_for_sig == 3)
	{
		g_for_sig = 4;
		return (1);
	}
	return (0);
}

void	ps_ck_hdoc_input(t_list_redirection *hdoc,
	t_shell_info *sh_info, int *h_error)
{
	if (hdoc->next)
		ps_ck_hdoc_input(hdoc->next, sh_info, h_error);
	if (hdoc->token == HDOC && *h_error != 1)
		*h_error = ps_handler_hdoc(hdoc, sh_info);
}

int	ps_set_hdoc(t_minitree *node
	, t_minitree *node_h, t_shell_info *sh_info)
{
	int					h_error;

	(void)node_h;
	h_error = 0;
	if (node->next)
		h_error = ps_set_hdoc(node->next, sh_info->node_h, sh_info);
	if (node->subsh)
		h_error = ps_set_hdoc(node->subsh, sh_info->node_h, sh_info);
	if (h_error == 1)
		return (1);
	if (node->redire)
		ps_ck_hdoc_input(node->redire, sh_info, &h_error);
	return (0);
}
