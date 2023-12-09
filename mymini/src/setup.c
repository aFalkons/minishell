/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:07:42 by afalconi          #+#    #+#             */
/*   Updated: 2023/12/01 21:26:27 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler_sig(int sig)
{
	if (sig == SIGINT)
	{
		if (g_for_sig == 0)
		{
			write(1, "\n", 1);
			rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
		}
		else if (g_for_sig == 1)
		{
			write(1, "\npremi pure invio <3\n", 1);
			rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
			g_for_sig = 3;
		}
	}
	else if (sig == SIGQUIT)
	{
		printf("\r");
		rl_on_new_line();
		rl_redisplay();
	}
}

static t_list_var_env	*ft_fill_the_list_with_env(char **env,
				t_shell_info *sh_info)
{
	int		i;
	int		index_egual_sign;
	char	*name;
	char	*value;

	i = 0;
	sh_info->var->node = NULL;
	while (env[i])
	{
		index_egual_sign = ft_find_char_index_str(env[i], '=');
		name = ft_substr(env[i], 0, index_egual_sign);
		value = ft_substr(env[i], index_egual_sign + 1, ft_strlen(env[i]));
		ft_add_node_in_list(&sh_info->var->node, name, value);
		free(name);
		free(value);
		i++;
	}
	return (sh_info->var);
}

static void	ft_init_var_newcmd2(t_shell_info *sh_info)
{
	char	*tmp;
	int		i;
	int		sh_level;

	i = -1;
	sh_info->is_emty = 0;
	sh_info->stdin_flag = 0;
	sh_info->stdout_flag = 0;
	sh_info->pid_flag = 1;
	sh_info->pid = 2;
	sh_info->sub_level = 1;
	sh_info->pipe_flag = 0;
	while (sh_info->env[++i])
	{
		if (ft_cmp_len_and_str(sh_info->env[i], "SHLVL=", 6) == 1)
			break ;
	}
	tmp = ft_strndup(sh_info->env[i], 6, ft_strlen(sh_info->env[i]));
	sh_level = ft_atoi(tmp);
	free(tmp);
	free(sh_info->env[i]);
	sh_level ++;
	tmp = ft_itoa(sh_level);
	sh_info->env[i] = ft_strjoin("SHLVL=", tmp);
	free(tmp);
}

//inizializzazione delle variabili d'ambiente
void	ft_init_variables(char **env, t_shell_info *sh_info)
{
	sh_info->last_exit = 0;
	g_for_sig = 0;
	sh_info->flag_hdoc_sig = 0;
	sh_info->complete_quote = 0;
	sh_info->lx_error = 0;
	sh_info->env = ft_copy_array(env, ft_get_size_array(env));
	sh_info->input = NULL;
	sh_info->pwd = 0;
	sh_info->lx_ls_token = NULL;
	sh_info->lx_ls_token_h = NULL;
	sh_info->complite = NULL;
	sh_info->node = NULL;
	sh_info->node_h = NULL;
	sh_info->fd_stdout = dup(1);
	sh_info->fd_stdin = dup(0);
	signal(SIGQUIT, &handler_sig);
	signal(SIGINT, &handler_sig);
	sh_info->var = (t_list_var_env *) malloc(sizeof(t_list_var_env));
	sh_info->var = ft_fill_the_list_with_env(env, sh_info);
	sh_info->var->head = ft_get_list_head(sh_info->var);
	sh_info->var->tail = ft_get_list_tail(sh_info->var);
	ft_init_var_newcmd2(sh_info);
	ft_add_last_exit_to_array(sh_info);
}

void	ft_init_var_newcmd(t_shell_info *sh_info, char **env)
{
	(void)env;
	g_for_sig = 0;
	sh_info->flag_hdoc_sig = 0;
	sh_info->complete_quote = 0;
	sh_info->lx_error = 0;
	sh_info->input = NULL;
	sh_info->pwd = 0;
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
	sh_info->stdin_flag = 0;
	sh_info->stdout_flag = 0;
	sh_info->pid_flag = 1;
	sh_info->pid = 2;
	sh_info->sub_level = 1;
	sh_info->pipe_flag = 0;
	sh_info->exit_stat = 0;
}
