/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:24:52 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/21 12:55:20 by afalconi         ###   ########.fr       */
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
	while(str[start] && str[start] == ' ')
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
	if (str[finish] == OUT)
		return(NULL);
	while (str[finish] && str[finish] != OUT)
		finish ++;
	finish --;
	return(ft_strndup(str, 0, finish));
}

void 	ex_out(t_minitree *node, t_shell_info *sh_info)
{
	char	*file;
	char	*fd_input;

	file = ex_out_parser(node->token->str);
	fd_input = ex_out_parser_fd(node->token->str);
	if (node->open_redirection == 1)
	{
		*node->fd_file = open(file, O_CREAT | O_RDONLY, 0644);
		printf("--%d\n", *node->fd_file);
		if (fd_input == NULL)
		{
			dup2(STDOUT_FILENO, *node->fd_file);
		}
		else
			dup2(ft_atoi(fd_input), *node->fd_file);
	}
	else
	{
		if (fd_input == NULL)
			dup2(*node->fd_file, STDOUT_FILENO);
		else
			dup2(*node->fd_file, ft_atoi(fd_input));
		printf("---%d\n", *node->fd_file);
		close(*node->fd_file);
	}
	free(file);
	if (fd_input != NULL)
		free(fd_input);
	(void)sh_info;
}
