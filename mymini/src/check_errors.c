/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_lexical_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:13:45 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/28 14:23:41 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	ft_check_args(int argc, char **argv)
{
	if (argc != 1)
	{
		ft_print_message("Error: too many arguments", 2);
		exit(1);
	}
	(void) argv;
}
void	ft_check_lexical_error(t_shell_info *sh_info)
{
	if (sh_info->lx_error == 1)
		ft_print_message("Error: lexical error", 2);
	sh_info->lx_error = 0;
}
