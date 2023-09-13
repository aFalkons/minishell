/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_set_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 05:57:49 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/13 16:20:05 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lx_set_redirection(struct s_lx_list_token *token_list)
{
	struct s_lx_list_token	*tmp;
	struct s_lx_list_token	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	while (token_list)
	{
		if (token_list->token == CMD && token_list->next != NULL)
		{
			tmp = token_list;
			while (token_list->next->next != NULL && token_list->next->token != ARG && token_list->next->token != OR && token_list->next->token != AND && token_list->next->token != PIPE)
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
