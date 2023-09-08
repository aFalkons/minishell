/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:23:15 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/08 10:53:21 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ex_pipe(struct s_list_redirection *pip, int flag)
{
	int	bozi;

	bozi = *(pip->for_pipe);
	if(flag == 1)
	{
		if (pip->fd_input == 1)
		{
			if (pipe(pip->for_pipe) == -1)
			{
				pip->exit_inp = 1;
				return;
			}
			close(pip->for_pipe[1]);
			if (bozi != 1)
			{
				pip->fd_copy = dup(1);
				dup2(pip->for_pipe[0], 1);
			}
		}
		else
		{
			close(pip->for_pipe[0]);
			pip->fd_copy = dup(0);
			dup2(pip->for_pipe[1], 0);
		}
		return;
	}
	dup2(pip->fd_copy, pip->fd_input);
	close(pip->fd_copy);
}
