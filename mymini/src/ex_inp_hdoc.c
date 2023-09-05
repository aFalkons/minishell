/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_inp_hdoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:04:23 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/31 17:40:38 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ex_inp(struct s_list_redirection *redire, int flag)
{
	char	*str;

	str = NULL;
	printf("%s\n", redire->file);
	if (flag == 0)
	{
		if (access(redire->file, R_OK) == -1)
		{
			str = ft_strjoin(redire->file ,": No such file or directory");
			ft_print_message(str, 2);
			free(str);
			redire->dont_say_that = -1;
			return ;
		}
		redire->dont_say_that = 1;
		redire->fd_of_file = open(redire->file, O_RDWR | O_APPEND, 0644);
		redire->fd_copy = dup(redire->fd_input);
		dup2(redire->fd_of_file, redire->fd_input);
		return ;
	}
	dup2(redire->fd_copy, redire->fd_input);
	close(redire->fd_copy); // to verify
	close(redire->fd_of_file);
}
