/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:43:15 by matteo            #+#    #+#             */
/*   Updated: 2023/10/11 16:38:00 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bl_env(char **env, int argc, char **split)
{
	if (argc == 1)
	{
		ft_print_array(env);
		return (1);
	}
	else
	{
		printf("env: %s: No such file or directory\n", split[1]);
		return (-1);
	}
}
