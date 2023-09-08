/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_redirection_setup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:34:42 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/08 13:39:28 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static void ps_set_struct_pipe(t_minitree *node, t_minitree *first, t_list_redirection *redire_list_h)
{
	t_list_redirection *pip;
	t_list_redirection *tmp;
	static	int *fd_for_pipe;
	int	*fd;

	pip = NULL;
	tmp = NULL;
	fd = NULL;
	printf("GG\n");
	if (first->token != NULL && node->token != NULL)
	{
		if (node->token->token == PIPE || first->token->token == PIPE)
		{
			if (fd_for_pipe == 0)
			{
				fd = ft_calloc(8 ,1);
				*fd = 0;
				pip = ft_calloc(sizeof(t_list_redirection *), 1);
				pip->fd_of_file = fd[0];
				pip->fd_input = 0;
				fd_for_pipe = fd;
				pip->for_pipe = fd;
			}
			else
			{
				pip->for_pipe = fd_for_pipe;
				pip->fd_of_file = fd_for_pipe[1];
				pip->fd_input = 1;
				fd_for_pipe = NULL;
			}
			pip->token = PIPE;
			pip->dont_say_that = 1;
			pip->fd_copy = 0;
			pip->file = NULL;
			pip->exit_inp = 0;
			if (redire_list_h == NULL)
				redire_list_h = pip;
			else
			{
				while(tmp->next)
					tmp = tmp->next;
				tmp->next = pip;
			}
		}
	}
	node->redire = redire_list_h;
	first->close_redire = redire_list_h;
}

static int ps_file_befor_token(char *str)
{
	int		finish;
	char	*tmp;
	int		ret;

	finish = 0;
	if (str[finish] == OUT)
		return(1);
	if (str[finish] == INP)
		return(0);
	while (str[finish] != OUT && str[finish] != INP)
		finish ++;
	tmp = ft_strndup(str, 0, finish);
	ret = ft_atoi(tmp);
	free(tmp);
	return(ret);
}

static char	*ps_file_after_token(char *str)
{
	int		start;
	int		finish;

	start = 0;
	finish = 0;
	while (str[start])
	{
		if (str[start] == OUT || str[start] == INP)
			break;
		start ++;
	}
	start ++;
	if (str[start] == OUT || str[start] == INP)
		start ++;
	while(str[start] && str[start] == ' ')
		start ++;
	finish = start;
	while(str[finish])
		finish ++;
	return(ft_strndup(str, start, finish));
}

t_list_redirection *insert_redire_list(t_minitree *node)
{
	t_list_redirection *tmp;

	tmp = ft_calloc(sizeof(struct s_list_redirection), 1);
	tmp->fd_input = ps_file_befor_token(node->token->str);
	tmp->file = ps_file_after_token(node->token->str);
	tmp->token = node->token->token;
	tmp->next = NULL;
	tmp->dont_say_that = 0;
	tmp->exit_inp = 0;
	tmp->for_pipe = NULL;
	return(tmp);
}

static void	ps_setup_redire(t_minitree *node)
{
	t_list_redirection *redire_list;
	t_list_redirection *redire_list_h;
	t_minitree *last;
	t_minitree *first;

	redire_list = NULL;
	redire_list_h = NULL;
	first = node;
	last = NULL;
	while(node)
	{
		last = node;
		node = node->next;
		if (node == NULL)
			break ;
		if (node->token->token == AND || node->token->token == OR || node->token->token == PIPE)
		{
			first->close_redire = redire_list_h;
			node->redire = redire_list_h;
			return (ps_set_struct_pipe(node, first, redire_list_h));
		}
		if (node->token->token == OUT || node->token->token == INP || node->token->token == HDOC || node->token->token == APP)
		{
			if (redire_list == NULL)
			{
				redire_list = insert_redire_list(node);
				redire_list_h = redire_list;
			}
			else
			{
				redire_list->next = insert_redire_list(node);
				redire_list = redire_list->next;
			}
		}
	}
	ps_set_struct_pipe(last, first, redire_list_h);

	first->close_redire = redire_list_h;
	last->redire = redire_list_h;
}

void	ps_redirection_setup(t_minitree *node, t_minitree *node_h, t_shell_info *sh_info)
{
	if (node == node_h)
		ps_setup_redire(node);
	if (node != node_h)
	{
		if (node->token->token == AND || node->token->token == OR || node->token->token == CL_S || node->token->token == PIPE)
			ps_setup_redire(node);
	}
	if (node->subsh)
		ps_redirection_setup(node->subsh, node_h, sh_info);
	if (node->next)
		ps_redirection_setup(node->next, node_h, sh_info);
	if (node == NULL)
		return ;
}





