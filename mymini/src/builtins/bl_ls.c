/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <matteo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:13:10 by misidori          #+#    #+#             */
/*   Updated: 2023/09/29 00:55:55 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bl_ls(void)
{
	t_program	program;
	char		**list_of_files;

	list_of_files = ft_get_list_files(&program);
	if (!list_of_files)
		return (-1);
	ft_print_array(list_of_files);
	ft_free_array(list_of_files);
	return (1);
}
