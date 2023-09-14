/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 07:43:55 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/14 20:03:00 by afalconi         ###   ########.fr       */
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
	if (arg == NULL)
		return(2);
//	write(2, arg->str, ft_strlen(arg->str))
	while(arg->str[++i])
	{
		write(2, "tumadre\n", 8);
		while(arg->str[i] == ' ')
			i ++;
		while(arg->str[i] && arg->str[i] != ' ')
		{
			ex_check_quotes(arg->str, &i);
			i++;
		}
		x++;
	}
	return(x + 2);
}

static char	**ex_formated(struct s_lx_list_token *arg, char *cmd)
{
	int		i;
	int		j;
	int		x;
	char	**ret;

	i = -1;
	j = 0;
	x = ex_cont_formated_arg(arg) + 48;
	write(2, "----", 4);
	write(2, &x, 1);
	write(2, "\n", 1);
	x = 0;
	ret = ft_calloc(ex_cont_formated_arg(arg) * 8 , 1);
	ret[0] = ft_strdup(cmd);
	if (arg == NULL)
	{
		ret[1] = NULL;
		return (ret);
	}
	while(arg->str[++i])
	{
		j = i;
		while(arg->str[i] == ' ')
			i ++;
		i --;
		while(arg->str[++i] != ' ' && arg->str[i])
			ex_check_quotes(arg->str, &i);
		ret[++x] = ft_strndup(arg->str, j, i);
	}
	ret[++x] = NULL;
	return(ret);
}

int ex_cmd(struct s_lx_list_token *cmd, struct s_lx_list_token *arg, struct s_minitree *node, t_shell_info *sh_info)
{
	char	*path_cmd;
	char	**arr_cmd_arg;
	int		i;

	i = -1;
	path_cmd = NULL;
	path_cmd = ex_ck_cmd(cmd, node);
	if (path_cmd == NULL && node->exit_status == -1)
		return(-1) ;
	arr_cmd_arg = ex_formated(arg, cmd->str);
	ex_real_esecution(path_cmd, arr_cmd_arg, node, sh_info);
	while (arr_cmd_arg[++i])
	{
		write(2, "---", 3);
		write(2, arr_cmd_arg[i], ft_strlen(arr_cmd_arg[i]));
		write(2, "---", 3);
		write(2, "\n", 1);
		free(arr_cmd_arg[i]);
	}
	free(arr_cmd_arg);
	free(path_cmd);
	return(1);
}
