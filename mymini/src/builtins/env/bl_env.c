/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:43:15 by matteo            #+#    #+#             */
/*   Updated: 2023/12/01 22:25:05 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_print_array_env(char **array_strings)
{
	int	i;

	i = 0;
	if (!array_strings)
		return (-1);
	while (array_strings[i])
	{
		if (array_strings[i][0] != '?')
			printf("%s\n", array_strings[i]);
		i++;
	}
	return (1);
}

int	bl_env(char **env, int argc, char **arr_cmd_arg)
{
	if (argc == 1)
	{
		ft_print_array_env(env);
		return (1);
	}
	else
	{
		printf("env: %s: No such file or directory\n", arr_cmd_arg[1]);
		return (-1);
	}
}
