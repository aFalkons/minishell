/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:24:52 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/29 06:26:20 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	ex_out(struct s_list_redirection *redire, int flag)
{
	if (flag == 0)
	{
		write(2, "GGG\n", 4);
		redire->fd_of_file = open(redire->file, O_CREAT | O_RDWR, 0644);
		redire->fd_copy = dup(redire->fd_input);
		dup2(redire->fd_of_file, redire->fd_input);
		return ;
	}
	write(2, "GG\n", 3);
	redire->fd_of_file = redire->fd_copy;
	close(redire->fd_of_file);
}
