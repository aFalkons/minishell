/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_set_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 05:57:49 by afalconi          #+#    #+#             */
/*   Updated: 2023/11/19 21:45:02 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	lx_add_redi_arg2(t_shell_info *sh_info, int *fi)
{
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
}

void	lx_add_redi_arg(t_shell_info *sh_info, char **str, int *fi, int *st)
{
	int		end_redi;
	char	*tmp;
	char	*tmp2;

	end_redi = *fi - 1;
	while (ft_isnumeric(sh_info->input[end_redi]))
		end_redi --;
	lx_add_redi_arg2(sh_info, fi);
	if (*str == NULL)
		*str = ft_strndup(sh_info->input, *st, end_redi);
	else
	{
		tmp2 = ft_strndup(sh_info->input, *st, end_redi);
		tmp = ft_strdup(*str);
		free(*str);
		*str = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
	}
	*st = *fi;
}

void	lx_set_redirection(struct s_lx_list_token *token_list)
{
	struct s_lx_list_token	*tmp;
	struct s_lx_list_token	*tmp2;

	tmp2 = NULL;
	while (token_list)
	{
		if (token_list->token == CMD && token_list->next != NULL)
		{
			tmp = token_list;
			while (token_list->next->next != NULL
				&& token_list->next->token != ARG
				&& token_list->next->token != OR
				&& token_list->next->token != AND
				&& token_list->next->token != PIPE)
				token_list = token_list->next;
			if (token_list->next->token == ARG)
			{
				tmp2 = token_list->next;
				token_list->next = token_list->next->next;
				tmp2->next = tmp->next;
				tmp->next = tmp2;
			}
		}
		token_list = token_list->next;
	}
}
