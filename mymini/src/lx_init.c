/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <matteo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:17:04 by afalconi          #+#    #+#             */
/*   Updated: 2023/08/01 13:39:16 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// vedo se sono messe bene le redirection possono essere accettate solo se hanno effettivamente qualcosa a destra
static void	lx_redirections(t_shell_info *sh_info, int i)
{
	// int	flag;

	// flag = 0;
	if (sh_info->input[i] == '>' || sh_info->input[i] == '<')
	{
		if (sh_info->input[i] == '>' && sh_info->input[i + 1] == '>')
			i++;
		if (sh_info->input[i] == '<' && sh_info->input[i + 1] == '<')
			i++;
		while(sh_info->input[++i])
		{
			if (sh_info->input[i] == '>' || sh_info->input[i] == '<')
				sh_info->lx_error = 1;
			if (sh_info->input[i] != ' ' || sh_info->input[i] == '>' || sh_info->input[i] == '<')
				return ;
		}
		sh_info->lx_error = 1;
	}
}

// controllo se ci sono due token uno dopo l'altro per la maggior parte dei token non si puo fare come per | && ||
static void	lx_double_tokens(t_shell_info *sh_info, int i)
{
	static int	flag;

	if (sh_info->input[i] == '|' || sh_info->input[i] == '&')
	{
		if (sh_info->input[i + 1] == '|' && sh_info->input[i] == '|')
			return ;
		if (sh_info->input[i + 1] == '&' && sh_info->input[i] == '&')
			return ;
		if (flag == 1)
			sh_info->lx_error = 1;
		flag = 1;
	}
	else if (sh_info->input[i] != ' ')
	{
		flag = 0;
	}
}

// controllo se si lasciano le virgolette sia singole che doppie aperte
static void	lx_check_quotes(t_shell_info *sh_info, int *i)
{
	char	sing_doub_q;

	sing_doub_q = 0;
	if (sh_info->input[*i] == 39 || sh_info->input[*i] == 34)
	{
		sing_doub_q = sh_info->input[*i];
		*i = *i + 1;
		while(sh_info->input[*i] != sing_doub_q)
		{
			*i = *i + 1;
			if (!sh_info->input[*i])
			{
				sh_info->lx_error = 1;
				break;
			}
		}
	}
}

// il cuore del ft_lexical
void	ft_lexical(t_shell_info *sh_info)
{
	int	i;

	i = -1;
	while(sh_info->input[++i])
	{
		lx_check_quotes(sh_info, &i);
		lx_double_tokens(sh_info, i);
		lx_redirections(sh_info, i);
	}
	lx_list_token(sh_info);
}
