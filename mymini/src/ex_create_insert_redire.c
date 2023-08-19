/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_create_insert_redire.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:40:30 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/19 19:52:59 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	insert(t_shell_info *sh_info)
{
	struct s_list_redirection *tmp;

	tmp = ft_calloc(sizeof(struct s_list_redirection), 1);
	tmp->fd_input = NULL;
	tmp->file = NULL;
	tmp->next = NULL;
	sh_info->redire->next = tmp;
}

static void	create(t_shell_info *sh_info)
{
	sh_info->redire = ft_calloc(sizeof(struct s_list_redirection), 1);
	sh_info->redire->fd_input = NULL;
	sh_info->redire->file = NULL;
	sh_info->redire->next = NULL;
	sh_info->redire_h = sh_info->redire;
}


void	create_insert_redirection(t_shell_info *sh_info)
{
	if (sh_info->redire == NULL)
		create(sh_info);
	else
		insert(sh_info);
}
