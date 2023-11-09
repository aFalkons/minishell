/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 23:47:50 by matteo            #+#    #+#             */
/*   Updated: 2023/11/07 18:09:03 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	bl_exit(char **split, int argc, int stat)
{
	int	num_error;

	num_error = 0;
	if (argc == 1)
		ft_exit(1, "exit", stat);
	else
	{
		ft_check_exit_error(split);
		num_error = ft_atoi(split[1]);
		if (argc == 2)
		{
			if (num_error > 256)
			{
				num_error = num_error % 256;
				ft_free_array(split);
				ft_exit(2, "exit", num_error);
			}
			ft_free_array(split);
			ft_exit(2, "exit", num_error);
		}
		else
			printf("exit\nbash: exit: too many arguments\n");
	}
}

void	ft_check_exit_error(char **split)
{
	if (ft_isdigit_str(split[1]) == false)
	{
		write(2, "exit\n", 5);
		write(2, "minishell: exit: ", 17);
		write(2, split[1], ft_strlen(split[1]));
		write(2, ": numeric argument required\n", 28);
		ft_free_array(split);
		exit(2);
	}
}
