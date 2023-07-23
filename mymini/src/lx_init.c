/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:17:04 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/23 16:26:37 by afalconi         ###   ########.fr       */
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
void	lx_dobble_token(t_shell_info *sh_info, int *i)
{
	static int	flag;

	printf("%c\n", sh_info->input[*i]);
	if (sh_info->input[*i] == '|' || sh_info->input[*i] == '&')
	{
		if (sh_info->input[*i + 1] == '|' && sh_info->input[*i] == '|')
			*i = *i + 1;
		else if (sh_info->input[*i + 1] == '&' && sh_info->input[*i] == '&')
			*i = *i + 1;
		if (flag == 1)
			sh_info->lx_error = 1;
		flag = 1;
	}
	else if (sh_info->input[*i] != ' ')
	{
		flag = 0;
	}
}

// controllo se si lasciano le virgolette sia singole che doppie aperte
int		lx_sing_doble_q(t_shell_info *sh_info, int i, int *flag_sing_q, int *flag_double_q)
{
	static int	singol_q;
	static int	doble_q;

	if (sh_info->input[i] == 39 && doble_q == 0 && singol_q == 0)
		singol_q = 1;
	else if (sh_info->input[i] == 34 && singol_q == 0 && doble_q == 0)
		doble_q = 1;
	else if (sh_info->input[i] == 39 && singol_q == 1 && doble_q == 0)
		singol_q = 0;
	else if (sh_info->input[i] == 34 && singol_q == 0 && doble_q == 1)
		doble_q = 0;
	if (sh_info->input[i] == 39 && doble_q == 0)
		*flag_sing_q = *flag_sing_q + 1;
	if (sh_info->input[i] == 34 && singol_q == 0)
		*flag_double_q =  *flag_double_q + 1;
	if (doble_q == 1 || singol_q == 1)
		return(0);
	return(1);
}

// il cuore el lexical
void	lexical(t_shell_info *sh_info)
{
	int	i;
	int	sing_q;
	int	doble_q;

	i = -1;
	sing_q = 0;
	doble_q = 0;
	while(sh_info->input[++i])
	{
		if (lx_sing_doble_q(sh_info, i, &sing_q, &doble_q) == 1)
		{
			lx_dobble_token(sh_info, &i);
			// lx_redirection(sh_info);
		}
	}
	if (sing_q % 2 != 0 || doble_q % 2 != 0)
		sh_info->lx_error = 1;
}
