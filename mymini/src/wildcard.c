/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:57:14 by matteo            #+#    #+#             */
/*   Updated: 2023/11/15 21:24:10 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**add_string(char **array, int *size, const char *string)
{
	char	**new_array;

	new_array = ft_realloc(array, (*size + 2) * sizeof(char *));
	if (new_array == NULL)
		return (NULL);
	new_array[*size] = malloc(strlen(string) + 1);
	if (new_array[*size] == NULL)
		return (NULL);
	strcpy(new_array[*size], string);
	(*size)++;
	new_array[*size] = NULL;
	return (new_array);
}



static int	ft_find_match(t_index_match	*ind,
	char *name_in_folder, char *input_str)
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

static bool	ft_is_match(char *name_in_folder, char *input_str)
{
	t_index_match	index;

	index.name_in_folder = 0;
	index.input_str = 0;
	index.star = -1;
	index.match = 0;
	ft_find_match(&index, name_in_folder, input_str);
	while (index.input_str < ft_strlen(input_str)
		&& input_str[index.input_str] == '*')
		index.input_str++;
	if (index.input_str == ft_strlen(input_str))
		return (true);
	return (false);
}

static void	ft_swap_strings(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	ft_sort_array_ascend_order(char **arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strcmp(arr[j], arr[j + 1]) > 0)
			{
				ft_swap_strings(&arr[j], &arr[j + 1]);
			}
			j++;
		}
		i++;
	}
}

void	ft_copy_array(char ***new_array, char **original_array, int size_array)
{
	int	i;

	i = 0;
	*new_array = ft_calloc(sizeof(char *) * (size_array + 1), 1);
	if (!*new_array)
		return ;
	while (original_array[i])
	{
		(*new_array)[i] = ft_strdup(original_array[i]);
		i++;
	}
	(*new_array)[i] = 0;
}

char	**wc_star(char **arr_cmd_arg)
{
	t_program	program;
	char		**list_of_files;
	char		**new_array;
	int			i;
	int			j;
	int			count;
	int			size_array;

	new_array = NULL;
	i = 1;
	j = 0;
	count = 0;
	size_array = ft_get_size_array(arr_cmd_arg);
	ft_copy_array(&new_array, arr_cmd_arg, size_array);
	if (size_array > 1)
	{
		list_of_files = ft_get_list_files(&program);
		ft_sort_array_ascend_order(list_of_files,
			ft_get_size_array(list_of_files));
		while (arr_cmd_arg[i])
		{
			j = 0;
			while (list_of_files[j])
			{
				while ((j < ft_get_size_array(list_of_files)
					&& (list_of_files[j][0] == '.'
					|| (list_of_files[j][0] == '.'
					&& list_of_files[j][1] == '.'))))
					j++;
				if (ft_is_match(list_of_files[j], arr_cmd_arg[i]) == 1)
				{
					if (count == 0)
						new_array[i] = ft_strdup(list_of_files[j]);
					else
						new_array = add_string(new_array, &size_array, list_of_files[j]);
					count++;
				}
				j++;
			}
			i++;
		}
		ft_free_array(list_of_files);
	}
	if (count > 0)
	{
		ft_free_array(arr_cmd_arg);
		return (new_array);
	}
	else
		return (arr_cmd_arg);
}
