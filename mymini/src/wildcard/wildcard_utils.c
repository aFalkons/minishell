/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:11:53 by misidori          #+#    #+#             */
/*   Updated: 2023/11/27 22:41:31 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_match_and_replace(t_wildcard *star, char **arr_cmd_arg)
{
	star->j = ft_skip_invisible_files(star->list_of_files, star->j);
	if (ft_is_match(star->list_of_files[star->j], arr_cmd_arg[star->i]) == 1)
	{
		if (star->count == 0)
		{
			free(star->new_array[star->i]);
			star->new_array[star->i] = ft_strdup(star->list_of_files[star->j]);
		}
		else
		{
			star->temp = ft_add_string(star->new_array, &star->size_array,
					star->list_of_files[star->j]);
			if (star->temp != NULL)
			{
				star->new_array = star->temp;
			}
		}
		star->count++;
	}
}

int	ft_skip_invisible_files(char **list_of_files, int j)
{
	while ((j < ft_get_size_array(list_of_files) && (list_of_files[j][0] == '.'
			|| (list_of_files[j][0] == '.' && list_of_files[j][1] == '.'))))
	{
		j++;
	}
	return (j);
}

bool	ft_is_match(char *name_in_folder, char *input_str)
{
	t_index_match	index;
	int				return_match;

	index.name_in_folder = 0;
	index.input_str = 0;
	index.star = -1;
	index.match = 0;
	if (ft_count_char(input_str, '*') == 0)
	{
		return_match = ft_strcmp(name_in_folder, input_str);
		if (return_match == 0)
			return (true);
	}
	else
	{
		ft_find_match(&index, name_in_folder, input_str);
		while (index.input_str < ft_strlen(input_str)
			&& input_str[index.input_str] == '*')
			index.input_str++;
		if (index.input_str == ft_strlen(input_str))
			return (true);
	}
	return (false);
}

int	ft_find_match(t_index_match	*ind, char *name_in_folder, char *input_str)
{
	while (ind->name_in_folder < ft_strlen(name_in_folder))
	{
		if (ind->input_str < ft_strlen(input_str)
			&& input_str[ind->input_str] == name_in_folder[ind->name_in_folder])
		{
			ind->name_in_folder++;
			ind->input_str++;
		}
		else if (ind->input_str < ft_strlen(input_str)
			&& input_str[ind->input_str] == '*')
		{
			ind->star = ind->input_str;
			ind->match = ind->name_in_folder;
			ind->input_str++;
		}
		else if (ind->star != -1)
		{
			ind->input_str = ind->star + 1;
			ind->match++;
			ind->name_in_folder = ind->match;
		}
		else
			return (0);
	}
	return (1);
}
