/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_create_ls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:16:43 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/28 15:07:21 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	lx_insert_list(t_shell_info *sh_info)
{
	sh_info->lx_ls_token->next = ft_calloc(sizeof(sh_info->lx_ls_token), 1);
	sh_info->lx_ls_token = sh_info->lx_ls_token->next;
	sh_info->lx_ls_token->next = NULL;
	sh_info->lx_ls_token->str = 0;
	sh_info->lx_ls_token->token = 0;
}

static void	lx_create_list(t_shell_info *sh_info)
{
	sh_info->lx_ls_token = ft_calloc(sizeof(sh_info->lx_ls_token), 1);
	sh_info->lx_ls_token->next = NULL;
	sh_info->lx_ls_token->str = 0;
	sh_info->lx_ls_token->token = 0;
	sh_info->lx_ls_token_h = sh_info->lx_ls_token;
}

void 	lx_create_or_insert(t_shell_info *sh_info)
{
	if (sh_info->lx_ls_token == NULL)
		lx_create_list(sh_info);
	else
		lx_insert_list(sh_info);
}
