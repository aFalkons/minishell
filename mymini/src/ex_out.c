/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:24:52 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/15 16:20:32 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ex_out_parser(char *str)
{
	int		start;
	int		finish;

	start = 0;
	finish = 0;
	while (str[start] && str[start] != OUT)
		start ++;
	start ++;
	finish = start;
	while(str[finish])
		finish ++;
	return(ft_strndup(str, start, finish));
}

static char *ex_out_parser_fd(char *str)
{
	int	finish;

	finish = 0;
	while (str[finish] && str[finish] != OUT)
		finish ++;
	finish ++;
	return(ft_strndup(str, 0, finish));
}

void	ex_setup_next_node(t_minitree *node, char *file, int flag)
{
	if (node->token->token == ARG || node->token->token == CMD)
		node->fd_output = open(file, O_CREAT, O_RDWR);
	if ((node->token->token == AND || node->token->token == PIPE || node->token->token == OR) && flag == 0)
		return ;
	if (node->subsh)
		ex_setup_next_node(node, file, 1);
	if (node->next)
		ex_setup_next_node(node, file, flag);
}

void	ex_out(t_minitree *node, t_shell_info *sh_info, int flag)
{
	char	*file;
	char	*fd_input;

	file = ex_out_parser(node->token->str);
	fd_input = ex_out_parser_fd(node->token->str);
	if (flag == 0)
		ex_setup_next_node(node, file, 0);
	free(file);
	free(fd_input);
	(void)sh_info;
}
