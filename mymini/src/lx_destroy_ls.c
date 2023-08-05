/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_destroy_ls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 00:42:57 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/05 06:10:28 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lx_free_ls(t_shell_info *sh_info)
{
	int	i;
	struct s_lx_list_token *tmp;

	if (sh_info->lx_ls_token_h == NULL)
		return ;
	i = -1;
	tmp = sh_info->lx_ls_token_h;
	while (tmp != NULL)
	{
		sh_info->lx_ls_token_h = sh_info->lx_ls_token_h->next;
		free(tmp->str);
		free(tmp);
		tmp = sh_info->lx_ls_token_h;
	}
	sh_info->lx_ls_token_h = NULL;
	sh_info->lx_ls_token = NULL;
}
