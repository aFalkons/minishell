/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:57:14 by matteo            #+#    #+#             */
/*   Updated: 2023/11/27 22:57:43 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**wc_wildcard(char **arr_cmd_arg)
{
	t_program	program;
	t_wildcard	star;

	if (ft_find_char_array(arr_cmd_arg, '*') == -1)
		return (arr_cmd_arg);
	ft_init_wildcard_var(&star, arr_cmd_arg);
	star.list_of_files = ft_get_list_files(&program);
	ft_sort_array_ascend_order(star.list_of_files,
		ft_get_size_array(star.list_of_files));
	while (arr_cmd_arg[++star.i])
	{
		star.j = 0;
		while (star.list_of_files[star.j])
		{
			ft_check_match_and_replace(&star, arr_cmd_arg);
			star.j++;
		}
	}
	ft_free_array(star.list_of_files);
	ft_free_array(arr_cmd_arg);
	return (star.new_array);
}

void	ft_init_wildcard_var(t_wildcard *star, char **arr_cmd_arg)
{
	star->new_array = NULL;
	star->i = 0;
	star->j = 0;
	star->count = 0;
	star->size_array = ft_get_size_array(arr_cmd_arg);
	star->new_array = ft_copy_array(arr_cmd_arg, star->size_array);
}

char	**ft_get_list_files(t_program *program)
{
	char	**list;
	int		i;

	list = NULL;
	list = (char **) ft_calloc(4096 * sizeof(char *), 1);
	if (!list)
		return (NULL);
	i = 0;
	program->dir = opendir(".");
	if (program->dir == NULL)
	{
		perror("opendir");
		return (NULL);
	}
	program->dir_entry = readdir(program->dir);
	while (program->dir_entry != NULL)
	{
		list[i] = ft_strdup(program->dir_entry->d_name);
		i++;
		program->dir_entry = readdir(program->dir);
	}
	closedir(program->dir);
	return (list);
}

void	ft_sort_array_ascend_order(char **arr, int size)
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
