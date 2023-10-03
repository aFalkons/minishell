/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_list_CMD_ARG.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:14:19 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/19 18:27:53 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	lx_add_redi_arg(t_shell_info *sh_info, char **str, char **str2, int *fi, int *st)
{
	int end_redi;

	end_redi = *fi - 1;
	while(ft_isnumeric(sh_info->input[end_redi]))
		end_redi --;
	if (sh_info->input[*fi] == OUT)
	{
		lx_insert_out_app(sh_info, fi);
		*fi = *fi + 1;
	}
	else if (sh_info->input[*fi] == INP)
	{
		lx_insert_inp_hdoc(sh_info, fi);
		*fi = *fi + 1;
	}
	if (*str == NULL)
		*str = ft_strndup(sh_info->input, *st, end_redi);
	else
	{
		*str2 = ft_strndup(sh_info->input, *st, end_redi);
		*str = ft_strjoin(*str, *str2);
		free(*str2);
	}
	//printf("--%s--\n", *str);
	*st = *fi;
}

static void	lx_skip_quot(char	*str, int	*i)
{
	char	quot;

	quot = 0;
	if (str[*i] == 39 || str[*i] == 34)
	{
		quot = str[*i];
		*i = *i + 1;
		while(str[*i] != quot)
			*i = *i + 1;
	}
}

static void	 lx_insert_arg(t_shell_info *sh_info, int *i)
{
	char	*str;
	char	*str2;
	int 	st;
	int		fi;

	st = *i;
	fi = *i;
	str = 0;
	str2 = 0;
	lx_skip_space(sh_info, &st);
	if (sh_info->input[st] == OR || sh_info->input[st] == PIPE || sh_info->input[st] == '&' || sh_info->input[st] == OP_S || sh_info->input[st] == CL_S || sh_info->input[st] == '\0' || sh_info->input[st] == INP || sh_info->input[st] == OUT)
	{
		*i = st - 1;
		return ;
	}
	//if (sh_info->input[st + 1] == ' ' && sh_info->input[st] == ' ')
	//{
	//	st ++;
	//	lx_skip_space(sh_info, &st);
	//}
	if (sh_info->input[st] == OR && sh_info->input[st] != PIPE && sh_info->input[st] != '&' && sh_info->input[st] != OP_S && sh_info->input[st] != CL_S && sh_info->input[st] != '\0' && sh_info->input[st] != INP && sh_info->input[st] != OUT )
	{
		*i = st - 1;
		return ;
	}
	fi = st;
	while(sh_info->input[fi] != OR && sh_info->input[fi] != PIPE && sh_info->input[fi] != '&' && sh_info->input[fi] != OP_S && sh_info->input[fi] != CL_S && sh_info->input[fi] != '\0')
	{
		lx_skip_quot(sh_info->input , &fi);
		if (sh_info->input[fi] == OUT || sh_info->input[fi] == INP)
			lx_add_redi_arg(sh_info, &str, &str2, &fi, &st);
		else
			fi++;
	}
	//if (st < fi)
	//{
	str2 = ft_strndup(sh_info->input, st, fi);
	str = ft_strjoin(str, str2);
	free(str2);
	lx_create_or_insert(sh_info, str, ARG);
	//}
	*i = fi - 1;
}


void	lx_insert_cmd_arg(t_shell_info *sh_info, int *i)
{
	int	start;
	int	finish;

	start = *i;
	finish = *i;
	while (sh_info->input[finish] && sh_info->input[finish] != ' ' && sh_info->input[finish] != CL_S && sh_info->input[finish] != PIPE && sh_info->input[finish] != INP && sh_info->input[finish] != OUT && sh_info->input[finish] != '&')
		finish ++;
	*i = finish;
	if (sh_info->input[finish] == OUT || sh_info->input[finish] == INP)
	{
		while(ft_isnumeric(sh_info->input[finish - 1]))
			finish --;
	}
	lx_create_or_insert(sh_info, ft_strndup(sh_info->input, start, finish), CMD);
	lx_insert_arg(sh_info, i);
}

void	lx_skip_space(t_shell_info *sh_info, int *i)
{
	while (sh_info->input[*i] == ' ' && sh_info->input[*i])
		*i = *i + 1;
}
