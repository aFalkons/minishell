/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_list_CMD_ARG.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:14:19 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/05 19:39:45 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	 lx_insert_arg(t_shell_info *sh_info, int *i)
{
	char	*str;
	char	*str2;
	int 	st;
	int		fi;
	int		test;

	st = *i;
	fi = *i;
	while(sh_info->input[fi] != OR && sh_info->input[fi] != PIPE && sh_info->input[fi] != '&' && sh_info->input[fi] != OP_S && sh_info->input[fi] != CL_S && sh_info->input[fi] != '\0')
	{
		printf("");
		lx_check_quotes(sh_info, &fi);
		if (sh_info->input[fi] == OUT || sh_info->input[fi] == INP)
		{
			test = fi - 1;
			while(ft_isnumeric(sh_info->input[test]))
				test --;
			if (sh_info->input[fi] == OUT)
			{
				lx_insert_out_app(sh_info, &fi);
				fi ++;
			}
			else if (sh_info->input[fi] == INP)
			{
				lx_insert_inp_hdoc(sh_info, &fi);
				fi ++;
			}
			if (str == NULL)
				str = ft_strndup(sh_info->input, st, test);
			else
			{
				str2 = ft_strndup(sh_info->input, st, test);
				str = ft_strjoin(str, str2);
				free(str2);
			}
			st = fi;
		}
		fi++;
	}
	if (st - fi > 1)
	{
		str2 = ft_strndup(sh_info->input, st, test);
		str = ft_strjoin(str, str2);
		free(str2);
	}
 	lx_create_or_insert(sh_info, str, ARG);
}

// static void	 lx_insert_arg(t_shell_info *sh_info, int *i)
// static void	 lx_insert_arg(t_shell_info *sh_info, int *i)
// {
// 	int		start;
// 	int		finish;
// 	char	*str;
// 	char	*str2;
// 	char	q;
//
// 	start = *i;
// 	finish = *i;
// 	str = NULL;
// 	str2 = NULL;
// 	while (1)
// 	{
// 		printf("%c\n", sh_info->input[finish]);
// 		if ((sh_info->input[finish] == 39 || sh_info->input[finish] == 34) && sh_info->input[finish - 1] != '\\')
// 		{
// 			printf("--%c\n", sh_info->input[finish]);
// 			q = sh_info->input[finish];
// 			finish ++;
// 			while(1)
// 			{
// 				if (sh_info->input[finish] == q && sh_info->input[finish - 1] != '\\')
// 					break;
// 				finish ++;
// 			}
// 		}
// 		finish ++;
// 		if (sh_info->input[finish] == OR || sh_info->input[finish] == PIPE || sh_info->input[finish] == '&' || sh_info->input[finish] == OP_S || sh_info->input[finish] == CL_S || sh_info->input[finish] == '\0')
// 		{
// 			str2 = ft_strndup(sh_info->input, start, finish);
// 			if (str == NULL)
// 				str = str2;
// 			else
// 			{
// 				str = ft_strjoin(str, str2);
// 				free(str2);
// 			}
// 			break ;
// 		}
// 		if (sh_info->input[finish] == OUT || sh_info->input[finish] == INP)
// 		{
// 			if (sh_info->input[finish] == OUT)
// 			{
// 				finish = *i;
// 				lx_insert_out_app(sh_info, i);
// 				*i = *i + 1;
// 			}
// 			else if (sh_info->input[finish] == INP)
// 			{
// 				finish = *i;
// 				lx_insert_inp_hdoc(sh_info, i);
// 				*i = *i + 1;
// 			}
// 			while(ft_isnumeric(sh_info->input[finish - 1]))
// 				finish --;
// 			if (str == NULL)
// 			{
// 				str = ft_strndup(sh_info->input, start, finish);
// 			}
// 			else
// 			{
// 				str2 = ft_strndup(sh_info->input, start, finish);
// 				str = ft_strjoin(str, str2);
// 				free(str2);
// 			}
// 			start = *i;
// 			finish = *i;
// 		}
// 	}
// 	*i = finish - 1;
// 	lx_create_or_insert(sh_info, str, ARG);
// }

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
	lx_skip_space(sh_info, i);
	if (sh_info->input[*i] == INP || sh_info->input[*i] == OUT || sh_info->input[*i] == PIPE || sh_info->input[*i] == '&' || sh_info->input[*i] == OP_S || sh_info->input[*i] == CL_S || sh_info->input[*i] == '\0')
	{
		if (sh_info->input[finish] == OUT)
		{
			lx_insert_out_app(sh_info, i);
			*i = *i + 1;
		}
		else if (sh_info->input[finish] == INP)
		{
			lx_insert_inp_hdoc(sh_info, i);
			*i = *i + 1;
		}
		else
		{
			*i = *i - 1;
			return ;
		}
	}
	lx_insert_arg(sh_info, i);
}

void	lx_skip_space(t_shell_info *sh_info, int *i)
{
	while (sh_info->input[*i] == ' ' && sh_info->input[*i])
		*i = *i + 1;
}
