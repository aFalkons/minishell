/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_list_CMD_ARG.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:14:19 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/05 07:01:57 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	lx_insert_ARG(t_shell_info *sh_info, int *i)
{
	int start;
	int finish;

	start = *i;
	finish = *i;
	while(sh_info->input[finish])
	{
		lx_check_quotes(sh_info, &finish);
		finish ++;
		if (sh_info->input[finish] == PIPE || sh_info->input[finish] == INP || sh_info->input[finish] == OUT || sh_info->input[finish] == '&')
			break ;
	}
	lx_create_or_insert(sh_info, ft_strndup(sh_info->input, start, finish), ARG);
	*i = finish - 1;
}

void	lx_insert_CMD_ARG(t_shell_info *sh_info, int *i)
{
	int start;
	int finish;

	start = *i;
	finish = *i;
	while (sh_info->input[finish] && sh_info->input[finish] != ' ')
		finish ++;
	lx_create_or_insert(sh_info, ft_strndup(sh_info->input, start, finish), CMD);
	*i = finish;
	lx_insert_ARG(sh_info, i);
}
