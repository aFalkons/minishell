/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 07:43:55 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/12 14:49:31 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ex_check_quotes(char *str, int *i)
{
	char	sing_doub_q;

	sing_doub_q = 0;
	if (str[*i] == 39 || str[*i] == 34)
	{
		sing_doub_q = str[*i];
		*i = *i + 1;
		while (str[*i] != sing_doub_q)
			*i = *i + 1;
	}
}
static int	ex_cont_formated_arg(struct s_lx_list_token *arg)
{
	int		i;
	int		x;

	i = -1;
	x = 0;
	while(arg->str[++i])
	{
		while(arg->str[i] == ' ')
			i ++;
		i --;
		while(arg->str[++i] != ' ' && arg->str[i])
			ex_check_quotes(arg->str, &i);
		x++;
	}
	return(x + 1);
}

static char	**ex_formated_arg(struct s_lx_list_token *arg)
{
	int		i;
	int		j;
	int		x;
	char	**ret;

	i = -1;
	j = 0;
	x = 0;
	ret = NULL;
	ret = ft_calloc(ex_cont_formated_arg(arg) * 8 , 1);
	while(arg->str[++i])
	{
		j = i;
		while(arg->str[i] == ' ')
			i ++;
		i --;
		while(arg->str[++i] != ' ' && arg->str[i])
			ex_check_quotes(arg->str, &i);
		ret[x] = ft_strndup(arg->str, j, i);
		x++;
	}
	ret[x] = NULL;
	return(ret);
}

void ex_cmd(struct s_lx_list_token *cmd, struct s_lx_list_token *arg, struct s_minitree *node)
{
	char	*path_cmd;
	char	**arr_arg;
	(void)cmd;
	(void)node;

	arr_arg = NULL;
	path_cmd = ex_ck_cmd(cmd, node);
	if (arg != NULL)
		arr_arg = ex_formated_arg(arg);
}
