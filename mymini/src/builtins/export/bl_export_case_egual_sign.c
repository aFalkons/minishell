/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bl_export_case_egual_sign.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misidori <misidori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:06:35 by misidori          #+#    #+#             */
/*   Updated: 2023/11/29 15:01:56 by misidori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_init_exp_var(t_export_var *exp_var, char *arg,
	bool plus_sign_and_value)
{
	exp_var->index_egual_sign = ft_find_char_index_str(arg, '=');
	if (plus_sign_and_value == true)
		exp_var->name = ft_substr(arg, 0, exp_var->index_egual_sign - 1);
	else
		exp_var->name = ft_substr(arg, 0, exp_var->index_egual_sign);
	exp_var->return_value = 1;
	if (ft_check_name(exp_var, arg) == -1)
	{
		free(exp_var->name);
		exp_var->return_value = -1;
	}
	return (exp_var->return_value);
}

int	ft_arg_has_plus_sign(t_shell_info *sh_info, char **env,
	char *arg, char *value)
{
	t_export_var	exp_var;

	if (ft_init_exp_var(&exp_var, arg, true) == -1)
		return (-1);
	if (ft_check_if_variable_name_exists(sh_info, exp_var.name) == 1)
	{
		ft_attach_string_to_array(env, exp_var.name, value);
		ft_attach_string_to_list(sh_info, exp_var.name, value);
	}
	else
	{
		ft_add_element_to_array(sh_info, exp_var.name, value);
		ft_add_or_update_node_in_list(&sh_info->var->node, exp_var.name, value);
	}
	free(exp_var.name);
	return (exp_var.return_value);
}

int	ft_arg_has_egual_sign(t_shell_info *sh_info, char **env,
	char *arg, char *value)
{
	t_export_var	exp_var;

	if (ft_init_exp_var(&exp_var, arg, false) == -1)
		return (-1);
	if (ft_check_if_variable_name_exists(sh_info, exp_var.name) == 1)
	{
		ft_edit_value_in_array(env, exp_var.name, value);
		ft_add_or_update_node_in_list(&sh_info->var->head, exp_var.name, value);
	}
	else if (ft_check_if_variable_name_exists(sh_info, exp_var.name) == 2)
	{
		ft_add_element_to_array(sh_info, exp_var.name, value);
		ft_add_or_update_node_in_list(&sh_info->var->head, exp_var.name, value);
	}
	else
	{
		ft_add_element_to_array(sh_info, exp_var.name, value);
		ft_add_or_update_node_in_list(&sh_info->var->head, exp_var.name, value);
	}
	free(exp_var.name);
	return (exp_var.return_value);
}
