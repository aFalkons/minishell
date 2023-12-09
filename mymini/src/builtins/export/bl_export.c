/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:17:08 by matteo            #+#    #+#             */
/*   Updated: 2023/12/01 21:44:40 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	bl_export(t_shell_info *sh_info, char **env, int argc, char **arr_cmd_arg)
{
	t_export_var	exp_var;

	exp_var.i = 0;
	exp_var.return_value = 1;
	if (argc == 1)
	{
		ft_export_without_args(sh_info);
		return (1);
	}
	if (ft_check_exclamation_mark(arr_cmd_arg) == -1)
		return (-1);
	while (arr_cmd_arg[++exp_var.i])
	{
		if (ft_export_with_args(sh_info, env, arr_cmd_arg, &exp_var) == -1)
			return (exp_var.return_value);
	}
	return (exp_var.return_value);
}

void	ft_export_without_args(t_shell_info *sh_info)
{
	ft_sort_list(&sh_info->var->head);
	ft_print_list_export(sh_info->var);
}

int	ft_export_with_args(t_shell_info *sh_info, char **env,
	char **arr_cmd_arg, t_export_var *exp_var)
{
	exp_var->index_egual_sign = ft_find_char_index_str(arr_cmd_arg[exp_var->i],
			'=');
	if (exp_var->index_egual_sign > -1)
	{
		if (ft_egual_sign_exists(sh_info, env, arr_cmd_arg[exp_var->i],
				exp_var->index_egual_sign) == -1)
			exp_var->return_value = -1;
	}
	else
	{
		if (ft_add_arg_without_egual_sign(sh_info,
				arr_cmd_arg[exp_var->i]) == -1)
			exp_var->return_value = -1;
	}
	return (exp_var->return_value);
}

int	ft_egual_sign_exists(t_shell_info *sh_info, char **env, char *arg,
	int index_egual_sign)
{
	char	*value;
	int		return_value;

	if (arg[0] == '=')
	{
		printf("minishell: export: `%s': not a valid identifier\n", arg);
		return (-1);
	}
	return_value = 1;
	value = ft_substr(arg, (index_egual_sign + 1), ft_strlen(arg));
	if (arg[index_egual_sign - 1] == '+')
	{
		if (ft_arg_has_plus_sign(sh_info, env, arg, value) == -1)
			return_value = -1;
	}
	else
		if (ft_arg_has_egual_sign(sh_info, env, arg, value) == -1)
			return_value = -1;
	free(value);
	return (return_value);
}

int	ft_add_arg_without_egual_sign(t_shell_info *sh_info, char *arg)
{
	int	return_value;

	return_value = 1;
	if (ft_isalnum_str(arg) == true && ft_isdigit(arg[0]) == false)
	{
		ft_add_or_update_node_in_list(&sh_info->var->node, arg, NULL);
	}
	else
	{
		printf("minishell: export: `%s': not a valid identifier\n", arg);
		return_value = -1;
	}
	return (return_value);
}
