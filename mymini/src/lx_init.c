/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:17:04 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/23 19:15:46 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// vedo se sonoo messe bene le redirection
void	lx_redirection(t_shell_info *sh_info)
{
	int i;
	int flag;

	i = -1;
	flag = 0;
	while(sh_info->input[++i])
	{
		if (sh_info->input[i] == '>')
		{

		}
	}
}

// controllo se ci sono due token uno dopo l'altro per la maggior parte dei token non si puo fare come per | && ||
static void	lx_dobble_token(t_shell_info *sh_info, int i)
{
	static int	flag;

	if (sh_info->input[i] == '|' || sh_info->input[i] == '&')
	{
		if ()
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
static void	lx_sing_doble_q(t_shell_info *sh_info, int *i)
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

// il cuore el lexical
void	lexical(t_shell_info *sh_info)
{
	int	i;

	i = -1;
	while(sh_info->input[++i])
	{
		lx_sing_doble_q(sh_info, &i);
		lx_dobble_token(sh_info, i);
	}
}
