/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 23:47:50 by matteo            #+#    #+#             */
/*   Updated: 2023/12/01 19:19:45 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_free_list(t_list_var_env *var)
{
	t_node	*current;
	t_node	*next;

	current = var->node;
	while (current != NULL)
	{
		next = current->next;
		ft_free_node(current);
		free(current);
		current = next;
	}
}

int	ft_exit_with_args(char **arr_cmd_arg, int argc)
{
	int	num_error;

	num_error = 0;
	ft_check_exit_error(arr_cmd_arg);
	num_error = ft_atoi(arr_cmd_arg[1]);
	if (argc == 2)
	{
		if (num_error > 256)
		{
			num_error = num_error % 256;
			ft_free_array(arr_cmd_arg);
			ft_exit(2, "exit", num_error);
		}
		ft_free_array(arr_cmd_arg);
		ft_exit(2, "exit", num_error);
	}
	else
		printf("exit\nminishell: exit: too many arguments\n");
	return (-1);
}

int	bl_exit(t_shell_info *sh_info, char **arr_cmd_arg, int argc, int stat)
{
	if (argc == 1)
	{
		ps_free_tree_recursiv(sh_info->node_h);
		ft_free_array(sh_info->env);
		ft_free_array(arr_cmd_arg);
		ft_exit(1, "exit", stat);
	}
	else
	{
		ft_exit_with_args(arr_cmd_arg, argc);
	}
	return (-1);
}

void	ft_check_exit_error(char **arr_cmd_arg)
{
	if (ft_isdigit_str(arr_cmd_arg[1]) == false)
	{
		write(2, "exit\n", 5);
		write(2, "minishell: exit: ", 17);
		write(2, arr_cmd_arg[1], ft_strlen(arr_cmd_arg[1]));
		write(2, ": numeric argument required\n", 28);
		ft_free_array(arr_cmd_arg);
		exit(2);
	}
}
