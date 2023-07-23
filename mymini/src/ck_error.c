/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:13:45 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/23 15:31:27 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	re_init_val(t_shell_info *sh_info)
{
	sh_info->lx_error = 0;
}

void	print_error(t_shell_info *sh_info)
{
	if (sh_info->lx_error == 1)
		printf("error: lexical error\n");
}

void	ck_error(t_shell_info *sh_info)
{
	print_error(sh_info);
	re_init_val(sh_info);
}
