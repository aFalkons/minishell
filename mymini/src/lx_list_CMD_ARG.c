/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_list_CMD_ARG.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:14:19 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/02 19:00:40 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	lx_insert_ARG(t_shell_info *sh_info, int *i)
{
	int start;
	int finish;

	start = *i;
	finish = *i;
	lx_create_or_insert(sh_info);
	// while(sh_info->input[finish] != PIPE || sh_info->input[finish] != INP || sh_info->input[finish] != OUT || sh_info->input[finish] != '&' || sh_info->input[finish] != 0)
	while(sh_info->input[finish] != 0)
	{
		lx_check_quotes(sh_info, &finish);
		finish ++;
	}
	sh_info->lx_ls_token->token = ARG;
	sh_info->lx_ls_token->str = ft_strndup(sh_info->input, start, finish);
	*i = finish;
}

void	lx_insert_CMD_ARG(t_shell_info *sh_info, int *i)
{
	int start;
	int finish;

	start = *i;
	finish = *i;
	lx_create_or_insert(sh_info);
	while (sh_info->input[finish] && sh_info->input[finish] != ' ')
		finish ++;
	sh_info->lx_ls_token->token = CMD;
	sh_info->lx_ls_token->str = ft_strndup(sh_info->input, start, finish);
	*i = finish;
	lx_insert_ARG(sh_info, i);
}
