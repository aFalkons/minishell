/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_last_exit_to_array.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:49:18 by misidori          #+#    #+#             */
/*   Updated: 2023/12/01 22:20:40 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_last_exit_to_array(t_shell_info *sh_info)
{
	char	**question_mark_input;
	char	*temp;

	temp = ft_itoa(sh_info->last_exit);
	question_mark_input = (char **) ft_calloc(3, sizeof(char *));
	question_mark_input[0] = ft_strdup("export");
	question_mark_input[1] = ft_strjoin("?=", temp);
	free(temp);
	question_mark_input[2] = NULL;
	bl_export(sh_info, sh_info->env, 2, question_mark_input);
	free(question_mark_input[0]);
	free(question_mark_input[1]);
	free(question_mark_input[2]);
	free(question_mark_input);
}
