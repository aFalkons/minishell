/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:17:04 by afalconi          #+#    #+#             */
/*   Updated: 2023/10/04 17:27:50 by afalconi         ###   ########.fr       */
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

static int	complete_quotes(t_shell_info *sh_info, char quotes, int i)
{
	char	*str;
	char	*complite;

	str = NULL;
	complite = NULL;
	while (ft_contchar(str, quotes) % 2 == 0 || ft_contchar(str, quotes) == 0)
	{
		complite = ft_strjoin(complite, "\n");
		str = readline("quote> ");
		complite = ft_strjoin(complite, str);
	}
	sh_info->input = ft_strjoin(sh_info->input, complite);
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
			if (sh_info->input[*i] == sing_doub_q && sh_info->input[*i - 1] != '\\')
				break;
			if (!sh_info->input[*i])
			{
				*i = complete_quotes(sh_info, sing_doub_q, *i);
				sing_doub_q = 0;
				break ;
			}
			*i = *i + 1;
		}
	}
}

void	lx_check_subsh(t_shell_info *sh_info, int i)
{
	if (sh_info->input[i] == '(')
	{
		while (sh_info->input[i] != ')')
		{
			if (!sh_info->input[i])
			{
				sh_info->lx_error = 1;
				break ;
			}
			i ++;
		}
	}
}

// il cuore del ft_lexical
void	ft_lexical(t_shell_info *sh_info)
{
	int	i;
	int	flag;

	i = -1;
	flag = 1;
	while (sh_info->input[++i])
	{
		lx_check_quotes(sh_info, &i);
		lx_check_subsh(sh_info, i);
		lx_redirections(sh_info, i);
	}
	i = -1;
	while(sh_info->input[++i])
	{
		if (sh_info->input[i] != ' ')
			flag = 0;
	}
	sh_info->is_emty = flag;
	if (sh_info->is_emty == 1)
		return;
	lx_list_token(sh_info);
}
