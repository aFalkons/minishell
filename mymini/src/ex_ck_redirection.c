/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_ck_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 02:20:42 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/29 05:50:52 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ex_redire_to_do(struct s_list_redirection *open)
{
	int		number;
	char	token_ck;

	number = 0;
	token_ck = 0;
	if (open->dont_say_that == -1)
		return ;
	number = open->fd_input;
	token_ck = open->token;
	open->dont_say_that = 1;
	open = open->next;
	while (open)
	{
		if (number == open->fd_input && token_ck)
			open->dont_say_that = -1;
		open = open->next;
	}
}


static void	ex_open_redirection(struct s_list_redirection *open)
{
	struct s_list_redirection	*head;

	head = open;
	while(open)
	{
		ex_redire_to_do(open);
		printf("%d\n", open->dont_say_that);
		if (open->token == OUT && open->dont_say_that == 1)
			ex_out(open, 0);
		//else if (open->token == INP && open->dont_say_that == 1)
		//	ex_inp(open);
		//else if (open->token == HDOC && open->dont_say_that == 1)
		//	ex_hdoc(open);
		//else if (open->token == APP && open->dont_say_that == 1)
		//	ex_app();
		open = open->next;
	}
	open = head;
}

static void	ex_close_redirection(struct s_list_redirection *close)
{
	struct s_list_redirection	*head;

	head = close;
	while(close)
	{
		if (close->token == OUT && close->dont_say_that == 1)
			ex_out(close, 1);
		//else if (close->token == INP && close->dont_say_that == 1)
		//	ex_inp(close);
		//else if (close->token == HDOC && close->dont_say_that == 1)
		//	ex_hdoc(close);
		//else if (close->token == APP && close->dont_say_that == 1)
		//	ex_app();
		close = close->next;
	}
}


void	ex_ck_redirection(t_minitree *node)
{
	if (node->close_redire)
		ex_close_redirection(node->close_redire);
	if (node->redire)
		ex_open_redirection(node->redire);
}
