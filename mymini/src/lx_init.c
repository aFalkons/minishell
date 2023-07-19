/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:17:04 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/19 18:57:27 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// controllo se si lasciano le virgolette sia singole che doppie aperte
void	lx_sing_doble_q(t_shell_info *sh_info)
{
	int	singol_q;
	int	doble_q;
	int	i;

	singol_q = 0;
	doble_q = 0;
	i = -1;
	while(sh_info->input[++i])
	{
		if (sh_info->input[i] == 39 && doble_q == 0 && singol_q == 0)
			singol_q = 1;
		else if (sh_info->input[i] == 34 && singol_q == 0 && doble_q == 0)
			doble_q = 1;
		else if (sh_info->input[i] == 39 && singol_q == 1 && doble_q == 0)
			singol_q = 0;
		else if (sh_info->input[i] == 34 && singol_q == 0 && doble_q == 1)
			doble_q = 0;
	}
	if (doble_q == 1 || singol_q == 1)
		sh_info->error = 1;
}

// il cuore el lexical
void	lexical(t_shell_info *sh_info)
{
	lx_sing_doble_q(sh_info);
}
