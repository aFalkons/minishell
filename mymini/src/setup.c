/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:07:42 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/28 20:40:31 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//inizializzazione delle variabili d'ambiente
void	ft_init_variables(char **env, t_shell_info *sh_info)
{
	sh_info->env = env;
	sh_info->input = NULL;
	sh_info->pwd = 0;
}
