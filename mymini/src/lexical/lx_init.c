/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:17:04 by afalconi          #+#    #+#             */
/*   Updated: 2023/11/30 16:09:43 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// vedo se sono messe bene le redirection possono essere
// accettate solo se hanno effettivamente qualcosa a destra
static void	lx_redirections(t_shell_info *sh_info, int i)
{
	if (sh_info->input[i] == '>' || sh_info->input[i] == '<')
	{
		if (sh_info->input[i] == '>' && sh_info->input[i + 1] == '>')
			i++;
		if (sh_info->input[i] == '<' && sh_info->input[i + 1] == '<')
			i++;
		while (sh_info->input[++i])
		{
			if (sh_info->input[i] == '>' || sh_info->input[i] == '<')
				sh_info->lx_error = 1;
			if (sh_info->input[i] != ' ' || sh_info->input[i] == '>'
				|| sh_info->input[i] == '<')
				return ;
		}
		sh_info->lx_error = 1;
	}
}

static int	lx_complete_quotes(t_shell_info *sh_info, char quotes, int i)
{
	char	*str;
	char	*complite;

	str = NULL;
	complite = ft_strdup("\n");
	g_for_sig = 1;
	while ((ft_count_char(str, quotes) % 2 == 0
			|| ft_count_char(str, quotes) == 0) && g_for_sig != 3)
	{
		str = readline("quote> ");
		if (!str)
		{
			sh_info->lx_error = 2;
			break ;
		}
		lx_free_and_join(complite, str);
	}
	lx_free_and_join(sh_info->input, complite);
	if (sh_info->lx_error == 2 || g_for_sig == 3)
		return (-1);
	while (sh_info->input[i] != quotes)
		i ++;
	return (i);
}

// controllo se si lasciano le virgolette sia singole che doppie aperte
void	lx_check_quotes(t_shell_info *sh_info, int *i)
{
	char	sing_doub_q;

	sing_doub_q = 0;
	if (sh_info->input[*i] == 39 || sh_info->input[*i] == 34)
	{
		sing_doub_q = sh_info->input[*i];
		*i = *i + 1;
		while (1)
		{
			if (sh_info->input[*i] == sing_doub_q)
				break ;
			if (!sh_info->input[*i])
			{
				*i = lx_complete_quotes(sh_info, sing_doub_q, *i);
				sing_doub_q = 0;
				break ;
			}
			*i = *i + 1;
		}
	}
}

void	lx_check_subsh(t_shell_info *sh_info, int i)
{
	static int	ck;

	if (i == -42)
	{
		ck = 0;
		return ;
	}
	if (sh_info->input[i] == '(')
	{
		while (sh_info->input[i] != ')' || ck == i)
		{
			if (!sh_info->input[i])
			{
				sh_info->lx_error = 1;
				break ;
			}
			i ++;
		}
		ck = i;
	}
}

// il cuore del ft_lexical
void	ft_lexical(t_shell_info *sh_info)
{
	int	i;

	i = -1;
	while (sh_info->input[++i])
	{
		lx_check_quotes(sh_info, &i);
		if (sh_info->lx_error == 2 || g_for_sig == 3)
		{
			if (g_for_sig == 3)
				sh_info->last_exit = 130;
			return ;
		}
		lx_check_subsh(sh_info, i);
		lx_redirections(sh_info, i);
	}
	lx_check_subsh(NULL, -42);
	g_for_sig = 0;
	lx_ck_is_empty(sh_info);
	if (sh_info->is_emty == 1)
		return ;
	lx_list_token(sh_info);
}
