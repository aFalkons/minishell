/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_list_CMD_ARG.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:14:19 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/19 18:27:22 by afalconi         ###   ########.fr       */
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
		if (sh_info->input[finish] == PIPE || sh_info->input[finish] == INP || sh_info->input[finish] == OUT || sh_info->input[finish] == '&' || sh_info->input[finish] == OP_S || sh_info->input[finish] == CL_S)
			break ;
	}
	*i = finish - 1;
	if (sh_info->input[finish] == OUT || sh_info->input[finish] == INP)
	{
		while(ft_isnumeric(sh_info->input[finish - 1]))
			finish --;
	}
	lx_create_or_insert(sh_info,
		ft_strndup(sh_info->input, start, finish), ARG);
}

void	lx_insert_cmd_arg(t_shell_info *sh_info, int *i)
{
	int	start;
	int	finish;
	int	flag;

	start = *i;
	finish = *i;
	flag = 0;;
	while (sh_info->input[finish] && sh_info->input[finish] != ' ' && sh_info->input[finish] != CL_S && sh_info->input[finish] != PIPE && sh_info->input[finish] != INP && sh_info->input[finish] != OUT && sh_info->input[finish] != '&')
		finish ++;
	printf("GG\n");
	*i = finish;
	if (sh_info->input[finish] == OUT || sh_info->input[finish] == INP)
	{
		flag = 1;
		while(ft_isnumeric(sh_info->input[finish - 1]))
			finish --;
	}
	lx_create_or_insert(sh_info, ft_strndup(sh_info->input, start, finish), CMD);
	lx_skip_space(sh_info, i);
	if (sh_info->input[*i] == PIPE || flag == 1 || sh_info->input[*i] == '&' || sh_info->input[*i] == OP_S || sh_info->input[*i] == CL_S || sh_info->input[*i] == '\0')
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
