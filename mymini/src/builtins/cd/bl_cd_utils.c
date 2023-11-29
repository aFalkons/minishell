/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:45:16 by misidori          #+#    #+#             */
/*   Updated: 2023/11/24 00:36:35 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_cd_check_quotes(char *arg)
{
	int	n_single_quote;
	int	n_double_quotes;
	int	total_quotes;
	int	index_double_quotes;
	int	result;

	n_single_quote = ft_count_char(arg, '\'');
	n_double_quotes = ft_count_char(arg, '\"');
	total_quotes = n_single_quote + n_double_quotes;
	index_double_quotes = ft_find_char_index_str(arg, '\"');
	if (total_quotes > 0)
	{
		result = ft_remove_quotes(arg, n_single_quote, n_double_quotes,
				index_double_quotes);
		if (result == 1)
			return (1);
		else if (result == -1)
			return (-1);
	}
	return (1);
}

int	ft_remove_quotes(char *arg, int n_single_quote, int n_double_quotes,
	int index_double_quotes)
{
	int	index_single_quote;

	index_single_quote = ft_find_char_index_str(arg, '\'');
	if (n_single_quote > 0 && n_double_quotes == 0)
	{
		ft_remove_char_in_str(arg, '\'');
		return (1);
	}
	if (n_double_quotes > 0 && n_single_quote == 0)
	{
		ft_remove_char_in_str(arg, '\"');
		return (1);
	}
	if (index_single_quote > index_double_quotes)
	{
		ft_remove_char_in_str(arg, '\"');
		return (-1);
	}
	if (index_double_quotes > index_single_quote)
	{
		ft_remove_char_in_str(arg, '\'');
		return (-1);
	}
	return (1);
}

char	*ft_get_home(char **env)
{
	char	*home_dir;
	int		i;

	home_dir = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp("HOME=", env[i], 5) == 0)
		{
			home_dir = ft_substr(env[i], 5, ft_strlen(env[i]) - 5);
			break ;
		}
		i++;
	}
	return (home_dir);
}

int	ft_change_folder(char *new_folder, char **split)
{
	if (!split[1])
	{
		if (chdir(new_folder) != 0)
		{
			printf("minishell: cd: %s\n", strerror(errno));
			return (-1);
		}
	}
	else
	{
		if (chdir(new_folder) != 0)
		{
			printf("minishell: cd: %s: %s\n", split[1], strerror(errno));
			return (-1);
		}
	}
	return (1);
}
