/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:13:39 by misidori          #+#    #+#             */
/*   Updated: 2023/11/30 12:10:12 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bl_echo(char **arr_cmd_arg, int argc)
{
	bool	only_n;
	int		i;
	int		j;

	only_n = true;
	i = 0;
	j = 1;
	while (arr_cmd_arg[++i])
		ft_echo_check_quotes(arr_cmd_arg[i]);
	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		while (arr_cmd_arg[1][j])
		{
			if (arr_cmd_arg[1][j] != 'n')
			{
				only_n = false;
				break ;
			}
			j++;
		}
		ft_echo(arr_cmd_arg, only_n);
	}
}

void	ft_echo(char **arr_cmd_arg, bool only_n)
{
	if (ft_strncmp(arr_cmd_arg[1], "-n", 2) == 0 && only_n == true)
		ft_echo_n_option(arr_cmd_arg);
	else
		ft_echo_no_options(arr_cmd_arg);
}

void	ft_echo_check_quotes(char *arg)
{
	int	n_single_quote;
	int	n_double_quotes;
	int	index_single_quote;
	int	index_double_quotes;

	n_single_quote = ft_count_char(arg, '\'');
	n_double_quotes = ft_count_char(arg, '\"');
	index_double_quotes = ft_find_char_index_str(arg, '\"');
	index_single_quote = ft_find_char_index_str(arg, '\'');
	if (n_single_quote > 0 && n_double_quotes == 0)
		ft_remove_char_in_str(arg, '\'');
	if (n_double_quotes > 0 && n_single_quote == 0)
		ft_remove_char_in_str(arg, '\"');
	if (index_single_quote > index_double_quotes)
		ft_remove_char_in_str(arg, '\"');
	if (index_double_quotes > index_single_quote)
		ft_remove_char_in_str(arg, '\'');
}

int	ft_echo_n_option(char **arr_cmd_arg)
{
	int	i;

	i = 1;
	while (arr_cmd_arg[i + 1])
	{
		if (arr_cmd_arg[i + 2] != NULL)
		{
			printf("%s ", arr_cmd_arg[i + 1]);
			i++;
		}
		else
		{
			printf("%s", arr_cmd_arg[i + 1]);
			break ;
		}
	}
	return (0);
}

int	ft_echo_no_options(char **arr_cmd_arg)
{
	int	i;

	i = 1;
	while (arr_cmd_arg[i])
	{
		if (arr_cmd_arg[i + 1] != NULL)
		{
			printf("%s ", arr_cmd_arg[i]);
			i++;
		}
		else
		{
			printf("%s\n", arr_cmd_arg[i]);
			break ;
		}
	}
	return (0);
}
