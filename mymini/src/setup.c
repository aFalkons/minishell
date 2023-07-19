/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:07:42 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/19 13:52:30 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//inizializzazione delle variabili d'ambiente
void	init_val(char **env, t_shell_info *sh_info)
{
	sh_info->env = env;
	sh_info->input = NULL;
	sh_info->pwd = 0;
}
