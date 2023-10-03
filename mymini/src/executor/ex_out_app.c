/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_out_app.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:24:52 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/08 10:46:19 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ex_out(struct s_list_redirection *redire, int flag)
{
	if (redire->dont_say_that == -1)
	{
		redire->fd_of_file = open(redire->file, O_CREAT | O_RDWR | O_TRUNC, 0644);
		close(redire->fd_of_file);
		return ;
	}
	if (flag == 0)
	{
		redire->fd_of_file = open(redire->file, O_CREAT | O_RDWR, 0644);
		redire->fd_copy = dup(redire->fd_input);
		dup2(redire->fd_of_file, redire->fd_input);
		return ;
	}
	dup2(redire->fd_copy, redire->fd_input);
	close(redire->fd_copy);
	close(redire->fd_of_file);
}

void	ex_app(struct s_list_redirection *redire, int flag)
{
	if (redire->dont_say_that == -1)
	{
		redire->fd_of_file = open(redire->file, O_CREAT | O_RDWR | O_TRUNC, 0644);
		close(redire->fd_of_file);
		return ;
	}
	if (flag == 0)
	{
		redire->fd_of_file = open(redire->file, O_CREAT | O_RDWR | O_APPEND, 0644);
		redire->fd_copy = dup(redire->fd_input);
		dup2(redire->fd_of_file, redire->fd_input);
		return ;
	}
	dup2(redire->fd_copy, redire->fd_input);
	close(redire->fd_copy);
	close(redire->fd_of_file);
}
