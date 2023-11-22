/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_create_insert_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:16:43 by afalconi          #+#    #+#             */
/*   Updated: 2023/11/19 19:09:38 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lx_ck_is_empty(t_shell_info *sh_info)
{
	int	flag;
	int	i;

	i = -1;
	flag = 1;
	while (sh_info->input[++i])
	{
		if (sh_info->input[i] != ' ')
			flag = 0;
	}
	sh_info->is_emty = flag;
}

void	lx_free_and_join(char *to_join, char *to_free)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strdup(to_join);
	to_join = ft_strjoin(tmp, to_free);
	free(to_free);
	free(tmp);
}

static void	lx_insert_list(t_shell_info *sh_info, char *str, char token)
{
	t_lx_list_token	*tmp;

	tmp = NULL;
	tmp = ft_calloc(sizeof(struct s_lx_list_token), 1);
	tmp->next = NULL;
	tmp->str = str;
	tmp->token = token;
	sh_info->lx_ls_token->next = tmp;
	sh_info->lx_ls_token = sh_info->lx_ls_token->next;
}

static void	lx_create_list(t_shell_info *sh_info, char *str, char token)
{
	sh_info->lx_ls_token = ft_calloc(sizeof(struct s_lx_list_token), 1);
	sh_info->lx_ls_token->next = NULL;
	sh_info->lx_ls_token->str = str;
	sh_info->lx_ls_token->token = token;
	sh_info->lx_ls_token_h = sh_info->lx_ls_token;
}

void	lx_create_or_insert(t_shell_info *sh_info, char *str, char token)
{
	if (sh_info->lx_ls_token == NULL)
		lx_create_list(sh_info, str, token);
	else
		lx_insert_list(sh_info, str, token);
}
