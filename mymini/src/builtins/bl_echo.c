/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:13:39 by misidori          #+#    #+#             */
/*   Updated: 2023/10/11 16:37:55 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bl_echo(char **split, int argc)
{
	int		j;
	bool	only_n;

	j = 1;
	only_n = true;
	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		while (split[1][j])
		{
			if (split[1][j] != 'n')
			{
				only_n = false;
				break ;
			}
			j++;
		}
		if (ft_strncmp(split[1], "-n", 2) == 0 && only_n == true)
			ft_echo_n_option(split);
		else
			ft_echo_no_options(split);
	}
}

int	ft_echo_n_option(char **split)
{
	int	i;

	i = 1;
	while (split[i + 1])
	{
		if (split[i + 2] != NULL)
		{
			printf("%s ", split[i + 1]);
			i++;
		}
		else
		{
			printf("%s", split[i + 1]);
			break ;
		}
	}
	return (0);
}

int	ft_echo_no_options(char **split)
{
	int	i;

	i = 1;
	while (split[i])
	{
		if (split[i + 1] != NULL)
		{
			printf("%s ", split[i]);
			i++;
		}
		else
		{
			printf("%s\n", split[i]);
			break ;
		}
	}
	return (0);
}
