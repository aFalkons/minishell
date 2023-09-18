/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_ck_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 02:20:42 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/15 16:14:19 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ex_redire_to_do(struct s_list_redirection *open, t_shell_info *sh_info)
{
	int		number;
	char	token;

	number = 0;
	if (open->dont_say_that == -1)
		return ;
	number = open->fd_input;
	token =open->token;
	open->dont_say_that = 1;
	open = open->next;
	if (number == 1 && (token == OUT || token == APP))
		sh_info->stdout_flag = 1;
	else if (number == 0 && (token == HDOC || token == INP))
		sh_info->stdin_flag = 1;
	while (open)
	{
		if ((token == OUT && (open->token == OUT || open->token == APP)) && number == open->fd_input)
			open->dont_say_that = -1;
		if ((token == APP && (open->token == OUT || open->token == APP)) && number == open->fd_input)
			open->dont_say_that = -1;
		if ((token == INP && (open->token == INP || open->token == HDOC)) && number == open->fd_input)
			open->dont_say_that = -1;
		// if ((token == HDOC && (open->token == INP || open->token == HDOC)) && number == open->fd_input)
		// 	open->dont_say_that = -1;
		open = open->next;
	}
}


static void	ex_open_redirection(struct s_list_redirection *open, t_shell_info *sh_info)
{
	struct s_list_redirection	*head;

	head = open;
	//write(2, "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n", ft_strlen("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"));
	while (open)
	{
		ex_redire_to_do(open, sh_info);
		open = open->next;
	}
	open = head;
	while(open)
	{
		if (open->token == OUT)
			ex_out(open, 0);
		else if (open->token == APP)
			ex_app(open, 0);
		else if (open->token == INP)
			ex_inp(open, 0);
		//else if (open->token == PIPE)
		//	ex_pipe(open, 0);
		open = open->next;
	}
}

static void	ex_close_redirection(struct s_list_redirection *close, t_shell_info *sh_info)
{
	while(close)
	{
		if (close->token == OUT && close->dont_say_that == 1)
			ex_out(close, 1);
		else if (close->token == INP && close->dont_say_that == 1)
			ex_inp(close, 1);
		// else if (close->token == HDOC && close->dont_say_that == 1)
		// 	ex_hdoc(close);
		else if (close->token == APP && close->dont_say_that == 1)
			ex_app(close , 1);
		close = close->next;
	}
	sh_info->stdout_flag = 0;
	sh_info->stdin_flag = 0;
}


void	ex_ck_redirection(t_minitree *node, t_shell_info *sh_info)
{
	if (node->close_redire)
		ex_close_redirection(node->close_redire, sh_info);
	if (node->redire)
		ex_open_redirection(node->redire, sh_info);
}
