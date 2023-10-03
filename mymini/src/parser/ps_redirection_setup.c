/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_redirection_setup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:34:42 by afalconi          #+#    #+#             */
/*   Updated: 2023/10/03 02:07:42 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_list_redirection *insert_redire_list(t_minitree *node, t_shell_info *sh_info)
{
	t_list_redirection *tmp;

	tmp = ft_calloc(sizeof(struct s_list_redirection), 1);
	tmp->token = node->token->token;
	tmp->file = ps_file_after_token(node->token->str);
	tmp->fd_input = ps_file_befor_token(node->token->str);
	tmp->next = NULL;
	tmp->dont_say_that = 0;
	tmp->exit_inp = 0;
	tmp->fd_of_file = 0;
	if (tmp->token == HDOC)
		ps_handler_HDOC(tmp, sh_info);
	return(tmp);
}

static void	ps_setup_redire(t_minitree *node, t_shell_info *sh_info, t_minitree *node_h)
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
			return (ps_set_struct_pipe(node, first, redire_list_h, node_h));
		if (node->token->token == OUT || node->token->token == INP || node->token->token == HDOC || node->token->token == APP)
		{
			if (redire_list == NULL)
			{
				redire_list = insert_redire_list(node, sh_info);
				redire_list_h = redire_list;
			}
			else
			{
				redire_list->next = insert_redire_list(node, sh_info);
				redire_list = redire_list->next;
			}
		}
	}
	ps_set_struct_pipe(last, first, redire_list_h, node_h);
}

void	ps_redirection_setup(t_minitree *node, t_minitree *node_h, t_shell_info *sh_info)
{
	if (node == node_h)
		ps_setup_redire(node, sh_info, node_h);
	if (node != node_h)
	{
		if (node->token->token == AND || node->token->token == OR || node->token->token == PIPE)
			ps_setup_redire(node, sh_info, node_h);
	}
	if (node->next)
		ps_redirection_setup(node->next, node_h, sh_info);
	if (node->subsh)
		ps_redirection_setup(node->subsh, node->subsh, sh_info);
	if (node == NULL)
		return ;
}





