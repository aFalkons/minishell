/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_list_CMD_ARG.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:14:19 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/10 03:29:10 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	lx_insert_arg(t_shell_info *sh_info, int *i)
{
	int	start;
	int	finish;

	start = *i;
	finish = *i;
	while (sh_info->input[finish])
	{
		lx_check_quotes(sh_info, &finish);
		finish ++;
		if (sh_info->input[finish] == PIPE || sh_info->input[finish] == INP
			|| sh_info->input[finish] == OUT || sh_info->input[finish] == '&'
			|| sh_info->input[finish] == OP_S || sh_info->input[finish] == CL_S)
			break ;
	}
	lx_create_or_insert(sh_info,
		ft_strndup(sh_info->input, start, finish), ARG);
	*i = finish - 1;
}

void	lx_insert_cmd_arg(t_shell_info *sh_info, int *i)
{
	int	start;
	int	finish;

	start = *i;
	finish = *i;
	while (sh_info->input[finish] && sh_info->input[finish] != ' '
		&& sh_info->input[finish] != CL_S && sh_info->input[finish] != PIPE
		&& sh_info->input[finish] != INP && sh_info->input[finish] != OUT)
		finish ++;
	lx_create_or_insert(sh_info,
		ft_strndup(sh_info->input, start, finish), CMD);
	*i = finish;
	lx_skip_space(sh_info, i);
	if (sh_info->input[*i] == PIPE || sh_info->input[*i] == INP
		|| sh_info->input[*i] == OUT || sh_info->input[*i] == '&'
		|| sh_info->input[*i] == OP_S || sh_info->input[*i] == CL_S
		|| sh_info->input[*i] == '\0')
	{
		*i = *i - 1;
		return ;
	}
	lx_insert_arg(sh_info, i);
}

void	lx_skip_space(t_shell_info *sh_info, int *i)
{
	while (sh_info->input[*i] == ' ')
		*i = *i + 1;
}
