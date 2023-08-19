/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:24:52 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/19 20:01:44 by afalconi         ###   ########.fr       */
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
	while (str[finish] && str[finish] != OUT)
		finish ++;
	finish --;
	return(ft_strndup(str, 0, finish));
}

void	ex_setup_next_node(t_minitree *node, int fd, int flag)
{
	while(node)
	{
		node->fd_output = fd;
		if ((node->token->token == AND || node->token->token == PIPE || node->token->token == OR) && flag == 0)
			break ;
		if (node->subsh)
			ex_setup_next_node(node, fd, 1);
		node = node->next;
	}
	// printf("GG\n");
}

void 	ex_out(t_minitree *node, t_shell_info *sh_info)
{
	char	*file;
	int		fd;
	char	*fd_input;

	file = ex_out_parser(node->token->str);
	fd_input = ex_out_parser_fd(node->token->str);
	fd = open(file, O_RDWR | O_TRUNC | O_CREAT, 777);
	printf("%d\n", fd);
	// ex_setup_next_node(node, fd, 0);

	free(file);
	free(fd_input);
	(void)sh_info;
}
