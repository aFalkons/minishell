/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pipe_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 02:06:53 by afalconi          #+#    #+#             */
/*   Updated: 2023/11/22 20:34:50 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ps_file_befor_token(char *str)
{
	int		finish;
	char	*tmp;
	int		ret;

	finish = 0;
	if (str[finish] == OUT)
		return (1);
	if (str[finish] == INP)
		return (0);
	while (str[finish] != OUT && str[finish] != INP)
		finish ++;
	tmp = ft_strndup(str, 0, finish);
	ret = ft_atoi(tmp);
	free(tmp);
	return (ret);
}

static int	ps_set_str_pipe_head(t_minitree *last
	, t_minitree *first, t_list_redirection *redire_list_h, t_minitree *node_h)
{
	if (first == node_h && last->token->token == PIPE)
	{
		first->flag_pipe = 3;
		last->flag_pipe = 2;
		last->redire = redire_list_h;
		first->close_redire = redire_list_h;
		return (1);
	}
	else if (first == node_h && last->token->token != PIPE)
	{
		last->redire = redire_list_h;
		first->close_redire = redire_list_h;
		return (1);
	}
	return (0);
}

void	ps_set_struct_pipe(t_minitree *last
	, t_minitree *first, t_list_redirection *redire_list_h, t_minitree *node_h)
{
	if (ps_set_str_pipe_head(last, first, redire_list_h, node_h) == 1)
		return ;
	if (first->token->token == PIPE && last->token->token != PIPE)
	{
		last->flag_pipe = 1;
	}
	if (last->token->token == PIPE
		&& (first->token->token != PIPE || first->token == NULL))
	{
		last->flag_pipe = 2;
		if (first->flag_pipe == 1)
			first->flag_pipe = 5;
		else
			first->flag_pipe = 3;
	}
	if (last->token->token == PIPE && last->flag_pipe != 2)
	{
		last->flag_pipe = 4;
	}
	last->redire = redire_list_h;
	first->close_redire = redire_list_h;
}
