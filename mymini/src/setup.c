/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:07:42 by afalconi          #+#    #+#             */
/*   Updated: 2023/09/10 19:31:17 by afalconi         ###   ########.fr       */
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
	sh_info->is_emty = 0;
	sh_info->node = ft_calloc(sizeof(struct s_minitree), 1);
	sh_info->node->env = NULL;
	sh_info->node->exit_status = 0;
	sh_info->node->token = NULL;
	sh_info->node->subsh = NULL;
	sh_info->node->next = NULL;
	sh_info->node_h = sh_info->node;
	sh_info->fd_stdin = 0;
	sh_info->fd_stdout = 0;
	sh_info->stdin_flag= 0;
	sh_info->stdout_flag = 0;
	sh_info->pid_flag = 1;
}

void	ft_init_var_newcmd(t_shell_info *sh_info)
{
	sh_info->pid_flag = 1;
	sh_info->input = NULL;
	sh_info->pwd = 0;
	sh_info->is_emty = 0;
	sh_info->lx_ls_token = NULL;
	sh_info->lx_ls_token_h = NULL;
	sh_info->complite = NULL;
	sh_info->node = NULL;
	sh_info->node_h = NULL;
	sh_info->node = ft_calloc(sizeof(struct s_minitree), 1);
	sh_info->node_h = sh_info->node;
	sh_info->lx_error = 0;
}
