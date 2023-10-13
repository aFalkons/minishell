/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_inp_hdoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:04:23 by afalconi          #+#    #+#             */
/*   Updated: 2023/10/13 12:23:56 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ex_inp(struct s_list_redirection *redire, int flag, int *exit_stat)
{
	if (redire->inp_error == 1)
	{
		*exit_stat = -1;
		return(1);
	}
	if (redire->dont_say_that == -1)
		return (0);
	if (flag == 0)
	{
		redire->dont_say_that = 1;
		redire->fd_of_file = open(redire->file, O_RDWR | O_APPEND, 0644);
		redire->fd_copy = dup(redire->fd_input);
		dup2(redire->fd_of_file, redire->fd_input);
		return(0) ;
	}
	dup2(redire->fd_copy, redire->fd_input);
	close(redire->fd_copy);
	close(redire->fd_of_file);
	return(0);
}

void	ex_hdoc(struct s_list_redirection *redire, int flag)
{
	if (flag == 0)
	{
		redire->dont_say_that = 1;
		redire->fd_copy = dup(redire->fd_input);
		dup2(redire->fd_of_file, redire->fd_input);
		return ;
	}
	dup2(redire->fd_copy, redire->fd_input);
	close(redire->fd_copy);
	close(redire->fd_of_file);
}
