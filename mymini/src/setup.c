/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:07:42 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/12 03:18:14 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//inizializzazione delle variabili d'ambiente
void	ft_init_variables(char **env, t_shell_info *sh_info)
{
	sh_info->lx_error = 0;
	sh_info->env = env;
	sh_info->input = NULL;
	sh_info->pwd = 0;
	sh_info->lx_ls_token = NULL;
	sh_info->lx_ls_token_h = NULL;
	sh_info->complite = NULL;
	sh_info->node = NULL;
	sh_info->node_h = NULL;
	sh_info->node = ft_calloc(sizeof(struct s_minitree), 1);
	sh_info->node_h = sh_info->node;
}

void	ft_init_var_newcmd(t_shell_info *sh_info)
{
	sh_info->input = NULL;
	sh_info->pwd = 0;
	sh_info->lx_ls_token = NULL;
	sh_info->lx_ls_token_h = NULL;
	sh_info->complite = NULL;
	sh_info->node = NULL;
	sh_info->node_h = NULL;
	sh_info->node = ft_calloc(sizeof(struct s_minitree), 1);
	sh_info->node_h = sh_info->node;
}
